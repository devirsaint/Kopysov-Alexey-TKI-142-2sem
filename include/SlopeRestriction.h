#pragma once

#include "Restriction.h"
#include "Piquet.h"

/**
* @brief Класс ограничение уклона.
* Класс хранит значение уклона в промилях,
* координату начала и координату конца ограничения.
*/
class SlopeRestriction : public Restriction
{
private:
    /**
    * @brief Значение уклона в промилях.
    */
    double slopeValue;

    /**
    * @brief Координата начала действия ограничения.
    */
    Piquet beginPiquet;

    /**
    * @brief Координата конца действия ограничения.
    */
    Piquet endPiquet;

    /**
    * @brief Проверяет корректность ограничения уклона.
    * @throw invalid_argument если уклон или координаты заданы неверно.
    */
    void CheckRestriction(void) const;

public:
    /**
    * @brief Конструктор из значения уклона и двух пикетов.
    * @param slopeValue Значение уклона в промилях.
    * @param beginPiquet Координата начала действия ограничения.
    * @param endPiquet Координата конца действия ограничения.
    * @throw invalid_argument если уклон или координаты заданы неверно.
    */
    SlopeRestriction(const double slopeValue = 0.0, const Piquet beginPiquet = Piquet(), const Piquet endPiquet = Piquet());

    /**
    * @brief Возвращает значение уклона.
    * @return Значение уклона в промилях.
    */
    double getSlopeValue(void) const;

    /**
    * @brief Возвращает координату начала ограничения.
    * @return Пикет начала ограничения.
    */
    Piquet getBeginPiquet(void) const;

    /**
    * @brief Возвращает координату конца ограничения.
    * @return Пикет конца ограничения.
    */
    Piquet getEndPiquet(void) const;

    /**
    * @brief Изменяет значение уклона.
    * @param slopeValue Новое значение уклона в промилях.
    * @throw invalid_argument если уклон задан неверно.
    */
    void setSlopeValue(const double slopeValue);

    /**
    * @brief Изменяет координаты действия ограничения.
    * @param beginPiquet Новая координата начала.
    * @param endPiquet Новая координата конца.
    * @throw invalid_argument если координаты заданы неверно.
    */
    void setPiquets(const Piquet beginPiquet, const Piquet endPiquet);

    /**
    * @brief Преобразует ограничение уклона в строку.
    * @return Строковое представление ограничения.
    */
    string ToString(void) const override;

    /**
    * @brief Считывает ограничение уклона из потока ввода.
    * Формат ввода: уклон; номер начал;а смещение начала; длина начала; номер конца; смещение конца; длина конца.
    * @param input Поток ввода.
    */
    void Read(istream& input) override;

    /**
    * @brief Считывает ограничение уклона из стандартного потока ввода.
    * @return Считанное ограничение уклона.
    * @throw invalid_argument если ограничение задано неверно.
    */
    static SlopeRestriction Read(void);

    /**
    * @brief Считывает ограничение уклона из заданного потока ввода.
    * @param input Поток ввода.
    * @return Считанное ограничение уклона.
    */
    static SlopeRestriction ReadFrom(istream& input);

    /**
    * @brief Оператор вывода ограничения уклона в поток.
    * @param output Поток вывода.
    * @param restriction Выводимое ограничение.
    * @return Ссылка на поток вывода.
    */
    friend ostream& operator << (ostream& output, const SlopeRestriction& restriction);

    /**
    * @brief Оператор ввода ограничения уклона из потока.
    * @param input Поток ввода.
    * @param restriction Ограничение, в которое записываются считанные данные.
    * @return Ссылка на поток ввода.
    */
    friend istream& operator >> (istream& input, SlopeRestriction& restriction);
};
