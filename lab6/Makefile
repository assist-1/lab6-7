CC = g++
CFLAGS = -c -Wall

all: myProg

myProg:lab6.o
	$(CC) lab6.o -o myProg.exe

lab6.o: lab6.cpp
	$(CC) $(CFLAGS) lab6.cpp -o main.o

clean:
	del /s *.o

distclean:
	del /s *.o
	del /s myProg.exe