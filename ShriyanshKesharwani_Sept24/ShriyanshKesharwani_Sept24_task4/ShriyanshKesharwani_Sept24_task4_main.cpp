#include "ShriyanshKesharwani_Sept24_task4_Time.cpp"

int main() {
    Time t; // default 00:00:00

    std::cout << "Initial universal time: ";
    t.printUniversal();
    std::cout << "\nInitial standard time: ";
    t.printStandard();
    std::cout<< "\n\n";

    // Valid set
    if (!t.setTime(13, 27, 45)) 
    {
        std::cout << "Error: Invalid time!\n";
    }

    std::cout << "After setting valid time:\n";
    t.printUniversal(); 
    std::cout << " (Universal)\n";
    t.printStandard();  
    std::cout << " (Standard)\n\n";

    // Invalid set
    if (!t.setHour(99)) 
    {
        std::cout << "Error: Invalid hour (99)\n";
    }
    if (!t.setMinute(75)) 
    {
        std::cout << "Error: Invalid minute (75)\n";
    }
    if (!t.setSecond(-5)) 
    {
        std::cout << "Error: Invalid second (-5)\n";
    }

    std::cout << "\nFinal time:\n";
    t.printUniversal(); 
    std::cout << " (Universal)\n";
    t.printStandard();  
    std::cout << " (Standard)\n";

    return 0;
}
