/*
* Pavel Zak
* st142062@student.spbu.ru
HomeAssignment5
*/

#include <gtest/gtest.h>
#include "Rational.hpp"

TEST(RationalTest, ConstructorAndInvariant) {
    Rational r1(2, 4);
    EXPECT_EQ(r1.get_num(), 1);
    EXPECT_EQ(r1.get_den(), 2);

    Rational r2(3, -1);
    EXPECT_EQ(r2.get_num(), -3);
    EXPECT_EQ(r2.get_den(), 1);

    Rational r3(-4, -8);
    EXPECT_EQ(r3.get_num(), 1);
    EXPECT_EQ(r3.get_den(), 2);

    Rational r4(0, 5);
    EXPECT_EQ(r4.get_num(), 0);
    EXPECT_EQ(r4.get_den(), 1);
}

TEST(RationalTest, DefaultConstructor) {
    Rational r;
    EXPECT_EQ(r.get_num(), 0);
    EXPECT_EQ(r.get_den(), 1);
}

TEST(RationalTest, Addition) {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational res = r1 + r2;
    EXPECT_EQ(res.get_num(), 5);
    EXPECT_EQ(res.get_den(), 6);

    Rational r3(1, 4);
    r3 += Rational(1, 4);
    EXPECT_EQ(r3.get_num(), 1);
    EXPECT_EQ(r3.get_den(), 2);
}

TEST(RationalTest, Multiplication) {
    Rational r1(2, 3);
    Rational r2(3, 4);
    Rational res = r1 * r2;
    EXPECT_EQ(res.get_num(), 1);
    EXPECT_EQ(res.get_den(), 2);

    Rational r3(-1, 2);
    r3 *= Rational(2, 1);
    EXPECT_EQ(r3.get_num(), -1);
    EXPECT_EQ(r3.get_den(), 1);
}

TEST(RationalTest, Comparison) {
    Rational r1(1, 2);
    Rational r2(2, 4);
    Rational r3(1, 3);

    EXPECT_TRUE(r1 == r2);
    EXPECT_FALSE(r1 == r3);
    EXPECT_TRUE(r1 != r3);
}

TEST(RationalTest, Exceptions) {
    EXPECT_THROW(Rational(1, 0), std::invalid_argument);
}
