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

#include "./Hanzo.h"

Hanzo::Hanzo(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {

  m_lifebar_color.r={0}   ;
  m_lifebar_color.g={0}   ;
  m_lifebar_color.b={255} ;
  m_lifebar_color.a={176} ;


  add_map_kicks({0, 4},     0) ;   // Garde stand.


  add_map_kicks({5, 15},    1) ;   // Walking stand.


  add_map_kicks({39, 39},   3, 2) ;  // go down.


  add_map_kicks({44, 47},   4, 2) ;     // protected in standing.

  add_map_kicks({48, 51},   5, 2) ;     // protected  on knees.


  add_map_kicks({84, 87},   6, 2) ;    // defense elbow (age-uke).

  add_map_kicks({118, 122}, 7) ;    // body kick (back arm).


  add_map_kicks({88, 90}, 8, 2) ;    // fist kick standing.

  add_map_kicks({77, 83}, 9) ;    // fist kick body arm streched.


  add_map_kicks({123, 131}, 10) ;    // uppercut (back arm).

  add_map_kicks({113, 117}, 11) ;    // uppercut (front arm).


  add_map_kicks({91, 92}, 12, 2) ;


  add_map_kicks({171, 175}, 14) ;    // jump foot kick to head (front leg).

  add_map_kicks({218, 232}, 15) ;    // knife kick jumping attack to head (knife out, kicking, and range knife) to head.

  add_map_kicks({238, 245}, 16) ;    // return foot kick to body (front leg).

  add_map_kicks({105, 107}, 17, 2) ;    // foot kick to knees on knees (front leg).

  add_map_kicks({132, 141}, 18) ;    // return foot kick at head (back leg).


  add_map_kicks({99, 104},  19) ;    // foot kick to body (back leg).
  add_map_kicks({206, 217}, 20) ;    // knife kick body (knife out, kicking, and range knife) to head.
  add_map_kicks({142, 149}, 21) ;    // return foot kick at body (back leg).
  add_map_kicks({110, 111}, 22, 2) ;    // foot kick to knees on knees (back leg).
  add_map_kicks({132, 141}, 23) ;    // return foot kick at head (back leg).


  add_map_kicks({292, 295}, 31, 2) ;    // hit by kick at head.
  add_map_kicks({296, 300}, 32, 2) ;    // hit by kick on body.
  add_map_kicks({301, 304}, 33, 2) ;    // hit by kick on knees.

  add_map_kicks({305, 309}, 41, 2)  ;    // final fall (short).
  add_map_kicks({310, 312}, 42, 2)  ;    // fall head first (coup bas).
  add_map_kicks({318, 332}, 43)     ;    // final fall (long) and maybe re-up.


  add_map_kicks({163, 170}, 51)     ;    // make idiot standing.
  add_map_kicks({275, 279}, 52, 2)  ;    // make idiot from back.
  add_map_kicks({280, 286}, 53, 2)  ;    // make idiot front arm at head.

  add_map_kicks({312, 312}, 63, 4)  ;    // Down on the ground (dead) !!!

  //add_map_kicks({287, 291}, 54, 2)  ;    // make idiot front touching the floor or achèvement.


  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-2+6+3+1) ;

  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << '\n' << std::endl ;
  print_infos() ;
  #endif

  init_kicks_power() ;

}