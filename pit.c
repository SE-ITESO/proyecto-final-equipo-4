/*
 * pit.c
 *
 *  Created on: 3 nov 2023
 *      Author: Arlette Uribe & Pablo Ramos
 */

#include "pit.h"

/**************************************************************************************************************
 *                                            Functions definitions
 **************************************************************************************************************/

uint8_t g_pit = false;

void PIT0_IRQHandler(void)
{
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
}


void PIT_init(void)
{
	pit_config_t pitConfig;

	DisableIRQ(PIT0_IRQn);
	PIT_GetDefaultConfig(&pitConfig);
	PIT_Init(PIT, &pitConfig);
	PIT_StopTimer(PIT, kPIT_Chnl_0);
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(PIT0_TIME, PITclock));
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
	EnableIRQ(PIT0_IRQn);
	PIT_StartTimer(PIT, kPIT_Chnl_0);
}

uint8_t PIT_status_flag(void){
	return g_pit;
}

void PIT_clear_status_flag(void){
	g_pit = false;
}
