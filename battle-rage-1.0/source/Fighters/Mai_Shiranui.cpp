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

#include "./Mai_Shiranui.h"

Mai_Shiranui::Mai_Shiranui(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {

  m_is_male={false} ;

  m_lifebar_color.r={255}   ;
  m_lifebar_color.g={62}   ;
  m_lifebar_color.b={62} ;
  m_lifebar_color.a={176} ;


  add_map_kicks({0,   9},   0)    ;   // Garde stand.


  add_map_kicks({10,  14},  1)    ;   // walking forward.

  add_map_kicks({15,  21},  2)    ;   // walking backward.


  add_map_kicks({37,  37},  3, 2) ;   // go down.


  add_map_kicks({38,  42},  4, 2) ;   // protected standing.

  add_map_kicks({43,  44},  5, 2) ;   // protected on knees.


  add_map_kicks({232, 238}, 6)    ;   // strech elbow kick.

  add_map_kicks({144, 155}, 7, 2) ;   // return elbow kick to knees (or body).


  add_map_kicks({104,  106}, 8, 2) ;   // hand fan kick to body (front arm).

  add_map_kicks({98,  103}, 9) ;   // hand fan kick from up to down (front arm).


  add_map_kicks({139,  143}, 10)    ;   // hand fan kick to head.


  add_map_kicks({107,  108}, 12, 2) ;   // hand fan balayette on knees.

  add_map_kicks({129,  134}, 13) ;   // hair kick to knees from standing (hand fan, hair)




  add_map_kicks({156,  161}, 14) ;   // foot kick to head (front leg).
  add_map_kicks({258,  271}, 15) ;   // foot kick to knees on knees and foot kick to head from knees (front leg, back leg) .



  add_map_kicks({68,  75}, 16)          ;   // jumping double foot kick to body.
  add_map_kicks({135,  138}, 17, 2)     ;   // foot kick to knees on knees (front leg).
  add_map_kicks({162,  168}, 18, 2)     ;   // return foot kick to body (back leg).



  add_map_kicks({122,  128}, 19)        ;   // foot kick to body (back leg).
  add_map_kicks({169,  172}, 20, 2)     ;   // jump foot kick to body (back leg).
  add_map_kicks({175,  185}, 22)        ;   // foot kick to knees on knees (back leg).
  add_map_kicks({192,  206}, 23)        ;   // return double foot kick to knees on knees and return flip-flap.


  add_map_kicks({436,  439}, 31, 2)     ;   // hit at head.
  add_map_kicks({440,  444}, 32, 2)     ;   // hit at body.
  add_map_kicks({445,  448}, 33, 2)     ;   // hit at knees.

  add_map_kicks({449,  452}, 41, 2)     ;   // fall to ground.
  add_map_kicks({455,  458}, 42, 2)     ;   // fall to ground head first.
  add_map_kicks({463,  473}, 43)        ;   // fall turning roulette and re-up.




  add_map_kicks({243,  257}, 51)    ;   // make idiot: jump back sexy leg and re-up.
  add_map_kicks({272,  283}, 52, 2)    ;   // make idiot get on knees 2 hand fan deployed.
  add_map_kicks({284,  292}, 53)    ;   // make idiot left-right jumping.
  add_map_kicks({385,  395}, 54, 2)    ;   // make idiot hi you.

  // Other idiotness...
  //add_map_kicks({293,  315}, 55)    ;   // make idiot hand fan in mouth.
  //add_map_kicks({327,  337}, 56, 2)    ;   // make idiot jump and fingert sich on knees.
  //add_map_kicks({338,  344}, 57)    ;   // make idiot show asshole.

  add_map_kicks({458,  458}, 63, 4)    ;   // Down on the ground (dead) !!!




  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-3+6+3+1) ;


  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << std::endl ;
  print_infos() ;
  #endif


  init_kicks_power() ;

}