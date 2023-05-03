#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>

namespace ariel
{
    class Fraction {
    public:
        Fraction();
        Fraction(int numerator, int denominator);
        Fraction(float value);
        int getDenominator() const;
        int getNumerator() const;

        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;

        Fraction operator+(float value) const;
        Fraction operator-(float value) const;
        Fraction operator*(float value) const;
        Fraction operator/(float value) const;

        Fraction operator++(int);
        Fraction operator--(int);

        Fraction& operator++();
        Fraction& operator--();

        friend Fraction operator+(float value, const Fraction& fraction);
        friend Fraction operator-(float value, const Fraction& fraction);
        friend Fraction operator*(float value, const Fraction& fraction);
        friend Fraction operator/(float value, const Fraction& fraction);

        bool operator==(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;

        bool operator==(float value) const;
        bool operator!=(float value) const;
        bool operator>(float value) const;
        bool operator<(float value) const;
        bool operator>=(float value) const;
        bool operator<=(float value) const;

        friend bool operator==(float value, const Fraction& fraction);
        friend bool operator!=(float value, const Fraction& fraction);
        friend bool operator>(float value, const Fraction& fraction);
        friend bool operator<(float value, const Fraction& fraction);
        friend bool operator>=(float value, const Fraction& fraction);
        friend bool operator<=(float value, const Fraction& fraction);

        friend std::ostream& operator<<(std::ostream& outputStream, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& inputStream, Fraction& fraction);

    private:
        int numerator;
        int denominator;
        void reduce();

    };
}