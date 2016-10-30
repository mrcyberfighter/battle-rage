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

#include "./Fuuma.h"

Fuuma::Fuuma(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)

: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {

  m_lifebar_color.r={255} ;
  m_lifebar_color.g={0}   ;
  m_lifebar_color.b={0}   ;
  m_lifebar_color.a={176} ;

  //CTor and load all kicks... this will take some time.

  add_map_kicks({0,  4},  0) ;   // Garde stand.

  add_map_kicks({5, 15}, 1) ;   // Walking forward.

  // 2 Walking backward.

  add_map_kicks({36, 36}, 3, 2) ;  // go down.

  add_map_kicks({40, 43}, 4, 2) ;  // protected in standing.

  add_map_kicks({47, 49}, 5, 2) ;  // protected  on knees.

  add_map_kicks({82, 84}, 6) ;  // elbow kick standing.


  add_map_kicks({74, 81}, 7) ;  // Simple fist kick stand.

  add_map_kicks({85, 85}, 8, 2) ;  // Simple fist kick standing.

  add_map_kicks({108, 113}, 9) ;  // fist kick to body.

  add_map_kicks({117, 123}, 10) ;  // Big uppercut standing (with left hand, back arm).


  add_map_kicks({86, 92},   12, 2) ;  // (It seems to be a defensiv body kick stopping) -> Chain triple fist kick jump, up and down fist and down fist kick...


  add_map_kicks({248, 255}, 14) ;  // Very good knife kick with take hit and range the knife. From down to up to head.

  add_map_kicks({238, 248}, 15) ;  // Very good knife kick with take hit and range the knife. From up to down to head.

  add_map_kicks({201, 213}, 16) ;  // take the knife and one kick to body.

  add_map_kicks({139, 140}, 17) ;  // foot kick to knees (front leg).

  add_map_kicks({171, 175}, 18) ;  // return foot kick to head (back leg).





  add_map_kicks({93, 100},  19) ;  // Foot kick to body standing (back leg).
  add_map_kicks({131, 137}, 20) ;  // return foot kick to head (back leg).
  add_map_kicks({214, 227}, 21) ;  // double-knife kick to body.
  add_map_kicks({148, 159}, 22) ;  // foot kick to body from on knees (front leg).
  add_map_kicks({141, 147}, 23) ;  // returned foot kick to body (front leg) or rotating balayette.





  add_map_kicks({296, 300}, 31, 2) ;  // Be hit at head.
  add_map_kicks({300, 304}, 32, 2) ;  // Be hit at body.
  add_map_kicks({305, 309}, 33, 2) ;  // Be hit at knees.

  add_map_kicks({310, 314}, 41, 2)  ;  // Fall on the ground.
  add_map_kicks({315, 317}, 42, 2)  ;  // Fall on the ground head first.
  add_map_kicks({322, 336}, 43)     ;  // Down on the ground !!!


  add_map_kicks({281, 283}, 51) ;  // Make idiot with fist (it seems to mean: You want to fight ?) !!!
  add_map_kicks({274, 280}, 52) ;  // Make idiot with knife !!!
  add_map_kicks({284, 289}, 53) ;  // Make idiot joining hands !!!

  // Other idiotness...
  //add_map_kicks({270, 273}, 54) ;  // Make idiot with finger (seems to pray) !!!
  //add_map_kicks(286, 289, 56) ;  // Make idiot arms !!!
  //add_map_kicks({290, 295}, 55) ;  // Make idiot !!!


  add_map_kicks({317, 317}, 63, 4)  ;  // Down on the ground (dead) !!!




  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-3+6+3+1) ;


  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << '\n' << std::endl ;
  print_infos() ;
  #endif

  init_kicks_power() ;


}