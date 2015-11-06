#ifndef _H_LIBHZBAT_
#define _H_LIBHZBAT_

#include "dc4c_api.h"
#include "dc4c_tfc_dag.h"

#include <time.h>

#include "hzb_log.h"

#include "businessdb.h"

#include "DB_Pm_Hzbat_Schedule.h"
#include "DB_Pm_Hzbat_Batches_Info.h"
#include "DB_Pm_Hzbat_Batches_Direction.h"
#include "DB_Pm_Hzbat_Batches_Filter.h"
#include "DB_Pm_Hzbat_Batches_Tasks.h"

int DB_pm_hzbat_batches_info_debug_print(char *reason,Pm_Hzbat_Batches_Info *adata, char *filename, int line_no);

extern char	*__HZBAT_VERSION ;

#endif

