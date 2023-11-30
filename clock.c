/*
 * clock.c
 *
 *  Created on: 5 nov 2023
 *      Author: Arlette Uribe & Pablo Ramos
 */

#include "clock.h"


/**************************************************************************************************************
 *                                             Functions definitions
 **************************************************************************************************************/

void CLK_config(void){

	mcg_pll_config_t pll0Config = {
			.enableMode = MCG_PLL_DISABLE, 	/* MCGPLLCLK disabled */
			.prdiv      = 0x13U,            /* PLL Reference divider: divided by 20 */
			.vdiv       = 0x10U,            /* VCO divider: multiplied by 40 */
	};

	const osc_config_t osc_config = {
			.freq        = 50000000U,    	/* Oscillator frequency: 50000000Hz */
			.capLoad     = (OSC_CAP0P),  	/* Oscillator capacity load: 0pF */
			.workMode    = kOSC_ModeExt, 	/* Use external clock */
			.oscerConfig = {
					.enableMode = kOSC_ErClkEnable, /* Enable external reference clock, disable external reference clock in STOP mode */
			}
	};

	CLOCK_InitOsc0(&osc_config);
	CLOCK_SetXtal0Freq(osc_config.freq);

	CLOCK_BootToPeeMode(kMCG_OscselOsc, kMCG_PllClkSelPll0, &pll0Config);


}
