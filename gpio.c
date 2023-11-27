/*
 * gpio.c
 *
 *  Created on: 01 nov 2023
 *      Author: Arlette Uribe & Pablo Ramos
 */


#include "gpio.h"

/**************************************************************************************************************
 *                                             Global variables
 **************************************************************************************************************/

volatile static gpio_interrupt_flags_t g_intr_status_flag = {0};

static void (*gpio_callback) (uint8_t) = 0;

/**************************************************************************************************************
 *                                            Functions definitions
 **************************************************************************************************************/
void GPIO_callback_init( void (*handler))
{
	if(0 == gpio_callback ){
		gpio_callback = handler;
	}
}
void PORTA_IRQHandler(void)
{
	g_intr_status_flag.flag_port_a = true;
	GPIO_PortClearInterruptFlags(GPIOA, 0xFFFFFFF);
}

void PORTB_IRQHandler(void)
{
	g_intr_status_flag.flag_port_b = true;
	GPIO_PortClearInterruptFlags(GPIOB, 0xFFFFFFF);
}

void PORTC_IRQHandler(void)
{
	g_intr_status_flag.flag_port_c = true;
	GPIO_PortClearInterruptFlags(GPIOC, 0xFFFFFFF);
}


void GPIO_init(void){

	/* configuration structures */

	gpio_pin_config_t gpio_input_config = {
			        kGPIO_DigitalInput,
			        0,
			    };

	const port_pin_config_t button_config = {
			kPORT_PullUp,                          /* Internal pull-up resistor is enabled */
			kPORT_FastSlewRate,                    /* Fast slew rate is configured */
			kPORT_PassiveFilterEnable,             /* Passive filter is enable */
			kPORT_OpenDrainDisable,                /* Open drain is disabled */
			kPORT_HighDriveStrength,               /* High drive strength is configured */
			kPORT_MuxAsGpio,                       /* Pin is configured as PTA4 */
			kPORT_UnlockRegister                   /* Pin Control Register fields [15:0] are not locked */
	};

	/* Enable clocks */
	CLOCK_EnableClock(kCLOCK_PortA);
	CLOCK_EnableClock(kCLOCK_PortC);

	GPIO_PinInit(GPIOA,BTN_left, &gpio_input_config);
	PORT_SetPinConfig(PORTA, BTN_left, &button_config);
	PORT_SetPinInterruptConfig(PORTA, BTN_left, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOA, BTN_right, &gpio_input_config);
	PORT_SetPinConfig(PORTA, BTN_right, &button_config);
	PORT_SetPinInterruptConfig(PORTA, BTN_right, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOC, BTN_up, &gpio_input_config);
	PORT_SetPinConfig(PORTC, BTN_up, &button_config);
	PORT_SetPinInterruptConfig(PORTC, BTN_up, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOC, BTN_down, &gpio_input_config);
	PORT_SetPinConfig(PORTC, BTN_down, &button_config);
	PORT_SetPinInterruptConfig(PORTC, BTN_down, kPORT_InterruptFallingEdge);
}

void GPIO_Clear_irq_status(gpio_port_name_t gpio_port){

	switch (gpio_port){

	case GPIO_A:
		g_intr_status_flag.flag_port_a = false;
		break;
	case GPIO_B:
		g_intr_status_flag.flag_port_b = false;
		break;
	case GPIO_C:
		g_intr_status_flag.flag_port_c = false;
		break;
	case GPIO_D:
		g_intr_status_flag.flag_port_d = false;
		break;
	default:
		g_intr_status_flag.flag_port_a = false;
		break;
	}
}

uint8_t GPIO_Get_irq_status(gpio_port_name_t gpio_port){

	static uint8_t status = 0;

	switch (gpio_port){

	case GPIO_A:
		status = g_intr_status_flag.flag_port_a;
		break;
	case GPIO_B:
		status = g_intr_status_flag.flag_port_b;
		break;
	case GPIO_C:
		status = g_intr_status_flag.flag_port_c;
		break;
	case GPIO_D:
		status = g_intr_status_flag.flag_port_d;
		break;
	default:
		status = g_intr_status_flag.flag_port_a;
		break;
	}
	return (status);
}
