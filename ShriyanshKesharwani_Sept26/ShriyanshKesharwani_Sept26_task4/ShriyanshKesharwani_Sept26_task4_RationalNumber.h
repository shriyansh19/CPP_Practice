#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>

class RationalNumber {
private:
    int numerator;     // stores numerator
    int denominator;   // stores denominator

    // helper function to calculate greatest common divisor
    int gcd(int a, int b) const;

    // function to simplify the fraction
    void simplify();

public:
    // constructor with default values
    RationalNumber(int num = 0, int den = 1);

    // operator overloads for arithmetic
    RationalNumber operator+(const RationalNumber& other) const;
    RationalNumber operator-(const RationalNumber& other) const;
    RationalNumber operator*(const RationalNumber& other) const;
    RationalNumber operator/(const RationalNumber& other) const;

    // operator overloads for comparison
    bool operator==(const RationalNumber& other) const;
    bool operator!=(const RationalNumber& other) const;
    bool operator<(const RationalNumber& other) const;
    bool operator<=(const RationalNumber& other) const;
    bool operator>(const RationalNumber& other) const;
    bool operator>=(const RationalNumber& other) const;

    // display function
    void print() const;
};

#endif
