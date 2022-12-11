#include <string>
#include "student_id.h"
#include "mgtuu.h"

std::string MGTUU :: get_sex_for_id()
{
	std::string sex = get_sex();
	if(sex == "woman") return "1";
	return "2";
}
std::string MGTUU :: get_name()
{
	return "MGTUU";
}