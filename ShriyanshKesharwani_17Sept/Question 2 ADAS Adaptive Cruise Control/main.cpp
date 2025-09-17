#include <iostream>
#include <cstdint>
#include <climits>

class TrackedVehicle {
    uint32_t vehicle_id;
    float speed;
    float distance;

    // Static members to track minimal distance and vehicle count
    static float min_recorded_distance;
    static int vehicle_count;

public:
    // Constructor initializes members and updates static members
    TrackedVehicle(uint32_t id, float spd, float dist) 
    {
        vehicle_id = id;
        speed = spd;
        distance = dist;
        vehicle_count++; // Increment count when new object is created

        // Update minimum recorded distance if this distance is smaller
        if (dist < min_recorded_distance) {
            min_recorded_distance = dist;
        }
    }

    // Display details of the vehicle
    void display() const {
        std::cout << "Vehicle ID: " << vehicle_id << ", Speed: " << speed << ", Distance: " << distance << std::endl;
    }

    // Compare distance with another vehicle, return pointer to the nearer one
    const TrackedVehicle* compareDistance(const TrackedVehicle& other) const
     {
        if (distance < other.distance) {
            return this;
        } 
        else if (other.distance < distance) 
        {
            return &other;
        }
        // If equal, return this
        return this;
    }

    // Static getter for minimum recorded distance
    static float getMinRecordedDistance() 
    {
        return min_recorded_distance;
    }

    // Static getter for vehicle count
    static int getVehicleCount() 
    {
        return vehicle_count;
    }

    // Getter for distance, used in global functions
    float getDistance() const 
    {
        return distance;
    }
};

// Define initial static member values
float TrackedVehicle::min_recorded_distance = INT_MAX;
int TrackedVehicle::vehicle_count = 0;

// Find the lead (nearest) vehicle in an array
void findLeadVehicle(TrackedVehicle* arr, uint32_t size, const TrackedVehicle*& lead) 
{
    lead = 0;
    if (size == 0) return;
    lead = &arr[0];
    for (uint32_t i = 1; i < size; i++) 
    {
        if (arr[i].getDistance() < lead->getDistance()) 
        {
            lead = &arr[i];
        }
    }
}

// Print tracked vehicle details (global function)
void printTrackedVehicle(const TrackedVehicle& vehicle) {
    vehicle.display();
}

// Print lead vehicle or "None found"
void printLeadVehicle(const TrackedVehicle* lead) {
    if (lead) {
        std::cout << "Lead Vehicle:" << std::endl;
        lead->display();
    } 
    else 
    {
        std::cout << "None found" << std::endl;
    }
}

int main() {
    // Dynamically allocate array of 4 vehicles
    TrackedVehicle* arr = new TrackedVehicle[4]{
        TrackedVehicle(501, 80, 60),
        TrackedVehicle(502, 78, 45),
        TrackedVehicle(503, 85, 100),
        TrackedVehicle(504, 76, 40)
    };

    // Find the lead vehicle (with lowest distance)
    const TrackedVehicle* lead = 0;
    findLeadVehicle(arr, 4, lead);

    // Print all vehicle details
    for (int i = 0; i < 4; i++) {
        printTrackedVehicle(arr[i]);
    }

    // Print the lead vehicle
    printLeadVehicle(lead);

    // Print minimum recorded distance and vehicle count
    std::cout << "Minimum Recorded Distance: " << TrackedVehicle::getMinRecordedDistance() << std::endl;
    std::cout << "Total Vehicles Created: " << TrackedVehicle::getVehicleCount() << std::endl;

    // Clean up memory
    delete[] arr;
    return 0;
}
