OUT		= run
CC		= g++
FLAGS	= -g -c 
SRC		= ./src/
OBJ		= ./obj/
SOURCE	= main.cpp
OBJS	= $(OBJ)main.o

all: $(OBJS)
	$(CC) -w $(OBJS) -o $(OUT)

$(OBJ)main.o: $(SRC)main.cpp
	$(CC) $(FLAGS) $(SRC)main.cpp -o $(OBJ)main.o

$(OBJ)objects.o: $(SRC)objects.cpp
	$(CC) $(FLAGS) $(SRC)objects.cpp -o $(OBJ)objects.o

clean:
	rm $(OUT) $(OBJ)*.o

dist-clean: clean
	rm *.txt