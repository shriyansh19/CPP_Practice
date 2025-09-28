#include "ShriyanshKesharwani_Sept26_task4_RationalNumber.h"
#include <iostream>

int main() {
    RationalNumber r1(2, 4);   // should reduce to 1/2
    RationalNumber r2(3, 9);   // should reduce to 1/3

    std::cout << "First rational number: ";
    r1.print();

    std::cout << "\nSecond rational number: ";
    r2.print();

    // arithmetic operations
    RationalNumber sum = r1 + r2;
    RationalNumber diff = r1 - r2;
    RationalNumber prod = r1 * r2;
    RationalNumber quot = r1 / r2;

    std::cout << "\n\nResults:";

    std::cout << "\nSum: "; 
    sum.print();

    std::cout << "\nDifference: "; 
    diff.print();

    std::cout << "\nProduct: "; 
    prod.print();

    std::cout << "\nQuotient: "; 
    quot.print();

    // comparisons
    std::cout << "\n\nComparisons:";
    std::cout << "\nEqual? " << ((r1 == r2) ? "true" : "false");
    std::cout << "\nNot Equal? " << ((r1 != r2) ? "true" : "false");
    std::cout << "\nLess than? " << ((r1 < r2)  ? "true" : "false");
    std::cout << "\nGreater than? " << ((r1 > r2)  ? "true" : "false");

    std::cout << "\n";

    return 0;
}
