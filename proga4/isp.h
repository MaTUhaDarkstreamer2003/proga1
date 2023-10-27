#pragma once
#include <iostream>
#include <windows.h> 
#include <fstream>
#include <string> 
#include <sstream>
#include <vector>

using namespace std;


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