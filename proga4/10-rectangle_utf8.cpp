#include <iostream>
#include <windows.h> 
#include <fstream>
#include <string> 
#include <sstream>
#include <vector>

using namespace std;

class rec {
    public:
        rec (float poz1, float poz2, float dlin, float wys): x{poz1}, y{poz2}, a{dlin}, b{wys} {
    }

        float x;
        float y;
        float a;
        float b;
};

class isp {
    public:
        isp (rec rec1, rec rec2): X{rec1}, Y{rec2} {
            if (Y.x < X.x || Y.y < X.y) {
                rec rec3 = Y;
                Y = X;
                X = rec3;
            }
            if (X.x+X.a>=Y.x && Y.y+X.b>=Y.y) { cout << "Пересекаются"; }
            else { cout << "Непересекаются";}
        }
    private:
        rec X;
        rec Y;
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