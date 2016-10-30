AC_PREREQ([2.69])
AC_INIT([battle-rage], [1.0], [mrcyberfighter@gmail.com], [battle-rage], [www.open-source-projects.net/battle-rage/battle-rage])

AC_CONFIG_SRCDIR([./source])

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign -Wall -Werror])



AC_LANG([C++])

AC_COPYRIGHT([GPLv3])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CXX_C_O
AC_PROG_CXXCPP


# std=c++11
AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])

# vector.at(...)
AX_CXX_HAVE_VECTOR_AT

# POSIX programs detection.
AC_PROG_INSTALL
AC_PROG_MKDIR_P
AC_PROG_LN_S
AC_PROG_MAKE_SET


# coreutils package
AC_PATH_PROG([CHMOD],       [chmod],      [no])
AC_PATH_PROG([RM],          [rm],         [no])
AC_PATH_PROG([MV],          [mv],         [no])
AC_PATH_PROG([BASENAME],    [basename],   [no])

if test "$CHMOD" = no ; then

  AC_MSG_ERROR(Install the coreutils package (chmod is missing) !, 1)

fi


if test "$RM" = no ; then

  AC_MSG_ERROR(Install the coreutils package (rm is missing) !, 1)

fi


if test "$MV" = no ; then

  AC_MSG_ERROR(Install the coreutils package (mv is missing) !, 1)

fi

if test "$BASENAME" = no ; then

  AC_MSG_ERROR(Install the coreutils package (basename is missing) !, 1)

fi


# xdg-utils package:
AC_PATH_PROG([XDG_OPEN],    [xdg-open],   [no])

if test "$XDG_OPEN" = no ; then

  AC_MSG_WARN(xdg-open is used to display the notice into the program !)

fi

# desktop-file-utils package:
AC_PATH_PROG([DESKTOP_FILE_INSTALL],    [desktop-file-install],   [no])

if test "$DESKTOP_FILE_INSTALL" = no ; then

  AC_MSG_WARN(Install the desktop-file-utils (Not absolute required) !)
  AC_MSG_NOTICE(The desktop-file-install tool is used to install the *.desktop file.)

fi

# xdg-utils package:
AC_PATH_PROG([XDG_DESKTOP_MENU],    [xdg-desktop-menu],   [no])

if test "$XDG_DESKTOP_MENU" = no ; then

  AC_MSG_WARN(Install the xdg-utils (Not absolute required) !)
  AC_MSG_NOTICE(The xdg-desktop-menu tool is used to install the *.desktop file.)
  AC_MSG_NOTICE(The xdg-desktop-menu tool is used to update the *.desktop file database.)

fi

# desktop-file-utils package:
AC_PATH_PROG([UPDATE_DESKTOP_DATABASE],    [update-desktop-database],   [no])

if test "$UPDATE_DESKTOP_DATABASE" = no ; then

  AC_MSG_WARN(Install the desktop-file-utils (Not absolute required) !)
  AC_MSG_NOTICE(The update-desktop-database tool is used to update the *.desktop file database.)

fi

# unzip package:
AC_PATH_PROG([UNZIP],    [unzip],   [no])

if test "$UNZIP" = no ; then

  AC_MSG_ERROR(Install the unzip package !, 1)

fi

# Checks for libraries:

# sdl2
PKG_CHECK_MODULES([SDL2], [sdl2], [], [SDL2=no])

if test "$SDL2" = no ; then

   # Fallback because the pkg-config (*.pc) file is not present.

   AC_CHECK_LIB(SDL2, SDL_Init, [],  AC_MSG_ERROR(   libdl2 library not detected !!!

   ***************** sdl2 library required for battle-rage ****************
   Install the sdl2 library from your package manager or from source.

   WARNING: Take care to install the development files from libsdl2 !
            Often call: libsdl2-dev or libsdl2-devel.

   Then retry to launch the ./configure script...
   ************************************************************************
   , 1))

fi


# SDL2_image
PKG_CHECK_MODULES([SDL2_IMAGE], [SDL2_image], [], [SDL2_IMAGE=no])

if test "$SDL2_IMAGE" = no ; then

   # Fallback because the pkg-config (*.pc) file is not present.

   AC_CHECK_LIB(SDL2_image, IMG_Init, [],  AC_MSG_ERROR(   libsdl2-image library not detected !!!

   ************** sdl2-image library required for battle-rage *************
   Install the sdl2-image library from your package manager or from source.

   WARNING: Take care to install the development files from libsdl2-image !
            Often call: libsdl2-image-dev or libsdl2-image-devel.

   Then retry to launch the ./configure script...
   ************************************************************************
   , 1))

fi

# SDL2_TTF
PKG_CHECK_MODULES([SDL2_TTF], [SDL2_ttf], [], [SDL2_TTF=no])

if test "$SDL2_TTF" = no ; then
 
   # Fallback because the pkg-config (*.pc) file is not present.
 
   AC_CHECK_LIB(SDL2_ttf, TTF_Init, [],  AC_MSG_ERROR(   libsdl2-ttf library not detected !!!

   **************** sdl2-ttf library required for battle-rage *************
   Install the sdl2-ttf library from your package manager or from source.

   WARNING: Take care to install the development files from libsdl2-ttf !
            Often call: libsdl2-ttf-dev or libsdl2-ttf-devel.

   Then retry to launch the ./configure script...
   ************************************************************************
   , 1))

fi

# SDL2_mixer
PKG_CHECK_MODULES([SDL2_MIXER], [SDL2_mixer], [], [SDL2_MIXER=no])

if test "$SDL2_MIXER" = no ; then

   # Fallback because the pkg-config (*.pc) file is not present.

   AC_CHECK_LIB(SDL2_mixer, Mix_Init, [],  AC_MSG_ERROR(   libsdl2-mixer library not detected !!!

   *************** sdl2-mixer library required for battle-rage ************
   Install the sdl2-mixer library from your package manager or from source.

   WARNING: Take care to install the development files from libsdl2-mixer !
            Often call: libsdl2-mixer-dev or libsdl2-mixer-devel.

   Then retry to launch the ./configure script...
   ************************************************************************
   , 1))

fi

AC_CHECK_HEADER_STDBOOL
AC_C_INLINE


# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT16_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_CHECK_FUNCS([atexit memset malloc realpath strerror])

AC_CONFIG_FILES([Makefile
                source/Makefile
                texi/Makefile
                man/Makefile
                data/Makefile
                doc/Makefile
                desktop/Makefile
                ])

AC_OUTPUT

AC_MSG_NOTICE(System check OK !!!)

echo "
  ************************** ${PACKAGE_STRING} ************************

  ${PACKAGE_NAME} a Beat-Them-All fighting game to use with joystick(s).

  Package dependencies: sdl2, sdl2-image, sdl2-ttf, sdl2-mixer.

  Compiler: ${CXX} ${CXXFLAGS} ${CPPFLAGS}

  Prefix: ${prefix}

  Author: Brüggemann Eddie.
  contact: ${PACKAGE_BUGREPORT}

  Now enter:

  $ make
  $ sudo make install

  To build and install ${PACKAGE_NAME}.

  You can launch the program with the commandline:
  $ battle-rage
  or with the icon from your desktop menu.
"