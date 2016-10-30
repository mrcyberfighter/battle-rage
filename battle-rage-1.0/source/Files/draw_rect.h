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

#ifndef SDL2_UTILS_DRAW_RECT_HH
#define SDL2_UTILS_DRAW_RECT_HH

#include "../headers/includes.h"

extern void draw_filled_rect_with_border(SDL_Renderer *pRenderer, uint16_t x, int16_t y, int16_t width, int16_t height,int16_t borderwidth, SDL_Color rect_color, SDL_Color border_color) ;

extern void draw_rect(SDL_Renderer *pRenderer, int16_t x, int16_t y, int16_t width, int16_t height, SDL_Color color, bool fill=false) ;

#endif