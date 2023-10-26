#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <math.h>

using namespace std;

long long int fib(int i)
{
    if (i==1 || i==2)
        return 1;
    else
        return fib(i-1)+fib(i-2);
}

void fibb (vector<long long int>& X, int d)
{
    vector <long long int> Y = X;
    X.push_back(Y[d-1]+Y[d-2]);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");
    int o=0;

    while(o!=1)
    {
        vector<long long int> X = {0, 1, 1};
        cout<<"Введите число";
        cout<<"\n";
        string str;
        cin>>str;
        bool is_number = true;
        double n;
        try
        {   
            n = stod(str);
            if (n > floor(n))
            {
                cout << "Вы ввели нецелое число\n";
            }
            else if (n < 0)
            {
                cout << "Вы ввели отрицательное число\n";
            }
            else if (n > 100000)
            {
                cout << "Вы ввели слишком большое число\n";
            }
            else
            {
                int y = n;
                for (int i=1; i<=y; i++)
                {
                    if (i>2)
                    {    
                        fibb(X, X.size());
                    }
                    cout<< X[i]<< " "; 
                }
                cout<<"\n";
                o=1;
            }
        }
        catch(invalid_argument)
        {
            cout << "Вы ввели строку\n";
        }
        catch(out_of_range)
        {
            cout << "Вы ввели слишком большое число\n";
        }

    }
    return 0;
}
