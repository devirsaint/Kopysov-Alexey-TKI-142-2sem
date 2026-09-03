#pragma once

#include <iostream>
#include <string>

using namespace std;

/**
* @brief Класс пикет.
* Класс хранит номер пикета, смещение, длину пикета и признак стандартного пикета.
*/
class Piquet
{
private:
    /**
    * @brief Номер пикета.
    */
    int number;

    /**
    * @brief Смещение внутри пикета.
    */
    double shift;

    /**
    * @brief Длина пикета в метрах.
    */
    double length;

    /**
    * @brief Признак стандартного пикета.
    * @retur true, если длина пикета равна 100м (стандартный), иначе false
    */
    bool isStandard;

    /**
    * @brief Проверяет корректность пикета.
    * @throw invalid_argument если длина или смещение заданы неверно.
    */
    void CheckPiquet(void) const;

    /**
    * @brief Рассчитывает координату пикета в метрах.
    * @return Координата пикета в метрах.
    */
    double ToMeters(void) const;

public:
    /**
    * @brief Конструктор пикета.
    * @param number Номер пикета.
    * @param shift Смещение внутри пикета.
    * @param length Длина пикета. По умолчанию равна 100 м.
    * @throw invalid_argument если длина или смещение заданы неверно.
    */
    Piquet(const int number = 0, const double shift = 0.0, const double length = 100.0);

    /**
    * @brief Возвращает номер пикета.
    * @return Номер пикета.
    */
    int getNumber(void) const;

    /**
    * @brief Возвращает смещение пикета.
    * @return Смещение пикета.
    */
    double getShift(void) const;

    /**
    * @brief Возвращает длину пикета.
    * @return Длина пикета.
    */
    double getLength(void) const;

    /**
    * @brief Возвращает признак стандартного пикетажа.
    * @return true, если пикет стандартный, иначе false.
    */
    bool getIsStandard(void) const;

    /**
    * @brief Преобразует пикет в строку.
    * @return Строка с пикетом в формате ПК Номер+Смещение.
    */
    string ToString(void) const;

    /**
    * @brief Сравнивает два пикета на равенство.
    * @param other Пикет для сравнения.
    * @return true, если пикеты равны, иначе false.
    */
    bool operator == (const Piquet& other) const;

    /**
    * @brief Сравнивает два пикета на неравенство.
    * @param other Пикет для сравнения.
    * @return true, если пикеты не равны, иначе false.
    */
    bool operator != (const Piquet& other) const;

    /**
    * @brief Проверяет, что текущий пикет меньше другого.
    * @param other Пикет для сравнения.
    * @return true, если текущий пикет меньше другого, иначе false.
    */
    bool operator < (const Piquet& other) const;

    /**
    * @brief Проверяет, что текущий пикет меньше или равен другому.
    * @param other Пикет для сравнения.
    * @return true, если текущий пикет меньше или равен другому, иначе false.
    */
    bool operator <= (const Piquet& other) const;

    /**
    * @brief Проверяет, что текущий пикет больше другого.
    * @param other Пикет для сравнения.
    * @return true, если текущий пикет больше другого, иначе false.
    */
    bool operator > (const Piquet& other) const;

    /**
    * @brief Проверяет, что текущий пикет больше или равен другому.
    * @param other Пикет для сравнения.
    * @return true, если текущий пикет больше или равен другому, иначе false.
    */
    bool operator >= (const Piquet& other) const;

    /**
    * @brief Оператор вывода пикета в поток.
    * @param output Поток вывода.
    * @param piquet Выводимый пикет.
    * @return Ссылка на поток вывода.
    */
    friend ostream& operator << (ostream& output, const Piquet& piquet);

    /**
    * @brief Оператор ввода пикета из потока.
    * Формат ввода: номер; смещение; длина.
    * @param input Поток ввода.
    * @param piquet Пикет, в который записываются считанные данные.
    * @return Ссылка на поток ввода.
    */
    friend istream& operator >> (istream& input, Piquet& piquet);
};
