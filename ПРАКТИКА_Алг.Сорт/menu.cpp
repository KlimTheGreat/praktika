#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>

#include "sortirovka.h"
using namespace std;


void print_menu() 
{
    system("cls"); // ������� �����
    cout << "------��������� ���������� ����������------\n\n";
    cout << "�������� ������� �����:\n";
    cout << "1. ��������� �����\n";
    cout << "2. � ����������\n";
    cout << "3. �� �����\n";
    cout << "4. �����\n";
    cout << ">";
}


int get_variant(int count) 
{
    int variant;
    string s; // ������ ��� ���������� �������� ������
    getline(cin, s);

    // ���� ���� �����������, �������� �� ���� � ������ ��������� ���
    while (sscanf_s(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
        cout << "�������� ����. ���������� �����\n"; // ������� ��������� �� ������
        cout << ">";
        getline(cin, s); // ��������� ������ ��������
    }

    return variant;
}


int get_size() 
{
    cout << "\n������� ����� �������:\n";
    cout << ">";
    int n;
    cin >> n;
    cout << "\n";
    return n;
}


void print_mass(int* a, int size) 
{
    for (int i = 0; i < size; i++)
        cout << "  " << a[i];
    cout << "\n";
}


void print_done(int* a, int size) 
{
    cout << "1. ��\n";
    cout << "2. ���\n";
    cout << ">";
    if (get_variant(2) == 1) {
        cout << "\n���������� ������:\n";
        print_mass(a, size);
    }
}


void choose_method(int* a, int size) 
{
    cout << "\n�������� ������ ����������:\n";
    cout << "1. �������� �������� ����� ���������\n";
    cout << "2. ���������� ��������\n";
    cout << "3. ������� ����������\n";
    cout << "4. ���������� ���������\n";
    cout << ">";

    clock_t start;
    clock_t end;
    double mergeSort_time;
    double quickSort_time;
    double insertSort_time;
    int* a1 = new int[size];
    int* a2 = new int[size];
    int* a3 = new int[size];

    switch (get_variant(4)) {
    case 1:
        for (int i = 0; i < size; i++) {
            a1[i] = a[i];
            a2[i] = a[i];
            a3[i] = a[i];
        }

        start = clock();
        mergeSort(a1, 0, size - 1); // ���������� ���������� ��������
        end = clock();
        mergeSort_time = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        quickSort(a2, 0, size - 1); // ������� ����������
        end = clock();
        quickSort_time = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        insertSort(a3, size); // ���������� ���������
        end = clock();
        insertSort_time = (double)(end - start) / CLOCKS_PER_SEC;

        // ����� ��������������� ��������
        Sleep(100);
        cout << "\n���������� ��������: �������\n";
        cout << "����� ������: " << mergeSort_time << " ���\n";

        Sleep(100);
        cout << "\n������� ����������: �������\n";
        cout << "����� ������: " << quickSort_time << " ���\n";

        Sleep(100);
        cout << "\n���������� ���������: �������\n";
        cout << "����� ������: " << insertSort_time << " ���\n";

        Sleep(100);
        cout << "\n������� ��������������� ������?\n";
        print_done(a1, size);

        break;

    case 2:
        start = clock();
        mergeSort(a, 0, size - 1); // ���������� ���������� ��������
        end = clock();
        mergeSort_time = (double)(end - start) / CLOCKS_PER_SEC;

        Sleep(100);
        cout << "\n���������� ��������:\n";
        if (mergeSort_time > 0)
            cout << "����� ������: " << mergeSort_time << " ���\n";
        else
            cout << "����� ������: " << "< 0.001" << " ���\n";

        Sleep(100);
        cout << "\n������� ��������������� ������?\n";
        print_done(a, size);

        break;

    case 3:
        start = clock();
        quickSort(a, 0, size - 1); // ������� ����������
        end = clock();
        quickSort_time = (double)(end - start) / CLOCKS_PER_SEC;

        Sleep(100);
        cout << "\n������� ����������:\n";
        if (quickSort_time > 0)
            cout << "����� ������: " << quickSort_time << " ���\n";
        else
            cout << "����� ������: " << "< 0.001" << " ���\n";

        Sleep(100);
        cout << "\n������� ��������������� ������?\n";
        print_done(a, size);

        break;

    case 4:
        start = clock();
        insertSort(a, size); // ���������� ���������
        end = clock();
        insertSort_time = (double)(end - start) / CLOCKS_PER_SEC;

        Sleep(100);
        cout << "\n���������� ���������:\n";
        if (insertSort_time > 0)
            cout << "����� ������: " << insertSort_time << " ���\n";
        else
            cout << "����� ������: " << "< 0.001" << " ���\n";

        Sleep(100);
        cout << "\n������� ��������������� ������?\n";
        print_done(a, size);

        break;

    }

    cout << "\n";
}