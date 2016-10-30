SUBDIRS = source data man texi doc desktop

###############################################################################
#                                                                             #
# This will install the source locally: into ${DESTDIR}${pkgdatadir}/source   #
#                                                                             #
# It's done for you so that you can modify my code... and test the result.    #
#                                                                             #
# A Makefile is provided with the source,                                     #
#                                                                             #
# simply change to ${DESTDIR}${pkgdatadir} and type:                          #
#                                                                             #
# $ make help                                                                 # 
#                                                                             #
# To sea the provided target. Good hacking !                                  #
#                                                                             #
###############################################################################

nobase_dist_pkgdata_DATA   =  ./source/*.cpp            \
                              ./source/*.h       \
                              ./source/Fighters/*.cpp   \
                              ./source/Fighters/*.h     \
                              ./source/Files/*.cpp      \
                              ./source/Files/*.h        \
                              ./source/headers/*.h      \
                              ./Makefile.mk
                         
EXTRA_DIST = ./Makefile.mk

install-data-hook:
	$(MV) $(DESTDIR)$(pkgdatadir)/Makefile.mk $(DESTDIR)$(pkgdatadir)/Makefile
	$(CHMOD) -R a+rwx "$(DESTDIR)${pkgdatadir}/source"
	if `test ! -d "$(DESTDIR)${pkgdatadir}/bin"`; then $(MKDIR_P) "$(DESTDIR)${pkgdatadir}/bin" ; fi
	$(CHMOD) -R a+rwx "$(DESTDIR)${pkgdatadir}/bin"
                        