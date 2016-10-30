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

#include "./Terry_Bogard.h"

Terry_Bogard::Terry_Bogard(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {

  m_lifebar_color.r={62}     ;
  m_lifebar_color.g={62}     ;
  m_lifebar_color.b={128+32} ;
  m_lifebar_color.a={176}    ;


  add_map_kicks({0,   5},  0) ;   // Garde stand.


  add_map_kicks({6,  11}, 1) ;   // walking forward (one feet).

  add_map_kicks({12,  16}, 2) ;   // walking backward (one feet).


  add_map_kicks({19,  19}, 3, 2) ;   // go down.


  add_map_kicks({34,  37}, 4, 2) ;   // protected standing.

  add_map_kicks({38,  40}, 5, 2) ;   // protected on knees.


  add_map_kicks({204,  207}, 6, 2)    ;   // elbow kick to body in standing.

  add_map_kicks({105,  112}, 7) ;   // fist kick to body (back arm) strech.


  add_map_kicks({215,  217}, 8)    ;   // jump fist kick at body (back arm).

  add_map_kicks({191,  195}, 9, 2)    ;   // jump fist kick to body (front arm).


  add_map_kicks({167,  173}, 10)    ;   // uppercut (front arm) in standing.



  add_map_kicks({116,  122}, 12)    ;   // fist kick to knees on knees (back arm).

  add_map_kicks({174,  179}, 13, 2)    ;   // jump fist kick to knees (back arm).


  add_map_kicks({129,  135}, 14)    ;   // foot kick to body or head (front leg).

  add_map_kicks({75,  81}, 15) ;   // foot kick to head (back leg).

  add_map_kicks({97,  99}, 17, 2)    ;   // foot kick to knees on knees (front leg).

  add_map_kicks({123,  128}, 18)    ;   // return foot kick to head (back leg).









  add_map_kicks({94,  96}, 19, 2)    ;   // jump knees kick to body (front leg).

  add_map_kicks({196,  203}, 20)    ;   // return jump foot kick to head (back leg).

  add_map_kicks({91,  93}, 21, 2) ;   // foot kick to body (back leg).

  add_map_kicks({141,  150}, 22)    ;   // foot kick to body (back leg).

  add_map_kicks({212,  214}, 23, 2)    ;   // foot kick to knees in standing (front leg).




  add_map_kicks({276,  279}, 31)       ;   // hit at head.
  add_map_kicks({280,  282}, 32)       ;   // hit at body.
  add_map_kicks({283,  286}, 33)       ;   // hit at knees.

  add_map_kicks({287,  290}, 41)       ;   // fall to ground.
  add_map_kicks({293,  296}, 42)       ;   // fall to ground head first.
  add_map_kicks({300,  309}, 43)       ;   // fall turning backward roulette and re-up.


  add_map_kicks({238,  249}, 51, 2)    ;   // make idiot jacket.
  add_map_kicks({250,  257}, 52)       ;   // make idiot back to the user.
  add_map_kicks({258,  275}, 53)       ;   // make idiot gloves and arms up.

  add_map_kicks({296,  296}, 63, 4)       ;   // fall to ground head first.



  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24-2+6+3+1) ;


  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << std::endl ;
  print_infos() ;
  #endif


  init_kicks_power() ;

}