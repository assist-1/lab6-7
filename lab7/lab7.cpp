#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>

class TemplateStudentCard{
	public: 
		std::string TemplateGenerator(std::string sex,std::string birthYear,std::string birthMonth,std::string birthDay) const{
			std::stringstream almostResultTemp;
			std::string amlostResult;
			std::string result;
			almostResultTemp << generateSex(sex);
			std::string birthDate = generateBirthDate(birthYear,birthMonth,birthDay);
			almostResultTemp << birthDate;
			almostResultTemp << randomNumber(birthDate);
			
			std::string almostResult = almostResultTemp.str();
			almostResultTemp << lastNumberRes(almostResult);
			result = almostResultTemp.str();
			return result;
		}
	protected:
		std::string generateBirthDate(std::string birthYear,std::string birthMonth,std::string birthDay) const {
			std::string birthDat;
			std::stringstream birthDate;
			if(birthYear.length()==4){
				birthDate << birthYear;
			}
			else{
				std::cerr << "WRONG BIRTHYEAR FORMAT" << std::endl;
				exit(1);
			}
			
			if(birthMonth.length()==2&&(std::stoi(birthMonth)<=12&&std::stoi(birthMonth)>=1)){
				birthDate << birthMonth;
			}
			else{
				std::cerr << "WRONG BIRTHMONTH FORMAT" << std::endl;
				exit(1);
			}
			
			if(birthDay.length()==2&&(std::stoi(birthDay)<=31&&std::stoi(birthDay)>=1)){
				birthDate << birthDay;
			}
			else{
				std::cerr << "WRONG BIRTHDAY FORMAT" << std::endl;
				exit(1);
			}
			birthDat = birthDate.str();
			return birthDat;
		}
		
		virtual std::string generateSex(std::string sex) const =0;
		virtual std::string randomNumber(std::string birthDate) const = 0;
		virtual std::string lastNumberRes(std::string alsmostRes) const = 0;
		
		virtual void SomeMethod1()const{}
		virtual void SomeMethod2()const{}
};

class Mgtuu : public TemplateStudentCard{
	protected:
		 std::string generateSex(std::string sex) const override{
			 std::string res;
			 if(sex.length()==3||sex.length()==5){
				if(sex=="man"){
					res = "2";
				}
				else{
					res = "1";
				}
			}
			return res;
		 }
		 std::string randomNumber(std::string birthDate) const override{
			std::string res;
			int randomNumber;
			srand(std::stoi(birthDate));
			randomNumber = (rand()+1000)%10000;
			res = std::to_string(randomNumber);
			return res;
		 }
		 std::string lastNumberRes(std::string calcC) const override{
			 int Multi = 0;
			 std::string res;
			 for(int i=calcC.length()-1;i>=1;i--){
				Multi = Multi + (i+1)*std::stoi(calcC.substr(i,1));
			}
			bool check = false;
			for(int i=0;i<10;i++){
				if((Multi+i*1)%10==0){
					check = true;
					res = std::to_string(i);
					break;
				}
			}
			if(check){
				return res;
			}
			else {
				std::cerr << "SOMETHING WENT WRONG WHILE CALCULATING LAST NUMBER." << std::endl;
				exit(1);
			}
		 }
};

class Miem : public TemplateStudentCard{
	protected:
		 std::string generateSex(std::string sex) const override{
			 std::string res;
			 if(sex.length()==3||sex.length()==5){
				if(sex=="man"){
					res = "8";
				}
				else{
					res = "4";
				}
			}
			return res;
		 }
		 std::string randomNumber(std::string birthDate) const override{
			std::string res;
			int randomNumber;
			srand(std::stoi(birthDate));
			randomNumber = (rand()%90000)+10000;
			res = std::to_string(randomNumber);
			return res;
		 }
		 std::string lastNumberRes(std::string calcC) const override{
			int Multi = 0;
			std::string res;
			for(int i=0;i<calcC.length();i++){
				Multi = Multi + (i+1)*std::stoi(calcC.substr(i,1));
			}
			bool check = false;
			for(int i=0;i<10;i++){
				if((Multi+i*15)%11==0){
					check = true;
					res = std::to_string(i);
					break;
				}
			}
			if(check){
				return res;
			}
			else {
				std::cerr << "SOMETHING WENT WRONG WHILE CALCULATING LAST NUMBER." << std::endl;
				exit(1);
			}
		 }
};


/*void Client(TemplateStudentCard* class_){
	class_->TemplateGenerator(
}*/

std::string fromFileFunc(Miem* miemObjects,Mgtuu* mgtuObjects,int number){
	std::ifstream file("fromFileExample.txt"); //Format example: 0123456789
	std::string line;							//				 mgtu woman 1999 11 21
	int mgtuPos = 0;							//				 mgtu man 2005 01 07
	int miemPos = 0;
	if(file.is_open()){
		getline(file,line);
	}
	else{
		std::cerr << "FILE CANNOT BE OPENED" << std::endl;
		exit(1);
	}
	
	if(line.substr(0,4)=="mgtu"){
		if(line.substr(5,3)=="man"){
			return mgtuObjects[mgtuPos].TemplateGenerator(line.substr(5,3),line.substr(9,4),line.substr(14,2),line.substr(17,2));
		}
		else return mgtuObjects[mgtuPos].TemplateGenerator(line.substr(5,5),line.substr(11,4),line.substr(16,2),line.substr(19,2));
	}
	else if(line.substr(0,4)=="miem"){
		if(line.substr(5,3)=="man"){
			return miemObjects[miemPos].TemplateGenerator(line.substr(5,3),line.substr(9,4),line.substr(14,2),line.substr(17,2));
		}
		else return miemObjects[miemPos].TemplateGenerator(line.substr(5,5),line.substr(11,4),line.substr(16,2),line.substr(19,2));
	}
	else{
		std::cerr << "WRONG FROMFILE INPUT" << std::endl;
		exit(1);
	}
}

int main(int argc,char** argv){
	bool toFile = false;
	bool fromFile = false;
	
	int number = 1;
	Miem* miemObjects = new Miem[number];
	Mgtuu* mgtuObjects = new Mgtuu[number];
	
	for(int i=0;i<argc;i++){
		if(strcmp(argv[i],"--toFile")==0) toFile = true;
		if(strcmp(argv[i],"--fromFile")==0) {
			fromFile = true;
			
		}
	}
	
	if(toFile&&fromFile==true){
		std::ofstream file("toFile.txt");
		file << fromFileFunc(miemObjects,mgtuObjects,number);
	}
	if(toFile==false&&fromFile==true){
		std::cout << fromFileFunc(miemObjects,mgtuObjects,number) << std::endl;
	}
	
	/*
	Mgtuu* MgtuuObj1 = new Mgtuu;
	std::string SB_1 = MgtuuObj1->TemplateGenerator("woman", "1994", "10","07");
	std::cout << SB_1 << std::endl;
	Miem* MiemObj1 = new Miem;
	std::string SB_2 = MiemObj1->TemplateGenerator("woman", "1994", "10","07");
	std::cout << SB_2 << std::endl;
	*/
	delete[] miemObjects;
	delete[] mgtuObjects;
	return 0;
}