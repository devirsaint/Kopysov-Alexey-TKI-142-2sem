#pragma once
#include <cmath>

/**
* @brief Класс точки в трехмерном пространстве
*/
class Point
{
private:
	/**
	* @param x - координата точки по x
	*/
	double x;

	/**
	* @param y - координата точки по y
	*/
	double y;

	/**
	* @param z - координата точки по z
	*/
	double z;

public:
	/**
	* @brief Конструктор, который задаёт точку с координатами (x;y;z)
	* @param x - координата точки по x
	* @param y - координата точки по y
	* @param z - координата точки по z
	*/
	Point(const double x = 0, const double y = 0, const double z = 0);

	/**
	* @brief Выводит значение точки по  x
	* @return Значение точки по x
	*/
	double getX(void) const;

	/**
	* @brief Выводит значение точки по y
	* @return Значение точки по y
	*/
	double getY(void) const;

	/**
	* @brief Выводит значение точки по z
	* @return Значение точки по z
	*/
	double getZ(void) const;
};