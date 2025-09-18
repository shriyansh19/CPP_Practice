#include <iostream>
#include <cstdint>   

// Enumeration for sensor types
enum SensorType
{
    LIDAR,
    RADAR,
    CAMERA
};

// Static function to convert sensor type enum to string
    static const char* sensorTypeToString(SensorType t)
    {
        switch (t)
        {
            case LIDAR:
                return "LIDAR";
            case RADAR:
                return "RADAR";
            case CAMERA:
                return "CAMERA";
            default:
                return "UNKNOWN";
        }
    }

// Class representing a sensor in ADAS
class SensorArray
{
private:
    uint32_t sensor_id;              // Unique identifier
    SensorType type;                 // Sensor type
    double* temperature_readings;    // Dynamic array of readings
    uint32_t num_readings;           // Number of readings

    static double global_max_temperature; // Highest temp across all sensors

public:
    // Constructor
    SensorArray(uint32_t id, SensorType t, const double* readings, uint32_t n)
    {
        sensor_id = id;
        type = t;
        num_readings = n;

        // Allocate memory for readings
        temperature_readings = new double[num_readings];

        for (uint32_t i = 0; i < num_readings; i++)
        {
            temperature_readings[i] = readings[i];

            // Update global maximum temperature if needed
            if (readings[i] > global_max_temperature)
            global_max_temperature = readings[i];
        }
    }

    // Destructor
    ~SensorArray()
    {
        delete[] temperature_readings;
    }

    // Get maximum temperature of this sensor
    double getMaxTemperature() const
    {
        double max_temp = temperature_readings[0];

        for (uint32_t i = 1; i < num_readings; i++)
        {
            if (temperature_readings[i] > max_temp)
            max_temp = temperature_readings[i];
        }
        return max_temp;
    }

    // Print sensor information
    void printSensorInfo() const
    {
        std::cout << "Sensor ID: " << sensor_id << std::endl;
        std::cout << "Sensor Type: " << sensorTypeToString(type) << std::endl;
        std::cout << "Max Temperature: " << getMaxTemperature() << " C" << std::endl;
    }

    // Static function to return global max temperature
    static double getGlobalMaxTemperature() {
        return global_max_temperature;
    }
};

// Define static member
double SensorArray::global_max_temperature = -1e9;

// Global function to print single sensor info
void printSensor(const SensorArray& s)
{
    s.printSensorInfo();
}

// Global function to print all sensors
void printAllSensors(const SensorArray* arr, uint32_t size)
{
    for (uint32_t i = 0; i < size; i++)
    {
        arr[i].printSensorInfo();
        std::cout << std::endl;
    }
}

// Main function
int main()
{
    // Sample data
    double readings1[] = {35.5, 36.1, 34.9};
    double readings2[] = {39.0, 38.7, 39.3};
    double readings3[] = {30.2, 31.0, 30.5};

    // Dynamically allocate array of sensors
    SensorArray* sensors = new SensorArray[3]
    {
        SensorArray(801, LIDAR, readings1, 3),
        SensorArray(802, RADAR, readings2, 3),
        SensorArray(803, CAMERA, readings3, 3)
    };

    std::cout << "Sensor Information:" << std::endl << std::endl;
    printAllSensors(sensors, 3);

    std::cout << "Global Maximum Temperature: " << SensorArray::getGlobalMaxTemperature() << " C" << std::endl;

    // Free allocated memory
    delete[] sensors;

    return 0;
}
