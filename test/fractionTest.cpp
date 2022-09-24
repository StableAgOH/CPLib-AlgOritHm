#include "../lib/fraction.hpp"
#include <gtest/gtest.h>

TEST(fractionTest, fractionTest1)
{
    agoh::Fraction f(10, 8);
    EXPECT_EQ(f.get_numerator(), 5);
    EXPECT_EQ(f.get_denominator(), 4);
    EXPECT_EQ(f.toInteger(), 1);
    EXPECT_EQ(f.toDouble(), 1.25);
    EXPECT_EQ(f.toString(), "5/4");
}

TEST(fractionTest, fractionTest2)
{
    agoh::Fraction f1(2, 3);
    agoh::Fraction f2(4, 6);
    agoh::Fraction f3(5, 4);
    EXPECT_TRUE(f1 == f2);
    EXPECT_TRUE(f1 != f3);
    EXPECT_TRUE(f1 < f3);
    EXPECT_FALSE(f2 > f3);
}

TEST(fractionTest, fractionTest3)
{
    agoh::Fraction f1(-5, 10);
    agoh::Fraction f2(2, -4);
    EXPECT_EQ(f1, f2);
    EXPECT_EQ(-f1, -f2);
}

TEST(fractionTest, fractionTest4)
{
    agoh::Fraction f1(9, 2);
    agoh::Fraction f2(12, 7);
    EXPECT_EQ(f1 + f2, agoh::Fraction(87, 14));
    EXPECT_EQ(f2 + f1, agoh::Fraction(87, 14));
    EXPECT_EQ(f1 - f2, agoh::Fraction(39, 14));
    EXPECT_EQ(f2 - f1, agoh::Fraction(-39, 14));
    EXPECT_EQ(f1 * f2, agoh::Fraction(54, 7));
    EXPECT_EQ(f2 * f1, agoh::Fraction(54, 7));
    EXPECT_EQ(f1 / f2, agoh::Fraction(21, 8));
    EXPECT_EQ(f2 / f1, agoh::Fraction(8, 21));
}

TEST(fractionTest, fractionTest5)
{
    agoh::Fraction f(3, 2);
    EXPECT_EQ(f + 3, agoh::Fraction(9, 2));
    EXPECT_EQ(f - 3, agoh::Fraction(-3, 2));
    EXPECT_EQ(f * 2, 3);
    EXPECT_EQ(f / 3, agoh::Fraction(1, 2));
}

TEST(fractionTest, fractionTest6)
{
    agoh::Fraction f;
    EXPECT_EQ(f.toString(), "0/1");
}
