#include <string>
#include <cmath>
#include "student_id.h"
#include "miem.h"
#include "mgtuu.h"
#include "template_generator.h"


std::string random(std::string university_name, int year, int month, int day)//псевдослучайное число для билетов
{
	int un = 0;//un = 1 for miem; 0 for mgtuu
	if(university_name == "MIEM") un = 1;
	std::string ans;
	int lena_num = pow(10, 4 + un);
	if(un) ans = std::to_string((year*23456-month*6789+day*1203)%lena_num);
	else   ans = std::to_string((year*3456 -month*2345+day*678) %lena_num);
	for(int i = sizeof(ans); i < 5 + un; i ++) ans = std::to_string(i) + ans;
	return ans;
}


Student_ID* Template_Generator :: generator(std::string university_name, std::string sex, int year, int month, int day)
{
	static Student_ID* m;
	int un = 0;
	if(university_name == "MIEM") 
		{
			m = new MIEM;
			un += 1;
		}
	else m = new MGTUU;
	m->set_sex(sex);
	m->set_year(year);
	m->set_month(month);
	m->set_day(day); 
	std::string id;
	id += m->get_sex_for_id() + generate_date(m) + generate_random(m);
	int c_count = 0;
	for(int i = 0; i < id.size(); i++)
		c_count += (i + 1)*(id[i] - '0');
	id += std::to_string(c_count % (10 + un));
	m->set_id(id);
	return m;
} 


std::string Template_Generator :: generate_date(Student_ID* m)
{
	return m->get_year_for_id() + m->get_month_for_id() + m->get_day_for_id();
}

std::string Template_Generator :: generate_random(Student_ID* m)
{
	return random(m->get_name(), m->get_year(), m->get_month(), m->get_day());
}