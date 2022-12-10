PROJECT = main
CC = clang++


$(PROJECT): main.o function.o
	$(CC) main.o function.o -o $(PROJECT)


main.0: main.cpp
	$(CC) main.cpp -o main.o


function.0: function.cpp
	$(CC) function.cpp -o function.o

clear:
	rm $(PROJECT) *.o

distclean:
	rm $(PROJECT) *.o *.txt