#include "classes.h"

/**
 * \brief Генерирует номер студ. билета МГТУУ на основе пола и даты рождения студента.
 * \param[in] sex - пол (1 - женский, 0 - мужской)
 * \param[in] y - год рождения
 * \param[in] m - месяц рождения
 * \param[in] d - день рождения
 * \return ticket - номер студ. билета.
 * 
 * Первая цифра билета зависит от пола. Затем к ней добавляется дата рождения (г, м, д).
 * После чего генерируется 5-изначное случайное число. Если число при делении на 10 дает нечетный остаток,
 * то заменяется вторая цифра случайного числа, пока остаток не станет четным. После чего подбирается последняя цифра.
*/
std::string MGTUU::generate(int sex, int y, int m, int d) {
    std::string ticket = "";
    if (!sex) {
        ticket += std::to_string(man);
        sum += man;
    }
    else {
        ticket += std::to_string(woman);
        sum += woman;
    }

    ticket += std::to_string(y * 10000 + m * 100 + d);
    for (int i = 1; i < ticket.size(); ++i) {
        sum += (ticket[i] - '0') * (i + 1);
    }

    int date = y + m + d;

    std::mt19937 gen(date); 
    std::uniform_int_distribution<> distr(1000, 9999);
    std::string id = std::to_string(distr(gen));

    for (int i = 0; i < id.size(); ++i)
        sum += (id[i] - '0') * (i + 10);

    while ((sum % mult) % 2 == 1) {
        sum -= id[1] * 11;
        int new_d = (id[1] - '0' + 1) % 10;
        char new_dc = new_d + '0';
        std::cout <<"d " << new_d << ' ' << new_dc << std::endl;
        id = {id[0], new_dc, id[2], id[3]};
        sum += id[1] * 11;
        std::cout << "s " << sum << ' ' << sum % 10 << std::endl;
    }

    ticket += id;

    int ost = sum % mult;
    for (int i = 0; i < 10; i++) {
        if ((ost + (i * 14) % mult) % mult == 0) {
            ost = 0;
            ticket += std::to_string(i);
            break;
        }
    }

    return ticket;
}

/**
 * \brief Генерирует номер студ. билета МИЭМ на основе пола и даты рождения студента.
 * \param[in] sex - пол (1 - женский, 0 - мужской)
 * \param[in] y - год рождения
 * \param[in] m - месяц рождения
 * \param[in] d - день рождения
 * \return ticket - номер студ. билета.
 * 
 * Первая цифра билета зависит от пола. Затем к ней добавляется дата рождения (г, м, д).
 * После чего генерируется 4-хзначное случайное число. Если число при делении на 11 дает остаток 10,
 * то заменяется третья цифра случайного числа, пока остаток равен 10. После чего подбирается последняя цифра.
*/
std::string MIEM::generate(int sex, int y, int m, int d) {
    std::string ticket = "";
    if (!sex) {
        ticket += std::to_string(man);
        sum += man;
    }
    else {
        ticket += std::to_string(woman);
        sum += woman;
    }

    ticket += std::to_string(y * 10000 + m * 100 + d);
    for (int i = 1; i < ticket.size(); ++i) {
        sum += (ticket[i] - '0') * (i + 1);
    }

    int date = y + m + d;
    
    std::mt19937 gen(date); 
    std::uniform_int_distribution<> distr(10000, 99999);
    std::string id = std::to_string(distr(gen));

    for (int i = 0; i < id.size(); ++i)
        sum += (id[i] - '0') * (i + 10);

    while (sum % mult == 4) {
        sum -= id[2] * 12;
        int new_d = (id[2] - '0' + 1) % 10;
        char new_dc = new_d + '0';
        id = {id[0], id[1], new_dc, id[3], id[4]};
        sum += id[2] * 12;
    }

    ticket += id;

    int ost = sum % mult;
    for (int i = 0; i < 10; i++) {
        if ((ost + (i * 15) % mult) % mult == 0) {
            ost = 0;
            ticket += std::to_string(i);
            break;
        }
    }

    return ticket;
}


/**
 * \brief Возвращает объект класса MIEM или MGTUU, в зависимости от переданного аргумента.
 * \param[in] name - название университета
 * \return university - объект класса MIEM или MGTUU 
*/
University* TicketGenerator::generator(std::string name) {
    if (name == "MIEM") {
        MIEM* university = new MIEM;
        return university;
    }
    MGTUU* university = new MGTUU;
    return university;
}
