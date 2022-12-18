TR = prog
CC = g++
OB = functions.o main.o
$(TR) : $(OB)
	$(CC) $(OB) -o $(TR)

functions.o : functions.cpp
	$(CC) -c functions.cpp -o functions.o

main.o : main.cpp
	$(CC) -c main.cpp -o main.o

clean :
	rm $(OB)

distclean : clean
	rm $(TR) *.txt Makefile