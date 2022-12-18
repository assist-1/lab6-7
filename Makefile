all:
	g++ main.cpp -o task
clean:
		rm -rf *.o task
distclean:
		rm -rf *.o task
		rm *.txt
