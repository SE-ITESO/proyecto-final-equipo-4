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
#include "spi.h"
#include "LCD_nokia.h"


uint8_t ITESO[] = {
		0xFF,0xFF,0xFF};

int main(void) {

	CLOCK_SetSimSafeDivs();

	uint8_t string_1[] = "ITESO"; /*! String to be printed in the LCD*/
	uint8_t string_2[] = "Sistemas"; /*! String to be printed in the LCD*/
	uint8_t string_3[] = "Embebidos I"; /*! String to be printed in the LCD*/
	uint8_t string_4[] = "IE"; /*! String to be printed in the LCD*/

	LCD_nokia_init(); /*! Configuration function for the LCD */
	LCD_nokia_clear();

    while(1) {

    	LCD_nokia_write_byte(1,0x0F);
		//LCD_nokia_bitmap(ITESO);
		//LCD_nokia_goto_xy(20,0); /*! It establishes the position to print the messages in the LCD*/
		//LCD_nokia_send_string(&string_1[0]); /*! It print a string stored in an array*/


    }
    return 0 ;
}
