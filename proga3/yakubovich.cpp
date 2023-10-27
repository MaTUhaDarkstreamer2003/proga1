#include <iostream>
#include <cstring>
#include <vector>
#include <windows.h> 
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <string> 
#include <sstream>
#include "yakubovich.h"
#include "game.h"


using namespace std;

yakobovich::yakobovich() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");
    ifstream file("fraz1.txt");
    if (file.is_open()) {
    string line;
    while (getline(file, line)) {
            fraz.push_back(line);
    }
    file.close();
    }
}

void yakobovich::start() {
    cout << fraz[0];
    cin >> yn;

    cout << "\n";
    if (yn == fraz[1])
    {
        exit(0);
    }
    game lama;
    lama.play();
    while(true) {
    cout << fraz[2];
    cin >> yn;

    cout << "\n";
    if (yn == fraz[1]) {
        exit(0);
    }
    lama.play();    
    }
}