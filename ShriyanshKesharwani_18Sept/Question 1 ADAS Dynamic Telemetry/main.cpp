#include <iostream>

// VehicleStatus class definition
class VehicleStatus {
private:
    int num_wheels;
    float* wheel_speed;   
    int num_temps;
    float* engine_temp;   

public:
    // Constructor
    VehicleStatus(int nw, const float* ws, int nt, const float* et) {
        num_wheels = nw;
        wheel_speed = new float[num_wheels];
        for (int i = 0; i < num_wheels; i++) 
        {
            wheel_speed[i] = ws[i];
        }

        num_temps = nt;
        engine_temp = new float[num_temps];
        for (int i = 0; i < num_temps; i++) 
        {
            engine_temp[i] = et[i];
        }
    }

    // Destructor
    ~VehicleStatus() {
        delete[] wheel_speed;
        delete[] engine_temp;
    }

    // Function to calculate average wheel speed
    float averageWheelSpeed() const 
    {
        float sum = 0.0f;
        for (int i = 0; i < num_wheels; i++) 
        {
            sum += wheel_speed[i];
        }
        return sum / num_wheels;
    }

    // Function to calculate maximum engine temperature
    float maxEngineTemp() const 
    {
        float maxVal = engine_temp[0];
        for (int i = 1; i < num_temps; i++) 
        {
            if (engine_temp[i] > maxVal) 
            {
                maxVal = engine_temp[i];
            }
        }
        return maxVal;
    }

    // Function to calculate maximum wheel speed
    float maxWheelSpeed() const {
        float maxVal = wheel_speed[0];
        for (int i = 1; i < num_wheels; i++) 
        {
            if (wheel_speed[i] > maxVal) 
            {
                maxVal = wheel_speed[i];
            }
        }
        return maxVal;
    }

    // Compare max wheel speed with another vehicle
    bool isWheelSpeedHigher(const VehicleStatus& other) const 
    {
        return this->maxWheelSpeed() > other.maxWheelSpeed(); 
    }

    // Friend global function to print status
    friend void printVehicleStatus(const VehicleStatus& vs);
    friend bool compareWheelSpeedGlobal(const VehicleStatus& vs1, const VehicleStatus& vs2);
};

// Global function to print vehicle status
void printVehicleStatus(const VehicleStatus& vs) 
{
    std::cout << "Wheel Speeds: ";
    for (int i = 0; i < vs.num_wheels; i++) {
        std::cout << vs.wheel_speed[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Engine Temperatures: ";
    for (int i = 0; i < vs.num_temps; i++) {
        std::cout << vs.engine_temp[i] << " ";
    }
    std::cout << std::endl;
}

// Global comparison function
bool compareWheelSpeedGlobal(const VehicleStatus& vs1, const VehicleStatus& vs2) 
{
    return vs1.isWheelSpeedHigher(vs2);
}

// Main function
int main() {
    // Vehicle 1 data
    float wheelSpeeds1[4] = {55.5f, 56.6f, 57.2f, 55.9f};
    float engineTemps1[2] = {90.5f, 88.9f};
    VehicleStatus v1(4, wheelSpeeds1, 2, engineTemps1);

    // Vehicle 2 data
    float wheelSpeeds2[4] = {50.0f, 51.2f, 49.8f, 50.4f};
    float engineTemps2[2] = {92.0f, 89.5f};
    VehicleStatus v2(4, wheelSpeeds2, 2, engineTemps2);

    // Print vehicle statuses
    std::cout << "Vehicle 1 Status:" << std::endl;
    printVehicleStatus(v1);
    std::cout << std::endl;

    std::cout << "Vehicle 2 Status:" << std::endl;
    printVehicleStatus(v2);
    std::cout << std::endl;

    // Compare max wheel speeds
    std::cout << "Is Vehicle 1 max wheel speed higher than Vehicle 2? " << (v1.isWheelSpeedHigher(v2) ? "Yes" : "No") << std::endl;

    std::cout << "Global Comparison: Vehicle 1 has higher max wheel speed than Vehicle 2? " << (compareWheelSpeedGlobal(v1, v2) ? "Yes" : "No") << std::endl;

    return 0;
}
