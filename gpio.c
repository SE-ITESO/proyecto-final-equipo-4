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


/**************************************************************************************************************
 *                                            Functions definitions
 **************************************************************************************************************/

void PORTA_IRQHandler(void)
{
	g_intr_status_flag.flag_port_a = true;
	GPIO_PortClearInterruptFlags(GPIOA, 0xFFFFFFFFF);
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


	GPIO_PinInit(GPIOA, 1, &gpio_input_config);
	PORT_SetPinConfig(PORTA, 1, &button_config);
	PORT_SetPinInterruptConfig(PORTA, 1, kPORT_InterruptFallingEdge);

}

void GPIO_Clear_irq_status(gpio_port_name_t gpio_port){

	switch (gpio_port){

	case GPIO_A:
		g_intr_status_flag.flag_port_a = FALSE;
		break;
	case GPIO_B:
		g_intr_status_flag.flag_port_b = FALSE;
		break;
	case GPIO_C:
		g_intr_status_flag.flag_port_c = FALSE;
		break;
	case GPIO_D:
		g_intr_status_flag.flag_port_d = FALSE;
		break;
	default:
		g_intr_status_flag.flag_port_a = FALSE;
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
