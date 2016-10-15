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

#include "joystick_configuration.h"

static bool get_joystick_button_value(int8_t joy, int8_t &button) ;

static inline void incr_button_dump_process(bool res, int8_t &val) ;

static bool get_joystick_arrows_value(int8_t joy, int8_t& button, int8_t& stick_x, int8_t& stick_y, bool x_axis=true) ;


inline void incr_button_dump_process(bool res, int8_t &val) {

  // Simply incremenent the control variable in relationship to button pressed.

  if (res) {

    if (val <= 16) {

      ++val ;

    }

  }

  return ;

}

bool get_joystick_button_value(int8_t joy, int8_t &button) {

  /** We highly suppose that the buttonA, buttonB, buttonC and buttonD are comprise into [0-3]. **/

  bool val0 = input_handler->get_button_state(joy, 0) ;
  bool val1 = input_handler->get_button_state(joy, 1) ;
  bool val2 = input_handler->get_button_state(joy, 2) ;
  bool val3 = input_handler->get_button_state(joy, 3) ;

  if      (val0)  { button = 0  ; return true   ;   }
  else if (val1)  { button = 1  ; return true   ;   }
  else if (val2)  { button = 2  ; return true   ;   }
  else if (val3)  { button = 3  ; return true   ;   }
  else            { button = -1 ; return false  ;   }

  // @NOTE: I cant' do otherwise per example setting more than 4 values tests doesn't work.

}

static bool get_joystick_arrows_value(int8_t joy, int8_t& button, int8_t& stick_x, int8_t& stick_y, bool x_axis) {

  /** Getting the value of an directional pad arrow, with fallback to the other axis. **/

  if (x_axis) {

    button = input_handler->get_axis_x(joy, 1) ;

    if (button != 0) {

      stick_x=1 ;

      return (button == -1 or button == 1) ;

    }

    button = input_handler->get_axis_x(joy, 2) ;

    if (button != 0) {

      stick_x=2 ;

      return (button == -1 or button == 1) ;

    }

    button = input_handler->get_axis_y(joy, 1) ;

    if (button != 0) {

      stick_x=1 ;

      return (button == -1 or button == 1) ;

    }

    button = input_handler->get_axis_y(joy, 2) ;

    if (button != 0) {

      stick_x = 2 ;

      return (button == -1 or button == 1) ;

    }

  }
  else {

    button = input_handler->get_axis_y(joy, 1) ;

    if (button != 0) {

      stick_y=1 ;

      return (button == -1 or button == 1) ;

    }

    button = input_handler->get_axis_y(joy, 2) ;

    if (button != 0) {

      stick_y=2 ;

      return (button == -1 or button == 1) ;

    }

    button = input_handler->get_axis_x(joy, 1) ;

    if (button != 0) {

      stick_y=1 ;

      return (button == -1 or button == 1) ;

    }

    button = input_handler->get_axis_x(joy, 2) ;

    if (button != 0) {

      stick_y=2 ;

      return (button == -1 or button == 1) ;
    }

  }

  return (button == -1 or button == 1) ;

}

bool configure_joystick(const int8_t joy, bool reconfigure) {

  /**   This function provide all the necessary to configure a joystick in order to play this game correctly.
    *   Because:
    *
    *   1. All joysticks doesn't work equally internally.
    *
    *   2. This game follow a logic for the buttons position and combination.
    *      Sea the joined notice for further informations.
    *
    *  @note: The joystick configuration is obliged for the reason explain above.
    *         And I'm not sure that it will work with every model, because I had only 2 joysticks for testing.
    *
    **********************************************************************************************************/

  bool loop ;

  #define set_loop(x) (loop=(x))


  SDL_JoystickUpdate() ;


  // Joystick images datas (buttons):
  SDL_Texture *directional_pad_image_texture = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/W_DPAD_all.png") ;

  // Joystick images datas white (buttons):
  SDL_Texture *white_button_a_image_texture = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/WbuttonA.png") ;
  SDL_Texture *white_button_b_image_texture = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/WbuttonB.png") ;
  SDL_Texture *white_button_c_image_texture = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/WbuttonX.png") ;
  SDL_Texture *white_button_d_image_texture = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/WbuttonY.png") ;

  // Joystick images datas black: for the blinking effect.
  SDL_Texture *black_button_a_image_texture = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/BbuttonA.png") ;
  SDL_Texture *black_button_b_image_texture = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/BbuttonB.png") ;
  SDL_Texture *black_button_c_image_texture = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/BbuttonX.png") ;
  SDL_Texture *black_button_d_image_texture = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/BbuttonY.png") ;

  // Joystick images datas black (directional pad): for the blinking effect.
  SDL_Texture *black_directional_pad_tmp_axis_X_forward_texture  = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/B_DPAD_right.png") ;
  SDL_Texture *black_directional_pad_tmp_axis_X_backward_texture = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/B_DPAD_left.png") ;
  SDL_Texture *black_directional_pad_tmp_axis_Y_upward_texture   = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/B_DPAD_up.png") ;
  SDL_Texture *black_directional_pad_tmp_axis_Y_downward_texture = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/B_DPAD_down.png") ;

  // Joystick images datas white (directional pad):
  SDL_Texture *white_directional_pad_tmp_axis_X_forward_texture  = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/W_DPAD_right.png") ;
  SDL_Texture *white_directional_pad_tmp_axis_X_backward_texture = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/W_DPAD_left.png") ;
  SDL_Texture *white_directional_pad_tmp_axis_Y_upward_texture   = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/W_DPAD_up.png") ;
  SDL_Texture *white_directional_pad_tmp_axis_Y_downward_texture = get_texture_from_image(pRenderer, PATH_TO_JOYSTICK_IMG "/W_DPAD_down.png") ;


  SDL_Color color_red ;

  color_red.r = 255 ;
  color_red.g = 0   ;
  color_red.b = 0   ;
  color_red.a = 255 ;

  SDL_Color color_yellow ;

  color_yellow.r = 255 ;
  color_yellow.g = 255 ;
  color_yellow.b = 0   ;
  color_yellow.a = 255 ;


  // Setting up text to display:

  Text *joystick_configure_text_title = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(joystick_configure_text_title) ;

  joystick_configure_text_title->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 36) ;

  const char *joystick_configuring_text_title{"Configuring joystick: "} ;

  TTF_SetFontHinting(joystick_configure_text_title->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, joystick_configure_text_title,  joystick_configuring_text_title, color_yellow, WIDTH/2, HEIGHT/2-245) ;




  Text *joystick_configure_vendor_id = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(joystick_configure_vendor_id) ;

  joystick_configure_vendor_id->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 26) ;

  TTF_SetFontHinting(joystick_configure_vendor_id->font, TTF_HINTING_LIGHT) ;




  if (reconfigure) {
  
    const char *joystick_configure_text_vendor_id = input_handler->get_vendor_id(joy).c_str() ;
  
    configure_text(pRenderer, joystick_configure_vendor_id,  joystick_configure_text_vendor_id, color_yellow, WIDTH/2, HEIGHT/2-210) ;
  }




  Text *joystick_configure_text_explanations = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(joystick_configure_text_explanations) ;

  joystick_configure_text_explanations->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 18) ;

  TTF_SetFontHinting(joystick_configure_text_title->font, TTF_HINTING_LIGHT) ;

  TTF_SetFontStyle(joystick_configure_text_title->font, TTF_STYLE_BOLD) ;

  const char *joystick_explanation_text{"You must configure your joystick in order to play this game.\n"
                                        "Because every different joystick works differently internally.\n"
                                        "You will only have to do this step\neverytime you plug a new joystick model to use this game."} ;



  configure_text_wrap(pRenderer, joystick_configure_text_explanations,  joystick_explanation_text, color_red, WIDTH/2 * 0.25 + 18, HEIGHT/2-190 + 9, 512*1.5) ;




  Text *joystick_configure_press_button = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(joystick_configure_press_button) ;

  joystick_configure_press_button->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 24) ;

  TTF_SetFontHinting(joystick_configure_press_button->font, TTF_HINTING_LIGHT) ;

  const char *joystick_configure_press_button_text{"Press the blinking button on your joystick."} ;

  const char *joystick_configure_terminate_text{"Joystick configuration finished, now press Return (Enter)."} ;

  configure_text(pRenderer, joystick_configure_press_button,  joystick_configure_press_button_text, color_yellow, WIDTH/2, HEIGHT/2+200) ;





  // Makes buttons blink.
  static bool blinking_switcher{false} ;

  // Joytsick button dump and configuration variables.
  int8_t tmp_buttonA{-1} ;
  int8_t tmp_buttonB{-1} ;
  int8_t tmp_buttonC{-1} ;
  int8_t tmp_buttonD{-1} ;

  // Joystick directional pad dump and configuration variable:
  int8_t tmp_axis_X_forward{0}  ;
  int8_t tmp_axis_X_backward{0} ;
  int8_t tmp_axis_Y_upward{0}  ;
  int8_t tmp_axis_Y_downward{0} ;

  int8_t tmp_stick_x{0} ;
  int8_t tmp_stick_y{0} ;

  // Control variables for buttons configuration.
  bool    result_of_joystick_dump{false} ;
  int8_t  joystick_configuration_phase_control{0} ;
  int8_t  tmp{-1} ;


  // Framerate control.
  const int FPS{12} ;
  const int FRAME_DELAY = roundf(1000.0f/static_cast<float>(FPS)) ;

  input_handler->reset() ;

  // Loop control.
  set_loop(true) ;

  while (loop) {

    int frame_start = SDL_GetTicks() ;

    clear(pRenderer, 0, 0, 0, 0) ;

    render_text(pRenderer, joystick_configure_text_title) ;
  
    if (reconfigure) {
      render_text(pRenderer, joystick_configure_vendor_id) ;
    }
  
    draw_rect(pRenderer, WIDTH/2 * 0.25, HEIGHT/2-190, WIDTH/2+WIDTH/4, 100, color_yellow, false) ;

    render_text(pRenderer, joystick_configure_text_explanations) ;

    draw_filled_rect_with_border(pRenderer, WIDTH/2-150, HEIGHT/2-50, 300, 150, 15, color_red, color_yellow) ;


    // Joystick buttons and directional pad images displaying:
    if (joystick_configuration_phase_control == 0 or joystick_configuration_phase_control == 1) {

      // Button 'A'.
      if (not blinking_switcher) {
        display_image(pRenderer, white_button_a_image_texture, WIDTH/2+10, HEIGHT/2) ;
      }
      else {
        display_image(pRenderer, black_button_a_image_texture, WIDTH/2+10, HEIGHT/2) ;
      }

      display_image(pRenderer, white_button_b_image_texture,          WIDTH/2+30+10,        HEIGHT/2-30)  ;
      display_image(pRenderer, white_button_c_image_texture,          WIDTH/2+30*2+10,      HEIGHT/2)     ;
      display_image(pRenderer, white_button_d_image_texture,          WIDTH/2+30+10,        HEIGHT/2+30)  ;

      display_image(pRenderer, directional_pad_image_texture,        WIDTH/2-120,      HEIGHT/2-25) ;
    }
    else if (joystick_configuration_phase_control == 2 or joystick_configuration_phase_control == 3) {

      // Button 'B'.
      if (not blinking_switcher) {
        display_image(pRenderer, white_button_b_image_texture,        WIDTH/2+30+10,        HEIGHT/2-30)  ;
      }
      else {
        display_image(pRenderer, black_button_b_image_texture,        WIDTH/2+30+10,        HEIGHT/2-30)  ;
      }

      display_image(pRenderer, white_button_a_image_texture,          WIDTH/2+10,           HEIGHT/2)     ;
      display_image(pRenderer, white_button_c_image_texture,          WIDTH/2+30*2+10,      HEIGHT/2)     ;
      display_image(pRenderer, white_button_d_image_texture,          WIDTH/2+30+10,        HEIGHT/2+30)  ;

      display_image(pRenderer, directional_pad_image_texture,        WIDTH/2-120,      HEIGHT/2-25) ;
    }
    else if (joystick_configuration_phase_control == 4 or joystick_configuration_phase_control == 5) {

      // Button 'C' (displayed as X, but named C internally).
      if (not blinking_switcher) {
        display_image(pRenderer, white_button_c_image_texture,        WIDTH/2+30*2+10,      HEIGHT/2)     ;
      }
      else {
        display_image(pRenderer, black_button_c_image_texture,        WIDTH/2+30*2+10,      HEIGHT/2)     ;
      }

      display_image(pRenderer, white_button_a_image_texture,          WIDTH/2+10,           HEIGHT/2)     ;
      display_image(pRenderer, white_button_b_image_texture,          WIDTH/2+30+10,        HEIGHT/2-30)  ;
      display_image(pRenderer, white_button_d_image_texture,          WIDTH/2+30+10,        HEIGHT/2+30)  ;

      display_image(pRenderer, directional_pad_image_texture,        WIDTH/2-120,      HEIGHT/2-25) ;
    }
    else if (joystick_configuration_phase_control == 6 or joystick_configuration_phase_control == 7) {

      // Button 'D' (displayed as Y, but named D internally).
      if (not blinking_switcher) {
        display_image(pRenderer, white_button_d_image_texture,        WIDTH/2+30+10,        HEIGHT/2+30)  ;
      }
      else {
        display_image(pRenderer, black_button_d_image_texture,        WIDTH/2+30+10,        HEIGHT/2+30)  ;
      }

      display_image(pRenderer, white_button_a_image_texture,          WIDTH/2+10,           HEIGHT/2)     ;
      display_image(pRenderer, white_button_b_image_texture,          WIDTH/2+30+10,        HEIGHT/2-30)  ;
      display_image(pRenderer, white_button_c_image_texture,          WIDTH/2+30*2+10,      HEIGHT/2)     ;

      display_image(pRenderer, directional_pad_image_texture,        WIDTH/2-120,          HEIGHT/2-25) ;
    }
    else if (joystick_configuration_phase_control == 8 or joystick_configuration_phase_control == 9) {

      // directional pad.
      if (not blinking_switcher) {
        display_image(pRenderer, white_directional_pad_tmp_axis_X_forward_texture, WIDTH/2-120,      HEIGHT/2-25)  ;
      }
      else {
        display_image(pRenderer, black_directional_pad_tmp_axis_X_forward_texture, WIDTH/2-120,      HEIGHT/2-25)  ;
      }

      display_image(pRenderer, white_button_a_image_texture,          WIDTH/2+10,           HEIGHT/2)     ;
      display_image(pRenderer, white_button_b_image_texture,          WIDTH/2+30+10,        HEIGHT/2-30)  ;
      display_image(pRenderer, white_button_c_image_texture,          WIDTH/2+30*2+10,      HEIGHT/2)     ;
      display_image(pRenderer, white_button_d_image_texture,          WIDTH/2+30+10,        HEIGHT/2+30)  ;

    }
    else if (joystick_configuration_phase_control == 10 or joystick_configuration_phase_control == 11) {

      // directional pad.
      if (not blinking_switcher) {
        display_image(pRenderer, white_directional_pad_tmp_axis_X_backward_texture, WIDTH/2-120,      HEIGHT/2-25)  ;
      }
      else {
        display_image(pRenderer, black_directional_pad_tmp_axis_X_backward_texture, WIDTH/2-120,      HEIGHT/2-25)  ;
      }

      display_image(pRenderer, white_button_a_image_texture,          WIDTH/2+10,           HEIGHT/2)     ;
      display_image(pRenderer, white_button_b_image_texture,          WIDTH/2+30+10,        HEIGHT/2-30)  ;
      display_image(pRenderer, white_button_c_image_texture,          WIDTH/2+30*2+10,      HEIGHT/2)     ;
      display_image(pRenderer, white_button_d_image_texture,          WIDTH/2+30+10,        HEIGHT/2+30)  ;

    }
    else if (joystick_configuration_phase_control == 12 or joystick_configuration_phase_control == 13) {

      // directional pad.
      if (not blinking_switcher) {
        display_image(pRenderer, white_directional_pad_tmp_axis_Y_upward_texture, WIDTH/2-120,      HEIGHT/2-25)  ;
      }
      else {
        display_image(pRenderer, black_directional_pad_tmp_axis_Y_upward_texture, WIDTH/2-120,      HEIGHT/2-25)  ;
      }

      display_image(pRenderer, white_button_a_image_texture,          WIDTH/2+10,           HEIGHT/2)     ;
      display_image(pRenderer, white_button_b_image_texture,          WIDTH/2+30+10,        HEIGHT/2-30)  ;
      display_image(pRenderer, white_button_c_image_texture,          WIDTH/2+30*2+10,      HEIGHT/2)     ;
      display_image(pRenderer, white_button_d_image_texture,          WIDTH/2+30+10,        HEIGHT/2+30)  ;

    }
    else if (joystick_configuration_phase_control == 14 or joystick_configuration_phase_control == 15) {

      // directional pad.
      if (not blinking_switcher) {
        display_image(pRenderer, white_directional_pad_tmp_axis_Y_downward_texture, WIDTH/2-120,      HEIGHT/2-25)  ;
      }
      else {
        display_image(pRenderer, black_directional_pad_tmp_axis_Y_downward_texture, WIDTH/2-120,      HEIGHT/2-25)  ;
      }

      display_image(pRenderer, white_button_a_image_texture,          WIDTH/2+10,           HEIGHT/2)     ;
      display_image(pRenderer, white_button_b_image_texture,          WIDTH/2+30+10,        HEIGHT/2-30)  ;
      display_image(pRenderer, white_button_c_image_texture,          WIDTH/2+30*2+10,      HEIGHT/2)     ;
      display_image(pRenderer, white_button_d_image_texture,          WIDTH/2+30+10,        HEIGHT/2+30)  ;

    }
    else {

      display_image(pRenderer, white_button_a_image_texture,          WIDTH/2+10,           HEIGHT/2)     ;
      display_image(pRenderer, white_button_b_image_texture,          WIDTH/2+30+10,        HEIGHT/2-30)  ;
      display_image(pRenderer, white_button_c_image_texture,          WIDTH/2+30*2+10,      HEIGHT/2)     ;
      display_image(pRenderer, white_button_d_image_texture,          WIDTH/2+30+10,        HEIGHT/2+30)  ;

      display_image(pRenderer, directional_pad_image_texture,        WIDTH/2-120,          HEIGHT/2-25) ;
    }



    // Acquire datas from user for joystick buttons and directional pad configuration.
    switch (joystick_configuration_phase_control) {


      case 0 :

        tmp={-1} ;

        result_of_joystick_dump = get_joystick_button_value(joy, tmp) ;

        if (tmp != -1) {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

      case 1 :

        tmp_buttonA={-1} ;

        result_of_joystick_dump = get_joystick_button_value(joy, tmp_buttonA) ;

        if (tmp != tmp_buttonA) {

          joystick_configuration_phase_control -= 1 ;

        }
        else {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

      case 2 :

        tmp={-1} ;

        result_of_joystick_dump = get_joystick_button_value(joy, tmp) ;

        if (tmp != -1) {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;


      case 3 :

        tmp_buttonB={-1} ;

        result_of_joystick_dump = get_joystick_button_value(joy, tmp_buttonB) ;

        if (tmp != tmp_buttonB) {

          joystick_configuration_phase_control -= 1 ;

        }
        else {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

      case 4 :

        tmp={-1} ;

        result_of_joystick_dump = get_joystick_button_value(joy, tmp) ;

        if (tmp != -1) {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;


      case 5 :

        tmp_buttonD={-1} ;

        result_of_joystick_dump = get_joystick_button_value(joy, tmp_buttonD) ;

        if (tmp != tmp_buttonD) {

          joystick_configuration_phase_control -= 1 ;

        }
        else {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

      case 6 :

        tmp={-1} ;

        result_of_joystick_dump = get_joystick_button_value(joy, tmp) ;

        if (tmp != -1) {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

      case 7 :

        tmp_buttonC={-1} ;

        result_of_joystick_dump = get_joystick_button_value(joy, tmp_buttonC) ;

        if (tmp != tmp_buttonC) {

          joystick_configuration_phase_control -= 1 ;

        }
        else {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

      case 8 :

        tmp={0} ;

        result_of_joystick_dump = get_joystick_arrows_value(joy, tmp, tmp_stick_x, tmp_stick_y) ;

        if (tmp != 0) {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

      case 9 :

        tmp_axis_X_forward={0} ;

        result_of_joystick_dump = get_joystick_arrows_value(joy, tmp_axis_X_forward, tmp_stick_x, tmp_stick_y) ;

        if (tmp != tmp_axis_X_forward) {

          joystick_configuration_phase_control -= 1 ;

        }
        else {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

      case 10 :

        tmp={0} ;

        result_of_joystick_dump = get_joystick_arrows_value(joy, tmp, tmp_stick_x, tmp_stick_y) ;

        if (tmp != 0) {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

      case 11 :

        tmp_axis_X_backward={0} ;

        result_of_joystick_dump = get_joystick_arrows_value(joy, tmp_axis_X_backward, tmp_stick_x, tmp_stick_y) ;

        if (tmp != tmp_axis_X_backward) {

          joystick_configuration_phase_control -= 1 ;

        }
        else {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

      case 12 :

        tmp={0} ;

        result_of_joystick_dump = get_joystick_arrows_value(joy, tmp, tmp_stick_x, tmp_stick_y, false) ;

        if (tmp != 0) {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

      case 13 :

        tmp_axis_Y_upward={0} ;

        result_of_joystick_dump = get_joystick_arrows_value(joy, tmp_axis_Y_upward, tmp_stick_x, tmp_stick_y, false) ;

        if (tmp != tmp_axis_Y_upward) {

          joystick_configuration_phase_control -= 1 ;

        }
        else {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

      case 14 :

        tmp={0} ;

        result_of_joystick_dump = get_joystick_arrows_value(joy, tmp, tmp_stick_x, tmp_stick_y, false) ;

        if (tmp != 0) {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

      case 15 :

        tmp_axis_Y_downward={0} ;

        result_of_joystick_dump = get_joystick_arrows_value(joy, tmp_axis_Y_downward, tmp_stick_x, tmp_stick_y, false) ;

        if (tmp != tmp_axis_Y_downward) {

          joystick_configuration_phase_control -= 1 ;

        }
        else {

          incr_button_dump_process(result_of_joystick_dump, joystick_configuration_phase_control) ;

        }

        break ;

    }






    if ( input_handler->is_key_down(SDL_SCANCODE_ESCAPE)) {

      std::string err_msg{"Error of configure joystick:\n"} ;
 
      err_msg += input_handler->get_vendor_id(joy) ;
 
      err_msg += "\n\nOoops ! If you exit the program now that will surely mean that you cannot configure your joystick\n"
      "You can retry to configure your joystick again.\n\n"
      "Else your joystick is really not compatible with this game\n\n"
      "Very sorry, consult the notice for further infomations." ;
 
      SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Joystick configuration failed !", err_msg.c_str(), pWindow) ;

      exit(EXIT_FAILURE) ;

    }

    if ( input_handler->is_key_down(SDL_SCANCODE_RETURN) and joystick_configuration_phase_control == 16) {

      set_loop(false) ;
    }

    if (joystick_configuration_phase_control == 16) {

      configure_text(pRenderer, joystick_configure_press_button,  joystick_configure_terminate_text, color_yellow, WIDTH/2, HEIGHT/2+200) ;

    }



    render_text(pRenderer, joystick_configure_press_button) ;


    input_handler->update() ;


    display(pRenderer) ;

    update(pWindow) ;



    blinking_switcher = not blinking_switcher ;



    int frame_end = SDL_GetTicks() - frame_start ;

    if (frame_end < FRAME_DELAY) {
      SDL_Delay(FRAME_DELAY - frame_end) ;
    }



  }


  destroy_text(joystick_configure_text_title) ;
  destroy_text(joystick_configure_vendor_id) ;
  destroy_text(joystick_configure_text_explanations) ;
  destroy_text(joystick_configure_press_button) ;

  SDL_DestroyTexture(directional_pad_image_texture) ;

  SDL_DestroyTexture(white_button_a_image_texture) ;
  SDL_DestroyTexture(white_button_b_image_texture) ;
  SDL_DestroyTexture(white_button_c_image_texture) ;
  SDL_DestroyTexture(white_button_d_image_texture) ;

  SDL_DestroyTexture(black_button_a_image_texture) ;
  SDL_DestroyTexture(black_button_b_image_texture) ;
  SDL_DestroyTexture(black_button_c_image_texture) ;
  SDL_DestroyTexture(black_button_d_image_texture) ;

  SDL_DestroyTexture(black_directional_pad_tmp_axis_X_forward_texture) ;
  SDL_DestroyTexture(black_directional_pad_tmp_axis_X_backward_texture) ;
  SDL_DestroyTexture(black_directional_pad_tmp_axis_Y_upward_texture) ;
  SDL_DestroyTexture(black_directional_pad_tmp_axis_Y_downward_texture) ;

  SDL_DestroyTexture(white_directional_pad_tmp_axis_X_forward_texture) ;
  SDL_DestroyTexture(white_directional_pad_tmp_axis_X_backward_texture) ;
  SDL_DestroyTexture(white_directional_pad_tmp_axis_Y_upward_texture) ;
  SDL_DestroyTexture(white_directional_pad_tmp_axis_Y_downward_texture) ;

  #ifdef DEBUG
  fprintf(stdout,"joy_1_buttonA: %d\n", joy_1_buttonA) ;
  fprintf(stdout,"joy_1_buttonB: %d\n", joy_1_buttonB) ;
  fprintf(stdout,"joy_1_buttonC: %d\n", joy_1_buttonC) ;
  fprintf(stdout,"joy_1_buttonD: %d\n", joy_1_buttonD) ;

  fprintf(stdout,"joy_1_axis_X_forward: %d\n",  joy_1_axis_X_forward) ;
  fprintf(stdout,"joy_1_axis_Y_upward: %d\n",   joy_1_axis_X_backward) ;
  fprintf(stdout,"joy_1_axis_Y_upward: %d\n",   joy_1_axis_Y_upward) ;
  fprintf(stdout,"joy_1_axis_Y_downward: %d\n", joy_1_axis_Y_downward) ;

  fprintf(stdout,"joy_1_stick_x: %d\n", joy_1_stick_x) ;
  fprintf(stdout,"joy_1_stick_y: %d\n", joy_1_stick_y) ;

  fprintf(stdout,"\n") ;

  fprintf(stdout,"joy_2_buttonA: %d\n", joy_2_buttonA) ;
  fprintf(stdout,"joy_2_buttonB: %d\n", joy_2_buttonB) ;
  fprintf(stdout,"joy_2_buttonC: %d\n", joy_2_buttonC) ;
  fprintf(stdout,"joy_2_buttonD: %d\n", joy_2_buttonD) ;

  fprintf(stdout,"joy_2_axis_X_forward: %d\n", joy_2_axis_X_forward) ;
  fprintf(stdout,"joy_2_axis_Y_upward: %d\n",   joy_2_axis_X_backward) ;
  fprintf(stdout,"joy_2_axis_Y_upward: %d\n",   joy_2_axis_Y_upward) ;
  fprintf(stdout,"joy_2_axis_Y_downward: %d\n", joy_2_axis_Y_downward) ;

  fprintf(stdout,"joy_2_stick_x: %d\n", joy_2_stick_x) ;
  fprintf(stdout,"joy_2_stick_y: %d\n", joy_2_stick_y) ;
  #endif


  if (tmp_buttonA == -1 or tmp_buttonB == -1 or tmp_buttonC == -1 or tmp_buttonD == -1) {

    // Case the configuration fail !

    return false ;

  }

  if (tmp_axis_X_backward == 0 or tmp_axis_X_forward == 0 or tmp_axis_Y_downward == 0 or tmp_axis_Y_upward == 0) {

    // Case the configuration fail !

    return false ;

  }

  if (tmp_stick_x == 0 or tmp_stick_y == 0) {
 
    // Case the configuration fail !
 
    return false ;

  }

  buttonA={tmp_buttonA} ;
  buttonB={tmp_buttonB} ;
  buttonC={tmp_buttonC} ;
  buttonD={tmp_buttonD} ;

  axis_X_forward={tmp_axis_X_forward} ;
  axis_X_backward={tmp_axis_X_backward} ;
  axis_Y_upward={tmp_axis_Y_upward} ;
  axis_Y_downward={tmp_axis_Y_downward} ;

  stick_x={tmp_stick_x} ;
  stick_y={tmp_stick_y} ;

  return true ;

}


bool is_joystick_know(const int8_t joy) {

  /** Tghis function return if the given joystick is in configuration file. **/

  std::ifstream configuration_file(PATH_TO_JOY_CONF_FILE, std::ios::in) ;

  std::string test ;

  while ( std::getline(configuration_file, test) ) {

    auto pos = test.find("=") ;

    std::string key = test.substr(0, pos) ;

    std::string value = test.substr(pos+1) ;

    #ifdef DEBUG
    std::cout << __func__ << " " << key << " = " << value << std::endl ;
    #endif

    if (key == "vendor_id") {

      if (value == input_handler->get_vendor_id(joy)) {

        return true ;
      }

    }

  }

  configuration_file.close() ;

  return false ;

}




void write_new_joystick_configuration(const int8_t joy) {

  /** Function called by reconfigure joystick. **/

  std::ofstream configuration_file(PATH_TO_JOY_CONF_FILE, std::ios::out | std::ios::app) ;

  configuration_file << "vendor_id="  + input_handler->get_vendor_id(joy) << std::endl ;

  configuration_file << "buttonA="    + std::to_string(buttonA) << std::endl ;

  configuration_file << "buttonB="    + std::to_string(buttonB) << std::endl ;

  configuration_file << "buttonC="    + std::to_string(buttonC) << std::endl ;

  configuration_file << "buttonD="    + std::to_string(buttonD) << std::endl ;

  configuration_file << "axis_X_forward="    + std::to_string(axis_X_forward) << std::endl ;

  configuration_file << "axis_X_backward="    + std::to_string(axis_X_backward) << std::endl ;

  configuration_file << "axis_Y_upward="      + std::to_string(axis_Y_upward) << std::endl ;

  configuration_file << "axis_Y_downward="    + std::to_string(axis_Y_downward) << std::endl ;

  configuration_file << "stick_x="            + std::to_string(stick_x) << std::endl ;

  configuration_file << "stick_y="            + std::to_string(stick_y) << std::endl ;

  configuration_file.close() ;

}

void read_joystick_configuration(const int8_t joy) {

  /** Read the joystick configuration file **/

  std::ifstream configuration_file(PATH_TO_JOY_CONF_FILE, std::ios::in) ;

  bool joystick_found{false} ;

  while (not configuration_file.eof()) {

    std::string line ;

    getline(configuration_file, line) ;

    auto pos = line.find("=") ;

    std::string key = line.substr(0, pos) ;

    std::string value = line.substr(pos+1) ;

    if (key == "vendor_id") {

      if (value == input_handler->get_vendor_id(joy)) {

        joystick_found = true ;

        #ifdef DEBUG
        std::cout << __func__ << " joystick found :" << input_handler->get_vendor_id(joy) << std::endl ;
        #endif

        continue ;
      }
    }

    if (joystick_found) {

      if (key == "buttonA") {

        if (joy == 0) {

          joy_1_buttonA = static_cast<int8_t>(std::stoi(value)) ;
        }
        else if (joy == 1) {

          joy_2_buttonA = static_cast<int8_t>(std::stoi(value)) ;
        }


      }
      else if (key == "buttonB") {

        if (joy == 0) {

          joy_1_buttonB = static_cast<int8_t>(std::stoi(value)) ;
        }
        else if (joy == 1) {

          joy_2_buttonB = static_cast<int8_t>(std::stoi(value)) ;
        }

      }
      else if (key == "buttonC") {

        if (joy == 0) {

          joy_1_buttonC = static_cast<int8_t>(std::stoi(value)) ;
        }
        else if (joy == 1) {

          joy_2_buttonC = static_cast<int8_t>(std::stoi(value)) ;
        }

      }
      else if (key == "buttonD") {

        if (joy == 0) {

          joy_1_buttonD = static_cast<int8_t>(std::stoi(value)) ;
        }
        else if (joy == 1) {

          joy_2_buttonD = static_cast<int8_t>(std::stoi(value)) ;
        }

      }
      else if (key == "axis_X_forward") {

        if (joy == 0) {

          joy_1_axis_X_forward = static_cast<int8_t>(std::stoi(value)) ;
        }
        else if (joy == 1) {

          joy_2_axis_X_forward = static_cast<int8_t>(std::stoi(value)) ;
        }

      }
      else if (key == "axis_X_backward") {

        if (joy == 0) {

          joy_1_axis_X_backward = static_cast<int8_t>(std::stoi(value)) ;
        }
        else if (joy == 1) {

          joy_2_axis_X_backward = static_cast<int8_t>(std::stoi(value)) ;
        }

      }
      else if (key == "axis_Y_upward") {

        if (joy == 0) {

          joy_1_axis_Y_upward = static_cast<int8_t>(std::stoi(value)) ;
        }
        else if (joy == 1) {

          joy_2_axis_Y_upward = static_cast<int8_t>(std::stoi(value)) ;
        }

      }
      else if (key == "axis_Y_downward") {

        if (joy == 0) {

          joy_1_axis_Y_downward = static_cast<int8_t>(std::stoi(value)) ;
        }
        else if (joy == 1) {

          joy_2_axis_Y_downward = static_cast<int8_t>(std::stoi(value)) ;
        }

      }
      else if (key == "stick_x") {

        if (joy == 0) {

          joy_1_stick_x = static_cast<int8_t>(std::stoi(value)) ;
        }
        else if (joy == 1) {

          joy_2_stick_x = static_cast<int8_t>(std::stoi(value)) ;

        }

      }
      else if (key == "stick_y") {

        if (joy == 0) {

          joy_1_stick_y = static_cast<int8_t>(std::stoi(value)) ;
        }
        else if (joy == 1) {

          joy_2_stick_y = static_cast<int8_t>(std::stoi(value)) ;

        }

        #ifdef DEBUG
        fprintf(stdout,"joy_1_buttonA: %d\n", joy_1_buttonA) ;
        fprintf(stdout,"joy_1_buttonB: %d\n", joy_1_buttonB) ;
        fprintf(stdout,"joy_1_buttonC: %d\n", joy_1_buttonC) ;
        fprintf(stdout,"joy_1_buttonD: %d\n", joy_1_buttonD) ;

        fprintf(stdout,"joy_1_axis_X_forward: %d\n",  joy_1_axis_X_forward) ;
        fprintf(stdout,"joy_1_axis_Y_upward: %d\n",   joy_1_axis_X_backward) ;
        fprintf(stdout,"joy_1_axis_Y_upward: %d\n",   joy_1_axis_Y_upward) ;
        fprintf(stdout,"joy_1_axis_Y_downward: %d\n", joy_1_axis_Y_downward) ;

        fprintf(stdout,"joy_1_stick_x: %d\n", joy_1_stick_x) ;
        fprintf(stdout,"joy_1_stick_y: %d\n", joy_1_stick_y) ;

        fprintf(stdout,"\n") ;

        fprintf(stdout,"joy_2_buttonA: %d\n", joy_2_buttonA) ;
        fprintf(stdout,"joy_2_buttonB: %d\n", joy_2_buttonB) ;
        fprintf(stdout,"joy_2_buttonC: %d\n", joy_2_buttonC) ;
        fprintf(stdout,"joy_2_buttonD: %d\n", joy_2_buttonD) ;

        fprintf(stdout,"joy_2_axis_X_forward: %d\n", joy_2_axis_X_forward) ;
        fprintf(stdout,"joy_2_axis_Y_upward: %d\n",   joy_2_axis_X_backward) ;
        fprintf(stdout,"joy_2_axis_Y_upward: %d\n",   joy_2_axis_Y_upward) ;
        fprintf(stdout,"joy_2_axis_Y_downward: %d\n", joy_2_axis_Y_downward) ;

        fprintf(stdout,"joy_2_stick_x: %d\n", joy_2_stick_x) ;
        fprintf(stdout,"joy_2_stick_y: %d\n", joy_2_stick_y) ;
        #endif

        configuration_file.close() ;

        return ;
      }

    }

  }

  configuration_file.close() ;

  return ;

}

void reconfigure_joystick_file(const int8_t joy) {

  /** Function called by reconfigure joystick. **/

  std::ifstream configuration_file(PATH_TO_JOY_CONF_FILE, std::ios::in) ;

  bool joystick_found{false} ;

  std::string buffer{} ;

  while (not configuration_file.eof()) {
 
    // Read current configuration by omit the wanted joystick.
 
    std::string line ;

    getline(configuration_file, line) ;

    auto pos = line.find("=") ;

    std::string key = line.substr(0, pos) ;

    std::string value = line.substr(pos+1) ;

    if (key.empty() and value.empty()) {

      continue ;
    }

    if (key == "vendor_id") {

      if (value == input_handler->get_vendor_id(joy)) {

        joystick_found = true ;

        #ifdef DEBUG
        std::cout << __func__ << " joystick found :" << input_handler->get_vendor_id(joy) << std::endl ;
        #endif

        continue ;
      }
    }

    if (joystick_found) {

      if (key == "stick_y") {

        joystick_found={false} ;
        continue ;

      }

    }
    else {

      if (not key.empty() and not value.empty()) {

        buffer +=  key + "=" + value + '\n' ;

      }

    }

  }

  configuration_file.close() ;

  // Write new configuration.
  std::ofstream write_file(PATH_TO_JOY_CONF_FILE, std::ios::out | std::ios::trunc) ;

  write_file << buffer ;

  write_file.close() ;

  write_new_joystick_configuration(joy) ;

}