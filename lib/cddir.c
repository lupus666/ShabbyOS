/*************************************************************************//**
 *****************************************************************************
 * @file   cddir.c
 * @brief  cddir()
 *****************************************************************************
 *****************************************************************************/

#include "type.h"
#include "stdio.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"

/*****************************************************************************
 *                                cddir
 *****************************************************************************/
/**
 * Change current directory.
 * 
 * @param pathname  The full path of the directory to enter.
 * 
 * @return 0 if successful, otherwise -1.
 *****************************************************************************/

PUBLIC int mkdir(const char *pathname)
{
	MESSAGE msg;

	msg.type = CDDIR;

	msg.PATHNAME = (void*)pathname;
	msg.NAME_LEN = strlen(pathname);

	send_recv(BOTH, TASK_FS, &msg);
	assert(msg.type == SYSCALL_RET);

	return msg.RETVAL;
}