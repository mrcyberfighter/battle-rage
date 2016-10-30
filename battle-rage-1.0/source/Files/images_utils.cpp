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

#include "images_utils.h"


SDL_Texture *get_texture_with_colokey_from_image(SDL_Renderer *pRenderer, const char *filepath, SDL_Color colorkey) {
  /** Generate an SDL_Texture object from an image filepath. **/

  SDL_Surface *image_surface = IMG_Load(filepath);

  if (image_surface == NULL) {
    /** Display an error message and quit the program in case of error. **/
    char *message=(char *) calloc(256,sizeof(char)) ;
    sprintf(message,"Failed to load image %s!\n%s",filepath,SDL_GetError()) ;
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error image loading", message ,NULL) ;
    free(message) ;
    exit(EXIT_FAILURE) ;

  }

  uint32_t key = SDL_MapRGB(image_surface->format, colorkey.r, colorkey.g, colorkey.b) ;

  SDL_SetColorKey(image_surface, SDL_TRUE, key) ;


  SDL_Texture *image_texture = SDL_CreateTextureFromSurface(pRenderer, image_surface) ;

  if (image_texture == NULL) {
    /** Exit the program in case of error. **/
    exit(EXIT_FAILURE) ;

  }

  SDL_FreeSurface(image_surface) ; /** We clean up the surface. **/

  return image_texture ;
}


SDL_Texture *get_texture_from_image(SDL_Renderer *pRenderer, const char *filepath) {

  /** Generate an SDL_Texture object from an image filepath. **/

  SDL_Surface *image_surface = IMG_Load(filepath);

  if (image_surface == NULL) {
    /** Display an error message and quit the program in case of error. **/
    char *message=(char *) calloc(256,sizeof(char)) ;
    sprintf(message,"Failed to load image %s!\n%s",filepath,SDL_GetError()) ;
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error image loading", message ,NULL) ;
    free(message) ;
    exit(EXIT_FAILURE) ;

  }

  SDL_Texture *image_texture = SDL_CreateTextureFromSurface(pRenderer,image_surface) ;


  if ( image_texture == NULL ) {
    /** Exit the program in case of error. **/
    exit(EXIT_FAILURE) ;

  }

  SDL_FreeSurface(image_surface) ; /** We clean up the surface. **/

  return image_texture ;
}



void display_image(SDL_Renderer *pRenderer,SDL_Texture *texture, uint16_t x, uint16_t y, bool middle) {

  /** Function to display an image. **/

  int w, h ;

  SDL_QueryTexture(texture,NULL, NULL,&w, &h) ;

  SDL_Rect     src_rect ;

  src_rect.x = 0 ;
  src_rect.y = 0 ;
  src_rect.w = w ;
  src_rect.h = h ;

  SDL_Rect     dst_rect ;

  if (middle) {
  
    dst_rect.x = x - w / 2 ;
    dst_rect.y = y - h / 2 ;

  }
  else { 

    dst_rect.x = x ;
    dst_rect.y = y ;

  }


  dst_rect.w = w ;
  dst_rect.h = h ;

  SDL_RenderCopy(pRenderer, texture, &src_rect, &dst_rect) ;
  //SDL_RenderCopyEx(pRenderer, texture, NULL, &dst_rect, 0, NULL, SDL_FLIP_NONE) ;
  return ;
}

void display_image_simple_flip(SDL_Renderer *pRenderer,SDL_Texture *texture, uint16_t x, uint16_t y, const SDL_RendererFlip flip) {

  /** Function to display an image. **/

  if (texture == NULL) {
 
    return ;

  }

  int w, h ;

  SDL_QueryTexture(texture,NULL, NULL,&w, &h) ;

  SDL_Rect     src_rect ;

  src_rect.x = 0 ;
  src_rect.y = 0 ;
  src_rect.w = w ;
  src_rect.h = h ;

  SDL_Rect     dst_rect ;

  dst_rect.x = x ;
  dst_rect.y = y ;
  dst_rect.w = w ;
  dst_rect.h = h ;

  SDL_RenderCopyEx(pRenderer,
                   texture,
                   (const SDL_Rect*) &src_rect,
                   (const SDL_Rect*) &dst_rect,
                   0,
                   NULL,
                   (const SDL_RendererFlip) flip) ;
         
  //SDL_RenderCopyEx(pRenderer, texture, NULL, &dst_rect, 0, NULL, SDL_FLIP_NONE) ;
  return ;
}

void display_resized_image(SDL_Renderer *pRenderer, SDL_Texture *texture, int x, int y, double factor) {

  int w, h ;

  SDL_QueryTexture(texture,NULL, NULL,&w, &h) ;

  double factor_image_size = (double) w / (double) h ;

  if (factor_image_size < 0) {
    factor_image_size *= -1 ;
  }

  //fprintf(stdout,"%lf\n",factor_image_size*factor) ;

  SDL_Rect     src_rect ;

  src_rect.x = x ;
  src_rect.y = y ;
  src_rect.w = w ;
  src_rect.h = h ;

  SDL_Rect     dst_rect ;


  dst_rect.x = x ; // + (x+w/2) ;
  dst_rect.y = y ; // + (y+h/2) ;

  dst_rect.w = w * factor ;
  dst_rect.h = h * factor ;

  SDL_RenderCopy(pRenderer,texture,&src_rect,&dst_rect) ;

  return ;

}

void display_horizontal_sprite_image(SDL_Renderer *pRenderer,SDL_Texture *texture, int x, int y, int width, int height, int frame) {

  /** Function to display an image. **/

  int w, h ;

  SDL_QueryTexture(texture,NULL, NULL, &w, &h) ;

  int h_factor  =  w / width ;


  SDL_Rect     src_rect ;


  fprintf(stdout,"x: %d\n",(frame % h_factor) * width) ;
  fprintf(stdout,"y: %d\n",(frame / h_factor) * height) ;

  src_rect.x = (frame % h_factor) * width   ;
  src_rect.y = (frame / h_factor) * height  ;
  src_rect.w = width                ;
  src_rect.h = height               ;

  SDL_Rect     dst_rect ;

  dst_rect.x = x ;
  dst_rect.y = y ;
  dst_rect.w = w ;
  dst_rect.h = height ;

  SDL_RenderCopyEx(pRenderer, texture, &src_rect, &dst_rect, 0, NULL, SDL_FLIP_NONE) ;

  return ;
}

void display_sprites_images(SDL_Renderer *pRenderer, SDL_Texture *texture, int x, int y, int width, int height, int frame) {

  SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_MOD) ;

  int w,h ;

  SDL_QueryTexture(texture,NULL, NULL,&w, &h) ;

  int w_factor  =  w / width  ;


  SDL_Rect     src_rect ;


  //fprintf(stdout,"x: %d\n",(frame % w_factor) * width) ;
  //fprintf(stdout,"y: %d\n",(frame / w_factor) * height) ;

  src_rect.x = (frame % w_factor) * width   ;
  src_rect.y = (frame / w_factor) * height  ;
  src_rect.w = width                ;
  src_rect.h = height               ;




  SDL_Rect     dst_rect ;

  dst_rect.x = x ;
  dst_rect.y = y ;
  dst_rect.w = width ;
  dst_rect.h = height ;






  //SDL_RenderClear(pRenderer) ;
  SDL_RenderCopyEx(pRenderer, texture, &src_rect, &dst_rect,0, NULL, SDL_FLIP_NONE) ;

  SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_NONE) ;


  return ;

}

void display_image_with_color_mode(SDL_Renderer *pRenderer, SDL_Texture *texture, int x, int y, uint8_t r, uint8_t g, uint8_t b) {

  SDL_SetTextureColorMod(texture, r, g, b) ;

  int w, h ;

  SDL_QueryTexture(texture, NULL, NULL, &w, &h) ;

  SDL_Rect     src_rect ;

  src_rect.x = 0 ;
  src_rect.y = 0 ;
  src_rect.w = w ;
  src_rect.h = h ;

  SDL_Rect     dst_rect ;

  dst_rect.x = x ;
  dst_rect.y = y ;
  dst_rect.w = w ;
  dst_rect.h = h ;

  SDL_RenderCopy(pRenderer, texture, &src_rect, &dst_rect) ;
  //SDL_RenderCopyEx(pRenderer, texture, NULL, &dst_rect, 0, NULL, SDL_FLIP_NONE) ;
  return ;

}

