#include <iostream>
#include <string>

// FleetVehicle class definition
class FleetVehicle {
private:
    int vehicleID;
    float fuelLevel;
    double distanceTravelled;
    char status;         // 'A' for Active, 'I' for Inactive
    bool isAvailable;
    std::string driverName;

public:
    // Default constructor
    FleetVehicle() {
        vehicleID = 0;
        fuelLevel = 50.0;
        distanceTravelled = 0.0;
        status = 'A';
        isAvailable = true;
        driverName = "Unassigned";
    }

    // Parameterized constructor
    FleetVehicle(int vID, float fuel, double dist, char s, bool avail, std::string dName) {
        vehicleID = vID;
        fuelLevel = fuel;
        distanceTravelled = dist;
        status = s;
        isAvailable = avail;
        driverName = dName;
    }

    // Destructor
    ~FleetVehicle() {
        std::cout << "Destructor called for vehicle ID: " << vehicleID << std::endl;
    }

    // Getters
    int getVehicleID() { 
        return vehicleID; 
    }
    float getFuelLevel() { 
        return fuelLevel; 
    }
    double getDistanceTravelled() {
        return distanceTravelled; 
    }
    char getStatus() { 
        return status; 
    }
    bool getIsAvailable() { 
        return isAvailable; 
    }
    std::string getDriverName() { 
        return driverName; 
    }

    // Setters
    void setVehicleID(int id) { 
        vehicleID = id; 
    }
    void setFuelLevel(float fuel) { 
        fuelLevel = fuel; 
    }
    void setDistanceTravelled(double dist) { 
        distanceTravelled = dist; 
    }
    void setStatus(char s) { 
        status = s; 
    }
    void setIsAvailable(bool avail) { 
        isAvailable = avail; 
    }
    void setDriverName(std::string name) { 
        driverName = name; 
    }

    // Updates the status of the vehicle
    void updateStatus() {
        if (fuelLevel < 10.0 || !isAvailable)
            status = 'I';
        else
            status = 'A';
    }

    // Displays all information about the vehicle
    void displayInfo() {
        std::cout << "----- Vehicle Information -----" << std::endl;
        std::cout << "Vehicle ID: " << vehicleID << std::endl;
        std::cout << "Fuel Level: " << fuelLevel << " liters" << std::endl;
        std::cout << "Distance Travelled: " << distanceTravelled << " km" << std::endl;
        std::cout << "Status: " << (status == 'A' ? "Active" : "Inactive") << std::endl;
        std::cout << "Available: " << (isAvailable ? "Yes" : "No") << std::endl;
        std::cout << "Driver Name: " << driverName << std::endl;
        std::cout << "------------------------------" << std::endl;
    }
};

// Assigns a driver to the vehicle
void assignDriver(FleetVehicle &vehicle, std::string name) {
    vehicle.setDriverName(name);
    std::cout << "Driver '" << vehicle.getDriverName() << "' assigned successfully." << std::endl;
}

// Refuels the vehicle and validates fuel amount
void refuelVehicle(FleetVehicle &vehicle, float fuelAmount) {
    if (fuelAmount <= 0) {
        throw std::invalid_argument("Fuel amount must be positive.");
    }
    vehicle.setFuelLevel(vehicle.getFuelLevel() + fuelAmount);
    std::cout << "Vehicle refueled. New fuel level: " << vehicle.getFuelLevel() << " liters" << std::endl;
}

int main() {
    FleetVehicle vehicles[3];  

    vehicles[0] = FleetVehicle(101, 45.5, 120.0, 'A', true, "Raj");
    vehicles[1] = FleetVehicle(102, 8.0, 300.0, 'A', true, "Priya");
    // vehicles[2] uses default constructor

    int choice, index;

    while (true) {
        // Display menu options
        std::cout << std::endl;
        std::cout << "=== Fleet Vehicle Monitoring Menu ===" << std::endl;
        std::cout << "1. Add vehicle details" << std::endl;
        std::cout << "2. Assign a driver" << std::endl;
        std::cout << "3. Refuel a vehicle" << std::endl;
        std::cout << "4. Update vehicle status" << std::endl;
        std::cout << "5. Display vehicle info" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Add or update vehicle using parameterized constructor
                std::cout << "Enter the vehicle index (0-2): ";
                std::cin >> index;
                if (index < 0 || index > 2) {
                    std::cout << "Invalid index!" << std::endl;
                    break;
                }
                int id;
                float fuel;
                double dist;
                char s;
                bool avail;
                std::string driver;
                std::cout << "Enter vehicle ID: "; std::cin >> id;
                std::cout << "Enter fuel level: "; std::cin >> fuel;
                std::cout << "Enter distance travelled: "; std::cin >> dist;
                std::cout << "Enter status ('A' for Active, 'I' for Inactive): "; std::cin >> s;
                std::cout << "Is vehicle available? (1 for Yes, 0 for No): "; std::cin >> avail;
                std::cout << "Enter driver name: "; 
                std::getline(std::cin, driver);

                vehicles[index] = FleetVehicle(id, fuel, dist, s, avail, driver);
                std::cout << "Vehicle details updated." << std::endl;
                break;
            }
            case 2: {
                // Assign driver
                std::cout << "Enter the vehicle index (0-2): ";
                std::cin >> index;
                if (index < 0 || index > 2) {
                    std::cout << "Invalid index!" << std::endl;
                    break;
                }
                std::string driver;
                std::cout << "Enter driver name: "; 
                std::getline(std::cin, driver);
                assignDriver(vehicles[index], driver);
                break;
            }
            case 3: {
                // Refuel vehicle
                std::cout << "Enter the vehicle index (0-2): ";
                std::cin >> index;
                if (index < 0 || index > 2) {
                    std::cout << "Invalid index!" << std::endl;
                    break;
                }
                float amount;
                std::cout << "Enter fuel amount to add: ";
                std::cin >> amount;
                try {
                    refuelVehicle(vehicles[index], amount);
                }
                catch (std::exception &e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                // Update status
                std::cout << "Enter the vehicle index (0-2): ";
                std::cin >> index;
                if (index < 0 || index > 2) {
                    std::cout << "Invalid index!" << std::endl;
                    break;
                }
                vehicles[index].updateStatus();
                std::cout << "Vehicle status updated." << std::endl;
                break;
            }
            case 5: {
                // Display vehicle info
                std::cout << "Enter the vehicle index (0-2): ";
                std::cin >> index;
                if (index < 0 || index > 2) {
                    std::cout << "Invalid index!" << std::endl;
                    break;
                }
                vehicles[index].displayInfo();
                break;
            }
            case 6: {
                std::cout << "Exiting Fleet Vehicle Monitoring System. Goodbye!" << std::endl;
                return 0;
            }
            default:
                std::cout << "Invalid choice! Please select a valid option." << std::endl;
        }
    }
    return 0;
}
