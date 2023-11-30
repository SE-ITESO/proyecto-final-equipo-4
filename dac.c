/*
 * dac.c
 *
 *  Created on: 3 nov 2023
 *      Author: Arlette Uribe & Pablo Ramos
 */

#include "dac.h"

/**************************************************************************************************************
 *                                            Functions definitions
 **************************************************************************************************************/

void DAC_init(DAC_Type *base)
{
	dac_config_t dacConfigStruct;
	dac_buffer_config_t dacBufferConfigStruct;

	DAC_GetDefaultConfig(&dacConfigStruct);
	DAC_Init(base, &dacConfigStruct);
	DAC_Enable(base, true);

	DAC_GetDefaultBufferConfig(&dacBufferConfigStruct);
	DAC_SetBufferConfig(DAC0, &dacBufferConfigStruct);

	DAC_SetBufferReadPointer(base, false);
	DAC_SetValue(DAC0,false);
}

void DAC_SetValue(DAC_Type *base, uint32_t value)
{
	DAC_SetBufferValue(base, false, value);
}
