#include <iostream>

class University {
public:
    std::string sex;
    University() {}
    virtual std::string gen(std::string, int, int, int) = 0;
};

class MIEM : public University {
public:
    MIEM(){}
    std::string gen(std::string, int, int, int) override;
};

class MGTUU : public University {
public:
    MGTUU(){}
    std::string gen(std::string, int, int, int) override;
};

std::string first_gen(int, int, int, int);

class template_pattern_student_number_generator {
public:
    template_pattern_student_number_generator() {};
    University* generator(std::string);
};