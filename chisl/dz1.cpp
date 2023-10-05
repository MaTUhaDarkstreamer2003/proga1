#include <iostream>
#include <cmath>
using namespace std;

double eps() {
    double eps = 1.0;
    double gnome = eps;
    while (1.0+eps > 1.0) {
        eps = gnome/2;
        if (1 + eps != 1.0) {
            gnome = eps;
        }
    }
    return gnome;
}

double dwarf() {
    double dwarf = 1.0;
    double gnome = dwarf;
    while (dwarf > 0.0) {
        dwarf = gnome/2;
        if (dwarf != 0.0) {
            gnome = dwarf;
        }
    }
    return gnome;
}


double infinit() {
    double i = 1;
    double gnome = i;
    while (!isinf(i)) {
        i *= 2;
        if (!isinf(i)) {
            gnome = i;
        }
    }
    return gnome;
}


int main() {

    double a = eps();
    double b=1.0;
    if (b+a/2 == 1.0) {
        cout << "Mashinnoe epsilon = " << a << endl;
    }

    a = dwarf();
    if (a/2 == 0.0) {
        cout << "Mashinnoe dwarf = " << a << endl;
    }

    a = infinit();
        cout << "Mashinnaya beskonechnost' = " << a << endl;

    return 0;
}