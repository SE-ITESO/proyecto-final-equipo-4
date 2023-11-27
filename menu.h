/*
 * menu.h
 *
 *  Created on: 6 nov. 2023
 *      Author: Ray
 */

#ifndef MENU_H_
#define MENU_H_

#include "LCD_nokia.h"
#include "gpio.h"
#include "spi.h"
#include "nvic.h"
#include "memory.h"


void MENU_init(void);

void MENU_add_virus(void);

void MENU_add_pill(void);

void MENU_down_pill(void);

void MENU_game_reset(void);

void MENU_check_pill(void);

void MENU_move_left(void);

void MENU_move_right(void);

void MENU_add_left(uint32_t position,uint8_t pill,uint8_t part);

void MENU_add_right(uint32_t position,uint8_t pill,uint8_t part);

void MENU_add_up(uint32_t position,uint8_t pill,uint8_t part);

void MENU_add_down(uint32_t position,uint8_t pill,uint8_t part);

void MENU_clean_pill(uint32_t position);
#endif /* MENU_H_ */
