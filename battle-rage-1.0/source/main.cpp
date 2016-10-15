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

#include "./headers/includes.h"
#include <fstream>

#include "./headers/defines.h"

#include "./global_vars.h"

#include "./global_fighters.h"

#include "./joystick.h"

#include "./helper_templates.h"

#include "./helper_functions.h"

#include "./joystick_configuration.h"

#include "./choose_fighters.h"

#include "./fighting_mainloop.h"

#include "./presentation_screen.h"

#include "./main_menu.h"

#include "./configure_game_menu.h"

#include "./round_interlude.h"


static int joystick_not_plugged_can_exit(void) ;

static std::shared_ptr<Fighters> get_fighter_from_index(const int8_t idx, const bool is_player, const bool computer_vs_computer = false) ;

static void read_game_configuration_from_file(void) ;






int main(void) {

  atexit(&at_exit) ;

  SDL_Surface *battle_rage_icon = NULL ;

  reinitialized :

  if (sdl_init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0 ) {
    std::string err_msg{"SDL2 initialize failure:\n"} ;
    err_msg += SDL_GetError() ;
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error initialize SDL2", err_msg.c_str(), NULL) ;
    exit(EXIT_FAILURE) ;
  }

  if (not  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {

    fprintf(stderr,"Set hint: SDL_HINT_RENDER_SCALE_QUALITY 1 failed\n") ;

  }

  if (not SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1") ) {

    fprintf(stderr, "Set hint: SDL_HINT_RENDER_VSYNC 1 failed\n") ;

  }

  if ( IMG_Init(IMG_INIT_PNG) == 0 ) {
    std::string err_msg{"SDL_image library could not initialize !\nSDL_image error:\n"} ;
    err_msg += SDL_GetError() ;
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error initialize SDL_image", err_msg.c_str(), NULL) ;
    SDL_Quit() ;
    exit(EXIT_FAILURE) ;
  }

  if (TTF_Init() == -1) {
    std::string err_msg{"SDL_ttf library could not initialize !\nSDL_ttf error:\n"} ;
    err_msg += TTF_GetError() ;
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error initialize SDL_ttf", err_msg.c_str(), NULL) ;
    IMG_Quit() ;
    SDL_Quit() ;
    exit(EXIT_FAILURE) ;
  }



  int mix_flags=MIX_INIT_OGG  ;

  int initted = Mix_Init(mix_flags) ;

  if ( (initted & mix_flags) != mix_flags) {

    std::string err_msg{"SDL_mxier library could not initialize !\nSDL_mixer error:\n"} ;
    err_msg += Mix_GetError() ;
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error initialize SDL_mixer", err_msg.c_str(), NULL) ;
    TTF_Quit() ;
    IMG_Quit() ;
    SDL_Quit() ;
    exit(EXIT_FAILURE) ;

  }


  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    std::string err_msg{"SDL_mixer could not initialize !\nSDL_mixer Error:\n"} ;
    err_msg += Mix_GetError() ;
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error initialize SDL_mixer", err_msg.c_str(), NULL) ;
    TTF_Quit() ;
    IMG_Quit() ;
    SDL_Quit() ;
    exit(EXIT_FAILURE) ;

  }

  // allocate 8 mixing channels
  //Mix_AllocateChannels(8) ;
  //Mix_ReserveChannels(8);

  #ifdef DEBUG // Extract from the SDL2 documentation.
  int i;
  for ( i = 0; i < SDL_GetNumAudioDrivers(); ++i ) {
      printf("Audio driver %d: %s\n", i, SDL_GetAudioDriver(i));
  }

  int numtimesopened, frequency, channels;
  Uint16 format;
  numtimesopened=Mix_QuerySpec(&frequency, &format, &channels);
  if (!numtimesopened) {
      printf("Mix_QuerySpec: %s\n",Mix_GetError());
  }
  else {
      const char *format_str="Unknown";
      switch(format) {
          case AUDIO_U8: format_str="U8"; break;
          case AUDIO_S8: format_str="S8"; break;
          case AUDIO_U16LSB: format_str="U16LSB"; break;
          case AUDIO_S16LSB: format_str="S16LSB"; break;
          case AUDIO_U16MSB: format_str="U16MSB"; break;
          case AUDIO_S16MSB: format_str="S16MSB"; break;
      }
      printf("opened=%d times  frequency=%dHz  format=%s  channels=%d\n", numtimesopened, frequency, format_str, channels);
  }
  #endif






  input_handler->initialise_joysticks() ;

  while (not input_handler->joysticks_initialised()) {

    int res = joystick_not_plugged_can_exit() ;

    switch (res) {

      case 1 :

        IMG_Quit() ;
        TTF_Quit() ;
        Mix_CloseAudio() ;
        Mix_Quit() ;
        SDL_Quit() ;

        goto reinitialized ;

      case 2 :

        exit(EXIT_SUCCESS) ;

      default :

        exit(EXIT_SUCCESS) ;

     }



  }









  pWindow = sdl_create_window(PRGNAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN) ;

  if (pWindow == NULL ) {

    std::string err_msg{"Fail to create SDL window:\n"} ;
    err_msg += SDL_GetError() ;
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL fatal error !", err_msg.c_str(), NULL) ;
    exit(EXIT_FAILURE) ;
  }


  if ((pRenderer = sdl_create_renderer(pWindow,-1, 0)) == NULL) {

    std::string err_msg{"SDL Renderer creating error:\n"} ;
    err_msg += SDL_GetError() ;
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL fatal error !", err_msg.c_str(), pWindow) ;
    exit(EXIT_FAILURE) ;
  }

  battle_rage_icon = IMG_Load(PATH_TO_ICON "/battle-rage_icon.png") ;

  SDL_SetWindowIcon(pWindow, battle_rage_icon) ;

  SDL_FreeSurface(battle_rage_icon);


  construct_map_sound() ;

  read_game_configuration_from_file() ;

  #ifdef DEBUG
  fprintf(stdout,"game_difficulty: %d\n", game_difficulty) ;
  fprintf(stdout,"game_speed: %d\n", game_speed) ;
  fprintf(stdout,"game_sounds: %d\n", game_sounds) ;
  fprintf(stdout,"game_music: %d\n", game_music) ;
  #endif

  // Mainloop of the entire game.
  start :

  //presentation_screen() ;  // FIXME: If problem with joystick reconfigure -> uncomment.

  auto nb_of_joysticks_plugged = input_handler->get_nb_of_joysticks_plugged() ;

  bool is_joystick_configure{false} ;

  for (uint8_t c=0 ; c < nb_of_joysticks_plugged ; ++c) {

    if (not is_joystick_know(c)) {

      is_joystick_configure = configure_joystick(c) ;

      if (not is_joystick_configure) {

        std::string err_msg{"Error of configure joystick:\n"} ;

        err_msg += input_handler->get_vendor_id(c) ;

        err_msg += "\n\nIn the most bad case your joystick isn't compatible with this game.\n"
        "Maybe you will bereave of some functionalities.\n"
        "But you can retry to configure your joytsick again.\n\n"
        "Very sorry, consult the notice for further infomations.\n" ;

        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Joystick configuration failed !", err_msg.c_str(), pWindow) ;

        exit(EXIT_FAILURE) ;

      }
      else {

        std::string err_msg{"\nConfiguration of this joystick model registered:\n"} ;
        err_msg += input_handler->get_vendor_id(c) ;
        err_msg += "\n\nIf you have made a misstake during the configuration by error\nor if you remark some dysfunctionalities of your joystick:\nReconfigure it through the configure joystick menu item.\n\nYou will only have to configure a joystick when a new model of joystick is plug for the first time.\n\nFor further informations read the notice." ;
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Configuration of joystick sucessfull !", err_msg.c_str(), pWindow) ;

        write_new_joystick_configuration(c) ;

      }

    }
    else {

      is_joystick_configure={true} ;

    }

  }

  if (is_joystick_configure) {

    #ifdef DEBUG
    std::cout << "read_joystick_configuration OK\n" ;
    #endif

    for (int8_t c{0} ; c < nb_of_joysticks_plugged ; ++c) {

      #ifdef DEBUG
      std::cout << "Reading joystick N° " << std::to_string(c) << " configuration." << std::endl ;
      #endif

      read_joystick_configuration(c) ;

    }

  }

  presentation_screen() ;  // FIXME: If problem with joystick reconfigure -> comment line.

  auto control_menu = main_menu() ;

  switch (control_menu) {

    case 2 : {

      // Case Player vs Player mode.

      auto fighter_1_choice=choose_fighter(0) ;

      if (fighter_1_choice == -1) {

        goto start ;
      }

      std::shared_ptr<Fighters> fighter1 = get_fighter_from_index(fighter_1_choice, true) ;

      if (not fighter1) {

        break ;
      }

      auto fighter_2_choice=choose_fighter(1) ;

      if (fighter_2_choice == -1) {

        if (fighter1) {
          fighter1.reset() ;
        }
      
        goto start ;
      }

      std::shared_ptr<Fighters> fighter2 = get_fighter_from_index(fighter_2_choice, true) ;

      if (not fighter2) {
  
        fighter1.reset() ;
  
        break ;
      }

      fighter1->m_is_player= true ;
      fighter2->m_is_player= true ;




      int8_t round_nb={1} ;

      int8_t ret ;

      ret=fighting_mainloop(fighter1.get(), fighter2.get(), round_nb) ;

      if (ret == -2) {

        if (fighter1) {
          fighter1.reset() ;
        }
        if (fighter2) {
          fighter2.reset() ;
        }

        goto start ;

      }

      ret=round_interlude(fighter1->get_name().c_str(), fighter2->get_name().c_str(), round_nb, (ret == -1) ? true : false) ;

      if (ret == -1) {

        if (fighter1) {
          fighter1.reset() ;
        }
        if (fighter2) {
          fighter2.reset() ;
        }

        goto start ;

      }


      ++round_nb ;



      ret=fighting_mainloop(fighter1.get(), fighter2.get(), round_nb) ;

      if (ret == -2) {

        if (fighter1) {
          fighter1.reset() ;
        }
        if (fighter2) {
          fighter2.reset() ;
        }

        goto start ;

      }

      if ((fighter1->rounds_win == 1) and (fighter2->rounds_win == 1)) {

        ret=round_interlude(fighter1->get_name().c_str(), fighter2->get_name().c_str(), round_nb, (ret == -1) ? true : false) ;

        if (ret == -1) {

          if (fighter1) {
            fighter1.reset() ;
          }
          if (fighter2) {
            fighter2.reset() ;
          }

          goto start ;

        }

        ++round_nb ;

        ret=fighting_mainloop(fighter1.get(), fighter2.get(), round_nb) ;

        if (ret == -2) {

          if (fighter1) {
            fighter1.reset() ;
          }
          if (fighter2) {
            fighter2.reset() ;
          }

          goto start ;

        }

        ++round_nb ;

        round_interlude(fighter1->get_name().c_str(), fighter2->get_name().c_str(), round_nb, (ret == -1) ? true : false) ;

      }
      else {

        ++round_nb ;

        ++round_nb ;

        round_interlude(fighter1->get_name().c_str(), fighter2->get_name().c_str(), round_nb, (fighter1->rounds_win == 2) ? true : false) ;


      }




      if (fighter1) {
        fighter1.reset() ;
      }
      if (fighter2) {
        fighter2.reset() ;
      }



      break ;

    }
    case 3 : {

      // Case Computer vs Computer mode.

      auto fighter_1_choice=choose_fighter(-2) ;

      if (fighter_1_choice == -1) {

        goto start ;
      }

      std::shared_ptr<Fighters> fighter1 = get_fighter_from_index(fighter_1_choice, false, true) ;

      if (not fighter1) {

        break ;
      }

      auto fighter_2_choice=choose_fighter(-2) ;

      if (fighter_2_choice == -1) {

        if (fighter1) {
          fighter1.reset() ;
        }
    
        goto start ;
      }

      std::shared_ptr<Fighters> fighter2 = get_fighter_from_index(fighter_2_choice, false, true) ;

      if (not fighter2) {
  
        fighter1.reset() ;
  
        break ;
      }

      fighter1->m_is_player= false ;
      fighter2->m_is_player= false ;

      int8_t round_nb={1} ;

      int8_t ret ;

      ret=fighting_mainloop(fighter1.get(), fighter2.get(), round_nb) ;

      if (ret == -2) {

        if (fighter1) {
          fighter1.reset() ;
        }
        if (fighter2) {
          fighter2.reset() ;
        }

        goto start ;

      }

      ret=round_interlude(fighter1->get_name().c_str(), fighter2->get_name().c_str(), round_nb, (ret == -1) ? true : false) ;

      if (ret == -1) {

        if (fighter1) {
          fighter1.reset() ;
        }
        if (fighter2) {
          fighter2.reset() ;
        }

        goto start ;

      }

      ++round_nb ;



      ret=fighting_mainloop(fighter1.get(), fighter2.get(), round_nb) ;

      if (ret == -2) {

        if (fighter1) {
          fighter1.reset() ;
        }
        if (fighter2) {
          fighter2.reset() ;
        }

        goto start ;

      }

      if ((fighter1->rounds_win == 1) and (fighter2->rounds_win == 1)) {

        ret=round_interlude(fighter1->get_name().c_str(), fighter2->get_name().c_str(), round_nb, (ret == -1) ? true : false) ;

        if (ret == -1) {

          if (fighter1) {
            fighter1.reset() ;
          }
          if (fighter2) {
            fighter2.reset() ;
          }

          goto start ;

        }

        ++round_nb ;

        ret=fighting_mainloop(fighter1.get(), fighter2.get(), round_nb) ;

        if (ret == -2) {

          fighter1.reset() ;
          fighter2.reset() ;

          goto start ;

        }

        ++round_nb ;

        round_interlude(fighter1->get_name().c_str(), fighter2->get_name().c_str(), round_nb, (ret == -1) ? true : false) ;

      }
      else {

        ++round_nb ;

        ++round_nb ;

        round_interlude(fighter1->get_name().c_str(), fighter2->get_name().c_str(), round_nb, (fighter1->rounds_win == 2) ? true : false) ;


      }




      if (fighter1) {
        fighter1.reset() ;
      }
      if (fighter2) {
        fighter2.reset() ;
      }

      break ;

    }
    case 4 : {

      // Case configure game choice.

      auto ret = configure_game_menu() ;

      if (ret == -1) {

        goto start ;

      }

      break ;

    }
    case 5 :

      // Case reconfigure joystick 1 (index 0).

      configure_joystick(0, true) ;
      reconfigure_joystick_file(0) ;

      break ;

    case 6 : {

      auto sys_ret = system("xdg-open " PATH_TO_NOTICE) ;
      if ( sys_ret == 0) {

        std::string err_msg{"\nNotice available in your favorite browser."} ;
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Notice !", err_msg.c_str(), pWindow) ;

      }
      else {

        std::string err_msg{"\nError by launching the html notice into your favorite browser.\n\n"} ;

        err_msg += strerror(sys_ret) ;

        err_msg += '\n' ;

        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error launching notice !", err_msg.c_str(), pWindow) ;

      }


      break ;

    }
    case -1 :

      // Case the new plugged joystick mustbe add to game.

      input_handler->add_a_joystick(1) ;
      goto start ;

    case -2 :

      // Case reconfigure joystick 2 (index 1).

      configure_joystick(1, true) ;
      reconfigure_joystick_file(1) ;
      break ;

    case -3 :

      break ;


    default :  // choice 0 and 1.

      auto fighter_1_choice=choose_fighter(0)   ;

      if (fighter_1_choice == -1) {

        goto start ;
      }

      std::shared_ptr<Fighters> fighter1 = get_fighter_from_index(fighter_1_choice, true) ;

      if (not fighter1) {

        break ;
      }

      auto fighter_2_choice=choose_fighter(-1)  ;

      if (fighter_2_choice == -1) {

        if (fighter1) {
          fighter1.reset() ;
        }
   
        goto start ;
      }

      std::shared_ptr<Fighters> fighter2 = get_fighter_from_index(fighter_2_choice, false) ;

      if (not fighter2) {
   
        fighter1.reset() ;
   
        break ;
      }

      fighter1->m_is_player= true   ;
      fighter2->m_is_player= false  ;

      int8_t round_nb={1} ;

      int8_t ret ;

      ret=fighting_mainloop(fighter1.get(), fighter2.get(), round_nb) ;

      if (ret == -2) {

        if (fighter1) {
          fighter1.reset() ;
        }
        if (fighter2) {
          fighter2.reset() ;
        }

        goto start ;

      }

      ret=round_interlude(fighter1->get_name().c_str(), fighter2->get_name().c_str(), round_nb, (ret == -1) ? true : false) ;

      if (ret == -1) {

        fighter1.reset() ;
        fighter2.reset() ;

        goto start ;

      }

      ++round_nb ;



      ret=fighting_mainloop(fighter1.get(), fighter2.get(), round_nb) ;

      if (ret == -2) {

        if (fighter1) {
          fighter1.reset() ;
        }
        if (fighter2) {
          fighter2.reset() ;
        }

        goto start ;

      }

      if ((fighter1->rounds_win == 1) and (fighter2->rounds_win == 1)) {

        ret=round_interlude(fighter1->get_name().c_str(), fighter2->get_name().c_str(), round_nb, (ret == -1) ? true : false) ;

        if (ret == -1) {

          if (fighter1) {
            fighter1.reset() ;
          }
          if (fighter2) {
            fighter2.reset() ;
          }

          goto start ;

        }

        ++round_nb ;

        ret=fighting_mainloop(fighter1.get(), fighter2.get(), round_nb) ;

        if (ret == -2) {

          if (fighter1) {
            fighter1.reset() ;
          }
          if (fighter2) {
            fighter2.reset() ;
          }

          goto start ;

        }

        final_message(fighter1->get_name().c_str(), fighter2->get_name().c_str(), (ret == -1) ? true : false) ;

      }
      else {

        final_message(fighter1->get_name().c_str(), fighter2->get_name().c_str(), (fighter1->rounds_win == 2) ? true : false) ;

      }

      /** FIXME: It produce an segmentation error HERE sometimes...??? **/

      if (fighter1) {
        fighter1.reset() ;
      }
      if (fighter2) {
        fighter2.reset() ;
      }



      break ;


  }

  goto start ;





}


static int joystick_not_plugged_can_exit(void) {

  const SDL_MessageBoxButtonData buttons[] = {

    { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "OK" },
    { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "EXIT" },

  } ;


  const SDL_MessageBoxData messageboxdata = {
      SDL_MESSAGEBOX_WARNING,       /* .flags */
      NULL,                         /* .window */
      "No paddle nor joystick detected !",        /* .title */
      "Plug a control stick or "
      "any instrument used to control the action on a computer game.\n\n"
      "A joystick is required in order to play this game.\n"
      "\n\nThen press OK (Return) when done.\n\nOr press EXIT (Escape) to exit program.",
      SDL_arraysize(buttons),       /* .numbuttons */
      buttons,                      /* .buttons */
      NULL

  } ;

  int buttonid;

  if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {

    SDL_Log("error displaying message box");
    return -1 ;

  }

  return buttonid ;

}

static std::shared_ptr<Fighters> get_fighter_from_index(const int8_t idx, const bool is_player, const bool computer_vs_computer) {

  /** Function to load a fighter. **/

  // Put something like: [10-14] / 5 / 5 (give one star to all for nothing.) and an half star for looking speed.
  std::vector<int8_t> fighters_speed{ 11,   // Fuuma
                                      10,   // Geese_Howard
                                      12,   // Hanzo
                                      14,   // Hotaru_Futaba
                                      12,   // Iori_Yagami
                                      12,   // K'
                                      13,   // Kim_Kaphwan
                                      14,   // Kisarah_Westfield
                                      13,   // Kyo_Kusanagi
                                      13,   // Lee_Pai_Long
                                      12,   // Mai_Shiranui
                                      10,   // Mr_Big
                                      13,   // Mr_Karate
                                      12,   // Robert_Garcia
                                      14,   // Rock_Howard
                                      12    // Terry_Bogard
                                    } ;


  // between 55.0f and 75.0f. 20 / 10 == 2 the semi-star.             
  std::vector<float> fighters_aggressiveness{ 71.0f,    // Fuuma
                                              65.0f,    // Geese_Howard
                                              69.0f,    // Hanzo
                                              61.0f,    // Hotaru_Futaba
                                              65.0f,    // Iori_Yagami
                                              65.0f,    // K'
                                              65.0f,    // Kim_Kaphwan
                                              61.0f,    // Kisarah_Westfield
                                              65.0f,    // Kyo_Kusanagi
                                              63.0f,    // Lee_Pai_Long
                                              65.0f,    // Mai_Shiranui
                                              69.0f,    // Mr_Big
                                              67.0f,    // Mr_Karate
                                              65.0f,    // Robert_Garcia
                                              63.0f,    // Rock_Howard
                                              65.0f     // Terry_Bogard
                                        } ;


  // 0.80-1.30. (50 / 10 == 5 the semi-star.)
  std::vector<float> fighters_force{  0.95f,    // Fuuma
                                      1.20f,    // Geese_Howard
                                      1.05f,    // Hanzo
                                      1.10f,    // Hotaru_Futaba
                                      0.95f,    // Iori_Yagami
                                      0.95f,    // K'
                                      1.15f,    // Kim_Kaphwan
                                      1.05f,    // Kisarah_Westfield
                                      1.10f,    // Kyo_Kusanagi
                                      1.05f,    // Lee_Pai_Long
                                      1.0f,     // Mai_Shiranui
                                      1.15f,    // Mr_Big
                                      1.15f,    // Mr_Karate
                                      1.0f,     // Robert_Garcia
                                      1.05f,    // Rock_Howard
                                      1.10f     // Terry_Bogard
                                   } ;


  // 0.75-1.25. (50 / 10 == 5 the semi-star.)
  std::vector<float> fighters_resistance{ 1.05f,    // Fuuma
                                          0.90f,    // Geese_Howard
                                          0.95f,    // Hanzo
                                          0.90f,    // Hotaru_Futaba
                                          1.05f,    // Iori_Yagami
                                          1.05f,    // K'
                                          0.95f,    // Kim_Kaphwan
                                          0.85f,    // Kisarah_Westfield
                                          0.95f,    // Kyo_Kusanagi
                                          0.95f,    // Lee_Pai_Long
                                          1.0f,     // Mai_Shiranui
                                          0.90f,    // Mr_Big
                                          0.90f,    // Mr_Karate
                                          0.95f,    // Robert_Garcia
                                          1.0f,     // Rock_Howard
                                          0.95f     // Terry_Bogard
                                        } ;


  constexpr float level_easy={0.725f} ;              
  constexpr float level_hard={1.275f} ;
            
  constexpr float level_easy_aggressiveness={0.90f} ;              
  constexpr float level_hard_aggressiveness={1.10f} ;



  int8_t speed={fighters_speed.at(idx)} ;

  speed *= (not is_player) ? ((game_difficulty == -1) ? level_easy : (game_difficulty == 1) ? level_hard : 1.0f) : 1.0f ;  // Setting difficulty.

  if (game_difficulty == 2) {

    speed={12} ;
  }



  float aggressiveness{fighters_aggressiveness.at(idx)} ;

  aggressiveness *= (not is_player) ? ((game_difficulty == -1) ? level_easy_aggressiveness : (game_difficulty == 1) ? level_hard_aggressiveness : 1.0f) : 1.0f ;  // Setting difficulty.

  if (game_difficulty == 2) {

    aggressiveness={65.0f} ;
  }


  if (computer_vs_computer) {

    aggressiveness += 12.5f ;

  }


  float force{fighters_force.at(idx)} ;

  force *= (not is_player) ? ((game_difficulty == -1) ? level_easy : (game_difficulty == 1) ? level_hard : 1.0f) : 1.0f ;  // Setting difficulty.

  //force += (not is_player) ? 0.025f : 0.0f ; // not player bonus ! Else it's too easy for me.

  if (game_difficulty == 2) {

    force={1.0f} ;
  }



  float resistance{fighters_resistance.at(idx)} ;

  resistance *= (not is_player) ? ((game_difficulty == -1) ? level_easy : (game_difficulty == 1) ? level_hard : 1.0f) : 1.0f ;  // Setting difficulty.

  //resistance += (not is_player) ? 0.025f : 0.0f ;  // not player bonus ! Else it's too easy for me.

  if (game_difficulty == 2) {

    resistance={1.0f} ;
  }

  #ifdef DEBUG
  static uint8_t fighter_nb={1} ;
  std::cout << "Fighter " << std::to_string(fighter_nb) << std::endl ;
  std::cout << "speed: " << std::to_string(speed)  << std::endl ;
  std::cout << "aggressiveness: " << std::to_string(aggressiveness)  << std::endl ;
  std::cout << "force: " << std::to_string(force)  << std::endl ;
  std::cout << "resistance: " << std::to_string(resistance)  << std::endl ;
  ++fighter_nb ;
  if (fighter_nb == 3) {

    fighter_nb={1} ;
  }
  #endif

  switch (idx) {

    case 0 :

      return std::move(load_fighter<Fuuma>("Fuuma", PATH_TO_SPRITES_Fuuma, speed, aggressiveness, force, resistance)) ;

    case 1 :

      return std::move(load_fighter<Geese_Howard>("Geese Howard", PATH_TO_SPRITES_Geese_Howard, speed, aggressiveness, force, resistance)) ;

    case 2 :

      return std::move(load_fighter<Hanzo>("Hanzo", PATH_TO_SPRITES_Hanzo, speed, aggressiveness, force, resistance)) ;

    case 3 :

      return std::move(load_fighter<Hotaru_Futaba>("Hotaru Futaba", PATH_TO_SPRITES_Hotaru_Futaba, speed, aggressiveness, force, resistance)) ;

    case 4 :

      return std::move(load_fighter<Iori_Yagami>("Iori Yagami", PATH_TO_SPRITES_Iori_Yagami, speed, aggressiveness, force, resistance)) ;

    case 5 :

      return std::move(load_fighter<K>("K'", PATH_TO_SPRITES_K, speed, aggressiveness, force, resistance)) ;

    case 6 :

      return std::move(load_fighter<Kim_Kaphwan>("Kim Kaphwan", PATH_TO_SPRITES_Kim_Kaphwan, speed, aggressiveness, force, resistance)) ;

    case 7 :

      return std::move(load_fighter<Kisarah_Westfield>("Kisarah Westfield", PATH_TO_SPRITES_Kisarah_Westfield, speed, aggressiveness, force, resistance) ) ;

    case 8 :

      return std::move(load_fighter<Kyo_Kusanagi>("Kyo Kusanagi", PATH_TO_SPRITES_Kyo_Kusanagi, speed, aggressiveness, force, resistance)) ;

    case 9 :

      return std::move(load_fighter<Lee_Pai_Long>("Lee Pai Long", PATH_TO_SPRITES_Lee_Pai_Long, speed, aggressiveness, force, resistance)) ;

    case 10 :

      return std::move(load_fighter<Mai_Shiranui>("Mai Shiranui", PATH_TO_SPRITES_Mai_Shiranui, speed, aggressiveness, force, resistance)) ;

    case 11 :

      return std::move(load_fighter<Mr_Big>("Mr. Big", PATH_TO_SPRITES_Mr_Big, speed, aggressiveness, force, resistance)) ;

    case 12 :

      return std::move(load_fighter<Mr_Karate>("Mr. Karate", PATH_TO_SPRITES_Mr_Karate, speed, aggressiveness, force, resistance)) ;

    case 13 :

      return std::move(load_fighter<Robert_Garcia>("Robert Garcia", PATH_TO_SPRITES_Robert_Garcia, speed, aggressiveness, force, resistance)) ;

    case 14 :

      return std::move(load_fighter<Rock_Howard>("Rock Howard", PATH_TO_SPRITES_Rock_Howard, speed, aggressiveness, force, resistance)) ;

    case 15 :

      return std::move(load_fighter<Terry_Bogard>("Terry Bogard", PATH_TO_SPRITES_Terry_Bogard, speed, aggressiveness, force, resistance)) ;

    default :

      return nullptr ;

 }

 return nullptr ;

}

static void read_game_configuration_from_file(void) {

  /** Function to read Game configuration file. **/

  read_file :

  try {

    std::ifstream configuration_file(PATH_TO_GAME_CONF_FILE, std::ios::in) ;

    while (not configuration_file.eof()) {

      std::string line ;

      getline(configuration_file, line) ;

      auto pos = line.find("=") ;

      std::string key = line.substr(0, pos) ;

      std::string value = line.substr(pos+1) ;

      #ifdef DEBUG
      if (not key.empty() and not value.empty()) {
        std::cout << key << " = " << value << std::endl ;
      }
      #endif

      if (key == "difficulty") {

        game_difficulty = static_cast<int8_t>(std::stoi(value)) ;
      }
      else if (key == "speed") {

        game_speed = static_cast<int8_t>(std::stoi(value)) ;
      }
      else if (key == "sounds") {

        game_sounds = (std::stoi(value) == 1) ? true : false ;
      }
      else if (key == "music") {

        game_music = (std::stoi(value) == 1) ? true : false ;
      }

    }

  }
  catch (...) {

    write_game_configuration_to_file() ;

    goto read_file ;
  }


}