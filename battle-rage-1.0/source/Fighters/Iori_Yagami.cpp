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

#include "./Iori_Yagami.h"

Iori_Yagami::Iori_Yagami(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance)
: Fighters::Fighters{name, folderpath, speed, agressivity, force, resistance} {

  m_lifebar_color.r={196} ;
  m_lifebar_color.g={64}  ;
  m_lifebar_color.b={64}  ;
  m_lifebar_color.a={176} ;


  add_map_kicks({0,   7},   0) ;   // Garde stand.


  add_map_kicks({8,   14},  1) ;   // Walking forward.

  add_map_kicks({15,  25},  2) ;   // walking back.


  add_map_kicks({41,  41},  3, 2) ;   // go down.


  add_map_kicks({42,  43},  4, 2) ;   // (protected standing with arms kross) better ready for attack..

  add_map_kicks({44,  51},  5, 2) ;   // protected down.


  add_map_kicks({235, 240}, 6) ;     // elbow kick at body (back arm).

  add_map_kicks({130, 137}, 7) ;      // kick on body from back to front (same as 21 but at body) (coup de griffe, gifle)..


  add_map_kicks({97,  102}, 8) ;   // double fist kick body (front arm).

  add_map_kicks({197, 200}, 9, 2) ; // fist kick at head.


  add_map_kicks({126, 129}, 10) ;   // kick on head from up to down (coup de griffe, gifle) uppercut.

  add_map_kicks({250, 259}, 11) ;   // uppercut.


  add_map_kicks({103,  106}, 12) ;   // hand (strech) kick (front arm) to knees (jumping ?).


  add_map_kicks({107,  111}, 13) ;   // hand kick to knees being down (front arm).



  add_map_kicks({153,  159}, 14) ;   // foot kick to head (front leg).

  add_map_kicks({202, 215}, 15) ;  // foot kick at head (strech) in standing (front leg).

  add_map_kicks({169,  174}, 16) ;   // jump foot kick to body (front leg).

  add_map_kicks({120,  121}, 17, 2) ;  // foot kick to knees on knees (front leg).

  add_map_kicks({350, 361}, 18) ; // return fist kick to head.





  add_map_kicks({116, 119}, 19) ;   // foot kick to body (back leg).

  add_map_kicks({181, 192}, 20) ;   // head kick.

  add_map_kicks({175, 180}, 21) ;   // double foot kick to body (with both legs).

  add_map_kicks({122,  125}, 22, 2) ;  // foot kick to knees on knees (front leg) (tackling).

  add_map_kicks({160,  168}, 23) ;   // return foot kick to body (back leg).






  add_map_kicks({398, 402}, 31, 2) ;   // hit at head.
  add_map_kicks({403, 406}, 32, 2) ;   // hit at body.
  add_map_kicks({407, 410}, 33, 2) ;   // hit at knees.


  add_map_kicks({411, 414}, 41) ;    // fall to ground.
  add_map_kicks({417, 420}, 42) ;    // fall to ground head first.
  add_map_kicks({424, 428}, 43) ;    // fall turning.


  add_map_kicks({362, 371}, 51) ;   // make idiot passing hand in the hair.
  add_map_kicks({372, 382}, 52) ;   // making idiot talking.
  add_map_kicks({383, 389}, 53) ;   // making idiot wishing mouse.

  add_map_kicks({420, 420}, 63, 4) ;   // Down on the ground (dead) !!!

  // Other idiotness...
  //add_map_kicks({340, 345}, 54) ; // make idiot coming fighting.
  //add_map_kicks({390, 396}, 53) ;   // making idiot turn around.
  //add_map_kicks({331, 339}, 46, 2) ; // make idiot shirt (afraiding).




  // Rehash and so adjust bucket count and load factor.
  rehash_kicks_hash_table(24+6+3+1) ;

  #ifdef DEBUG
  std::cout << "\nInfos containers: " << get_name() << '\n' << std::endl ;
  print_infos() ;
  #endif


  init_kicks_power() ;

}