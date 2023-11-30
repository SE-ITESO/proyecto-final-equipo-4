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
static void (*gpioA_callback) (void)= FALSE;
static void (*gpioB_callback) (void)= FALSE;
static void (*gpioC_callback) (void)= FALSE;
static void (*gpioD_callback) (void)= FALSE;

/**************************************************************************************************************
 *                                            Functions definitions
 **************************************************************************************************************/
void GPIO_callback_init(void (*handler))
{
	if(FALSE == gpioA_callback){
		gpioA_callback = handler;
	}else if(FALSE == gpioB_callback ){
		gpioB_callback = handler;
	}else if (FALSE == gpioC_callback){
		gpioC_callback = handler;
	}else if(FALSE == gpioD_callback){
		gpioD_callback = handler;
	}
}
void PORTA_IRQHandler(void)
{
	static uint8_t flag = 0;
	flag = MENU_return_flag();
	if(gpioA_callback && flag){
		gpioA_callback();
	}
	g_intr_status_flag.flag_port_a = true;
	GPIO_PortClearInterruptFlags(GPIOA, 0xFFFFFFF);
}

void PORTB_IRQHandler(void)
{
	static uint8_t flag = 0;
	flag = MENU_return_flag();
	if(gpioB_callback && flag){
		gpioB_callback();
	}
	g_intr_status_flag.flag_port_b = true;
	GPIO_PortClearInterruptFlags(GPIOB, 0xFFFFFFF);
}

void PORTC_IRQHandler(void)
{
	static uint8_t flag = 0;
	flag = MENU_return_flag();
	if(gpioC_callback && flag){
		gpioC_callback();
	}
	g_intr_status_flag.flag_port_c = true;
	GPIO_PortClearInterruptFlags(GPIOC, 0xFFFFFFF);
}

void PORTD_IRQHandler(void)
{
	static uint8_t flag = 0;
	flag = MENU_return_flag();
	if(gpioD_callback && flag ){
		gpioD_callback();
	}
	g_intr_status_flag.flag_port_d = true;
	GPIO_PortClearInterruptFlags(GPIOD, 0xFFFFFFF);
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
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortC);
	CLOCK_EnableClock(kCLOCK_PortD);

	GPIO_PinInit(GPIOB,BTN_kick, &gpio_input_config);
	PORT_SetPinConfig(PORTB, BTN_kick, &button_config);
	PORT_SetPinInterruptConfig(PORTB, BTN_kick, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOB, BTN_snare, &gpio_input_config);
	PORT_SetPinConfig(PORTB, BTN_snare, &button_config);
	PORT_SetPinInterruptConfig(PORTB, BTN_snare, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOC, BTN_bongo, &gpio_input_config);
	PORT_SetPinConfig(PORTC, BTN_bongo, &button_config);
	PORT_SetPinInterruptConfig(PORTC, BTN_bongo, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOC, BTN_hit_hat, &gpio_input_config);
	PORT_SetPinConfig(PORTC, BTN_hit_hat, &button_config);
	PORT_SetPinInterruptConfig(PORTC, BTN_hit_hat, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOB, BTN_guiro, &gpio_input_config);
	PORT_SetPinConfig(PORTB, BTN_guiro, &button_config);
	PORT_SetPinInterruptConfig(PORTB, BTN_guiro, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOC, BTN_rim_shot, &gpio_input_config);
	PORT_SetPinConfig(PORTC, BTN_rim_shot, &button_config);
	PORT_SetPinInterruptConfig(PORTC, BTN_rim_shot, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOB, BTN_tambor, &gpio_input_config);
	PORT_SetPinConfig(PORTB, BTN_tambor, &button_config);
	PORT_SetPinInterruptConfig(PORTB, BTN_tambor, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOC, BTN_cynbal, &gpio_input_config);
	PORT_SetPinConfig(PORTC, BTN_cynbal, &button_config);
	PORT_SetPinInterruptConfig(PORTC, BTN_cynbal, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOC, BTN_cowbell, &gpio_input_config);
	PORT_SetPinConfig(PORTC, BTN_cowbell, &button_config);
	PORT_SetPinInterruptConfig(PORTC, BTN_cowbell, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOA, BTN_menu, &gpio_input_config);
	PORT_SetPinConfig(PORTA, BTN_menu, &button_config);
	PORT_SetPinInterruptConfig(PORTA, BTN_menu, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOD, 3, &gpio_input_config);
	PORT_SetPinConfig(PORTD, 3, &button_config);
	PORT_SetPinInterruptConfig(PORTD, 3, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOD, BTN_two, &gpio_input_config);
	PORT_SetPinConfig(PORTD, BTN_two, &button_config);
	PORT_SetPinInterruptConfig(PORTD, BTN_two, kPORT_InterruptFallingEdge);
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
