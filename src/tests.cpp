#include <iostream>
#include <fstream>
#include <string>
#include "classmake.h"

int main(){

    int flag;
    int i;
    char a;
    
    std::ifstream ifs1("./testfiles/test1_ans.txt");
    std::ifstream ifs2("./testfiles/test2_ans.txt");
    std::ifstream ifs3("./testfiles/test3_ans.txt");
    
    //TEST_1
    flag = 1;
    std::string name1 = "./testfiles/test1.txt";
    std::string mas1 = prog(name1);

    for (int i = 0; i < 9; i++){
        a = ifs1.get();
                if (mas1[i] != a) {
            flag = 0;
            break;
        }
    }

    ifs1.close();
    if (flag == 1) std::cout<<"TEST_1 --> passed succesfully"<<std::endl;
    else std::cout<<"TEST_1 --> failed!"<<std::endl;
    

    //TEST_2
    flag = 1;
    std::string name2 = "./testfiles/test2.txt";
    std::string mas2 = prog(name2);

    for (int i = 0; i < 9; i++){
        a = ifs2.get();
                if (mas2[i] != a) {
            flag = 0;
            break;
        }
    }
    ifs2.close();
    if (flag == 1) std::cout<<"TEST_2 --> passed succesfully"<<std::endl;
    else std::cout<<"TEST_2 --> failed!"<<std::endl;

    //TEST_3
    flag = 1;
    std::string name3 = "./testfiles/test3.txt";
    std::string mas3 = prog(name3);

    for (int i = 0; i < 9; i++){
        a = ifs3.get();
                if (mas3[i] != a) {
            flag = 0;
            break;
        }
    }
    ifs3.close();
    if (flag == 1) std::cout<<"TEST_3 --> passed succesfully"<<std::endl;
    else std::cout<<"TEST_3 --> failed!"<<std::endl;



    return 0;
}