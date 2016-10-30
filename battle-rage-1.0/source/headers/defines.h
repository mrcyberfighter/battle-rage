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

#ifndef __BATTLE_RAGE_1_0_0_DEFINES_HH__ /** Inclusion guard **/
#define __BATTLE_RAGE_1_0_0_DEFINES_HH__

/** About definition: **/
#define AUTHOR      "Brüggemann Eddie"
#define MAIL        "mrcyberfighter@gmail.com"
#define PRGNAME     "battle-rage"
#define VERSION     "1.0"
#define LICENSE     "GPLv3"
#define PRGWEBURL   "http://www.open-source-projects.net/battle-rage/battle-rage"
#define COPYRIGHT   "Copyright (C) 2016 Brüggemann Eddie GPLv3"

/** Conditional Prefix definition. **/
#ifndef PREFIX
#define PREFIX ".."

/** You must define PREFIX by distributing with a preprocessor directive:
  *
  * $ c++ -DPREFIX="/usr" -o prgname $(OBJECTS)
  *
  * @or
  *
  * $ c++ -D'PREFIX="/usr/local"' -o prgname $(OBJECTS)
  *
  ***********************************************************************/

#endif


/** Path definitions: **/
#define DATADIR                                 PREFIX "/share/" PRGNAME




#define PATH_TO_FIGHTERS                        DATADIR "/Images/Fighters"


#define PATH_TO_SPRITES_Mr_Karate               PATH_TO_FIGHTERS "/Mr. Karate"

#define PATH_TO_SPRITES_Fuuma                   PATH_TO_FIGHTERS "/Fuuma"

#define PATH_TO_SPRITES_Geese_Howard            PATH_TO_FIGHTERS "/Geese Howard"

#define PATH_TO_SPRITES_Hanzo                   PATH_TO_FIGHTERS "/Hanzo"

#define PATH_TO_SPRITES_Hotaru_Futaba           PATH_TO_FIGHTERS "/Hotaru Futaba"

#define PATH_TO_SPRITES_Iori_Yagami             PATH_TO_FIGHTERS "/Iori Yagami"

#define PATH_TO_SPRITES_K                       PATH_TO_FIGHTERS "/K'"

#define PATH_TO_SPRITES_Kim_Kaphwan             PATH_TO_FIGHTERS "/Kim Kaphwan"

#define PATH_TO_SPRITES_Kisarah_Westfield       PATH_TO_FIGHTERS "/Kisarah Westfield"

#define PATH_TO_SPRITES_Kyo_Kusanagi            PATH_TO_FIGHTERS "/Kyo Kusanagi"

#define PATH_TO_SPRITES_Lee_Pai_Long            PATH_TO_FIGHTERS "/Lee Pai Long"

#define PATH_TO_SPRITES_Mai_Shiranui            PATH_TO_FIGHTERS "/Mai Shiranui"

#define PATH_TO_SPRITES_Mr_Big                  PATH_TO_FIGHTERS "/Mr. Big"

#define PATH_TO_SPRITES_Mr_Karate               PATH_TO_FIGHTERS "/Mr. Karate"

#define PATH_TO_SPRITES_Robert_Garcia           PATH_TO_FIGHTERS "/Robert Garcia"

#define PATH_TO_SPRITES_Rock_Howard             PATH_TO_FIGHTERS "/Rock Howard"

#define PATH_TO_SPRITES_Terry_Bogard            PATH_TO_FIGHTERS "/Terry Bogard"



#define PATH_TO_BACKGROUND      DATADIR "/Images/Background"


#define PATH_TO_LIFEBAR_IMG     DATADIR "/Images/Lifebar"

#define PATH_TO_JOYSTICK_IMG    DATADIR "/Images/Joystick"

#define PATH_TO_FONT_TTF        DATADIR "/Fonts"

#define PATH_TO_JOY_CONF_FILE   DATADIR "/Configuration/joysticks.ini"

#define PATH_TO_GAME_CONF_FILE  DATADIR "/Configuration/game_config.ini"

#define PATH_TO_THUMB_IMG       DATADIR "/Images/Fighters/thumb"


#define PATH_TO_SOUND_FILES     DATADIR "/Sound"

#define PATH_TO_SOUND_VOICES    PATH_TO_SOUND_FILES "/Voices"

#define PATH_TO_SOUND_MUSIC     PATH_TO_SOUND_FILES "/Music"

#define PATH_TO_ICON            DATADIR "/Images/Icon"

#define PATH_TO_NOTICE          DATADIR "/Documentation/notice.html"

#define WIDTH  800
#define HEIGHT 576


/** Uncomment to use gettext
#define GETTEXT_SUPPORT */


#ifdef GETTEXT_SUPPORT
#include <libintl.h>

#ifdef ROOT

#ifdef  PACKAGE
#undef  PACKAGE
#endif

#define PACKAGE    "./"   PRGNAME


#ifdef  LOCALEDIR
#undef  LOCALEDIR
#endif

#else

#define PACKAGE  PREFIX "/bin" "/" PRGNAME

#endif /* ROOT */

#define LOCALEDIR  PREFIX "/share" "/locale"

#define _(String) gettext       (String)
#define gettext_noop(String)     String
#define N_(String) gettext_noop (String)

#endif /* GETTEXT_SUPPORT */






/** Uncomment to use debug features or use the target: make ddebug
#define DEBUG */

#ifdef DEBUG

#include <cstdio>

#define DEBUG_PT          fprintf(stderr,"\n%s:%s(...) at line: %d\n", __FILE__, __func__, __LINE__) ;
#define DEBUG_FUNC_MARK   fprintf(stderr,"\n%s:%s(...) called\n",__FILE__, __func__) ;

#define DEBUG_INT(x)      fprintf(stderr,"DEBUG PT N° %d\n",   (x)) ;
#define DEBUG_LINT(x)     fprintf(stderr,"DEBUG PT N° %d\n",   (x)) ;
#define DEBUG_LLINT(x)    fprintf(stderr,"DEBUG PT N° %d\n",   (x)) ;

#define DEBUG_FLOAT(x)    fprintf(stderr,"DEBUG PT N° %f\n",   (x)) ;
#define DEBUG_DOUBLE(x)   fprintf(stderr,"DEBUG PT N° %lf\n",  (x)) ;
#define DEBUG_LDOUBLE(x)  fprintf(stderr,"DEBUG PT N° %llf\n", (x)) ;

#define DEBUG_STR(str)    fprintf(stderr,"%s\n", (str)) ;
#define DEBUG_PTR(ptr)    fprintf(stderr,"%p\n", (ptr)) ;


/** Extended DEBUGGING **/
#define EDEBUG_INT(str, x)      fprintf(stderr,"%s(line:%d): %s %d\n",   __func__, __LINE__, (str), (x)) ;
#define EDEBUG_LINT(str, x)     fprintf(stderr,"%s(line:%d): %s %d\n",   __func__, __LINE__, (str), (x)) ;
#define EDEBUG_LLINT(str, x)    fprintf(stderr,"%s(line:%d): %s %d\n",   __func__, __LINE__, (str), (x)) ;

#define EDEBUG_FLOAT(str, x)    fprintf(stderr,"%s(line:%d): %s %f\n",   __func__, __LINE__, (str), (x)) ;
#define EDEBUG_DOUBLE(str, x)   fprintf(stderr,"%s(line:%d): %s %lf\n",  __func__, __LINE__, (str), (x)) ;
#define EDEBUG_LDOUBLE(str, x)  fprintf(stderr,"%s(line:%d): %s %llf\n", __func__, __LINE__, (str), (x)) ;

#define EDEBUG_STR(str)         fprintf(stderr,"%s(%d): %s\n", __func__, __LINE__, (str)) ;
#define EDEBUG_PTR(ptr)         fprintf(stderr,"%s(%d): %s\n", __func__, __LINE__, (ptr)) ;

#endif




#endif /** Inclusion guard **/