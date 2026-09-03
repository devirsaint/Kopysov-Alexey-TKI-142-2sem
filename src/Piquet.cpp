#include "../include/Piquet.h"

#include <cmath>
#include <exception>
#include <iomanip>
#include <limits>
#include <sstream>
#include <stdexcept>

void Piquet::CheckPiquet(void) const
{
    if (!isfinite(length) || length <= 0.0)
    {
        throw invalid_argument("Длина пикета должна быть больше нуля.");
    }

    if (!isfinite(shift) || shift < 0.0 || shift >= length)
    {
        throw invalid_argument("Смещение должно быть от 0 до значения меньше длины пикета.");
    }
}

Piquet::Piquet(const int number, const double shift, const double length)
{
    this->number = number;
    this->shift = shift;
    this->length = length;
    this->isStandard = fabs(length - 100.0) < numeric_limits<double>::epsilon();

    CheckPiquet();
}

int Piquet::getNumber(void) const
{
    return number;
}

double Piquet::getShift(void) const
{
    return shift;
}

double Piquet::getLength(void) const
{
    return length;
}

bool Piquet::getIsStandard(void) const
{
    return isStandard;
}

double Piquet::ToMeters(void) const
{
    if (number < 0)
    {
        return number * length - shift;
    }

    return number * length + shift;
}

string Piquet::ToString(void) const
{
    ostringstream output;

    output << fixed << setprecision(2);
    output << "ПК ";

    if (number < 0)
    {
        output << '0' << abs(number);
    }
    else
    {
        output << number;
    }

    output << '+' << shift;

    string result = output.str();

    return result;
}

bool Piquet::operator == (const Piquet& other) const
{
    return fabs(ToMeters() - other.ToMeters()) < numeric_limits<double>::epsilon();
}

bool Piquet::operator != (const Piquet& other) const
{
    return !(*this == other);
}

bool Piquet::operator < (const Piquet& other) const
{
    return ToMeters() < other.ToMeters() && *this != other;
}

bool Piquet::operator <= (const Piquet& other) const
{
    return *this < other || *this == other;
}

bool Piquet::operator > (const Piquet& other) const
{
    return other < *this;
}

bool Piquet::operator >= (const Piquet& other) const
{
    return *this > other || *this == other;
}

ostream& operator << (ostream& output, const Piquet& piquet)
{
    output << piquet.ToString();
    return output;
}

istream& operator >> (istream& input, Piquet& piquet)
{
    int number;
    double shift;
    double length;

    input >> number >> shift >> length;

    if (input.fail())
    {
        return input;
    }

    try
    {
        piquet = Piquet(number, shift, length);
    }
    catch (const exception& error)
    {
        cerr << "Ошибка: " << error.what() << endl;
        input.setstate(ios::failbit);
    }

    return input;
}
