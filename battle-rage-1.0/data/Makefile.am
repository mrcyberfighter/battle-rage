
nobase_dist_pkgdata_DATA   =  ./Images.zip                      \
                              ./Sound.zip                       \
                              ./Configuration/game_config.ini   \
                              ./Documentation/*.html            \
                              ./Documentation/*.inv             \
                              ./Documentation/*.js              \
                              ./Documentation/_images/*.png     \
                              ./Documentation/_sources/*.txt    \
                              ./Documentation/_static/*.gif     \
                              ./Documentation/_static/*.png     \
                              ./Documentation/_static/*.css     \
                              ./Documentation/_static/*.js      \
                              ./Fonts/UbuntuMono-R.ttf          \
                              ./License/GPLv3.txt
                         
install-data-hook:
	if `test -f "${DESTDIR}/${pkgdatadir}/Images.zip"` ; then $(UNZIP) -q -o "${DESTDIR}/${pkgdatadir}/Images.zip"  -d "${DESTDIR}/${pkgdatadir}"   ; fi
	if `test -f "${DESTDIR}/${pkgdatadir}/Sound.zip"`  ; then $(UNZIP) -q -o "${DESTDIR}/${pkgdatadir}/Sound.zip"   -d "${DESTDIR}/${pkgdatadir}"   ;  fi
	if `test -f "${DESTDIR}/${pkgdatadir}/Images.zip"` ; then $(RM) -f "${DESTDIR}/${pkgdatadir}/Images.zip" ; fi
	if `test -f "${DESTDIR}/${pkgdatadir}/Sound.zip"`  ; then $(RM) -f "${DESTDIR}/${pkgdatadir}/Sound.zip"  ; fi

uninstall-hook:
	if `test -d "${DESTDIR}/${pkgdatadir}/Images"` ; then $(RM) -rf "${DESTDIR}/${pkgdatadir}/Images" ; fi
	if `test -d "${DESTDIR}/${pkgdatadir}/Sound"`  ; then $(RM) -rf "${DESTDIR}/${pkgdatadir}/Sound"  ; fi