CC = g++
CFLAGS += -c
RM = del
OBJS = main.o funcs7.o

.PHONY: all, clean, distclean, realclean, uninstall

all: make

make: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o main
main.o: main.cpp funcs.hpp
	$(CC) $(CFLAGS) $< -o $@
funcs7.o: funcs6.cpp
	$(CC) $(CFLAGS) $^ -o funcs7.o

clean:
	$(RM) $(OBJS)
distclean: clean
	$(RM) main.exe output.txt
realclean: distclean
	$(RM) input.txt makefile
uninstall: realclean
	$(RM) funcs.hpp funcs6.cpp main.cpp