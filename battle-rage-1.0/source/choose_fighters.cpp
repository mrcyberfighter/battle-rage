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

#include "choose_fighters.h"

int8_t choose_fighter(const int8_t joy) {

  /** This function permit to choose a fighter:
    *
    * +) For the player .
    *
    * +) As adversary.
    *
    * +) As Computer fighter.
    *
    *******************************************/

  #ifdef DEBUG
  fprintf(stdout,"%s(...) call\n", __func__) ;
  #endif

  SDL_FlushEvents(SDL_WINDOWEVENT, SDL_DROPFILE) ;

  SDL_JoystickUpdate() ;


  bool loop ;

  #define set_loop(x) (loop=(x))

  // Loading SDL_Texture (images):
  SDL_Texture *fuuma_thumb_texture              = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/fuuma_thumb.png") ;
  SDL_Texture *geese_howard_thumb_texture       = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/geese_howard_thumb.png") ;
  SDL_Texture *hanzo_thumb_texture              = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/hanzo_thumb.png") ;
  SDL_Texture *hotaru_fataba_thumb_texture      = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/hotaru_fataba_thumb.png") ;
  SDL_Texture *iori_yagami_thumb_texture        = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/iori_yagami_thumb.png") ;
  SDL_Texture *kim_kaphwan_thumb_texture        = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/kim_kaphwam_thumb.png") ;
  SDL_Texture *kisarah_westfield_thumb_texture  = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/kisara_westfield_thumb.png") ;
  SDL_Texture *k_thumb_texture                  = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/k_thumb.png") ;
  SDL_Texture *kyo_kusanagi_thumb_texture       = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/kyo_kusanagi_thumb.png") ;
  SDL_Texture *lee_pai_long_thumb_texture       = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/lee_pai_long_thumb.png") ;
  SDL_Texture *mai_shiranui_thumb_texture       = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/mai_shiranui_thumb.png") ;
  SDL_Texture *mr_big_thumb_texture             = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/mr_Big_thumb.png") ;
  SDL_Texture *mr_karate_thumb_texture          = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/mr_karate_thumb.png") ;
  SDL_Texture *robert_garcia_thumb_texture      = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/robert_garcia_thumb.png") ;
  SDL_Texture *rock_howard_thumb_texture        = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/rock_howard_thumb.png") ;
  SDL_Texture *terry_bogard_thumb_texture       = get_texture_from_image(pRenderer, PATH_TO_THUMB_IMG "/terry_gogard_thumb.png") ;

  SDL_Texture *starred_texture                  = get_texture_from_image(pRenderer, PATH_TO_ICON "/starred.png") ;
  SDL_Texture *semi_starred_texture             = get_texture_from_image(pRenderer, PATH_TO_ICON "/semi-starred.png") ;
  SDL_Texture *non_starred_texture              = get_texture_from_image(pRenderer, PATH_TO_ICON "/non-starred.png") ;

  std::vector<SDL_Texture*>         thumb_forward_list{ fuuma_thumb_texture,
                                                        geese_howard_thumb_texture,
                                                        hanzo_thumb_texture,
                                                        hotaru_fataba_thumb_texture,
                                                        iori_yagami_thumb_texture,
                                                        k_thumb_texture,
                                                        kim_kaphwan_thumb_texture,
                                                        kisarah_westfield_thumb_texture,
                                                        kyo_kusanagi_thumb_texture,
                                                        lee_pai_long_thumb_texture,
                                                        mai_shiranui_thumb_texture,
                                                        mr_big_thumb_texture,
                                                        mr_karate_thumb_texture,
                                                        robert_garcia_thumb_texture,
                                                        rock_howard_thumb_texture,
                                                        terry_bogard_thumb_texture } ;
   
   
  // Text to display in relation ship to the currently choosen fighter.
  std::vector<const char *> fighters_names{ "Current fighter name: Fuuma",
                                            "Current fighter name: Geese Howard",
                                            "Current fighter name: Hanzo",
                                            "Current fighter name: Hotaru Fataba",
                      
                                            "Current fighter name: Iori Yagami",
                                            "Current fighter name: K",
                                            "Current fighter name: Kim Kaphwan",
                                            "Current fighter name: Kisarah Westfield",
                                
                                            "Current fighter name: Kyo Kusanagi",
                                            "Current fighter name: Lee Pai Long",
                                            "Current fighter name: Mai Shiranui",
                                            "Current fighter name: Mr. Big",
                   
                                            "Current fighter name: Mr. Karate",
                                            "Current fighter name: Robert Garcia",
                                            "Current fighter name: Rock Howard",
                                            "Current fighter name: Terry Bogard" } ;






  // Main control variables for adversary choice.
  bool choose_adversary_switch{false} ;
  bool fighter_selection_auto{false} ;
  bool computer_vs_computer{false} ;

  int8_t cur_joy = joy ;

  if (joy == -1) {

    // Case we choice the adversary.

    choose_adversary_switch={true} ;

    cur_joy = 0 ;

  }

  if (joy == -2) {

    // Case we let the computer fight against the computer.

    computer_vs_computer={true} ;

    cur_joy = 0 ;

  }


  // [Start] Choosing the adversary either randomly or manually control variables. [/Start]

  // Control if 2 random choice doesn't give the same result.
  int8_t precedent_rand_adversary={-1} ;

  // Random choice timer.
  uint16_t counter{0} ;

  // Random device, engine and distribution.
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int8_t> rand_choice_adversary(0, 15) ;

  // [End] Choosing the adversary either randomly or manually control variables. [/END]



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


  Text *choose_fighter_title = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(choose_fighter_title) ;

  choose_fighter_title->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 36) ;

  TTF_SetFontHinting(choose_fighter_title->font, TTF_HINTING_LIGHT) ;

  const char *choose_fighter_text_title ;

  if (not choose_adversary_switch) {
    choose_fighter_text_title={"Choose your figther:"} ;
  }
  else {
    choose_fighter_text_title={"Choose your adversary:"} ;
  }

  if (computer_vs_computer) {
    choose_fighter_text_title={"Choose the figther:"} ;
  }

  configure_text(pRenderer, choose_fighter_title, (char *) choose_fighter_text_title, color_yellow, WIDTH/2, HEIGHT/2-245) ;


  Text *choose_fighter_explanation = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(choose_fighter_explanation) ;

  choose_fighter_explanation->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 20) ;

  TTF_SetFontHinting(choose_fighter_explanation->font, TTF_HINTING_LIGHT) ;

  const char *choose_fighter_explanation_text ;

  if (not choose_adversary_switch or computer_vs_computer) {

    choose_fighter_explanation_text={"Use the arrows to choose your fighter, press any button to confirm.\nOr press the Enter (Return) key for automatic fighter selection."} ;
  }
  else {

    choose_fighter_explanation_text={"Use the arrows to choose your adversary, press any button to confirm.\nOr press the Enter (Return) key for automatic adversary selection."} ;
  }

  configure_text_wrap(pRenderer, choose_fighter_explanation, (char *) choose_fighter_explanation_text, color_yellow, WIDTH/2+50, HEIGHT/2-190, 512*1.5, true) ;


  Text *choose_fighter_names = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(choose_fighter_names) ;

  choose_fighter_names->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 24) ;

  TTF_SetFontHinting(choose_fighter_names->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, choose_fighter_names, (char *) fighters_names.at(0), color_yellow, WIDTH/2, HEIGHT/2+250) ;


  Text *fighters_properties_names = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(fighters_properties_names) ;

  fighters_properties_names->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 20) ;

  TTF_SetFontHinting(fighters_properties_names->font, TTF_HINTING_LIGHT) ;

  std::vector<const char *> fighters_properties_titles_text{"Speed............: ",
                                                            "Aggressiveness...: ",
                                                            "Power............: ",
                                                            "Resistance.......: "
                                                             } ;

  // Fighters properties dislayed as stars:
  // 2: A star ; 1: a semi-star ; 0: nonstar ;                                                              
  // vector<vector>{  {speed},  {aggressivness},  {power},  {resistance}  } ;
  std::vector<std::vector<std::vector<int8_t>>> fighter_properties_values_star_idx{ {{2,2,0,0,0}, {2,2,2,2,0}, {2,2,0,0,0}, {2,2,2,0,0}}, // Fuuma
                                                                                    {{2,0,0,0,0}, {2,2,1,0,0}, {2,2,2,2,0}, {2,1,0,0,0}}, // Geese Howard
                                                                                    {{2,2,1,0,0}, {2,2,2,1,0}, {2,2,2,0,0}, {2,2,0,0,0}}, // Hanzo
                                                                                    {{2,2,2,2,2}, {2,1,0,0,0}, {2,2,2,1,0}, {2,1,0,0,0}}, // Hotaru_Futaba
                                                                                    {{2,2,1,0,0}, {2,2,1,0,0}, {2,2,0,0,0}, {2,2,2,0,0}}, // Iori_Yagami
                                                                                    {{2,2,1,0,0}, {2,2,1,0,0}, {2,2,0,0,0}, {2,2,2,0,0}}, // K'
                                                                                    {{2,2,2,0,0}, {2,1,0,0,0}, {2,2,2,2,0}, {2,2,0,0,0}}, // Kim_Kaphwan
                                                                                    {{2,2,2,2,2}, {2,1,0,0,0}, {2,2,2,0,0}, {2,0,0,0,0}}, // Kisarah_Westfield
                                                                                    {{2,2,2,0,0}, {2,2,1,0,0}, {2,2,2,1,0}, {2,2,0,0,0}}, // Kyo_Kusanagi
                                                                                    {{2,2,2,2,1}, {2,2,0,0,0}, {2,2,0,0,0}, {2,2,0,0,0}}, // Lee_Pai_Long
                                                                                    {{2,2,1,0,0}, {2,2,1,0,0}, {2,2,1,0,0}, {2,2,1,0,0}}, // Mai_Shiranui
                                                                                    {{2,0,0,0,0}, {2,2,2,1,0}, {2,2,2,2,0}, {2,1,0,0,0}}, // Mr_Big
                                                                                    {{2,2,2,0,0}, {2,2,2,0,0}, {2,2,2,2,0}, {2,1,0,0,0}}, // Mr_Karate
                                                                                    {{2,2,1,0,0}, {2,2,1,0,0}, {2,2,1,0,0}, {2,2,0,0,0}}, // Robert_Garcia
                                                                                    {{2,2,2,2,2}, {2,2,0,0,0}, {2,2,2,0,0}, {2,2,1,0,0}}, // Rock_Howard
                                                                                    {{2,2,1,0,0}, {2,2,1,0,0}, {2,2,2,1,0}, {2,2,0,0,0}}  // Terry_Bogard
                                                                                  } ;

  for (auto &val : fighter_properties_values_star_idx) {

    for (auto &vval : val) {

      std::reverse(std::begin(vval), std::end(vval) ) ;
    }

  }
                                             
  std::vector<SDL_Texture*> fighter_properties_values_star_tex{ non_starred_texture,
                                                                semi_starred_texture,
                                                                starred_texture} ;



  // Loading sounds effects:
  Mix_Chunk *change_player_sound_effect ;

  change_player_sound_effect=Mix_LoadWAV(PATH_TO_SOUND_FILES "/Menu"  "/menu_change_choice.ogg");


  Mix_Chunk *ready_male ;

  ready_male = Mix_LoadWAV(PATH_TO_SOUND_FILES "/Voices" "/ready_male.ogg") ;


  Mix_Chunk *ready_female ;

  ready_female = Mix_LoadWAV(PATH_TO_SOUND_FILES "/Voices" "/ready_female.ogg") ;


  Mix_Volume(-1, MIX_MAX_VOLUME/2) ;



  // Control variables to choose fighter.
  int8_t fighter_current_selection{0} ;
  bool button_press{false} ;

  // Framerate control.
  const int FPS{5} ;
  const int FRAME_DELAY = roundf(1000.0f/static_cast<float>(FPS)) ;

  // Loop control.
  set_loop(true) ;

  SDL_FlushEvents(SDL_WINDOWEVENT, SDL_DROPFILE) ;

  input_handler->reset() ;

  while (loop) {

    int frame_start = SDL_GetTicks() ;

    clear(pRenderer, 0, 0, 0, 0) ;

    render_text(pRenderer, choose_fighter_title) ;

    render_text(pRenderer, choose_fighter_explanation) ;


    auto x_axis = input_handler->get_axis_x(cur_joy, (cur_joy == 1) ? joy_2_stick_x : joy_1_stick_x) ;
    auto y_axis = input_handler->get_axis_y(cur_joy, (cur_joy == 1) ? joy_2_stick_y : joy_1_stick_y) ;

    if (x_axis != 0 and y_axis != 0)  {

       goto joystick_get_axis_error_do_nothing ;

    }

    if (x_axis == joy_1_axis_X_forward  and not fighter_selection_auto) {

      if (fighter_current_selection < 15) {
        ++fighter_current_selection ;

        if (game_sounds) {

          Mix_PlayChannel(-1, change_player_sound_effect, 0) ;
        }

      }
      else if (fighter_current_selection >= 15) {

        fighter_current_selection={0} ;

        if (game_sounds) {

          Mix_PlayChannel(-1, change_player_sound_effect, 0) ;
        }
      }

      precedent_rand_adversary = fighter_current_selection ;

      configure_text(pRenderer, choose_fighter_names, (char *) fighters_names.at(fighter_current_selection), color_yellow, WIDTH/2, HEIGHT/2+250) ;





   }
   else if (x_axis == joy_1_axis_X_backward  and not fighter_selection_auto) {



      if (fighter_current_selection > 0) {
        --fighter_current_selection ;

        if (game_sounds) {

          Mix_PlayChannel(-1, change_player_sound_effect, 0) ;
        }
      }
      else if (fighter_current_selection == 0) {

        fighter_current_selection={15} ;

        if (game_sounds) {

          Mix_PlayChannel(-1, change_player_sound_effect, 0) ;
        }
      }

      precedent_rand_adversary = fighter_current_selection ;

      configure_text(pRenderer, choose_fighter_names, (char *) fighters_names.at(fighter_current_selection), color_yellow, WIDTH/2, HEIGHT/2+250) ;

    }
    else if (y_axis == joy_1_axis_Y_upward  and not fighter_selection_auto) {

      if (fighter_current_selection > 7) {

        fighter_current_selection = fighter_current_selection - 8 ;

        if (game_sounds) {

          Mix_PlayChannel(-1, change_player_sound_effect, 0) ;
        }

      }

      precedent_rand_adversary = fighter_current_selection ;

      configure_text(pRenderer, choose_fighter_names, (char *) fighters_names.at(fighter_current_selection), color_yellow, WIDTH/2, HEIGHT/2+250) ;
    }
    else if (y_axis == joy_1_axis_Y_downward and not fighter_selection_auto) {

      if (fighter_current_selection < 8) {

        fighter_current_selection = fighter_current_selection + 8 ;

        if (game_sounds) {

          Mix_PlayChannel(-1, change_player_sound_effect, 0) ;
        }

      }

      precedent_rand_adversary = fighter_current_selection ;

      configure_text(pRenderer, choose_fighter_names, (char *) fighters_names.at(fighter_current_selection), color_yellow, WIDTH/2, HEIGHT/2+250) ;
    }

    joystick_get_axis_error_do_nothing :

    if ( input_handler->is_key_down(SDL_SCANCODE_RETURN)) {

      fighter_selection_auto={true} ;

    }


    if (fighter_selection_auto) {

      // Random adversary choice.

      ++counter ;

      if (counter % 4 == 0) {  // FPS == 5. ; 18 times.

        while ((fighter_current_selection = rand_choice_adversary(gen)) and fighter_current_selection == precedent_rand_adversary) { ; } ;

        precedent_rand_adversary = fighter_current_selection ;

        if (game_sounds) {

          Mix_PlayChannel(-1, change_player_sound_effect, 0) ;
        }

      }


      if (counter == 75) { // FPS == 5. ; 18 choices before fighter is set (and 3 counter units).

        // End of random adversary choice.

        if (fighter_current_selection == 3 or fighter_current_selection == 7 or fighter_current_selection == 10) {

          if (game_sounds) {

            Mix_PlayChannel(-1, ready_female, 0) ;
          }
        }
        else {

          if (game_sounds) {

            Mix_PlayChannel(-1, ready_male, 0) ;
          }

        }

        SDL_Delay(1000) ;

        set_loop(false) ;

      }



    }




    // Draw rectangles all red.
    draw_rect(pRenderer, (0+1)*20+0*75+15, 109-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (1+1)*20+1*75+15, 109-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (2+1)*20+2*75+15, 109-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (3+1)*20+3*75+15, 109-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (4+1)*20+4*75+15, 109-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (5+1)*20+5*75+15, 109-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (6+1)*20+6*75+15, 109-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (7+1)*20+7*75+15, 109-8+20, 80, 80, color_red, true) ;

    draw_rect(pRenderer, (8-7)*20+(8-8)*75+15, 109*2-10-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (9-7)*20+(9-8)*75+15, 109*2-10-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (10-7)*20+(10-8)*75+15, 109*2-10-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (11-7)*20+(11-8)*75+15, 109*2-10-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (12-7)*20+(12-8)*75+15, 109*2-10-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (13-7)*20+(13-8)*75+15, 109*2-10-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (14-7)*20+(14-8)*75+15, 109*2-10-8+20, 80, 80, color_red, true) ;
    draw_rect(pRenderer, (15-7)*20+(15-8)*75+15, 109*2-10-8+20, 80, 80, color_red, true) ;


    // Draw the selected fighter rectangle in yellow.
    switch (fighter_current_selection) {

      case 0 :

        draw_rect(pRenderer, (0+1)*20+0*75+15, 109-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 1 :

        draw_rect(pRenderer, (1+1)*20+1*75+15, 109-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 2 :

        draw_rect(pRenderer, (2+1)*20+2*75+15, 109-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 3 :

        draw_rect(pRenderer, (3+1)*20+3*75+15, 109-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 4 :

        draw_rect(pRenderer, (4+1)*20+4*75+15, 109-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 5 :

        draw_rect(pRenderer, (5+1)*20+5*75+15, 109-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 6 :

        draw_rect(pRenderer, (6+1)*20+6*75+15, 109-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 7 :

        draw_rect(pRenderer, (7+1)*20+7*75+15, 109-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 8 :

        draw_rect(pRenderer, (8-7)*20+(8-8)*75+15, 109*2-10-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 9 :

        draw_rect(pRenderer, (9-7)*20+(9-8)*75+15, 109*2-10-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 10 :

        draw_rect(pRenderer, (10-7)*20+(10-8)*75+15, 109*2-10-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 11 :

        draw_rect(pRenderer, (11-7)*20+(11-8)*75+15, 109*2-10-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 12 :

        draw_rect(pRenderer, (12-7)*20+(12-8)*75+15, 109*2-10-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 13 :

        draw_rect(pRenderer, (13-7)*20+(13-8)*75+15, 109*2-10-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 14 :

        draw_rect(pRenderer, (14-7)*20+(14-8)*75+15, 109*2-10-8+20, 80, 80, color_yellow, true) ;
        break ;

      case 15 :

        draw_rect(pRenderer, (15-7)*20+(15-8)*75+15, 109*2-10-8+20, 80, 80, color_yellow, true) ;
        break ;
    }


    for (int8_t c{0} ; c < 16 ; ++c) {
 
      // Display all fighter thumbs in 2 lines from 8 fighter thumb each.
 
      if (c < 8) {

        display_image(pRenderer, thumb_forward_list[c], (c+1)*20+c*75+15+8, 109+20) ;

      }
      else if (c > 7 and c < 16) {

         display_image(pRenderer, thumb_forward_list[c], (c-7)*20+(c-8)*75+15+8, 109*2-10+20) ;

      }

    }

    for (int8_t c{0} ; c < 4 ; ++c) {
 
      // Display current selected fighter name and properties.
 
      configure_text(pRenderer, fighters_properties_names, (char *)  fighters_properties_titles_text.at(c), color_yellow, WIDTH/2-75, HEIGHT/2+250-50-(c+1)*30, true) ;

      render_text(pRenderer, fighters_properties_names) ;

      for (int8_t cc{0} ; cc < 5 ; cc++) {

        display_image(pRenderer, fighter_properties_values_star_tex.at(fighter_properties_values_star_idx.at(fighter_current_selection).at(c).at(cc)), WIDTH/2-(cc+1)*30+175, HEIGHT/2+250-50-(c+1)*30-20) ;

      }


    }


    render_text(pRenderer, choose_fighter_names) ;

    button_press={false} ;
    button_press = input_handler->get_button_state(cur_joy, (cur_joy == 1) ? joy_2_buttonA : joy_1_buttonA) ;
    if (button_press and not fighter_selection_auto) {

        if (fighter_current_selection == 3 or fighter_current_selection == 7 or fighter_current_selection == 10) {

          if (game_sounds) {

            Mix_PlayChannel(-1, ready_female, 0) ;
          }

        }
        else {

          if (game_sounds) {

            Mix_PlayChannel(-1, ready_male, 0) ;
          }

        }

        SDL_Delay(1000) ;

        set_loop(false) ;

    }

    button_press={false} ;
    button_press = input_handler->get_button_state(cur_joy, (cur_joy == 1) ? joy_2_buttonB : joy_1_buttonB) ;
    if (button_press and not fighter_selection_auto) {

        if (fighter_current_selection == 3 or fighter_current_selection == 7 or fighter_current_selection == 10) {

          if (game_sounds) {

            Mix_PlayChannel(-1, ready_female, 0) ;
          }

        }
        else {

          if (game_sounds) {

            Mix_PlayChannel(-1, ready_male, 0) ;
          }

        }

        set_loop(false) ;

        SDL_Delay(1000) ;

    }

    button_press={false} ;
    button_press = input_handler->get_button_state(cur_joy, (cur_joy == 1) ? joy_2_buttonC : joy_1_buttonC) ;
    if (button_press and not fighter_selection_auto) {

        if (fighter_current_selection == 3 or fighter_current_selection == 7 or fighter_current_selection == 10) {

          if (game_sounds) {

            Mix_PlayChannel(-1, ready_female, 0) ;
          }

        }
        else {

          if (game_sounds) {

            Mix_PlayChannel(-1, ready_male, 0) ;
          }

        }

        set_loop(false) ;

        SDL_Delay(1000) ;

    }

    button_press={false} ;
    button_press = input_handler->get_button_state(cur_joy, (cur_joy == 1) ? joy_2_buttonD : joy_1_buttonD) ;
    if (button_press and not fighter_selection_auto) {

        if (fighter_current_selection == 3 or fighter_current_selection == 7 or fighter_current_selection == 10) {

          if (game_sounds) {

            Mix_PlayChannel(-1, ready_female, 0) ;
          }

        }
        else {

          if (game_sounds) {

            Mix_PlayChannel(-1, ready_male, 0) ;
          }

        }

        set_loop(false) ;

        SDL_Delay(1000) ;

    }

    if ( input_handler->is_key_down(SDL_SCANCODE_ESCAPE)) {

      fighter_current_selection={-1} ;

      set_loop(false) ;

    }

    input_handler->update() ;

    display(pRenderer) ;

    update(pWindow) ;

    int frame_end = SDL_GetTicks() - frame_start ;

    if (frame_end < FRAME_DELAY) {

      SDL_Delay(FRAME_DELAY - frame_end) ;

    }



  }

  // Free all ressources...
  Mix_FreeChunk(change_player_sound_effect);
  Mix_FreeChunk(ready_male);
  Mix_FreeChunk(ready_female);

  for ( auto &val : thumb_forward_list) {
    SDL_DestroyTexture(val) ;
  }

  for ( auto &val : fighter_properties_values_star_tex) {
    SDL_DestroyTexture(val) ;
  }

  SDL_DestroyTexture(starred_texture) ;
  SDL_DestroyTexture(semi_starred_texture) ;
  SDL_DestroyTexture(non_starred_texture) ;

  destroy_text(choose_fighter_title) ;
  destroy_text(choose_fighter_explanation) ;
  destroy_text(choose_fighter_names) ;
  destroy_text(fighters_properties_names) ;

  // Display a black screen for 1.25 seconds.
  clear(pRenderer, 0, 0, 0, 0) ;
  display(pRenderer) ;
  update(pWindow) ;
  SDL_Delay(1250) ;

  input_handler->reset() ;

  return fighter_current_selection ;

}