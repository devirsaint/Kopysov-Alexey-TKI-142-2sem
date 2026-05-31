#include <gtest/gtest.h>

#include "../include/Piquet.h"
#include "../include/Restriction.h"
#include "../include/SlopeRestriction.h"

#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string>

TEST(PiquetTest, ConstructorValid)
{
    Piquet piquet(12, 28.37, 100.0);

    ASSERT_EQ(piquet.getNumber(), 12);
    ASSERT_NEAR(piquet.getShift(), 28.37, 1e-9);
    ASSERT_DOUBLE_EQ(piquet.getLength(), 100.0);
    ASSERT_TRUE(piquet.getIsStandard());
}

TEST(PiquetTest, NonStandardPiquet)
{
    Piquet piquet(3, 20.0, 80.0);

    ASSERT_FALSE(piquet.getIsStandard());
    ASSERT_DOUBLE_EQ(piquet.getLength(), 80.0);
}

TEST(PiquetTest, NegativeToString)
{
    Piquet piquet(-12, 28.37, 100.0);

    ASSERT_EQ(piquet.ToString(), "ПК 012+28.37");
}

TEST(PiquetTest, InvalidValues)
{
    ASSERT_THROW(Piquet(1, -1.0, 100.0), invalid_argument);
    ASSERT_THROW(Piquet(1, 100.0, 100.0), invalid_argument);
    ASSERT_THROW(Piquet(1, 0.0, 0.0), invalid_argument);
}

TEST(PiquetTest, Operators)
{
    Piquet first(10, 20.0, 100.0);
    Piquet second(10, 20.0, 100.0);
    Piquet third(10, 30.0, 100.0);

    ASSERT_TRUE(first == second);
    ASSERT_TRUE(first != third);
    ASSERT_TRUE(first < third);
    ASSERT_TRUE(third > first);
    ASSERT_TRUE(first <= second);
    ASSERT_TRUE(first >= second);
}

TEST(PiquetTest, IOOperators)
{
    stringstream input("12 28.37 100");

    Piquet piquet;
    input >> piquet;

    ASSERT_FALSE(input.fail());
    ASSERT_EQ(piquet.getNumber(), 12);
    ASSERT_NEAR(piquet.getShift(), 28.37, 1e-9);

    stringstream output;
    output << piquet;

    ASSERT_EQ(output.str(), "ПК 12+28.37");
}

TEST(PiquetTest, IncorrectInput)
{
    stringstream input("12 100 100");

    Piquet piquet;
    input >> piquet;

    ASSERT_TRUE(input.fail());
}

TEST(SlopeRestrictionTest, ConstructorValid)
{
    Piquet beginPiquet(10, 20.0, 100.0);
    Piquet endPiquet(12, 30.0, 100.0);
    SlopeRestriction restriction(15.5, beginPiquet, endPiquet);

    ASSERT_DOUBLE_EQ(restriction.getSlopeValue(), 15.5);
    ASSERT_TRUE(restriction.getBeginPiquet() == beginPiquet);
    ASSERT_TRUE(restriction.getEndPiquet() == endPiquet);
}

TEST(SlopeRestrictionTest, InvalidSlope)
{
    Piquet beginPiquet(10, 20.0, 100.0);
    Piquet endPiquet(12, 30.0, 100.0);

    ASSERT_THROW(SlopeRestriction(51.0, beginPiquet, endPiquet), invalid_argument);
    ASSERT_THROW(SlopeRestriction(-51.0, beginPiquet, endPiquet), invalid_argument);
}

TEST(SlopeRestrictionTest, InvalidPiquets)
{
    Piquet beginPiquet(12, 30.0, 100.0);
    Piquet endPiquet(10, 20.0, 100.0);

    ASSERT_THROW(SlopeRestriction(10.0, beginPiquet, endPiquet), invalid_argument);
}

TEST(SlopeRestrictionTest, Setters)
{
    SlopeRestriction restriction(10.0, Piquet(1, 0.0, 100.0), Piquet(2, 0.0, 100.0));

    restriction.setSlopeValue(20.0);
    restriction.setPiquets(Piquet(3, 0.0, 100.0), Piquet(4, 0.0, 100.0));

    ASSERT_DOUBLE_EQ(restriction.getSlopeValue(), 20.0);
    ASSERT_TRUE(restriction.getBeginPiquet() == Piquet(3, 0.0, 100.0));
    ASSERT_TRUE(restriction.getEndPiquet() == Piquet(4, 0.0, 100.0));
}

TEST(SlopeRestrictionTest, ToString)
{
    SlopeRestriction restriction(12.5, Piquet(10, 25.5, 100.0), Piquet(12, 40.0, 100.0));

    string result = restriction.ToString();

    ASSERT_NE(result.find("Информация об ограничении уклона"), string::npos);
    ASSERT_NE(result.find("Начало ограничения"), string::npos);
    ASSERT_NE(result.find("Конец ограничения"), string::npos);
    ASSERT_NE(result.find("Значение уклона"), string::npos);
}

TEST(SlopeRestrictionTest, OutputOperator)
{
    SlopeRestriction restriction(12.5, Piquet(10, 25.5, 100.0), Piquet(12, 40.0, 100.0));

    stringstream output;
    output << restriction;

    string result = output.str();

    ASSERT_NE(result.find("ПК 10+25.50"), string::npos);
    ASSERT_NE(result.find("ПК 12+40.00"), string::npos);
    ASSERT_NE(result.find("12.5"), string::npos);
}

TEST(SlopeRestrictionTest, ReadFrom)
{
    stringstream input("12.5 10 25.5 100 12 40 100");

    SlopeRestriction restriction = SlopeRestriction::ReadFrom(input);

    ASSERT_FALSE(input.fail());
    ASSERT_DOUBLE_EQ(restriction.getSlopeValue(), 12.5);
    ASSERT_TRUE(restriction.getBeginPiquet() == Piquet(10, 25.5, 100.0));
    ASSERT_TRUE(restriction.getEndPiquet() == Piquet(12, 40.0, 100.0));
}

TEST(SlopeRestrictionTest, IOOperators)
{
    stringstream input("-10 1 0 100 3 0 100");

    SlopeRestriction restriction;
    input >> restriction;

    ASSERT_FALSE(input.fail());
    ASSERT_DOUBLE_EQ(restriction.getSlopeValue(), -10.0);
}

TEST(SlopeRestrictionTest, IncorrectInput)
{
    stringstream input("60 1 0 100 3 0 100");

    SlopeRestriction restriction;
    input >> restriction;

    ASSERT_TRUE(input.fail());
}

TEST(SlopeRestrictionTest, Polymorphism)
{
    SlopeRestriction restriction(12.5, Piquet(10, 25.5, 100.0), Piquet(12, 40.0, 100.0));
    Restriction* base = &restriction;

    ASSERT_NE(base->ToString().find("Значение уклона"), string::npos);
}

int main(int argc, char** argv)
{
#ifdef _WIN32
    system("chcp 65001");
#endif

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
