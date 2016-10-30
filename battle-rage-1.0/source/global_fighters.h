/** ***********************************************************************************
  *                                                                                   *    
  * battle-rage a fighting duels game. with battle-rage, the battle rages on !        *
  * Copyright (C) 2016 Brüggemann Eddie <mrcyberfighter@gmail.com>                    *
  *                                                                                   *
  * This file is part of battle-rage.                                                 *
  * battle-rage is free software: you can redistribute it and/or modify               *
  * it under the terms of the GNU General Public License as published by              *
  * the Free Software Foundation, either version 3 of the License, or                 *
  * (at your option) any later version.                                               *
  *                                                                                   *
  * battle-rage is distributed in the hope that it will be useful,                    *
  * but WITHOUT ANY WARRANTY; without even the implied warranty of                    *
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                      *
  * GNU General Public License for more details.                                      *
  *                                                                                   *
  * You should have received a copy of the GNU General Public License                 *
  * along with battle-rage. If not, see <http://www.gnu.org/licenses/>                *
  *                                                                                   *
  *************************************************************************************/

#ifndef BATTLE_RAGE_GLOBAL_FIGHTERS_HH
#define BATTLE_RAGE_GLOBAL_FIGHTERS_HH

#include "./Fighters/Fighters.h"

#include "./Fighters/Fuuma.h"
#include "./Fighters/Geese_Howard.h"
#include "./Fighters/Hanzo.h"
#include "./Fighters/Hotaru_Futaba.h"
#include "./Fighters/Iori_Yagami.h"
#include "./Fighters/K.h"
#include "./Fighters/Kim_Kaphwan.h"
#include "./Fighters/Kisarah_Westfield.h"
#include "./Fighters/Kyo_Kusanagi.h"
#include "./Fighters/Lee_Pai_Long.h"
#include "./Fighters/Mai_Shiranui.h"
#include "./Fighters/Mr_Big.h"
#include "./Fighters/Mr_Karate.h"
#include "./Fighters/Robert_Garcia.h"
#include "./Fighters/Rock_Howard.h"
#include "./Fighters/Terry_Bogard.h"

#include "./Input_Handler.h"

extern Input_Handler* input_handler ;


// Joystick 1 (index 0) configuration variables:
extern int8_t joy_1_buttonA ;
extern int8_t joy_1_buttonB ;
extern int8_t joy_1_buttonC ;
extern int8_t joy_1_buttonD ;

extern int8_t joy_1_axis_X_forward  ;
extern int8_t joy_1_axis_X_backward ;
extern int8_t joy_1_axis_Y_upward   ;
extern int8_t joy_1_axis_Y_downward ;

extern int8_t joy_1_stick_x ;
extern int8_t joy_1_stick_y ;



// Joystick 2 (index 1) configuration variables:
extern int8_t joy_2_buttonA ;
extern int8_t joy_2_buttonB ;
extern int8_t joy_2_buttonC ;
extern int8_t joy_2_buttonD ;

extern int8_t joy_2_axis_X_forward  ;
extern int8_t joy_2_axis_X_backward ;
extern int8_t joy_2_axis_Y_upward   ;
extern int8_t joy_2_axis_Y_downward ;

extern int8_t joy_2_stick_x ;
extern int8_t joy_2_stick_y ;

// Battle sound effects containers:
extern std::unordered_map<int8_t, Mix_Chunk *> hit_sound_container ;
extern std::unordered_map<int8_t, Mix_Chunk *> kick_sound_container ;

// Game settings variables:
extern int8_t game_difficulty ;
extern int8_t game_speed ;
extern bool game_sounds ;
extern bool game_music ;

// Game music:
extern Mix_Music *music ;

#endif