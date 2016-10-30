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

#ifndef SDL2_UTILS_HH
#define SDL2_UTILS_HH

#include "../headers/includes.h"

#include "../headers/defines.h"

#include "../global_vars.h"

extern int sdl_init(uint32_t flags) ;

extern SDL_Window* sdl_create_window(const char *title,int screen_x_pos, int screen_y_pos, int width, int height,int flags) ;

extern SDL_Renderer* sdl_create_renderer(SDL_Window *window,int index,int flags) ;

extern void clear(SDL_Renderer *pRenderer,uint8_t bg_red, uint8_t bg_green, uint8_t bg_blue,uint8_t bg_alpha) ;

extern void display(SDL_Renderer *pRenderer) ;

extern void update(SDL_Window *pWindow) ;

extern void clean_up(SDL_Renderer *pRenderer, SDL_Window *pWindow) ;

#endif