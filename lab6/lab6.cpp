#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>

class interface{
	public:
		std::string data;
		virtual void generateStudentCard(std::string sex,std::string birthYear,std::string birthMonth,std::string birthDay )=0;
		
};

class miem : public interface{
	public:
		void generateStudentCard(std::string sex,std::string birthYear,std::string birthMonth,std::string birthDay ) override final{
			std::stringstream res;
			
			if(sex.length()==3||sex.length()==5){
				if(sex=="man"){
					res << "8";
				}
				else{
					res << "4";
				}
			}
			else {
				std::cerr << "WRONG SEX" << std::endl;
				exit(1);
			}
			
			std::string birthDat;
			std::stringstream birthDate;
			if(birthYear.length()==4){
				birthDate << birthYear;
			}
			else{
				std::cerr << "WRONG BIRTHYEAR FORMAT" << std::endl;
				exit(1);
			}
			
			if(birthMonth.length()==2){
				birthDate << birthMonth;
			}
			else{
				std::cerr << "WRONG BIRTHMONTH FORMAT" << std::endl;
				exit(1);
			}
			
			if(birthDay.length()==2){
				birthDate << birthDay;
			}
			else{
				std::cerr << "WRONG BIRTHDAY FORMAT" << std::endl;
				exit(1);
			}
			birthDat = birthDate.str();
			res << birthDat;
			
			int randomNumber;
			srand(std::stoi(birthDat));
			randomNumber = rand()%(99999-10000+1)+10000;
			res << std::to_string(randomNumber);
			
			std::string calcC = res.str();
			int Multi = 0;
			for(int i=0;i<calcC.length();i++){
				Multi = Multi + (i+1)*std::stoi(calcC.substr(i,1));
				
			}
			for(int i=0;i<10;i++){
				if((Multi+i*15)%11==0){
					res << std::to_string(i);
				}
			}
			
			std::string result = res.str();
			this->data = result;
		}
};

class mgtu : public interface{
	public:
		void generateStudentCard(std::string sex,std::string birthYear,std::string birthMonth,std::string birthDay ) override final{
			std::stringstream res;
			
			if(sex.length()==3||sex.length()==5){
				if(sex=="man"){
					res << "2";
				}
				else{
					res << "1";
				}
			}
			else {
				std::cerr << "WRONG SEX" << std::endl;
				exit(1);
			}
			
			std::string birthDat;
			std::stringstream birthDate;
			if(birthYear.length()==4){
				birthDate << birthYear;
			}
			else{
				std::cerr << "WRONG BIRTHYEAR FORMAT" << std::endl;
				exit(1);
			}
			
			if(birthMonth.length()==2){
				birthDate << birthMonth;
			}
			else{
				std::cerr << "WRONG BIRTHMONTH FORMAT" << std::endl;
				exit(1);
			}
			
			if(birthDay.length()==2){
				birthDate << birthDay;
			}
			else{
				std::cerr << "WRONG BIRTHDAY FORMAT" << std::endl;
				exit(1);
			}
			birthDat = birthDate.str();
			res << birthDat;
			
			int randomNumber;
			srand(std::stoi(birthDat));
			randomNumber = rand()%(9999-1000+1)+1000;
			res << std::to_string(randomNumber);
			
			std::string calcC = res.str();
			int Multi = 0;
			for(int i=0;i<calcC.length();i++){
				Multi = Multi + (i+1)*std::stoi(calcC.substr(i,1));
				
			}
			for(int i=0;i<10;i++){
				if((Multi+i*14)%10==0){
					res << std::to_string(i);
				}
			}
			
			std::string result = res.str();
			this->data = result;
		}
};

void fromFileFunc(miem* miemObjects,mgtu* mgtuObjects,int number){
	std::ifstream file("fromFileExample.txt"); //Format example: mgtu man 2005 01 07
	std::string line;
	int mgtuPos = 0;
	int miemPos = 0;
	if(file.is_open()){
		getline(file,line);
	}
	else{
		std::cerr << "FILE CANNOT BE OPENED" << std::endl;
		exit(1);
	}
	
	if(line.substr(0,4)=="mgtu"){
		mgtuObjects[mgtuPos].generateStudentCard(line.substr(5,3),line.substr(9,4),line.substr(14,2),line.substr(17,2));
	}
	else if(line.substr(0,4)=="miem"){
		miemObjects[miemPos].generateStudentCard(line.substr(5,3),line.substr(9,4),line.substr(14,2),line.substr(17,2));
	}
	else{
		std::cerr << "WRONG FROMFILE INPUT" << std::endl;
		exit(1);
	}
}

int main(int argc, char** argv){
	bool toFile = false;
	bool fromFile = false;
	
	int number = 1;
	miem* miemObjects = new miem[number];
	mgtu* mgtuObjects = new mgtu[number];
	
	for(int i=0;i<argc;i++){
		if(strcmp(argv[i],"--toFile")==0) toFile = true;
		if(strcmp(argv[i],"--fromFile")==0) {
			fromFile = true;
			
		}
	}
	
	if(fromFile) fromFileFunc(miemObjects,mgtuObjects,number);
	
	if(toFile&&fromFile==true){
		std::ofstream file("toFile.txt");
		file << mgtuObjects[0].data << std::endl;
		file << miemObjects[0].data << std::endl;
	}
	if(toFile==false&&fromFile==true){
		std::cout << mgtuObjects[0].data << std::endl;
		std::cout << miemObjects[0].data << std::endl;
	}
	
	/*
	miem miemObject;
	miemObject.generateStudentCard("man","2005","01","07");
	std::cout << miemObject.data << std::endl;
	
	mgtu mgtuObject;
	mgtuObject.generateStudentCard("woman","1984","10","07");
	std::cout << mgtuObject.data << std::endl;
	*/
	delete[] miemObjects;
	delete[] mgtuObjects;
	return 0;
}
