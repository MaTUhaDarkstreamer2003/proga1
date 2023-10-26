#include <iostream>
#include <sstream>
#include <vector>
#include <windows.h> 
#include <algorithm>

using namespace std;

void printCombination(int s, int n, vector<int> nel, vector<int> combination, int currSum, int startNum) {
    // Если мы нашли комбинацию из n чисел, дающих сумму s, то выводим ее и выходим из функции.
    if (n == 0 && currSum == s) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    // Перебираем числа от startNum до 9.
    for (int i = startNum; i <= 9; i++) {
        // Если i не входит в вектор nel, то добавляем его в combination и вызываем функцию рекурсивно,
        // уменьшая количество оставшихся чисел на 1 и увеличивая текущую сумму на i.
        if (find(nel.begin(), nel.end(), i) == nel.end()) {
            combination.push_back(i);
            printCombination(s, n - 1, nel, combination, currSum + i, i + 1);
            combination.pop_back(); // Удаляем последний элемент из combination перед следующей итерацией цикла.
        }
    }
}

// Функция для вызова printCombination с начальными параметрами.
void findCombinations(int s, int n, vector<int> nel) {
    vector<int> combination;
    printCombination(s, n, nel, combination, 0, 1);
}

void astolfo () {
    int n = 0;
    int s = 0;
    vector<int> nel;
    string input;
    getline(cin, input);
    istringstream iss(input);
    string token;
    int count = 0;
    while (getline(iss, token, ',')) {
        istringstream iss2(token);
        int num;
        if (iss2 >> num) {
            count++;
            if (count == 1) {
                s = num;
            } else if (count == 2) {
                n = num;
            } else {
                nel.push_back(num);
            }
        }
    }
    cout << "n = " << n << ", s = " << s << ", nel = [";
    for (int i = 0; i < nel.size(); i++) {
        cout << nel[i];
        if (i != nel.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    findCombinations(s, n, nel);
}


int main () {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");
    cout << "Начнём" << endl;
    cout << "Ну пиши тут сумму, которая нужна, количство свободных клеточек и запрещённые цифры всё через запятые" << endl;
    cout << "Напишешь не цифры оно просто не защитается" << endl;
    astolfo();
    while (true) {
        string yn;
        cout << "Надо ещё? (да / нет)" << endl;
        getline(cin, yn);
        if (yn == "да" || yn == "ДА" || yn == "Да" || yn == "дА" || yn == "yes" || yn == "Yes" || yn == "YEs" || yn == "YES") {
            cout << "Ну пиши тут сумму, которая нужна, количство свободных клеточек и запрещённые цифры всё через запятые" << endl;
            astolfo();
        } else if (yn == "нет" || yn == "НЕТ" || yn == "Нет" || yn == "НЕт" || yn == "NO" || yn == "no" || yn == "No" || yn == "nO") {
            cout << "Ну нет так нет" << endl;
            break;
        }
        } 
    return 0;
}