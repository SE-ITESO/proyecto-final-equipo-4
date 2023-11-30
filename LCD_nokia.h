

#ifndef LCD_NOKIA_H_
#define LCD_NOKIA_H_

#include "stdint.h"
#include "spi.h"

#define LCD1_CE		0u   /*!< Pin number for pin 0 in a port */
#define LCD_CLK		1u   /*!< Pin number for pin 1 in a port */
#define LCD_DIN		2u   /*!< Pin number for pin 2 in a port */
#define LCD2_CE		3u   /*!< Pin number for pin 3 in a port */

#define LCD_TRANSFER_SIZE     8U     /*! Transfer dataSize */
#define LCD_TRANSFER_BAUDRATE 2500000U /*! Transfer baudrate - 500k */

#define SCREENW 84
#define SCREENH 48
#define DATA_SIZE 504

#define LCD_X 84
#define LCD_Y 48
#define LCD_DATA 1
#define LCD_CMD 0
#define LCD1_DATA_OR_CMD_PIN 	5
#define LCD1_RESET_PIN 			7
#define LCD2_DATA_OR_CMD_PIN 	2
#define LCD2_RESET_PIN 			4


typedef enum{
	LCD_game,
	LCD_menu
}LCD_t;

/*It configures the LCD*/
void LCD_nokia_pin_config(void);
/*It initialize the LCD*/
void LCD_nokia_init(LCD_t LDC_selected);
/*It writes a byte in the LCD memory. The place of writting is the last place that was indicated by LCDNokia_gotoXY. In the reset state
 * the initial place is x=0 y=0*/
void LCD_nokia_write_byte(uint8_t data_or_command, uint8_t data,LCD_t LDC_selected);
/*it clears all the figures in the LCD*/
void LCD_nokia_clear(LCD_t LDC_selected);
/*It is used to indicate the place for writing a new character in the LCD. The values that x can take are 0 to 84 and y can take values
 * from 0 to 5*/
void LCD_nokia_goto_xy(uint8_t x, uint8_t y,LCD_t LDC_selected);
/*It allows to write a figure represented by constant array*/
void LCD_nokia_bitmap(const uint8_t bitmap[], LCD_t LDC_selected);
/*It write a character in the LCD*/
void LCD_nokia_send_char(uint8_t character, LCD_t LDC_selected);
/*It write a string into the LCD*/
void LCD_nokia_send_string(const uint8_t characters [],LCD_t LDC_selected);
/*It used in the initialization routine*/
void LCD_nokia_delay(void);



#endif /* LCD_NOKIA_H_ */
