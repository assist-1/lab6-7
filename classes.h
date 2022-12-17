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



#endif