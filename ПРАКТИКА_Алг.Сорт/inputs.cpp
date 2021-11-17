#include <iostream>
#include <fstream>

#include "menu.h"
using namespace std;

void in_rand() 
{
    cout << "\nВвод случайными числами";
    int size = get_size();
    int* a = new int[size];

    int num, max, min;
    cout << "Введите минимум:\n";
    cout << ">";
    cin >> min;
    cout << "\n";
    cout << "Введите максимум:\n";
    cout << ">";
    cin >> max;
    cout << "\n";

    srand(time(0));
    if (min < 0) {
        max = max - min + 1;
    }
    for (int i = 0; i < size; i++)
    {
        num = (min + rand() % (max + 1));
        a[i] = num;
    }

    cout << "Массив получен\n";
    cout << "Вывести?\n";
    print_done(a, size);

    choose_method(a, size);
}


void in_cmd() 
{
    cout << "\nВвод вручную";
    int size = get_size();
    int* a = new int[size];
    cout << "Введите элементы построчно:\n";

    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    cout << "\nМассив получен\n";
    cout << "Вывести?\n";
    print_done(a, size);

    choose_method(a, size);
}


void in_file() 
{
    cout << "\nВвод из файла\n";
    ifstream digits;

    string file_name;

    do {

        cout << "Введите имя файла:\n";
        cout << ">";
        cin >> file_name;

        digits.open(file_name);

        if (!digits.is_open())
            cout << "Файл не найден, попробуйте снова\n\n";

    } while (!digits.is_open());

    int size = get_size();
    int* a = new int[size];
    int n = 0;

    int number;
    while (!digits.eof())
    {
        digits >> a[n];
        n++;

        if (n == size)
            break;
    }

    cout << "Массив получен\n";
    cout << "Вывести?\n";
    print_done(a, size);

    choose_method(a, size);

}