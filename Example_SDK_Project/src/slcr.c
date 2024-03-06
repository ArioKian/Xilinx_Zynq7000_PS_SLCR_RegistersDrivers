/*
 * slcr.c
 *
 *  Created on: Mar 21, 2023
 *      Author: Kian
 */

#include "slcr.h"
#include "xil_printf.h"
#include <stdio.h>

void unlockSLCR(){
	u32 slcrLockStatus;
	printf("UNLOCKING SLCR REGS\n");
	Xil_Out32(SLCR_UNLOCK, SLCR_UNLOCK_VALUE);
	slcrLockStatus = Xil_In32(SLCR_LOCKSTA);
	printf("LOCKSTA value is %lu\n", slcrLockStatus);
}

void lockSLCR(){
	u32 slcrLockStatus;
	printf("LOCKING SLCR REGS\n");
	Xil_Out32(SLCR_LOCK, SLCR_LOCK_VALUE);
	slcrLockStatus = Xil_In32(SLCR_LOCKSTA);
	printf("LOCKSTA value is %lu\n", slcrLockStatus);
}

void lockSLCRCheck(){
	u32 slcrLockStatus;

	slcrLockStatus = Xil_In32(SLCR_LOCKSTA);
    if(!(slcrLockStatus & 0x1)){
    	printf("SLCR REGS ARE WRITEABLE: LOCKSTA value is %lu\n", slcrLockStatus);
    }
    else{
    	printf("SLCR REGS ARE WRITE PROTECTED: LOCKSTA value is %lu\n", slcrLockStatus);
    }
}


