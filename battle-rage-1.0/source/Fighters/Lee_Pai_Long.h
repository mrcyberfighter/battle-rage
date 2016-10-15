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

#ifndef __BATTLE_RAGE_LEE_PAI_LONG__
#define __BATTLE_RAGE_LEE_PAI_LONG__

#include "Fighters.h"

class Lee_Pai_Long : public Fighters {

   public :

     Lee_Pai_Long() { ; }

     Lee_Pai_Long(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance) ;

     Lee_Pai_Long(const Lee_Pai_Long& lee_pai_long) : Fighters{lee_pai_long} { ; }
} ;

#endif