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

#include "./Robert_Garcia.h"

Robert_Garcia::Robert_Garcia(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {


  m_lifebar_color.r={164} ;
  m_lifebar_color.g={116} ;
  m_lifebar_color.b={255} ;
  m_lifebar_color.a={176} ;




  add_map_kicks({0,   8},   0)    ;   // Garde stand.


  add_map_kicks({9,  16},   1)    ;   // walking forward.

  add_map_kicks({17,  23},  2)    ;   // walking backward.


  add_map_kicks({49,  49},  3, 2) ;   // go down.


  add_map_kicks({54,  59},  4, 2) ;   // protected in standing.

  add_map_kicks({60,  65},  5, 2) ;   // protected on knees.


  add_map_kicks({134, 142}, 6)    ;   // fist kick to body (crochet) (back arm).

  add_map_kicks({204, 213}, 7)    ;   // return fist kick to head (back arm).


  add_map_kicks({112,  115}, 8) ;   // fist kick to body (front arm).

  add_map_kicks({143,  147}, 9)    ;   // fist kick to head (front arm).


  add_map_kicks({151,  155}, 10, 2) ;   // uppercut (front arm).



  add_map_kicks({119,  120}, 12, 2) ;   // fist kick to knees on knees (front arm).

  add_map_kicks({148,  150}, 13, 2) ;   // fist kick to knees on knees (front arm).


  add_map_kicks({156,  161}, 14)    ;   // foot kick to head (back leg).
  add_map_kicks({335,  338}, 15)    ;   // foot kick to head (front leg).
  add_map_kicks({214,  222}, 16)    ;   // jump double foot kick to body and to head (front leg).
  add_map_kicks({171,  183}, 17)    ;   // return double jump foot kick to knees on knees (both leg).
  add_map_kicks({223,  230}, 18)    ;   // return jump foot kick to body (back leg).



  add_map_kicks({162,  170}, 19)    ;   // return foot kick to body (back leg).
  add_map_kicks({197,  203}, 20)    ;   // return foot kick to head (back leg).
  add_map_kicks({184,  196}, 21)    ;   // triple foot kick to body, head, knees (front leg).
  add_map_kicks({102,  111}, 22) ;   // double jump foot kick to knees (both leg).
  add_map_kicks({231,  242}, 23)    ;   // return foot kick to head (front leg).







  add_map_kicks({387,  389}, 31, 2)    ;   // hit at head.
  add_map_kicks({390,  392}, 32, 2)    ;   // hit at body.
  add_map_kicks({393,  397}, 33, 2)    ;   // hit at kness.

  add_map_kicks({398,  401}, 41, 2)     ;   // fall to ground.
  add_map_kicks({404,  407}, 42, 2)     ;   // fall to ground head first.
  add_map_kicks({412,  425}, 43)        ;   // fall turning, backward roulette and re-up.




  add_map_kicks({348,  356}, 51)    ;   // make idiot show muscles.
  add_map_kicks({357,  364}, 52)    ;   // make idiot shake fist, or Yes !
  add_map_kicks({370,  386}, 53)    ;   // make idiot coming fighting.

  //add_map_kicks({365,  369}, 54, 2)    ;   // make idiot smash glove to ground.


  add_map_kicks({407,  407}, 63, 4)     ;   // Down on the ground (dead) !!!





  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-1+6+3+1) ;


  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << std::endl ;
  print_infos() ;
  #endif



  init_kicks_power() ;


}