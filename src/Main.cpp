#include "../include/SlopeRestriction.h"

#include <cstdlib>
#include <exception>
#include <iostream>

using namespace std;

/**
* @brief Основной код программы.
* @return 0, если программа завершилась успешно, иначе 1.
*/
int main()
{
    system("chcp 65001");

    cout << "Введите ограничение уклона:" << endl;
    cout << "Формат: уклон; номер начала; смещение начала; длина начала; номер конца; смещение конца; длина конца;" << endl;

    try
    {
        SlopeRestriction restriction = SlopeRestriction::Read();
        cout << restriction;
    }
    catch (const exception& error)
    {
        cerr << "Ошибка: " << error.what() << endl;
        return 1;
    }

    return 0;
}
