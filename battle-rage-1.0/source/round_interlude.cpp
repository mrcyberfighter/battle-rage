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

#include "./round_interlude.h"
#include "./round_interlude.h"

int8_t round_interlude(const char *fighter_1_name, const char *fighter_2_name, int8_t round, bool win) {

  /** This function display which is the winner of a round. **/

  int8_t ret{0} ;

  if (game_music) {

    PAUSE_MUSIC

  }

  bool loop ;

  #define set_loop(x) (loop=(x))

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


  Text *round_interlude_text_title = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(round_interlude_text_title) ;

  round_interlude_text_title->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72) ;

  const char *round_interlude_text_title_text{"Battle-Rage"} ;

  TTF_SetFontHinting(round_interlude_text_title->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, round_interlude_text_title, (char *) round_interlude_text_title_text, color_yellow, 210+32+78, 32, false) ;


  Text *round_interlude_round = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(round_interlude_round) ;

  round_interlude_round->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72/2*1.5) ;

  std::string round_interlude_round_text ;

  if (round >= 1 and round <= 3) {

    round_interlude_round_text={"Round:" + std::to_string(round)} ;
  }
  else {

    round_interlude_round_text={"Fight:"} ;

  }

  TTF_SetFontHinting(round_interlude_text_title->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, round_interlude_round, (char *) round_interlude_round_text.c_str(), color_red, 210+32+78, 32+96, false) ;



  #define OFFSET_HEIGHT 32


  Text *round_interlude_fighter_1 = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(round_interlude_fighter_1) ;

  round_interlude_fighter_1->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72/2) ;

  const char *round_interlude_fighter_1_text={ fighter_1_name } ;

  TTF_SetFontHinting(round_interlude_fighter_1->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, round_interlude_fighter_1, (char *) round_interlude_fighter_1_text, color_yellow, 210+32+78, 32+96+72/2+OFFSET_HEIGHT, false) ;


  Text *round_interlude_fighter_1_win = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(round_interlude_fighter_1_win) ;

  round_interlude_fighter_1_win->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72/2) ;

  std::string round_interlude_fighter_1_win_text={ std::string((win) ? "WIN " : "LOSE") + " !" } ;

  TTF_SetFontHinting(round_interlude_fighter_1_win->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, round_interlude_fighter_1_win, (char *) round_interlude_fighter_1_win_text.c_str(), (win) ? color_yellow : color_red, 210+32+78+31*8+100, 32+96+72/2+OFFSET_HEIGHT, false) ;




  Text *round_interlude_versus = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(round_interlude_versus) ;

  round_interlude_versus->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72/3) ;

  TTF_SetFontHinting(round_interlude_versus->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, round_interlude_versus, (char *) "versus", color_red, 210+32+78, 32+96+72/2+72/2+OFFSET_HEIGHT+4, false) ;



  Text *round_interlude_fighter_2 = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(round_interlude_fighter_2) ;

  round_interlude_fighter_2->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72/2) ;

  const char *round_interlude_fighter_2_text={ fighter_2_name } ;

  TTF_SetFontHinting(round_interlude_fighter_2->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, round_interlude_fighter_2, (char *) round_interlude_fighter_2_text, color_yellow, 210+32+78, 32+96+72/2+72/3+72/2+OFFSET_HEIGHT+8, false) ;


  Text *round_interlude_fighter_2_win = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(round_interlude_fighter_2_win) ;

  round_interlude_fighter_2_win->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72/2) ;

  std::string round_interlude_fighter_2_win_text={ std::string((not win) ? "WIN " : "LOSE") + " !" } ;

  TTF_SetFontHinting(round_interlude_fighter_2_win->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, round_interlude_fighter_2_win, (char *) round_interlude_fighter_2_win_text.c_str(), (not win) ? color_yellow : color_red, 210+32+78+31*8+100, 32+96+72/2+72/3+72/2+OFFSET_HEIGHT+8, false) ;

  // Control variables:
  bool blink_switcher{true} ;
  uint16_t counter{0} ;

  bool button{false} ;

  // Framerate control.
  const int FPS = 4 * 2 ;
  const int FRAME_DELAY = roundf(1000.0f/static_cast<float>(FPS)) ;

  input_handler->reset() ;

  set_loop(true) ;

  while (loop) {

    int frame_start = SDL_GetTicks() ;

    clear(pRenderer, 16, 16, 16, 0) ;




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




    render_text(pRenderer, round_interlude_text_title) ;

    render_text(pRenderer, round_interlude_round) ;

    render_text(pRenderer, round_interlude_fighter_1) ;


    if (blink_switcher and win) {
      render_text(pRenderer, round_interlude_fighter_1_win) ;
    }
    else if (not win) {
      render_text(pRenderer, round_interlude_fighter_1_win) ;
    }


    render_text(pRenderer, round_interlude_versus) ;

    render_text(pRenderer, round_interlude_fighter_2) ;


    if (blink_switcher and not win) {
      render_text(pRenderer, round_interlude_fighter_2_win) ;
    }
    else if (win) {
      render_text(pRenderer, round_interlude_fighter_2_win) ;
    }

    if (counter % 2 == 0) {
      blink_switcher = not blink_switcher ;
    }

    if (counter == FPS * 8) { // 8 seconds.

      set_loop(false) ;

    }

    input_handler->update() ;

    ++counter ;

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

    if ( input_handler->is_key_down(SDL_SCANCODE_RETURN) ) {

       set_loop(false) ;
    }

    if ( input_handler->is_key_down(SDL_SCANCODE_ESCAPE) ) {

       ret={-1} ;

       set_loop(false) ;
    }



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


  destroy_text(round_interlude_text_title) ;
  destroy_text(round_interlude_round) ;

  destroy_text(round_interlude_fighter_1) ;
  destroy_text(round_interlude_fighter_1_win) ;

  destroy_text(round_interlude_fighter_2) ;
  destroy_text(round_interlude_fighter_2_win) ;

  SDL_Delay(250) ;

  return ret ;

}

void final_message(const char *fighter_name, const char *adversary, bool win) {

  /** This function display which is the winner of the fight. **/

  if (game_music) {

    PAUSE_MUSIC

  }

  bool loop ;

  #define set_loop(x) (loop=(x))

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

  // SDL_Texture (images):
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
  Text *round_interlude_text_title = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(round_interlude_text_title) ;

  round_interlude_text_title->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72) ;

  const char *round_interlude_text_title_text{"Battle-Rage"} ;

  TTF_SetFontHinting(round_interlude_text_title->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, round_interlude_text_title, (char *) round_interlude_text_title_text, color_yellow, 210+32+78, 32, false) ;


  #define OFFSET 16

  Text *round_interlude_status_msg = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(round_interlude_status_msg) ;

  round_interlude_status_msg->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72/2*1.5) ;

  std::string round_interlude_status_msg_text={"You " + std::string((win) ? "win" : "lose") + " !"} ;

  TTF_SetFontHinting(round_interlude_text_title->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, round_interlude_status_msg, (char *) round_interlude_status_msg_text.c_str(), color_yellow, 210+32+78, 32+96-OFFSET, false) ;


  Text *round_interlude_intro_fighter1 = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(round_interlude_intro_fighter1) ;

  round_interlude_intro_fighter1->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72/3) ;

  const char *round_interlude_intro_fighter1_text={"With fighter:"} ;

  TTF_SetFontHinting(round_interlude_intro_fighter1->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, round_interlude_intro_fighter1, (char *) round_interlude_intro_fighter1_text, color_red, 210+32+78, 32+96+72-OFFSET, false) ;


  Text *round_interlude_fighter = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(round_interlude_fighter) ;

  round_interlude_fighter->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72/2.5) ;

  TTF_SetFontHinting(round_interlude_fighter->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, round_interlude_fighter, (char *) fighter_name, color_yellow, 210+32+78, 32+96+72+72/2-OFFSET-4, false) ;


  Text *round_interlude_intro_fighter2 = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(round_interlude_intro_fighter2) ;

  round_interlude_intro_fighter2->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72/3) ;

  const char *round_interlude_intro_fighter2_text={"Against:"} ;

  TTF_SetFontHinting(round_interlude_intro_fighter2->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, round_interlude_intro_fighter2, (char *) round_interlude_intro_fighter2_text, color_red, 210+32+78, 32+96+72+72/2+36-OFFSET, false) ;


  Text *round_interlude_adversary = static_cast<Text *>(malloc(sizeof(Text))) ;

  init_text(round_interlude_adversary) ;

  round_interlude_adversary->font = TTF_OpenFont(PATH_TO_FONT_TTF "/UbuntuMono-R.ttf", 72/2.5) ;

  TTF_SetFontHinting(round_interlude_adversary->font, TTF_HINTING_LIGHT) ;

  configure_text(pRenderer, round_interlude_adversary, (char *) adversary, color_yellow, 210+32+78, 32+96+72+72/2+72-OFFSET-4, false) ;





  // Control variables:
  bool blink_switcher{true} ;

  bool button{false} ;

  // Framerate control.
  const int FPS = 8 ;
  const int FRAME_DELAY = roundf(1000.0f/static_cast<float>(FPS)) ;

  uint16_t counter{0} ;

  input_handler->reset() ;

  set_loop(true) ;

  while (loop) {

    int frame_start = SDL_GetTicks() ;

    clear(pRenderer, 16, 16, 16, 0) ;




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




    render_text(pRenderer, round_interlude_text_title) ;

    if (blink_switcher) {
      render_text(pRenderer, round_interlude_status_msg) ;
    }

    render_text(pRenderer, round_interlude_intro_fighter1) ;

    render_text(pRenderer, round_interlude_fighter) ;

    render_text(pRenderer, round_interlude_intro_fighter2) ;

    render_text(pRenderer, round_interlude_adversary) ;


    if (counter % 2 == 0) {
      blink_switcher = not blink_switcher ;
    }

    if (counter == FPS * 16) { // 16 seconds.

      set_loop(false) ;

    }

    input_handler->update() ;

    ++counter ;

    if ( input_handler->is_key_down(SDL_SCANCODE_ESCAPE) or input_handler->is_key_down(SDL_SCANCODE_RETURN)) {

       set_loop(false)  ;
       SDL_Delay(150)   ;
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


  destroy_text(round_interlude_text_title) ;
  destroy_text(round_interlude_status_msg) ;
  destroy_text(round_interlude_intro_fighter1) ;
  destroy_text(round_interlude_fighter) ;
  destroy_text(round_interlude_intro_fighter2) ;
  destroy_text(round_interlude_adversary) ;

  SDL_Delay(250) ;

  return ;

}