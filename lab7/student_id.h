class Student_ID
{
public:
	virtual std::string get_sex_for_id() = 0;
	
	void set_sex(std::string);
	void set_year(int);
	void set_month(int);
	void set_day(int);
	void set_id(std::string);

	std::string get_id();

	std::string get_year_for_id();
	std::string get_month_for_id();
	std::string get_day_for_id();

	virtual std::string get_name() = 0;
	std::string get_sex();
	int get_year();
	int get_month();
	int get_day();
protected:
	std::string id;
	std::string sex;
	int year;
	int month;
	int day;
};