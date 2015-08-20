
CC=gcc
CFLAGS=-I.
LDFLAGS=-L.
TARGET=mytest
SRCS=mytest.c mytestthread.c
LIBNAME=mytestlib
LIBSRC=$(LIBNAME).c

#@echo link dynamic

all: $(TARGET)

$(TARGET): $(LIBNAME)
	$(CC)  $(SRCS) $(CFLAGS) $(LDFLAGS) -l$< -lpthread -o $@

$(LIBNAME):
ifeq ($(link), d)
	@echo dynamic link
	$(CC) -c -fPIC $(LIBSRC) -o $@.o
	$(CC) -shared -Wl,-soname,lib$@.so -o lib$@.so $@.o
else
ifeq ($(link), s)
	@echo link static
	$(CC) -c $(LIBSRC) -o $@.o
	ar rcs lib$@.a $@.o
else
	@echo no link type defined, use: link=d or link=s
	exit 1
endif
endif

clean:
	rm -f $(TARGET) *.o *.a *.so



