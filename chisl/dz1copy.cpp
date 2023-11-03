#include <iostream>
#include <cmath>
using namespace std;

float eps() {
    float eps = 1.0;
    float gnome = eps;
    while (1.0+eps != 1.0) {
        eps = eps/2;
        if (1 + eps != 1.0) {
            gnome = eps;
        }
    }
    return gnome;
}

float dwarf() {
    float dwarf = 1.0;
    float gnome = dwarf;
    while (dwarf > 0.0) {
        dwarf = gnome/2;
        if (dwarf != 0.0) {
            gnome = dwarf;
        }
    }
    return gnome;
}


float infinit() {
    float i = 1;
    float gnome = i;
    while (!isinf(i)) {
        i *= 2;
        if (!isinf(i)) {
            gnome = i;
        }
    }
    return gnome;
}


int main() {

    float a = eps();
    float b=1.0;
    if (b+a/2 == 1.0) {
        cout << "Mashinnoe epsilon float 16= " << a << endl;
    }

    a = dwarf();
    if (a/2 == 0.0) {
        cout << "Mashinnoe dwarf = " << a << endl;
    }

    a = infinit();
        cout << "Mashinnaya beskonechnost' = " << a << endl;

    return 0;
}