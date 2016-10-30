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

#ifndef __BATTLE_RAGE_KISARAH_WESTFIELD__
#define __BATTLE_RAGE_KISARAH_WESTFIELD__

#include "Fighters.h"

class Kisarah_Westfield : public Fighters {

   public :

     Kisarah_Westfield() { ; }

     Kisarah_Westfield(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance) ;

     Kisarah_Westfield(const Kisarah_Westfield& kisarah_westfield) : Fighters{kisarah_westfield} { ; }
} ;

#endif