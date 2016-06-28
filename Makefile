CC            ?=  gcc
CFLAGS        ?=  -Ofast

PREFIX        ?=  /usr
RM            ?=  rm -f
INSTALL_DIR   ?=  install -m755 -d
INSTALL_PROG  ?=  install -m755

all:
	@echo "CC randstr.c"
	@$(CC) $(CFLAGS) randstr.c -o randstr

install:
	$(INSTALL_DIR) $(DESTDIR)$(PREFIX)/bin
	$(INSTALL_PROG) randstr $(DESTDIR)$(PREFIX)/bin/randstr

uninstall:
	$(RM) $(DESTDIR)$(PREFIX)/bin/randstr
