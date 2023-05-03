#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test addition")
{
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction result = f1 + f2;
    CHECK(result == Fraction(5, 6));

    Fraction f3(-1, 2);
    Fraction f4(1, 2);
    result = f3 + f4;
    CHECK(result == Fraction(0, 1));

    Fraction f5(0, 1);
    Fraction f6(1, 2);
    result = f5 + f6;
    CHECK(result == Fraction(1, 2));
}

TEST_CASE("Test subtraction")
{
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    Fraction result = f1 - f2;
    CHECK(result == Fraction(1, 4));

    Fraction f3(-1, 2);
    Fraction f4(-1, 2);
    result = f3 - f4;
    CHECK(result == Fraction(0, 1));

    Fraction f5(0, 1);
    Fraction f6(1, 2);
    result = f5 - f6;
    CHECK(result == Fraction(-1, 2));
}

TEST_CASE("Test multiplication")
{
    Fraction f1(3, 4);
    Fraction f2(2, 3);
    Fraction result = f1 * f2;
    CHECK(result == Fraction(1, 2));

    Fraction f3(0, 1);
    Fraction f4(1, 2);
    result = f3 * f4;
    CHECK(result == Fraction(0, 1));

    Fraction f5(-3, 4);
    Fraction f6(-1, 2);
    result = f5 * f6;
    CHECK(result == Fraction(3, 8));
}

TEST_CASE("Test division")
{
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction result = f1 / f2;
    CHECK(result == Fraction(3, 2));

    // Division by zero test passed.
    Fraction f3(1, 2);
    Fraction f4(0, 1);
    try
    {
        result = f3 / f4;
        CHECK(false);
    }
    catch (const std::invalid_argument &)
    {
        CHECK(true);
    }

    Fraction f5(-1, 2);
    Fraction f6(1, 2);
    result = f5 / f6;
    CHECK(result == Fraction(-1, 1));
}

// Comparison operators
TEST_CASE("Test equality")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    CHECK(f1 == f2);

    Fraction f3(1, 2);
    Fraction f4(-1, 2);
    CHECK(!(f3 == f4));

    Fraction f5(0, 1);
    Fraction f6(0, 1);
    CHECK(f5 == f6);
}

TEST_CASE("Test inequality")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    CHECK(!(f1 != f2));

    Fraction f3(1, 2);
    Fraction f4(-1, 2);
    CHECK(f3 != f4);

    Fraction f5(0, 1);
    Fraction f6(1, 1);
    CHECK(f5 != f6);
}

TEST_CASE("Test greater than")
{
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    CHECK(f1 > f2);

    Fraction f3(1, 2);
    Fraction f4(-1, 2);
    CHECK(f3 > f4);

    Fraction f5(0, 1);
    Fraction f6(-1, 2);
    CHECK(f5 > f6);
}

TEST_CASE("Test less than")
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    CHECK(f1 < f2);

    Fraction f3(-1, 2);
    Fraction f4(1, 2);
    CHECK(f3 < f4);

    Fraction f5(-1, 2);
    Fraction f6(0, 1);
    CHECK(f5 < f6);
}

TEST_CASE("Test greater than or equal")
{
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    CHECK(f1 >= f2);

    Fraction f3(1, 2);
    Fraction f4(-1, 2);
    CHECK(f3 >= f4);

    Fraction f5(0, 1);
    Fraction f6(-1, 2);
    CHECK(f5 >= f6);

    Fraction f7(1, 2);
    Fraction f8(1, 2);
    CHECK(f7 >= f8);
}

TEST_CASE("Test less than or equal")
{
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    CHECK(f2 <= f1);

    Fraction f3(1, 2);
    Fraction f4(-1, 2);
    CHECK(f4 <= f3);

    Fraction f5(0, 1);
    Fraction f6(-1, 2);
    CHECK(f6 <= f5);

    Fraction f7(1, 2);
    Fraction f8(1, 2);
    CHECK(f7 <= f8);
}