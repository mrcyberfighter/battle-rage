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

#include "./Geese_Howard.h"

Geese_Howard::Geese_Howard(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {


  m_lifebar_color.r={255} ;
  m_lifebar_color.g={128+32} ;
  m_lifebar_color.b={127+32} ;
  m_lifebar_color.a={176} ;





  add_map_kicks({0, 3},  0) ;   // Garde stand.


  add_map_kicks({4, 10}, 1) ;   // walking forward.

  add_map_kicks({11, 18}, 2) ;  // walking backward.


  add_map_kicks({28, 28}, 3, 2) ;  // go down.


  add_map_kicks({29, 32}, 4, 2) ;  // protected in standing.

  add_map_kicks({33, 36}, 5, 2) ;  // protected  on knees.


  add_map_kicks({70, 73}, 6) ;  // elbow kick.

  add_map_kicks({66, 69}, 7, 2) ;  // light standing fist kick (front hand with leg move up).


  add_map_kicks({62, 64}, 8, 2) ;  // light standing fist kick (front hand with leg move up).

  add_map_kicks({97, 98}, 9, 2) ;  // standing fist kick.


  add_map_kicks({107, 109}, 10) ;  // standing uppercut.

  add_map_kicks({163, 169}, 11) ;  // flat hand uppercut or parade to a jump attack.

  add_map_kicks({99, 101},  12, 2) ;  // fist kick to down for in jump...

  add_map_kicks({102, 106}, 13, 2) ;  // hand open kick to down for in jump...



  add_map_kicks({110, 114}, 14) ;  // foot kick to head (front leg).

  add_map_kicks({128, 138}, 15) ;  // elbow kick and fist kick to head (front arm).

  add_map_kicks({84, 86}, 17, 2) ;  // foot kick to knees in standing (back leg).

  add_map_kicks({115, 121}, 18) ;  // returned foot kick to head (front leg).



  add_map_kicks({211, 221}, 19) ; // double fist kick to body.

  add_map_kicks({74, 78}, 20) ;  // jump fist kick to knees.

  add_map_kicks({79, 80}, 21, 2) ;  // fist kick to body on knees.

  add_map_kicks({92, 93}, 22, 2) ;  // foot kick to knees on knees (front leg).

  add_map_kicks({122, 127}, 23) ;  // double foot kick to knees on knees (front and back leg).




  add_map_kicks({273, 276}, 31, 2) ; // hit at head.
  add_map_kicks({277, 281}, 32, 2) ; // hit at body.
  add_map_kicks({282, 285}, 33, 2) ; // hit at knees.


  add_map_kicks({286, 289}, 41) ; // fall on the ground.
  add_map_kicks({292, 295}, 42) ; // fall on the ground head first.
  add_map_kicks({301, 313}, 43) ; // fall turning, roulette and re-up.




  add_map_kicks({267, 272}, 51) ; // make idiot -> you come or not ?
  add_map_kicks({241, 252}, 52) ; // make idiot -> Ready to fight ha ha ha...
  add_map_kicks({259, 266}, 53) ; // make idiot with big arms move !

  add_map_kicks({289, 289}, 63, 4) ; // Down on the ground (dead) !!!


  //add_map_kicks({222, 228}, 54) ; // make idiot front camera, 2 fist, up to down.




  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24+6+3+1) ;

  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << '\n' << std::endl ;
  print_infos() ;
  #endif






 init_kicks_power() ;



}