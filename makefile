out : main.o uni.o
	g++ main.o uni.o -o out

main.o : main.cpp
	g++ -c main.cpp -o main.o

fun.o : uni.cpp
	g++ -c uni.cpp -o uni.o

clean :
	rm out *.o

distclean :
	rm out *.o *.txt