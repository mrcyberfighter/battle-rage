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

#include "./global_fighters.h"

Input_Handler *input_handler = new Input_Handler{} ;

// Joystick 1 (index 0) configuration variables:
int8_t joy_1_buttonA{-1} ;
int8_t joy_1_buttonB{-1} ;
int8_t joy_1_buttonC{-1} ;
int8_t joy_1_buttonD{-1} ;

int8_t joy_1_axis_X_forward{0}  ;
int8_t joy_1_axis_X_backward{0} ;

int8_t joy_1_axis_Y_upward{0}   ;
int8_t joy_1_axis_Y_downward{0} ;

int8_t joy_1_stick_x{0} ;
int8_t joy_1_stick_y{0} ;


// Joystick 2 (index 1) configuration variables:
int8_t joy_2_buttonA{-1} ;
int8_t joy_2_buttonB{-1} ;
int8_t joy_2_buttonC{-1} ;
int8_t joy_2_buttonD{-1} ;

int8_t joy_2_axis_X_forward{0}  ;
int8_t joy_2_axis_X_backward{0} ;

int8_t joy_2_axis_Y_upward{0}   ;
int8_t joy_2_axis_Y_downward{0} ;

int8_t joy_2_stick_x{0} ;
int8_t joy_2_stick_y{0} ;


// Battle sound effects containers:
std::unordered_map<int8_t, Mix_Chunk *> hit_sound_container ;
std::unordered_map<int8_t, Mix_Chunk *> kick_sound_container ;

// Game settings variables:
int8_t game_difficulty{0} ;
int8_t game_speed{0}      ;
bool game_sounds{true} ;
bool game_music{true} ;

// Game music:
Mix_Music *music = NULL ;