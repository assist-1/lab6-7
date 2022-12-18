TARGET = Prog
CC=g++
CFLAGS=-I.

PREF_SRC = ./src/
PREF_OBJ = ./obj/

$(TARGET) : $(PREF_OBJ)classmake.o $(PREF_OBJ)classes.o
	$(CC) $(PREF_OBJ)classmake.o $(PREF_OBJ)classes.o -o $(TARGET)

$(PREF_OBJ)classmake.o : $(PREF_SRC)classmake.cpp
	$(CC) -c $(PREF_SRC)classmake.cpp -o $(PREF_OBJ)classmake.o

$(PREF_OBJ)classes.o : $(PREF_SRC)classes.cpp
	$(CC) -c $(PREF_SRC)classes.cpp -o $(PREF_OBJ)classes.o

mytest : $(PREF_OBJ)tests.o $(PREF_OBJ)classes.o
	$(CC) $(PREF_OBJ)tests.o $(PREF_OBJ)classes.o -o mytest

$(PREF_OBJ)tests.o : $(PREF_SRC)tests.cpp
	$(CC) -c $(PREF_SRC)tests.cpp -o $(PREF_OBJ)tests.o

clean:
	rm $(TARGET) $(PREF_OBJ)*.o

dist-clean: clean
	rm -f *.txt mytest