#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
public:
    Complex(double = 0.0, double = 0.0); // constructor

    // Arithmetic operators
    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&) const;

    // Comparison operators
    bool operator==(const Complex&) const;
    bool operator!=(const Complex&) const;

    // Stream operators
    friend std::istream& operator>>(std::istream&, Complex&);
    friend std::ostream& operator<<(std::ostream&, const Complex&);

private:
    double real;      // real part
    double imaginary; // imaginary part
};

#endif
