#include <iostream>
#include <fstream>
#include <map>
#include <random>
#include <ctime>

using namespace std;

enum class sex {
    man, woman
};


class templateGenerator{
public:
    templateGenerator(unsigned int minN_, unsigned int maxN_) {
        maxN = maxN_;
        minN = minN_;

        rndN = {};

        mt19937 rnd(time(0));
        uniform_int_distribution <mt19937::result_type> distribution(minN, maxN + 1);

        for (unsigned int year = 1900; year <= 2100; year++)
            for (unsigned int month = 1; month <= 12; month++)
                for (unsigned int day = 1; day <= 31; day++)
                    rndN[this->getData(year, month, day)] = distribution(rnd);



        cout << "Generation ended" << endl;
    }

    virtual ~templateGenerator() {

    };

    string generate(sex gender, unsigned int year, unsigned int month, unsigned int day){
        string res = "";

        res += (this->getS(gender));
        res += (this->getData(year, month, day));
        res += (this->getN(year, month, day));
        res += (this->getC(res));

        return res;
    }

protected:
    map <string, unsigned int> rndN;
    unsigned int maxN, minN;

    virtual string toN(unsigned int rnd) = 0;
    virtual string getS(sex gender) = 0;
    virtual string getN(unsigned int year, unsigned int month, unsigned int day) = 0;
    virtual string getC(string s) = 0;
    string getData(unsigned int year, unsigned int month, unsigned int day) {
        string res = "";

        res += (to_string(year / 1000) + to_string(year % 1000 / 100) + to_string(year % 100 / 10) + to_string(year % 10));
        res += (to_string(month / 10) + to_string(month % 10));
        res += (to_string(day / 10) + to_string(day % 10));

        return res;
    }
};


class MIEM final : public templateGenerator {
public:
    MIEM() : templateGenerator(10000, 99999){

    }

protected:
    virtual string toN(unsigned int rnd) override {
        string res = "";

        res += to_string(rnd / 10000);
        res += to_string(rnd % 10000 / 1000);
        res += to_string(rnd % 1000 / 100);
        res += to_string(rnd % 100 / 10);
        res += to_string(rnd % 10);

        return res;
    }

    virtual string getS(sex gender) override {
        return (gender == sex::man ? "8" : "4");
    }

    virtual string getN(unsigned int year, unsigned int month, unsigned int day) override {
        return toN(rndN[this->getData(year, month, day)]);
    }

    virtual string getC(string s) override {
        unsigned int summ = 0;

        for (size_t i = 0; i < s.size(); i++)
            summ += ((i + 1) * (s[i] - '0'));

        for (unsigned int i = 0; i <= 9; i++)
            if ((summ + i * (s.size() + 1)) % 11 == 0)
                return to_string(i);


        return "*";
    }

};


class MGTU final : public templateGenerator {
public:
    MGTU() : templateGenerator(1000, 9999){

    }

protected:
    virtual string toN(unsigned int rnd) override {
        string res = "";

        res += to_string(rnd / 1000);
        res += to_string(rnd % 1000 / 100);
        res += to_string(rnd % 100 / 10);
        res += to_string(rnd % 10);

        return res;
    }

    virtual string getS(sex gender) override {
        return (gender == sex::man ? "2" : "1");
    }

    virtual string getN(unsigned int year, unsigned int month, unsigned int day) override {
        return toN(rndN[this->getData(year, month, day)]);
    }

    virtual string getC(string s) override {
        unsigned int summ = 0;

        for (size_t i = 0; i < s.size(); i++)
            summ += ((i + 1) * (s[i] - '0'));

        for (unsigned int i = 0; i <= 9; i++)
            if ((summ + i * (s.size() + 1)) % 10 == 0)
                return to_string(i);


        return "*";
    }

};


class templateStudentGenerator {
public:
    templateStudentGenerator() {
        generators["MIEM"] = new MIEM();
        generators["MGTU"] = new MGTU();
    }

    templateGenerator* generator(string university) const {
        auto it = generators.find(university);

        if(it != end(generators))
            return it->second;
        else
            throw runtime_error("Wrong university name");
    }

private:
    map<string, templateGenerator* > generators;
};

int main(int argc, char **argv){
    for (int i = 1; i < argc; i++)
        cout << argv[i] << " ";

    try {
        templateStudentGenerator aboba;

        unsigned int tmp;

        cout << endl <<  "Test block:" << endl << endl;
        string res = aboba.generator("MIEM")->generate(sex::man, 2002, 12, 05);
        cout << "Number for man from MIEM who was born at 2002.12.05: " << res << ". ";

        tmp = 0;
        for (size_t i = 0; i < res.size(); i++)
            tmp += ((i + 1) * (res[i] - '0'));
        cout << "Sum of multiplications of digits on their positions is " << tmp
             << ". Sum % 11 = " << tmp % 11 << endl << endl;

        res = aboba.generator("MGTU")->generate(sex::woman, 2005, 11, 25);
        cout << "Number for woman from MGTU who was born at 2005.11.25: " << res << ". ";

        tmp = 0;
        for (size_t i = 0; i < res.size(); i++)
            tmp += ((i + 1) * (res[i] - '0'));
        cout << "Sum of multiplications of digits on their positions is " << tmp
             << ". Sum % 10 = " << tmp % 10 << endl << endl << "Perfect." << endl << endl;


        bool fromfile = false, tofile = false;
        size_t ifromfile, itofile;

        string sexy, university;
        unsigned int year, month, day;


        for (int i = 1; i < argc; i++){
            if (fromfile == false && string(argv[i]) == "--fromfile" && i != argc){
                fromfile = true;
                ifromfile = i + 1;
            }
            if (tofile == false && string(argv[i]) == "--tofile" && i != argc){
                tofile = true;
                itofile = i + 1;
            }
        }

        cout << fromfile << " " << tofile << endl;

        //Ввод либо из файла, либо с клавиатуры
        if (fromfile){
            ifstream input;
            input.open(argv[ifromfile]);

            if (input)
                input >> university >> sexy >> year >> month >> day;
            else
                throw runtime_error("Wrong input file path");

            input.close();
        }
        else
        {
            cout << "University (MIEM/MGTU): ";
            cin >> university;
            cout << "Sex (man/woman): ";
            cin >> sexy;
            cout << "Birth date (YYYY MM DD): ";
            cin >> year >> month >> day;
        }

        //Проверка данных
        if (university != "MIEM" && university != "MGTU")
            throw runtime_error("Wrong university name");
        if (sexy != "man" && sexy != "woman")
            throw runtime_error("Wrong sex");
        if (month == 0 || month > 12)
            throw runtime_error("Wrong month number");
        if (day == 0 || day > 31)
            throw runtime_error("Wrong day number");

        res = aboba.generator(university)->generate((sexy == "man" ? sex::man : sex::woman), year, month, day);

        if (tofile){
            ofstream output;
            output.open(argv[itofile], ios::trunc);

            if (output)
                output << res;
            else
                throw runtime_error("Wrong output file path");

            output.close();
        }
        else
            cout << res << endl;
    }
    catch(...){
        cout << "Something's wrong...";
    }

    system("pause");

    return 0;
}
