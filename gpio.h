/*
 * gpio.h
 *
 *  Created on: 01 nov 2023
 *      Author: Arlette Uribe & Pablo Ramos
 */

#ifndef GPIO_H_
#define GPIO_H_

/**************************************************************************************************************
 *                                               Included files
 **************************************************************************************************************/

#include "stdint.h"
#include "stdio.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_gpio.h"

/**************************************************************************************************************
 *                                                   Macros
 **************************************************************************************************************/

typedef enum{FALSE, TRUE} boolean_t;

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

typedef enum {
	BTN_kick 		= 19u,		/* PORTB */
	BTN_snare 		= 18u,		/* PORTB */
	BTN_bongo 		= 1u,		/* PORTC */
	BTN_hit_hat 	= 8u,		/* PORTC */
	BTN_guiro 		= 23u,		/* PORTB */
	BTN_rim_shot 	= 9u,		/* PORTC */
	BTN_tambor 		= 9u,		/* PORTB */
	BTN_cynbal 		= 0u,		/* PORTC */
	BTN_cowbell 	= 16u, 		/* PORTC */
	BTN_menu 		= 1u, 		/* PORTA */
	BTN_one 		= 4u,		/* PORTD */
	BTN_two 		= 5u 		/* PORTD */
}button_t;

/**************************************************************************************************************
 *                                             Functions declarations
 **************************************************************************************************************/

void GPIO_init(void);

uint8_t GPIO_Get_irq_status(gpio_port_name_t gpio_port);

void GPIO_Clear_irq_status(gpio_port_name_t gpio_port);

void GPIO_callback_init( void (*handler));

#endif /* GPIO_H_ */
