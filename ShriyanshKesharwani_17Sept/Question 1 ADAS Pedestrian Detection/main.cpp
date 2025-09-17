#include <iostream>
#include <cstdint>   

class Pedestrian
{
private:
    uint32_t pedestrian_id;         // unique ID for each pedestrian
    float distance_from_vehicle;    // distance in meters

public:
    // Constructor
    Pedestrian(uint32_t id = 0, float distance = 0.0f)
    {
        pedestrian_id = id;
        distance_from_vehicle = distance;
    }

    // Function to update pedestrian distance
    void updateDistance(float newDistance) {
        distance_from_vehicle = newDistance;
    }

    // Getter for distance
    float getDistance() const {
        return distance_from_vehicle;
    }

    // Getter for ID
    uint32_t getID() const
    {
        return pedestrian_id;
    }
};

// Function to find the closest pedestrian
void findClosestPedestrian(Pedestrian* array, uint32_t size, const Pedestrian*& closest) {
    if (size == 0 || array == nullptr)
    {
        closest = nullptr;
        return;
    }

    closest = &array[0];   // assume first pedestrian is closest

    for (uint32_t i = 1; i < size; i++)
    {
        if (array[i].getDistance() < closest->getDistance())
        closest = &array[i];
       
    }
}

// Global function to print pedestrian info
void printPedestrianInfo(const Pedestrian& ped)
{
    std::cout << "Pedestrian ID: " << ped.getID() << ", Distance: " << ped.getDistance() << " meters" << std::endl;
}

// Global function to print closest pedestrian info
void printClosestPedestrian(const Pedestrian* closest)
{
    if (closest != nullptr)
    std::cout << "Closest Pedestrian -> ID: " << closest->getID() << ", Distance: " << closest->getDistance() << " meters" << std::endl;
    else
    std::cout << "No pedestrians detected." << std::endl;
    
}

int main()
{
    // Dynamically allocate array of 3 pedestrians
    Pedestrian* pedestrians = new Pedestrian[3]
    {
        Pedestrian(101, 12.4f),
        Pedestrian(102, 8.7f),
        Pedestrian(103, 15.1f)
    };

    // Print all pedestrians
    std::cout << "All Pedestrians:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        printPedestrianInfo(pedestrians[i]);
    }
    std::cout << std::endl;

    // Find closest pedestrian
    const Pedestrian* closest = nullptr;
    findClosestPedestrian(pedestrians, 3, closest);

    // Print closest pedestrian
    printClosestPedestrian(closest);

    // Deallocate memory
    delete[] pedestrians;
    pedestrians = nullptr;

    return 0;
}
