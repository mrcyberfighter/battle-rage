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

#include "./main_menu.h"

static int which_joystick_reconfigure(void) ;

int8_t main_menu(void) {

  /** This function display the main menu from the game. **/


  bool loop ;

  #define set_loop(x) (loop=(x))


  SDL_JoystickUpdate() ;


  SDL_Texture *bg_floor = get_texture_from_image(pRenderer, PATH_TO_BACKGROUND "/floor.png") ;

  int bg_floor_h ;

  SDL_QueryTexture(bg_floor, NULL, NULL, NULL, &bg_floor_h) ;

  SDL_DestroyTexture(bg_floor) ;

  SDL_Color colorkey ;
  colorkey.r = 255  ;
  colorkey.g = 0    ;
  colorkey.b = 255  ;

  SDL_Texture *bg_bridge  = get_texture_with_colokey_from_image(pRenderer, PATH_TO_BACKGROUND "/floor.png", colorkey) ;

  SDL_Texture *tiger_logo = get_texture_from_image(pRenderer, PATH_TO_ICON "/Fire_Tiger.png") ; // "/Fire_Tiger.png") ;

  #define LOGO_OFFSET -(HEIGHT/8)-(16+2)



  SDL_Color color_yellow ;
  color_yellow.r = 255 ;
  color_yellow.g = 255 ;
  color_yellow.b = 0   ;
  color_yellow.a = 255 ;





  #define OFFSET (175)

  #define FONT_SIZE_MENU_TITLE 42

  #define FONT_SIZE_MENU_1 32

  #define FONT_SIZE_MENU_2 26

  #define FONT_SIZE_OFFSET (36*2)

  // Text to display:
  Text *main_menu_text_title = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(main_menu_text_title) ;

  main_menu_text_title->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_TITLE) ;

  const char *main_menu_text_title_title{"Battle-Rage main menu:"} ;

  TTF_SetFontHinting(main_menu_text_title->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, main_menu_text_title,  main_menu_text_title_title, color_yellow, WIDTH/2, FONT_SIZE_OFFSET) ;


  Text *main_menu_text_play = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(main_menu_text_play) ;

  main_menu_text_play->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_1) ;

  const char *main_menu_text_play_text{"=> Play"} ;
  const char *main_menu_text_play_text_select{"-> Play"} ;

  TTF_SetFontHinting(main_menu_text_play->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, main_menu_text_play,  main_menu_text_play_text, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2, false) ;


  Text *menu_play_player_vs_computer = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(menu_play_player_vs_computer) ;

  menu_play_player_vs_computer->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_2) ;

  const char *menu_play_player_vs_computer_text{"+] Player vs Computer"} ;
  const char *menu_play_player_vs_computer_text_select{"-] Player vs Computer"} ;

  TTF_SetFontHinting(menu_play_player_vs_computer->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, menu_play_player_vs_computer,  menu_play_player_vs_computer_text, color_yellow, WIDTH/2-OFFSET+FONT_SIZE_MENU_1, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*2.0, false) ;


  Text *menu_play_player_vs_player = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(menu_play_player_vs_player) ;

  menu_play_player_vs_player->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_2) ;

  const char *menu_play_player_vs_player_text{"+] Player vs Player"} ;
  const char *menu_play_player_vs_player_text_select{"-] Player vs Player"} ;

  TTF_SetFontHinting(menu_play_player_vs_player->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, menu_play_player_vs_player,  menu_play_player_vs_player_text, color_yellow, WIDTH/2-OFFSET+FONT_SIZE_MENU_1, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*3.5, false) ;


  Text *menu_play_computer_vs_computer = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(menu_play_computer_vs_computer) ;

  menu_play_computer_vs_computer->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_2) ;

  const char *menu_play_computer_vs_computer_text{"+] Computer vs Computer"} ;
  const char *menu_play_computer_vs_computer_text_select{"-] Computer vs Computer"} ;

  TTF_SetFontHinting(menu_play_computer_vs_computer->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, menu_play_computer_vs_computer,  menu_play_computer_vs_computer_text, color_yellow, WIDTH/2-OFFSET+FONT_SIZE_MENU_1, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0, false) ;


  Text *main_menu_text_configure_game = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(main_menu_text_configure_game) ;

  main_menu_text_configure_game->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_1) ;

  const char *main_menu_text_configure_game_text{"=> Configure game"} ;
  const char *main_menu_text_configure_game_text_select{"-> Configure game"} ;

  TTF_SetFontHinting(main_menu_text_configure_game->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, main_menu_text_configure_game,  main_menu_text_configure_game_text, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0 + FONT_SIZE_MENU_1*2, false) ;



  Text *main_menu_text_configure_joystick = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(main_menu_text_configure_joystick) ;

  main_menu_text_configure_joystick->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_1) ;

  const char *main_menu_text_configure_joystick_text{"=> Reconfigure Joystick"} ;
  const char *main_menu_text_configure_joystick_text_select{"-> Reconfigure Joystick"} ;

  TTF_SetFontHinting(main_menu_text_configure_joystick->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, main_menu_text_configure_joystick,  main_menu_text_configure_joystick_text, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0 + FONT_SIZE_MENU_1*4, false) ;


  Text *main_menu_text_read_notice = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(main_menu_text_read_notice) ;

  main_menu_text_read_notice->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE_MENU_1) ;

  const char *main_menu_text_read_notice_text{"=> Read Notice"} ;
  const char *main_menu_text_read_notice_text_select{"-> Read Notice"} ;

  TTF_SetFontHinting(main_menu_text_read_notice->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, main_menu_text_read_notice,  main_menu_text_read_notice_text, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0 + FONT_SIZE_MENU_1*6, false) ;

  // Control variables:
  bool blink_switcher{true} ;
  int8_t choice{1} ;

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

        configure_text(pRenderer, main_menu_text_play,  main_menu_text_play_text_select, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2, false) ;
        configure_text(pRenderer, menu_play_player_vs_computer,  menu_play_player_vs_computer_text, color_yellow, WIDTH/2-OFFSET+FONT_SIZE_MENU_1, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*2.0, false) ;
        break ;

      case 1 :

        configure_text(pRenderer, menu_play_player_vs_computer,  menu_play_player_vs_computer_text_select, color_yellow, WIDTH/2-OFFSET+FONT_SIZE_MENU_1, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*2.0, false) ;

        configure_text(pRenderer, main_menu_text_play,  main_menu_text_play_text, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2, false) ;
        configure_text(pRenderer, menu_play_player_vs_player,  menu_play_player_vs_player_text, color_yellow, WIDTH/2-OFFSET+FONT_SIZE_MENU_1, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*3.5, false) ;
        break ;

      case 2 :

        configure_text(pRenderer, menu_play_player_vs_player,  menu_play_player_vs_player_text_select, color_yellow, WIDTH/2-OFFSET+FONT_SIZE_MENU_1, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*3.5, false) ;

        configure_text(pRenderer, menu_play_player_vs_computer,  menu_play_player_vs_computer_text, color_yellow, WIDTH/2-OFFSET+FONT_SIZE_MENU_1, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*2.0, false) ;
        configure_text(pRenderer, menu_play_computer_vs_computer,  menu_play_computer_vs_computer_text, color_yellow, WIDTH/2-OFFSET+FONT_SIZE_MENU_1, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0, false) ;
        break ;

      case 3 :

        configure_text(pRenderer, menu_play_computer_vs_computer,  menu_play_computer_vs_computer_text_select, color_yellow, WIDTH/2-OFFSET+FONT_SIZE_MENU_1, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0, false) ;

        configure_text(pRenderer, menu_play_player_vs_player,  menu_play_player_vs_player_text, color_yellow, WIDTH/2-OFFSET+FONT_SIZE_MENU_1, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*3.5, false) ;
        configure_text(pRenderer, main_menu_text_configure_game,  main_menu_text_configure_game_text, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0 + FONT_SIZE_MENU_1*2, false) ;
        break ;

      case 4 :

        configure_text(pRenderer, main_menu_text_configure_game,  main_menu_text_configure_game_text_select, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0 + FONT_SIZE_MENU_1*2, false) ;

        configure_text(pRenderer, menu_play_computer_vs_computer,  menu_play_computer_vs_computer_text, color_yellow, WIDTH/2-OFFSET+FONT_SIZE_MENU_1, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0, false) ;
        configure_text(pRenderer, main_menu_text_configure_joystick,  main_menu_text_configure_joystick_text, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0 + FONT_SIZE_MENU_1*4, false) ;
        break ;

      case 5 :

        configure_text(pRenderer, main_menu_text_configure_joystick,  main_menu_text_configure_joystick_text_select, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0 + FONT_SIZE_MENU_1*4, false) ;

        configure_text(pRenderer, main_menu_text_configure_game,  main_menu_text_configure_game_text, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0 + FONT_SIZE_MENU_1*2, false) ;
        configure_text(pRenderer, main_menu_text_read_notice,  main_menu_text_read_notice_text, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0 + FONT_SIZE_MENU_1*6, false) ;
        break ;

      case 6 :

        configure_text(pRenderer, main_menu_text_read_notice,  main_menu_text_read_notice_text_select, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0 + FONT_SIZE_MENU_1*6, false) ;

        configure_text(pRenderer, main_menu_text_configure_joystick,  main_menu_text_configure_joystick_text, color_yellow, WIDTH/2-OFFSET, FONT_SIZE_OFFSET+FONT_SIZE_MENU_1*2+FONT_SIZE_MENU_2*5.0 + FONT_SIZE_MENU_1*4, false) ;
        break ;

    }





    display_image(pRenderer, bg_bridge, WIDTH/2, HEIGHT-(bg_floor_h/2), true) ;
    display_image(pRenderer, tiger_logo, FONT_SIZE_MENU_1, 32) ;






    render_text(pRenderer, main_menu_text_title) ;


    if (blink_switcher and choice == 0) {
      render_text(pRenderer, main_menu_text_play) ;
    }
    else if (choice != 0) {
      render_text(pRenderer, main_menu_text_play) ;
    }

    if (blink_switcher and choice == 1) {
      render_text(pRenderer, menu_play_player_vs_computer) ;
    }
    else if (choice != 1) {
      render_text(pRenderer, menu_play_player_vs_computer) ;
    }

    if (blink_switcher and choice == 2) {
      render_text(pRenderer, menu_play_player_vs_player) ;
    }
    else if (choice != 2) {
      render_text(pRenderer, menu_play_player_vs_player) ;
    }

    if (blink_switcher and choice == 3) {
      render_text(pRenderer, menu_play_computer_vs_computer) ;
    }
    else if (choice != 3) {
      render_text(pRenderer, menu_play_computer_vs_computer) ;
    }

    if (blink_switcher and choice == 4) {
      render_text(pRenderer, main_menu_text_configure_game) ;
    }
    else if (choice != 4) {
      render_text(pRenderer, main_menu_text_configure_game) ;
    }

    if (blink_switcher and choice == 5) {
      render_text(pRenderer, main_menu_text_configure_joystick) ;
    }
    else if (choice != 5) {
      render_text(pRenderer, main_menu_text_configure_joystick) ;
    }

    if (blink_switcher and choice == 6) {
      render_text(pRenderer, main_menu_text_read_notice) ;
    }
    else if (choice != 6) {
      render_text(pRenderer, main_menu_text_read_notice) ;
    }




    auto y_axis = input_handler->get_axis_y(0, joy_1_stick_y) ;

    if (y_axis == joy_1_axis_Y_upward) {

      if (choice > 0) {

        --choice ;
      }
    }
    else if (y_axis == joy_1_axis_Y_downward) {

      if (choice < 6) {

        ++choice ;
      }
    }

    auto button = input_handler->get_button_state(0, joy_1_buttonA) ;

    if (button) {

      if (input_handler->get_nb_of_joysticks_plugged() < 2 and choice == 2) {

        std::string err_msg{"\nNot enougth joystic plugged:\nFor playing: Player vs Player.\nYou must plug another joystick before\npressing Return (Enter) at the start screen.\n\nFor futher informations please read the notice."} ;
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Joysticks error:", err_msg.c_str(), pWindow) ;

        choice = -1 ;

      }
      else if (choice == 5 and input_handler->get_nb_of_joysticks_plugged() >= 2) {

        choice=which_joystick_reconfigure() ;


      }

      set_loop(false) ;
    }

    button = input_handler->get_button_state(0, joy_1_buttonB) ;

    if (button) {

      if (input_handler->get_nb_of_joysticks_plugged() < 2 and choice == 2) {

        std::string err_msg{"\nNot enougth joystic plugged:\nFor playing: Player vs Player.\nYou must plug another joystick before\npressing Return (Enter) at the start screen.\n\nFor futher informations please read the notice."} ;
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Joysticks error:", err_msg.c_str(), pWindow) ;

        choice = -1 ;

      }
      else if (choice == 5 and input_handler->get_nb_of_joysticks_plugged() >= 2) {

        choice=which_joystick_reconfigure() ;

      }


      set_loop(false) ;
    }

    button = input_handler->get_button_state(0, joy_1_buttonC) ;

    if (button) {

      if (input_handler->get_nb_of_joysticks_plugged() < 2 and choice == 2) {

        std::string err_msg{"\nNot enougth joystic plugged:\nFor playing: Player vs Player.\nYou must plug another joystick before\npressing Return (Enter) at the start screen.\n\nFor futher informations please read the notice."} ;
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Joysticks error:", err_msg.c_str(), pWindow) ;

        choice = -1 ;

      }
      else if (choice == 5 and input_handler->get_nb_of_joysticks_plugged() >= 2) {

        choice=which_joystick_reconfigure() ;

      }

      set_loop(false) ;
    }

    button = input_handler->get_button_state(0, joy_1_buttonD) ;

    if (button) {

      if (input_handler->get_nb_of_joysticks_plugged() < 2 and choice == 2) {

        std::string err_msg{"\nNot enougth joystic plugged:\nFor playing: Player vs Player.\nYou must plug another joystick before\npressing Return (Enter) at the start screen.\n\nFor futher informations please read the notice."} ;
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Joysticks error:", err_msg.c_str(), pWindow) ;

        choice = -1 ;

      }
      else if (choice == 5 and input_handler->get_nb_of_joysticks_plugged() >= 2) {

        choice=which_joystick_reconfigure() ;

      }

      set_loop(false) ;
    }

    input_handler->update() ;

    if ( input_handler->is_key_down(SDL_SCANCODE_ESCAPE) ) {

       choice={-3} ;

       set_loop(false) ;

    }

    if ( input_handler->is_key_down(SDL_SCANCODE_RETURN) ) {

       if (input_handler->get_nb_of_joysticks_plugged() < 2 and choice == 2) {

        std::string err_msg{"\nNot enougth joystic plugged:\nFor playing: Player vs Player.\nYou must plug another joystick before...\nAnd pressing Return (Enter) at the start screen.\n\nFor futher informations please read the notice."} ;
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Joysticks error:", err_msg.c_str(), pWindow) ;

        choice = -1 ;

      }
      else if (choice == 5 and input_handler->get_nb_of_joysticks_plugged() >= 2) {

        choice=which_joystick_reconfigure() ;

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







  SDL_DestroyTexture(tiger_logo) ;
  SDL_DestroyTexture(bg_bridge)  ;


  destroy_text(main_menu_text_play) ;
  destroy_text(menu_play_player_vs_computer) ;
  destroy_text(menu_play_player_vs_player) ;
  destroy_text(menu_play_computer_vs_computer) ;
  destroy_text(main_menu_text_configure_game) ;
  destroy_text(main_menu_text_read_notice) ;

  return choice ;

}

static int which_joystick_reconfigure(void) {

  const SDL_MessageBoxButtonData buttons[] = {

    { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT,  5, "Joystick 1" },
    { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, -2, "Joystick 2" },

  } ;


  const SDL_MessageBoxData messageboxdata = {
      SDL_MESSAGEBOX_INFORMATION,       /* .flags */
      NULL,                         /* .window */
      "Which joystick reconfigure ?",
      "Reconfigure joystick 1 (which you are using).   -> press Return.\n"
      "Or reconfigure the other joystick (joystick 2). -> press Escape.",
      SDL_arraysize(buttons),       /* .numbuttons */
      buttons,                      /* .buttons */
      NULL

  } ;

  int buttonid;

  if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {

    SDL_Log("error displaying message box");
    return -3 ;

  }

  return buttonid ;

}