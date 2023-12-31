/*
 * clock.h
 *
 *  Created on: 5 nov 2023
 *      Author: Arlette Uribe & Pablo Ramos
 */

#ifndef CLOCK_H_
#define CLOCK_H_

/**************************************************************************************************************
 *                                             Included files
 **************************************************************************************************************/

#include "fsl_clock.h"

/**************************************************************************************************************
 *                                                 Macros
 **************************************************************************************************************/

#define MCG_PLL_DISABLE 0U                     /*!< MCGPLLCLK disabled */
#define OSC_CAP0P 0U                           /*!< Oscillator 0pF capacitor load */

/**************************************************************************************************************
 *                                          Functions declarations
 **************************************************************************************************************/


void CLK_config(void);

#endif /* CLOCK_H_ */
