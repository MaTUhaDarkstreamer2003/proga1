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
    
    string music [14]={"Master of puppets Metallica", "Брошу Pyrokinesis", "Homebody PH1","Червяк Даргомыжский","Russian Ebunny","Enemy Imagine dragons"," Зизазай Огги и тараканы","Valentine Justice","Swimming pools Kendrick Lamar","Night Call Kovinsky","Yesterday The Beatles","Так закалялась сталь Гражданская оборона","За деньги да Инстасамка","Bad habits Ed sheeran"}; 
    string movies[14]={"Короткое замыкание", "Трансформеры", "Полночь", "По соображениям совести","Джентльмены","Ван Хельсинк","Операция Ы","Драйв","Большая игра","Игра в имитацию","Всё везде и сразу","Форрест Гамп","Терминал","Не смотрите наверх"} ;
    string actors [14]={"Райан Гослинг", "Кристиан Бейл", "Джеки Чан","Эндрю Гарфилд","Леонардо ДиКаприо","Бенедикт Кембербетч","Мэтью Макконахи","Дэвид Линч","Дэниэлл Рэдклифф","Джейк Джиллехолл","Александр Петров","Рональд Рейган","Том Круз","Брэд Питт"} ;
    string actriss [14]={"Наталия Крачковская", "Меган Фокс", "Джениффер Лопез","Эмма Стоун","Эмма Уотсон","Кира Найтли","Милла Йовович","Марго Робби","Мерил Стрип","Скарлет Йоханссон","Александра Бортич","Анджелина Джоли","Шарлиз Терон","Ингеборга Дапкунайте"} ;
    string celeb [14]={"Дейв Мастейн", "Иван Зола", "Сергей Мавроди", "Екатерина Гордеева", "Роберт Опенгеймер", "Лионель Месси", "Папич", "Хидэо Кодзима", "Ляйсан Утяшева","Павел Воля","Криштиану Роналду","Борис Бурда","Ким Кардашьян","Клава Кока"};
    string ima;
    string data;
    cout<<"Ваше имя: "<< endl;

    cin>>ima;
    cout<<endl;
    cout<<"Введите дату рождения: "<< endl;
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
    cout<<"Здравствуйте, "<< ima << "!" <<endl;
    int ura [5] = {0, 0, 0, 0, 0};
    dom (ura, a); 
    cout<<"Ваша песня сегодня: "<< music [ura[0]] <<endl;
    cout<<"Фильм: "<< movies [ura[1]] <<endl;
    cout<<"Актёр: "<< actors [ura[2]] <<endl;
    cout<<"Актрисса: "<< actriss [ura[3]] <<endl;
    cout<<"Селеба: "<< celeb [ura[4]] <<endl;
    cout<<"Хорошего дня!"<< endl;
    return 0;
}