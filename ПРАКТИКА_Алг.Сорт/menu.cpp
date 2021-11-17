#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>

#include "sortirovka.h"
using namespace std;


void print_menu() 
{
    system("cls"); // очищаем экран
    cout << "------СРАВНЕНИЕ АЛГОРИТМОВ СОРТИРОВКИ------\n\n";
    cout << "Выберите вариант ввода:\n";
    cout << "1. Случайные числа\n";
    cout << "2. С клавиатуры\n";
    cout << "3. Из файла\n";
    cout << "4. Выход\n";
    cout << ">";
}


int get_variant(int count) 
{
    int variant;
    string s; // строка для считывания введённых данных
    getline(cin, s);

    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf_s(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
        cout << "Неверный ввод. Попробуйте снова\n"; // выводим сообщение об ошибке
        cout << ">";
        getline(cin, s); // считываем строку повторно
    }

    return variant;
}


int get_size() 
{
    cout << "\nВведите длину массива:\n";
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
    cout << "1. Да\n";
    cout << "2. Нет\n";
    cout << ">";
    if (get_variant(2) == 1) {
        cout << "\nПолученный массив:\n";
        print_mass(a, size);
    }
}


void choose_method(int* a, int size) 
{
    cout << "\nВыберите способ сортировки:\n";
    cout << "1. Сравнить скорость тремя способами\n";
    cout << "2. Сортировка слиянием\n";
    cout << "3. Быстрая сортировка\n";
    cout << "4. Сортировка вставками\n";
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
        mergeSort(a1, 0, size - 1); // сортировка нисходящим слиянием
        end = clock();
        mergeSort_time = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        quickSort(a2, 0, size - 1); // быстрая сортировка
        end = clock();
        quickSort_time = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        insertSort(a3, size); // сортировка вставками
        end = clock();
        insertSort_time = (double)(end - start) / CLOCKS_PER_SEC;

        // вывод отсортированных массивов
        Sleep(100);
        cout << "\nСортировка слиянием: успешно\n";
        cout << "Время работы: " << mergeSort_time << " сек\n";

        Sleep(100);
        cout << "\nБыстрая сортировка: успешно\n";
        cout << "Время работы: " << quickSort_time << " сек\n";

        Sleep(100);
        cout << "\nСортировка вставками: успешно\n";
        cout << "Время работы: " << insertSort_time << " сек\n";

        Sleep(100);
        cout << "\nВывести отсортированный массив?\n";
        print_done(a1, size);

        break;

    case 2:
        start = clock();
        mergeSort(a, 0, size - 1); // сортировка нисходящим слиянием
        end = clock();
        mergeSort_time = (double)(end - start) / CLOCKS_PER_SEC;

        Sleep(100);
        cout << "\nСортировка слиянием:\n";
        if (mergeSort_time > 0)
            cout << "Время работы: " << mergeSort_time << " сек\n";
        else
            cout << "Время работы: " << "< 0.001" << " сек\n";

        Sleep(100);
        cout << "\nВывести отсортированный массив?\n";
        print_done(a, size);

        break;

    case 3:
        start = clock();
        quickSort(a, 0, size - 1); // быстрая сортировка
        end = clock();
        quickSort_time = (double)(end - start) / CLOCKS_PER_SEC;

        Sleep(100);
        cout << "\nБыстрая сортировка:\n";
        if (quickSort_time > 0)
            cout << "Время работы: " << quickSort_time << " сек\n";
        else
            cout << "Время работы: " << "< 0.001" << " сек\n";

        Sleep(100);
        cout << "\nВывести отсортированный массив?\n";
        print_done(a, size);

        break;

    case 4:
        start = clock();
        insertSort(a, size); // сортировка вставками
        end = clock();
        insertSort_time = (double)(end - start) / CLOCKS_PER_SEC;

        Sleep(100);
        cout << "\nСортировка вставками:\n";
        if (insertSort_time > 0)
            cout << "Время работы: " << insertSort_time << " сек\n";
        else
            cout << "Время работы: " << "< 0.001" << " сек\n";

        Sleep(100);
        cout << "\nВывести отсортированный массив?\n";
        print_done(a, size);

        break;

    }

    cout << "\n";
}