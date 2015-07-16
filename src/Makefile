libdir=$(prefix)/lib

CPPFLAGS=-Wall -g -fPIC
CPP=g++

RPIOZHOGIN2012_SRC=rpiozhogin2012.C
RPIOZHOGIN2012_OBJ=$(RPIOZHOGIN2012_SRC:.C=.o)

build: libRpiOzhogin2012.a libRpiOzhogin2012.so

libRpiOzhogin2012.a: $(RPIOZHOGIN2012_OBJ)
	ar rc $@ $^

libRpiOzhogin2012.so: $(RPIOZHOGIN2012_OBJ)
	$(CPP) -shared -Wl,-soname,$@ -o $@ $^

install: $(libdir)/libRpiOzhogin2012.a $(libdir)/libRpiOzhogin2012.so

$(libdir)/libRpiOzhogin2012.a $(libdir)/libRpiOzhogin2012.so: libRpiOzhogin2012.a libRpiOzhogin2012.so
	cp libRpiOzhogin2012.a libRpiOzhogin2012.so $(libdir)

uninstall:
	- rm -f $(libdir)/libRpiOzhogin2012.a $(libdir)/libRpiOzhogin2012.so

clean:
	- rm -f libRpiOzhogin2012.a libRpiOzhogin2012.so $(RPIOZHOGIN2012_OBJ)
