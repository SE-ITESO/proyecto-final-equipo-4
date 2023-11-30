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
static void (*pit1_callback) (void)= 0;

void PIT_callback_init( void (*handler))
{
	if(0 == pit1_callback ){
		pit1_callback = handler;
	}
}

void PIT0_IRQHandler(void)
{
	g_pit = true;
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
}
void PIT1_IRQHandler(void)
{
	if(pit1_callback ){
		pit1_callback();
	}
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_1, kPIT_TimerFlag);
}

void PIT0_init()
{
	pit_config_t pitConfig;

	DisableIRQ(PIT0_IRQn);
	PIT_GetDefaultConfig(&pitConfig);
	PIT_Init(PIT, &pitConfig);
	PIT_StopTimer(PIT, kPIT_Chnl_0);
	PIT_StopTimer(PIT, kPIT_Chnl_1);
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(PIT_TIME, PITclock));
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_1, USEC_TO_COUNT(PIT1_TIME, PITclock));
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
	PIT_EnableInterrupts(PIT, kPIT_Chnl_1, kPIT_TimerInterruptEnable);
	EnableIRQ(PIT0_IRQn);
	EnableIRQ(PIT1_IRQn);
	PIT_StartTimer(PIT, kPIT_Chnl_0);
	PIT_StartTimer(PIT, kPIT_Chnl_1);
}
