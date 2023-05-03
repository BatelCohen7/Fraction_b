#include <iostream>
#include <stdexcept>
#include <cmath>
#include <numeric>
#include "Fraction.hpp"

using namespace std;

namespace ariel
{
    
    // default constrctor
    Fraction::Fraction()
    {
        this->denominator=1;
        this->numerator=1;
    }

    // Constrctors
    Fraction::Fraction(int num, int den) : numerator(num), denominator(den)
    {
        if (denominator == 0)
        {
            throw std::invalid_argument("Denominator cannot be 0"); // It is forbidden to divide a number by 0
        }
        reduce();
    }

    Fraction::Fraction(float f)
    {
        denominator = 1000;
        numerator = static_cast<int>(round(f * 1000));
        reduce();
    }

    // Getters
    int Fraction::getNumerator() const
    {
        return numerator;
    }

    int Fraction::getDenominator() const
    {
        return denominator;
    }

    //  Reduce the given fraction to its simplest form
    void Fraction::reduce()
    {
        int gcd = std::gcd(numerator, denominator);
        if(denominator < 0)
        {
            this->denominator*=-1;
            this->numerator*=-1;
        }
        numerator /= gcd;
        denominator /= gcd;
    }

    // Overflow
    void add_overflow(int num1, int num2){
        int num3  = num1 + num2;
        
        if(num1 > 0 && num2 > 0 && num3 < 0){
            throw std::overflow_error("overflow");
        }
        if(num1 < 0 && num2 < 0 && num3 > 0){
            throw std::overflow_error("overflow");
        }
    }

    void mul_overflow(int num1, int num2){
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();

        if(num1 == 0 || num2 == 0){
            return;
        }
        int num3 = num1 * num2;
        if( (num3 / num1) != num2)
        {
            throw std::overflow_error("overflow");
        }
    }

    // Arithmetic operators
    Fraction Fraction::operator+(const Fraction &other) const
    {
        mul_overflow(numerator , other.denominator);
        mul_overflow(other.numerator , denominator);
        add_overflow(numerator * other.denominator , other.numerator * denominator);
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        Fraction result(num, den);
        result.reduce();
        return result;
    }

    Fraction Fraction::operator-(const Fraction &other) const
    { // lhs = this
        int lcm = std::lcm(this->denominator, other.denominator);
        int num1 = this->numerator * (lcm / this->denominator);
        int num2 = other.numerator * (lcm / other.denominator);
        if ((num1 < 0 && num2 > 0 && num1 < std::numeric_limits<int>::min() + num2) ||
            (num1 > 0 && num2 < 0 && num1 > std::numeric_limits<int>::max() + num2)) {
            throw std::overflow_error("Integer overflow in Fraction subtraction.");
        }
        return Fraction(num1 - num2, lcm);
    }

    Fraction Fraction::operator*(const Fraction &other) const
    {
        mul_overflow(numerator,other.numerator);
        int num = numerator * other.numerator;
        mul_overflow(other.denominator,denominator);
        int den = denominator * other.denominator;
        Fraction result(num, den);
        result.reduce();
        return result;
    }

    Fraction Fraction::operator/(const Fraction &other) const
    {

        if (other.numerator == 0)
        {
            throw  std::runtime_error("Division by zero");
        }
        mul_overflow(numerator , other.denominator);
        int num = numerator * other.denominator;
        mul_overflow(denominator , other.numerator);
        int den = denominator * other.numerator;
        Fraction result(num, den);
        result.reduce();
        return result;
    }

    // Increment and decrement operators
    Fraction& Fraction::operator++()
    {
        numerator += denominator;
        reduce();
        return *this;
    }

    Fraction Fraction::operator++(int)
    {
        Fraction temp = *this;
        numerator += denominator;
        reduce();
        return temp;
    }

    Fraction& Fraction::operator--()
    {
        numerator -= denominator;
        reduce();
        return *this;
    }

    Fraction Fraction::operator--(int)
    {
        Fraction temp = *this;
        numerator -= denominator;
        reduce();
        return temp;
    }

    // Float operators
    Fraction Fraction::operator+(const float f) const
    {
        return *this + Fraction(f);
    }

    Fraction Fraction::operator-(const float f) const
    {

        return *this - Fraction(f);
    }

    Fraction Fraction::operator*(const float f) const
    {
        return *this * Fraction(f);
    }

    Fraction Fraction::operator/(const float f) const
    {
        return *this / Fraction(f);
    }

    Fraction operator+(const float f, const Fraction &fraction)
    {
        return Fraction(f) + fraction;
    }

    Fraction operator-(const float f, const Fraction &fraction)
    {
        return Fraction(f) - fraction;
    }

    Fraction operator*(const float f, const Fraction &fraction)
    {
        return Fraction(f) * fraction;
    }

    Fraction operator/(const float f, const Fraction &fraction)
    {
    return Fraction(f) / fraction;
    }

    // Comparison operators
    bool Fraction::operator==(const Fraction &other) const
    {
        int num1 = (this->numerator * 1000) / this->denominator;
        int num2 = (other.numerator * 1000) / other.denominator;
        return num1 == num2;
    }

    bool Fraction::operator!=(const Fraction &other) const
    {
        return !(*this == other);
    }

    bool Fraction::operator>(const Fraction &other) const
    {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool Fraction::operator<(const Fraction &other) const
    {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool Fraction::operator>=(const Fraction &other) const
    {
        return !(*this < other);
    }

    bool Fraction::operator<=(const Fraction& other) const
    {
        return !(*this > other);
    }

    // Float comparison operators
    bool Fraction::operator==(const float f) const
    {
        return *this == Fraction(f);
    }

    bool Fraction::operator!=(const float f) const
    {
        return *this != Fraction(f);
    }

    bool Fraction::operator>(const float f) const
    {
        return *this > Fraction(f);
    }

    bool Fraction::operator<(const float f) const
    {
        return *this < Fraction(f);
    }

    bool Fraction::operator>=(const float f) const
    {
        return *this >= Fraction(f);
    }

    bool Fraction::operator<=(const float f) const
    {
        return *this <= Fraction(f);
    }

    bool operator==(const float f, const Fraction &fraction)
    {
        return Fraction(f) == fraction;
    }

    bool operator!=(const float f, const Fraction &fraction)
    {
        return Fraction(f) != fraction;
    }

    bool operator>(const float f, const Fraction &fraction)
    {
        return Fraction(f) > fraction;
    }

    bool operator<(const float f, const Fraction &fraction)
    {
        return Fraction(f) < fraction;
    }

    bool operator>=(const float f, const Fraction &fraction)
    {
        return Fraction(f) >= fraction;
    }

    bool operator<=(const float f, const Fraction &fraction)
    {
        return Fraction(f) <= fraction;
    }

    // Stream operators
    std::ostream &operator<<(std::ostream &os, const Fraction &fraction)
    {
        os << fraction.getNumerator() << '/' << fraction.getDenominator();
        return os;
    }

    std::istream &operator>>(std::istream &is, Fraction &fraction) {
        int numerator, denominator;
        if (is >> numerator >> denominator) {
            if (denominator == 0) {
                throw std::runtime_error("Cannot divide by zero.");
            }
            fraction = Fraction(numerator, denominator);
        }
        else {
            throw std::runtime_error("Failed to read Fraction from input.");
        }
        return is;
    }
} // namespace ariel
