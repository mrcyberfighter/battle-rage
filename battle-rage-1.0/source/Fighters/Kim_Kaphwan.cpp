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

#include "./Kim_Kaphwan.h"

Kim_Kaphwan::Kim_Kaphwan(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {


  m_lifebar_color.r={0}   ;
  m_lifebar_color.g={255} ;
  m_lifebar_color.b={255} ;
  m_lifebar_color.a={176} ;





  add_map_kicks({0,   7},   0) ;   // Garde stand.


  add_map_kicks({8,   13},  1) ;   // Walking forward.

  add_map_kicks({14,  19},  2) ;   // Walking backward.


  add_map_kicks({38,  38},  3, 2) ;   // go down.


  add_map_kicks({39,  41},  4, 2) ;   // protected in standing.

  add_map_kicks({42,  44},  5, 2) ;   // protected on knees.


  add_map_kicks({71,  74},  6) ;   // strech fist kick to body (front arm) or catch the enemie.

  add_map_kicks({45,  50},  7) ;   // big knees kick to body.


  add_map_kicks({80,  83},  8) ;   // double fist kick to head and body.

  add_map_kicks({280,  283}, 9, 2)    ;   // knees kick to body.


  add_map_kicks({186,  196}, 10)    ;   // jumping big foot kick at body (front leg) with prepare to attack comprise.



  add_map_kicks({87, 88}, 12, 2) ;   // fist kick to knees. (front arm).

  add_map_kicks({84,  85}, 13, 2) ;   // fist kick to knees on knees (back arm) (jumping).


  // Use it.
  //add_map_kicks({96,  101}, 14) ;   // strech foot kick to head (front leg).


  // Use it.
  //add_map_kicks({106,  110}, 14) ;   // foot kick to body in standing (back leg).



  add_map_kicks({141, 146}, 14) ;   // foot kick to head (front leg).
  add_map_kicks({133, 140}, 15) ;   // strech foot kick to head (front leg).
  add_map_kicks({75,  79},  16, 2) ;   // strech foot kick to body (front leg).
  add_map_kicks({224, 231}, 17)    ;   // double foot kick to knees on knees (front leg).
  add_map_kicks({147, 163}, 18)    ;   // return double foot kick to head (back and front leg) (an head gifle with the foots).



  add_map_kicks({102,  103}, 19, 2) ;   // strech foot kick to head (back leg).
  add_map_kicks({123,  132}, 20) ;   // foot kick to head (front leg).
  add_map_kicks({255,  268}, 21)    ;   // return double foot kick at body and head (back leg).
  add_map_kicks({170,  176}, 22)    ;   // return foot kick to knees on knees (back leg).
  add_map_kicks({111,  122}, 23)    ;   // return foot kick to head (front leg).




  add_map_kicks({373,  376}, 31, 2)    ;   // hit at head.
  add_map_kicks({377,  381}, 32, 2)    ;   // hit at body.
  add_map_kicks({382,  385}, 33, 2)    ;   // hit on knees.

  add_map_kicks({386,  389}, 41)    ;   // fall to ground.
  add_map_kicks({392,  395}, 42)    ;   // fall to ground head first.
  add_map_kicks({399,  404}, 43)    ;   // fall turning.




  add_map_kicks({307,  318}, 51)    ;   // make idiot whishing head.
  add_map_kicks({335,  354}, 52)    ;   // make idiot coming fighting.
  add_map_kicks({327,  334}, 53)    ;   // make idiot detend legs.

  // Other idiotness...
  //add_map_kicks({319,  326}, 52)    ;   // make idiot unguilty.
  //add_map_kicks({355,  365}, 46)    ;   // make idiot fight position and scream.
  //add_map_kicks({366,  370}, 47)    ;   // make idiot close eyes.
  //add_map_kicks({371,  372}, 48)    ;   // make idiot eyes (to repeat).
  //add_map_kicks({366,  372}, 47)    ;   // make idiot longuer seq...


  add_map_kicks({395,  395}, 63, 4)    ;   // Down on the ground (dead) !!!




  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-1+6+3+1) ;

  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << '\n' << std::endl ;
  print_infos() ;
  #endif

  init_kicks_power() ;


}