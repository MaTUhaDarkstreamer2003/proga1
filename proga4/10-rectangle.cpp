#include <iostream>
#include <windows.h> 
#include <fstream>
#include <string> 
#include <sstream>
#include <vector>
#include "rec.h"
#include "isp.h"
using namespace std;

int main () {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");

    vector <rec> ab;

    ifstream file("rec.txt");
    string line;
    string token;
    int count = 0;
    while (getline(file, line)) {
        stringstream iss (line);
        string token;
        int count = 0;
        int a;
        int b;
        int c;
        int d;
        while (getline(iss, token, ',')) {
            istringstream iss2(token);
            int num=0;
            if (iss2 >> num) {
                count++;
                if (count == 1) {
                    a = num;
                } else if (count == 2) {
                    b = num;
                } else if (count == 3) {
                    c = num;
                } else if (count == 4) {
                    d = num;
                }
            }
            if (count >= 4) {
                rec hop (a, b, c, d);
                ab.push_back(hop);
            }
        }
    }
    file.close();
    isp (ab[0], ab[1]);
    return 0;
}