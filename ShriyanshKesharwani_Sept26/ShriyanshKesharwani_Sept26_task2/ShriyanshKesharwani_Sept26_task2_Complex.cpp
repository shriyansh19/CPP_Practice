#include "ShriyanshKesharwani_Sept26_task2_Complex.h"

// Constructor
Complex::Complex(double realPart, double imaginaryPart)
    : real(realPart), imaginary(imaginaryPart) {}

// Addition
Complex Complex::operator+(const Complex& operand2) const 
{
    return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

// Subtraction
Complex Complex::operator-(const Complex& operand2) const 
{
    return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

// Multiplication ( (a+bi)(c+di) = (ac - bd) + (ad+bc)i )
Complex Complex::operator*(const Complex& operand2) const {
    return Complex(
        (real * operand2.real - imaginary * operand2.imaginary),
        (real * operand2.imaginary + imaginary * operand2.real)
    );
}

// Equality
bool Complex::operator==(const Complex& operand2) const 
{
    return (real == operand2.real && imaginary == operand2.imaginary);
}

// Inequality
bool Complex::operator!=(const Complex& operand2) const 
{
    return !(*this == operand2);
}

// Input
std::istream& operator>>(std::istream& input, Complex& c) 
{
    input >> c.real >> c.imaginary;
    return input;
}

// Output
std::ostream& operator<<(std::ostream& output, const Complex& c) 
{
    output << "(" << c.real << ", " << c.imaginary << ")";
    return output;
}
