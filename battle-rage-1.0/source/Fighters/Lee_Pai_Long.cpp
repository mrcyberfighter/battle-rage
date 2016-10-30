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

#include "./Lee_Pai_Long.h"

Lee_Pai_Long::Lee_Pai_Long(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {

  m_lifebar_color.r={196}    ;
  m_lifebar_color.g={196}    ;
  m_lifebar_color.b={128+32} ;
  m_lifebar_color.a={176}    ;




  add_map_kicks({0,   3},   0)    ;   // Garde stand.


  add_map_kicks({4,   6},   1)    ;   // walking.


  add_map_kicks({21,  21},  3, 2) ;   // go down.


  add_map_kicks({26,  29},  4, 2) ;   // protected standing.

  add_map_kicks({30,  33},  5, 2) ;   // protected on knees.


  add_map_kicks({102,  106}, 6)    ;   // fist kick to body (front arm).

  add_map_kicks({107, 113}, 7)    ;   // fist kick to body (back arm).


  add_map_kicks({85,  87}, 8, 2) ;   // fist kick to body (front arm).

  add_map_kicks({204,  215}, 9)    ;   // triple fist kick to head, body, knees (front arm).


  add_map_kicks({176,  185}, 10)    ;   // double hand with griffe uppercut.

  add_map_kicks({74,  84}, 11) ;   // uppercut with griffe at hand (back arm).


  add_map_kicks({237,  244}, 12, 2)    ;   // double griffe kick to knees (jumping) (or achèvement).

  add_map_kicks({91, 92}, 13, 2) ;   // fist kick to knees on knees.











  add_map_kicks({128,  133}, 14)    ;   // foot kick to head (front leg).
  add_map_kicks({216,  228}, 15)    ;   // jump double foot kick to head (front and back leg).
  add_map_kicks({146,  154}, 16)    ;   // return jump foot kick to body.
  add_map_kicks({100,  101}, 17, 2) ;   // foot kick to knees on knees (front leg).
  add_map_kicks({134,  141}, 18)    ;   // jump return foot kick to body (front leg).





  add_map_kicks({93,   97}, 19) ;   // foot kick to head (front leg).
  add_map_kicks({186, 190}, 20)    ;   // jump foot kick to head (back leg).
  add_map_kicks({98,   99}, 21, 2) ;   // jump foot kick to body (front leg).
  add_map_kicks({142, 145}, 22)    ;   // jump foot kick to knees (front leg).
  add_map_kicks({191, 203}, 23)    ;   // griffes out roulette and extension with griffes to head from knees.





  add_map_kicks({291,  294}, 31, 2)    ;   // hit at head.
  add_map_kicks({295,  299}, 32, 2)    ;   // hit at body.
  add_map_kicks({300,  303}, 33, 2)    ;   // hit at knees.


  add_map_kicks({304,  308}, 41)    ;   // fall .
  add_map_kicks({309,  311}, 42)    ;   // fall head first.
  add_map_kicks({318,  329}, 43)    ;   // falling turning and backward roulette.


  add_map_kicks({275,  278}, 51, 2)     ;   // make idiot knick head.
  add_map_kicks({279,  284}, 52, 2)     ;   // make idiot hands to head.
  add_map_kicks({285,  290}, 53)        ;   // make idiot coming fighting.



  add_map_kicks({311,  311}, 63, 1)        ;   // Down on the ground (dead) !!!



  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-1+6+3+1) ;

  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << '\n' << std::endl ;
  print_infos() ;
  #endif


  init_kicks_power() ;

}