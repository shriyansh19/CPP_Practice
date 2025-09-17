#include <iostream>

class RadarSignal
{
private:
    int num_channels;          // number of radar channels
    float* signal_strength;    // dynamic array to hold signal strengths

public:
    // Constructor to allocate and initialize signals
    RadarSignal(int num, float* signals){
        num_channels = num;
        signal_strength = new float[num_channels];

        for (int i = 0; i < num_channels; i++) {
            signal_strength[i] = signals[i];
        }
    }

    // Destructor to free memory
    ~RadarSignal()
    {
        delete[] signal_strength;
    }

    // Function to calculate average signal strength
    float averageSignal() const
    {
        float sum = 0.0;

        for (int i = 0; i < num_channels; i++)
        {
            sum = sum + signal_strength[i];
        }

        return sum / num_channels;
    }

    // Boost signals by value (does not affect original object)
    void boostSignalByValue(RadarSignal obj)
    {
        for (int i = 0; i < obj.num_channels; i++) {
            obj.signal_strength[i] = obj.signal_strength[i] + 5.0f;
        }

        std::cout << "Inside boostSignalByValue: " << std::endl;
        for (int i = 0; i < obj.num_channels; i++){
            std::cout << "Channel " << i << ": " << obj.signal_strength[i] << std::endl;
        }
    }

    // Boost signals by reference (affects original object)
    void boostSignalByReference(RadarSignal& obj)
    {
        for (int i = 0; i < obj.num_channels; i++)
        {
            obj.signal_strength[i] = obj.signal_strength[i] + 5.0f;
        }
    }

    // Getter for number of channels
    int getNumChannels() const
    {
        return num_channels;
    }

    // Getter for individual signal strength
    float getSignalStrength(int index) const
    {
        return signal_strength[index];
    }
};

// Global function to print radar signal strengths
void printRadarSignal(const RadarSignal& radar)
{
    std::cout << "Radar Signal Strengths:" << std::endl;

    for (int i = 0; i < radar.getNumChannels(); i++){
        std::cout << "Channel " << i << ": " << radar.getSignalStrength(i) << std::endl;
    }
}

// Global function to create RadarSignal on heap
RadarSignal* createRadarSignalHeap(int num, float* signals)
{
    RadarSignal* ptr = new RadarSignal(num, signals);
    return ptr;
}

int main()
{
    // Sample data
    int num_channels = 4;
    float signals[4] = {55.5f, 48.2f, 60.1f, 52.6f};

    // Create RadarSignal object on heap
    RadarSignal* radarPtr = createRadarSignalHeap(num_channels, signals);

    // Print initial signals
    std::cout << "Initial Radar Signals:" << std::endl;
    printRadarSignal(*radarPtr);
    std::cout << std::endl;

    // Call boost by value (does not modify original)
    radarPtr->boostSignalByValue(*radarPtr);

    std::cout << "After boostSignalByValue (original unchanged):" << std::endl;
    printRadarSignal(*radarPtr);
    std::cout << std::endl;

    // Call boost by reference (modifies original)
    radarPtr->boostSignalByReference(*radarPtr);

    std::cout << "After boostSignalByReference (original updated):" << std::endl;
    printRadarSignal(*radarPtr);
    std::cout << std::endl;

    // Show average signal strength
    std::cout << "Average Signal Strength: " << radarPtr->averageSignal() << std::endl;

    // Delete heap object
    delete radarPtr;
    radarPtr = NULL;

    return 0;
}
