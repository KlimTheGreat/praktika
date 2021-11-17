#include <iostream>
#include <fstream>

#include "menu.h"
using namespace std;

void in_rand() 
{
    cout << "\n���� ���������� �������";
    int size = get_size();
    int* a = new int[size];

    int num, max, min;
    cout << "������� �������:\n";
    cout << ">";
    cin >> min;
    cout << "\n";
    cout << "������� ��������:\n";
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

    cout << "������ �������\n";
    cout << "�������?\n";
    print_done(a, size);

    choose_method(a, size);
}


void in_cmd() 
{
    cout << "\n���� �������";
    int size = get_size();
    int* a = new int[size];
    cout << "������� �������� ���������:\n";

    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    cout << "\n������ �������\n";
    cout << "�������?\n";
    print_done(a, size);

    choose_method(a, size);
}


void in_file() 
{
    cout << "\n���� �� �����\n";
    ifstream digits;

    string file_name;

    do {

        cout << "������� ��� �����:\n";
        cout << ">";
        cin >> file_name;

        digits.open(file_name);

        if (!digits.is_open())
            cout << "���� �� ������, ���������� �����\n\n";

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

    cout << "������ �������\n";
    cout << "�������?\n";
    print_done(a, size);

    choose_method(a, size);

}