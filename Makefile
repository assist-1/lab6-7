CC=g++
CFLAGS=-c -std=c++17

all: lab_67
lab_67 : main.o
	$(CC) main.o -o lab_67

main.o : main.cpp
	$(CC) -c main.cpp -o main.o

clean :
	rm -rf *.o lab_67

distclean :
	rm -rf *.o lab_67
