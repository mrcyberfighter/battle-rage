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

#include "Input_Handler.h"

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


Input_Handler::Input_Handler() :

m_keystates(nullptr),

m_b_joysticks_initialised(false),

m_mouse_position(new Vector2D(0,0)) {

   // create button states for the mouse
   for (int i = 0; i < 3; i++) {

      m_mouse_button_states.push_back(false);
   }

}

Input_Handler::~Input_Handler() {

    // delete anything we created dynamically

    // Cannot delete because it's an const pointer ;
    // But this don't mind because the delete is called at the game end (uninitialized).
    // And I think the values points to internal datas.
    //delete m_keystates;

    delete m_mouse_position;

    // clear our arrays
    m_joystick_values.clear();
    m_joysticks.clear();
    m_button_states.clear();
    m_mouse_button_states.clear();
}

void Input_Handler::clean() {

  // we need to clean up after ourselves and close the joysticks we opened
  if (m_b_joysticks_initialised) {

    for (int i = 0; i < SDL_NumJoysticks(); i++) {
        SDL_JoystickClose(m_joysticks[i]);
    }
  }
}

void Input_Handler::initialise_joysticks() {

    // if we haven't already initialised the joystick subystem, we will do it here
    if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0) {
      SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }

    // get the number of joysticks, skip init if there aren't any
    if (SDL_NumJoysticks() > 0) {

        for (int i = 0; i < SDL_NumJoysticks(); i++) {
     
          // create a new joystick
          SDL_Joystick* joy = SDL_JoystickOpen(i);

          #ifdef DEBUG
          std::cout << "Name of joystick: " << SDL_JoystickNameForIndex(i) << std::endl ;
          #endif

          // if the joystick opened correctly we need to populate our arrays
          if (SDL_JoystickOpen(i)) {
            // push back into the array to be closed later
            m_joysticks.push_back(joy);
          
            // create a pair of values for the axes, a vector for each stick
            m_joystick_values.push_back(std::make_pair(new Vector2D(0,0),new Vector2D(0,0)));

            // create an array to hold the button values
            std::vector<bool> tmp_buttons;

            // fill the array with a false value for each button
            for(int j = 0; j <  SDL_JoystickNumButtons(joy) ; j++) {
                tmp_buttons.push_back(false);
            }


            // push the button array into the button state array
            m_button_states.push_back(tmp_buttons);
          
            // store the vendor id
            m_vendor_id.push_back(SDL_JoystickNameForIndex(i)) ;
          }
          else {
            // if there was an error initialising a joystick we want to know about it
            std::cout << SDL_GetError();
          }

        }

        // enable joystick events
        SDL_JoystickEventState(SDL_ENABLE);
        m_b_joysticks_initialised = true;
  
        #ifdef DEBUG
        std::cout << "Initialised " << m_joysticks.size() << " joystick(s)\n" ;
        #endif
    }
    else {

      m_b_joysticks_initialised = false ;

      #ifdef DEBUG
      std::cout << "No joystick initialised \n" ;
      #endif

    }

}

void Input_Handler::add_a_joystick(const int8_t nb) {

  SDL_Joystick* joy = nullptr ;

  joy = SDL_JoystickOpen(nb) ;

  // if the joystick opened correctly we need to populate our arrays
  if (joy != nullptr) {

    #ifdef DEBUG
    std::cout << "Name of joystick: " << SDL_JoystickNameForIndex(nb) << std::endl ;
    #endif

    // push back into the array to be closed later
    m_joysticks.push_back(joy);

    // create a pair of values for the axes, a vector for each stick
    m_joystick_values.push_back(std::make_pair(new Vector2D(0,0),new Vector2D(0,0)));

    // create an array to hold the button values
    std::vector<bool> tmp_buttons;

    // fill the array with a false value for each button
    for(int j = 0; j <  SDL_JoystickNumButtons(joy); j++) {
        tmp_buttons.push_back(false);
    }


    // push the button array into the button state array
    m_button_states.push_back(tmp_buttons);

    m_vendor_id.push_back(SDL_JoystickNameForIndex(nb)) ;

    SDL_JoystickUpdate() ;
 }
 else {

   std::string err_msg{"Error by adding joystick:\n"} ;

   err_msg += SDL_GetError() ;

   SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Joystick adding failed !", err_msg.c_str(), pWindow) ;

 }


 return ;

}

void Input_Handler::reset() {

  m_mouse_button_states[LEFT] = false;
  m_mouse_button_states[RIGHT] = false;
  m_mouse_button_states[MIDDLE] = false;

  m_keystates=nullptr ;

  m_joystick_values[0].first->set_x(0) ;
  m_joystick_values[0].first->set_y(0) ;

  std::fill(std::begin(m_button_states[0]), std::end(m_button_states[0]), false) ;

  if (SDL_NumJoysticks() > 1) {

    m_joystick_values[1].first->set_x(0) ;
    m_joystick_values[1].second->set_y(0) ;

    std::fill(std::begin(m_button_states[1]), std::end(m_button_states[1]), false) ;
  }


}

bool Input_Handler::is_key_down(SDL_Scancode key) const {

  if (m_keystates != nullptr) {

    if (m_keystates[key] == 1) {

      return true;
    }
    else {
      return false;
    }

  }

  return false;
}


int8_t Input_Handler::get_axis_x(int8_t joy, int8_t stick) const {

  if (m_joystick_values.size() > 0) {

    if (stick == 1) {
 
      #ifdef DEBUG
      std::cout << "Joystick " << std::to_string(joy) << " stick " << std::to_string(stick) << " get first." << std::endl ;
      #endif
 
      return m_joystick_values[joy].first->get_x() ;

    }
    else if (stick == 2) {
 
      #ifdef DEBUG
      std::cout << "Joystick " << std::to_string(joy) << " stick " << std::to_string(stick) << " get first." << std::endl ;
      #endif
 
      return m_joystick_values[joy].second->get_x() ;

    }

  }

  return 0;

}

int8_t Input_Handler::get_axis_y(int8_t joy, int8_t stick) const {

  if (m_joystick_values.size() > 0) {

    #ifdef DEBUG
    std::cout << "m_joystick_values.size() > 0" << std::endl ;
    #endif

    if (stick == 1) {
 
      #ifdef DEBUG
      std::cout << "stick 1" << std::endl ;
      #endif
 
      return m_joystick_values[joy].first->get_y() ;

    }
    else if (stick == 2) {
 
      #ifdef DEBUG
      std::cout << "stick 2" << std::endl ;
      #endif
  
      return m_joystick_values[joy].second->get_y();


    }

  }

  return 0;

}

bool Input_Handler::get_button_state(int8_t joy, int button_nb) const {

  return m_button_states[joy][button_nb];

}

bool Input_Handler::get_mouse_button_state(int button_nb) const {

  return m_mouse_button_states[button_nb];

}

Vector2D* Input_Handler::get_mouse_position() const {

  return m_mouse_position;

}

void Input_Handler::update() {

  SDL_Event event ;

  while (SDL_PollEvent(&event)) {

    switch (event.type) {

        case SDL_QUIT:
       
          exit(EXIT_SUCCESS) ;
          break;

        case SDL_JOYAXISMOTION:

          on_joystick_axis_move(event);
          break;

        case SDL_JOYBUTTONDOWN:

          on_joystick_button_down(event) ;
          break;

        case SDL_JOYBUTTONUP:

          on_joystick_button_up(event);
          break;

        case SDL_MOUSEMOTION:

          on_mouse_move(event);
          break;

        case SDL_MOUSEBUTTONDOWN:

          on_mouse_button_down(event);
          break;

        case SDL_MOUSEBUTTONUP:

          on_mouse_button_up(event);
          break;

        case SDL_KEYDOWN:

          on_key_down();
          break;

        case SDL_KEYUP:

          on_key_up();
          break;

        default:

          break;

    }
  }

  return ;
}


void Input_Handler::on_key_down() {

  m_keystates = SDL_GetKeyboardState(0) ;

}

void Input_Handler::on_key_up() {

  m_keystates = SDL_GetKeyboardState(0) ;

}

void Input_Handler::on_mouse_move(SDL_Event &event) {

  m_mouse_position->set_x(event.motion.x);
  m_mouse_position->set_y(event.motion.y);

}

void Input_Handler::on_mouse_button_down(SDL_Event &event) {

  if (event.button.button == SDL_BUTTON_LEFT) {

    m_mouse_button_states[LEFT] = true;

  }

  if (event.button.button == SDL_BUTTON_MIDDLE) {

    m_mouse_button_states[MIDDLE] = true;

  }

  if (event.button.button == SDL_BUTTON_RIGHT) {

    m_mouse_button_states[RIGHT] = true;

  }

}

void Input_Handler::on_mouse_button_up(SDL_Event &event) {

  if (event.button.button == SDL_BUTTON_LEFT) {

    m_mouse_button_states[LEFT] = false;

  }

  if (event.button.button == SDL_BUTTON_MIDDLE) {

    m_mouse_button_states[MIDDLE] = false;

  }

  if (event.button.button == SDL_BUTTON_RIGHT) {

    m_mouse_button_states[RIGHT] = false;

  }

}

void Input_Handler::on_joystick_axis_move(SDL_Event &event) {

   // We suppose that axis 0 and 2 are the X axis and the axis 1 and 3 are the Y axis.
   // But in most case 0 and 1 is sufficient.

   int which_one = event.jaxis.which ;

    // left stick move left or right
    if (event.jaxis.axis == 0) {

      if (event.jaxis.value > m_joystick_dead_zone) {

        m_joystick_values[which_one].first->set_x(1);
    
        #ifdef DEBUG
        std::cout << "Joystick " << which_one << " axis 0 set to 1" << std::endl ;
        #endif
    
      }
      else if (event.jaxis.value < -m_joystick_dead_zone) {

        m_joystick_values[which_one].first->set_x(-1);
    
        #ifdef DEBUG
        std::cout << "Joystick " << which_one << " axis 0 set to -1" << std::endl ;
        #endif
  
      }
      else {

        m_joystick_values[which_one].first->set_x(0);
   
        #ifdef DEBUG
        std::cout << "Joystick " << which_one << " axis 0 set to 0" << std::endl ;
        #endif

      }



    }

    // left stick move up or down
    if (event.jaxis.axis == 1) {

      if (event.jaxis.value > m_joystick_dead_zone) {

        m_joystick_values[which_one].first->set_y(1);

        #ifdef DEBUG
        std::cout << "Joystick " << which_one << " axis 1 set to 1" << std::endl ;
        #endif
    
      }
      else if (event.jaxis.value < -m_joystick_dead_zone) {

        m_joystick_values[which_one].first->set_y(-1);

        #ifdef DEBUG
        std::cout << "Joystick " << which_one << " axis 1 set to -1" << std::endl ;
        #endif
   
      }
      else {

        m_joystick_values[which_one].first->set_y(0);

        #ifdef DEBUG
        std::cout << "Joystick " << which_one << " axis 1 set to 0" << std::endl ;
        #endif

      }

    }

    // right stick move left or right
    if (event.jaxis.axis == 2) {

      if (event.jaxis.value > m_joystick_dead_zone) {

        m_joystick_values[which_one].second->set_x(1);

        #ifdef DEBUG
        std::cout << "Joystick " << which_one << " axis 3 set to 1" << std::endl ;
        #endif
    
      }
      else if (event.jaxis.value < -m_joystick_dead_zone) {

        m_joystick_values[which_one].second->set_x(-1);

        #ifdef DEBUG
        std::cout << "Joystick " << which_one << " axis 3 set to -1" << std::endl ;
        #endif
   
      }
      else {

        m_joystick_values[which_one].second->set_x(0);

        #ifdef DEBUG
        std::cout << "Joystick " << which_one << " axis 3 set to 0" << std::endl ;
        #endif
    
      }

    }

    // right stick move left or right
    if (event.jaxis.axis == 3) {

      if (event.jaxis.value > m_joystick_dead_zone) {

        m_joystick_values[which_one].second->set_y(1);

        #ifdef DEBUG
        std::cout << "Joystick " << which_one << " axis 3 set to 1" << std::endl ;
        #endif
   
      }
      else if (event.jaxis.value < -m_joystick_dead_zone) {

        m_joystick_values[which_one].second->set_y(-1);

        #ifdef DEBUG
        std::cout << "Joystick " << which_one << " axis 3 set to -1" << std::endl ;
        #endif
    
      }
      else {

        m_joystick_values[which_one].second->set_y(0);

        #ifdef DEBUG
        std::cout << "Joystick " << which_one << " axis 3 set to 0" << std::endl ;
        #endif
   
      }

    }


}

void Input_Handler::on_joystick_button_down(SDL_Event &event) {

  int which_one = event.jaxis.which;

  m_button_states[which_one][event.jbutton.button] = true;

  #ifdef DEBUG
  std::cout << "Joystick " << std::to_string(which_one) << " " <<  std::to_string(event.jbutton.button) << " Button down" << std::endl ;
  #endif

}

void Input_Handler::on_joystick_button_up(SDL_Event &event) {

  int which_one = event.jaxis.which;

  m_button_states[which_one][event.jbutton.button] = false;

  #ifdef DEBUG
  std::cout << "Joystick " << std::to_string(which_one) << " " <<  std::to_string(event.jbutton.button) << " Button up" << std::endl ;
  #endif

}