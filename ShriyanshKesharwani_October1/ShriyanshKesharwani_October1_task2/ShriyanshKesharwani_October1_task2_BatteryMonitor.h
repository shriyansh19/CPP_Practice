#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

#include <iostream>
#include <string>

class BatteryMonitor {
private:
    std::string scooterID;
    int chargeCycles;
    float batteryCapacity;     // current capacity (kWh)
    float originalCapacity;    // original capacity (kWh)
    bool isActive;
    int* tripDistances;        // dynamic array
    int tripCount;

public:
    // Constructor
    BatteryMonitor(const std::string& id, int cycles, float currCap, float origCap, bool active, int trips);

    // Copy constructor
    BatteryMonitor(const BatteryMonitor& other);

    // Assignment operator (deep copy)
    BatteryMonitor& operator=(const BatteryMonitor& other);

    // Destructor
    ~BatteryMonitor();

    // Operator overloads
    bool operator>(const BatteryMonitor& other) const;
    bool operator<(const BatteryMonitor& other) const;
    BatteryMonitor& operator+=(int cycles); // simulate degradation
    int& operator[](int index);
    bool operator!() const; // check inactive
    friend std::ostream& operator<<(std::ostream& os, const BatteryMonitor& bm);

    // Utility
    float getHealth() const;
};

#endif
