/*************************************************************************//**
 *****************************************************************************
 * @file   misc.c
 * @brief  
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
#include "keyboard.h"
#include "proto.h"
#include "hd.h"
#include "fs.h"

/*****************************************************************************
 *                                do_lsdir
 *************************************************************************//**
 * List the current directory
 * 
 * @return  nr of files is returned.
 *****************************************************************************/
PUBLIC int do_lsdir()
{
	int src = fs_msg.source;	/* caller proc nr. */

	int dir_blk0_nr = current_inode->i_start_sect;
	int nr_dir_blks = (current_inode->i_size + SECTOR_SIZE) / SECTOR_SIZE;
	int nr_dir_entries =
		current_inode->i_size / DIR_ENTRY_SIZE; /**
						     * including unused slots
						     * (the file has been
						     * deleted but the slot
						     * is still there)
						     */

	int m = 0;
	struct dir_entry de[nr_dir_entries];
	struct dir_entry * pde;

	int i, j;
	for(i = 0; i < nr_dir_blks; i++){
		RD_SECT(current_inode->i_dev, dir_blk0_nr + i);

		pde = (struct dir_entry *)fsbuf;
		for(j = 0; j < SECTOR_SIZE / DIR_ENTRY_SIZE; j++, pde++){
			if(m >= nr_dir_entries)
				break;
			de[m] = *pde;
			m++;
		}
	}
	phys_copy((void*)va2la(src, fs_msg.BUF), /* to   */
		  (void*)va2la(TASK_FS, de),	 /* from */
		  nr_dir_entries*DIR_ENTRY_SIZE);

	return nr_dir_entries;
}