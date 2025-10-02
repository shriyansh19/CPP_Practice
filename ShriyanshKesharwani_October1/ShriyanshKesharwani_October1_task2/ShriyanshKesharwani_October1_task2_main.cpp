#include "ShriyanshKesharwani_October1_task2_BatteryMonitor.h"
#include <iostream>

int main() {
    // Create two scooters
    BatteryMonitor s1("SCT101", 300, 4.0, 5.0, true, 3); // 80% health
    BatteryMonitor s2("SCT202", 150, 3.5, 5.0, true, 2); // 70% health

    // Populate trips
    s1[0] = 12; s1[1] = 18; s1[2] = 25;
    s2[0] = 10; s2[1] = 15;

    // Display scooters
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    // Compare health
    std::cout << "Is s1 healthier than s2? " << (s1 > s2 ? "Yes" : "No") << std::endl;

    // Simulate charge cycles
    s1 += 50;
    std::cout << "After +50 cycles: " << s1 << std::endl;

    // Inactive check
    std::cout << "Is s1 inactive? " << (!s1 ? "Yes" : "No") << std::endl;

    // Deep copy test
    BatteryMonitor s3 = s1; // copy constructor
    std::cout << "Copied s3: " << s3 << std::endl;

    return 0;
}
