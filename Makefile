make: l67.o
	g++ -o make l67.o
clean:
	rm *.o make
distclean: clean
	rm Makefile