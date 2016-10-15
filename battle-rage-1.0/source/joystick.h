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

#ifndef BATTLE_RAGE_JOYSTICKS_HH
#define BATTLE_RAGE_JOYSTICKS_HH

#include "./global_fighters.h"

#include "./Input_Handler.h"

/** The problem comes when you play with 2 players.
extern void get_input_axis_x(Fighters* fighter, int joy, int stick) ;

extern void get_input_axis_y(Fighters* fighter, int joy, int stick) ;
*/

extern void get_buttons(Fighters* fighter, int8_t joy) ;

extern void select_key_from_joy_combination_1(Fighters* fighter) ;
extern void select_key_from_joy_combination_2(Fighters* fighter) ;

#endif