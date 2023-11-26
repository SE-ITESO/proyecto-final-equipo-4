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
#include "config.h"

/**************************************************************************************************************
 *                                             Functions declarations
 **************************************************************************************************************/

void GPIO_init(void);

uint8_t GPIO_Get_irq_status(gpio_port_name_t gpio_port);

void GPIO_Clear_irq_status(gpio_port_name_t gpio_port);

void GPIO_callback_init( void (*handler));

#endif /* GPIO_H_ */
