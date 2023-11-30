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
#include <fsl_rnga.h>

typedef struct {
	uint8_t x;
	uint8_t y;
}XY_position_t;


void MENU_game_settings(void);

void MENU_SetLevel(void);

void MENU_PrintLevel(uint8_t level);

void MENU_print_game_over(void);

void MENU_SetSpeed(void);

void MENU_PrintSpeed(uint8_t speed);

void MENU_init(void);

void MENU_add_virus(uint8_t virus);

XY_position_t MENU_get_virus_position(void);

void MENU_add_pill(void);

void MENU_down_pill(void);

void MENU_game_reset(void);

void MENU_move_left(void);

void MENU_move_right(void);

void MENU_add_left(uint32_t position,uint8_t pill,uint8_t part);

void MENU_add_right(uint32_t position,uint8_t pill,uint8_t part);

void MENU_add_up(uint32_t position,uint8_t pill,uint8_t part);

void MENU_add_down(uint32_t position,uint8_t pill,uint8_t part);

void MENU_clean_pill(uint32_t position);

void MENU_flip(void);

void MENU_flip2(void);

void MENU_track(uint32_t position, uint8_t pill);

void MENU_track_virus(uint32_t position, uint8_t virus);

void MENU_check_pill(void);

void MENU_state_machine(void);

void MENU_change_state(void);

uint8_t MENU_return_flag(void);

void MENU_startGame();

#endif /* MENU_H_ */
