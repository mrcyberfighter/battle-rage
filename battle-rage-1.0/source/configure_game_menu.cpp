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

#include "./configure_game_menu.h"

/**
  * + difficulties: EASY/NORMAL/HARD/Equals.
  *
  * + Game speed: LOW / MEDIUM / FAST
  *
  * + configure joystick.
  *
  * + Sound ON/OFF.
  *
  * + Music ON/OFF.
*/


int8_t configure_game_menu(void) {

  /** This function permit to the user to configure the game as he like.
    *
    ********************************************************************/

  #ifdef DEBUG
  fprintf(stdout,"%s(...) call\n", __func__) ;
  #endif

  int8_t ret{0} ;

  bool loop ;

  #define set_loop(x) (loop=(x))


  SDL_JoystickUpdate() ;


  // tmp_* variables to not alter the current configuration.
  int8_t tmp_game_difficulty = game_difficulty ;
  int8_t tmp_game_speed      = game_speed ;
  bool tmp_game_sounds  = game_sounds ;
  bool tmp_game_music   = game_music ;

  // Getting the background floor height:
  SDL_Texture *bg_floor = get_texture_from_image(pRenderer, PATH_TO_BACKGROUND "/floor.png") ;
  int bg_floor_h ;
  SDL_QueryTexture(bg_floor, NULL, NULL, NULL, &bg_floor_h) ;
  SDL_DestroyTexture(bg_floor) ;


  SDL_Color colorkey ;
  colorkey.r = 255  ;
  colorkey.g = 0    ;
  colorkey.b = 255  ;

  SDL_Texture *bg_bridge  = get_texture_with_colokey_from_image(pRenderer, PATH_TO_BACKGROUND "/floor.png", colorkey) ;
  SDL_Texture *tiger_logo = get_texture_from_image(pRenderer, PATH_TO_ICON "/Fire_Tiger.png") ;

  #define LOGO_OFFSET -(HEIGHT/8)-(16+2)



  SDL_Color color_yellow ;
  color_yellow.r = 255 ;
  color_yellow.g = 255 ;
  color_yellow.b = 0   ;
  color_yellow.a = 255 ;


  #define OFFSET (150)

  #define FONT_SIZE_MENU_TITLE 42

  #define FONT_SIZE_MENU_1 32

  #define FONT_SIZE_MENU_2 26

  #define FONT_SIZE_OFFSET (36*2)



  Text *config_game_menu_text_title = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(config_game_menu_text_title) ;

  config_game_menu_text_title->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_TITLE) ;

  std::string config_game_menu_text_title_title{"Battle-Rage configure game menu:"} ;

  TTF_SetFontHinting(config_game_menu_text_title->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, config_game_menu_text_title,  config_game_menu_text_title_title.c_str(), color_yellow, WIDTH/2, FONT_SIZE_OFFSET) ;


  Text *config_game_menu_text_difficulty = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(config_game_menu_text_difficulty) ;

  config_game_menu_text_difficulty->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_1) ;

  std::string config_game_menu_text_difficulty_text = "+] Game difficulty: " + ((tmp_game_difficulty == 0) ? std::string{"NORMAL"} : (tmp_game_difficulty == 1) ? std::string{"HARD"} : (tmp_game_difficulty == -1) ? std::string{"EASY"} : std::string{"MISC"}) ;

  TTF_SetFontHinting(config_game_menu_text_difficulty->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, config_game_menu_text_difficulty,  config_game_menu_text_difficulty_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2, false) ;


  Text *config_game_menu_text_tmp_game_speed = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(config_game_menu_text_tmp_game_speed) ;

  config_game_menu_text_tmp_game_speed->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_1) ;

  std::string config_game_menu_text_game_speed_text = "+] Game speed: " + ((tmp_game_speed == 0) ? std::string{"NORMAL"} : (tmp_game_speed == -1) ? std::string{"SLOW"} : std::string{"FAST"}) ;

  TTF_SetFontHinting(config_game_menu_text_tmp_game_speed->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, config_game_menu_text_tmp_game_speed,  config_game_menu_text_game_speed_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*2, false) ;



  Text *config_game_menu_text_sound_on_off = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(config_game_menu_text_sound_on_off) ;

  config_game_menu_text_sound_on_off->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_1) ;

  std::string config_game_menu_text_sound_on_off_text = "+] Game Sounds: " + ((tmp_game_sounds) ? std::string{"ON"} : std::string{"OFF"}) ;

  TTF_SetFontHinting(config_game_menu_text_sound_on_off->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, config_game_menu_text_sound_on_off,  config_game_menu_text_sound_on_off_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*4, false) ;


  Text *config_game_menu_text_music_on_off = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(config_game_menu_text_music_on_off) ;

  config_game_menu_text_music_on_off->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_1) ;

  std::string config_game_menu_text_music_on_off_text = "+] Game Music: " + ((tmp_game_music ? std::string{"ON"} : std::string{"OFF"})) ;

  TTF_SetFontHinting(config_game_menu_text_music_on_off->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, config_game_menu_text_music_on_off,  config_game_menu_text_music_on_off_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0 + FONT_SIZE_MENU_1*6, false) ;



  Text *config_game_menu_text_save_settings = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(config_game_menu_text_save_settings) ;

  config_game_menu_text_save_settings->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_1) ;

  std::string config_game_menu_text_save_settings_text = "+] Save and Exit !" ;

  TTF_SetFontHinting(config_game_menu_text_save_settings->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, config_game_menu_text_save_settings,  config_game_menu_text_save_settings_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*8, false) ;


  Text *config_game_menu_text_exit = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(config_game_menu_text_exit) ;

  config_game_menu_text_exit->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_1) ;

  std::string config_game_menu_text_exit_text = "+] Exit without Saving !" ;

  TTF_SetFontHinting(config_game_menu_text_exit->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, config_game_menu_text_exit,  config_game_menu_text_exit_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*10, false) ;

  // Control variables:
  bool blink_switcher{true} ;
  uint8_t blink_counter{0} ;
  int8_t choice{0} ;

  // Framerate control.
  const int FPS = 5 ;
  const int FRAME_DELAY = roundf(1000.0f/static_cast<float>(FPS)) ;

  input_handler->reset() ;

  set_loop(true) ;

  while (loop) {

    int frame_start = SDL_GetTicks() ;

    clear(pRenderer, 0, 0, 0, 0) ;

    switch (choice) {

      case 0 :

        config_game_menu_text_difficulty_text = "-] Game difficulty: " + ((tmp_game_difficulty == 0) ? std::string{"NORMAL"} : (tmp_game_difficulty == 1) ? std::string{"HARD"} : (tmp_game_difficulty == -1) ? std::string{"EASY"} : std::string{"MISC"}) ;

        config_game_menu_text_sound_on_off_text.at(0)   = '+' ;
        config_game_menu_text_music_on_off_text.at(0)   = '+' ;
        config_game_menu_text_game_speed_text.at(0)     = '+' ;
        config_game_menu_text_save_settings_text.at(0)  = '+' ;
        config_game_menu_text_exit_text.at(0)           = '+' ;

        configure_text(pRenderer, config_game_menu_text_difficulty,  config_game_menu_text_difficulty_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2, false) ;

        configure_text(pRenderer, config_game_menu_text_tmp_game_speed,  config_game_menu_text_game_speed_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*2, false) ;
        configure_text(pRenderer, config_game_menu_text_sound_on_off,  config_game_menu_text_sound_on_off_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*4, false) ;
        configure_text(pRenderer, config_game_menu_text_music_on_off,  config_game_menu_text_music_on_off_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*6, false) ;
        configure_text(pRenderer, config_game_menu_text_save_settings,  config_game_menu_text_save_settings_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*8, false) ;
        configure_text(pRenderer, config_game_menu_text_exit,  config_game_menu_text_exit_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*10, false) ;
        break ;

      case 1 :

        config_game_menu_text_game_speed_text = "-] Game speed: " + ((tmp_game_speed == 0) ? std::string{"NORMAL"} : (tmp_game_speed == -1) ? std::string{"SLOW"} : std::string{"FAST"}) ;

        config_game_menu_text_sound_on_off_text.at(0)   = '+' ;
        config_game_menu_text_music_on_off_text.at(0)   = '+' ;
        config_game_menu_text_difficulty_text.at(0)     = '+' ;
        config_game_menu_text_save_settings_text.at(0)  = '+' ;
        config_game_menu_text_exit_text.at(0)      = '+' ;

        configure_text(pRenderer, config_game_menu_text_tmp_game_speed,  config_game_menu_text_game_speed_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*2, false) ;

        configure_text(pRenderer, config_game_menu_text_difficulty,  config_game_menu_text_difficulty_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2, false) ;
        configure_text(pRenderer, config_game_menu_text_sound_on_off,  config_game_menu_text_sound_on_off_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*4, false) ;
        configure_text(pRenderer, config_game_menu_text_music_on_off,  config_game_menu_text_music_on_off_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*6, false) ;
        configure_text(pRenderer, config_game_menu_text_save_settings,  config_game_menu_text_save_settings_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*8, false) ;
        configure_text(pRenderer, config_game_menu_text_exit,  config_game_menu_text_exit_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*10, false) ;
        break ;

      case 2 :

        config_game_menu_text_sound_on_off_text = "-] Game Sounds: " + ((tmp_game_sounds) ? std::string{"ON"} : std::string{"OFF"}) ;

        config_game_menu_text_music_on_off_text.at(0)   = '+' ;
        config_game_menu_text_game_speed_text.at(0)     = '+' ;
        config_game_menu_text_difficulty_text.at(0)     = '+' ;
        config_game_menu_text_save_settings_text.at(0)  = '+' ;
        config_game_menu_text_exit_text.at(0)           = '+' ;

        configure_text(pRenderer, config_game_menu_text_sound_on_off,  config_game_menu_text_sound_on_off_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*4, false) ;

        configure_text(pRenderer, config_game_menu_text_difficulty,  config_game_menu_text_difficulty_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2, false) ;
        configure_text(pRenderer, config_game_menu_text_tmp_game_speed,  config_game_menu_text_game_speed_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*2, false) ;
        configure_text(pRenderer, config_game_menu_text_music_on_off,  config_game_menu_text_music_on_off_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*6, false) ;
        configure_text(pRenderer, config_game_menu_text_save_settings,  config_game_menu_text_save_settings_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*8, false) ;
        configure_text(pRenderer, config_game_menu_text_exit,  config_game_menu_text_exit_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*10, false) ;
        break ;

      case 3 :

        config_game_menu_text_music_on_off_text = "-] Game Music: " + ((tmp_game_music ? std::string{"ON"} : std::string{"OFF"})) ;

        config_game_menu_text_sound_on_off_text.at(0)   = '+' ;
        config_game_menu_text_game_speed_text.at(0)     = '+' ;
        config_game_menu_text_difficulty_text.at(0)     = '+' ;
        config_game_menu_text_save_settings_text.at(0)  = '+' ;
        config_game_menu_text_exit_text.at(0)           = '+' ;

        configure_text(pRenderer, config_game_menu_text_music_on_off,  config_game_menu_text_music_on_off_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*6, false) ;

        configure_text(pRenderer, config_game_menu_text_difficulty,  config_game_menu_text_difficulty_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2, false) ;
        configure_text(pRenderer, config_game_menu_text_tmp_game_speed,  config_game_menu_text_game_speed_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*2, false) ;
        configure_text(pRenderer, config_game_menu_text_sound_on_off,  config_game_menu_text_sound_on_off_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*4, false) ;
        configure_text(pRenderer, config_game_menu_text_save_settings,  config_game_menu_text_save_settings_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*8, false) ;
        configure_text(pRenderer, config_game_menu_text_exit,  config_game_menu_text_exit_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*10, false) ;
        break ;

      case 4 :

        config_game_menu_text_save_settings_text = "-] Save and Exit !" ;

        config_game_menu_text_music_on_off_text.at(0) = '+' ;
        config_game_menu_text_sound_on_off_text.at(0) = '+' ;
        config_game_menu_text_game_speed_text.at(0)   = '+' ;
        config_game_menu_text_difficulty_text.at(0)   = '+' ;
        config_game_menu_text_exit_text.at(0)         = '+' ;

        configure_text(pRenderer, config_game_menu_text_save_settings,  config_game_menu_text_save_settings_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*8, false) ;

        configure_text(pRenderer, config_game_menu_text_difficulty,  config_game_menu_text_difficulty_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2, false) ;
        configure_text(pRenderer, config_game_menu_text_tmp_game_speed,  config_game_menu_text_game_speed_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*2, false) ;
        configure_text(pRenderer, config_game_menu_text_sound_on_off,  config_game_menu_text_sound_on_off_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*4, false) ;
        configure_text(pRenderer, config_game_menu_text_exit,  config_game_menu_text_exit_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*10, false) ;
        break ;

      case 5 :

        config_game_menu_text_exit_text = "-] Exit without Saving !" ;

        config_game_menu_text_music_on_off_text.at(0)   = '+' ;
        config_game_menu_text_sound_on_off_text.at(0)   = '+' ;
        config_game_menu_text_game_speed_text.at(0)     = '+' ;
        config_game_menu_text_difficulty_text.at(0)     = '+' ;
        config_game_menu_text_save_settings_text.at(0)  = '+' ;

        configure_text(pRenderer, config_game_menu_text_exit,  config_game_menu_text_exit_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*10, false) ;

        configure_text(pRenderer, config_game_menu_text_difficulty,  config_game_menu_text_difficulty_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2, false) ;
        configure_text(pRenderer, config_game_menu_text_tmp_game_speed,  config_game_menu_text_game_speed_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*2, false) ;
        configure_text(pRenderer, config_game_menu_text_sound_on_off,  config_game_menu_text_sound_on_off_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*4, false) ;
        configure_text(pRenderer, config_game_menu_text_save_settings,  config_game_menu_text_save_settings_text.c_str(), color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_1*8, false) ;
        break ;

    }





    display_image(pRenderer, bg_bridge, WIDTH/2, HEIGHT-(bg_floor_h/2), true) ;
    display_image(pRenderer, tiger_logo, FONT_SIZE_MENU_1, 32) ;






    render_text(pRenderer, config_game_menu_text_title) ;


    if (blink_switcher and blink_counter % 2 == 0 and choice == 0) {
      render_text(pRenderer, config_game_menu_text_difficulty) ;
    }
    else if (choice != 0) {
      render_text(pRenderer, config_game_menu_text_difficulty) ;
    }

    if (blink_switcher and blink_counter % 2 == 0  and choice == 1) {
      render_text(pRenderer, config_game_menu_text_tmp_game_speed) ;
    }
    else if (choice != 1) {
      render_text(pRenderer, config_game_menu_text_tmp_game_speed) ;
    }

    if (blink_switcher and blink_counter % 2 == 0  and choice == 2) {
      render_text(pRenderer, config_game_menu_text_sound_on_off) ;
    }
    else if (choice != 2) {
      render_text(pRenderer, config_game_menu_text_sound_on_off) ;
    }

    if (blink_switcher and blink_counter % 2 == 0  and choice == 3) {
      render_text(pRenderer, config_game_menu_text_music_on_off) ;
    }
    else if (choice != 3) {
      render_text(pRenderer, config_game_menu_text_music_on_off) ;
    }

    if (blink_switcher and blink_counter % 2 == 0  and choice == 4) {
      render_text(pRenderer, config_game_menu_text_save_settings) ;
    }
    else if (choice != 4) {
      render_text(pRenderer, config_game_menu_text_save_settings) ;
    }

    if (blink_switcher and blink_counter % 2 == 0  and choice == 5) {
      render_text(pRenderer, config_game_menu_text_exit) ;
    }
    else if (choice != 5) {
      render_text(pRenderer, config_game_menu_text_exit) ;
    }



    auto x_axis = input_handler->get_axis_x(0, joy_1_stick_x) ;
    auto y_axis = input_handler->get_axis_y(0, joy_1_stick_y) ;

    if (x_axis != 0 and y_axis != 0) {

      goto joystick_confusion ;

    }

    if (y_axis == joy_1_axis_Y_upward) {

      if (choice > 0) {

        --choice ;
      }
    }
    else if (y_axis == joy_1_axis_Y_downward) {

      if (choice < 5) {

        ++choice ;
      }
    }

    switch (choice) {

      case 0 :

        if (x_axis == joy_1_axis_X_forward) {

          if (tmp_game_difficulty < 2) {

            ++tmp_game_difficulty ;
          }

        }
        else if (x_axis == joy_1_axis_X_backward) {

          if (tmp_game_difficulty > -1) {

            --tmp_game_difficulty ;
          }

        }

        break ;

     case 1 :

       if (x_axis == joy_1_axis_X_forward) {

          if (tmp_game_speed < 1) {

            ++tmp_game_speed ;
          }

        }
        else if (x_axis == joy_1_axis_X_backward) {

          if (tmp_game_speed > -1) {

            --tmp_game_speed ;
          }

        }

        break ;

     case 2 :

       if (x_axis == joy_1_axis_X_forward or x_axis == joy_1_axis_X_backward) {

          tmp_game_sounds = not tmp_game_sounds ;

       }

       break ;

     case 3 :

       if (x_axis == joy_1_axis_X_forward or x_axis == joy_1_axis_X_backward) {

          tmp_game_music = not tmp_game_music ;

       }

       break ;

    }







    joystick_confusion :

    auto button = input_handler->get_button_state(0, joy_1_buttonA) ;

    if (button) {

      if (choice == 4) {

        game_difficulty = tmp_game_difficulty ;
        game_speed      = tmp_game_speed  ;

        game_sounds = tmp_game_sounds ;
        game_music  = tmp_game_music  ;

        write_game_configuration_to_file() ;
      }

      set_loop(false) ;

    }

    button = input_handler->get_button_state(0, joy_1_buttonB) ;

    if (button) {

      if (choice == 4) {

        game_difficulty = tmp_game_difficulty ;
        game_speed      = tmp_game_speed  ;

        game_sounds = tmp_game_sounds ;
        game_music  = tmp_game_music  ;

        write_game_configuration_to_file() ;
      }

      set_loop(false) ;

    }

    button = input_handler->get_button_state(0, joy_1_buttonC) ;

    if (button) {

      if (choice == 4) {

        game_difficulty = tmp_game_difficulty ;
        game_speed      = tmp_game_speed  ;

        game_sounds = tmp_game_sounds ;
        game_music  = tmp_game_music  ;

        write_game_configuration_to_file() ;
      }

      set_loop(false) ;

    }

    button = input_handler->get_button_state(0, joy_1_buttonD) ;

    if (button) {

      if (choice == 4) {

        game_difficulty = tmp_game_difficulty ;
        game_speed      = tmp_game_speed  ;

        game_sounds = tmp_game_sounds ;
        game_music  = tmp_game_music  ;

        write_game_configuration_to_file() ;
      }

      set_loop(false) ;

    }

    input_handler->update() ;

    if ( input_handler->is_key_down(SDL_SCANCODE_ESCAPE) ) {

       ret={-1} ;
  
       set_loop(false) ;
  
    }

    if ( input_handler->is_key_down(SDL_SCANCODE_RETURN) ) {

      if (choice == 4) {

        game_difficulty = tmp_game_difficulty ;
        game_speed      = tmp_game_speed  ;

        game_sounds = tmp_game_sounds ;
        game_music  = tmp_game_music  ;

        write_game_configuration_to_file() ;
      }

      set_loop(false) ;
    }


    blink_switcher = not blink_switcher ;

    display(pRenderer) ;

    update(pWindow) ;


    int frame_end = SDL_GetTicks() - frame_start ;

    if (frame_end < FRAME_DELAY) {
      SDL_Delay(FRAME_DELAY - frame_end) ;
    }




  }


  // Free ressources...
  SDL_DestroyTexture(tiger_logo) ;
  SDL_DestroyTexture(bg_bridge) ;

  destroy_text(config_game_menu_text_title) ;
  destroy_text(config_game_menu_text_difficulty) ;
  destroy_text(config_game_menu_text_tmp_game_speed) ;
  destroy_text(config_game_menu_text_sound_on_off) ;
  destroy_text(config_game_menu_text_music_on_off) ;
  destroy_text(config_game_menu_text_save_settings) ;
  destroy_text(config_game_menu_text_exit) ;

  return ret ;

}