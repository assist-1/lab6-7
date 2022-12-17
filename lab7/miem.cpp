#include <string>
#include "student_id.h"
#include "miem.h"

std::string MIEM :: get_sex_for_id()
{
	std::string sex = get_sex();
	if(sex == "woman") return "4";
	return "8";
}

std::string MIEM :: get_name()
{
	return "MIEM";
}