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

#include "./Mr_Karate.h"

Mr_Karate::Mr_Karate(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {


  m_lifebar_color.r={196-64}   ;
  m_lifebar_color.g={196-96}   ;
  m_lifebar_color.b={255-32}   ;
  m_lifebar_color.a={176}      ;


  add_map_kicks({0,   3},   0) ;   // Garde stand.


  add_map_kicks({4,  14},   1) ;   // walking forward.


  add_map_kicks({29,  29},  3, 2) ;   // go down.


  add_map_kicks({30,  33},  4, 2) ;   // protected standing.

  add_map_kicks({34,  37},  5, 2) ;   // protected on knees.


  add_map_kicks({103,  109}, 6)    ;   // fist kick to body (back arm).

  add_map_kicks({227,  234}, 7)    ;   // fist kick to head from up to down (front arm).


  add_map_kicks({63,  75}, 8) ;   // fist kick to body in standing (front arm)

  add_map_kicks({168,  175}, 9)    ;   // fist kick to body in standing (front arm).


  add_map_kicks({255,  259}, 10)    ;   // uppercut.

  add_map_kicks({159,  167}, 11)    ;   // little uppercut (back arm).



  add_map_kicks({80,  82}, 12, 2) ;   // fist kick to knees on knees (front arm) with élant.

  add_map_kicks({123,  125}, 13, 2)    ;   // fist kick to knees (jumping) .



  add_map_kicks({85,    92}, 14)  ;   // foot kick to head (front leg).
  add_map_kicks({139,  146}, 15)  ;   // return foot kick to head (back leg).
  add_map_kicks({150,  158}, 17)  ;   // return foot kick to knees on knees (back leg).
  add_map_kicks({130,  138}, 18)  ;   // return foot kick to head (back leg).



  add_map_kicks({93,    96}, 19)        ;   // foot kick to body (back leg).
  add_map_kicks({235,  247}, 21)        ;   // triple fist kick to body, knees and head.
  add_map_kicks({100,  102}, 22, 2)     ;   // foot kick to knees on knees (front leg).
  add_map_kicks({216,  226}, 23, 2)     ;   // jump return double foot kick (front leg, back leg).






  add_map_kicks({327,  330}, 31, 2)    ;   // hit at head.
  add_map_kicks({331,  335}, 32, 2)    ;   // hit at body.
  add_map_kicks({336,  339}, 33, 2)    ;   // hit at knees.

  add_map_kicks({340,  343}, 41, 2)    ;   // fall to ground.
  add_map_kicks({346,  349}, 42, 2)    ;   // fall to ground head first.
  add_map_kicks({355,  367}, 43, 2)    ;   // fall and turning and re-up.



  add_map_kicks({314,  326}, 51)    ;   // make idiot coming fighting.
  add_map_kicks({309,  313}, 52, 2)    ;   // make idiot arms cross on head then go down.
  add_map_kicks({190,  206}, 53)    ;   // make idiot kata.

  //add_map_kicks({295,  305}, 54)      ;   // make idiot kata 2.

  add_map_kicks({349,  349}, 63, 4)    ;   // Down on the ground (dead) !!!




  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-3+6+3+1) ;


  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << std::endl ;
  print_infos() ;
  #endif

  init_kicks_power() ;


}