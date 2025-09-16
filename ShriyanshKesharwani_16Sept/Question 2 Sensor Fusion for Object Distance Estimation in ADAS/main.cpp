#include <iostream>

class ObjectDistance {
private:
    float radar_distance;    // distance measured by radar
    float camera_distance;   // distance measured by camera

public:
    // Constructor to initialize distances
    ObjectDistance(float radar, float camera)
    {
        radar_distance = radar;
        camera_distance = camera;
    }

    // Function to adjust distances by passing object by value
    void adjustDistancesByValue(ObjectDistance obj) {
        // Adding +5.0 to local copy (will not affect original object)
        obj.radar_distance = obj.radar_distance + 5.0;
        obj.camera_distance = obj.camera_distance + 5.0;

        std::cout << "Inside adjustDistancesByValue (local changes only):" << std::endl;
        std::cout << "Radar Distance: " << obj.radar_distance << ", Camera Distance: " << obj.camera_distance << std::endl;
    }

    // Function to adjust distances by passing object by reference
    void adjustDistancesByReference(ObjectDistance& obj)
    {
        // Adding +5.0 to actual object (changes will persist)
        obj.radar_distance = obj.radar_distance + 5.0;
        obj.camera_distance = obj.camera_distance + 5.0;
    }

    // Getter functions
    float getRadarDistance() const {
        return radar_distance;
    }

    float getCameraDistance() const
    {
        return camera_distance;
    }
};

// Global function to print distances
void printObjectDistance(const ObjectDistance& obj)
{
    std::cout << "Radar Distance: " << obj.getRadarDistance() << ", Camera Distance: " << obj.getCameraDistance() << std::endl;
}

// Global function to create an object on heap
ObjectDistance* createObjectDistanceOnHeap(float radar, float camera) {
    ObjectDistance* ptr = new ObjectDistance(radar, camera);
    return ptr;
}

int main()
{
    // Create object on heap
    ObjectDistance* objPtr = createObjectDistanceOnHeap(35.5, 34.8);

    std::cout << "Initial Distances:" << std::endl;
    printObjectDistance(*objPtr);
    std::cout << std::endl;

    // Call adjust by value (no permanent effect)
    objPtr->adjustDistancesByValue(*objPtr);

    std::cout << "After adjustDistancesByValue (original unchanged):" << std::endl;
    printObjectDistance(*objPtr);
    std::cout << std::endl;

    // Call adjust by reference (permanent effect)
    objPtr->adjustDistancesByReference(*objPtr);

    std::cout << "After adjustDistancesByReference (original updated):" << std::endl;
    printObjectDistance(*objPtr);
    std::cout << std::endl;

    // Properly delete heap object
    delete objPtr;
    objPtr = nullptr;

    return 0;
}
