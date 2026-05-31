#include "Point.h"
#include <float.h>

Point::Point(const double x, const double y, const double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Point::getX(void) const
{
	return x;
}

double Point::getY(void) const
{
	return y;
}

double Point::getZ(void) const
{
	return z;
}