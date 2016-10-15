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

#include "./Fighters.h"

const int8_t Fighters::m_resistance={50} ;



void Fighters::add_map_kicks(const std::pair<uint16_t, uint16_t> range, const int8_t &key, const int8_t times) {

  std::shared_ptr<std::forward_list<SDL_Texture*>> ret = std::shared_ptr<std::forward_list<SDL_Texture*>>{new std::forward_list<SDL_Texture*> } ;

  for (uint16_t c={range.first} ; c <= range.second ; ++c) {

    char *nb =  static_cast<char *>(malloc(sizeof(char)*4)) ;
   
    memset(nb, '\0', 4) ;
   
    sprintf(nb,"%03d",c) ;

    std::string filepath{m_folderpath + "/" + m_name +  "_" + nb + ".png"} ;
  
    free(nb) ;
  
    SDL_Texture *texture_ptr = get_texture_from_image(pRenderer, filepath.c_str()) ;

    ret->push_front(texture_ptr) ;

    if (times > 1 and c == range.second) {

      // Multiple end of sequence image repeating.

      for (int8_t c=0 ; c <= times-1 ; ++c) {

        ret->push_front(texture_ptr) ;

      }
    }


  }



  ret->reverse() ;

  m_kicks_container[key]=std::move(ret) ;

  ret.reset() ;

  return ;

}



void Fighters::init_kicks_power(void) {

  // The keys values are effectly starting from 0 but before 6 their aren't kicks.

  constexpr int8_t power_factor = 7 ;

  m_kicks_power[6]    = 10 * power_factor ;  // Button 'A' without axis.                     -> Simple front arm fist kick.

  m_kicks_power[7]    = 20 * power_factor ;  // Button 'A' with forward (x_axis == 1).       -> Front arm fist kick to body.


  m_kicks_power[8]    = 15 * power_factor ;  // Button 'D' without axis.                     -> Back arm fist kick to body.

  m_kicks_power[9]    = 25 * power_factor ;  // Button 'D' with forward (x_axis == 1)        -> Back arm fist kick to body.


  m_kicks_power[10]   = 40 * power_factor ;  // Button 'D' with upward (y_axis == -1)        -> Front hand uppercut.

  m_kicks_power[11]   = 35 * power_factor ;  // Button 'A' with upward (y_axis == -1)        -> Back hand uppercut.


  m_kicks_power[12]   = 40 * power_factor ;  // Button 'D' with downward (y_axis == 1)       -> Front arm fist kick to knees.

  m_kicks_power[13]   = 35 * power_factor ;  // Button 'A' with downward (y_axis == 1)       -> Back arm fist kick to knees.


  m_kicks_power[14]   = 35 * power_factor ;  // Button 'B' without axis.                     -> Normal foot kick to head.

  m_kicks_power[15]   = 45 * power_factor ;  // Button 'B' with upward (y_axis == 1).        -> Front foot kick to head.

  m_kicks_power[16]   = 40 * power_factor ;  // Button 'B' with forward (x_axis == 1).       -> Frontal front leg kick (to body).

  m_kicks_power[17]   = 45 * power_factor ;  // Button 'B' without downward (y_axis == -1).  -> Brush with front leg.

  m_kicks_power[18]   = 50 * power_factor ;  // Button 'B' without backward (x_axis == -1).  -> Return front leg kick to head.


  m_kicks_power[19]   = 30 * power_factor ;  // Button 'C' without axis.                     -> Normal foot kick to body.

  m_kicks_power[20]   = 40 * power_factor ;  // Button 'C' with upward (y_axis == 1).        -> Front foot kick to head.

  m_kicks_power[21]   = 35 * power_factor ;  // Button 'C' with forward (x_axis == 1).       -> Frontal front leg kick (to body).

  m_kicks_power[22]   = 40 * power_factor ;  // Button 'C' without downward (y_axis == -1).  -> Brush with front leg.

  m_kicks_power[23]   = 45 * power_factor ;  // Button 'C' without backward (x_axis == -1).  -> Return back leg kick to body.



  m_kicks_power.rehash(18) ;

  #ifdef DEBUG
  std::cout << "m_kicks_power" << "After reshasing: " << std::endl ;

  std::cout << "m_kicks_power" << " -> " << "for " << m_kicks_power.size() << " elts" << std::endl ;

  std::cout << "m_kicks_power" << " -> " << "bucket_count: " << m_kicks_power.bucket_count() << std::endl ;

  std::cout << "m_kicks_power" << " -> " << "load factor:  " << m_kicks_power.load_factor() << std::endl ;
  #endif




}


inline void Fighters::get_fighter_image_rect(const int w, const int h) {

  if (m_flip == SDL_FLIP_HORIZONTAL) {
    // Ajust the Bounding rectangle for given the illusion for the fighters position. ! @NOT the image position.
    image_rect.x = {m_x-(w/5)}  ;
  }
  else if (m_flip == SDL_FLIP_NONE) {
    // Ajust the Bounding rectangle for given the illusion for the fighters position. ! @NOT the image position.
    image_rect.x = {m_x+(w/5)}  ;
  }

  image_rect.y = {HEIGHT-h}  ;

  image_rect.w = {w}    ;
  image_rect.h = {h}    ;


  return ;

}


void Fighters::display(SDL_Texture *texture) {

  #ifdef DEBUG
  fprintf(stdout,"%s(...)\n", __func__) ;
  #endif

  if (texture == NULL) {

    return ;

  }

  int w, h ;

  SDL_QueryTexture(texture, NULL, NULL, &w, &h) ;

  get_fighter_image_rect(w, h) ;

  display_image_simple_flip(pRenderer, texture, m_x, (HEIGHT-h), m_flip) ;

  return ;

}


inline void Fighters::update_pos(void) {

  #ifdef DEBUG
  fprintf(stdout,"%s(...)\n", __func__) ;
  #endif


  if (m_can_move) {

    if (m_x_sens != 0 and m_y_sens != 1) {

      switch (m_x_sens) {

        case -1 :

          #ifdef DEBUG
          std::cout << "m_x -= " << std::to_string(m_speed) << m_x << std::endl ;
          #endif


          if (m_flip == SDL_FLIP_HORIZONTAL) {

            m_x -= m_speed ;
          }
          else if (m_flip == SDL_FLIP_NONE) {

            m_x += m_speed ;
          }

          break ;

        case 1 :

          #ifdef DEBUG
          std::cout << "m_x += " << std::to_string(m_speed) << "  " << m_x << std::endl ;
          #endif


          if (m_flip == SDL_FLIP_HORIZONTAL) {

            m_x += m_speed ;
          }
          else if (m_flip == SDL_FLIP_NONE) {

            m_x -= m_speed ;
          }

          break ;

      }

    }

  }

  if (m_move_by_kick) {

    if (m_flip == SDL_FLIP_HORIZONTAL) {

      m_x += static_cast<int8_t>(roundf(static_cast<float>(m_speed) / 3.75f)) ;
    }
    else if (m_flip == SDL_FLIP_NONE) {

      m_x -= static_cast<int8_t>(roundf(static_cast<float>(m_speed) / 3.75f)) ;
    }

  }

  return ;

}

void Fighters::process(void) {

  #ifdef DEBUG
  fprintf(stdout,"%s(...)\n", __func__) ;
  #endif


  if ( m_iter !=  std::end(*m_current_kick) ) {



    // Make the fighter move or not according settings.
    update_pos() ;

    display(*m_iter) ;

    if (m_block_last_image and std::distance(m_iter, std::end(*m_current_kick)) == 1) {

      // Case fighter is protected: we display only the last image after having displaying the entire sequence.

      display(*m_iter) ;

      return ;

    }

    ++m_iter ;

    is_sequence_ended={false} ;

  }
  else {

    is_sequence_ended={true} ;

    m_current_kick.reset() ;

    if (not kick_seq_change) {

       // Reset to fighter guard images sequence.

      if (m_key != 63) {

        m_key = {0} ;
      }

    }


    try {

      m_current_kick = get_kicks_seq(m_key) ;

    }
    catch (...) {

      m_key = {0} ;

      m_current_kick = get_kicks_seq(m_key) ;

    }

    m_iter = std::begin(*m_current_kick) ;




    // Make the fighter move or not according settings.
    update_pos() ;

    display(*m_iter) ;

    ++m_iter ;

  }



  return  ;


}

void Fighters::init(void) {

  #ifdef DEBUG
  fprintf(stdout,"%s(...)\n", __func__) ;
  #endif

  m_key = {0} ;

  if (m_current_kick) {

    m_current_kick.reset() ;

  }

  try {

    m_current_kick = get_kicks_seq(m_key) ;

  }
  catch (...) {

    m_key = {0} ;

    m_current_kick = get_kicks_seq(m_key) ;

  }

  m_iter = std::begin(*m_current_kick) ;

  kick_seq_change={false} ;

  set_can_move(false) ;

  set_blocking_image(false) ;

  set_move_by_kick(false) ;

  m_life_points={17500} ;

  set_kick(0) ;

  display(*m_iter) ;

}

void Fighters::is_pausing(void) {

  set_blocking_image(true) ;

  set_can_move(false) ;

  set_move_by_kick(false) ;



  if (m_current_kick == nullptr) {

    try {

      m_current_kick = get_kicks_seq(m_key) ;
    }
    catch (...) {

      m_key = {0} ;

      m_current_kick = get_kicks_seq(m_key) ;

    }

    m_iter = std::begin(*m_current_kick) ;

  }
  else if (m_iter == std::end(*m_current_kick)) {

    try {

      m_current_kick = get_kicks_seq(m_key) ;
    }
    catch (...) {

      m_key = {0} ;

      m_current_kick = get_kicks_seq(m_key) ;

    }

    m_iter = std::begin(*m_current_kick) ;

  }


  display(*m_iter) ;

  return ;

}

void Fighters::set_kick(const int8_t key) {

  #ifdef DEBUG
  fprintf(stdout,"%s(...)\n", __func__) ;
  #endif

  if (m_key != 0 and m_key != 1 and m_key != 2) {  // TODO: I don't know actually if (m_key != 1 and m_key != 2) is a good idea ?

    // Sequence isn't interruptible. So we must wait the sequence to end !

    kick_seq_change=false ;

    return ;

  }

  m_key = key ;

  #ifdef DEBUG
  std::cout << "set kick " << std::to_string(m_key) << std::endl ;
  #endif

  if (m_key >= 31 and m_key <= 53) {

    kick_seq_change={false} ;
  }
  else {

    kick_seq_change={true} ;
  }

  m_current_kick.reset() ;

  try {

    m_current_kick = get_kicks_seq(m_key) ;
  }
  catch (...) {

    m_key = {0} ;

    m_current_kick = get_kicks_seq(m_key) ;

  }

  m_iter = std::begin(*m_current_kick) ;

  return ;

}


void Fighters::set_kick_with_fallback(const int8_t key, const int8_t fallback) {

  #ifdef DEBUG
  fprintf(stdout,"%s(...)\n", __func__) ;
  #endif

  /** This function takes care of keys which doesn't exist for any reason. And provide a fallback key for this case. **/

  if (m_key != 0 and m_key != 1 and m_key != 2) { // TODO: I don't know actually if (m_key != 1 and m_key != 2) is a good idea ?

    // Sequence isn't interruptible. So we must wait the sequence to end !

    kick_seq_change = {false} ;

    return ;

  }

  m_key = key ;

  kick_seq_change = {true} ;

  try {

    m_current_kick.reset() ;

    m_current_kick = get_kicks_seq(m_key) ;

    #ifdef DEBUG
    std::cout << "set kick " << std::to_string(m_key) << std::endl ;
    #endif

  }
  catch (std::out_of_range &e) {

    m_current_kick.reset() ;

    m_key = {fallback} ;


    try {

      m_current_kick = get_kicks_seq(m_key) ;
    }
    catch (...) {

      m_key = {0} ;

      m_current_kick = get_kicks_seq(m_key) ;

    }



    #ifdef DEBUG
    std::cout << "Set kick error: " << key << "\nSo setting on fallback: " << std::to_string(fallback) << std::endl ;
    #endif

  }



  m_iter = std::begin(*m_current_kick) ;

  return ;

}