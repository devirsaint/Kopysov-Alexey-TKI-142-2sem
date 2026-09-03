#include "Cone.h"
#include <float.h>

void Cone::checkCone(const double radius, const double height)
{
	if (radius <= DBL_EPSILON)
	{
		cerr << "Радиус должен быть больше нуля";
		exit(1);
	}

	if (height <= DBL_EPSILON)
	{
		cerr << "Высота должна быть больше нуля";
		exit(1);
	}
}

Cone::Cone(const Point center, const double radius, const double height)
{
	this->center = center;
	this->radius = radius;
	this->height = height;

	checkCone(radius, height);
}

double Cone::getSurfaceArea() const
{
	const double PI = acos(-1.0);
	const double generatrix = sqrt(pow(radius, 2) + pow(height, 2));

	return PI * radius * (radius + generatrix);
}
