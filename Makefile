main: Source.o lab_6_7.o
	g++ Source.o lab_6_7.o -o main

Source.o: Source.cpp
	g++ -c Source.cpp -o Source.o

lab_6_7.o: lab_6_7.cpp
	g++ -c lab_6_7.cpp -o lab_6_7.o

clean:
	rm Source.o lab_6_7.o

distclean : clean
	rm main *.txt Makefile