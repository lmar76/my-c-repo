CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -shared
LIBFILE = libmylib.so
OBJECTS = mylib.o
HEADERS = mylib.h
BASEDIR = /opt/mylib
INCLUDEDIR = $(addprefix $(BASEDIR)/,include)
LIBDIR = $(addprefix $(BASEDIR)/,lib)

$(LIBFILE): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -f $(LIBFILE) $(OBJECTS)

install:
	mkdir -p $(INCLUDEDIR)
	mkdir -p $(LIBDIR)
	install -t $(INCLUDEDIR) $(HEADERS)
	install -t $(LIBDIR) $(LIBFILE)

uninstall:
	rm -fr $(BASEDIR)

.PHONY: clean install uninstall

