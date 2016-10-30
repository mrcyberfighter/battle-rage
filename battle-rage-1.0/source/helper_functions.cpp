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

#include "./helper_functions.h"

// Local random settings fight sounds:
static std::random_device random_engine ;
static std::mt19937 generator(random_engine()) ;
static std::uniform_int_distribution<int8_t> fighter_kick(1, 5) ;

static inline void fighter_hit_by(const int8_t key, Fighters* fighter) {

  /** This function set a hit image sequence according to a key. **/

  #ifdef DEBUG
  std::cout << __func__ <<  " " << fighter->get_name() << " -> " << std::to_string(key) << std::endl ;
  #endif

  // Only if the key is an attack.

  if (game_sounds) {

    Mix_PlayChannel(-1, hit_sound_container.at(fighter_kick(generator)), 0) ;
  }

  switch (key) {

    case 6 :

      fighter->set_kick(32) ;
      break ;

    case 7 :

      fighter->set_kick(32) ;
      break ;

    case 8 :

      fighter->set_kick(32) ;
      break ;

    case 9 :

      fighter->set_kick(32) ;
      break ;

    case 10 :

      fighter->set_kick(31) ;
      break ;


    case 11 :

      fighter->set_kick(31) ;
      break ;

    case 12 :

      fighter->set_kick(31) ;
      break ;

    case 13 :

      fighter->set_kick(33) ;
      break ;

    case 14 :

      fighter->set_kick(31) ;
      break ;

    case 15 :

      fighter->set_kick(31) ;
      break ;

    case 16 :

      fighter->set_kick(32) ;
      break ;

    case 17 :

      fighter->set_kick(42) ;  // FIXME: Reset on value 33 if this make too much mess.
      break ;

    case 18 :

      fighter->set_kick(43) ;  // FIXME: Reset on value 32 if this make too much mess.
      break ;

    case 19 :

      fighter->set_kick(32) ;
      break ;

    case 20 :

      fighter->set_kick(31) ;
      break ;

    case 21 :

      fighter->set_kick(32) ;
      break ;

    case 22 :

      fighter->set_kick(41) ;  // FIXME: Reset on value 33 if this make too much mess.
      break ;

    case 23 :

      fighter->set_kick(43) ;  // FIXME: Reset on value 32 if this make too much mess.
      break ;

    default :

      break ;

  }



  return ;

}

void check_intersections(Fighters* fighter1, Fighters* fighter2, int8_t& fighter_win_round) {

  /** This function check if the 2 fighters rectangles (which are adjust to be realist) intersect.
    * And take some dispositions according the player fighter kick in response to his kick.
    *
    *********************************************************************************************/

  /**
    * FIXME: Their is a problem with fighter1: it blink to being at x <= 0.
    *
   **/

  auto distance = fighter2->get_x() - fighter1->get_x() ;

  while (distance < 0) {

    // In case the fighter 1 (fighter left) is back to the fighter 2 (fighter right).

    fighter1->change_x_value(-(75)) ;

    fighter2->change_x_value(75) ;

    return ;

  }


  SDL_Rect result ;

  auto fighter1_action = fighter1->get_kick() ;
  auto fighter2_action = fighter2->get_kick() ;

  std::random_device rd;
  std::mt19937 gen(rd());

  // Moving forward ((1.0-val)*1000) percent probability to return @true.
  std::bernoulli_distribution aggressiveness((100.0f - fighter2->m_aggressiveness) / 100.0f);



  std::uniform_int_distribution<int8_t> kick_sound(1, 15) ;

  fighter1->image_rect.x += 5 ;
  fighter2->image_rect.x -= 5 ;

  if (SDL_IntersectRect(dynamic_cast<const SDL_Rect*>(&fighter1->image_rect), dynamic_cast<const SDL_Rect*>(&fighter2->image_rect), &result)) {


    if (fighter1->get_x() <= 0) {

      // Case fighter 1 (fighter left is at the left border.

      // FIXME: The fighter disapppear upto < 0 ;

      if ( (fighter2_action >= 6 and fighter2_action < 31) and fighter1_action < 6 )  {


        // Case fighter 2 kick on fighter 1 and fighter 1 is doing something else than attack (passiv or defense).

        if ( fighter1_action != 4 and fighter1_action != 5 ) {
   
          // Case fighter 1 isn't protected: the fighter 2 kick the ass of fighter 1.
   
          if (game_sounds) {
            Mix_PlayChannel(-1, kick_sound_container.at(kick_sound(generator)), 0) ;
          }

          fighter_hit_by(fighter2_action, fighter1) ;


          fighter1->m_life_points -= (fighter2->get_damage_from_kick(fighter2_action)+result.w) - (fighter1->m_resistance * fighter1->m_resistance_factor) ;

          if (fighter1->m_life_points <= 0) {
      
            #ifdef DEBUG
            std::cout <<  fighter2->get_name() <<  " Win !!!\n" << std::endl ;
            #endif
       
            fighter_win_round = 1 ; // Reverse of the player number which have no more life points.

            return  ;

          }

        }


        fighter1->set_x(0) ;

        fighter2->change_x_value(-result.w/2) ;

        return ;



      }
      else if ((fighter1_action >= 6 and fighter1_action < 31) and fighter2_action < 6 )  {

        // Case fighter 1 attack and fighter 2 is doing something else (passiv or defense).

        if ( fighter2_action != 4 and fighter2_action != 5 ) {
  
          // Case fighter 2 isn't protected: the fighter 1 kick the ass of fighter 2.
  
          if (game_sounds) {
            Mix_PlayChannel(-1, kick_sound_container.at(kick_sound(generator)), 0) ;
          }

          fighter_hit_by(fighter1_action, fighter2) ;

          fighter2->m_life_points -= (fighter1->get_damage_from_kick(fighter1_action)+result.w) - fighter2->m_resistance * fighter2->m_resistance_factor  ;

          if (fighter2->m_life_points <= 0) {
       
            #ifdef DEBUG
            std::cout <<  fighter1->get_name() <<  " Win !!!\n" << std::endl ;
            #endif
      
            fighter_win_round = -1 ; // Reverse of the player number which have no more life points.

            return  ;

          }


        }

        fighter1->set_x(0) ;

        fighter2->change_x_value(-result.w/4) ;

        return ;


      }

      return ;
    }

    if (fighter2->get_x() >= static_cast<int16_t>(WIDTH-(fighter2->image_rect.w)) ) {

      // Case fighter 2 is at the right border.




      if ( (fighter2_action >= 6 and fighter2_action < 31) and fighter1_action < 6 ) {

        // Case fighter 2 kick on fighter 1 and fighter 1 is doing something else than attack (passiv or defense).

        if ( fighter1_action != 4 and fighter1_action != 5  ) {
  
          // Case fighter 1 isn't protected: the fighter 2 kick the ass of fighter 1.
  
          if (game_sounds) {
            Mix_PlayChannel(-1, kick_sound_container.at(kick_sound(generator)), 0) ;
          }

          fighter_hit_by(fighter2_action, fighter1) ;


          fighter1->m_life_points -= (fighter2->get_damage_from_kick(fighter2_action)+result.w) - (fighter1->m_resistance * fighter1->m_resistance_factor) ;

          if (fighter1->m_life_points <= 0) {
      
            #ifdef DEBUG
            std::cout <<  fighter2->get_name() <<  " Win !!!\n" << std::endl ;
            #endif
       
            fighter_win_round = 1 ; // Reverse of the player number which have no more life points.

            return  ;

          }

        }

        return ;


      }
      else if ( (fighter1_action >= 6 and fighter1_action < 31) and fighter2_action < 6 )  {

        // Fighter 1 attack and fighter 2 is doing something else (passiv or defense).

        if ( fighter2_action != 4 and fighter2_action != 5) {
  
          // Case fighter 2 isn't protected: the fighter 1 kick the ass of fighter 2.

          if (game_sounds) {

            Mix_PlayChannel(-1, kick_sound_container.at(kick_sound(generator)), 0) ;
          }

          fighter_hit_by(fighter1_action, fighter2) ;

          fighter2->m_life_points -= (fighter1->get_damage_from_kick(fighter1_action)+result.w) - fighter2->m_resistance * fighter2->m_resistance_factor  ;

          if (fighter2->m_life_points <= 0) {
       
            #ifdef DEBUG
            std::cout <<  fighter1->get_name() <<  " Win !!!\n" << std::endl ;
            #endif
      
            fighter_win_round = -1 ; // Reverse of the player number which have no more life points.

            return  ;

          }


        }





      }

      fighter2->set_x(static_cast<int16_t>( WIDTH-(fighter2->image_rect.w) ) ) ;

      return ;

    }

    if ( ( fighter1_action >= 6 and fighter1_action <= 31)  and (fighter2_action >= 6 and fighter2_action < 31) ) {

      // The 2 fighters are kicking at the same time.

      if (game_sounds) {

        Mix_PlayChannel(-1, kick_sound_container.at(kick_sound(generator)), 0) ;

        Mix_PlayChannel(-1, kick_sound_container.at(kick_sound(generator)), 0) ;
      }
     
         
      fighter1->m_life_points -= (fighter2->get_damage_from_kick(fighter2_action)+result.w) / 2 - (fighter1->m_resistance * fighter1->m_resistance_factor) ;

      fighter2->m_life_points -= (fighter1->get_damage_from_kick(fighter1_action)+result.w) / 2 - (fighter2->m_resistance * fighter2->m_resistance_factor) ;
     
      /** Or like this: this will advantage the player if they are minus damage by twice fighters kicking.
     
      fighter1->m_life_points -= ((fighter2->get_damage_from_kick(fighter2_action)+result.w) / 2 - (fighter1->m_resistance * fighter1->m_resistance_factor)) / 2 ;

      fighter2->m_life_points -= ((fighter1->get_damage_from_kick(fighter1_action)+result.w) / 2 - (fighter2->m_resistance * fighter2->m_resistance_factor)) / 2 ;

      **/
      

      if (fighter2->m_life_points > 0 and fighter1->m_life_points <= 0) {
   
        #ifdef DEBUG
        std::cout <<  fighter2->get_name() <<  " Win !!!\n" << std::endl ;
        #endif
   
        fighter_win_round = 1 ; // Reverse of the player number which have no more life points.

        return  ;

      }

      if (fighter1->m_life_points > 0 and fighter2->m_life_points <= 0) {
  
        #ifdef DEBUG
        std::cout <<  fighter1->get_name() <<  " Win !!!\n" << std::endl ;
        #endif
  
        fighter_win_round = -1 ; // Reverse of the player number which have no more life points.

        return  ;

      }
      else if (fighter1->m_life_points <= 0 and fighter2->m_life_points <= 0) {

        std::bernoulli_distribution fifty_fifty(0.5) ;

        (fifty_fifty(gen)) ? fighter_win_round = -1 : fighter_win_round = 1 ;
  
        #ifdef DEBUG
        std::cout << ((fighter_win_round == -1) ? fighter2->get_name() : fighter1->get_name()) << " Win !!!\n" << std::endl ;
        #endif
  
        return ;

      }





      fighter1->change_x_value(-(result.w/2)) ;

      fighter2->change_x_value(result.w/2) ;

      return ;
    }
    else if ( (fighter1_action >= 6 and fighter1_action < 31) and fighter2_action < 6)  {

      // Fighter 1 attack and fighter 2 is doing something else (passiv or defense).

      if ( fighter2_action != 4 and fighter2_action != 5 ) {
 
        // Case fighter 2 isn't protected: the fighter 1 kick the ass of fighter 2.
 
        if (game_sounds) {

          Mix_PlayChannel(-1, kick_sound_container.at(kick_sound(generator)), 0) ;
        }

        fighter2->change_x_value(result.w) ;

        fighter_hit_by(fighter1_action, fighter2) ;

        fighter2->m_life_points -= (fighter1->get_damage_from_kick(fighter1_action)+result.w) - (fighter2->m_resistance * fighter2->m_resistance_factor) ;

        if (fighter2->m_life_points <= 0) {
    
          #ifdef DEBUG
          std::cout <<  fighter1->get_name() <<  " Win !!!\n" << std::endl ;
          #endif
    
          fighter_win_round = -1 ; // Reverse of the player number which have no more life points.

          return  ;

        }

        return ;

      }

      fighter1->change_x_value(-(result.w/4)) ;

      fighter2->change_x_value(result.w/4) ;


      return ;
    }
    else if ( (fighter2_action >= 6 and fighter2_action < 31) and fighter1_action < 6 ) {

      // Case fighter 2 kick on fighter 1 and fighter 1 is doing something else than attack (passiv or defense).



      if ( fighter1_action != 4 and fighter1_action != 5) {

        // Case fighter 1 isn't protected: the fighter 2 kick the ass of fighter 1.

        Mix_PlayChannel(-1, kick_sound_container.at(kick_sound(generator)), 0) ;

        fighter_hit_by(fighter2_action, fighter1) ;

        fighter1->change_x_value(-result.w) ;

        fighter1->m_life_points -= (fighter2->get_damage_from_kick(fighter2_action)+result.w) - (fighter1->m_resistance * fighter1->m_resistance_factor) ;

        if (fighter1->m_life_points <= 0) {
    
          #ifdef DEBUG
          std::cout <<  fighter2->get_name() <<  " Win !!!\n" << std::endl ;
          #endif
     
          fighter_win_round = 1 ; // Reverse of the player number which have no more life points.

          return  ;

        }

        return ;

      }

      fighter1->change_x_value(-(result.w/4)) ;

      fighter2->change_x_value(result.w/4) ;


      return ;
    }

    else if (fighter1_action == 1 and fighter2_action < 6) {

      // Fighter 1 is walking forward and fighter 2 is doing something else than attack (passiv).

      switch (fighter2_action) {

        case 1 :

          // Fighters 1 and 2 are walking forward.

          fighter1->change_x_value(-(result.w/2)) ;
          fighter2->change_x_value(  result.w/2 ) ;
          break ;

        default :

          // Fighters 2 is not kicking: walking forward, protected or in guard.

          fighter2->change_x_value(result.w) ;
          break ;

      }

      return ;

    }

    else if (fighter2_action == 1 and fighter1_action < 6) {

      switch (fighter1_action) {

        case 1 :

          // Fighters 1 and 2 are walking forward.

          fighter1->change_x_value(-(result.w/2)) ;
          fighter2->change_x_value(  result.w/2 ) ;
          break ;

        default :

          // Fighters 1 is not kicking: walking forward, protected or in guard.

          fighter1->change_x_value(-result.w) ;
          break ;

      }

      return ;

    }
    // Must be the last for dysfunction prevention !
    else if (fighter1_action == 0 and fighter2_action == 0) {

      // TODO: make something the automate fighter cannot staying doing nothing.
      //       The best were going forward if the distance autorize it.

      // @ATTENTION: a take care to do not make mess because the guard is a holy state.

      fighter1->change_x_value(-(result.w/2)+1) ;
      fighter2->change_x_value(  result.w/2+1 ) ;

      return ;

    }



  }
  else {

    if (fighter1->get_x() <= 0) {

      // Fighter 1 at left border.

      fighter1->set_x(0) ;

      return ;
    }

    if (fighter2->get_x() >= static_cast<int16_t>(WIDTH-(fighter2->image_rect.w)) ) {

      // Fighter 2 at right border.

      fighter2->set_x(static_cast<int16_t>( WIDTH-(fighter2->image_rect.w) ) ) ;

      return ;

    }

    if (fighter1_action == 0 and fighter2_action == 0) {

      if (not fighter2->m_is_player) {

        if (aggressiveness(gen)) {  // They are more chance that the result will be true. So most of the time:

          fighter2->set_kick(1) ;

          fighter2->set_x_sens(1)  ;

          fighter2->set_can_move(true) ;

          fighter2->set_move_by_kick(false) ;

          fighter2->set_blocking_image(false) ;

        }

      }

      return ;

    }

  }

  return ;
}

void fighter_2_compute_reactions(const int8_t fighter1_action, const int16_t fighter1_x, Fighters* fighter2) {

  /** This function controls the reactions of the automate fighter: the user adversary.
    * Responding to the player movement or attacks in differents (random) manner.
    **/

  auto distance = fighter2->get_x() - fighter1_x ;

  if (not fighter2->is_sequence_ended) {

    // Do nothing: continue image(s) sequence to run.

    fighter2->set_blocking_image(false) ;

    return ;

  }


  std::vector<int8_t> rand_kick_on_knees{12, 13, 17, 22} ;

  std::vector<int8_t> rand_fallback_kick{ 6, 7, 8, 9, 10, 12, 14, 19} ;



  std::random_device rd;
  std::mt19937 gen(rd());

  std::minstd_rand0 linear_rand(rd()) ;
  linear_rand.seed(std::time(nullptr)) ;


  std::uniform_int_distribution<int8_t> rand_animation(51, 53);
  std::uniform_int_distribution<int8_t> rand_kick(6, 23) ;

  std::uniform_int_distribution<int8_t> kick_fallback_idx(0, rand_fallback_kick.size()-1);

  static bool animation_on={true} ;

  if (distance >= 600 and animation_on) {

    // Fighter 2 is far away from fighter 1 so he does something like a joke: he does the idiot.

    fighter2->set_kick(rand_animation(gen)) ;

    fighter2->set_x_sens(0) ;

    fighter2->set_y_sens(0) ;

    fighter2->set_move_by_kick(false) ;

    fighter2->set_can_move(false) ;

    fighter2->set_blocking_image(false) ;

    animation_on={false} ;

    return ;

  }


  // aggressiveness: ((1.0-val)*1000) percent probability returning True.
  std::bernoulli_distribution aggressiveness((100.0f - fighter2->m_aggressiveness) / 100.0f);
  std::bernoulli_distribution fifty_fifty(0.5);


  std::uniform_int_distribution<int8_t> gone_kicking(-1, 2) ;
  std::uniform_int_distribution<int8_t> player_is_protected(-1, 1) ;


  // Minimal distance before the computer fighter begins to kick.
  const uint8_t min_dist_to_kick = 220  ;


  static int8_t fighter1_attack_counter{0} ;

  switch (fighter1_action) {

    case 0 :  // The fighter player is in guard.

      if (distance > min_dist_to_kick) {

        fighter2->set_kick(0) ;

        fighter2->set_move_by_kick(false) ;

        animation_on=true ;

        #ifdef DEBUG
        std::cout << "The automate fighter " << "is in guard" << std::endl ;
        #endif
 
      }
      else {

        std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

        fighter2->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

        fighter2->set_move_by_kick(true) ;

        #ifdef DEBUG
        std::cout << "The automate fighter " << "attacks" << std::endl ;
        #endif

      }

      fighter2->set_can_move(false) ;

      fighter2->set_x_sens(0) ;

      fighter2->set_blocking_image(false) ;

      fighter1_attack_counter = 0 ;

      break ;

    case 1 :  // The fighter player is walking forward.

      if (distance < min_dist_to_kick) {

        std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

        fighter2->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

        fighter2->set_move_by_kick(true) ;

        fighter2->set_x_sens(0) ;

        #ifdef DEBUG
        std::cout << "The automate fighter " << "attacks" << std::endl ;
        #endif

      }

      if (aggressiveness(gen)) {  // They are more chance that the result will be true. So most of the time:

        // The automate fighter walks backward.
        // When the player fighter walk forward.

        fighter2->set_kick_with_fallback(2, 1) ;
        fighter2->set_x_sens(-1) ;

        #ifdef DEBUG
        std::cout << "The automate fighter " << "walks " << "backward " << std::endl ;
        #endif
 
      }
      else {

        // The automate fighter walks forward.
        // When the player fighter walk forward.

        fighter2->set_kick(1) ;
        fighter2->set_x_sens(1) ;

        #ifdef DEBUG
        std::cout << "The automate fighter " << "walks " << "forward " << std::endl ;
        #endif
 
      }

      fighter2->set_can_move(true) ;

      fighter2->set_move_by_kick(false) ;

      fighter2->set_blocking_image(false) ;

      animation_on=true ;

      fighter1_attack_counter = 0 ;

      break ;

    case 2 :  // The fighter player walks backward.

      if (aggressiveness(gen)) {  // They are more chance that the result will be true. So most of the time:

        // The automate fighter walks forward.
        // When the player fighter walk backward.

        fighter2->set_kick(1) ;
        fighter2->set_x_sens(1) ;

        #ifdef DEBUG
        std::cout << "The automate fighter " << "walks " << "forward " << std::endl ;
        #endif

      }
      else {

        // The automate fighter walks backward.
        // When the player fighter walk backward.

        fighter2->set_kick_with_fallback(2, 1) ;

        fighter2->set_x_sens(-1) ;

        #ifdef DEBUG
        std::cout << "The automate fighter " << "walks " << "backward " << std::endl ;
        #endif

      }


      fighter2->set_move_by_kick(false) ;
      fighter2->set_can_move(true) ;
      fighter2->set_blocking_image(false) ;

      animation_on=true ;

      fighter1_attack_counter = 0 ;

      break ;

    case 3 : // Player fighter on his knees.

      if (distance < min_dist_to_kick) {

        std::shuffle(std::begin(rand_kick_on_knees), std::end(rand_kick_on_knees), gen) ;

        fighter2->set_kick(rand_kick_on_knees.at(0)) ;

        fighter2->set_move_by_kick(true) ;

        #ifdef DEBUG
        std::cout << "The automate fighter " << "attacks" << std::endl ;
        #endif

      }
      else {

        fighter2->set_kick(0) ;

        fighter2->set_move_by_kick(false) ;
 
        #ifdef DEBUG
        std::cout << "The automate fighter " << "stay in guard" << std::endl ;
        #endif
 
      }

      fighter2->set_x_sens(0) ;

      fighter2->set_blocking_image(false) ;

      fighter2->set_can_move(false) ;

      animation_on=true ;

      fighter1_attack_counter = 0 ;

      break ;



    case 4 : // Player fighter protected in standing.

      if (distance < min_dist_to_kick) {

        if (aggressiveness(gen)) {

          std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

          fighter2->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

          fighter2->set_x_sens(0) ;

          fighter2->set_move_by_kick(true) ;

          fighter2->set_can_move(false) ;
  
          #ifdef DEBUG
          std::cout << "The automate fighter " << "stay in guard" << std::endl ;
          #endif
  
        }
        else {

          fighter2->set_kick(2) ;

          fighter2->set_x_sens(0) ;

          fighter2->set_move_by_kick(false) ;

          fighter2->set_can_move(false) ;
  
          #ifdef DEBUG
          std::cout << "The automate fighter " << "walks backward" << std::endl ;
          #endif
  
        }



      }
      else {

        fighter2->set_kick(0) ;

        fighter2->set_x_sens(0) ;

        fighter2->set_move_by_kick(false) ;

        fighter2->set_can_move(false) ;

        #ifdef DEBUG
        std::cout << "The automate fighter " << "stay in guard" << std::endl ;
        #endif

      }



      fighter2->set_blocking_image(false) ;

      animation_on=true ;

      fighter1_attack_counter = 0 ;

      break ;

    case 5 : // Player fighter protected on his knees.

      if (distance < min_dist_to_kick) {

        if (aggressiveness(gen)) {

          std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

          fighter2->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

          fighter2->set_move_by_kick(true) ;

          fighter2->set_can_move(false) ;
  
          #ifdef DEBUG
          std::cout << "The automate fighter " << "attacks" << std::endl ;
          #endif
  
        }
        else {

          fighter2->set_kick(2) ;

          fighter2->set_move_by_kick(false) ;

          fighter2->set_can_move(false) ;
  
          #ifdef DEBUG
          std::cout << "The automate fighter " << "walks backward" << std::endl ;
          #endif
  
        }

      }
      else {

        fighter2->set_kick(0) ;

        fighter2->set_can_move(true) ;

        fighter2->set_move_by_kick(false) ;

        #ifdef DEBUG
        std::cout << "The automate fighter " << "stay in guard" << std::endl ;
        #endif

      }

      fighter2->set_x_sens(0) ;

      fighter2->set_blocking_image(false) ;

      animation_on=true ;

      fighter1_attack_counter = 0 ;

      break ;

    default :

      ++fighter1_attack_counter ;

      if (distance >= min_dist_to_kick) {

        fighter2->set_kick(0) ;

        fighter2->set_x_sens(0) ;

        fighter2->set_blocking_image(false) ;

        fighter2->set_can_move(false) ;

        fighter2->set_move_by_kick(false) ;

        #ifdef DEBUG
        std::cout << "The automate fighter " << "stay in guard" << std::endl ;
        #endif

        return ;

      }




      if ((fighter1_action == 12) and
          (fighter1_action == 13) and
          (fighter1_action == 17) and
          (fighter1_action == 22))     // The fighter player attack to knees.

      {

        switch (gone_kicking(gen)) {

          case -1 : // The automate fighter protecte his knees.

            fighter2->set_kick(4) ;

            fighter2->set_x_sens(0) ;

            fighter2->set_move_by_kick(false) ;

            fighter2->set_can_move(false) ;

            fighter2->set_blocking_image(false) ;
    
            #ifdef DEBUG
            std::cout << "The automate fighter " << "protect on his knees" << std::endl ;
            #endif
    
            break ;

          case 0 :  // The automate fighter attacks.

            std::shuffle(std::begin(rand_kick_on_knees), std::end(rand_kick_on_knees), gen) ;

            fighter2->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

            fighter2->set_x_sens(0) ;

            fighter2->set_move_by_kick(true) ;

            fighter2->set_can_move(false) ;

            fighter2->set_blocking_image(false) ;
    
            #ifdef DEBUG
            std::cout << "The automate fighter " << "attacks" << std::endl ;
            #endif
    
            break ;

          case 1 : // The automate fighter stay in guard.

              fighter2->set_kick(0) ; // Thye automate fighter stay in guard and so receive the kick.

              fighter2->set_x_sens(0) ;

              fighter2->set_move_by_kick(false) ;

              fighter2->set_can_move(false) ;

              fighter2->set_blocking_image(false) ;
      
              #ifdef DEBUG
              std::cout << "The automate fighter " << "stay in guard" << std::endl ;
              #endif
      
              break ;

           case 2 :

              if (fifty_fifty(gen)) {  // The automate fighter goes backward.

                fighter2->set_kick_with_fallback(2, 1) ;

                fighter2->set_x_sens(-1) ;

                fighter2->set_move_by_kick(false) ;

                fighter2->set_can_move(true) ;

                fighter2->set_blocking_image(false) ;
        
                #ifdef DEBUG
                std::cout << "The automate fighter " << "walks backward" << std::endl ;
                #endif
        
                break ;

              }
              else { // The automate fighter protect his head and body.

                fighter2->set_kick(4) ;

                fighter2->set_x_sens(0) ;

                fighter2->set_move_by_kick(false) ;

                fighter2->set_can_move(false) ;

                fighter2->set_blocking_image(false) ;
          
                #ifdef DEBUG
                std::cout << "The automate fighter " << "protect his head and body" << std::endl ;
                #endif
          
                break ;
              }

              break ;
          }

          break ; // break the default case.
      }
      else if (fighter1_action == 10 or
          fighter1_action == 11 or
          fighter1_action == 14 or
          fighter1_action == 15 or
          fighter1_action == 18 or
          fighter1_action == 20   )  // Case the player fighter kicks to the head.

      {

        switch (gone_kicking(gen)) {

          case -1 : // The automate fighter protecte his head and body.

            fighter2->set_kick(5) ;

            fighter2->set_x_sens(0) ;

            fighter2->set_move_by_kick(false) ;

            fighter2->set_can_move(false) ;

            fighter2->set_blocking_image(false) ;

            break ;

          case 0 :  // The automate fighter attacks.

            std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

            fighter2->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

            fighter2->set_x_sens(0) ;

            fighter2->set_move_by_kick(true) ;

            fighter2->set_can_move(false) ;

            fighter2->set_blocking_image(false) ;

            break ;

          case 1 : // The automate fighter stay in guard so receive the kick.

              fighter2->set_kick(0) ; // Thye automate fighter stay in guard and so receive the kick.

              fighter2->set_x_sens(0) ;

              fighter2->set_move_by_kick(false) ;

              fighter2->set_can_move(false) ;

              fighter2->set_blocking_image(false) ;

              break ;

           case 2 :  // The automate fighter goes to knees to evit the kick at the head or stay in guard to receive the kick.

              if (aggressiveness(gen)) { // They are more chance that the result will be true. So most of the time:

                fighter2->set_kick(3) ;  // The automate fighter goes to knees to evit the kick at the head.

                fighter2->set_x_sens(0) ;

                fighter2->set_move_by_kick(false) ;

                fighter2->set_can_move(false) ;

                fighter2->set_blocking_image(false) ;

                break ;

              }
              else {

                fighter2->set_kick_with_fallback(2, 1) ;  // The automate fighter goes back to evit the kick.

                fighter2->set_x_sens(-1) ;

                fighter2->set_move_by_kick(false) ;

                fighter2->set_can_move(true) ;

                fighter2->set_blocking_image(false) ;

                break ;
             }

             break ; // break the default case.

        }

      }
      else if (fighter1_attack_counter > 3) {

        // To not be under attack for a too long time.

        if (fifty_fifty(gen)) {

          fighter2->set_kick(1) ;
          fighter2->set_x_sens(1) ;
          fighter2->set_move_by_kick(false) ;
          fighter2->set_can_move(true) ;
          fighter2->set_blocking_image(false) ;

          return ;
        }
        else {

          std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

          fighter2->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

          fighter2->set_x_sens(0) ;

          fighter2->set_move_by_kick(true) ;

          fighter2->set_can_move(false) ;

          fighter2->set_blocking_image(false) ;

          return ;
        }

      }
      else {  // The fighter player kick other than head or knees (per example an return kick).


        switch (gone_kicking(gen)) {

          case -1 : // Thye automate fighter stay in guard to receive the kick.

            fighter2->set_kick(0) ;  // The automate fighter stay in guard so receive the kick.

            fighter2->set_x_sens(0) ;

            fighter2->set_move_by_kick(false) ;

            fighter2->set_can_move(false) ;

            fighter2->set_blocking_image(false) ;

            break ;

          case 0 :  // Attack on attack.

            std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

            fighter2->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

            fighter2->set_x_sens(0) ;

            fighter2->set_move_by_kick(true) ;

            fighter2->set_can_move(false) ;

            fighter2->set_blocking_image(false) ;

            break ;

          case 1 :  // Protection on knees.

            fighter2->set_kick(4) ;

            fighter2->set_x_sens(0) ;

            fighter2->set_move_by_kick(false) ;

            fighter2->set_can_move(false) ;

            fighter2->set_blocking_image(true) ;

            break ;

          case 2 :  // Go back to evit the kick.

            if (fifty_fifty(gen)) {

              fighter2->set_kick_with_fallback(2, 1) ;

              fighter2->set_x_sens(-1) ;

              fighter2->set_move_by_kick(false) ;

              fighter2->set_can_move(true) ;

              fighter2->set_blocking_image(false) ;

              break ;
            }
            else {

              std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

              fighter2->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

              fighter2->set_x_sens(0) ;

              fighter2->set_move_by_kick(true) ;

              fighter2->set_can_move(false) ;

              fighter2->set_blocking_image(false) ;

              break ;

            }


        }

        animation_on=true ;

        break ; // break the default case.

      }

      break ;

   }

   return ;

}


void computer_vs_computer(const int8_t adversary_action, const int16_t adversary_x, Fighters* fighter) {

  /** This function control the fighter 1 and 2 during a fight Computer vs Computer.
    *
    ********************************************************************************/

  int16_t distance ;

  bool is_fighter_1 = (fighter->get_flip() == SDL_FLIP_HORIZONTAL) ;

  if (is_fighter_1) {

    // Fighter is fighter 1 (left).

   distance = adversary_x - fighter->get_x() ;

  }
  else {

    // Fighter is fighter 2 (right).

    distance = fighter->get_x() - adversary_x ;

  }

  if (not fighter->is_sequence_ended) {

    // Do nothing: continue image(s) sequence to run.

    fighter->set_blocking_image(false) ;

    return ;

  }


  std::vector<int8_t> rand_kick_on_knees{12, 13, 17, 22} ;

  std::vector<int8_t> rand_fallback_kick{ 6, 7, 8, 9, 10, 12, 14, 19} ;



  std::random_device rd;
  std::mt19937 gen(rd());

  std::minstd_rand0 linear_rand(rd()) ;

  std::uniform_int_distribution<int8_t> rand_animation(51, 53);
  std::uniform_int_distribution<int8_t> rand_kick(6, 23) ;

  std::uniform_int_distribution<int8_t> kick_fallback_idx(0, rand_fallback_kick.size()-1);

  static bool animation_on={true} ;




  // aggressiveness: ((1.0-val)*1000) percent probability returning True.
  std::bernoulli_distribution aggressiveness((100.0f - fighter->m_aggressiveness) / 100.0f);
  std::bernoulli_distribution fifty_fifty(0.5);


  std::uniform_int_distribution<int8_t> gone_kicking(-1, 2) ;
  std::uniform_int_distribution<int8_t> player_is_protected(-1, 1) ;



  const uint8_t min_dist_to_kick = 165  ;


  static int8_t fighter_attack_counter{0} ;


  if (distance >= 600 and animation_on) {



    if (not aggressiveness(gen)) {

      // Fighter 1 or 2 is far away from fighter 1 or 2, so the fighter does something like a joke.

      fighter->set_kick(rand_animation(gen)) ;

      fighter->set_x_sens(0) ;


      fighter->set_y_sens(0) ;

      fighter->set_move_by_kick(false) ;

      fighter->set_can_move(false) ;

      fighter->set_blocking_image(false) ;

      animation_on={false} ;

      #ifdef DEBUG
      std::cout << "The fighter " << "make a joke (does the idiot)" << std::endl ;
      #endif

    }
    else {

      // Fighter 1 or 2 is far away from fighter 1 or 2, so the fighter stay in guard.

      fighter->set_kick(0) ;

      fighter->set_x_sens( (is_fighter_1) ? 1 : -1 ) ;

      fighter->set_move_by_kick(false) ;

      fighter->set_can_move(true) ;

      fighter->set_blocking_image(false) ;

      animation_on={true} ;

      #ifdef DEBUG
      std::cout << "The fighter " << "stay in guard" << std::endl ;
      #endif

    }

    return ;

  }

  switch (adversary_action) {

    case 0 :  // The fighter player is in guard.

      if (distance > min_dist_to_kick) {

        if (fifty_fifty(gen)) { // Fifty precent to return @true...
   
          // The fighter stay in guard.
   
          fighter->set_kick(0) ;

          fighter->set_move_by_kick(false) ;

          animation_on=true ;

          fighter->set_x_sens(0) ;

          fighter->set_can_move(false) ;
  
          #ifdef DEBUG
          std::cout << "The fighter " << "stay in guard" << std::endl ;
          #endif

        }
        else {

          // The fighter walks forward.
          // When the other fighter walk forward.

          fighter->set_kick(1) ;

          fighter->set_x_sens( (is_fighter_1) ? 1 : -1 ) ;

          animation_on=true ;

          fighter->set_can_move(true) ;
  
          #ifdef DEBUG
          std::cout << "The fighter " << "is walking forward" << std::endl ;
          #endif

        }

      }


      if (distance < min_dist_to_kick)  {

        std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

        fighter->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_x_sens(0) ;

        fighter->set_can_move(false) ;

        #ifdef DEBUG
        std::cout << "The fighter " << "attacks" << std::endl ;
        #endif

      }





      fighter->set_blocking_image(false) ;

      fighter_attack_counter = 0 ;

      break ;

    case 1 :  // The fighter is walking forward.

      if (distance < min_dist_to_kick) {

        std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

        fighter->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;



        fighter->set_x_sens(0) ;

        fighter->set_can_move(true) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_blocking_image(false) ;

        animation_on=true ;

        fighter_attack_counter = 0 ;
 
        #ifdef DEBUG
        std::cout << "The fighter " << "attacks" << std::endl ;
        #endif

        break ;

      }
      else {

        // The fighter walks forward.
        // When the other fighter walk forward.

        fighter->set_kick(1) ;

        fighter->set_x_sens( (is_fighter_1) ? 1 : -1)  ;

        fighter->set_can_move(true) ;

        fighter->set_move_by_kick(false) ;

        fighter->set_blocking_image(false) ;

        animation_on=true ;

        fighter_attack_counter = 0 ;
  
        #ifdef DEBUG
        std::cout << "The fighter " << "walks " << "forward" << std::endl ;
        #endif

        break ;

      }



    case 2 :  // The fighter walks backward.


      if (distance < min_dist_to_kick) {

        std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

        fighter->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

        fighter->set_x_sens(0) ;
 
        fighter->set_can_move(false) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_blocking_image(false) ;

        animation_on=true ;

        fighter_attack_counter = 0 ;

        #ifdef DEBUG
        std::cout << "The fighter " << "attacks" << std::endl ;
        #endif

        break ;

      }
      else {

        // The fighter walks forward.
        // When the other fighter walk forward.

        fighter->set_kick(1) ;

        fighter->set_x_sens( (is_fighter_1) ? 1 : -1)  ;

        fighter->set_can_move(true) ;

        fighter->set_move_by_kick(false) ;

        fighter->set_blocking_image(false) ;

        animation_on=true ;

        fighter_attack_counter = 0 ;

        #ifdef DEBUG
        std::cout << "The fighter " << "walks " << "forward" << std::endl ;
        #endif

        break ;

      }

    case 3 : // Fighter on his knees.

      if (distance < min_dist_to_kick) {

        std::shuffle(std::begin(rand_kick_on_knees), std::end(rand_kick_on_knees), gen) ;

        fighter->set_kick(rand_kick_on_knees.at(0)) ;

        fighter->set_move_by_kick(true) ;

        #ifdef DEBUG
        std::cout << "The fighter " << "attacks" << std::endl ;
        #endif

      }
      else {

        fighter->set_kick(0) ;

        fighter->set_move_by_kick(false) ;

        #ifdef DEBUG
        std::cout << "The fighter " << "stay in guard" << std::endl ;
        #endif

      }

      fighter->set_x_sens(0) ;

      fighter->set_blocking_image(false) ;

      fighter->set_can_move(false) ;

      animation_on=true ;

      fighter_attack_counter = 0 ;

      break ;



    case 4 : // Fighter protected in standing.

      if (distance < min_dist_to_kick) {

        std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

        fighter->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;
 
        #ifdef DEBUG
        std::cout << "The fighter " << "attacks" << std::endl ;
        #endif
 
      }
      else {

        fighter->set_kick(0) ;

        fighter->set_move_by_kick(false) ;

        fighter->set_can_move(true) ;
 
        #ifdef DEBUG
        std::cout << "The fighter " << "stay in guard" << std::endl ;
        #endif
 
      }

      fighter->set_x_sens(0) ;

      fighter->set_blocking_image(false) ;

      animation_on=true ;

      fighter_attack_counter = 0 ;

      break ;

    case 5 : // Fighter protected on his knees.

      if (distance < min_dist_to_kick) {

        std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

        fighter->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

        fighter->set_move_by_kick(true) ;

        fighter->set_can_move(false) ;

        #ifdef DEBUG
        std::cout << "The fighter " << "attacks" << std::endl ;
        #endif

      }
      else {

        fighter->set_kick(0) ;

        fighter->set_can_move(true) ;

        fighter->set_move_by_kick(false) ;

        #ifdef DEBUG
        std::cout << "The fighter " << "stay in guard" << std::endl ;
        #endif

      }

      fighter->set_x_sens(0) ;

      fighter->set_blocking_image(false) ;

      animation_on=true ;

      fighter_attack_counter = 0 ;

      break ;

    default :

      ++fighter_attack_counter ;

      if (distance >= min_dist_to_kick) {

        fighter->set_kick(0) ;

        fighter->set_x_sens(0) ;

        fighter->set_blocking_image(false) ;

        fighter->set_can_move(false) ;

        fighter->set_move_by_kick(false) ;

        #ifdef DEBUG
        std::cout << "The fighter " << "stay in guard" << std::endl ;
        #endif

        return ;

      }




      if ((adversary_action == 12) and
          (adversary_action == 13) and
          (adversary_action == 17) and
          (adversary_action == 22))     // The fighter attack to knees.

      {

        switch (gone_kicking(gen)) {

          case -1 : // The fighter protecte his knees.

            fighter->set_kick(4) ;

            fighter->set_x_sens(0) ;

            fighter->set_move_by_kick(false) ;

            fighter->set_can_move(false) ;

            fighter->set_blocking_image(false) ;
    
            #ifdef DEBUG
            std::cout << "The fighter " << "protect his knees" << std::endl ;
            #endif
    
            break ;

          case 0 :  // The fighter attacks.

            std::shuffle(std::begin(rand_kick_on_knees), std::end(rand_kick_on_knees), gen) ;

            fighter->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

            fighter->set_x_sens(0) ;

            fighter->set_move_by_kick(true) ;

            fighter->set_can_move(false) ;

            fighter->set_blocking_image(false) ;
    
            #ifdef DEBUG
            std::cout << "The fighter " << "attacks" << std::endl ;
            #endif
    
            break ;

          case 1 : // The fighter stay in guard.

              fighter->set_kick(0) ; // The fighter stay in guard and so receive the kick.

              fighter->set_x_sens(0) ;

              fighter->set_move_by_kick(false) ;

              fighter->set_can_move(false) ;

              fighter->set_blocking_image(false) ;
       
              #ifdef DEBUG
              std::cout << "The fighter " << "stay in guard" << std::endl ;
              #endif
       
              break ;

           case 2 : // The fighter goes backward.

              if (not aggressiveness(gen)) {

                fighter->set_kick_with_fallback( (is_fighter_1) ? 2 : 1, 1) ;

                fighter->set_x_sens( (is_fighter_1) ? 1 : -1)  ;

                fighter->set_move_by_kick(false) ;

                fighter->set_can_move(true) ;

                fighter->set_blocking_image(false) ;
         
                #ifdef DEBUG
                std::cout << "The fighter " << "walks forward" << std::endl ;
                #endif
         
                break ;

              }
              else {

                fighter->set_kick(4) ;

                fighter->set_x_sens(0) ;

                fighter->set_move_by_kick(false) ;

                fighter->set_can_move(false) ;

                fighter->set_blocking_image(false) ;
        
                #ifdef DEBUG
                std::cout << "The fighter " << "protect his knees" << std::endl ;
                #endif
        
                break ;
              }

              break ;
          }

          break ; // break the default case.
      }
      else if ( adversary_action == 10 or
                adversary_action == 11 or
                adversary_action == 14 or
                adversary_action == 15 or
                adversary_action == 18 or
                adversary_action == 20   )  // Case the fighter kicks to the head.

      {

        switch (gone_kicking(gen)) {

          case -1 : // The fighter protecte his head.

            fighter->set_kick(3) ;

            fighter->set_x_sens(0) ;

            fighter->set_move_by_kick(false) ;

            fighter->set_can_move(false) ;

            fighter->set_blocking_image(false) ;
    
            #ifdef DEBUG
            std::cout << "The fighter " << "protect his head and body" << std::endl ;
            #endif
    
            break ;

          case 0 :  // The fighter attacks.

            std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

            fighter->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

            fighter->set_x_sens(0) ;

            fighter->set_move_by_kick(true) ;

            fighter->set_can_move(false) ;

            fighter->set_blocking_image(false) ;
    
            #ifdef DEBUG
            std::cout << "The fighter " << "attacks" << std::endl ;
            #endif
    
            break ;

          case 1 : // The fighter stay in guard so receive the kick.

              fighter->set_kick(0) ; // Thye fighter stay in guard and so receive the kick.

              fighter->set_x_sens(0) ;

              fighter->set_move_by_kick(false) ;

              fighter->set_can_move(false) ;

              fighter->set_blocking_image(false) ;
        
              #ifdef DEBUG
              std::cout << "The fighter " << "stay in guard" << std::endl ;
              #endif
        
              break ;

           case 2 :  // The fighter goes to knees to evit the kick at the head or walks backward.

              if (aggressiveness(gen)) { // They are more chance that the result will be true. So most of the time:

                fighter->set_kick(3) ;  // The fighter goes to knees to evit the kick at the head.

                fighter->set_x_sens(0) ;

                fighter->set_move_by_kick(false) ;

                fighter->set_can_move(false) ;

                fighter->set_blocking_image(false) ;
        
                #ifdef DEBUG
                std::cout << "The fighter " << "go on his knees" << std::endl ;
                #endif
        
                break ;

              }
              else {

                fighter->set_kick_with_fallback( (is_fighter_1) ? 2 : 1, 1) ;  // The fighter goes back to evit the kick.

                fighter->set_x_sens( (is_fighter_1) ? -1 : 1 ) ;

                fighter->set_move_by_kick(false) ;

                fighter->set_can_move(true) ;

                fighter->set_blocking_image(false) ;
        
                #ifdef DEBUG
                std::cout << "The fighter " << "walks " << "backward to evit the kick" << std::endl ;
                #endif
        
                break ;
             }

             break ; // break the default case.

        }

      }
      else {  // The fighter kick other than head or knees (per example an return kick).


        switch (gone_kicking(gen)) {

          case -1 : // The fighter stay in guard to receive the kick.

            fighter->set_kick(0) ;  // The fighter stay in guard so receive the kick.

            fighter->set_x_sens(0) ;

            fighter->set_move_by_kick(false) ;

            fighter->set_can_move(false) ;

            fighter->set_blocking_image(false) ;
     
            #ifdef DEBUG
            std::cout << "The fighter " << "stay in guard" << std::endl ;
            #endif
     
            break ;

          case 0 :  // Attack on attack.

            std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

            fighter->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

            fighter->set_x_sens(0) ;

            fighter->set_move_by_kick(true) ;

            fighter->set_can_move(false) ;

            fighter->set_blocking_image(false) ;
    
            #ifdef DEBUG
            std::cout << "The fighter " << "attacks" << std::endl ;
            #endif
    
            break ;

          case 1 :  // Protection on knees.

            fighter->set_kick(4) ;

            fighter->set_x_sens(0) ;

            fighter->set_move_by_kick(false) ;

            fighter->set_can_move(false) ;

            fighter->set_blocking_image(true) ;
     
            #ifdef DEBUG
            std::cout << "The fighter " << "protect his knees" << std::endl ;
            #endif
     
            break ;

          case 2 :  // Go back to evit the kick.

            if (not aggressiveness(gen)) {
    
              fighter->set_kick_with_fallback( (is_fighter_1) ? 2 : 1, 1) ;

              fighter->set_x_sens( (is_fighter_1) ? -1 : 1 ) ;

              fighter->set_move_by_kick(false) ;

              fighter->set_can_move(true) ;

              fighter->set_blocking_image(false) ;
     
              #ifdef DEBUG
              std::cout << "The fighter " << "walks " << "backward " << std::endl ;
              #endif
        
              break ;
            }
            else {

              std::shuffle(std::begin(rand_fallback_kick), std::end(rand_fallback_kick), gen) ;

              fighter->set_kick_with_fallback(rand_kick(gen), rand_fallback_kick.at(kick_fallback_idx(linear_rand))) ;

              fighter->set_x_sens(0) ;

              fighter->set_move_by_kick(true) ;

              fighter->set_can_move(false) ;

              fighter->set_blocking_image(false) ;
      
              #ifdef DEBUG
              std::cout << "The fighter " << "attacks" << std::endl ;
              #endif
      
              break ;

            }


        }

        animation_on=true ;

        break ; // break the default case.

      }

      break ;

   }

   return ;

}


void construct_map_sound(void) {

  /** This function load the battle sounds at start. **/

  for (int8_t c=1 ; c <= 5 ; ++c) {

    std::string filepath{PATH_TO_SOUND_FILES "/Hit/"} ;

    filepath += std::to_string(c) ;

    filepath += ".wav" ;

    #ifdef DEBUG
    std::cout << "Sound: " << filepath << " loaded."  << std::endl ;
    #endif

    Mix_Chunk *fighter_kick_sound_effect = Mix_LoadWAV(filepath.c_str()) ;

    if (fighter_kick_sound_effect == nullptr) {

      fprintf(stderr,"%s\n", Mix_GetError() ) ;

      exit(EXIT_FAILURE) ;
    }

    hit_sound_container[c] = fighter_kick_sound_effect ;

  }



  for (int8_t c{1} ; c <= 15 ; ++c) {
 
    char *nb =  static_cast<char *>(malloc(sizeof(char)*3)) ;
 
    memset(nb, '\0', 3) ;

    sprintf(nb,"%02d",c) ;

    std::string filepath{PATH_TO_SOUND_FILES "/Kick/slightscream-"} ;

    filepath += nb ;

    filepath += ".ogg" ;

    #ifdef DEBUG
    std::cout << "Sound: " << filepath << " loaded."  << std::endl ;
    #endif

    free(nb) ;

    Mix_Chunk *fighter_kick_sound_effect = Mix_LoadWAV(filepath.c_str()) ;

    if (fighter_kick_sound_effect == nullptr) {

      fprintf(stderr,"%s\n", Mix_GetError() ) ;

      exit(EXIT_FAILURE) ;
    }

    kick_sound_container[c] = fighter_kick_sound_effect ;

  }




  return ;

}

void display_fighter(SDL_Renderer *pRenderer, SDL_Texture *texture, const int16_t x, SDL_RendererFlip flip) {

  /** Display a fighter in the presentation screen iwth special settings for the width. **/

  // Query current image size:
  int w, h ;
  SDL_QueryTexture(texture,
                   NULL,
                   NULL,
                   &w,
                   &h) ;


  if (flip == SDL_FLIP_NONE) {

    display_image(pRenderer, texture, x-w, (HEIGHT-h)) ;
  }
  else {

    display_image_simple_flip(pRenderer, texture, x-w, (HEIGHT-h), SDL_FLIP_HORIZONTAL) ;

  }

  return ;

}

void write_game_configuration_to_file(void) {

  /** This function write the game settings to the configuration file. **/

  std::ofstream configuration_file(PATH_TO_GAME_CONF_FILE, std::ios::out | std::ios::trunc) ;

  configuration_file << "difficulty=" + std::to_string(game_difficulty) << std::endl ;

  configuration_file << "speed="      + std::to_string(game_speed) << std::endl ;

  configuration_file << "sounds="     + std::to_string((game_sounds) ? 1 : 0) << std::endl ;

  configuration_file << "music="      + std::to_string((game_music) ? 1 : 0) << std::endl ;

  configuration_file.close() ;


}

void at_exit(void) {

  #ifdef DEBUG
  std::cout << __func__ << "(...) called" << std::endl ;
  #endif

  /** Function called at exit to free resources. **/

  for (auto &val : hit_sound_container) {

    if (val.second != nullptr) {
      Mix_FreeChunk(val.second) ;
    }

  }

  for (auto &val : kick_sound_container) {

    if (val.second != nullptr) {
      Mix_FreeChunk(val.second) ;
    }

  }

  delete input_handler ;

  clean_up(pRenderer,pWindow) ;

  /** Quit SDL subsystems: */
  IMG_Quit() ;
  TTF_Quit() ;
  Mix_CloseAudio() ;
  Mix_Quit() ;
  /** Quit SDL. **/
  SDL_Quit() ;

  exit(EXIT_SUCCESS) ;

}