/*
 * menu.h
 *
 *  Created on: 26 nov 2023
 *      Author: arlet
 */

#ifndef MENU_H_
#define MENU_H_

#include "spi.h"
#include "LCD_nokia.h"
#include "gpio.h"

void MENU_init(void);

void MENU_PrintGame(void);

void MENU_SetLevel(void);

void MENU_SetSpeed(void);

void MENU_PrintLevel(uint8_t level);

void MENU_PrintSpeed(uint8_t speed);

#endif /* MENU_H_ */
