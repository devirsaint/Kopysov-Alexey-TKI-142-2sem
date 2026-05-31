#include "Cone.h"

/**
* @brief Считывает точку с проверкой ввода.
* @return Точку, с переданными ей значениями
*/
const Point getPoint(void);

/**
* @brief Считывает введенное число с клавиатуцры с проверкой ввода.
* @return Считанное значение
*/
const double getDouble(void);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");
	system("CLS");

	cout << "Введите координату центра окружности основания в формате (x y z): ";
	Point center = getPoint();

	double radius = 0;
	double height = 0;

	cout << "Введите радиус окружности основания: ";
	radius = getDouble();

	cout << "Введите высоту конуса: ";
	height = getDouble();

	Cone First(center, radius, height);
	cout << endl << endl << "Площадь поверхности конуса: " << First.getSurfaceArea() << endl;
	
	return 0;
}

const Point getPoint(void)
{
	double x = 0;
	double y = 0;
	double z = 0;
	cin >> x >> y >> z;
	if (cin.fail())
	{
		cout << "Ошибка ввода!";
		exit(1);
	}
	Point A(x, y, z);
	return A;
}

const double getDouble(void)
{
	double value = 0;
	cin >> value;
	if (cin.fail())
	{
		cout << "Ошибка ввода!";
		exit(1);
	}
	return value;
}