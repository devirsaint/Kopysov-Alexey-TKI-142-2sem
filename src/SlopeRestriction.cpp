#include "../include/SlopeRestriction.h"

#include <cmath>
#include <exception>
#include <sstream>
#include <stdexcept>

void SlopeRestriction::CheckRestriction(void) const
{
    if (!isfinite(slopeValue) || fabs(slopeValue) > 50.0)
    {
        throw invalid_argument("Значение уклона должно быть не больше 50 промилле.");
    }

    if (beginPiquet > endPiquet)
    {
        throw invalid_argument("Координата начала ограничения не должна быть больше координаты конца.");
    }
}

SlopeRestriction::SlopeRestriction(const double slopeValue, const Piquet beginPiquet, const Piquet endPiquet)
{
    this->slopeValue = slopeValue;
    this->beginPiquet = beginPiquet;
    this->endPiquet = endPiquet;

    CheckRestriction();
}

double SlopeRestriction::getSlopeValue(void) const
{
    return slopeValue;
}

Piquet SlopeRestriction::getBeginPiquet(void) const
{
    return beginPiquet;
}

Piquet SlopeRestriction::getEndPiquet(void) const
{
    return endPiquet;
}

void SlopeRestriction::setSlopeValue(const double slopeValue)
{
    double oldSlopeValue = this->slopeValue;

    this->slopeValue = slopeValue;

    try
    {
        CheckRestriction();
    }
    catch (...)
    {
        this->slopeValue = oldSlopeValue;
        throw;
    }
}

void SlopeRestriction::setPiquets(const Piquet beginPiquet, const Piquet endPiquet)
{
    Piquet oldBeginPiquet = this->beginPiquet;
    Piquet oldEndPiquet = this->endPiquet;

    this->beginPiquet = beginPiquet;
    this->endPiquet = endPiquet;

    try
    {
        CheckRestriction();
    }
    catch (...)
    {
        this->beginPiquet = oldBeginPiquet;
        this->endPiquet = oldEndPiquet;
        throw;
    }
}

string SlopeRestriction::ToString(void) const
{
    ostringstream output;

    output << "Информация об ограничении уклона:" << endl;
    output << "Начало ограничения: " << beginPiquet << endl;
    output << "Конец ограничения: " << endPiquet << endl;
    output << "Значение уклона: " << slopeValue << " промилле" << endl;

    return output.str();
}

void SlopeRestriction::Read(istream& input)
{
    double slopeValue;
    Piquet beginPiquet;
    Piquet endPiquet;

    input >> slopeValue >> beginPiquet >> endPiquet;

    if (input.fail())
    {
        return;
    }

    try
    {
        *this = SlopeRestriction(slopeValue, beginPiquet, endPiquet);
    }
    catch (const exception& error)
    {
        cerr << "Ошибка: " << error.what() << endl;
        input.setstate(ios::failbit);
    }
}

SlopeRestriction SlopeRestriction::Read(void)
{
    SlopeRestriction restriction;

    restriction.Read(cin);

    if (cin.fail())
    {
        throw invalid_argument("Ограничение задано неверно.");
    }

    return restriction;
}

SlopeRestriction SlopeRestriction::ReadFrom(istream& input)
{
    SlopeRestriction restriction;

    restriction.Read(input);

    return restriction;
}

ostream& operator << (ostream& output, const SlopeRestriction& restriction)
{
    output << restriction.ToString();
    return output;
}

istream& operator >> (istream& input, SlopeRestriction& restriction)
{
    restriction.Read(input);
    return input;
}
