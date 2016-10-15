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

#include "./Kisarah_Westfield.h"

Kisarah_Westfield::Kisarah_Westfield(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {


  m_is_male={false} ;


  m_lifebar_color.r={192} ;
  m_lifebar_color.g={192} ;
  m_lifebar_color.b={192-128} ;
  m_lifebar_color.a={176} ;


  add_map_kicks({0,   5},  0) ;   // Garde stand.


  add_map_kicks({33,  40},  1) ;   // walking.


  add_map_kicks({41,  48},  2) ;   // walking backward (pas-chasser).


  add_map_kicks({90,  90},  3, 2) ;   // go down.


  add_map_kicks({94,  96},  4, 2) ;   // protected standing.

  add_map_kicks({97,  99},  5, 2) ;   // protected knees.


  add_map_kicks({332, 336}, 6)    ;   // fast elbow kick (front arm).

  add_map_kicks({148, 150}, 7) ;   // bag kick at body (elle a pas l'air conne !).


  add_map_kicks({203,  212}, 8)    ;   // fist kick to body (arm not strech) (front arm).

  add_map_kicks({468,  481}, 9)    ;   // smash bag on head.


  add_map_kicks({309,  331}, 10)    ;   // big bag uppercut (special attack ?).

  add_map_kicks({498,  510}, 11)    ;   // rotated uppercut.



  add_map_kicks({234,  249}, 12)    ;   // bag kick and elbow kick to knees on knees.



  add_map_kicks({180,  190}, 14) ;   // strech foot kick to head (front leg).

  add_map_kicks({482,  497}, 15)    ;   // foot kick to knees and bag kick at head (from down to up) in standing (front leg).

  add_map_kicks({260,  275}, 16)    ;   // foot kick to body (back leg).

  add_map_kicks({276,  280}, 17, 2)    ;   // jump foot kick to knees on knees (front leg).

  add_map_kicks({340,  358}, 18)    ;   // return foot kick to head (back leg).




  add_map_kicks({250,  259}, 19)    ;   // knees kick to body (back leg).

  add_map_kicks({511,  519}, 20)    ;   // rotated bag kick to head from down to up.

  add_map_kicks({446,  458}, 21)    ;   // return bag kick to knees in standing.

  add_map_kicks({195,  202}, 22) ;   // foot kick to knees on knees (front leg).

  add_map_kicks({359,  376}, 23)    ;   // return foot kick to head (back leg).





  add_map_kicks({651,  654}, 31, 2)     ;   // hit at head.
  add_map_kicks({655,  656}, 32, 2)     ;   // hit at body.
  add_map_kicks({657,  659}, 33, 2)     ;   // hit at knees.

  add_map_kicks({660,  663}, 41, 2)     ;   // fall on the ground.
  add_map_kicks({666,  669}, 42, 2)     ;   // fall on the ground head first.
  add_map_kicks({675,  679}, 43)        ;   // fall turning.



  add_map_kicks({554,  566}, 51)    ;   // make idiot with static strech arms and bag disappear.
  add_map_kicks({567,  576}, 52)    ;   // make idiot show back.
  add_map_kicks({577,  583}, 53)    ;   // make idiot Yes !!!.

  // Other idiotness...
  //add_map_kicks({584,  607}, 54, 2)    ;   // make idiot phone call.
  //add_map_kicks({608,  611}, 56, 2)    ;   // make idiot sexy back.
  //add_map_kicks({612,  637}, 57)    ;   // make idiot hand in the air.
  //add_map_kicks({638,  650}, 58)    ;   // make idiot show tits.
  //add_map_kicks({6,   31},  59) ;   // make idiot hand in the air...

  add_map_kicks({669,  669}, 63, 4)    ;   // Down on the ground (dead) !!!


  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-1+6+3+1) ;


  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << '\n' << std::endl ;
  print_infos() ;
  #endif


  init_kicks_power() ;

}