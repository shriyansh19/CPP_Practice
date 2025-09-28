#include <iostream>
#include "ShriyanshKesharwani_Sept26_task2_Complex.h"

int main() {
    Complex x, y, z;

    std::cout << "Enter the complex number y (real and imaginary): ";
    std::cin >> y;
    std::cout << "Enter the complex number z (real and imaginary): ";
    std::cin >> z;

    std::cout << "\ny = " << y;
    std::cout << "\nz = " << z << std::endl;

    x = y + z;
    std::cout << "\nAddition: x = y + z = " << x << std::endl;

    x = y - z;
    std::cout << "Subtraction: x = y - z = " << x << std::endl;

    x = y * z;
    std::cout << "Multiplication: x = y * z = " << x << std::endl;

    std::cout << "\nComparison:\n";
    std::cout << "y == z ? " << (y == z ? "true" : "false") << std::endl;
    std::cout << "y != z ? " << (y != z ? "true" : "false") << std::endl;

    return 0;
}

