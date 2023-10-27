#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class game {
    public:
        game();
        void play();
    private:
        vector <string> fraz;
        string slovo();
        void checkLetter(char letter);
        string word;
        vector<bool> guessedLetters;
};
#endif