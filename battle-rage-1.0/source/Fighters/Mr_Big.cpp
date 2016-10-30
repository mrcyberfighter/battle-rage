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

#include "./Mr_Big.h"

Mr_Big::Mr_Big(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {


  m_lifebar_color.r={196-32}  ;
  m_lifebar_color.g={196-32}  ;
  m_lifebar_color.b={196-32}  ;
  m_lifebar_color.a={176}  ;


  add_map_kicks({0,   1},   0) ;   // Garde stand.


  add_map_kicks({2,  8},    1) ;   // walking forward.


  add_map_kicks({18,  18},  3, 2) ;   // go down.


  add_map_kicks({20,  23},  4, 2) ;   // protected standing.

  add_map_kicks({24,  27},  5, 2) ;   // protected on knees.


  add_map_kicks({203,  213}, 6)    ;   // baton kick to body (back arm).

  add_map_kicks({58,  65},  7) ;   // rotate double baton kick to body.


  add_map_kicks({69,  70}, 8, 2) ;   // baton kick to body (front arm).

  add_map_kicks({226,  236}, 9)    ;   // double baton kick to head (front arm then back arm) .


  add_map_kicks({147,  160}, 10, 2)    ;   // return double baton uppercut with preparation.

  add_map_kicks({237,  246}, 11)    ;   // jump baton uppercut.



  add_map_kicks({108,  111}, 12, 2)    ;   // double baton kick to knees on knees (jumping).

  add_map_kicks({78,  79}, 13, 2) ;   // double baton to knees on knees.


  add_map_kicks({112,  115}, 14) ;   // jump baton kick to head (front arm).
  add_map_kicks({277,  285}, 15)    ;   // baton kicks to head (front arm back arm).
  add_map_kicks({256,  263}, 16)    ;   // baton kick to body.
  add_map_kicks({116,  123}, 17) ;   // baton kick to knees on knees (front arm).
  add_map_kicks({161,  171}, 18)    ;   // return baton kick to body (double baton).



  add_map_kicks({71,  73},   19, 2) ;   // baton kick to body (front arm).
  add_map_kicks({250,  255}, 20)    ;   // rotate baton kick to head (double baton).
  add_map_kicks({189,  202}, 21)    ;   // return baton kick to body (double baton).
  add_map_kicks({135,  146}, 22)    ;   // foot kick to knees on knees (back leg).
  add_map_kicks({94,  107},  23)    ;   // return double baton kick to head and then to body.





  add_map_kicks({325,  328}, 31, 2)        ;   // hit at head.
  add_map_kicks({329,  333}, 32, 2)        ;   // hit at body.
  add_map_kicks({334,  337}, 33, 2)        ;   // hit at knees.


  add_map_kicks({338,  341}, 41, 2)     ;   // fall to ground.
  add_map_kicks({343,  346}, 42, 2)     ;   // fall to ground head first.
  add_map_kicks({349,  359}, 43)        ;   // fall turning roulette and re-up.



  add_map_kicks({263,  276}, 51)      ;   // make idiot dance batons in the air.
  add_map_kicks({290,  306}, 52)      ;   // make idiot batons cross and then to ground.
  add_map_kicks({314,  324}, 53, 2)   ;   // make idiot output batons.

  add_map_kicks({346,  346}, 63, 2)     ;   // Down on the ground (dead) !!!



  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-1+6+3+1) ;


  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << std::endl ;
  print_infos() ;
  #endif



  init_kicks_power() ;

}