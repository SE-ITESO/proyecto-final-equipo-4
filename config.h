/*
 * config.h
 *
 *  Created on: 10 nov 2023
 *      Author: Arlette Uribe & Pablo Ramos
 *
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <stdio.h>
#include <stdlib.h>
#include "MK64F12.h"

/****************************************
 *          General Macros
*****************************************/

enum{FALSE,TRUE};

typedef enum {
	zero,
	one,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	eleven,
	twelve,
	thirteen,
	fourteen,
	fifteen,
	sixteen,
	nineteen = 19u,
	twenty = 20u,
	onehundred = 100u,
	onethousand = 1000u
}Number_t;

/****************************************
 *          GPIO Macros
*****************************************/

typedef struct
{
	uint8_t flag_port_a		: 1;
	uint8_t flag_port_b 	: 1;
	uint8_t flag_port_c 	: 1;
	uint8_t flag_port_d 	: 2;
	uint8_t flag_port_e 	: 1;
} gpio_interrupt_flags_t;

typedef enum {
	GPIO_A,
	GPIO_B,
	GPIO_C,
	GPIO_D,
	GPIO_E
}gpio_port_name_t;


/****************************************
 *          Clock Macros
*****************************************/

#define PLL_DIVIDER 0x13U
#define VCO_DIVIDER 0x10U
#define OSCFREQ 50000000U

/****************************************
 *          DMA Macros
*****************************************/

#define TCD_QUEUE_SIZE	1u
#define DMA_SOURCE 		58u				/** Source always enable */
#define DAC_ADDR 		0x400CC000u
#define DMA_CHANNEL		0

#define SRC_WIDTH 2u
#define SRC_OFFSET 2u
#define DEST_WIDTH 2u
#define DEST_OFFSET 0u
#define MINOR_LOOP 2u


#endif /* CONFIG_H_ */
