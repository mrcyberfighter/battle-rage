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

#ifndef SDL2_UTILS_TTF_UTILS_HH
#define SDL2_UTILS_TTF_UTILS_HH

#include "../headers/includes.h"

/**
  *  Text utils for the SDL2_ttf extension.
  *****************************************/

typedef struct Text_ {
  /** Structure for holding text data. **/

  int16_t x ;
  int16_t y ;

  uint16_t width  ;
  uint16_t height ;

  SDL_Texture *font_texture = NULL ;

  TTF_Font *font = NULL ;

  SDL_Color text_color ;

  const char *text = NULL ;

} Text ;



extern void configure_text(SDL_Renderer *pRenderer, Text *text, const char *string, SDL_Color color, uint16_t x, uint16_t y, bool middle=true) ;

extern void render_text(SDL_Renderer *pRenderer, Text *text) ;

extern void configure_text_wrap(SDL_Renderer *pRenderer, Text *text, const char *string, SDL_Color color, uint16_t x, uint16_t y, uint32_t wrapLength, bool middle=false) ;

extern void init_text(Text *text) ;

extern void destroy_text(Text *text) ;

#endif