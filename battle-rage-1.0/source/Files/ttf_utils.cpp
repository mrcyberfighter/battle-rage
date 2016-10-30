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

#include "ttf_utils.h"

void configure_text(SDL_Renderer *pRenderer, Text *text, const char *string, SDL_Color color, uint16_t x, uint16_t y, bool middle) {


  if (text->font_texture  != nullptr) {

    SDL_DestroyTexture(text->font_texture) ;

  }


  /** Function to configure the text.    **/

  text->text         = string        ;   /**  Text to display. **/

  text->text_color.r = color.r       ;   /**  Red color.       **/
  text->text_color.g = color.g       ;   /**  Green color.     **/
  text->text_color.b = color.b       ;   /**  Blue color.      **/
  text->text_color.a = color.a       ;   /**  Alpha color.     **/



  SDL_Surface* text_surface   = TTF_RenderText_Blended(text->font, text->text, text->text_color);

  if ( text_surface == nullptr ) {
  
    fprintf(stdout,"\n%s(...) text: %s\n\nstring: %s\n\n", __func__, text->text, string) ;
  
    fprintf(stderr, "\nUnable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    return ;
  }

  text->font_texture  = SDL_CreateTextureFromSurface( pRenderer, text_surface );

  if ( text->font_texture == nullptr ) {
    fprintf(stderr,"Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
    return ;
  }
  else {

    text->width  = text_surface->w  ;
    text->height = text_surface->h ;

    if (middle) {

      text->x=  x  - text_surface->w/2  ;  /** X position from text to display. **/
      text->y=  y  - text_surface->h    ;  /** Y position from text to display. **/
    }
    else {

      text->x=  x   ;  /** X position from text to display. **/
      text->y=  y   ;  /** Y position from text to display. **/
    }

    SDL_FreeSurface(text_surface) ;

  }

  return ;

}

void configure_text_wrap(SDL_Renderer *pRenderer, Text *text, const char *string, SDL_Color color, uint16_t x, uint16_t y, uint32_t wrapLength, bool middle) {


  if (text->font_texture  != nullptr) {

    SDL_DestroyTexture(text->font_texture) ;

  }


  /** Function to configure the text.    **/

  text->text         = string        ;   /**  Text to display. **/

  text->text_color.r = color.r       ;   /**  Red color.       **/
  text->text_color.g = color.g       ;   /**  Green color.     **/
  text->text_color.b = color.b       ;   /**  Blue color.      **/
  text->text_color.a = color.a       ;   /**  Alpha color.     **/



  SDL_Surface* text_surface  = TTF_RenderText_Blended_Wrapped(text->font, text->text, text->text_color, wrapLength);

  if (text_surface == nullptr) {

    text_surface = TTF_RenderUTF8_Blended_Wrapped(text->font, text->text, text->text_color, wrapLength/2) ;

  }

  if ( text_surface == nullptr ) {
  
    fprintf(stdout,"\n%s(...) text: %s\n\nstring: %s\n\n", __func__, text->text, string) ;
  
    fprintf(stderr, "\nUnable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    return ;
  }

  text->font_texture  = SDL_CreateTextureFromSurface( pRenderer, text_surface );

  if ( text->font_texture == nullptr ) {
    fprintf(stderr,"Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
    return ;
  }
  else {

    text->width  = text_surface->w  ;
    text->height = text_surface->h  ;

    if (middle) {

      text->x=  x  - text_surface->w/2  ;  /** X position from text to display. **/
      text->y=  y  - text_surface->h    ;  /** Y position from text to display. **/
    }
    else {

      text->x=  x   ;  /** X position from text to display. **/
      text->y=  y   ;  /** Y position from text to display. **/
    }


    SDL_FreeSurface(text_surface) ;

  }

  return ;

}


void render_text(SDL_Renderer *pRenderer, Text *text) {

  /** Function to render any text given as argument. **/

  SDL_Rect textrect;

  textrect.x = text->x ;
  textrect.y = text->y ;
  textrect.w = text->width  ;
  textrect.h = text->height ;

  SDL_RenderCopy(pRenderer, text->font_texture, nullptr, &textrect) ;

  return ;
}

void init_text(Text *text) {

  text->font_texture = nullptr ;
  text->text = nullptr ;

  return ;
}

void destroy_text(Text *text) {

  if (text != nullptr) {

    if (text->font_texture  != nullptr) {

      SDL_DestroyTexture(text->font_texture) ;

    }

    if (text->font != nullptr) {

      TTF_CloseFont(text->font) ;
    }

    free(text) ;

  }

  return ;

}