#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <cstdlib> 
#include <ctime>  
#include <windows.h> 
 
using namespace std;

int rez() { 
    int arr[3] = { 0, 11111111, 22222222 }; 
    srand(time(NULL)); 
    int i = rand() % 3; 
    return arr[i];

}


void dom(int ura [5], int a[8]) 
{
    int g=0;
    for (int i = 0; i < 8; i++)
    {
        g+=a[i];
    }

    int me = 10*a[2] + a[3];

    int hop = pow (g, me);
    int y;
    y = rez();
    hop += y;
    ura [0] = hop & 0b1111;
    ura [1] = (hop >> 4) & 0b1111;
    ura [2] = (hop >> 8) & 0b1111;
    ura [3] = (hop >> 12) & 0b1111;
    ura [4] = (hop >> 16) & 0b1111;
    for (int i = 0; i < 5; i++)
    {
        ura [i]= ura [i] % 14;
    } 
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    string music [14]={"Master of puppets Metallica", "����� Pyrokinesis", "Homebody PH1","������ ������������","Russian Ebunny","Enemy Imagine dragons"," ������� ���� � ��������","Valentine Justice","Swimming pools Kendrick Lamar","Night Call Kovinsky","Yesterday The Beatles","��� ���������� ����� ����������� �������","�� ������ �� ����������","Bad habits Ed sheeran"}; 
    string movies[14]={"�������� ���������", "������������", "�������", "�� ������������ �������","�����������","��� ��������","�������� �","�����","������� ����","���� � ��������","�� ����� � �����","������� ����","��������","�� �������� ������"} ;
    string actors [14]={"����� �������", "�������� ����", "����� ���","����� �������","�������� ��������","�������� ����������","����� ���������","����� ����","������� ��������","����� ����������","��������� ������","������� ������","��� ����","���� ����"} ;
    string actriss [14]={"������� �����������", "����� ����", "��������� �����","���� �����","���� ������","���� ������","����� �������","����� �����","����� �����","������� ���������","���������� ������","��������� �����","������ �����","��������� ����������"} ;
    string celeb [14]={"���� �������", "���� ����", "������ �������", "��������� ��������", "������ ����������", "������� �����", "�����", "����� �������", "������ �������","����� ����","��������� �������","����� �����","��� ���������","����� ����"};
    string ima;
    string data;
    cout<<"���� ���: "<< endl;

    cin>>ima;
    cout<<endl;
    cout<<"������� ���� ��������: "<< endl;
    cin >> data;
    int a [8];
    a[0] = data[0] - 48;
    a[1] = data[1] - 48;
    a[2] = data[3] - 48;
    a[3] = data[4] - 48;
    a[4] = data[6] - 48;
    a[5] = data[7] - 48;
    a[6] = data[8] - 48;
    a[7] = data[9] - 48;
    int ch = 10*a[0] + a[1];
    int me = 10*a[2] + a[3];
    int god = 1000 * a[4] + 100 * a[5] + 10 * a[6] + a[7];
    cout<<"������������, "<< ima << "!" <<endl;
    int ura [5] = {0, 0, 0, 0, 0};
    dom (ura, a); 
    cout<<"���� ����� �������: "<< music [ura[0]] <<endl;
    cout<<"�����: "<< movies [ura[1]] <<endl;
    cout<<"����: "<< actors [ura[2]] <<endl;
    cout<<"��������: "<< actriss [ura[3]] <<endl;
    cout<<"������: "<< celeb [ura[4]] <<endl;
    cout<<"�������� ���!"<< endl;
    return 0;
}