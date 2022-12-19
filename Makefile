SixSeven.exe : SixSeven.cpp geni.h
	g++ SixSeven.cpp -o SixSeven.exe

clean:
	rm SixSeven.exe

distclean :
	rm SixSeven.exe
	rm SixSeven.cpp
	rm geni.h
	rm Makefile