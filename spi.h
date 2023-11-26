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
 *                                                 Macros
 **************************************************************************************************************/

#define PIN0_IDX                         0u   	/*!< Pin number for pin 0 in a port */
#define PIN1_IDX                         1u   	/*!< Pin number for pin 1 in a port */
#define PIN2_IDX                         2u   	/*!< Pin number for pin 2 in a port */
#define PIN3_IDX                         3u  	/*!< Pin number for pin 3 in a port */
#define PIN16_IDX                       16u   	/*!< Pin number for pin 16 in a port */
#define PIN17_IDX                       17u   	/*!< Pin number for pin 17 in a port */

#define LCD_TRANSFER_SIZE     8U     			/*! Transfer dataSize */
#define LCD_TRANSFER_BAUDRATE 1000000U 			/*! Transfer baudrate - 500k */

#define SCREENW 84
#define SCREENH 48

#define LCD_X 84
#define LCD_Y 48
#define LCD_DATA 1
#define LCD_CMD 0
#define DATA_OR_CMD_PIN 5
#define RESET_PIN 7
#define CE 0
#define TXDATASIZE 504u

typedef struct{
	uint32_t baudrate;
	uint16_t bitframe;
	uint8_t ctar;
	uint8_t cpol;
	uint8_t cpha;
	uint8_t pcs;
}SPI_config;

/**************************************************************************************************************
 *                                          Functions declarations
 **************************************************************************************************************/

void SPI0_config(SPI_config* config);

#endif /* SPI_H_ */
