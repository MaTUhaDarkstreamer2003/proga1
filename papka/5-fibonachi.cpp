#include <iostream>
#include <vector>
#include <string>


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
    int o=0;

    while(o!=1)
    {
        vector<long long int> X = {0, 1, 1};
        cout<<"vvedite chislo";
        cout<<"\n";
        string str;
        cin>>str;
        bool is_number = true;
        for (char c : str)
        { // ïðîõîäèì ïî êàæäîìó ñèìâîëó ñòðîêè
            if (!isdigit(c))
            { // åñëè ñèìâîë íå ÿâëÿåòñÿ öèôðîé
                is_number = false; // çíà÷èò ýòî íå ÷èñëî
                break; // âûõîäèì èç öèêëà
            }
        }

        if (is_number)
        {
            int num = stoi(str);
            if(num<1)
            {
                cout << "Eto otricatelnoe chislo, vvedite chislo pobolshe";
                cout<<"\n";
            }
            if(num>100)
            {
                cout << "Eto slishkom bolshoe chislo, vvedite chislo  pomenshe";
                cout<<"\n";
            }
            else
            {
                for (int i=1; i<=num; i++)
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
        else
        {
            cout << "Eto ne chislo, vvedite chislo";
            cout<<"\n";
        }
    }
    return 0;
}
