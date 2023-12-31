/*
 * pit.h
 *
 *  Created on: 3 nov 2023
 *      Author: Arlette Uribe & Pablo Ramos
 */

#ifndef PIT_H_
#define PIT_H_


/*************************************************************************************************************
 *                                               Included files
 **************************************************************************************************************/

#include "fsl_pit.h"
#include "fsl_common_arm.h"
#include "MK64F12.h"

/**************************************************************************************************************
 *                                                  Macros
 **************************************************************************************************************/

#define PIT_TIME 250u
#define PIT1_TIME 500000u
#define PITclock CLOCK_GetFreq(kCLOCK_BusClk)

/**************************************************************************************************************
 *                                             Functions declarations
 **************************************************************************************************************/

void PIT_init();
void PIT_callback_init( void (*handler));

#endif /* PIT_H_ */
