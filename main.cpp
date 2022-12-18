#include <iostream>
#include "class.h"
#include <cstring>
#include <string>
using std::cout;
using std::cerr;
using std::endl;
const char* flags[2] = {"--fromfile","--tofile"};
int main(int argc, char* argv[])
{
    if (argc == 1) Menu();
    else if (argc == 2)
    {
        if (!strcmp(argv[1],flags[0])) FromMenu();

        else if (!strcmp(argv[1],flags[1])) ToMenu();
        else
        {
            cout << "Wrong flags" << endl;
            Menu();
        }
    }
    else if (argc == 3)
    {
        char* namefile = argv[2];
        if (!strcmp(argv[1],flags[1]))
        {
            ToFile(namefile);
        }
        else if (!strcmp(argv[1],flags[0]))
        {
            FromFile(namefile);
        }
        else
        {
            cerr << "Wrong flags" << endl;
            Menu();
        }
    }
    else if (argc == 5)
    {
        char *in_file = argv[2];
        char *to_file = argv[4];
        if ((!strcmp(argv[1],flags[0])) && (!strcmp(argv[3], flags[1]))) FromToFile(in_file,to_file);
        else
        {
            cerr << "Entered Error" << endl;
            FromToMenu();
        }
    }
    else
    {
        cerr << "You entered wrong count of flags" << endl;
        Menu();
    }
}

