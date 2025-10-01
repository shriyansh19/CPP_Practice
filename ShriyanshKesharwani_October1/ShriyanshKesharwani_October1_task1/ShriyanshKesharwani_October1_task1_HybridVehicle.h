#ifndef HYBRIDVEHICLE_H
#define HYBRIDVEHICLE_H

#include <iostream>
#include <string>

class HybridVehicle {
    std::string modelName;
    float electricKm;
    float gasolineKm;
    float gasolineUsed;
    int trips[10];
    int tripCount;

public:
    // Constructor
    HybridVehicle(std::string name = "", float eKm = 0, float gKm = 0, float gUsed = 0);

    // Operator []
    int& operator[](int index);

    // Operator +
    HybridVehicle operator+(const HybridVehicle& other) const;

    // Operator ==
    bool operator==(const HybridVehicle& other) const;

    // Operator =
    HybridVehicle& operator=(const HybridVehicle& other);

    // Operator ++ (prefix)
    HybridVehicle& operator++();

    // Operator () : total distance
    float operator()() const;

    // Operator float() : efficiency
    operator float() const;

    // Friend operator<<
    friend std::ostream& operator<<(std::ostream& os, const HybridVehicle& v);
};

#endif
