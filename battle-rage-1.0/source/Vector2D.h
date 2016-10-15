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

#ifndef BATTLE_RAGE_VECTOR_2D_HH  /* Inclusion Guard */
#define BATTLE_RAGE_VECTOR_2D_HH

/** Vector2D:
  *
  * Initiallly written by
  *
  * Shaun Ross Mitchell <shaunmitchell84@googlemail.com>
  *
  * For his book: SDL Game Development (june 2013) [Packt Pusblishing].
  *
  * ---
  *
  * Rewritten by: Brüggemann Eddie <mrcyberfighter@gmail.com>
  *
  * For his game: battle-rage.
  *
  * Credits: Thanks to Shaun for his good implementation of an Vector2D.
  *
  ***************************************************************************/

#include <cstdint>

class Vector2D {

  public:

    Vector2D() {

      m_x={0}  ;
      m_y={0}  ;

    }

    Vector2D(int8_t x, int8_t y): m_x(x), m_y(y) {}

    int8_t get_x() { return m_x ; }
    int8_t get_y() { return m_y ; }

    void set_x(int8_t x) { m_x = {x} ; }
    void set_y(int8_t y) { m_y = {y} ; }

    int8_t m_x;
    int8_t m_y;
};

#endif  /* Inclusion Guard */