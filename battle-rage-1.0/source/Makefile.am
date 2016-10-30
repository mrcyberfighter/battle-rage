AUTOMAKE_OPTIONS=subdir-objects

bin_PROGRAMS = battle-rage

battle_rage_SOURCES =   ./global_vars.cpp \
                        ./global_fighters.cpp \
                        ./Files/draw_rect.cpp \
                        ./Files/images_utils.cpp \
                        ./Files/ttf_utils.cpp \
                        ./Files/SDL2_utils.cpp \
                        ./Fighters/Fighters.cpp \
                        ./Fighters/Fuuma.cpp \
                        ./Fighters/Geese_Howard.cpp \
                        ./Fighters/Hanzo.cpp \
                        ./Fighters/Hotaru_Futaba.cpp \
                        ./Fighters/Iori_Yagami.cpp \
                        ./Fighters/K.cpp \
                        ./Fighters/Kim_Kaphwan.cpp \
                        ./Fighters/Kisarah_Westfield.cpp \
                        ./Fighters/Kyo_Kusanagi.cpp \
                        ./Fighters/Lee_Pai_Long.cpp \
                        ./Fighters/Mai_Shiranui.cpp \
                        ./Fighters/Mr_Big.cpp \
                        ./Fighters/Mr_Karate.cpp \
                        ./Fighters/Robert_Garcia.cpp \
                        ./Fighters/Rock_Howard.cpp \
                        ./Fighters/Terry_Bogard.cpp \
                        ./Input_Handler.cpp \
                        ./joystick.cpp \
                        ./helper_functions.cpp \
                        ./main.cpp \
                        ./joystick_configuration.cpp \
                        ./choose_fighters.cpp \
                        ./fighting_mainloop.cpp \
                        ./presentation_screen.cpp \
                        ./main_menu.cpp \
                        ./configure_game_menu.cpp \
                        ./round_interlude.cpp

               

EXTRA_DIST =  *.h \
              ./Files/*.h    \
              ./Fighters/*.h \
              ./headers/*.h
          

battle_rage_CPPFLAGS = -DPREFIX=\"$(DESTDIR)$(prefix)\"
       
OPTIMISATION = -finline-functions -fno-signed-zeros       
       
battle_rage_CXXFLAGS = $(OPTIMISATION) ${SDL2_CFLAGS} ${SDL2_IMAGE_CFLAGS} ${SDL2_TTF_CFLAGS} ${SDL2_MIXER_CFLAGS}
battle_rage_LDADD =  ${SDL2_LIBS} ${SDL2_IMAGE_LIBS} ${SDL2_TTF_LIBS} ${SDL2_MIXER_LIBS} ${LIBS}      