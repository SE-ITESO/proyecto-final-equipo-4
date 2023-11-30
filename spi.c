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

	CLOCK_SetSimSafeDivs();
	dspi_master_config_t masterConfig;

	CLOCK_EnableClock(kCLOCK_Spi0);

	masterConfig.whichCtar 									= config->ctar;
	masterConfig.ctarConfig.baudRate 						= config->baudrate;
	masterConfig.ctarConfig.bitsPerFrame 					= config->bitframe;
	masterConfig.ctarConfig.cpol 							= config->cpol;
	masterConfig.ctarConfig.cpha 							= config->cpha;
	masterConfig.ctarConfig.direction 						= kDSPI_MsbFirst;
	masterConfig.ctarConfig.pcsToSckDelayInNanoSec 			= 0;
	masterConfig.ctarConfig.lastSckToPcsDelayInNanoSec 		= 0;
	masterConfig.ctarConfig.betweenTransferDelayInNanoSec 	= 0;

	masterConfig.whichPcs 									= config->pcs;
	masterConfig.pcsActiveHighOrLow 						= kDSPI_PcsActiveLow;

	masterConfig.enableContinuousSCK 						= false;
	masterConfig.enableRxFifoOverWrite 						= false;
	masterConfig.enableModifiedTimingFormat 				= false;
	masterConfig.samplePoint 								= kDSPI_SckToSin0Clock;

	srcClock_Hz = CLOCK_GetFreq(DSPI0_CLK_SRC);
	DSPI_MasterInit(SPI0, &masterConfig, srcClock_Hz);
}

void SPI_Halfduplex_config(const uint8_t data[])
{
	dspi_half_duplex_transfer_t masterxfer;

	masterxfer.txData                = (uint8_t *)data;
	masterxfer.rxData                = &g_master_rxBuff;
	masterxfer.txDataSize            = MEM_DATA;
	masterxfer.rxDataSize            = MEM_DATA_SPI;
	masterxfer.isTransmitFirst       = true;
	masterxfer.isPcsAssertInTransfer = true;
	masterxfer.configFlags           = kDSPI_MasterCtar1 | kDSPI_MasterPcs1 | kDSPI_MasterPcsContinuous;



	DSPI_MasterHalfDuplexTransferBlocking(SPI0, &masterxfer);
}

uint8_t SPI_return_data(void){
	return g_master_rxBuff;
}
