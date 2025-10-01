#include <iostream>
#include <iomanip>
#include "ShriyanshKesharwani_October1_task1_HybridVehicle.h"

int main() {
    // Create sample vehicles
    HybridVehicle v1("Prius", 120.5, 80.0, 4.5);
    HybridVehicle v2("Volt", 100.0, 90.0, 5.0);

    // Assign trips
    v1[0] = 50; 
    v1[1] = 60;
    v2[0] = 70; 
    v2[1] = 40;

    // 1. Display both vehicles
    std::cout << "Vehicle 1: " << v1 << std::endl;
    std::cout << "Vehicle 2: " << v2 << std::endl;

    // 2. Use + to combine
    HybridVehicle v3 = v1 + v2;
    std::cout << "Combined Vehicle: " << v3 << std::endl;

    // 3. Compare efficiency
    if (v1 == v2)
    {
        std::cout << "Vehicles have same efficiency.\n";
    }
    else
    {
        std::cout << "Vehicles have different efficiency.\n";
    }

    // 4. ++ operator
    ++v1;
    std::cout << "After adding dummy trip to v1: " << v1 << std::endl;

    // 5. Access a trip using []
    std::cout << "v2's first trip: " << v2[0] << " km" << std::endl;

    // 6. Use () operator
    std::cout << "Total distance of v1: " << v1() << " km" << std::endl;

    // 7. Use float() operator
    std::cout << "Fuel efficiency of v2: " << (float)(v2) << " km/L" << std::endl;

    // 8. Test = deep copy
    HybridVehicle v4;
    v4 = v1;
    std::cout << "v4 (copy of v1): " << v4 << std::endl;

    return 0;
}
