#include <string>

class Student_ID
{
public:
	virtual std::string generate(int, int, int, int) = 0;


class MIEM : public Student_ID
{
public:
	std::string generate(int, int, int, int) override;
};


class MGTUU : public Student_ID
{
public:
	std::string generate(int, int, int, int) override;
};