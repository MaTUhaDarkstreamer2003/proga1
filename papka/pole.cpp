#include <iostream>
#include <cstring>
using namespace std;

void func(char arr[], char bukva, char bolmal, int arr2[],int a)
{
    int h=0;
    for (int i=0; i<= a; i++)
    {
        if(arr[i]==bukva || arr[i]==bolmal)
        {
            if (arr2[i] == 0)
            {
                arr2[i]=1;
                h=1;
            }
            if (arr2[i] == 1)
            {
                h++;
            }
        }
    }
    //if (h>1)
    //{
      // cout<<"Uzhe bylo" ;
       //cout<<"\n"; 
    //}
    if (h==1)
    {
       cout<<"Ugadal!!!" ;
       cout<<"\n";
    }
    if (h==0)
    {
       cout<<"Net takoi bukvi!!!" ;
       cout<<"\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    setlocale(LC_ALL, "ru_RU.UTF-8");
    setlocale(LC_ALL, "");
    setlocale(0, "");
    setlocale(0, "rus");
    cout<<"Vashe slovo: ";
    string str;
    cin>>str;
    cout<<"\n";
    cout<< str <<"\n";
    char arr[str.length()];
    int arr2[str.length()];
    for (int i=0; i<=str.length(); i++)
    {
        arr2[i]=0;
    }
    cout<< str.length();
    cout<<"\n";
    for (int i=0; i< str.size(); i++)
        {
            cout<<"-";
        }
    cout<<"\n";
    str.copy(arr, str.length());
    int o=0;
    while(o!=str.size())
    {
        o=0;
        char bukva;
        char bolmal = 70;
        cout<<"Vasha bukva: ";
        cin>>bukva;
        if (bukva<93)
        {
            bolmal = bukva+32;
        }
        if (bukva>96)
        {
            bolmal = bukva-32;
        }
        cout<<"\n";
        func(arr, bukva, bolmal, arr2, str.length());
        for (int i=0; i< str.size(); i++)
        {
            if (arr2[i]==1)
            {
                cout<<arr[i];
                o++;
            }
            else
                cout<<"-";
        }
        cout<<"\n";
    }
    cout<<"Vy ugadali slovo - "<< str << " Pozdravlyau!";
    return 0;
}