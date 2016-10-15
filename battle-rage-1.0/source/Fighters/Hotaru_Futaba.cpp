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

#include "./Hotaru_Futaba.h"

Hotaru_Futaba::Hotaru_Futaba(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {

  m_is_male={false} ;

  m_lifebar_color.r={64}  ;
  m_lifebar_color.g={64}  ;
  m_lifebar_color.b={192} ;
  m_lifebar_color.a={176} ;


  add_map_kicks({0,   6},   0)    ;   // Garde stand.


  add_map_kicks({7,   14},  1)    ;   // walking stand.

  add_map_kicks({15,  24},  2)    ;   // walking stand (arms back).


  add_map_kicks({36,  36},  3, 2) ;   // go down.

  add_map_kicks({37,  38},  4, 2) ;   // protected standing.

  add_map_kicks({39,  40},  5, 2) ;   // protected down.


  add_map_kicks({89,  91},  6, 2) ;   // elbow kick body.

  add_map_kicks({203, 207}, 7)    ;   // fist kick at head (back arm) (streched).


  add_map_kicks({208, 217}, 8) ; // fist kick at body (front arm) (streched).

  add_map_kicks({350, 363}, 9) ; // return body fist kick.


  add_map_kicks({322, 328}, 10) ; // tackling and fist body double attack.


  add_map_kicks({98,  99}, 12, 2) ;   // fist kick on knees (arm strech) .

  add_map_kicks({140,  150}, 13) ;   // return fist kick (arm strech) on knees.



  add_map_kicks({151,  156}, 14) ;   // foot kick (strech) to head (front leg).

  add_map_kicks({218, 224},  15) ; // foot kick to head (front leg) (streched).

  add_map_kicks({77,  88}, 16) ;   // foot kick (strech) body (front leg).

  add_map_kicks({106,  110}, 17) ;   // foot kick to knees in standing (front leg).

  add_map_kicks({269, 279}, 18) ; // return foot kick to head in standing (back leg).




  add_map_kicks({157,  166},  19) ;   // foot kick to body (front leg).
  add_map_kicks({337, 343},   20) ; // return foot kick to head (front leg).
  add_map_kicks({329, 336},   21) ; // double foot kick to kness and to body (front leg).
  add_map_kicks({172,  181},  22) ;   // foot kick to knees on knees (back leg).
  add_map_kicks({239, 241},   23, 2) ; // jump foot kick to knees in standing (back leg).



  add_map_kicks({440, 444}, 31, 2) ;    // hit at head.
  add_map_kicks({445, 448}, 32, 2) ;    // hit at body.
  add_map_kicks({449, 452}, 33, 2) ;    // hit at body.

  add_map_kicks({453, 457}, 41) ;    // falling on the ground.
  add_map_kicks({458, 460}, 42) ;    // falling on the ground (head first).
  add_map_kicks({463, 471}, 43) ;   // falling and re-up.


  add_map_kicks({380, 402}, 51) ; // making idiot finger it.
  add_map_kicks({425, 439}, 52) ;    // making idiot hair.
  add_map_kicks({410, 417}, 53) ;    // making idiot speach.

  add_map_kicks({460, 460}, 63, 4) ;    // Down on the ground (dead) !!!

  // Other idiotness...
  //add_map_kicks({418, 424}, 54) ;    // making idiot fatiguer.
  //add_map_kicks({403, 409}, 52, 4) ; // making idiot with black cat.



  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-1+6+3+1) ;

  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << '\n' << std::endl ;
  print_infos() ;
  #endif


  init_kicks_power() ;


}