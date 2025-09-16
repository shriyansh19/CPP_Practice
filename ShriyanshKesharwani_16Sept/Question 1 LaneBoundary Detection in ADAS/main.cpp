#include <iostream>

class LaneBoundary
{
private:
    float curvature;   // curvature of the lane
    int lane_id;       // unique identifier for the lane

public:
    // Constructor to initialize members
    LaneBoundary(float c, int id)
    {
        curvature = c;
        lane_id = id;
    }

    // Getter function for curvature
    float getCurvature() const {
        return curvature;
    }

    // Getter function for lane_id
    int getLaneId() const {
        return lane_id;
    }

    // Member function to compare curvature
    bool compareCurvature(const LaneBoundary& other) const {
        
        if(this->curvature > other.curvature)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Function to display lane details
    void display() const {
        std::cout << "Lane ID: " << lane_id << ", Curvature: " << curvature << std::endl;
    }
};

// Global function to check if lane1 curvature is greater than lane2
bool isCurvatureGreater(const LaneBoundary& lane1, const LaneBoundary& lane2)
{
    if(lane1.getCurvature() > lane2.getCurvature())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Global function to print lane comparison
void printLaneComparison(const LaneBoundary& lane1, const LaneBoundary& lane2)
{
    if(lane1.getCurvature() > lane2.getCurvature())
    {
        std::cout << "Lane " << lane1.getLaneId() << " has greater curvature." << std::endl;
    }
    else if(lane2.getCurvature() > lane1.getCurvature())
    {
        std::cout << "Lane " << lane2.getLaneId() << " has greater curvature." << std::endl;
    }
    else
    {
        std::cout << "Both lanes have equal curvature." << std::endl;
    }
}

int main()
{
    // Creating objects with sample data
    LaneBoundary lane1(0.015, 1);
    LaneBoundary lane2(0.023, 2);

    // Display lane details
    std::cout << "Lane Details:" << std::endl;
    lane1.display();
    lane2.display();
    std::cout << std::endl;

    // Using member function to compare
    if(lane1.compareCurvature(lane2))
    {
        std::cout << "Using member function: Lane " << lane1.getLaneId() << " has greater curvature." << std::endl;
    }
    else if(lane2.compareCurvature(lane1))
    {
        std::cout << "Using member function: Lane " << lane2.getLaneId() << " has greater curvature." << std::endl;
    }
    else
    {
        std::cout << "Using member function: Both lanes have equal curvature." << std::endl;
    }

    // Using global functions
    std::cout << "Using global function:" << std::endl;
    printLaneComparison(lane1, lane2);

    return 0;
}
