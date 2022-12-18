all : ConsoleApplication4.cpp funs.h
	g++ ConsoleApplication4.cpp -o ConsoleApplication4.exe

clean:
	rm ConsoleApplication4.exe

distclean :
	rm ConsoleApplication4.exe
	rm ConsoleApplication4.cpp
	rm funs.h
	rm Makefile