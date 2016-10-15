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

#include "./Rock_Howard.h"

Rock_Howard::Rock_Howard(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {


  m_lifebar_color.r={255} ;
  m_lifebar_color.g={64}  ;
  m_lifebar_color.b={64}  ;
  m_lifebar_color.a={176} ;



  add_map_kicks({0,   17},  0)    ;   // Garde stand.


  add_map_kicks({18,  27},  1)    ;   // walking forward.

  add_map_kicks({28,  37},  2)    ;   // walking backward.


  add_map_kicks({48,  48},  3, 2) ;   // go down.


  add_map_kicks({49,  50},  4, 2) ;   // protected in standing.

  add_map_kicks({51,  52},  5, 2) ;   // protected on knees.


  add_map_kicks({100, 104}, 6)    ;   // elbow kick in standing.

  add_map_kicks({151, 160}, 7)    ;   // fist kick to body (little crochet) (back arm).


  add_map_kicks({105,  110}, 8) ;   // fist kick to body (front arm).

  add_map_kicks({161,  171}, 9)    ;   // fist kick to body (big crochet) (back arm).


  add_map_kicks({176,  185}, 10) ;   // uppercut (front arm).




  add_map_kicks({117,  125}, 12) ;   // fist kick to knees on knees (front arm).

  add_map_kicks({111,  116}, 13, 2) ;   // elbow kick to knees (achèvement).



  add_map_kicks({291,  296}, 14)    ;   // foot kick to head (back leg).
  add_map_kicks({354,  365}, 15)    ;   // jump return foot kick to head (front leg).
  add_map_kicks({163,  205}, 16)    ;   // jump foot kick to body (front leg).
  add_map_kicks({206,  217}, 17)    ;   // foot kick to knees on knees (front leg).
  add_map_kicks({280,  290}, 18)    ;   // return foot kick to head (back leg).






  add_map_kicks({131,  137}, 19) ;   // foot kick to knees in standing (back leg).
  add_map_kicks({186,  198}, 20)    ;   // return foot kick to head (back leg).
  add_map_kicks({89,  99}, 21) ;   // foot kick to body (back leg).
  add_map_kicks({142,  150}, 22) ;   // foot kick to knees on knees (front leg).
  add_map_kicks({366,  378}, 23)    ;   // return jump foot kick to knees on knees (front leg).




  add_map_kicks({476,  479}, 31, 2)    ;   // hit at head.
  add_map_kicks({480,  484}, 32, 2)    ;   // hit at body.
  add_map_kicks({485,  488}, 33, 2)    ;   // hit at kness.

  add_map_kicks({489,  492}, 41, 2)     ;   // fall to ground.
  add_map_kicks({495,  498}, 42, 2)     ;   // fall to ground head first.
  add_map_kicks({502,  510}, 43)        ;   // fall turning, backward roulette and re-up.



  add_map_kicks({247,  257}, 51)    ;   // make idiot hand in hair standing.

  add_map_kicks({437,  445}, 52)    ;   // make idiot wish mouth.
  add_map_kicks({452,  475}, 53)    ;   // make idiot gloves on, go into position and hey you !

  //add_map_kicks({258,  265}, 29)    ;   // make idiot hand in hair on knees.
  //add_map_kicks({446,  451}, 54)    ;   // make idiot arms.


  add_map_kicks({498,  498}, 63, 4)     ;   // Down on the ground (dead) !!!



  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-1+6+3+1) ;


  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << std::endl ;
  print_infos() ;
  #endif



  init_kicks_power() ;


}