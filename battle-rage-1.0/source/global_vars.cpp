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

#include "global_vars.h"

SDL_Window *pWindow = NULL ;

SDL_Renderer *pRenderer = NULL  ;


// Joysticks configure main variables:
int8_t buttonA{-1} ;
int8_t buttonB{-1} ;
int8_t buttonC{-1} ;
int8_t buttonD{-1} ;

int8_t axis_X_forward{0} ;
int8_t axis_X_backward{0} ;

int8_t axis_Y_upward{0} ;
int8_t axis_Y_downward{0} ;

int8_t stick_x{-1} ;
int8_t stick_y{-1} ;