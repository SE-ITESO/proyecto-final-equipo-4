/*
 * spi.c
 *
 *  Created on: 1 nov 2023
 *      Author: Arlette Uribe & Pablo Ramos
 */

#include "spi.h"

/**************************************************************************************************************
 *                                             Functions definitions
 **************************************************************************************************************/

uint8_t g_master_rxBuff;

void SPI0_config(SPI_config* config)
{
	uint32_t srcClock_Hz;
	dspi_master_config_t masterConfig;

	CLOCK_EnableClock(kCLOCK_Spi0);
	CLOCK_EnableClock(kCLOCK_PortD);

	PORT_SetPinMux(PORTD, PIN1_IDX, kPORT_MuxAlt2);
	PORT_SetPinMux(PORTD, PIN2_IDX, kPORT_MuxAlt2);

	masterConfig.whichCtar 									= config->ctar;
	masterConfig.ctarConfig.baudRate 						= config->baudrate;
	masterConfig.ctarConfig.bitsPerFrame 					= config->bitframe;
	masterConfig.ctarConfig.cpol 							= config->cpol;
	masterConfig.ctarConfig.cpha 							= config->cpha;
	masterConfig.ctarConfig.direction 						= kDSPI_MsbFirst;
	masterConfig.ctarConfig.pcsToSckDelayInNanoSec 			= false;
	masterConfig.ctarConfig.lastSckToPcsDelayInNanoSec 		= false;
	masterConfig.ctarConfig.betweenTransferDelayInNanoSec 	= false;

	masterConfig.whichPcs 									= config->pcs;
	masterConfig.pcsActiveHighOrLow 						= kDSPI_PcsActiveLow;

	masterConfig.enableContinuousSCK 						= false;
	masterConfig.enableRxFifoOverWrite 						= false;
	masterConfig.enableModifiedTimingFormat 				= false;
	masterConfig.samplePoint 								= kDSPI_SckToSin0Clock;

	srcClock_Hz = CLOCK_GetFreq(DSPI0_CLK_SRC);
	DSPI_MasterInit(SPI0, &masterConfig, srcClock_Hz);
}

