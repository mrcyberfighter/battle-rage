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

#ifndef __BATTLE_RAGE_FIGHTERS__
#define __BATTLE_RAGE_FIGHTERS__

#include "../headers/includes.h"

#include "../global_vars.h"
#include "../Files/images_utils.h"

#include <unordered_map>
#include <forward_list>
#include <iterator>

class Fighters {

  private :

    std::unordered_map<int8_t, std::shared_ptr<std::forward_list<SDL_Texture*>>> m_kicks_container ;

    std::string m_name ;

    std::string m_folderpath ;

    int16_t m_x ; // The fighter position horizontally.

    SDL_RendererFlip m_flip ;

  private :

    std::shared_ptr<std::forward_list<SDL_Texture*>> m_current_kick{nullptr} ;

    std::forward_list<SDL_Texture*>::iterator m_iter ;

    bool kick_seq_change{false} ;

    int8_t m_key{0} ;

    int8_t m_x_sens{0} ;  // X axis from joystick value.
    int8_t m_y_sens{0} ;  // Y axis from joystick value.

    bool m_can_move{false} ;

    bool m_block_last_image{true} ;

    bool m_move_by_kick{false} ;

    bool m_is_on_knees{false} ;


  public :

    // Fighters properties:

    int8_t m_speed{12} ;  // Put something like: [10-14] / 5 / 5 (give one star to all for nothing.) and an half star for looking speed.

    float m_aggressiveness{65.0f} ;  // between 55.0f and 75.0f. 20 / 10 == 2 the semi-star.

    float m_force_factor{1.0f} ;  // 0.80-1.30. (50 / 10 == 5 the semi-star.) ; //the resistance total must be littler than the attack power.

    float m_resistance_factor{1.0f} ;  // 0.75-1.25. (50 / 10 == 5 the semi-star.) ; //the resistance total must be littler than the attack power.

    const static int8_t m_resistance ;  // static const resistance value common to all, which will be multiply by the resistance_factor.


    std::unordered_map<int8_t, int16_t> m_kicks_power ;  // [10-50]  * m_force_factor{8} ;



    uint8_t rounds_win{0} ;

    bool m_is_player{true} ;

    int m_life_points{17500} ; // Constante value but the power and resistance influence the decremenation  of it.



    bool m_buttonA{false} ;
    bool m_buttonB{false} ;
    bool m_buttonC{false} ;
    bool m_buttonD{false} ;

    bool is_sequence_ended{false} ;

    bool m_is_male{true} ;


    SDL_Color m_lifebar_color ;

    SDL_Rect image_rect ;


  private :

    void update_pos(void) ;

    void display(SDL_Texture *texture) ;

    void get_fighter_image_rect(const int w, const int h) ;

  private :

    std::shared_ptr<std::forward_list<SDL_Texture*>> get_kicks_seq(const int8_t key) { return m_kicks_container.at(key)  ; }


  public :  // Setters and Getters:

    // Setters:

    void set_x(const int16_t x) { m_x = {x} ; }

    int16_t get_x(void) { return m_x ; }

    void set_flip(const SDL_RendererFlip& flipping) { m_flip = {flipping} ; }

    SDL_RendererFlip get_flip(void) { return m_flip ; }

    void set_x_sens(const int8_t sens) { m_x_sens = {sens} ; }
    void set_y_sens(const int8_t sens) { m_y_sens = {sens} ; }

    void change_x_value(const int8_t value) { m_x += value ; }

    int8_t get_x_axis(void) const { return m_x_sens ; }
    int8_t get_y_axis(void) const { return m_y_sens ; }

    void set_can_move(const bool val) { m_can_move = {val} ; }

    void set_blocking_image(const bool val) { m_block_last_image = {val} ; }


    void set_move_by_kick(const bool val) { m_move_by_kick = {val} ; }


    // Getters:

    const int8_t& get_kick(void) const { return m_key ; }

    const std::string get_name(void) const { return m_name ; }

    #ifdef DEBUG
    ssize_t get_container_size(void) const { return m_kicks_container.size() ; }
    #endif

  public :

    void init(void) ;

    void init_kicks_power(void) ;


    void process(void) ;

    void is_pausing(void) ;


    void set_kick(const int8_t key) ;

    void set_kick_with_fallback(const int8_t key, const int8_t fallback) ;


    void add_map_kicks(const std::pair<uint16_t, uint16_t> range, const int8_t &key, const int8_t times=1) ;

    void rehash_kicks_hash_table(const uint8_t count) { m_kicks_container.rehash(count) ; }


    int16_t get_damage_from_kick(const int8_t key) { if (key >= 6 and key <= 23) { return static_cast<int16_t>( roundf(m_kicks_power.at(key) * m_force_factor) ) ; } else { return 0 ; } }


    #ifdef DEBUG
    size_t get_kicks_bucket_count() const { return m_kicks_container.bucket_count() ; }
    float get_kicks_load_factor() const { return m_kicks_container.load_factor() ; }

    void print_infos() const {

      std::cout << m_name << " -> " << "Images container:" << std::endl ;

      std::cout << m_name << " -> " << "for " << m_kicks_container.size() << " elts" << std::endl ;

      std::cout << m_name << " -> " << "bucket_count: " << get_kicks_bucket_count() << std::endl ;

      std::cout << m_name << " -> " << "load factor:  " << get_kicks_load_factor() << std::endl ;

      std::cout << std::endl ;

    }
    #endif

  public :

    Fighters() {} ;

    Fighters(const std::string name, const std::string folderpath, const int8_t speed, const float agressivity, const float force, const float resistance) : m_name{name}, m_folderpath{folderpath}, m_speed{speed}, m_aggressiveness{agressivity}, m_force_factor{force}, m_resistance_factor{resistance}     { ; }

    Fighters(const Fighters& fighter) : m_kicks_container{fighter.m_kicks_container},  m_name{fighter.m_name}, m_folderpath{fighter.m_folderpath}, m_speed{fighter.m_speed}, m_aggressiveness{fighter.m_aggressiveness}, m_force_factor{fighter.m_force_factor}, m_resistance_factor{fighter.m_resistance_factor}  { ; }

    ~Fighters() {

      for (auto &val : m_kicks_container) {

        for (auto &vval : *(val.second)) {
       
          if (vval != nullptr) {
         
            #ifdef DEBUG
            std::cout << "SDL_DestroyTexture(...)" << " called for " << get_name() << " m_kicks_container" << std::endl ;
            #endif
         
            SDL_DestroyTexture(vval) ;
   
            vval = nullptr ;
     
          }
 
        }

        val.second.reset() ;

      }
   
      /** FIXME: It seems to produce an segmentation error sometimes.
      if (*m_iter != nullptr) {
    
        SDL_DestroyTexture(*m_iter) ;

        #ifdef DEBUG
        std::cout << "SDL_DestroyTexture(...)" << " called for " << get_name() << " m_iter" << std::endl ;
        #endif

        *m_iter=nullptr ;

      }
      */
   
      if (m_current_kick) {

        for (auto &val : (*m_current_kick)) {
 
          if (val != nullptr) {
         
            #ifdef DEBUG
            std::cout << "SDL_DestroyTexture(...)" << " called for " << get_name() << " m_current_kick" << std::endl ;
            #endif
         
            SDL_DestroyTexture(val) ;
 
            val = nullptr ;
   
          }
 
        }

        m_current_kick.reset() ;
 
      }

      m_name.clear() ;

      m_folderpath.clear() ;


  }

} ;

#endif