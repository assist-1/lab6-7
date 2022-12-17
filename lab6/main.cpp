#include <iostream>
#include <cstring>
#include "student_id.hpp"
#include <fstream>
using std::string;
#include "funcs.cpp"

enum sex { woman = 4, man = 8};//sex::woman




int main(int argc, char** argv){
	if(argc == 2 || argc == 4 || argc > 5)
		{
			std::cerr << "You have to enter any flag and name of file after, like: --tofile name.txt --fromfile name.txt" << std::endl;
			return EXIT_FAILURE;
		}
	int tofile = 0;
	int fromfile = 0;
	char* tofile_name;
	char* fromfile_name;
	for(int i = 1; i < argc; i++)
	{
		if(tofile == 1) 
		{
			tofile_name = argv[i];
			tofile = 2;
		}
		else if(fromfile == 1) 
		{
			fromfile_name = argv[i];
			fromfile = 2;
		}
		else if(strcmp(argv[i], "--tofile")  == 0 && tofile  == 0) tofile   = 1;
		else if(strcmp(argv[i], "--fromfile")==0  && fromfile == 0) fromfile = 1;
		else
		{
			std::cerr << "Unexpected flag " << argv[i] << std::endl;
			return EXIT_FAILURE;
		}
	}


	string* data;

	if(fromfile == 2) 
	{
		std::ifstream in;
		in.open(fromfile_name);
		data = read(in, true, fromfile_name);
		in.close();
		std::cout << "File \033[95m" << fromfile_name << " \033[97mwas readen"<< std::endl;
	}
	else
	{
		data = read(std::cin, false, " ");
	}

	Student_ID* gen;

	if(data[0] == "MIEM") gen = new MIEM;
	else gen = new MGTUU;
	string sd;
	if(data[1] == "woman") sd = gen->generate(sex::woman, std::stoi(data[2]), std::stoi(data[3]), std::stoi(data[4]));
	else                   sd = gen->generate(sex::  man, std::stoi(data[2]), std::stoi(data[3]), std::stoi(data[4]));


	if(tofile == 2)
	{
		std::ofstream out;
		out.open(tofile_name, std::ios::out);
		out << sd;
		out.close();
		std::cout << "Answer was written in \033[95m" << tofile_name << "\033[97m" << std::endl;
	}
	else std::cout << sd << std::endl;

	return EXIT_SUCCESS;
}