#pragma once

#include <iostream>
#include <string>

using namespace std;

/**
* @brief Абстрактный базовый класс "Ограничение".
* Класс задаёт общий интерфейс для ограничений.
*/
class Restriction
{
public:
    /**
    * @brief Виртуальный деструктор.
    */
    virtual ~Restriction(void) = default;

    /**
    * @brief Преобразует ограничение в строку.
    * @return Строковое представление ограничения.
    */
    virtual string ToString(void) const = 0;

    /**
    * @brief Считывает ограничение из потока ввода.
    * @param input Поток ввода.
    */
    virtual void Read(istream& input) = 0;
};
