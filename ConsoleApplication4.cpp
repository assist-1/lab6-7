#include "funs.h"

int main(int argc, char* argv[])
{
    bool flag1 = false, flag2 = false;
    string ofname;
    if (argc >= 3) {
        if (strcmp(argv[1], "--fromfile") == 0) flag1 = true;
        if (strcmp(argv[1], "--tofile") == 0) {
            flag2 = true;
            ofname = argv[2];
        }
    }if (argc == 5) {
        if (strcmp(argv[3], "--fromfile") == 0) flag1 = true;
        if (strcmp(argv[3], "--tofile") == 0) {
            flag2 = true;
            ofname = argv[4];
        }
    }ofstream file2(ofname);
    if (flag1){
        ifstream file(argv[2]);
        int n;
        file >> n;
        for (int i = 0; i < n; i++) {
            string name, sex;
            int y, m, d;
            file >> name >> sex >> y >> m >> d;
            if (!flag1) output1(name, sex, y, m, d);
            else output2(&file2, name, sex, y, m, d);
        }file.close();
    }
    else {
        int n;
        cin >> n;
        if (flag2) ofstream file2(ofname);
        for (int i = 0; i < n; i++) {
            string name, sex;
            int y, m, d;
            cin >> name >> sex >> y >> m >> d;
            if (!flag1) output1(name, sex, y, m, d);
            else output2(&file2, name, sex, y, m, d);
        }file2.close();
    }
}