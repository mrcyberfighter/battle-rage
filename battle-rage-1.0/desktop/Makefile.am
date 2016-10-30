# Because the autotools doesn't take in charge the desktopdir...
#
# I must write the *.desktop file by hand
#
# And it comes to a mess when handling with DESTDIR.
#
# So please be indulgent about it thanks !
#
# I create the *.desktop file at $(desktopdir)
#
# Then I update the *.desktop files database with the xdg-utils or the desktop-file-utils.

desktopdir  = $(DESTDIR)/usr/share/applications

desktop:
	- @echo "[Desktop Entry]" > ${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Version=1.0" >> ${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Name=battle-rage" >> ${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "GenericName=Battle-Rage" >> ${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Comment=With battle-rage, the battle rages on !" >> ${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Exec=battle-rage" >> ${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Icon=$(DESTDIR)${pkgdatadir}/Images/Icon/battle-rage_icon.png" >> ${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Terminal=false" >> ${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "X-MultipleArgs=false" >> ${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "StartupNotify=true" >> ${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Type=Application" >> ${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Keywords=Fight-Them-All;Beat-Them-All;Fighting;Game;" >> ${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Categories=Game;ArcadeGame;" >> ${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "desktop file generated at: ${desktopdir}/${PACKAGE_NAME}.desktop"

update-desktop:
	if `test -x ${XDG_DESKTOP_MENU}` ; then ${XDG_DESKTOP_MENU}  forceupdate --mode system ; \
	elif `test -x ${UPDATE_DESKTOP_DATABASE}` ; then ${UPDATE_DESKTOP_DATABASE} -q "${desktopdir}" ; fi

install-desktop:
	if `test -x ${XDG_DESKTOP_MENU}` ; then ${XDG_DESKTOP_MENU}  install --noupdate --novendor --mode system "${desktopdir}/${PACKAGE_NAME}.desktop" ; \
	elif `test -x ${DESKTOP_FILE_INSTALL}` ; then ${DESKTOP_FILE_INSTALL} --dir="$(desktopdir)" "${desktopdir}/${PACKAGE_NAME}.desktop" ; fi

mkdir-desktop:
	if `! test -d "${desktopdir}"` ; then ${MKDIR_P} "${desktopdir}" ; fi

install-data-hook:
	${MAKE} mkdir-desktop
	${MAKE} desktop
	${MAKE} install-desktop
	${MAKE} update-desktop
	$(CHMOD) -R a+rx "$(DESTDIR)${pkgdatadir}"
	if `test ! -d "$(DESTDIR)${pkgdatadir}/Configuration"` ; then ${MKDIR_P} $(DESTDIR)${pkgdatadir}/Configuration ; fi
	$(CHMOD) -R a+rwx "$(DESTDIR)${pkgdatadir}/Configuration"

uninstall-hook:
	- $(RM) -f ${desktopdir}/${PACKAGE_NAME}.desktop
	- $(RM) -rf "$(DESTDIR)${pkgdatadir}"
	- $(RM) -f "$(DESTDIR)${pkgdatadir}"
	- $(RM) -f "$(DESTDIR)${bindir}/battle-rage"
	- ${MAKE} update-desktop