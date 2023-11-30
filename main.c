
#include "menu.h"
#include "clock.h"
#include "dac.h"
#include "pit.h"

int main(void) {

	CLOCK_SetSimSafeDivs();
	GPIO_init();
	CLK_config();
	DAC_init(DAC0);
	PIT_init();
	LCD_nokia_pin_config();
	MENU_init();

	NVIC_set_basepri_threshold(PRIORITY_10);
	NVIC_enable_interrupt_and_priotity(PORTA_IRQ, PRIORITY_5);
	NVIC_enable_interrupt_and_priotity(PORTB_IRQ, PRIORITY_5);
	NVIC_enable_interrupt_and_priotity(PORTC_IRQ, PRIORITY_5);
	NVIC_enable_interrupt_and_priotity(PORTD_IRQ, PRIORITY_5);
	NVIC_enable_interrupt_and_priotity(DMA_CH0_IRQ, PRIORITY_4);
	NVIC_enable_interrupt_and_priotity(PIT_CH0_IRQ,PRIORITY_4);
	NVIC_enable_interrupt_and_priotity(PIT_CH1_IRQ,PRIORITY_4);

	PIT_callback_init(MENU_down_pill);
	GPIO_callback_init(MENU_flip);
	GPIO_callback_init(MENU_move_left);
	GPIO_callback_init(MENU_move_right);
	GPIO_callback_init(MENU_flip2);

	NVIC_global_enable_interrupts;

	while(1){

		MENU_state_machine();
	}
    return 0 ;
}
