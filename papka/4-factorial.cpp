#include <iostream>
#include <string>
#include <math.h>

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
        cout<<"������� �����";
        cout<<"\n";
        string str;
        cin>>str;
        double n;
        try
        {   
            n = stod(str);
            if (n > floor(n))
            {
                cout << "�� ����� ������� �����\n";
            }
            else if (n < 0)
            {
                cout << "�� ����� ������������� �����\n";
            }
            else if (n > 100000)
            {
                cout << "�� ����� ������� ������� �����\n";
            }
            else
            {
                cout<< fact(n);
                cout<<"\n";
                o=1;
            }
        }
        catch(invalid_argument)
        {
            cout << "�� ����� ������\n";
        }
        catch(out_of_range)
        {
            cout << "�� ����� ������� ������� �����\n";
        }
    }
    return 0;
}