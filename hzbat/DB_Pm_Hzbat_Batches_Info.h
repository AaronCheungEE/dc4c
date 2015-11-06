/*
 This Include File "DB_Pm_Hzbat_Batches_Info.h" 
 Genenated By
 Application <db9action> for MySQL
 with the action file "DB_Pm_Hzbat_Batches_Info.act".
 Create: Fri Nov  6 09:57:59 2015
*/

#ifndef _DB_pm_hzbat_batches_info_INCLUDE_H_
#define _DB_pm_hzbat_batches_info_INCLUDE_H_
#include "dbutil.h"

typedef struct {
	char	schedule_name[65];
	char	batch_name[65];
	char	batch_desc[65];
	int	view_pos_x;
	int	view_pos_y;
	int	interrupt_by_app;
	char	begin_datetime[20];
	char	end_datetime[20];
	int	progress;
	char	pretask_program_and_params[257];
	int	pretask_timeout;
	char	pretask_ip[41];
	int	pretask_port;
	int	pretask_progress;
	int	pretask_error;
	int	pretask_status;
        } Pm_Hzbat_Batches_Info;

int DB_pm_hzbat_batches_info_count_by_schedule_name( char *schedule_name__0,long *_a_cnt);
int DB_pm_hzbat_batches_info_open_select_by_schedule_name( char *schedule_name__0,Select_Info *_a_sInfo);
int DB_pm_hzbat_batches_info_fetch_select( Select_Info *_a_sInfo,Pm_Hzbat_Batches_Info *_a_data);
int DB_pm_hzbat_batches_info_close_select( Select_Info *_a_sInfo);
int DB_pm_hzbat_batches_info_read_by_schedule_name_and_batch_name( char *schedule_name__0,char *batch_name__1,Pm_Hzbat_Batches_Info *_a_data);
int DB_pm_hzbat_batches_info_update_for_begin_datetime_and_end_datetime_and_progress_by_schedule_name_and_batch_name( char *schedule_name__4,char *batch_name__5,Pm_Hzbat_Batches_Info *_a_data);
int DB_pm_hzbat_batches_info_update_for_end_datetime_and_progress_by_schedule_name_and_batch_name( char *schedule_name__3,char *batch_name__4,Pm_Hzbat_Batches_Info *_a_data);
int DB_pm_hzbat_batches_info_update_for_pretask_ip_and_pretask_port_and_pretask_progress_and_pretask_error_and_pretask_status_by_schedule_name_and_batch_name( char *schedule_name__6,char *batch_name__7,Pm_Hzbat_Batches_Info *_a_data);

#endif
