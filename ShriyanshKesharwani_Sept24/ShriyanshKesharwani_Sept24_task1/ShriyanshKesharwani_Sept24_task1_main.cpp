// Test program for Time class tick() function

#include <iostream>
#include "ShriyanshKesharwani_Sept24_task1_Time.cpp"

int main() {
    // Case A: Increment into next minute
    Time t1(12, 30, 58);
    std::cout << "Case A: Increment into next minute" << std::endl;

    for (int i = 0; i < 5; i++) 
    {
        t1.printStandard();
        std::cout << std::endl;
        t1.tick();
    }

    std::cout << std::endl;

    // Case B: Increment into next hour
    Time t2(8, 59, 58);
    std::cout << "Case B: Increment into next hour" << std::endl;

    for (int i = 0; i < 5; i++) 
    {
        t2.printStandard();
        std::cout << std::endl;
        t2.tick();
    }

    std::cout << std::endl;

    // Case C: Increment into next day
    Time t3(23, 59, 58);
    std::cout << "Case C: Increment into next day" << std::endl;

    for (int i = 0; i < 5; i++) 
    {
        t3.printStandard();
        std::cout << std::endl;
        t3.tick();
    }

    return 0;
}
