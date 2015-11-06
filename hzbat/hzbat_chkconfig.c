#include "libhzbat.h"

#define IS_LEAPYEAR(_year_)	( ( (_year_%4==0&&_year_%100!=0)||(_year_%400==0) ) ? 1 : 0 )

static int DaysOfMonth[2][13] =
	{     
		{ 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 } ,
		{ 0 , 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 }
	} ; 

static int CheckFilterRule( Pm_Hzbat_Batches_Filter *p_batches_filter )
{
	struct tm	tt ;
	
	InfoLog( __FILE__ , __LINE__ , "CheckFilterRule p_batches_filter->batch_name[%s]" , p_batches_filter->batch_name );
	if( STRCMP( p_batches_filter->filter_type , == , "DD" ) )
	{
		char	filter_param[ sizeof(p_batches_filter->filter_param) ] ;
		char	*ptr = NULL ;
		int	day ;
		
		strcpy( filter_param , p_batches_filter->filter_param );
		ptr = strtok( filter_param , "," ) ;
		while( ptr )
		{
			day = atoi(ptr) ;
			if( ( 1 <= day && day <= 31 ) || STRCMP( ptr , == , "MB" ) || STRCMP( ptr , == , "ME" ) )
			{
				;
			}
			else
			{
				ErrorLog( __FILE__ , __LINE__ , "DD参数[%s]不合法" , p_batches_filter->filter_param );
				return -1;
			}
			
			ptr = strtok( NULL , "," ) ;
		}
		if( ptr )
			return 0;
	}
	else if( STRCMP( p_batches_filter->filter_type , == , "MM-DD" ) )
	{
		char	filter_param[ sizeof(p_batches_filter->filter_param) ] ;
		char	*ptr = NULL ;
		char	_date[ 4+1+2+1+2 + 1 ] ;
		int	month ;
		int	day ;
		
		memset( _date , 0x00 , sizeof(_date) );
		snprintf( _date , sizeof(_date)-1 , "%02d-%02d" , tt.tm_mon+1 , tt.tm_mday );
		
		strcpy( filter_param , p_batches_filter->filter_param );
		ptr = strtok( filter_param , "," ) ;
		while( ptr )
		{
			*(ptr+2) = '\0' ;
			month = atoi(ptr) ;
			day = atoi(ptr+3) ;
			
			if( 1 <= month && month <= 12 && 1 <= day && day <= 31 )
			{
				;
			}
			else
			{
				ErrorLog( __FILE__ , __LINE__ , "MM-DD参数[%s]不合法" , p_batches_filter->filter_param );
				return -1;
			}
			
			ptr = strtok( NULL , "," ) ;
		}
		if( ptr )
			return 0;
	}
	else if( STRCMP( p_batches_filter->filter_type , == , "WDAY" ) )
	{
		char	filter_param[ sizeof(p_batches_filter->filter_param) ] ;
		char	*ptr = NULL ;
		int	wday ;
		
		strcpy( filter_param , p_batches_filter->filter_param );
		ptr = strtok( filter_param , "," ) ;
		while( ptr )
		{
			wday = atoi(ptr) ;
			if( 0 <= wday && wday <= 7 )
			{
				;
			}
			else
			{
				ErrorLog( __FILE__ , __LINE__ , "WDD参数[%s]不合法" , p_batches_filter->filter_param );
				return -1;
			}
			
			ptr = strtok( NULL , "," ) ;
		}
		if( ptr )
			return 0;
	}
	else
	{
		ErrorLog( __FILE__ , __LINE__ , "filter_type[%s] invalid" , p_batches_filter->filter_type );
		return DC4C_ERROR_PARAMETER;
	}
	
	return 1;
}

static int HZBATLoadDagScheduleFromDatabase( struct Dc4cDagSchedule **pp_sched , char *schedule_name , char *rservers_ip_port , int options )
{
	dag_schedule_configfile 	*p_config = NULL ;
	
	Pm_Hzbat_Schedule		schedule ;
	Pm_Hzbat_Batches_Info		batch_info ;
	Pm_Hzbat_Batches_Direction	batches_direction ;
	Pm_Hzbat_Batches_Filter		batch_filter ;
	Pm_Hzbat_Batches_Tasks		batches_tasks ;
	Select_Info			batch_info_cursor ;
	Select_Info			batches_direction_cursor ;
	Select_Info			batches_tasks_cursor ;
	char				begin_datetime[ 19 + 1 ] ;
	
	char				filename[ 256 + 1 ] ;
	char				pathfilename[ 256 + 1 ] ;
	
	int				nret = 0 ;
	
	p_config = (dag_schedule_configfile *)malloc( sizeof(dag_schedule_configfile) ) ;
	if( p_config == NULL )
	{
		ErrorLog( __FILE__ , __LINE__ , "alloc failed , errno[%d]" , errno );
		return DC4C_ERROR_ALLOC;
	}
	
	DSCINIT_dag_schedule_configfile( p_config );
	
	memset( & schedule , 0x00 , sizeof(schedule) );
	nret = DB_pm_hzbat_schedule_read_by_schedule_name( schedule_name , & schedule ) ;
	if( nret )
	{
		ErrorLog( __FILE__ , __LINE__ , "DB_pm_hzbat_schedule_read_by_schedule_name failed[%d] , schedule_name[%s]" , nret , schedule_name );
		free( p_config );
		return DC4C_ERROR_DATABASE;
	}
	else
	{
		InfoLog( __FILE__ , __LINE__ , "DB_pm_hzbat_schedule_read_by_schedule_name ok , schedule_name[%s]" , schedule_name );
	}
	
	strncpy( p_config->schedule.schedule_name , schedule.schedule_name , sizeof(p_config->schedule.schedule_name)-1 );
	strncpy( p_config->schedule.schedule_desc , schedule.schedule_desc , sizeof(p_config->schedule.schedule_desc)-1 );
	strncpy( p_config->schedule.begin_datetime , schedule.begin_datetime , sizeof(p_config->schedule.begin_datetime)-1 );
	strncpy( p_config->schedule.end_datetime , schedule.end_datetime , sizeof(p_config->schedule.end_datetime)-1 );
	p_config->schedule.progress = schedule.progress ;
	
	memset( & batch_info_cursor , 0x00 , sizeof(batch_info_cursor) );
	nret = DB_pm_hzbat_batches_info_open_select_by_schedule_name( schedule_name , & batch_info_cursor ) ;
	if( nret )
	{
		ErrorLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_info_open_select_by_schedule_name failed[%d] , schedule_name[%s]" , nret , schedule_name );
		free( p_config );
		return DC4C_ERROR_DATABASE;
	}
	else
	{
		DebugLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_info_open_select_by_schedule_name ok , schedule_name[%s]" , schedule_name );
	}
	
	for(	p_config->batches._batches_info_count = 0
		; p_config->batches._batches_info_count < p_config->batches._batches_info_size
		; )
	{
		memset( & batch_info , 0x00 , sizeof(batch_info) );
		nret = DB_pm_hzbat_batches_info_fetch_select( & batch_info_cursor , & batch_info ) ;
		if( nret == SQLNOTFOUND )
		{
			break;
		}
		else if( nret )
		{
			ErrorLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_info_fetch_select failed[%d]" , nret );
			free( p_config );
			return DC4C_ERROR_DATABASE;
		}
		else
		{
			DebugLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_info_fetch_select ok" );
		}
		
		strncpy( p_config->batches.batches_info[p_config->batches._batches_info_count].batch_name , batch_info.batch_name , sizeof(p_config->batches.batches_info[p_config->batches._batches_info_count].batch_name)-1 );
		strncpy( p_config->batches.batches_info[p_config->batches._batches_info_count].batch_desc , batch_info.batch_desc , sizeof(p_config->batches.batches_info[p_config->batches._batches_info_count].batch_desc)-1 );
		p_config->batches.batches_info[p_config->batches._batches_info_count].view_pos_x = batch_info.view_pos_x ;
		p_config->batches.batches_info[p_config->batches._batches_info_count].view_pos_y = batch_info.view_pos_y ;
		
		memset( & batches_tasks_cursor , 0x00 , sizeof(batches_tasks_cursor) );
		nret = DB_pm_hzbat_batches_tasks_open_select_by_schedule_name_and_batch_name_order_by_order_index( schedule_name , batch_info.batch_name , & batches_tasks_cursor ) ;
		if( nret )
		{
			ErrorLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_tasks_open_select_by_schedule_name_and_batch_name_order_by_order_index failed[%d] , schedule_name[%s] batch_name[%s]" , nret , schedule_name , batch_info.batch_name );
			free( p_config );
			return DC4C_ERROR_DATABASE;
		}
		else
		{
			DebugLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_tasks_open_select_by_schedule_name_and_batch_name_order_by_order_index ok , schedule_name[%s] batch_name[%s]" , schedule_name , batch_info.batch_name );
		}
		
		for(	p_config->batches.batches_info[p_config->batches._batches_info_count]._tasks_count = 0
			; p_config->batches.batches_info[p_config->batches._batches_info_count]._tasks_count < p_config->batches.batches_info[p_config->batches._batches_info_count]._tasks_size
			; )
		{
			memset( & batches_tasks , 0x00 , sizeof(batches_tasks) );
			nret = DB_pm_hzbat_batches_tasks_fetch_select( & batches_tasks_cursor , & batches_tasks ) ;
			if( nret == SQLNOTFOUND )
			{
				break;
			}
			else if( nret )
			{
				ErrorLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_tasks_fetch_select failed[%d]" , nret );
				free( p_config );
				return DC4C_ERROR_DATABASE;
			}
			else
			{
				DebugLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_tasks_fetch_select ok" );
			}
			
			p_config->batches.batches_info[p_config->batches._batches_info_count].tasks[p_config->batches.batches_info[p_config->batches._batches_info_count]._tasks_count].order_index = batches_tasks.order_index ;
			strncpy( p_config->batches.batches_info[p_config->batches._batches_info_count].tasks[p_config->batches.batches_info[p_config->batches._batches_info_count]._tasks_count].program_and_params , batches_tasks.program_and_params , sizeof(p_config->batches.batches_info[p_config->batches._batches_info_count].tasks[p_config->batches.batches_info[p_config->batches._batches_info_count]._tasks_count].program_and_params)-1 );
			p_config->batches.batches_info[p_config->batches._batches_info_count].tasks[p_config->batches.batches_info[p_config->batches._batches_info_count]._tasks_count].timeout = batches_tasks.timeout ;
			p_config->batches.batches_info[p_config->batches._batches_info_count].tasks[p_config->batches.batches_info[p_config->batches._batches_info_count]._tasks_count].progress = batches_tasks.progress ;
			
			memset( filename , 0x00 , sizeof(filename) );
			sscanf( batches_tasks.program_and_params , "%s" , filename );
			snprintf( pathfilename , sizeof(pathfilename) , "%s/bin/%s" , getenv("HOME") , filename );
			if( access( pathfilename , F_OK|R_OK ) == -1 )
			{
				ErrorLog( __FILE__ , __LINE__ , "access[%s] failed , errno[%d]" , pathfilename , errno );
				free( p_config );
				return DC4C_ERROR_FILE_NOT_FOUND;
			}
			
			p_config->batches.batches_info[p_config->batches._batches_info_count]._tasks_count++;
		}
		p_config->batches.batches_info[p_config->batches._batches_info_count].interrupt_by_app = batch_info.interrupt_by_app ;
		
		strncpy( p_config->batches.batches_info[p_config->batches._batches_info_count].begin_datetime , batch_info.begin_datetime , sizeof(p_config->batches.batches_info[p_config->batches._batches_info_count].begin_datetime)-1 );
		strncpy( p_config->batches.batches_info[p_config->batches._batches_info_count].end_datetime , batch_info.end_datetime , sizeof(p_config->batches.batches_info[p_config->batches._batches_info_count].end_datetime)-1 );
		p_config->batches.batches_info[p_config->batches._batches_info_count].progress = batch_info.progress ;
		
		memset( & batch_filter , 0x00 , sizeof(batch_filter) );
		nret = DB_pm_hzbat_batches_filter_read_by_schedule_name_and_batch_name( schedule_name , batch_info.batch_name , & batch_filter ) ;
		if( nret == SQLNOTFOUND )
		{
		}
		else if( nret )
		{
			ErrorLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_filter_read_by_schedule_name_and_batch_name failed[%d] , schedule_name[%s] batch_name[%s]" , nret , schedule_name , batch_info.batch_name );
			free( p_config );
			return DC4C_ERROR_DATABASE;
		}
		else
		{
			nret = CheckFilterRule( & batch_filter ) ;
			if( nret == 1 )
			{
				InfoLog( __FILE__ , __LINE__ , "FILTER!" );
				p_config->batches.batches_info[p_config->batches._batches_info_count]._tasks_count = 0 ;
			}
			else if( nret )
			{
				free( p_config );
				return nret;
			}
		}
		
		p_config->batches._batches_info_count++;
		
		DB_pm_hzbat_batches_tasks_close_select( & batches_tasks_cursor );
		DebugLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_tasks_close_select ok" );
	}
	
	DB_pm_hzbat_batches_info_close_select( & batch_info_cursor );
	DebugLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_info_close_select ok" );
	
	memset( & batches_direction_cursor , 0x00 , sizeof(batches_direction_cursor) );
	nret = DB_pm_hzbat_batches_direction_open_select_by_schedule_name( schedule_name , & batches_direction_cursor ) ;
	if( nret )
	{
		ErrorLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_direction_open_select_by_schedule_name failed[%d] , schedule_name[%s]" , nret , schedule_name );
		free( p_config );
		return DC4C_ERROR_DATABASE;
	}
	else
	{
		DebugLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_direction_open_select_by_schedule_name ok , schedule_name[%s]" , schedule_name );
	}
	
	for(	p_config->batches._batches_direction_count = 0
		; p_config->batches._batches_direction_count < p_config->batches._batches_direction_size
		; p_config->batches._batches_direction_count++ )
	{
		memset( & batches_direction , 0x00 , sizeof(batches_direction) );
		nret = DB_pm_hzbat_batches_direction_fetch_select( & batches_direction_cursor , & batches_direction ) ;
		if( nret == SQLNOTFOUND )
		{
			break;
		}
		else if( nret )
		{
			ErrorLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_direction_fetch_select failed[%d]" , nret );
			free( p_config );
			return DC4C_ERROR_DATABASE;
		}
		else
		{
			DebugLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_direction_fetch_select ok" );
		}
		
		strncpy( p_config->batches.batches_direction[p_config->batches._batches_direction_count].from_batch , batches_direction.from_batch , sizeof(p_config->batches.batches_direction[p_config->batches._batches_direction_count].from_batch)-1 );
		strncpy( p_config->batches.batches_direction[p_config->batches._batches_direction_count].to_batch , batches_direction.to_batch , sizeof(p_config->batches.batches_direction[p_config->batches._batches_direction_count].to_batch)-1 );
	}
	
	DB_pm_hzbat_batches_direction_close_select( & batches_direction_cursor );
	DebugLog( __FILE__ , __LINE__ , "DB_pm_hzbat_batches_direction_close_select ok" );
	
	nret = DC4CLoadDagScheduleFromStruct( pp_sched , p_config , rservers_ip_port , options ) ;
	free( p_config );
	if( nret )
	{
		ErrorLog( __FILE__ , __LINE__ , "DC4CLoadDagScheduleFromStruct failed[%d]" , nret );
		return nret;
	}
	else
	{
		InfoLog( __FILE__ , __LINE__ , "DC4CLoadDagScheduleFromStruct ok" );
	}
	
	return 0;
}

static int HZBATUnloadDagScheduleToDatabase( struct Dc4cDagSchedule **pp_sched )
{
	DC4CUnloadDagSchedule( pp_sched );
	InfoLog( __FILE__ , __LINE__ , "DC4CUnloadDagSchedule ok" );
	
	return 0;
}

static int hzbat_chkconfig( char *schedule_name )
{
	struct Dc4cDagSchedule	*p_sched = NULL ;
	
	int			nret = 0 ;
	
	nret = HZBATLoadDagScheduleFromDatabase( & p_sched , schedule_name , NULL , 0 ) ;
	if( nret )
	{
		printf( "HZBATLoadDagScheduleFromDatabase failed[%d]\n" , nret );
		return nret;
	}
	
	DC4CLogDagSchedule( p_sched );
	
	nret = HZBATUnloadDagScheduleToDatabase( & p_sched ) ;
	if( nret )
	{
		printf( "HZBATUnloadDagScheduleToDatabase failed[%d]\n" , nret );
		return nret;
	}
	
	return 0;
}

static int hzbat_all_chkconfig()
{
	Select_Info		schedule_cursor ;
	Pm_Hzbat_Schedule	schedule ;
	
	int			nret = 0 ;
	
	memset( & schedule_cursor , 0x00 , sizeof(schedule_cursor) );
	nret = DB_pm_hzbat_schedule_open_select_by_order_index_GE_order_by_order_index( 0 , & schedule_cursor ) ;
	if( nret )
	{
		printf( "DB_pm_hzbat_schedule_open_select_by_order_index_GE_order_by_order_index failed[%d]\n" , nret );
		return -1;
	}
	
	while(1)
	{
		memset( & schedule , 0x00 , sizeof(schedule) );
		nret = DB_pm_hzbat_schedule_fetch_select( & schedule_cursor , & schedule ) ;
		if( nret == SQLNOTFOUND )
		{
			nret = 0 ;
			break;
		}
		else if( nret )
		{
			printf( "DB_pm_hzbat_schedule_fetch_select failed[%d]\n" , nret );
			break;
		}
		
		nret = hzbat_chkconfig( schedule.schedule_name ) ;
		if( nret )
		{
			printf( "hzbat_chkconfig failed[%d]\n" , nret );
			break;
		}
		else
		{
			printf( "hzbat_chkconfig[%s] ok\n" , schedule.schedule_name );
		}
	}
	
	DB_pm_hzbat_schedule_close_select( & schedule_cursor );
	
	return nret;
}

int main( int argc , char *argv[] )
{
	int		nret = 0 ;
	
        DC4CSetAppLogFile( "hzbat_chkconfig" );
        SetLogLevel( LOGLEVEL_DEBUG );
        
	printf( "hzbat_chkconfig v%s build %s %s\n" , __HZBAT_VERSION , __DATE__ , __TIME__ );
	
	nret = BusinessDataBaseOpen() ;
	if( nret )
	{
		printf( "BusinessDataBaseOpen failed[%d]\n" , nret );
		return 1;
	}
	else
	{
		printf( "BusinessDataBaseOpen ok\n" );
	}
	
	nret = hzbat_all_chkconfig() ;
	if( nret )
	{
		printf( "*** ERROR *** , please see $HOME/log/hzbat_chkconfig.log\n" );
	}
	else
	{
		printf( "All DB configure is OK !!!\n" );
	}
	
	BusinessDataBaseClose();
	printf( "BusinessDataBaseClose ok\n" );
	
	return -nret;
}
