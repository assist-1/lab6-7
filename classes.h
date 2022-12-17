#ifndef CLASSES
#define CLASSES
#include <string>

class PassTiket {
protected:
	int sex;
	int year;
	int month;
	int day;
	std::string passticket = "";
public:
	virtual std::string pass_generate() = 0;
};

class PASS_MIEM : public PassTiket {
public:
	PASS_MIEM(int sex, int year, int month, int day) {
		this->sex   = (sex == 1) ? 8 : 4;
		this->year  = year;
		this->month = month;
		this->day   = day;
	}
	std::string pass_generate() override;
}


#endif