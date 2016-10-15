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

#ifndef BATTLE_RAGE_INPUT_HANDLER_HH  /* Inclusion Guard */
#define BATTLE_RAGE_INPUT_HANDLER_HH

/** Input_Handler:
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

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include "Vector2D.h"

#include "global_vars.h"

#include <algorithm>

enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class Input_Handler {

  public:

    Input_Handler() ;

    Input_Handler(const Input_Handler&);

    Input_Handler& operator=(const Input_Handler&);

    ~Input_Handler() ;

    // init joysticks
    void initialise_joysticks();
    bool joysticks_initialised() const { return m_b_joysticks_initialised; }

    uint8_t get_nb_of_joysticks() const { if (m_b_joysticks_initialised) { return static_cast<uint8_t>(m_joysticks.size()) ; } else { return 0 ; } }

    void add_a_joystick(const int8_t nb) ;

    void reset();

    // update and clean the input handler
    void update();
    void clean();

    // keyboard events
    bool is_key_down(SDL_Scancode key) const;

    // joystick events
    int8_t get_axis_x(int8_t joy, int8_t stick) const;
    int8_t get_axis_y(int8_t joy, int8_t stick) const;
    bool get_button_state(int8_t joy, int button_nb) const;

    // mouse events
    bool get_mouse_button_state(int button_nb) const;
    Vector2D* get_mouse_position() const;

    // getters:
    std::string get_vendor_id(const uint8_t idx) { return m_vendor_id.at(idx) ; }
    uint8_t get_nb_of_joysticks_plugged() const { return SDL_NumJoysticks() ; }

  private:

    // private functions to handle different event types

    // handle keyboard events
    void on_key_down();
    void on_key_up();

    // handle mouse events
    void on_mouse_move(SDL_Event& event);
    void on_mouse_button_down(SDL_Event& event);
    void on_mouse_button_up(SDL_Event& event);

    // handle joysticks events
    void on_joystick_axis_move(SDL_Event& event);
    void on_joystick_button_down(SDL_Event& event);
    void on_joystick_button_up(SDL_Event& event);

    // member variables

    // keyboard specific
    const uint8_t* m_keystates;

    // joystick specific
    std::vector<std::pair<Vector2D*, Vector2D*>> m_joystick_values;
    std::vector<SDL_Joystick*> m_joysticks ;
    std::vector<std::vector<bool>> m_button_states;
    bool m_b_joysticks_initialised ;
    static const int m_joystick_dead_zone = 10000 ; // I have seen 8000 in a tutorial for this value. ;

    // mouse specific
    std::vector<bool> m_mouse_button_states;
    Vector2D* m_mouse_position;

    std::vector<std::string> m_vendor_id ;


};



#endif /* Inclusion Guard */