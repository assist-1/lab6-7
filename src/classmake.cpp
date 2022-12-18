#include "classmake.h"
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    std::string file_read = "";
    std::string file_write = "";

    for(int i = 1; i<argc; i++){
        if (argv[i][0]=='-' && argv[i][1]=='-' && argv[i][2]=='f' && argv[i][3]=='r' && argv[i][4]=='o' &&
        argv[i][5]=='m' && argv[i][6]=='f' && argv[i][7]=='i' && argv[i][8]=='l' && argv[i][9]=='e') {
            std::cout << "Eter the file to read name" << std::endl;
            std::cin>>file_read;
        }

        if (argv[i][0]=='-' && argv[i][1]=='-' && argv[i][2]=='t' && argv[i][3]=='o' && argv[i][4]=='f' &&
        argv[i][5]=='i' && argv[i][6]=='l' && argv[i][7]=='e') {
            std::cout << "Eter the file to write name" << std::endl;
            std::cin>>file_write;
        }
    }

    std::string token = prog(file_read);
    if(file_write != ""){
        clear(file_write);
        std::ofstream wrfile(file_write);
        wrfile << token;
        wrfile.close();
    }
    else std::cout<<"Answer: "<<std::endl<<token<<std::endl;

    return 0;
}
