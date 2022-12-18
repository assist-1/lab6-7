CC = g++
CFLAGS = -c -Wall

all: myProg

myProg:lab7.o
	$(CC) lab7.o -o prog.exe

lab6.o: lab7.cpp
	$(CC) $(CFLAGS) lab7.cpp -o lab7.o

clean:
	del /s *.o

distclean:
	del /s *.o
	del /s prog.exe