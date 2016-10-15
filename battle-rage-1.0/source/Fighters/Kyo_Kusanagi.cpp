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

#include "./Kyo_Kusanagi.h"

Kyo_Kusanagi::Kyo_Kusanagi(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {


  m_lifebar_color.r={128+32}   ;
  m_lifebar_color.g={128+32}   ;
  m_lifebar_color.b={255}      ;
  m_lifebar_color.a={176}      ;



  add_map_kicks({0,   7},  0)     ;   // Garde stand.


  add_map_kicks({8,   10},  1)    ;   // walking.


  add_map_kicks({32,  32},  3, 2) ;   // go down.


  add_map_kicks({39,  43},  4, 2) ;   // protected standing.

  add_map_kicks({44,  48},  5, 2) ;   // protected on knees.


  add_map_kicks({82,  83},  6, 2) ;   // fist kick to body.

  add_map_kicks({252, 264}, 7)    ;   // return fist kick to head (back arm).


  add_map_kicks({103, 106}, 8)    ;   // fist kick at body (front arm).

  add_map_kicks({274,  287}, 9)    ;   // fist kick to body.



  add_map_kicks({288,  300}, 10)    ;   // big uppercut (from up to down).

  add_map_kicks({109,  113}, 11) ;   // uppercut from down (back arm).



  add_map_kicks({107,  108}, 12, 2)    ;   // fist kick to knees on knees (jumping).

  add_map_kicks({89,  90}, 13, 2) ;   // fist kick to knees on knees (front arm).





  add_map_kicks({95, 96},   14, 2) ;   // knees kick to body (front leg).
  add_map_kicks({153, 166}, 15)    ;   // double foot kick to head (front leg).
  add_map_kicks({239, 251}, 16)    ;   // return foot kick to body (back leg).
  add_map_kicks({134, 142}, 17)    ;   // foot kick to knees on knees (front leg).
  add_map_kicks({130, 133}, 18, 2)    ;   // jump return foot kick to head (front leg).



  add_map_kicks({114,  122}, 19) ;   // foot kick to body (back leg).
  add_map_kicks({183,  190}, 20)    ;   // double jump foot kick to head (back and front leg).
  add_map_kicks({167,  173}, 21, 2)    ;   // return jump foot kick to knees on knees (front leg).
  add_map_kicks({146,  152}, 22)    ;   // double foot kick to knees on knees.
  add_map_kicks({123,  129}, 23, 2) ;   // jump return foot kick at body (front leg).




  add_map_kicks({407,  409}, 31, 2)     ;   // hit at head.
  add_map_kicks({410,  413}, 32, 2)     ;   // hit at body.
  add_map_kicks({414,  418}, 33, 2)     ;   // hit at knees.

  add_map_kicks({419,  422}, 41, 2)     ;   // fall on the ground.
  add_map_kicks({425,  428}, 42, 2)     ;   // fall on the ground head first.
  add_map_kicks({432,  437}, 43)        ;   // fall and turning.



  add_map_kicks({375,  382}, 51)    ;   // make idiot fist in the air.
  add_map_kicks({383,  399}, 52, 2)    ;   // make idiot shirt.
  add_map_kicks({400,  406}, 53)    ;   // make idiot wish air.


  add_map_kicks({428,  428}, 63, 4)    ;   // Down on the ground (dead) !!!




  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-1+6+3+1) ;

  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << '\n' << std::endl ;
  print_infos() ;
  #endif


  init_kicks_power() ;


}