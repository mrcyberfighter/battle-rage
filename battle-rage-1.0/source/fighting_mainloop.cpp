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

#include "fighting_mainloop.h"

static void inline set_settings_start_end(Fighters* fighter1, Fighters* fighter2) {

  #ifdef DEBUG
  fprintf(stdout,"%s(...) call\n", __func__) ;
  #endif

  // start settings.

  fighter1->set_x_sens(0) ;
  fighter1->set_move_by_kick(false) ;
  fighter1->set_can_move(false) ;
  fighter1->set_blocking_image(false) ;

  fighter2->set_x_sens(0) ;
  fighter2->set_move_by_kick(false) ;
  fighter2->set_can_move(false) ;
  fighter2->set_blocking_image(false) ;

  fighter1->set_kick(0) ;
  fighter2->set_kick(0) ;

  return ;

}

int8_t fighting_mainloop(Fighters* fighter1, Fighters* fighter2, int8_t round) {

  #ifdef DEBUG
  fprintf(stdout,"%s(...) call\n", __func__) ;
  #endif

  bool loop ;

  #define set_loop(x) (loop=(x))

  SDL_JoystickUpdate() ;

  fighter1->init() ;
  fighter2->init() ;

  // Fighter at the left.
  fighter1->set_x(static_cast<int16_t>((WIDTH/2)*0.25f)) ;
  fighter1->set_flip(SDL_FLIP_HORIZONTAL) ;

  // Fighter at the right.
  fighter2->set_x(static_cast<int16_t>((WIDTH/2)*1.25f)) ;
  fighter2->set_flip(SDL_FLIP_NONE) ;


  if (game_music) {

    Mix_PauseMusic() ;

  }

  if (game_sounds) {

    Mix_Volume(-1, MIX_MAX_VOLUME/4) ;
  }

  SDL_FlushEvents(SDL_WINDOWEVENT, SDL_DROPFILE) ;


  // Loading sound effects:
  Mix_Chunk *sound_round_male ;
  sound_round_male=Mix_LoadWAV(PATH_TO_SOUND_VOICES "/round_male.ogg" );

  Mix_Chunk *sound_1_male ;
  sound_1_male = Mix_LoadWAV(PATH_TO_SOUND_VOICES "/1_male.ogg") ;

  Mix_Chunk *sound_2_male ;
  sound_2_male = Mix_LoadWAV(PATH_TO_SOUND_VOICES "/2_male.ogg") ;

  Mix_Chunk *sound_3_male ;
  sound_3_male = Mix_LoadWAV(PATH_TO_SOUND_VOICES "/3_male.ogg") ;

  Mix_Chunk *sound_go_male ;
  sound_go_male = Mix_LoadWAV(PATH_TO_SOUND_VOICES "/go_male.ogg") ;

  Mix_Chunk *sound_win_male ;
  sound_win_male = Mix_LoadWAV(PATH_TO_SOUND_VOICES "/you_win_male.ogg") ;

  Mix_Chunk *sound_lose_male ;
  sound_lose_male = Mix_LoadWAV(PATH_TO_SOUND_VOICES "/you_lose_male.ogg") ;

  Mix_Chunk *sound_final_round_male ;
  sound_final_round_male=Mix_LoadWAV(PATH_TO_SOUND_VOICES "/final_round_male.ogg" );

  Mix_Chunk *sound_final_round_female ;
  sound_final_round_female=Mix_LoadWAV(PATH_TO_SOUND_VOICES "/final_round_female.ogg" );


  Mix_Chunk *sound_round_female ;
  sound_round_female=Mix_LoadWAV(PATH_TO_SOUND_VOICES "/round_male.ogg" );

  Mix_Chunk *sound_1_female ;
  sound_1_female = Mix_LoadWAV(PATH_TO_SOUND_VOICES "/1_male.ogg") ;

  Mix_Chunk *sound_2_female ;
  sound_2_female = Mix_LoadWAV(PATH_TO_SOUND_VOICES "/2_male.ogg") ;

  Mix_Chunk *sound_3_female ;
  sound_3_female = Mix_LoadWAV(PATH_TO_SOUND_VOICES "/3_male.ogg") ;

  Mix_Chunk *sound_go_female ;
  sound_go_female = Mix_LoadWAV(PATH_TO_SOUND_VOICES "/go_male.ogg") ;

  Mix_Chunk *sound_win_female ;
  sound_win_female = Mix_LoadWAV(PATH_TO_SOUND_VOICES "/you_win_male.ogg") ;

  Mix_Chunk *sound_lose_female ;
  sound_lose_female = Mix_LoadWAV(PATH_TO_SOUND_VOICES "/you_lose_male.ogg") ;



  std::vector<Mix_Chunk *> sounds ;

  std::vector<Mix_Chunk *> sounds_2 ;

  if (fighter1->m_is_male) {

    sounds={sound_round_male,
           sound_1_male,
           sound_2_male,
           sound_3_male,
           sound_go_male,
           sound_win_male,
           sound_lose_male,
           sound_final_round_male} ;

    sounds_2={sound_round_female,
              sound_1_female,
              sound_2_female,
              sound_3_female,
              sound_go_female,
              sound_win_female,
              sound_lose_female,
              sound_final_round_female} ;
  }
  else {
    sounds={sound_round_female,
           sound_1_female,
           sound_2_female,
           sound_3_female,
           sound_go_female,
           sound_win_female,
           sound_lose_female,
           sound_final_round_female} ;

    sounds_2={sound_round_male,
              sound_1_male,
              sound_2_male,
              sound_3_male,
              sound_go_male,
              sound_win_male,
              sound_lose_male,
              sound_final_round_male} ;
  }




  #define FONT_SIZE 68

  SDL_Color color_yellow ;
  color_yellow.r = 255 ;
  color_yellow.g = 255 ;
  color_yellow.b = 0   ;
  color_yellow.a = 255 ;

  // Setting up text to display.
  Text *fighting_mainloop_1 = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(fighting_mainloop_1) ;

  fighting_mainloop_1->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE) ;

  TTF_SetFontHinting(fighting_mainloop_1->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, fighting_mainloop_1, "1", color_yellow, WIDTH/2, HEIGHT/2) ;


  Text *fighting_mainloop_2 = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(fighting_mainloop_2) ;

  fighting_mainloop_2->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE) ;

  TTF_SetFontHinting(fighting_mainloop_2->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, fighting_mainloop_2, "2", color_yellow, WIDTH/2, HEIGHT/2) ;


  Text *fighting_mainloop_3 = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(fighting_mainloop_3) ;

  fighting_mainloop_3->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE) ;

  TTF_SetFontHinting(fighting_mainloop_3->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, fighting_mainloop_3, "3", color_yellow, WIDTH/2, HEIGHT/2) ;


  Text *fighting_mainloop_round = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(fighting_mainloop_round) ;

  fighting_mainloop_round->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE) ;

  TTF_SetFontHinting(fighting_mainloop_round->font, TTF_HINTING_LIGHT) ;

  std::string fighting_mainloop_round_text{ ((round < 3) ? "Round " + std::to_string(round) : "Final Round") } ;

  configure_text(pRenderer, fighting_mainloop_round, fighting_mainloop_round_text.c_str(), color_yellow, WIDTH/2, HEIGHT/2) ;


  Text *fighting_mainloop_go = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(fighting_mainloop_go) ;

  fighting_mainloop_go->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE) ;

  TTF_SetFontHinting(fighting_mainloop_go->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, fighting_mainloop_go, "Go", color_yellow, WIDTH/2, HEIGHT/2) ;


  Text *fighting_mainloop_fighter1 = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(fighting_mainloop_fighter1) ;

  fighting_mainloop_fighter1->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE/2*1.5) ;

  TTF_SetFontHinting(fighting_mainloop_fighter1->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, fighting_mainloop_fighter1, "Win", color_yellow, WIDTH/2, HEIGHT/2) ;


  Text *fighting_mainloop_fighter2 = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(fighting_mainloop_fighter2) ;

  fighting_mainloop_fighter2->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", FONT_SIZE/2*1.5) ;

  TTF_SetFontHinting(fighting_mainloop_fighter2->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, fighting_mainloop_fighter2, "Win", color_yellow, WIDTH/2, HEIGHT/2) ;


  int8_t text_sequence{-1} ;

  #ifdef DEBUG
  std::cout << fighter1->get_name() << " goes to fight against " <<  fighter2->get_name() << std::endl ;
  #endif

  // Background bridge size quering.
  SDL_Texture *bg_floor = get_texture_from_image(pRenderer, PATH_TO_BACKGROUND "/floor.png") ;
  int bg_floor_w, bg_floor_h ;
  SDL_QueryTexture(bg_floor, NULL, NULL, &bg_floor_w, &bg_floor_h) ;
  SDL_DestroyTexture(bg_floor) ;


  // Setting up background bridge.
  SDL_Color colorkey ;
  colorkey.r = 255  ;
  colorkey.g = 0    ;
  colorkey.b = 255  ;

  SDL_Texture *bg_bridge  = get_texture_with_colokey_from_image(pRenderer, PATH_TO_BACKGROUND "/floor.png", colorkey) ;


  // For backgrounds.
  std::vector<std::string> bg_vector{   "/CmBkBch.png", "/CmBkCF.png", "/CmBkCur.png", "/CmBkDes.png", "/CmBkDrDd.png",
                                        "/CmBkDrMt.png", "/CmBkDrTr.png", "/CmBkEF.png", "/CmBkFF.png", "/CmBkGrMt.png",
                                        "/CmBkGrTr.png", "/CmBkHG.png", "/CmBkLava.png", "/CmBkLP.png", "/CmBkMag.png",
                                        "/CmBkMC.png",   "/CmBkRgh.png", "/CmBkRK.png", "/CmBkSnMt.png", "/CmBkSnTr.png",
                                        "/CmBkSub.png", "/CmBkSwmp.png" } ;

  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(std::begin(bg_vector), std::end(bg_vector), g) ;


  // SDL_Texture (images) setting up.
  SDL_Texture *far_background = get_texture_from_image(pRenderer, (std::string{PATH_TO_BACKGROUND} + "/battlebg" + bg_vector.at(0)).c_str() ) ;


  SDL_Texture *lifebar_player_1_bg = get_texture_from_image(pRenderer, PATH_TO_LIFEBAR_IMG "/lifebar_back.png"   ) ;
  SDL_Texture *lifebar_player_1_fg = get_texture_from_image(pRenderer, PATH_TO_LIFEBAR_IMG "/lifebar_front.png"  ) ;

  SDL_Texture *lifebar_player_2_bg = get_texture_from_image(pRenderer, PATH_TO_LIFEBAR_IMG "/lifebar_back.png"   ) ;
  SDL_Texture *lifebar_player_2_fg = get_texture_from_image(pRenderer, PATH_TO_LIFEBAR_IMG "/lifebar_front.png"  ) ;

  SDL_Texture *empty_star_texture     = get_texture_from_image(pRenderer, PATH_TO_LIFEBAR_IMG "/non-starred.png") ;
  SDL_Texture *semi_star_texture      = get_texture_from_image(pRenderer, PATH_TO_LIFEBAR_IMG "/semi-starred.png") ;
  SDL_Texture *semi_star_rtl_texture  = get_texture_from_image(pRenderer, PATH_TO_LIFEBAR_IMG "/semi-starred-rtl.png") ;
  SDL_Texture *full_star_texture      = get_texture_from_image(pRenderer, PATH_TO_LIFEBAR_IMG "/starred.png") ;

  #define LIFEBAR_IMG_SIZE 244

  #define OFFSET 24


  // Control variables
  bool is_paused{true} ;
  bool compter_vs_computer_ctrl{true} ;
  bool is_fighting{false} ;
  int8_t fighter_win_round{-2} ;
  uint16_t counter{0} ;
  int8_t fight_end_frame_counter{0} ;
  bool is_end_of_fight{false} ;


  // Framerate control.
  const int FPS = (game_speed == 0) ? 13 : (game_speed == -1) ? 10 : 15 ;
  const int FRAME_DELAY = roundf(1000.0f/static_cast<float>(FPS)) ;

  input_handler->reset() ;

  set_loop(true) ;

  while (loop) {

    int frame_start = SDL_GetTicks() ;

    clear(pRenderer, 0, 0, 0, 0) ;

    display_image(pRenderer, far_background, 0, 0) ;

    display_image(pRenderer, bg_bridge, WIDTH/2, HEIGHT-(bg_floor_h/2), true) ;




    // lifebar fighter 1.
    display_image(pRenderer, lifebar_player_1_bg, WIDTH/16+32, HEIGHT/16) ;
    draw_rect(pRenderer, WIDTH/16+32+16+32, HEIGHT/16+16+16+1, fighter1->m_life_points/100, 16, fighter1->m_lifebar_color, true) ;
    display_image(pRenderer, lifebar_player_1_fg, WIDTH/16+32, HEIGHT/16) ;


    // Lifebar fighter 2.
    display_image_simple_flip(pRenderer, lifebar_player_2_bg, WIDTH/16+WIDTH/2+OFFSET, HEIGHT/16, SDL_FLIP_HORIZONTAL) ;
    int t = 17500/100 - (fighter2->m_life_points/100) ;  // Computing for decrementing rectangle.
    draw_rect(pRenderer, t+(WIDTH/16+16+4)+WIDTH/2+OFFSET, HEIGHT/16+16+16+1, (fighter2->m_life_points/100), 16, fighter2->m_lifebar_color, true) ;
    display_image_simple_flip(pRenderer, lifebar_player_2_fg, WIDTH/16+WIDTH/2+OFFSET, HEIGHT/16, SDL_FLIP_HORIZONTAL) ;


    // Display stars accroding the number of winned rounds:
    switch (round) {

      case 1 :
        // Fighter 1.
        display_image(pRenderer, semi_star_texture, WIDTH/16-48,  HEIGHT/16) ;
        display_image(pRenderer, empty_star_texture, WIDTH/16-10,  HEIGHT/16) ;
        // Fighter 2.
        display_image(pRenderer, semi_star_rtl_texture, WIDTH/16+WIDTH/2+LIFEBAR_IMG_SIZE+48+OFFSET,  HEIGHT/16) ;
        display_image(pRenderer, empty_star_texture, WIDTH/16+WIDTH/2+LIFEBAR_IMG_SIZE+10+OFFSET,  HEIGHT/16) ;
        break ;

      case 2 :
        // Fighter 1.
        display_image(pRenderer, (fighter1->rounds_win == 1) ? full_star_texture : semi_star_texture, WIDTH/16-48,  HEIGHT/16) ;
        display_image(pRenderer, semi_star_texture, WIDTH/16-10,  HEIGHT/16) ;
        // Fighter 2.
        display_image(pRenderer, (fighter2->rounds_win == 1) ? full_star_texture : semi_star_rtl_texture, WIDTH/16+WIDTH/2+LIFEBAR_IMG_SIZE+48+OFFSET,  HEIGHT/16) ;
        display_image(pRenderer, semi_star_rtl_texture, WIDTH/16+WIDTH/2+LIFEBAR_IMG_SIZE+10+OFFSET,  HEIGHT/16) ;
        break ;

      case 3 :
        // Fighter 1.
        display_image(pRenderer, full_star_texture, WIDTH/16-48,  HEIGHT/16) ;
        display_image(pRenderer, semi_star_texture, WIDTH/16-10,  HEIGHT/16) ;
        // Fighter 2.
        display_image(pRenderer, full_star_texture, WIDTH/16+WIDTH/2+LIFEBAR_IMG_SIZE+48+OFFSET,  HEIGHT/16) ;
        display_image(pRenderer, semi_star_rtl_texture, WIDTH/16+WIDTH/2+LIFEBAR_IMG_SIZE+10+OFFSET,  HEIGHT/16) ;
        break ;

    }


    if (not is_paused) {


      if (not is_end_of_fight) {

        if (fighter1->m_is_player) {

          // Getting the axis status.
          fighter1->set_x_sens(input_handler->get_axis_x(0, joy_1_stick_x)) ;
          fighter1->set_y_sens(input_handler->get_axis_y(0, joy_1_stick_y)) ;

          // Getting the buttons status.
          get_buttons(fighter1, 0) ;

          // Harvesting the axis and keys combinations.
          select_key_from_joy_combination_1(fighter1) ;
        }

        if (fighter2->m_is_player) {

          // Getting the axis status.
          fighter2->set_x_sens(-input_handler->get_axis_x(1, joy_2_stick_x)) ;
          fighter2->set_y_sens( input_handler->get_axis_y(1, joy_2_stick_y)) ;

          // Getting the buttons status.
          get_buttons(fighter2, 1) ;

          // Harvesting the axis and keys combinations.
          select_key_from_joy_combination_2(fighter2) ;

        }

        else if (not fighter2->m_is_player and fighter1->m_is_player) {
 
          // Player against computer: the computer must react.
 
          fighter_2_compute_reactions(fighter1->get_kick(), fighter1->get_x(), fighter2) ;

        }
        else if (not fighter2->m_is_player and not fighter1->m_is_player)  {

          // Computer against computer.


          if (compter_vs_computer_ctrl) {

            computer_vs_computer(fighter1->get_kick(), fighter1->get_x(), fighter2) ;

            computer_vs_computer(fighter2->get_kick(), fighter2->get_x(), fighter1) ;

          }
          else {

            computer_vs_computer(fighter2->get_kick(), fighter2->get_x(), fighter1) ;

            computer_vs_computer(fighter1->get_kick(), fighter1->get_x(), fighter2) ;

          }

          compter_vs_computer_ctrl = not compter_vs_computer_ctrl ;

        }

        // Check intersections in every case.
        check_intersections(fighter1, fighter2, fighter_win_round) ;

      }



      if (fighter_win_round != -2) {

        if (not is_end_of_fight) {
          is_end_of_fight=true ;
        }

        if (is_end_of_fight) {
          ++fight_end_frame_counter ;
        }


        // Setting end of fight fighters positions.
        switch (fighter_win_round) {

          case -1 :
            // Fighter 1 win.
            fighter1->set_kick(0)  ;
            fighter2->set_kick(63) ;
            break ;

          case 1 :
            // Fighter 2 win.
            fighter1->set_kick(63)  ;
            fighter2->set_kick(0) ;
            break ;
        }

        set_settings_start_end(fighter1, fighter2) ;

        if (game_sounds) {

          if (fight_end_frame_counter == 1) {

            configure_text(pRenderer, fighting_mainloop_fighter1, std::string{fighter1->get_name() + ((fighter_win_round == -1) ? " Win" : " Lose")}.c_str(), color_yellow, WIDTH/2, HEIGHT/2) ;
            configure_text(pRenderer, fighting_mainloop_fighter2, std::string{fighter2->get_name() + ((fighter_win_round ==  1) ? " Win" : " Lose")}.c_str(), color_yellow, WIDTH/2, HEIGHT/2) ;

          }


          if (fight_end_frame_counter >= 1) {

            switch (fighter_win_round) {

              case -1 :
               render_text(pRenderer, fighting_mainloop_fighter1) ;
               break ;

              case 1 :
                render_text(pRenderer, fighting_mainloop_fighter2) ;
                break ;
             }

          }

          if (fight_end_frame_counter >= 48) {

            Mix_Volume(-1, MIX_MAX_VOLUME/2) ;


             if (fighter1->m_is_player and not fighter2->m_is_player) {

               // Case Player against computer.
               switch (fighter_win_round) {

                case -1 :

                  Mix_PlayChannel(-1, sounds.at(5), 0) ;
                  SDL_Delay(1750) ;
                  ++fighter1->rounds_win ;
                  break ;

                case 1 :

                  Mix_PlayChannel(-1, sounds.at(6), 0) ;
                  SDL_Delay(1750) ;
                  ++fighter2->rounds_win ;
                  break ;

              }
      
        

            }
            else {

        
              switch (fighter_win_round) {

                case -1 :

                  SDL_Delay(1750) ;
                  ++fighter1->rounds_win ;
                  break ;

                case 1 :

                  SDL_Delay(1750) ;
                  ++fighter2->rounds_win ;
                  break ;

              }
      
            }


            set_loop(false) ;

          }

        }

      }


    }



    // Called in every case.
    fighter1->process() ;
    fighter2->process() ;

    if (is_paused) {

      fighter2->is_pausing() ;

      fighter1->is_pausing() ;

    }



    if (not is_fighting) {

      // Start of fight announcement and count down.

      if ( input_handler->is_key_down(SDL_SCANCODE_ESCAPE) ) {

         fighter_win_round={-2} ;

         set_loop(false) ;
      }

      Mix_Volume(-1, MIX_MAX_VOLUME/2) ;

      ++counter ;

      if (  counter == FPS/2-1    or
            counter == FPS-1      or
            counter == FPS*2-1    or
            counter == FPS*2+10-1 or
            counter == FPS*2+20-1 or
            counter == FPS*2+30-1   )
        {

            ++text_sequence ;

        }




      if (fighter1->rounds_win == 1 and fighter2->rounds_win == 1) {

        switch (text_sequence) {

          case 0 :

            render_text(pRenderer, fighting_mainloop_round) ;
            break ;

          case 1 :

            render_text(pRenderer, fighting_mainloop_3) ;
            break ;

          case 2 :

            render_text(pRenderer, fighting_mainloop_2) ;
            break ;

          case 3 :

            render_text(pRenderer, fighting_mainloop_1) ;
            break ;

          case 4 :

            render_text(pRenderer, fighting_mainloop_go) ;
            break ;
        }


        if (counter == FPS/2) {

          if (game_sounds) {
   
            #ifdef DEBUG
            std::cout << "speak round !!!\n" ;
            #endif
   
            Mix_PlayChannel(-1, sounds.at(7), 0) ;
 
          }

          SDL_Delay(1000) ;

        }
        else if (counter == FPS) {

          if (game_sounds) {
    
            #ifdef DEBUG
            std::cout << "speak N° 3 !!!\n" ;
            #endif
   
            Mix_PlayChannel(-1, sounds.at(3), 0)  ;
 
          }

        }
        else if (counter == FPS*2) {

          if (game_sounds) {
   
            #ifdef DEBUG
            std::cout << "speak N° 2 !!!\n" ;
            #endif
   
            Mix_PlayChannel(-1, sounds.at(2), 0)  ;
 
          }

        }
        else if (counter == FPS*2+10) {

          if (game_sounds) {
   
            #ifdef DEBUG
            std::cout << "speak N° 1 !!!\n" ;
            #endif
   
            Mix_PlayChannel(-1, sounds.at(1), 0)  ;
 
          }

        }
        else if (counter == FPS*2+20) {

          if (game_sounds) {
   
            #ifdef DEBUG
            std::cout << "speak GO !!!\n" ;
            #endif
   
            Mix_PlayChannel(-1, sounds.at(4), 0) ;
 
          }

          is_fighting={true} ;
          is_paused={false}  ;

          SDL_Delay(1000) ;
          SDL_FlushEvents(SDL_WINDOWEVENT, SDL_DROPFILE) ;
          input_handler->reset() ;
          set_settings_start_end(fighter1, fighter2) ;

        }

      }
      else {

        // Render text for start announcement and countdown.
        switch (text_sequence) {

          case 0 :

            render_text(pRenderer, fighting_mainloop_round) ;
            break ;

          case 1 :

            render_text(pRenderer, fighting_mainloop_round) ;
            break ;

          case 2 :

            render_text(pRenderer, fighting_mainloop_3) ;
            break ;

          case 3 :

            render_text(pRenderer, fighting_mainloop_2) ;
            break ;

          case 4 :

            render_text(pRenderer, fighting_mainloop_1) ;
            break ;

          case 5 :

            render_text(pRenderer, fighting_mainloop_go) ;
            break ;
        }

        if (counter == FPS/2) {

          if (game_sounds) {
   
            #ifdef DEBUG
            std::cout << "speak round !!!\n" ;
            #endif
    
            Mix_PlayChannel(-1, sounds.at(0), 0) ;

          }

        }
        else if (counter == FPS) {

          if (game_sounds) {
    
            #ifdef DEBUG
            std::cout << "speak N° round !!!\n" ;
            #endif
    
            Mix_PlayChannel(-1, (round == 1) ? sounds.at(1) : (round == 2) ? sounds.at(2) : sounds.at(3), 0)  ;
 
          }

          SDL_Delay(1000) ;

        }
        else if (counter == FPS*2) {

          if (game_sounds) {
   
            #ifdef DEBUG
            std::cout << "speak N° 3 !!!\n" ;
            #endif
   
            Mix_PlayChannel(-1, sounds.at(3), 0)  ;
 
          }

        }
        else if (counter == FPS*2+10) {

          if (game_sounds) {
   
            #ifdef DEBUG
            std::cout << "speak N° 2 !!!\n" ;
            #endif
   
            Mix_PlayChannel(-1, sounds.at(2), 0)  ;
 
          }

        }
        else if (counter == FPS*2+20) {

          if (game_sounds) {
    
            #ifdef DEBUG
            std::cout << "speak N° 1 !!!\n" ;
            #endif
   
            Mix_PlayChannel(-1, sounds.at(1), 0)  ;
 
          }

        }
        else if (counter == FPS*2+30) {

          if (game_sounds) {
    
            #ifdef DEBUG
            std::cout << "speak GO !!!\n" ;
            #endif
   
            Mix_PlayChannel(-1, sounds.at(4), 0) ;
 
          }

          is_fighting={true} ;
          is_paused={false}  ;

          SDL_Delay(1000) ;
          SDL_FlushEvents(SDL_WINDOWEVENT, SDL_DROPFILE) ;
          input_handler->reset() ;
          set_settings_start_end(fighter1, fighter2) ;


        }

      }

    }




    if ( input_handler->is_key_down(SDL_SCANCODE_SPACE) and is_fighting) {

      is_paused = not is_paused ;
   
      if (is_paused) {
   
        fighter2->is_pausing() ;

        fighter1->is_pausing() ;
      }
      else {
     
        SDL_JoystickUpdate() ;
   
      }
   
      SDL_Delay(FPS*10*2) ; 

    }

    if ( input_handler->is_key_down(SDL_SCANCODE_ESCAPE) ) {

      fighter_win_round={-2} ;
 
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

  #ifdef DEBUG
  fprintf(stdout,"fighter1->m_life_points: %d\n", fighter1->m_life_points) ;
  fprintf(stdout,"fighter2->m_life_points: %d\n", fighter2->m_life_points) ;
  #endif


  // Free ressources...
  SDL_DestroyTexture(far_background) ;
  SDL_DestroyTexture(bg_bridge)  ;

  SDL_DestroyTexture(lifebar_player_1_bg) ;
  SDL_DestroyTexture(lifebar_player_1_fg) ;

  SDL_DestroyTexture(lifebar_player_2_bg) ;
  SDL_DestroyTexture(lifebar_player_2_fg) ;

  SDL_DestroyTexture(empty_star_texture) ;
  SDL_DestroyTexture(semi_star_texture) ;
  SDL_DestroyTexture(semi_star_rtl_texture) ;
  SDL_DestroyTexture(full_star_texture) ;

  destroy_text(fighting_mainloop_round) ;
  destroy_text(fighting_mainloop_1) ;
  destroy_text(fighting_mainloop_2) ;
  destroy_text(fighting_mainloop_3) ;
  destroy_text(fighting_mainloop_go) ;
  destroy_text(fighting_mainloop_fighter1) ;
  destroy_text(fighting_mainloop_fighter2) ;

  for (auto &val : sounds) {

    if (val !=  nullptr) {

      Mix_FreeChunk(val);
    }
 
  }

  for (auto &val : sounds_2) {

    if (val !=  nullptr) {

      Mix_FreeChunk(val);
    }

  }

  return fighter_win_round ;

}