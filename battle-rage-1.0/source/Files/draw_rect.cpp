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

#include "draw_rect.h"

void draw_filled_rect_with_border(SDL_Renderer *pRenderer, uint16_t x, int16_t y, int16_t width, int16_t height,int16_t borderwidth, SDL_Color rect_color, SDL_Color border_color) {

  /** Function to display an rectangle with 4 borders (left, right, top, bottom) : **/

  /** Setting main rectangle color. **/
  SDL_SetRenderDrawColor(pRenderer,
                         rect_color.r,
                         rect_color.g,
                         rect_color.b,
                         rect_color.a) ;


  /** Main rectangle. **/
  SDL_Rect drawrectfill ;
  drawrectfill.x=x      ;
  drawrectfill.y=y      ;
  drawrectfill.w=width  ;
  drawrectfill.h=height ;

  SDL_RenderFillRect(pRenderer,&drawrectfill) ;



  /** Setting borders rectangles color. **/
  SDL_SetRenderDrawColor(pRenderer,
                         border_color.r,
                         border_color.g,
                         border_color.b,
                         border_color.a ) ;


  /** Border rectangle at the top. */
  SDL_Rect border_rect_1 ;
  border_rect_1.x = x                       ;
  border_rect_1.y = y                       ;
  border_rect_1.w = width                   ;
  border_rect_1.h = borderwidth             ;

  /** Border rectangle at the right. **/
  SDL_Rect border_rect_2 ;
  border_rect_2.x = x + width-borderwidth  ;
  border_rect_2.y = y                      ;
  border_rect_2.w = borderwidth            ;
  border_rect_2.h = height                 ;

  /** Border rectangle at the bottom. **/
  SDL_Rect border_rect_3 ;
  border_rect_3.x = x                      ;
  border_rect_3.y = y + height-borderwidth ;
  border_rect_3.w = width                  ;
  border_rect_3.h = borderwidth            ;

  /** Border rectangle at the left. **/
  SDL_Rect border_rect_4 ;
  border_rect_4.x = x                      ;
  border_rect_4.y = y                      ;
  border_rect_4.w = borderwidth            ;
  border_rect_4.h = height                 ;


  SDL_RenderFillRect(pRenderer,&border_rect_1) ;  /** Border rectangle at the top. */
  SDL_RenderFillRect(pRenderer,&border_rect_2) ;  /** Border rectangle at the right. **/
  SDL_RenderFillRect(pRenderer,&border_rect_3) ;  /** Border rectangle at the bottom. **/
  SDL_RenderFillRect(pRenderer,&border_rect_4) ;  /** Border rectangle at the left. **/

  return ;

}



void draw_rect(SDL_Renderer *pRenderer, int16_t x, int16_t y, int16_t width, int16_t height, SDL_Color color, bool fill) {

  SDL_SetRenderDrawColor(pRenderer,
                         color.r,
                         color.g,
                         color.b,
                         color.a ) ;

  SDL_Rect rect ;

  rect.x = x ;
  rect.y = y ;
  rect.w = width ;
  rect.h = height ;

  if (fill) {
 
    SDL_RenderFillRect(pRenderer, (const SDL_Rect*) &rect) ;
  }
  else {
 
    SDL_RenderDrawRect(pRenderer, (const SDL_Rect*) &rect) ;

  }
 
  return ;

}

