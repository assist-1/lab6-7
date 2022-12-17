#include <iostream>
#include "class.h"
#include <cstring>
#include <string>
const char* flags[2] = {"--fromfile","--tofile"};
int main(int argc, char* argv[])
{
    if (argc == 1) Menu();
    if (argc == 2)
    {
        if (!strcmp(argv[1],flags[0])) FromMenu();

        else if (!strcmp(argv[1],flags[1])) ToMenu();
        else Menu();
    }
    if (argc == 3)
    {
        char* namefile = argv[2];
        if (!strcmp(argv[1],flags[1]))
        {
            ToFile(namefile);
        }
    }
}
