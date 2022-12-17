class Template_Generator
{
public:
	Student_ID* generator(std::string, std::string, int, int, int);
protected:
	std::string generate_date(Student_ID*);
	std::string generate_random(Student_ID*);
};