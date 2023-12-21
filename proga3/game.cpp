#include <iostream>
#include <cstring>
#include <vector>
#include <windows.h> 
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <string> 
#include <sstream>
#include "game.h"


using namespace std;

game::game() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");
        ifstream file("fraz.txt");
        if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            fraz.push_back(line);
        }
        file.close();
        }
}

void game::play() {
    word = slovo();
    guessedLetters.resize(word.length(), false);
    for (int i = 0; i < word.length(); i++) {
        guessedLetters[i] = false;
    }
    cout << word.length() << "\n";
    for (int i = 0; i < word.size(); i++) {
        cout << "-";
    }
    cout << "\n";
    int o = 0;
    while (o != word.size()) {
        o = 0;
        string ugadaika;
        char letter;
        int count = 0;
        while (true) {
            try {
                cout << fraz[0];
                cin >> ugadaika;
                cout << "\n";
                if (ugadaika.length() > 1) {
                    throw runtime_error(fraz[1]);
                }
                break;  // Если ввод корректен, прерываем цикл
            }
            catch (const exception& e) {
                cout << e.what() << endl;
                ++count;
                if (count == 9) {
                    cout << fraz[2] << endl;
                }
                if (count == 10) {
                    exit(0);
                }
            }
        }
        letter = ugadaika.at(0);
        checkLetter(letter);
        for (int i = 0; i < word.size(); i++) {
            if (guessedLetters[i]) {
                cout << word[i];
                o++;
            }
            else {
                cout << "-";
            }
        }
        cout << endl;
    }
    cout << fraz[3] << word << fraz[4] << endl;
    guessedLetters.resize(word.length(), false);
}

string game::slovo() {  
vector<string> words;
ifstream file("slova.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = 0;
            string token;
            while ((pos = line.find(", ")) != string::npos) {
                token = line.substr(0, pos);
                words.push_back(token);
                line.erase(0, pos + 2);
            }
            words.push_back(line);
        }
        file.close();
    }
    srand(time(NULL)); 
    int i = rand() % (size(words)); 
    return words[i];
}

void game::checkLetter(char letter) {
    int count = 0;
    int cock = 0;
    for (int i = 0; i <= word.length(); i++) {
        if (word[i] == letter) {
            if (!guessedLetters[i]) {
                guessedLetters[i] = true;
                count++;
            } else 
            {
                cock++;
            }
        }
    }
    if (cock==0) {
        if (count == 1) {
            cout << fraz[5] << endl;
        }
        if (count == 0) {
            cout << fraz[6] << endl;
        }
        if (count > 1) {
            cout << fraz[7] << count << fraz[8] << endl;
        } 
    } else {
        cout << fraz[9]<< endl;
    }
    count = 0;
    cock = 0;
}
