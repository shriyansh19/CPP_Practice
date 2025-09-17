#include <iostream>

class CameraConfig
{
private:
    int num_modes;                // number of camera modes
    int* resolution_width;        // dynamic array for width of each mode
    int* resolution_height;       // dynamic array for height of each mode

public:
    // Constructor to allocate arrays dynamically and initialize them
    CameraConfig(int modes, const int* widths, const int* heights)
    {
        num_modes = modes;

        // allocate memory for dynamic arrays
        resolution_width = new int[num_modes];
        resolution_height = new int[num_modes];

        // copy values into arrays
        for (int i = 0; i < num_modes; i++)
        {
            resolution_width[i] = widths[i];
            resolution_height[i] = heights[i];
        }
    }

    // Copy constructor for deep copy
    CameraConfig(CameraConfig& other)
    {
        num_modes = other.num_modes;

        resolution_width = new int[num_modes];
        resolution_height = new int[num_modes];

        for (int i = 0; i < num_modes; i++)
        {
            resolution_width[i] = other.resolution_width[i];
            resolution_height[i] = other.resolution_height[i];
        }
    }

    // Destructor to free allocated memory
    ~CameraConfig()
    {
        delete[] resolution_width;
        delete[] resolution_height;
    }

    // Const function to print configuration of all modes
    void printConfig() const
    {
        std::cout << "Camera Configuration:" << std::endl;
        for (int i = 0; i < num_modes; i++)
        {
            std::cout << "Mode " << i << " -> " << resolution_width[i] << " x " << resolution_height[i]  << std::endl;
        }
    }

    // Function to check if resolution of mode1 is higher than mode2
    bool isHigherResolution(int mode1, int mode2) const
    {
        int res1 = resolution_width[mode1] * resolution_height[mode1];
        int res2 = resolution_width[mode2] * resolution_height[mode2];

        return this->resolution_width[mode1] * this->resolution_height[mode1] > this->resolution_width[mode2] * this->resolution_height[mode2];
    }
};

// Global function to print camera configuration
void printCameraConfig(const CameraConfig& config)
{
    config.printConfig();
}

// Global function to compare resolutions using member function
bool globalCompareResolution(const CameraConfig& config, int m1, int m2) {
    return config.isHigherResolution(m1, m2);
}

int main() {
    // Sample data for initialization
    int widths[3] = {1920, 1280, 3840};
    int heights[3] = {1080, 2160, 2160};

    // Create CameraConfig object
    CameraConfig config(3, widths, heights);

    // Print configuration using member function
    config.printConfig();
    std::cout << std::endl;

    // Compare resolution of mode 0 and mode 2 using member function
    if (config.isHigherResolution(0, 2))
    {
        std::cout << "Mode 0 has higher resolution than Mode 2 (Member function)" << std::endl;
    }
    else
    {
        std::cout << "Mode 2 has higher or equal resolution than Mode 0 (Member function)" << std::endl;
    }

    // Compare resolution of mode 0 and mode 2 using global function
    if (globalCompareResolution(config, 0, 2))
    {
        std::cout << "Mode 0 has higher resolution than Mode 2 (Global function)" << std::endl;
    }
    else
    {
        std::cout << "Mode 2 has higher or equal resolution than Mode 0 (Global function)" << std::endl;
    }

    return 0;
}
