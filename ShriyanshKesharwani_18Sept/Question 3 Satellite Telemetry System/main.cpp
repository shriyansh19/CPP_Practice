#include <iostream>
#include <string>

// Enum for satellite status
enum SatelliteStatus {
    OPERATIONAL,
    MAINTENANCE,
    DECOMMISSIONED
};

// SatelliteData class
class SatelliteData {
private:
    int satellite_id;
    int num_antennas;
    float* signal_strength;            
    float orbital_altitude;
    SatelliteStatus status;
    static int active_satellites;      

public:
    // Constructor
    SatelliteData(int id, int antennas, const float* signals, float altitude, SatelliteStatus st) 
    {
        satellite_id = id;
        num_antennas = antennas;
        orbital_altitude = altitude;
        status = st;

        // allocate memory
        signal_strength = new float[num_antennas];

        for (int i = 0; i < num_antennas; i++) 
        signal_strength[i] = signals[i];
        

        active_satellites++;
    }

    // Copy Constructor (deep copy)
    SatelliteData(const SatelliteData& other) 
    {
        satellite_id = other.satellite_id;
        num_antennas = other.num_antennas;
        orbital_altitude = other.orbital_altitude;
        status = other.status;

        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; i++) 
        signal_strength[i] = other.signal_strength[i];
       

        active_satellites++;
    }

    // Destructor
    ~SatelliteData() 
    {
        delete[] signal_strength;
        active_satellites--;
    }

    // Average signal strength
    float getAverageSignalStrength() const 
    {
        float sum = 0.0;

        for (int i = 0; i < num_antennas; i++)
        sum += signal_strength[i];
       
        return sum / num_antennas;
    }

    // Boost all signals by factor
    void boostSignal(float factor) 
    {
        for (int i = 0; i < num_antennas; i++) 
        signal_strength[i] *= factor;
      
    }

    // Boost only signals below threshold
    void boostSignal(float factor, float threshold) 
    {
        for (int i = 0; i < num_antennas; i++) {
            if (signal_strength[i] < threshold) 
            {
                signal_strength[i] *= factor;
            }
        }
    }

    // Update satellite status
    void setStatus(SatelliteStatus new_status) 
    {
        status = new_status;
    }

    // Get status as string
    std::string getStatusString() const {

        switch (status) {
            case OPERATIONAL: 
            return "Operational";

            case MAINTENANCE: 
            return "Maintenance";

            case DECOMMISSIONED: 
            return "Decommissioned";

            default: 
            return "Unknown";
        }
    }

    // Get orbital altitude
    float getAltitude() const {
        return orbital_altitude;
    }

    // Get satellite id
    int getId() const {
        return satellite_id;
    }

    // Get number of antennas
    int getNumAntennas() const 
    {
        return num_antennas;
    }

    // Get signal strength array
    const float* getSignals() const {
        return signal_strength;
    }

    // Static function for active count
    static int getActiveSatelliteCount() {
        return active_satellites;
    }
};

// Initialize static member
int SatelliteData::active_satellites = 0;

// Global functions
void printSatelliteData(const SatelliteData& sd)
 {
    std::cout << "Satellite ID: " << sd.getId() << std::endl;
    std::cout << "Orbital Altitude: " << sd.getAltitude() << " km" << std::endl;
    std::cout << "Signal Strengths: ";
    const float* signals = sd.getSignals();

    for (int i = 0; i < sd.getNumAntennas(); i++) {
        std::cout << signals[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "Status: " << sd.getStatusString() << std::endl;
    std::cout << "Average Signal Strength: " << sd.getAverageSignalStrength() << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

// Compare altitude
bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2) {
    return s1.getAltitude() > s2.getAltitude();
}

// Clone satellite
void cloneSatellite(const SatelliteData& source, SatelliteData*& target) {
    target = new SatelliteData(source);  // invokes copy constructor
}

// Print active satellites
void printActiveSatelliteCount() {
    std::cout << "Active Satellites: " << SatelliteData::getActiveSatelliteCount() << std::endl;
}

// Update status if weak signal
void updateStatusIfWeak(SatelliteData& sd, float confidence_threshold) {
    if (sd.getAverageSignalStrength() < confidence_threshold) {
        sd.setStatus(MAINTENANCE);
    }
}

// Main function
int main() {
    // Sample data
    float signals1[3] = {78.5f, 80.2f, 79.0f};
    float signals2[2] = {75.0f, 76.5f};

    // Create two satellites
    SatelliteData* sat1 = new SatelliteData(101, 3, signals1, 550.0f, OPERATIONAL);
    SatelliteData* sat2 = new SatelliteData(102, 2, signals2, 600.0f, MAINTENANCE);

    // Print initial satellites
    std::cout << "Initial Satellite Data:" << std::endl;
    printSatelliteData(*sat1);
    printSatelliteData(*sat2);

    // Boost signals
    sat1->boostSignal(1.05f);             // Boost all signals
    sat2->boostSignal(1.10f, 76.0f);      // Boost only below threshold

    std::cout << "After Boosting:" << std::endl;
    printSatelliteData(*sat1);
    printSatelliteData(*sat2);

    // Compare altitudes
    if (compareAltitude(*sat1, *sat2))
     {
        std::cout << "Satellite " << sat1->getId() << " has higher altitude." << std::endl;
    } 
    else {
        std::cout << "Satellite " << sat2->getId() << " has higher altitude." << std::endl;
    }

    // Clone satellite 1
    SatelliteData* sat_clone = nullptr;
    cloneSatellite(*sat1, sat_clone);

    std::cout << "Cloned Satellite Data:" << std::endl;
    printSatelliteData(*sat_clone);

    // Update status if weak
    updateStatusIfWeak(*sat1, 79.0f);
    updateStatusIfWeak(*sat2, 79.0f);

    std::cout << "After Status Update:" << std::endl;
    printSatelliteData(*sat1);
    printSatelliteData(*sat2);

    // Print active satellites
    printActiveSatelliteCount();

    // Free memory
    delete sat1;
    delete sat2;
    delete sat_clone;

    printActiveSatelliteCount(); // should decrease

    return 0;
}
