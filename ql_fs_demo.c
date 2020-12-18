#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ql_api_osi.h"
#include "ql_log.h"
#include "ql_fs_demo.h"
#include "ql_fs.h"

#define QL_FS_DEMO_LOG_LEVEL		QL_LOG_LEVEL_INFO
#define QL_FS_DEMO_LOG(msg, ...)	QL_LOG(QL_FS_DEMO_LOG_LEVEL, "ql_fs_demo", msg, ##__VA_ARGS__)

ql_task_t ql_fs_task = NULL;

void ql_fs_callback(void *ctx)
{
	int fd = 0;
	int64 err = QL_FILE_OK;
	char buffer[100];
	char *str = TEST_STR;

}


int ql_fs_demo_init(void)
{	
	QlOSStatus err = QL_OSI_SUCCESS;
	
	err = ql_rtos_task_create(&ql_fs_task, QL_FS_TASK_STACK_SIZE, QL_FS_TASK_PRIO, "ql_fs_task", ql_fs_callback, NULL, QL_FS_TASK_EVENT_CNT);
	if(err != QL_OSI_SUCCESS)
	{
		QL_FS_DEMO_LOG("file_task created failed");
	}

	return err;
}


