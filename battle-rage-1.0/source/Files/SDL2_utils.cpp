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

#include "SDL2_utils.h"

int sdl_init(uint32_t flags) {
  /**
   * Flags
   * SDL_INIT_TIMER            timer subsystem
   * SDL_INIT_AUDIO            audio subsystem
   * SDL_INIT_VIDEO            video subsystem
   * SDL_INIT_JOYSTICK         joystick subsystem
   * SDL_INIT_HAPTIC           haptic (force feedback) subsystem
   * SDL_INIT_GAMECONTROLLER   controller subsystem
   * SDL_INIT_EVENTS           events subsystem
   * SDL_INIT_EVERYTHING       all of the above subsystems
   * SDL_INIT_NOPARACHUTE      don't catch fatal signals
   *******************************************************************/
   return SDL_Init(flags) ;
}

SDL_Window* sdl_create_window(const char *title,int screen_x_pos, int screen_y_pos, int width, int height,int flags) {

  /**
   * screen_x_pos && screen_y_pos == SDL_WINDOWPOS_CENTERED or SDL_WINDOWPOS_UNDEFINED ;
   *
   * flags :
   * SDL_WINDOW_FULLSCREEN          fullscreen window
   * SDL_WINDOW_FULLSCREEN_DESKTOP  fullscreen window at the current desktop resolution
   * SDL_WINDOW_OPENGL              window usable with OpenGL context
   * SDL_WINDOW_HIDDEN              window is not visible
   * SDL_WINDOW_BORDERLESS          no window decoration
   * SDL_WINDOW_RESIZABLE           window can be resized
   * SDL_WINDOW_MINIMIZED           window is minimized
   * SDL_WINDOW_MAXIMIZED           window is maximized
   * SDL_WINDOW_INPUT_GRABBED       window has grabbed input focus
   * SDL_WINDOW_ALLOW_HIGHDPI       window should be created in high-DPI mode if supported (>= SDL 2.0.1)
   **********************************************************************************************************/

  return SDL_CreateWindow(title, screen_x_pos, screen_y_pos, width, height, flags) ;
}

SDL_Renderer* sdl_create_renderer(SDL_Window *window,int index,int flags) {

   /**
    * index : the index of the rendering driver to initialize, or -1 to initialize the first one supporting the requested flags
    *
    * flags
    * SDL_RENDERER_SOFTWARE       the renderer is a software fallback
    * SDL_RENDERER_ACCELERATED    the renderer uses hardware acceleration
    * SDL_RENDERER_PRESENTVSYNC   present is synchronized with the refresh rate
    * SDL_RENDERER_TARGETTEXTURE  the renderer supports rendering to texture
    *
    * Note that providing no flags gives priority to available SDL_RENDERER_ACCELERATED renderers.
    **********************************************************************************************/

   return SDL_CreateRenderer(window,(index != -1) ? index : -1 , (flags == 0) ? SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC : flags ) ;
}

void clear(SDL_Renderer *pRenderer,uint8_t bg_red, uint8_t bg_green, uint8_t bg_blue,uint8_t bg_alpha) {
  SDL_SetRenderDrawColor(pRenderer, bg_red, bg_green, bg_blue, bg_alpha) ;
  SDL_RenderClear(pRenderer);
}

void display(SDL_Renderer *pRenderer) {
  SDL_RenderPresent(pRenderer);
}

void update(SDL_Window *pWindow) {
  SDL_UpdateWindowSurface(pWindow);
}

void clean_up(SDL_Renderer *pRenderer, SDL_Window *pWindow) {
  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(pWindow);
}