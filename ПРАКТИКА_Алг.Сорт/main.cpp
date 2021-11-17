#include <iostream>

#include "menu.h"
#include "inputs.h"
using namespace std;


int main()
{
    setlocale(0, "");

    int variant; // выбранный пункт меню

    do {
        print_menu(); // выводим меню на экран

        variant = get_variant(4); // получаем номер выбранного пункта меню

        switch (variant) {
        case 1:
            in_rand(); // ввод случайными числами
            break;

        case 2:
            in_cmd(); // ввод из консоли
            break;

        case 3:
            in_file(); // ввод из файла
            break;

        }

        if (variant != 4)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 4);

}