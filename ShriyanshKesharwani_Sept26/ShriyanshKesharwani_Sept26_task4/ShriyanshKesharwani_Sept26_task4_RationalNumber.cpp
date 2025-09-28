#include "ShriyanshKesharwani_Sept26_task4_RationalNumber.h"
#include <stdexcept>  

// calculate gcd using Euclidean algorithm
int32_t RationalNumber::gcd(int32_t a, int32_t b) const {
    while (b != 0) {
        int32_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// simplify fraction
void RationalNumber::simplify() {

    if (denominator < 0) 
    {
        numerator = -numerator;
        denominator = -denominator;
    }
    int divisor = gcd(abs(numerator), abs(denominator));

    if (divisor != 0) 
    {
        numerator /= divisor;
        denominator /= divisor;
    }
}

// constructor
RationalNumber::RationalNumber(int num, int den) {

    if (den == 0) 
    {
        throw std::runtime_error("Denominator cannot be zero.");
    }

    numerator = num;
    denominator = den;
    simplify();
}

// addition
RationalNumber RationalNumber::operator+(const RationalNumber& other) const 
{
    return RationalNumber(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

// subtraction
RationalNumber RationalNumber::operator-(const RationalNumber& other) const 
{
    return RationalNumber(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}

// multiplication
RationalNumber RationalNumber::operator*(const RationalNumber& other) const 
{
    return RationalNumber(numerator * other.numerator, denominator * other.denominator);
}

// division
RationalNumber RationalNumber::operator/(const RationalNumber& other) const {
    if (other.numerator == 0) 
    {
        throw std::runtime_error("Division by zero.");
    }

    return RationalNumber(numerator * other.denominator, denominator * other.numerator);
}

// equality
bool RationalNumber::operator==(const RationalNumber& other) const 
{
    return numerator == other.numerator && denominator == other.denominator;
}

bool RationalNumber::operator!=(const RationalNumber& other) const 
{
    return !(*this == other);
}

// relational operators
bool RationalNumber::operator<(const RationalNumber& other) const 
{
    return numerator * other.denominator < other.numerator * denominator;
}

bool RationalNumber::operator<=(const RationalNumber& other) const 
{
    return *this < other || *this == other;
}

bool RationalNumber::operator>(const RationalNumber& other) const 
{
    return !(*this <= other);
}

bool RationalNumber::operator>=(const RationalNumber& other) const 
{
    return !(*this < other);
}

// print function
void RationalNumber::print() const 
{
    std::cout << numerator << "/" << denominator;
}
