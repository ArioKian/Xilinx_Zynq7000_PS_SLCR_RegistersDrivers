/*
 * slcr.h
 *
 *  Created on: Mar 21, 2023
 *      Author: Kian
 */

#ifndef SRC_SLCR_H_
#define SRC_SLCR_H_

#include "xparameters.h"
#include "xil_io.h"

#define SLCR_BASEADDR	XPAR_PS7_SLCR_0_S_AXI_BASEADDR		// SLCR regs Base Addr	 	0xF8000000

#define SLCR_LOCK 		SLCR_BASEADDR+0x4					// SLCR_LOCK reg Addr		0xF8000004
#define SLCR_UNLOCK		SLCR_BASEADDR+0x8					// SLCR_UNLOCK reg Addr 	0xF8000008
#define SLCR_LOCKSTA	SLCR_BASEADDR+0xC					// SLCR_LOCKSTA reg Addr	0xF800000C

#define SLCR_LOCK_VALUE 0x767B					// SLCR regs Write Protection lock value
#define SLCR_LOCK_RESET_VALUE 0x0
#define SLCR_UNLOCK_VALUE 0xDF0D				// SLCR regs Write Protection unlock value
#define SLCR_UNLOCK_RESET_VALUE 0x0

void unlockSLCR();
void lockSLCR();
void lockSLCRCheck();

#endif /* SRC_SLCR_H_ */
