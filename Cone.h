#pragma once
#include <iostream>
#include "Point.h"

using namespace std;

/**
* @brief Класс конуса
*/
class Cone
{
private:
	/**
	* @param center - центр окружности основания конуса
	*/
	Point center;

	/**
	* @param radius - радиус окружности основания конуса
	*/
	double radius;

	/**
	* @param height - высота конуса
	*/
	double height;

	/**
	* @brief Функция проверки, образуют ли переданные значения конус
	* @param radius - радиус окружности основания конуса
	* @param height - высота конуса
	*/
	void checkCone(const double radius, const double height);

public:

	/**
	* @brief Конструктор, задаёт центр, радиус и высоту как переданные значения
	* @param center - центр окружности основания конуса
	* @param radius - радиус окружности основания конуса
	* @param height - высота конуса
	*/
	Cone(const Point center = Point(0,0,0), const double radius = 1.0, const double height = 1.0);

	/**
	* @brief Рассчитывает площадь полной поверхности конуса
	* @return Рассчитанное значение площади поверхности
	*/
	double getSurfaceArea() const;
};
