#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "student_id.h"
#include "miem.h"
#include "mgtuu.h"
#include "template_generator.h"


#include "funcs.cpp"



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


	std::string* data;

	if(fromfile == 2) 
	{
		std::ifstream in;
		in.open(fromfile_name);
		data = read(in, true, fromfile_name);
		in.close();
		std::cout << "File " << fromfile_name << " was readen"<< std::endl;
	}
	else
	{
		data = read(std::cin, false, " ");
	}


	Template_Generator template_generator;

	std::string sd = template_generator.generator(data[0], data[1], stoi(data[2]), stoi(data[3]), stoi(data[4]))->get_id();


	// Student_ID* gen;

	// if(data[0] == "MIEM") gen = new MIEM;
	// else gen = new MGTUU;
	// string sd;
	// if(data[1] == "woman") sd = gen->generate(sex::woman, std::stoi(data[2]), std::stoi(data[3]), std::stoi(data[4]));
	// else                   sd = gen->generate(sex::  man, std::stoi(data[2]), std::stoi(data[3]), std::stoi(data[4]));
	

	if(tofile == 2)
	{
		std::ofstream out;
		out.open(tofile_name, std::ios::out);
		out << sd;
		out.close();
		std::cout << "Answer was written in " << tofile_name << std::endl;
	}
	else std::cout << sd << std::endl;

	return EXIT_SUCCESS;
}