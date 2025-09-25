// Test program 

#include <iostream>
#include "ShriyanshKesharwani_Sept24_task3_DateAndTime.cpp"

int main() {
    // Case: Increment into next minute
    DateAndTime dt1(9, 16, 2025, 10, 59, 58);
    cout << "Incrementing into next minute:\n";
    dt1.printStandard();
    dt1.tick();
    dt1.printStandard();
    dt1.tick();
    dt1.printStandard();

    cout << "\nIncrementing into next hour:\n";
    DateAndTime dt2(9, 16, 2025, 10, 59, 59);
    dt2.printStandard();
    dt2.tick();
    dt2.printStandard();

    cout << "\nIncrementing into next day:\n";
    DateAndTime dt3(12, 31, 2025, 23, 59, 59);
    dt3.printStandard();
    dt3.tick();
    dt3.printStandard();

    return 0;
}
