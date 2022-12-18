#include <iostream>
#include <cstring>
#include "classes.h"
int main(int argc, char ** argv) {
	const char * flags[4] = {"--help", "--default", "--tofile", "--fromfile"};

	if(argc == 1) {
		std::cerr << "ERROR: flag not found!" << std::endl;
		std::cerr << "You can enter '--help' for instruction output" << std::endl;
		exit(1);
	}
	else if(argc == 2) {
		if(!strcmp(argv[1], flags[0]))
			Help();
		else if(!strcmp(argv[1], flags[1])) {
			GetResultFromConsole();
		}
	}
	return 0;
}