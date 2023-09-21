#include <iostream>
#include <string>


using namespace std;

long long int fact(int i)
{
    if (i==0)
        return 1;
    else
        return i*fact(i-1);
}

int main()
{
    int o=0;

    while(o!=1)
    {
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
            if(num<0)
            {
                cout << "Eto otricatelnoe chislo, vvedite chislo pobolshe";
                cout<<"\n";
            }
            if(num>100000)
            {
                cout << "Eto slishkom bolshoe chislo, vvedite chislo  pomenshe";
                cout<<"\n";
            }
            else
            {
                cout<< fact(num);
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
