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

/*void Client(TemplateStudentCard* class_){
	class_->TemplateGenerator(
}*/

int main(){
	Mgtuu* MgtuuObj1 = new Mgtuu;
	std::string SB_1 = MgtuuObj1->TemplateGenerator("woman", "1994", "10","07");
	std::cout << SB_1;
	return 0;
}