TR = main
CC = g++
OB = func.o c.o
$(TR) : $(OB)
	$(CC) $(OB) -o $(TR)

func.o : func.cpp
	$(CC) -c func.cpp -o func.o

c.o : c.cpp
	$(CC) -c c.cpp -o c.o

clean :
	rm $(OB)

distclean : clean
	rm $(TR) *.txt Makefile