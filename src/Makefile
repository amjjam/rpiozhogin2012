libdir=$(prefix)/lib

CPPFLAGS=-Wall -g -fPIC
CPP=g++

RPIOZHOGIN2012_SRC=rpiozhogin2012.C
RPIOZHOGIN2012_OBJ=$(RPIOZHOGIN2012_SRC:.C=.o)

build: libRpiozhogin2012.a libRpiozhogin2012.so

libRpiozhogin2012.a: $(RPIOZHOGIN2012_OBJ)
	ar rc $@ $^

libRpiozhogin2012.so: $(RPIOZHOGIN2012_OBJ)
	$(CPP) -shared -Wl,-soname,$@ -o $@ $^

install: $(libdir)/libRpiozhogin2012.a $(libdir)/libRpiozhogin2012.so

$(libdir)/libRpiozhogin2012.a $(libdir)/libRpiozhogin2012.so: libRpiozhogin2012.a libRpiozhogin2012.so
	cp libRpiozhogin2012.a libRpiozhogin2012.so $(libdir)

uninstall:
	- rm -f $(libdir)/libRpiozhogin2012.a $(libdir)/libRpiozhogin2012.so

clean:
	- rm -f libRpiozhogin2012.a libRpiozhogin2012.so $(RPIOZHOGIN2012_OBJ)
