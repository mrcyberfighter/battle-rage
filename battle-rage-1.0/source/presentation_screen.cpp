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

#include "./presentation_screen.h"



void presentation_screen(void) {

  /** This function display the presentation (start) screen. **/


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


  // SDL_Texture (images) resources:
  SDL_Texture *fuuma_texture                = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Fuuma "/Fuuma_272.png") ;
  SDL_Texture *geese_howard_texture         = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Geese_Howard "/Geese Howard_268.png") ;
  SDL_Texture *hanzo_texture                = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Hanzo "/Hanzo_285.png") ;
  SDL_Texture *hotura_futaba_texture        = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Hotaru_Futaba "/Hotaru Futaba_403.png") ;
  SDL_Texture *iori_yagami_texture          = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Iori_Yagami "/Iori Yagami_302.png") ;
  SDL_Texture *k_texture                    = get_texture_from_image(pRenderer, PATH_TO_SPRITES_K "/K'_433.png") ;
  SDL_Texture *kim_kaphwan_texture          = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Kim_Kaphwan "/Kim Kaphwan_322.png") ;
  SDL_Texture *kisarah_westfield_texture    = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Kisarah_Westfield "/Kisarah Westfield_616.png") ;
  SDL_Texture *kyo_kusanagi_texture         = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Kyo_Kusanagi "/Kyo Kusanagi_379.png") ;
  SDL_Texture *lee_pai_long_texture         = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Lee_Pai_Long "/Lee Pai Long_278.png") ;
  SDL_Texture *mai_shiranui_texture         = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Mai_Shiranui "/Mai Shiranui_378.png") ;
  SDL_Texture *mr_big_texture               = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Mr_Big "/Mr. Big_274.png") ;
  SDL_Texture *mr_karate_texture            = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Mr_Karate "/Mr. Karate_319.png") ;
  SDL_Texture *robert_garcia_texture        = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Robert_Garcia "/Robert Garcia_370.png") ;
  SDL_Texture *rock_howard_texture          = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Rock_Howard "/Rock Howard_457.png") ;
  SDL_Texture *terry_bogard_texture         = get_texture_from_image(pRenderer, PATH_TO_SPRITES_Terry_Bogard "/Terry Bogard_264.png") ;



  SDL_Color color_yellow ;
  color_yellow.r = 255 ;
  color_yellow.g = 255 ;
  color_yellow.b = 0   ;
  color_yellow.a = 255 ;

  SDL_Color color_red ;
  color_red.r = 255 ;
  color_red.g = 0   ;
  color_red.b = 0   ;
  color_red.a = 255 ;


  // Text to display:
  Text *presentation_screen_text_title = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(presentation_screen_text_title) ;

  presentation_screen_text_title->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72) ;

  const char *presentation_screen_text_title_text{"Battle-Rage"} ;

  TTF_SetFontHinting(presentation_screen_text_title->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, presentation_screen_text_title, presentation_screen_text_title_text, color_yellow, 210+32+78, 32, false) ;



  Text *presentation_screen_text_slogan = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(presentation_screen_text_slogan) ;

  presentation_screen_text_slogan->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 21) ;

  const char *presentation_screen_text_slogan_text{"With battle-rage,\nthe battle rages on ! And you have fun !!!"} ;

  TTF_SetFontHinting(presentation_screen_text_slogan->font, TTF_HINTING_LIGHT) ;

  configure_text_wrap(pRenderer, presentation_screen_text_slogan, presentation_screen_text_slogan_text, color_yellow, 210+32+78, 32+78+16, 512*1.5) ;


  Text *presentation_screen_text_start_game = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(presentation_screen_text_start_game) ;

  presentation_screen_text_start_game->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 48) ;

  const char *presentation_screen_text_start_game_text{"Press Enter to play !"} ;

  TTF_SetFontHinting(presentation_screen_text_start_game->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, presentation_screen_text_start_game, presentation_screen_text_start_game_text, color_red, 210+32+78, 32+78+16+28+48, false) ;


  if (music == nullptr) {

    if (game_music) {

      music=Mix_LoadMUS(PATH_TO_SOUND_MUSIC "/Hit Them Harder.ogg");

      if (!music) {

        #ifdef DEBUG
        printf("Mix_LoadMUS: %s\n", Mix_GetError());
        // this might be a critical error...
        #endif

        goto music_load_fail ;

      }
    }

  }
  else {

    if (game_music) {

      if (not Mix_PlayingMusic()) {

        PAUSE_MUSIC ;
      }

    }
    else {

      // halt music playback
      Mix_HaltMusic();

      Mix_FreeMusic(music);
      music=NULL; // so we know we freed it...

    }

  }
 

  if (game_music and music != NULL) {

    Mix_VolumeMusic(MIX_MAX_VOLUME/2) ;

    if (Mix_PlayMusic(music, -1) == -1) {

      printf("Mix_PlayMusic: %s\n", Mix_GetError());
      // Well, there's no music, but most games don't break without music...
    }

  }

  music_load_fail :

  int8_t blink_switcher{0} ;

  bool button{false} ;

  const int FPS = 12 ;
  const int FRAME_DELAY = roundf(1000.0f/static_cast<float>(FPS)) ;

  input_handler->reset() ;

  set_loop(true) ;

  while (loop) {

    int frame_start = SDL_GetTicks() ;

    clear(pRenderer, 16, 16, 16, 255) ;


    display_image(pRenderer, bg_bridge, WIDTH/2, HEIGHT-(bg_floor_h/2), true) ;
    display_image(pRenderer, tiger_logo, 32, 32) ;


    display_fighter(pRenderer, iori_yagami_texture,   WIDTH/2+32, SDL_FLIP_HORIZONTAL) ;
    display_fighter(pRenderer, k_texture,             WIDTH/2-40+128*1.5, SDL_FLIP_HORIZONTAL) ;
    display_fighter(pRenderer, fuuma_texture,         WIDTH-32) ;
    display_fighter(pRenderer, geese_howard_texture,  WIDTH-32-128*1.5) ;
    display_fighter(pRenderer, mai_shiranui_texture,  WIDTH-32-128*3.65, SDL_FLIP_HORIZONTAL) ;
    display_fighter(pRenderer, hanzo_texture,         WIDTH-32-128*3) ;
    display_fighter(pRenderer, mr_karate_texture,     128+140, SDL_FLIP_HORIZONTAL) ;
    display_fighter(pRenderer, terry_bogard_texture,  128+120, SDL_FLIP_HORIZONTAL) ;
    display_fighter(pRenderer, robert_garcia_texture, WIDTH-32-128) ;
    display_fighter(pRenderer, kyo_kusanagi_texture,  WIDTH-32-128*0.5) ;
    display_fighter(pRenderer, mr_big_texture,        176+12) ;
    display_fighter(pRenderer, lee_pai_long_texture,  128, SDL_FLIP_HORIZONTAL) ;
    display_fighter(pRenderer, kisarah_westfield_texture, WIDTH-(WIDTH-32-128), SDL_FLIP_HORIZONTAL) ;
    display_fighter(pRenderer, rock_howard_texture,    WIDTH+14) ;
    display_fighter(pRenderer, kim_kaphwan_texture,    WIDTH/2+60, SDL_FLIP_HORIZONTAL) ;
    display_fighter(pRenderer, hotura_futaba_texture, WIDTH/2+160, SDL_FLIP_HORIZONTAL) ;


    render_text(pRenderer, presentation_screen_text_title) ;
    render_text(pRenderer, presentation_screen_text_slogan) ;

    if (blink_switcher >= 0 and blink_switcher < 12) {

      render_text(pRenderer, presentation_screen_text_start_game) ;
    }

    ++blink_switcher ;

    if (blink_switcher == 24) {

      blink_switcher=0 ;
    }

    button={false} ;
    button=input_handler->get_button_state(0, joy_1_buttonA) ;
    if (button) {

      set_loop(false) ;
    }

    button={false} ;
    button=input_handler->get_button_state(0, joy_1_buttonB) ;
    if (button) {

      set_loop(false) ;
    }

    button={false} ;
    button=input_handler->get_button_state(0, joy_1_buttonC) ;
    if (button) {

      set_loop(false) ;
    }

    button={false} ;
    button=input_handler->get_button_state(0, joy_1_buttonD) ;
    if (button) {

      set_loop(false) ;
    }

    if ( input_handler->is_key_down(SDL_SCANCODE_ESCAPE) ) {

       set_loop(false) ;

       exit(EXIT_SUCCESS) ;
    }

    if ( input_handler->is_key_down(SDL_SCANCODE_RETURN) ) {

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


  SDL_DestroyTexture(tiger_logo) ;
  SDL_DestroyTexture(bg_bridge)  ;

  SDL_DestroyTexture(fuuma_texture) ;
  SDL_DestroyTexture(geese_howard_texture) ;
  SDL_DestroyTexture(hanzo_texture) ;
  SDL_DestroyTexture(hotura_futaba_texture) ;
  SDL_DestroyTexture(iori_yagami_texture) ;
  SDL_DestroyTexture(k_texture) ;
  SDL_DestroyTexture(kim_kaphwan_texture) ;
  SDL_DestroyTexture(kisarah_westfield_texture) ;
  SDL_DestroyTexture(kyo_kusanagi_texture) ;
  SDL_DestroyTexture(lee_pai_long_texture) ;
  SDL_DestroyTexture(mai_shiranui_texture) ;
  SDL_DestroyTexture(mr_big_texture) ;
  SDL_DestroyTexture(mr_karate_texture) ;
  SDL_DestroyTexture(robert_garcia_texture) ;
  SDL_DestroyTexture(rock_howard_texture) ;
  SDL_DestroyTexture(terry_bogard_texture) ;


  destroy_text(presentation_screen_text_title) ;
  destroy_text(presentation_screen_text_slogan) ;
  destroy_text(presentation_screen_text_start_game) ;

  if (game_music) {

    Mix_VolumeMusic(MIX_MAX_VOLUME/4) ;

  }

  return ;
}