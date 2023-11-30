/*
 * spi.h
 *
 *  Created on: 1 nov 2023
 *      Author: Arlette Uribe & Pablo Ramos
 */

#ifndef SPI_H_
#define SPI_H_

/**************************************************************************************************************
 *                                             Included files
 **************************************************************************************************************/

#include "fsl_dspi.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "fsl_clock.h"
#include "clock_config.h"

/**************************************************************************************************************
 *                                           Macros & structures
 **************************************************************************************************************/

typedef struct{
	uint32_t baudrate;
	uint16_t bitframe;
	uint8_t ctar;
	uint8_t cpol;
	uint8_t cpha;
	uint8_t pcs;
}SPI_config;

#define MEM_DATA		4u
#define MEM_DATA_SPI	1u

/**************************************************************************************************************
 *                                          Functions declarations
 **************************************************************************************************************/

void SPI0_config(SPI_config* config);

void SPI_Halfduplex_config(const uint8_t data[]);

uint8_t SPI_return_data(void);


#endif /* SPI_H_ */
