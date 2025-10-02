#include "ShriyanshKesharwani_October1_task2_BatteryMonitor.h"

// Constructor
BatteryMonitor::BatteryMonitor(const std::string& id, int cycles, float currCap, float origCap, bool active, int trips) : scooterID(id), chargeCycles(cycles), batteryCapacity(currCap), originalCapacity(origCap), isActive(active), tripCount(trips) 
{
    tripDistances = new int[tripCount];
    for (int i = 0; i < tripCount; ++i) 
    {
        tripDistances[i] = 0;
    }
}

// Copy constructor (deep copy)
BatteryMonitor::BatteryMonitor(const BatteryMonitor& other) : scooterID(other.scooterID), chargeCycles(other.chargeCycles), batteryCapacity(other.batteryCapacity), originalCapacity(other.originalCapacity), isActive(other.isActive), tripCount(other.tripCount) 
{
    tripDistances = new int[tripCount];
    for (int i = 0; i < tripCount; ++i) {
        tripDistances[i] = other.tripDistances[i];
    }
}

// Assignment operator (deep copy + self-check)
BatteryMonitor& BatteryMonitor::operator=(const BatteryMonitor& other) {
    if (this != &other) 
    {
        delete[] tripDistances;

        scooterID = other.scooterID;
        chargeCycles = other.chargeCycles;
        batteryCapacity = other.batteryCapacity;
        originalCapacity = other.originalCapacity;
        isActive = other.isActive;
        tripCount = other.tripCount;

        tripDistances = new int[tripCount];

        for (int i = 0; i < tripCount; ++i) 
        {
            tripDistances[i] = other.tripDistances[i];
        }
    }
    return *this;
}

// Destructor
BatteryMonitor::~BatteryMonitor() 
{
    delete[] tripDistances;
}

// Compare battery health
bool BatteryMonitor::operator>(const BatteryMonitor& other) const 
{
    return getHealth() > other.getHealth();
}

bool BatteryMonitor::operator<(const BatteryMonitor& other) const {
    return getHealth() < other.getHealth();
}

// += (add charge cycles & simulate degradation)
BatteryMonitor& BatteryMonitor::operator+=(int cycles) {
    chargeCycles += cycles;
    // Simple degradation model: every 100 cycles reduces 1% capacity
    batteryCapacity -= (originalCapacity * 0.01f) * (cycles / 100.0f);

    if (batteryCapacity < 0) 
    {
        batteryCapacity = 0;
    }

    return *this;
}

// [] access trip
int& BatteryMonitor::operator[](int index) {
    if (index < 0 || index >= tripCount) 
    {
        throw std::out_of_range("Trip index out of range");
    }
    return tripDistances[index];
}

// (inactive check)
bool BatteryMonitor::operator!() const {
    return !isActive;
}

// << print
std::ostream& operator<<(std::ostream& os, const BatteryMonitor& bm) {
    os << "Scooter ID: " << bm.scooterID
       << " | Cycles: " << bm.chargeCycles
       << " | Current Cap: " << bm.batteryCapacity << " kWh"
       << " | Health: " << bm.getHealth() * 100 << "%"
       << " | Status: " << (bm.isActive ? "Active" : "Inactive");
    return os;
}

// Utility: health ratio
float BatteryMonitor::getHealth() const 
{
    return (originalCapacity > 0) ? (batteryCapacity / originalCapacity) : 0.0f;
}
