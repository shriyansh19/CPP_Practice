// Test program for Date class nextDay()

#include <iostream>
#include "ShriyanshKesharwani_Sept24_task1_Date.cpp"

int main() {
    // Case A: Increment into next month
    Date d1(1, 30, 2025);
    std::cout << "Case A: Increment into next month" << std::endl;

    for (int i = 0; i < 3; i++) 
    {
        d1.print();
        std::cout << std::endl;
        d1.nextDay();
    }

    std::cout << "\n";

    // Case B: Increment into next year
    Date d2(12, 31, 2025);
    std::cout << "Case B: Increment into next year" << std::endl;

    for (int i = 0; i < 3; i++) 
    {
        d2.print();
        std::cout << std::endl;
        d2.nextDay();
    }

    std::cout << std::endl;

    // Case C: Test leap year transition
    Date d3(2, 28, 2024); // 2024 is leap year
    std::cout << "Case C: Leap year February transition" << std::endl;

    for (int i = 0; i < 3; i++) 
    {
        d3.print();
        std::cout << std::endl;
        d3.nextDay();
    }

    return 0;
}
