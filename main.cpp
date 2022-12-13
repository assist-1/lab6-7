#include "classes.h"
#include <algorithm>
#include <fstream>
#include <cstring>

/** 
 * \brief Пространство имен, отвечающее за пол студентна. Используется в функциях для создания студ. билета.
*/
namespace sex{ 
    int man = 0;
    int woman = 1;
};

std::string university; //< Название университета.
std::string vsex;       //< Пол студента.
int year;  //< Год рождения.
int month; //< Месяц рождения.
int day;   //< День рождения.

/**
 * \brief Выводит в консоль справку.
 * 
 * Функция выводит справку в консоль, 
 * если пользователь неверно ввел флаги при запуске программы.
*/
void usage() {
    std::cout << std::endl;
    std::cout << "USAGE: ./prog [--tofile <file_name>] [--fromfile <file_name>]" << std::endl;
    std::cout << std::endl;
    std::cout << "-------------------------Flags meaning-----------------------" << std::endl;
    std::cout << "--tofile   ------> write output data in file"                  << std::endl;
    std::cout << "--fromfile ------> read input data from file"                  << std::endl;
    std::cout << std::endl;
}

/**
 * \brief Возвращет символ, переведенный в нижний регистр.
 * \param[in] с - символ
 * \return c - символ, переведенный в нижний регистр
*/
char to_lower(char c) { return std::tolower(c); }

/**
 * \brief Возвращет символ, переведенный в верхний регистр 
 * \param[in] с - символ
 * \return c - символ, переведенный в верхний регистр
*/
char to_upper(char c) { return std::toupper(c); }

/**
 * \brief Проверяет введные пользователем данные на корректность.
 * \return 0 - функция выполнена успешно
 * \return 1 - обнаружена ошибка
*/
int check_input() {
    if (university != "MIEM" && university != "MGTUU") {
        std::cerr << "##### Wrong name of university #####\n";
        return 1;
    }

    if (vsex != "man" && vsex != "woman") {
        std::cerr << "##### Wrong sex #####\n";
        return 1;
    }

    if (year < 1900 || year > 5000) {
        std::cerr << "##### Wrong year of birthday #####\n";
        return 1;
    }
    if (month < 1 || month > 12) {
        std::cerr << "##### Wrong month of birthday #####\n";
        return 1;
    }
    if (day < 1 || day > 31) {
        std::cerr << "##### Wrong day of birthday #####\n";
        return 1;
    }

    return 0;
}

/**
 * \brief Считывает данные из потока cin и записывает их в глобальные переменные.
 * \return 0 - функция выполнена успешно
 * \return 1 - обнаружена ошибка
*/
int read() {
    std::cin >> university;
    std::transform(university.begin(), university.end(), university.begin(), to_upper);
    std::cin >> vsex;
    std::transform(vsex.begin(), vsex.end(), vsex.begin(), to_lower);
    std::cin >> year >> month >> day;

    if (check_input()) return 1;
    return 0;
}

/**
 * \brief Считывает данные из файла и записывает их в глобальные переменные.
 * \param[in] filename - имя файла
 * \return 0 - функция выполнена успешно
 * \return 1 - обнаружена ошибка
*/
int read(std::string filename) {
    std::ifstream file (filename);
    if (!file.is_open()) {
        std::cerr << "##### Wrong name of file #####\n";
        return 1;
    }

    std::getline(file, university);
    std::transform(university.begin(), university.end(), university.begin(), to_upper);
    std::getline(file, vsex);
    std::transform(vsex.begin(), vsex.end(), vsex.begin(), to_lower);
    file >> year >> month >> day;

    file.close();

    if (check_input()) return 1;
    return 0;
}

/**
 * \brief Выводит результат в поток cout.
 * \param[in] t - номер билета, который необходимо вывести
*/
void print(std::string t) { std::cout << "Ticket is " << t << std::endl; }

/**
 * \brief Выводит результат в файл.
 * \param[in] t - номер билета, который необходимо вывести
 * \param[in] filename - имя файла
*/
void print(std::string t, std::string filename) {
    std::ofstream file (filename);
    file << "Ticket is " << t << '\n';
    file.close();
}

/**
 * \brief Генерирует номер билета на основе введенных данных.
 * \return ticket - номер билета
 * 
 * В функции создается объект класса TicketGenerator, при помощи которого, в зависимости
 * от введных данных, генерируется номер студ. билета.
*/
std::string generate_ticket() {
    TicketGenerator ticket_generator;
    std::string ticket;
    if (vsex == "man")
        ticket = ticket_generator.generator(university)->generate(sex::man, year, month, day);
    else
        ticket = ticket_generator.generator(university)->generate(sex::woman, year, month, day);
    return ticket;
}

/**
 * \brief Обрабатывает параметры запуска.
 * \param[in] argc - количество параметров запуска
 * \param[in] argv - список параметров запуска
 * \return 0 - функция выполнена успешно
 * \return 1 - обнаружена ошибка
 *
 * В зависимости от введеных при запуске флагов определяет, откуда будут поступать данные, 
 * и куда их потом нужно будет вывести. Флаг --tofile сообщает, что вывод будет производиться
 * в файл, после него указывается имя файла. Флаг --fromfile сообщает, что ввод будет производиться 
 * из файла, после него указывается имя файла. Возможна обработка обоих флагов одновременно.
 * Если во время выполнения произошла ошибка, то выведется ошибка, и программа закончит выполнение 
 * с кодом 1, иначе с кодом 0.
 */
int main(int argc, char ** argv) { 
    std::string ticket;  
    switch (argc) {
    case 1:
        if (read()) exit(1);
        ticket = generate_ticket();
        print(ticket);
        break;
    case 3:
        if (!strcmp(argv[1], "--fromfile")) {
            if (read(argv[2])) exit(1);
            ticket = generate_ticket();
            print(ticket);
        }
        else if (!strcmp(argv[1], "--tofile")) {
            if (read()) exit(1);
            ticket = generate_ticket();
            print(ticket, argv[2]);
        }
        else {
            std::cerr << "##### Wrong flags #####\n";
            usage();
            exit(1);
        }
        break;
    case 5:
        if (!strcmp(argv[1], "--tofile") && !strcmp(argv[3], "--fromfile")) {
            if (read(argv[4])) exit(1);
            ticket = generate_ticket();
            print(ticket, argv[2]);
        }
        else if  (!strcmp(argv[3], "--tofile") && !strcmp(argv[1], "--fromfile")) {
            if (read(argv[2])) exit(1);
            ticket = generate_ticket();
            print(ticket, argv[4]);
        }
        else {
            std::cerr << "##### Wrong flags #####\n";
            usage();
            exit(1);
        }
        break;
    default:
        std::cerr << "##### Wrong flags #####\n";
        usage();
        exit(1);
        break;
    }

    return 0;
}
