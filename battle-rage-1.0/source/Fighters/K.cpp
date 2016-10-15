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

#include "./K.h"

K::K(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {

  m_lifebar_color.r={116-32}    ;
  m_lifebar_color.g={116-32}    ;
  m_lifebar_color.b={116-32}    ;
  m_lifebar_color.a={176}       ;




  add_map_kicks({0,   9},   0)    ;   // Garde stand.


  add_map_kicks({22, 33},   1)    ;   // Walking forward.

  add_map_kicks({35, 46},   2)    ;   // walking backward.


  add_map_kicks({63, 65},   3, 2) ;   // go down.


  add_map_kicks({72, 75},   4, 2) ;   // protected in standing.

  add_map_kicks({75, 79},   5, 2) ;   // protected on knees.


  add_map_kicks({126, 128}, 6)    ;   // elbow kick (front arm).

  add_map_kicks({175,  184}, 7) ;   // elbow kick.


  add_map_kicks({129, 133}, 8)    ;   // fist kick at body (front arm) strech.

  add_map_kicks({362,  372}, 9)    ;   // magic ha-do-ken.


  //add_map_kicks({191,  198}, 10)    ;   // big uppercut from knees to head.

  add_map_kicks({308,  320}, 10)    ;   // return jumping uppercut.

  add_map_kicks({239,  247}, 11)    ;   // big uppercut (strech) in standing (front arm).


  add_map_kicks({134,  138}, 12) ;   // fist kick to knees on knees (jumping).




  add_map_kicks({350,  352}, 14, 2)    ;   // foot kick to head (back leg).

  add_map_kicks({261,  270}, 15)    ;   // jump foot kick to head (back leg).

  add_map_kicks({298,  304}, 16)    ;   // return jump foot kick to body (front leg).

  add_map_kicks({165,  168}, 17) ;   // foot kick to knees on knees (front leg).

  add_map_kicks({321,  330}, 18)    ;   // return jump foot kick to head (back leg).




  add_map_kicks({149,  155}, 19) ;   // foot kick to body in standing (back leg).

  add_map_kicks({115,  125}, 20) ;   // foot kick to head (front leg).

  add_map_kicks({220,  227}, 21)    ;   // jump foot kick to body (front leg).

  add_map_kicks({228,  238}, 22)    ;   // foot kick to knees on knees (back leg).

  add_map_kicks({207,  219}, 23)    ;   // return foot kick to head (back leg).







  add_map_kicks({473,  476}, 31, 2)    ;   // hit at head.
  add_map_kicks({477,  481}, 32, 2)    ;   // hit at body.
  add_map_kicks({482,  485}, 33, 2)    ;   // hit at and on knees.

  add_map_kicks({486,  489}, 41)    ;   // fall to ground backward (hit at head).
  add_map_kicks({492,  495}, 42)    ;   // fall to ground head first (hit at body).
  add_map_kicks({501,  512}, 43)    ;   // fall turning back roulette and re-up.





  add_map_kicks({413,  421}, 51)    ;   // make idiot return hair in the wind.
  add_map_kicks({422,  429}, 52)    ;   // make idiot whish head from back.
  add_map_kicks({353,  361}, 53)    ;   // make idiot coming fighting.

  // Other idiotness...
  //add_map_kicks({353,  361}, 54)    ;   // make idiot coming fighting.
  //add_map_kicks({450,  455}, 55)    ;   // make idiot raise the head and arms at hips.
  //add_map_kicks({456,  463}, 56)    ;   // make idiot cross arms.
  //add_map_kicks({463,  472}, 57)    ;   // make idiot raise the head and arms down.
  //add_map_kicks({393,  401}, 49)    ;   // make idiot Yes !!!
  //add_map_kicks({402,  412}, 50)    ;   // make idiot stone fist.
  //add_map_kicks({430,  449}, 54)    ;   // make idiot long.

  add_map_kicks({494,  494}, 63, 4)    ;   // Down on the ground (dead) !!!




  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-1+6+3+1) ;




  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << '\n' << std::endl ;
  print_infos() ;
  #endif



  init_kicks_power() ;

}