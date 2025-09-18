#include <iostream>
#include <cstdint>  

// Class 
class DetectedObject
{
private:
    uint32_t object_id;  // Unique identifier for the object
    float rel_speed;     // Relative speed with respect to ego vehicle
    float distance;      // Distance from ego vehicle

public:
    // Constructor
    DetectedObject(uint32_t id, float rs, float dist)
    {
        object_id = id;
        rel_speed = rs;
        distance = dist;
    }

    // Display object details
    void display() const {
        std::cout << "Object ID: " << object_id << std::endl;
        std::cout << "Relative Speed: " << rel_speed << " km/h" << std::endl;
        std::cout << "Distance: " << distance << " m" << std::endl;
    }

    // Compare risk level with another object
    bool isHigherRisk(const DetectedObject& other) const
    {
        return (this->distance < other.distance) && (this->rel_speed > other.rel_speed);
    }

    // Update values by passing object by value (copy, no effect on original)
    void updateValuesByValue(DetectedObject obj) {
        obj.rel_speed += 2;
        obj.distance -= 5;
    }

    // Update values by passing object by reference (original is modified)
    void updateValuesByReference(DetectedObject& obj) {
        obj.rel_speed += 2;
        obj.distance -= 5;
    }

    // Getter for distance
    float getDistance() const
    {
        return distance;
    }

    // Getter for relative speed
    float getRelSpeed() const
    {
        return rel_speed;
    }
};

// Function to find the highest risk object
void findHighestRiskObject(DetectedObject* arr, uint32_t size, const DetectedObject*& riskObj)
{
    if (size == 0)
    {
        riskObj = NULL;
        return;
    }

    riskObj = &arr[0];  // Assume first object as highest risk initially

    for (uint32_t i = 1; i < size; i++)
    {
        if (arr[i].isHigherRisk(*riskObj))
        riskObj = &arr[i];
        
    }
}

// Global function to print an object
void printDetectedObject(const DetectedObject& obj)
{
    obj.display();
}

// Global function to print the highest risk object
void printHighestRiskObject(const DetectedObject* obj)
{
    if (obj != nullptr)
    {
        std::cout << "Highest Risk Object:" << std::endl;
        obj->display();
    }
    else
    {
        std::cout << "No high risk object detected." << std::endl;
    }
}

// Global function to update object values by value
void updateObjectValuesByValueGlobal(DetectedObject obj)
{
    obj.updateValuesByValue(obj);
}

// Global function to update object values by reference
void updateObjectValuesByReferenceGlobal(DetectedObject& obj)
{
    obj.updateValuesByReference(obj);
}

// Main function
int main()
{
    // Dynamically allocate array of 3 DetectedObject instances
    DetectedObject* objects = new DetectedObject[3]
    {
        DetectedObject(701, 15, 55),
        DetectedObject(702, 20, 35),
        DetectedObject(703, 10, 30)
    };

    std::cout << "Initial Objects:" << std::endl;
    for (uint32_t i = 0; i < 3; i++)
    {
        printDetectedObject(objects[i]);
        std::cout << std::endl;
    }

    // Update objects using global functions
    std::cout << "Updating Object 1 (By Value):" << std::endl;
    updateObjectValuesByValueGlobal(objects[0]); // No real effect
    printDetectedObject(objects[0]);
    std::cout << std::endl;

    std::cout << "Updating Object 2 (By Reference):" << std::endl;
    updateObjectValuesByReferenceGlobal(objects[1]); // Changes will persist
    printDetectedObject(objects[1]);
    std::cout << std::endl;

    // Find highest risk object
    const DetectedObject* riskObj = nullptr;
    findHighestRiskObject(objects, 3, riskObj);

    // Print highest risk object
    printHighestRiskObject(riskObj);

    // Deallocate heap memory
    delete[] objects;

    return 0;
}
