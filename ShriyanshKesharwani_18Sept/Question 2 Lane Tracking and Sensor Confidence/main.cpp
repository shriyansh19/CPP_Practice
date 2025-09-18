#include <iostream>

// EgoVehicleData class definition
class EgoVehicleData {
private:
    int num_lanes;                 // number of lanes
    float* lane_positions;         // dynamic array for lane positions
    float* sensor_confidence;      // dynamic array for sensor confidence scores

public:
    // Constructor
    EgoVehicleData(int n, const float* lanes, const float* confidence) {
        num_lanes = n;

        // Allocate memory for lane positions
        lane_positions = new float[num_lanes];
        for (int i = 0; i < num_lanes; i++) {
            lane_positions[i] = lanes[i];
        }

        // Allocate memory for sensor confidence
        sensor_confidence = new float[num_lanes];
        for (int i = 0; i < num_lanes; i++) 
        {
            sensor_confidence[i] = confidence[i];
        }
    }

    // Destructor
    ~EgoVehicleData() {
        delete[] lane_positions;
        delete[] sensor_confidence;
    }

    // Compute average lane position
    float getAverageLanePosition() const 
    {
        float sum = 0.0f;
        for (int i = 0; i < num_lanes; i++) {
            sum += lane_positions[i];
        }
        return sum / num_lanes;
    }

    // Multiply all sensor confidence scores by factor
    void updateSensorConfidence(float factor) {
        for (int i = 0; i < num_lanes; i++) {
            sensor_confidence[i] *= factor;
        }
    }

    // Calculate total confidence score
    float totalConfidence() const {
        float sum = 0.0f;
        for (int i = 0; i < num_lanes; i++) {
            sum += sensor_confidence[i];
        }
        return sum;
    }

    // Friend functions for printing
    friend void printEgoVehicleData(const EgoVehicleData& data);
    friend void findHighestConfidenceVehicle(EgoVehicleData* array, int size, const EgoVehicleData*& highest);
};

// Print EgoVehicleData details
void printEgoVehicleData(const EgoVehicleData& data) {
    std::cout << "Lane Positions: ";
    for (int i = 0; i < data.num_lanes; i++) {
        std::cout << data.lane_positions[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sensor Confidence Scores: ";
    for (int i = 0; i < data.num_lanes; i++) {
        std::cout << data.sensor_confidence[i] << " ";
    }
    std::cout << std::endl;
}

// Find vehicle with highest confidence sum
void findHighestConfidenceVehicle(EgoVehicleData* array, int size, const EgoVehicleData*& highest) {
    if (size <= 0) {
        highest = nullptr;
        return;
    }

    highest = &array[0];
    float maxConfidence = array[0].totalConfidence();

    for (int i = 1; i < size; i++) {
        float current = array[i].totalConfidence();
        if (current > maxConfidence) {
            maxConfidence = current;
            highest = &array[i];
        }
    }
}

// Print highest confidence vehicle
void printHighestConfidenceVehicle(const EgoVehicleData* vehicle) {
    if (vehicle != nullptr) {
        std::cout << "Vehicle with Highest Confidence: " << std::endl;
        printEgoVehicleData(*vehicle);
    } else {
        std::cout << "No vehicle data available." << std::endl;
    }
}

// Main function
int main() {
    // Sample data
    float lanes1[3] = {3.2f, 3.0f, 3.4f};
    float conf1[3]  = {0.95f, 0.97f, 0.93f};

    float lanes2[3] = {2.9f, 2.8f, 3.1f};
    float conf2[3]  = {0.92f, 0.90f, 0.88f};

    float lanes3[3] = {3.4f, 3.5f, 3.6f};
    float conf3[3]  = {0.99f, 0.98f, 0.97f};

    // Dynamically create 3 EgoVehicleData objects in an array
    EgoVehicleData* vehicles = new EgoVehicleData[3]{
        EgoVehicleData(3, lanes1, conf1),
        EgoVehicleData(3, lanes2, conf2),
        EgoVehicleData(3, lanes3, conf3)
    };

    // Update confidence values with different factors
    vehicles[0].updateSensorConfidence(1.05f); // Slight boost
    vehicles[1].updateSensorConfidence(0.95f); // Slight decrease
    vehicles[2].updateSensorConfidence(1.10f); // Strong boost

    // Print all vehicles
    for (int i = 0; i < 3; i++) {
        std::cout << "Vehicle " << i + 1 << " Data:" << std::endl;
        printEgoVehicleData(vehicles[i]);
        std::cout << std::endl;
    }

    // Find highest confidence vehicle
    const EgoVehicleData* highest = nullptr;
    findHighestConfidenceVehicle(vehicles, 3, highest);

    // Print result
    printHighestConfidenceVehicle(highest);

    // Free memory
    delete[] vehicles;

    return 0;
}
