/**
 * @file    Project_DrMario.c
 *
 * @author	Arlette Uribe & Pablo Ramos
 *
 * @brief   Application entry point.
 */

#include <stdio.h>
#include <stdint.h>
#include "MK64F12.h"
#include "fsl_clock.h"
#include "menu.h"
#include "gpio.h"
#include "nvic.h"

int main(void) {

	CLOCK_SetSimSafeDivs();
	GPIO_init();

	LCD_nokia_init(); /*! Configuration function for the LCD */

	MENU_init();

	NVIC_set_basepri_threshold(PRIORITY_10);
	NVIC_enable_interrupt_and_priotity(PORTA_IRQ, PRIORITY_5);
	NVIC_enable_interrupt_and_priotity(PORTB_IRQ, PRIORITY_5);
	NVIC_enable_interrupt_and_priotity(PORTC_IRQ, PRIORITY_5);
	NVIC_enable_interrupt_and_priotity(PORTD_IRQ, PRIORITY_5);
	NVIC_global_enable_interrupts;

    while(1) {

    	if(GPIO_Get_irq_status(GPIO_A)){
    		MENU_SetSpeed();
    		GPIO_Clear_irq_status(GPIO_A);
    	}

    }
    return 0 ;
}
