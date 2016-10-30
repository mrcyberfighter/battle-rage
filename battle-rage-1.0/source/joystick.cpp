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

#include "./joystick.h"


/** The problem comes when you play with 2 players.
  * And is wasting a function for one functionnality only used in certains cases,
  * and only in the fighting_mainloop(...) function.
  * So we do it if needed directly in the fighting_mainloop(...).

void get_input_axis_x(Fighters* fighter, int joy, int stick) {

  // This function handle the 'X' moves of the fighters.

  switch (joy) {

    case 0 :
      fighter->set_x_sens(input_handler->get_axis_x(joy, stick)) ;
      break ;

    case 1 :
      fighter->set_x_sens(-input_handler->get_axis_x(joy, stick)) ;
      break ;
 
  }

  return ;

}

* No need to invert the Y value.
void get_input_axis_y(Fighters* fighter, int joy, int stick) {

  // This function handle the 'Y' moves of the fighters.

  fighter->set_y_sens(input_handler->get_axis_y(joy, stick)) ;

  return ;

}
*/

void get_buttons(Fighters* fighter, int8_t joy) {

  /** This function handles the buttons of a fighter. **/

  switch (joy) {

    case 0 :

      fighter->m_buttonA = input_handler->get_button_state(joy, joy_1_buttonA) ;
      fighter->m_buttonB = input_handler->get_button_state(joy, joy_1_buttonB) ;
      fighter->m_buttonC = input_handler->get_button_state(joy, joy_1_buttonC) ;
      fighter->m_buttonD = input_handler->get_button_state(joy, joy_1_buttonD) ;

      break ;

    case 1 :

      fighter->m_buttonA = input_handler->get_button_state(joy, joy_2_buttonA) ;
      fighter->m_buttonB = input_handler->get_button_state(joy, joy_2_buttonB) ;
      fighter->m_buttonC = input_handler->get_button_state(joy, joy_2_buttonC) ;
      fighter->m_buttonD = input_handler->get_button_state(joy, joy_2_buttonD) ;

      break ;
  }


  return ;

}

void select_key_from_joy_combination_1(Fighters* fighter) {

  /** This function summarize and doest the effect of the preceding inputs.
    *
    * + The buttonA is button A
    * + The buttonB is button B
    * + The buttonC is button X
    * + The buttonD is button Y
    *
    ***********************************************************************/

  auto x_axis = fighter->get_x_axis() ;
  auto y_axis = fighter->get_y_axis() ;



  static int8_t x_axis_bk = x_axis ;
  static int8_t y_axis_bk = y_axis ;

  static bool continue_sequence{false} ;

  if (not fighter->m_buttonA and

      not fighter->m_buttonB and

      not fighter->m_buttonC and

      not fighter->m_buttonD)

  {

    // No "normal" button pressed.


    if (x_axis == x_axis_bk and y_axis == y_axis_bk and continue_sequence) {

      // Do nothing: continue image(s) sequence to run.

      fighter->set_blocking_image(false) ;

      return ;

    }


    if (x_axis == 0 and y_axis == 0) {

      // Set fighter to guard.

      fighter->set_kick(0) ;

      fighter->set_move_by_kick(false) ;

      fighter->set_can_move(false) ;

      fighter->set_blocking_image(false) ;

      continue_sequence={true} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;

      return ;

    }
    else if (x_axis == joy_1_axis_X_backward and y_axis == 0) {

      // Set the fighter walking.

      fighter->set_kick_with_fallback(2, 1) ;

      fighter->set_move_by_kick(false) ;

      fighter->set_can_move(true) ;

      fighter->set_blocking_image(false) ;

      continue_sequence={true} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;

      return ;

    }
    else if (x_axis == joy_1_axis_X_forward and y_axis == 0) {

      // Set the fighter walking.

      fighter->set_kick(1) ;

      fighter->set_move_by_kick(false) ;

      fighter->set_can_move(true) ;

      fighter->set_blocking_image(false) ;

      continue_sequence={true} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;

      return ;

    }
    else if (y_axis == joy_1_axis_Y_downward and x_axis == 0) {

        // Set the fighter on his knees.

        fighter->set_kick(3) ;

        fighter->set_move_by_kick(false) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;


    }

  }
  else if (fighter->m_buttonA and

          not fighter->m_buttonB and

          not fighter->m_buttonC and

          not fighter->m_buttonD)

  {

    // Button 'A' is pressed.


    if (x_axis == 0 and y_axis == 0) {

      // Button 'A' and no axes.

      // Simple Back Hand kick.

      fighter->set_kick(6) ;

      fighter->set_move_by_kick(true) ;

      fighter->set_can_move(false) ;

      fighter->set_blocking_image(false) ;

      continue_sequence={false} ;

      fighter->m_buttonA={false} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;

      return ;

    }
    else if (y_axis == joy_1_axis_Y_upward  and x_axis == 0) {

      // Button 'A' and up pressed (y_axis == axis_Y_upward)

      // Upward Back Hand kick.

      fighter->set_kick_with_fallback(11, 10) ;

      fighter->set_move_by_kick(true) ;

      fighter->set_can_move(false) ;

      fighter->set_blocking_image(false) ;

      continue_sequence={false} ;

      fighter->m_buttonA={false} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;

      return ;

    }
    else if (y_axis == joy_1_axis_Y_downward and x_axis == joy_1_axis_X_backward) {
     
       // Button 'A' and back-down pressed.
     
      // Fighter get into protected mode on his knees.

      fighter->set_kick(5) ;

      fighter->set_move_by_kick(false) ;

      fighter->set_can_move(false) ;

      fighter->set_blocking_image(true) ;

      continue_sequence={true} ;

      fighter->m_buttonA={false} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;

      return ;

    }


    if (y_axis == 0 and x_axis != 0) {

      if (x_axis == joy_1_axis_X_backward) {

        // Fighter get into protected mode by standing.

        fighter->set_kick(4) ;

        fighter->set_move_by_kick(false) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(true) ;

        continue_sequence={true} ;

        fighter->m_buttonA={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

      }
      else if (x_axis == joy_1_axis_X_forward) {

        // Button 'A' and x_axis forward.

        // Backward Back Hand kick.

        fighter->set_kick(7) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonA={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }

    }
    else {

      // Else return to fighter guard.

      fighter->set_kick(0) ;

      fighter->set_move_by_kick(false) ;

      fighter->set_can_move(false) ;

      fighter->set_blocking_image(false) ;

      continue_sequence={false} ;

      fighter->m_buttonA={false} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;



      return ;

    }


  }
  else if (not fighter->m_buttonA and

          not fighter->m_buttonB and

          not fighter->m_buttonC and

          fighter->m_buttonD)

  {

    // Button 'D' is pressed.

    if (x_axis == 0 and y_axis == 0) {

        // Button 'D' and no axes.

        // Simple Front Hand kick.

        fighter->set_kick(8) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonD={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

      }
      else if (x_axis == joy_1_axis_X_forward and y_axis == 0) {

        // Button 'D' and press forward (x_axis == axis_X_forward).

        // Forward Front Hand kick.

        fighter->set_kick(9) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonD={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

      }
      else if (y_axis == joy_1_axis_Y_upward and x_axis == 0) {

        // Button 'D' and press up (y_axis == axis_Y_downward).

        // Upward Front Hand kick.

        fighter->set_kick(10) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonD={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

      }
      else if (y_axis == joy_1_axis_Y_downward) {

        // Button 'D' and press up (y_axis == axis_Y_downward).

        // Downward Front Hand kick.

        fighter->set_kick(12) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonD={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

      }

  }
  else if (not fighter->m_buttonA and

               fighter->m_buttonB and

          not fighter->m_buttonC and

          not fighter->m_buttonD)

  {


     // Button 'B' is pressed.


     if (y_axis == joy_1_axis_Y_upward) {

        // Button 'B' and press up (y_axis == axis_Y_upward).

        // Foot kick to head up.

        fighter->set_kick_with_fallback(15, 14) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonB={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }
     else if (x_axis == joy_1_axis_X_forward) {

        // Button 'B' and press down (y_axis == axis_Y_downward).

        // Foot kick to head front.

        fighter->set_kick_with_fallback(16, 14) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonB={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }
     else if (y_axis == joy_1_axis_Y_downward) {

        // Button 'B' and press down (y_axis == axis_Y_downward).

        // Foot kick to knees down.

        fighter->set_kick_with_fallback(17, 14) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonB={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }
     else if (x_axis == joy_1_axis_X_backward) {

        // Button 'B' and press down (y_axis == axis_Y_downward).

        // Foot kick

        fighter->set_kick_with_fallback(18, 14) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonB={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }

     if (x_axis == 0 and y_axis == 0) {

        // Button 'B' and no axes.

        // Simple Foot kick to head.

        fighter->set_kick(14) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonB={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }


  }
  else if (not fighter->m_buttonA and

          not fighter->m_buttonB and

              fighter->m_buttonC and

          not fighter->m_buttonD)

  {



    // Button 'C' is pressed.


     if (y_axis == joy_1_axis_Y_upward) {

        // Button 'C' and press up (y_axis == axis_Y_upward).

        // Foot kick to head up.

        fighter->set_kick_with_fallback(20, 19) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonC={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }
     else if (x_axis == joy_1_axis_X_forward) {

        // Button 'C' and press down (y_axis == axis_Y_downward).

        // Foot kick to head front.

        fighter->set_kick_with_fallback(21, 19) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonC={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }
     else if (y_axis == joy_1_axis_Y_downward) {

        // Button 'C' and press down (y_axis == axis_Y_downward).

        // Foot kick to knees down.

        fighter->set_kick_with_fallback(22, 19) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonC={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }
     else if (x_axis == joy_1_axis_X_backward) {

        // Button 'C' and press down (y_axis == axis_Y_downward).

        // Foot kick to knees down.

        fighter->set_kick_with_fallback(23, 19) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonC={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }

     if (x_axis == 0 and y_axis == 0) {

        // Button 'C' and no axes.

        // Simple Foot kick to head.

        fighter->set_kick(19) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonC={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }



  }



  return ;

}

void select_key_from_joy_combination_2(Fighters* fighter) {

  /** This function summarize and doest the effect of the preceding inputs.
    * And is used for playing Player vs Player.
    *
    **********************************************************************/

  auto x_axis = fighter->get_x_axis() ;
  auto y_axis = fighter->get_y_axis() ;



  static int8_t x_axis_bk = x_axis ;
  static int8_t y_axis_bk = y_axis ;

  static bool continue_sequence{false} ;

  if (not fighter->m_buttonA and

      not fighter->m_buttonB and

      not fighter->m_buttonC and

      not fighter->m_buttonD)

  {

    // No "normal" button pressed.


    if (x_axis == x_axis_bk and y_axis == y_axis_bk and continue_sequence) {

      // Do nothing: continue image(s) sequence to run.

      fighter->set_blocking_image(false) ;

      return ;

    }


    if (x_axis == 0 and y_axis == 0) {

      // Set fighter to guard.

      fighter->set_kick(0) ;

      fighter->set_move_by_kick(false) ;

      fighter->set_can_move(false) ;

      fighter->set_blocking_image(false) ;

      continue_sequence={true} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;

    }
    else if (x_axis == joy_2_axis_X_backward and y_axis == 0) {

      // Set the fighter walking.

      fighter->set_kick_with_fallback(2, 1) ;

      fighter->set_move_by_kick(false) ;

      fighter->set_can_move(true) ;

      fighter->set_blocking_image(false) ;

      continue_sequence={true} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;

      return ;

    }
    else if (x_axis == joy_2_axis_X_forward and y_axis == 0) {

      // Set the fighter walking forward.

      fighter->set_kick(1) ;

      fighter->set_move_by_kick(false) ;

      fighter->set_can_move(true) ;

      fighter->set_blocking_image(false) ;

      continue_sequence={true} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;

      return ;

    }
    else if (y_axis == joy_2_axis_Y_downward and x_axis == 0) {

        // Set the fighter on his knees.

        fighter->set_kick(3) ;

        fighter->set_move_by_kick(false) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;


    }

  }
  else if (fighter->m_buttonA and

          not fighter->m_buttonB and

          not fighter->m_buttonC and

          not fighter->m_buttonD)

  {

    // Button 'A' is pressed.


    if (x_axis == 0 and y_axis == 0) {

      // Button 'A' and no axes.

      // Simple Back Hand kick.

      fighter->set_kick(6) ;

      fighter->set_move_by_kick(true) ;

      fighter->set_can_move(false) ;

      fighter->set_blocking_image(false) ;

      continue_sequence={false} ;

      fighter->m_buttonA={false} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;

      return ;

    }
    else if (y_axis == joy_2_axis_Y_upward  and x_axis == 0) {

      // Button 'A' and up pressed (y_axis == axis_Y_upward)

      // Upward Back Hand kick.

      fighter->set_kick_with_fallback(11, 10) ;

      fighter->set_move_by_kick(true) ;

      fighter->set_can_move(false) ;

      fighter->set_blocking_image(false) ;

      continue_sequence={false} ;

      fighter->m_buttonA={false} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;

      return ;

    }
    else if (y_axis == joy_2_axis_Y_downward and x_axis == joy_2_axis_X_backward) {

      // Fighter get into protected mode on his knees.

      fighter->set_kick(5) ;

      fighter->set_move_by_kick(false) ;

      fighter->set_can_move(false) ;

      fighter->set_blocking_image(true) ;

      continue_sequence={true} ;

      fighter->m_buttonA={false} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;

      return ;

    }


    if (y_axis == 0 and x_axis != 0) {

      if (x_axis == joy_2_axis_X_backward) {

        // Fighter get into protected mode by standing.

        fighter->set_kick(4) ;

        fighter->set_move_by_kick(false) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(true) ;

        continue_sequence={true} ;

        fighter->m_buttonA={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

      }
      else if (x_axis == joy_2_axis_X_forward) {

        // Button 'A' and x_axis forward.

        // Backward Back Hand kick.

        fighter->set_kick(7) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonA={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }
     else if (y_axis == joy_2_axis_Y_downward  and x_axis == joy_2_axis_X_forward) {

      // Button 'A' and up pressed (y_axis == axis_Y_upward)

      // Forward Back Hand kick.

      fighter->set_kick_with_fallback(13, 12) ;

      fighter->set_move_by_kick(true) ;

      fighter->set_can_move(false) ;

      fighter->set_blocking_image(false) ;

      continue_sequence={false} ;

      fighter->m_buttonA={false} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;

      return ;

    }


    }

    else {

      // Else return to fighter guard.

      fighter->set_kick(0) ;

      fighter->set_move_by_kick(false) ;

      fighter->set_can_move(false) ;

      fighter->set_blocking_image(false) ;

      continue_sequence={false} ;

      fighter->m_buttonA={false} ;

      x_axis_bk = x_axis ;
      y_axis_bk = y_axis ;



      return ;

    }


  }
  else if (not fighter->m_buttonA and

          not fighter->m_buttonB and

          not fighter->m_buttonC and

          fighter->m_buttonD)

  {

    // Button 'D' is pressed.

    if (x_axis == 0 and y_axis == 0) {

        // Button 'D' and no axes.

        // Simple Front Hand kick.

        fighter->set_kick(8) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonD={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

      }
      else if (x_axis == joy_2_axis_X_forward and y_axis == 0) {

        // Button 'D' and press forward (x_axis == axis_X_forward).

        // Forward Front Hand kick.

        fighter->set_kick(9) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonD={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

      }
      else if (y_axis == joy_2_axis_Y_upward and x_axis == 0) {

        // Button 'D' and press up (y_axis == axis_Y_downward).

        // Upward Front Hand kick.

        fighter->set_kick(10) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonD={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

      }
      else if (y_axis == joy_2_axis_Y_downward) {

        // Button 'D' and press up (y_axis == axis_Y_downward).

        // Downward Front Hand kick.

        fighter->set_kick(12) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonD={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

      }

  }
  else if (not fighter->m_buttonA and

               fighter->m_buttonB and

          not fighter->m_buttonC and

          not fighter->m_buttonD)

  {


     // Button 'B' is pressed.


     if (y_axis == joy_2_axis_Y_upward) {

        // Button 'B' and press up (y_axis == axis_Y_upward).

        // Foot kick to head up.

        fighter->set_kick_with_fallback(15, 14) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonB={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }
     else if (x_axis == joy_2_axis_X_forward) {

        // Button 'B' and press down (y_axis == axis_Y_downward).

        // Foot kick to head front.

        fighter->set_kick_with_fallback(16, 14) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonB={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }
     else if (y_axis == joy_2_axis_Y_downward) {

        // Button 'B' and press down (y_axis == axis_Y_downward).

        // Foot kick to knees down.

        fighter->set_kick_with_fallback(17, 14) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonB={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }
     else if (x_axis == joy_2_axis_X_backward) {

        // Button 'B' and press down (y_axis == axis_Y_downward).

        // Foot kick

        fighter->set_kick_with_fallback(18, 14) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonB={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }

     if (x_axis == 0 and y_axis == 0) {

        // Button 'B' and no axes.

        // Simple Foot kick to head.

        fighter->set_kick(14) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonB={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }


  }
  else if (not fighter->m_buttonA and

          not fighter->m_buttonB and

              fighter->m_buttonC and

          not fighter->m_buttonD)

  {



    // Button 'C' is pressed.


     if (y_axis == joy_2_axis_Y_upward) {

        // Button 'C' and press up (y_axis == axis_Y_upward).

        // Foot kick to head up.

        fighter->set_kick_with_fallback(20, 19) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonC={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }
     else if (x_axis == joy_2_axis_X_forward) {

        // Button 'C' and press down (y_axis == axis_Y_downward).

        // Foot kick to head front.

        fighter->set_kick_with_fallback(21, 19) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonC={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }
     else if (y_axis == joy_2_axis_Y_downward) {

        // Button 'C' and press down (y_axis == axis_Y_downward).

        // Foot kick to knees down.

        fighter->set_kick_with_fallback(22, 19) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonC={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }
     else if (x_axis == joy_2_axis_X_backward) {

        // Button 'C' and press down (y_axis == axis_Y_downward).

        // Foot kick to knees down.

        fighter->set_kick_with_fallback(23, 19) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonC={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }

     if (x_axis == 0 and y_axis == 0) {

        // Button 'C' and no axes.

        // Simple Foot kick to head.

        fighter->set_kick(19) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        fighter->set_blocking_image(false) ;

        continue_sequence={false} ;

        fighter->m_buttonC={false} ;

        x_axis_bk = x_axis ;
        y_axis_bk = y_axis ;

        return ;

     }



  }



  return ;

}