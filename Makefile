all: lab67
lab67: stud.o checking.o structs.o AKClasses.o
	g++ stud.o checking.o AKClasses.o structs.o -o lab67
stud.o: stud.cpp
	g++ -c stud.cpp
checking.o: checking.cpp	
	g++ -c checking.cpp
structs.o: structs.cpp
	g++ -c structs.cpp
AKClasses.o: AKClasses.cpp
	g++ -c AKClasses.cpp
clean: 
	rm *.o