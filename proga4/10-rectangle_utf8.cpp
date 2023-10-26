#include <iostream>
#include <windows.h> 
#include <fstream>
#include <string> 
#include <sstream>
#include <vector>

using namespace std;

class rec {
    public:
        rec (float poz1, float poz2, float dlin, float wys) {
            x = poz1;
            y = poz2;
            a = dlin;
            b = wys;
    }
        float x;
        float y;
        float a;
        float b;
};

class isp {
    public:
        isp (rec rec1, rec rec2) {
            if (rec2.x < rec1.x || rec2.y < rec1.y) {
                rec rec3 = rec2;
                rec2 = rec1;
                rec1 = rec3;
            }
            if (rec1.x+rec1.a>=rec2.x && rec1.y+rec1.b>=rec2.y) { cout << "Пересекаются"; }
            else { cout << "Непересекаются";}
        }
};

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