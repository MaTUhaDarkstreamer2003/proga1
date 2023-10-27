#pragma once
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