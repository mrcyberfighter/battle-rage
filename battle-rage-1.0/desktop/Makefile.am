desktopdir  = /usr/share/applications

# Because the autotools doesn't take in charge the desktopdir...
#
# I don't know if i must write:
#
# $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
#
# Or
#
# ${desktopdir}/${PACKAGE_NAME}.desktop
#
# So be indulgent the user or Mr the packager.


desktop:
	- @echo "[Desktop Entry]" > $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Version=1.0" >> $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Name=battle-rage" >> $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "GenericName=Battle-Rage" >> $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Comment=With battle-rage, the battle rages on !" >> $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Exec=battle-rage" >> $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Icon=$(DESTDIR)${pkgdatadir}/Images/Icon/battle-rage_icon.png" >> $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Terminal=false" >> $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "X-MultipleArgs=false" >> $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "StartupNotify=true" >> $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Type=Application" >> $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Keywords=Fight-Them-All;Beat-Them-All;Fighting;Game;" >> $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "Categories=Game;ArcadeGame;" >> $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop
	- @echo "desktop file generated at: $(DESTDIR)${desktopdir}/${PACKAGE_NAME}.desktop"

update-desktop:
	- $(XDG_DESKTOP_MENU)  install --novendor --mode system "${desktopdir}/${PACKAGE_NAME}.desktop"

mkdir-desktop:
	if `! test -d "$(DESTDIR)/${desktopdir}"` ; then ${MKDIR_P} "$(DESTDIR)/${desktopdir}" ; fi

install-data-hook:
	${MAKE} mkdir-desktop
	${MAKE} desktop
	${MAKE} update-desktop
	$(CHMOD) -R a+rx "$(DESTDIR)${pkgdatadir}"
	if `test ! -d "$(DESTDIR)${pkgdatadir}/Configuration"` ; then ${MKDIR_P} $(DESTDIR)${pkgdatadir}/Configuration ; fi
	$(CHMOD) -R a+rwx "$(DESTDIR)${pkgdatadir}/Configuration"

uninstall-hook:
	- $(RM) -f ${desktopdir}/${PACKAGE_NAME}.desktop
	- $(RM) -rf "$(DESTDIR)${pkgdatadir}"
	- $(RM) -f "$(DESTDIR)${pkgdatadir}"
	- $(RM) -f "$(DESTDIR)${BINDIR}/battle-rage"
