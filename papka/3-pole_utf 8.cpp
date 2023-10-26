#include <iostream>
#include <cstring>
#include <windows.h> 
using namespace std;

void func(char arr[], char bukva, char bolmal1, char bolmal2, int arr2[],int a)
{
    int h=0;
    for (int i=0; i<= a; i++)
    {
        if(arr[i]==bukva || arr[i]==bolmal1 || arr[i]==bolmal2)
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
    if (h==1)
    {
       cout<<"РЈРіР°РґР°Р»Рё!!!" ;
       cout<<"\n";
    }
    if (h==0)
    {
       cout<<"РќРµС‚ С‚Р°РєРѕР№ Р±СѓРєРІС‹!!!" ;
       cout<<"\n";
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");
    cout<<"Р’Р°С€Рµ СЃР»РѕРІРѕ: ";
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
        cout<<"Р’Р°С€Р° Р±СѓРєРІР°: ";
        cin>>bukva;
        char bolmal1 = bukva+32;
        char bolmal2 = bukva-32;
        cout<<"\n";
        func(arr, bukva, bolmal1, bolmal2, arr2, str.length());
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
    cout<<"Р’С‹ СѓРіР°РґР°Р»Рё СЃР»РѕРІРѕ - "<< str << " Р’С‹ РјРѕР»РѕРґРµС†! РџРѕР·РґСЂР°РІР»СЏСЋ!";
    return 0;
}