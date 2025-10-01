#include "ShriyanshKesharwani_October1_task1_HybridVehicle.h"
#include <cmath>
#include <stdexcept>

// Constructor
HybridVehicle::HybridVehicle(std::string name, float eKm, float gKm, float gUsed) {
    modelName = name;
    electricKm = eKm;
    gasolineKm = gKm;
    gasolineUsed = gUsed;
    tripCount = 0;

    for (int i = 0; i < 10; i++)
    {
        trips[i] = 0;
    }
}

// Operator [] 
int& HybridVehicle::operator[](int index) {
    if (index >= 0 && index < 10) 
    {
        if (index >= tripCount)
        {
            tripCount = index + 1;
        }

        return trips[index];
    }

    throw std::out_of_range("Invalid trip index");
}

// Operator +
HybridVehicle HybridVehicle::operator+(const HybridVehicle& other) const {
    HybridVehicle result("Combined");
    result.electricKm = electricKm + other.electricKm;
    result.gasolineKm = gasolineKm + other.gasolineKm;
    result.gasolineUsed = gasolineUsed + other.gasolineUsed;

    result.tripCount = std::min(tripCount + other.tripCount, 10);
    int idx = 0;

    for (int i = 0; i < tripCount && idx < 10; i++) 
    {
        result.trips[idx++] = trips[i];
    }

    for (int j = 0; j < other.tripCount && idx < 10; j++)
    {
        result.trips[idx++] = other.trips[j];
    }

    return result;
}

// Operator ==
bool HybridVehicle::operator==(const HybridVehicle& other) const {

    float eff1 = (gasolineUsed > 0) ? (electricKm + gasolineKm) / gasolineUsed : 0;
    float eff2 = (other.gasolineUsed > 0) ? (other.electricKm + other.gasolineKm) / other.gasolineUsed : 0;

    return (std::fabs(eff1 - eff2) < 1e-6);
}

// Operator =
HybridVehicle& HybridVehicle::operator=(const HybridVehicle& other) {
    if (this != &other) 
    {
        modelName = other.modelName;
        electricKm = other.electricKm;
        gasolineKm = other.gasolineKm;
        gasolineUsed = other.gasolineUsed;
        tripCount = other.tripCount;

        for (int i = 0; i < 10; i++) 
        {
            trips[i] = other.trips[i];
        }
    }
    return *this;
}

// Operator ++
HybridVehicle& HybridVehicle::operator++() {
    if (tripCount < 10) 
    {
        trips[tripCount++] = 10; // dummy trip
    }
    return *this;
}

// Operator ()
float HybridVehicle::operator()() const {
    return electricKm + gasolineKm;
}

// Operator float()
HybridVehicle::operator float() const {
    return (gasolineUsed > 0) ? (electricKm + gasolineKm) / gasolineUsed : 0;
}

// Operator <<
std::ostream& operator<<(std::ostream& os, const HybridVehicle& v) {
    os << "Model: " << v.modelName << " | Electric Km: " << v.electricKm << " | Gasoline Km: " << v.gasolineKm << " | Gasoline Used: " << v.gasolineUsed << " | Trips: ";

    for (int i = 0; i < v.tripCount; i++) 
    {
        os << v.trips[i] << " ";
    }
    
    return os;
}
