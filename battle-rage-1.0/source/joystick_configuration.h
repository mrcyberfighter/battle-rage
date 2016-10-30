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

#ifndef BATTLE_RAGE_JOYSTICK_CONFIGURATION_HH  /** Inclusion gaurd **/
#define BATTLE_RAGE_JOYSTICK_CONFIGURATION_HH

#include "./headers/includes.h"

#include "./headers/defines.h"

#include "./global_vars.h"

#include "./global_fighters.h"

#include "./Files/draw_rect.h"
#include "./Files/images_utils.h"
#include "./Files/ttf_utils.h"
#include "./Files/SDL2_utils.h"

#include <fstream>

extern bool configure_joystick(const int8_t joy, bool reconfigure=false) ;

extern void write_new_joystick_configuration(const int8_t joy) ;

extern void read_joystick_configuration(const int8_t joy) ;

extern bool is_joystick_know(const int8_t joy) ;

extern void reconfigure_joystick_file(const int8_t joy) ;

#endif