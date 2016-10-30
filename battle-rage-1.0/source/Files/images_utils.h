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

#ifndef SDL2_UTILS_IMAGES_UTILS_HH
#define SDL2_UTILS_IMAGES_UTILS_HH

#include "../headers/includes.h"

extern SDL_Texture *get_texture_with_colokey_from_image(SDL_Renderer *pRenderer, const char *filepath, SDL_Color colorkey) ;

extern SDL_Texture *get_texture_from_image(SDL_Renderer *pRenderer, const char *filepath) ;

extern void display_image(SDL_Renderer *pRenderer,SDL_Texture *texture, uint16_t x, uint16_t y, bool middle=false) ;

extern void display_image_simple_flip(SDL_Renderer *pRenderer,SDL_Texture *texture, uint16_t x, uint16_t y, const SDL_RendererFlip flip) ;

extern void display_resized_image(SDL_Renderer *pRenderer, SDL_Texture *texture, int x, int y, double factor) ;

extern void display_horizontal_sprite_image(SDL_Renderer *pRenderer,SDL_Texture *texture, int x, int y, int width, int height, int frame) ;

extern void display_sprites_images(SDL_Renderer *pRenderer, SDL_Texture *texture, int x, int y, int width, int height, int frame) ;

extern void display_image_with_color_mode(SDL_Renderer *pRenderer, SDL_Texture *texture, int x, int y, uint8_t r, uint8_t g, uint8_t b) ;

#endif