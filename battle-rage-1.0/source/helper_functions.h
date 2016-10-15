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

#ifndef BATTLE_RAGE_HELPER_FUNCTION_HH
#define BATTLE_RAGE_HELPER_FUNCTION_HH

#include "./headers/includes.h"

#include "./Fighters/Fighters.h"

#include "./global_fighters.h"

#include "./Files/SDL2_utils.h"

#include <ctime>
#include <fstream>

extern void check_intersections(Fighters* fighter1, Fighters* fighter2, int8_t& fighter_win_round) ;

extern void fighter_2_compute_reactions(const int8_t fighter2_action, const int16_t fighter2_x, Fighters* fighter1) ;

extern void computer_vs_computer(const int8_t adversary_action, const int16_t adversary_x, Fighters* fighter) ;

extern void display_fighter(SDL_Renderer *pRenderer, SDL_Texture *texture, const int16_t x, SDL_RendererFlip flip = SDL_FLIP_NONE) ;

extern void construct_map_sound(void) ;

extern void write_game_configuration_to_file(void) ;

extern void at_exit(void) ;

#endif