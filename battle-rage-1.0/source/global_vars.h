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

#ifndef __BATTLE_RAGE_1_0_0_GLOBAL_VARS_HH__  /** Inclusion guard **/
#define __BATTLE_RAGE_1_0_0_GLOBAL_VARS_HH__

#include "./headers/defines.h"
#include "./headers/includes.h"


extern SDL_Window* pWindow ;

extern SDL_Renderer *pRenderer ;

// Joysticks configure main variables:
extern int8_t buttonA ;
extern int8_t buttonB ;
extern int8_t buttonC ;
extern int8_t buttonD ;

extern int8_t axis_X_forward ;
extern int8_t axis_X_backward ;

extern int8_t axis_Y_upward ;
extern int8_t axis_Y_downward ;

extern int8_t stick_x ;
extern int8_t stick_y ;

// Set music ON/OFF.
#define PAUSE_MUSIC ( (Mix_PausedMusic()) ? Mix_ResumeMusic() : Mix_PauseMusic() ) ;

#endif /** Inclusion guard **/