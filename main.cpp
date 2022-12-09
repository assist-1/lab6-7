#include "classes.h"

namespace sex{
    int man = 0;
    int woman = 1;
};

int main() {   
    TicketGenerator ticket_generator;
    std::string result = ticket_generator.generator("MIEM")->generate(sex::man, 2004, 5, 8); 
    return 0;
}
