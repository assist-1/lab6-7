PROJECT = main
CC = g++


$(PROJECT): main.o class.o
	$(CC) main.o class.o -o $(PROJECT)

main.o: main.cpp
	$(CC) -c main.cpp -o main.o

class.o: class.cpp
	$(CC) -c class.cpp -o class.o

clean:
	rm $(PROJECT) *.o

distclean: clean
	rm -f make
