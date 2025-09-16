#include <iostream>
#include <iomanip>
#include <string>

// Enum for component types 
enum ComponentType
{
    COMPONENT_TYPE_ENGINE,
    COMPONENT_TYPE_AVIONICS,
    COMPONENT_TYPE_LANDING_GEAR,
    COMPONENT_TYPE_FUEL_SYSTEM
};

// Enum for component status 
enum ComponentStatus
{
    COMPONENT_STATUS_OPERATIONAL,
    COMPONENT_STATUS_MAINTENANCE_REQUIRED,
    COMPONENT_STATUS_FAILED
};

// Helper functions to convert enums to readable strings
std::string componentTypeToString(const ComponentType type)
{
    if (type == COMPONENT_TYPE_ENGINE)
    {
        return "Engine";
    }

    if (type == COMPONENT_TYPE_AVIONICS)
    {
        return "Avionics";
    }

    if (type == COMPONENT_TYPE_LANDING_GEAR)
    {
        return "Landing Gear";
    }

    if (type == COMPONENT_TYPE_FUEL_SYSTEM)
    {
        return "Fuel System";
    }

    return "Unknown";
}

std::string componentStatusToString(const ComponentStatus status)
{
    if (status == COMPONENT_STATUS_OPERATIONAL)
    {
        return "Operational";
    }

    if (status == COMPONENT_STATUS_MAINTENANCE_REQUIRED)
    {
        return "Maintenance Required";
    }

    if (status == COMPONENT_STATUS_FAILED)
    {
        return "Failed";
    }

    return "Unknown";
}

// Class representing an aerospace component
class AerospaceComponent
{
private:
    int component_identifier;
    double component_efficiency;
    std::string component_manufacturer;
    ComponentType component_type;
    ComponentStatus component_status;

public:
    // Default constructor - initialize to provided defaults
    AerospaceComponent()
    {
        component_identifier = 0;
        component_efficiency = 100.0;
        component_manufacturer = "Unknown";
        component_type = COMPONENT_TYPE_ENGINE;
        component_status = COMPONENT_STATUS_OPERATIONAL;
    }

    // Parameterized constructor - accepts all members
    AerospaceComponent(int identifier,
                       double efficiency,
                       const std::string &manufacturer,
                       const ComponentType type,
                       const ComponentStatus status)
    {
        component_identifier = identifier;
        component_efficiency = efficiency;
        component_manufacturer = manufacturer;
        component_type = type;
        component_status = status;
    }

    // Destructor - prints message
    ~AerospaceComponent()
    {
        std::cout << "Component "
                  << component_identifier
                  << " destroyed."
                  << std::endl;
    }

    // Getters (const-correct)
    int getComponentIdentifier() const
    {
        return component_identifier;
    }

    double getComponentEfficiency() const
    {
        return component_efficiency;
    }

    std::string getComponentManufacturer() const
    {
        return component_manufacturer;
    }

    ComponentType getComponentType() const
    {
        return component_type;
    }

    ComponentStatus getComponentStatus() const
    {
        return component_status;
    }

    // Setters
    void setComponentIdentifier(const int identifier)
    {
        component_identifier = identifier;
    }

    void setComponentEfficiency(const double efficiency)
    {
        component_efficiency = efficiency;
    }

    void setComponentManufacturer(const std::string &manufacturer)
    {
        component_manufacturer = manufacturer;
    }

    void setComponentType(const ComponentType type)
    {
        component_type = type;
    }

    void setComponentStatus(const ComponentStatus status)
    {
        component_status = status;
    }

    // UpdateStatus: set status depending on efficiency thresholds
    void UpdateStatus()
    {
        if (component_efficiency < 50.0)
        {
            component_status = COMPONENT_STATUS_FAILED;
        }
        else if (component_efficiency < 80.0)
        {
            component_status = COMPONENT_STATUS_MAINTENANCE_REQUIRED;
        }
        else
        {
            component_status = COMPONENT_STATUS_OPERATIONAL;
        }
    }

    // SimulateUsage: reduce efficiency by 0.5 units for each hour (0.5 percentage points per hour)
    void SimulateUsage(const int usage_hours)
    {
        int index;
        for (index = 0; index < usage_hours; index = index + 1)
        {
            component_efficiency = component_efficiency - 0.5;

            if (component_efficiency < 0.0)
            {
                component_efficiency = 0.0;
            }
        }

        // After usage, update the status accordingly
        UpdateStatus();
    }

    // PerformMaintenanceCheck: uses switch-case on component_status
    void PerformMaintenanceCheck() const
    {
        ComponentStatus status_local;
        status_local = component_status;

        switch (status_local)
        {
            case COMPONENT_STATUS_OPERATIONAL:
            {
                std::cout << "Component "
                          << component_identifier
                          << " is operational. No immediate action required."
                          << std::endl;
                break;
            }

            case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
            {
                std::cout << "Component "
                          << component_identifier
                          << " requires maintenance. Schedule inspection."
                          << std::endl;
                break;
            }

            case COMPONENT_STATUS_FAILED:
            {
                std::cout << "Component "
                          << component_identifier
                          << " has failed. Remove from service and repair."
                          << std::endl;
                break;
            }

            default:
            {
                std::cout << "Component "
                          << component_identifier
                          << " status unknown. Manual check required."
                          << std::endl;
                break;
            }
        }
    }

    // BoostEfficiency: increment efficiency by 1.0 until it reaches 100.0
    void BoostEfficiency()
    {
        while (component_efficiency < 100.0)
        {
            component_efficiency = component_efficiency + 1.0;

            if (component_efficiency > 100.0)
            {
                component_efficiency = 100.0;
            }
        }

        // After boosting, update status
        UpdateStatus();
    }

    // DisplayDetails: const method that prints all component details
    void DisplayDetails() const
    {
        std::cout << "Component Identifier: "
                  << component_identifier
                  << std::endl;

        std::cout << "Manufacturer: "
                  << component_manufacturer
                  << std::endl;

        std::cout << "Type: "
                  << componentTypeToString(component_type)
                  << std::endl;

        std::cout << "Efficiency: "
                  << component_efficiency
                  << std::endl;

        std::cout << "Status: "
                  << componentStatusToString(component_status)
                  << std::endl;

        std::cout << "----------------------------------------"
                  << std::endl;
    }
};

// Global Functions

// Assign manufacturer using setter and confirm via getter
void AssignManufacturer(AerospaceComponent &component, const std::string &manufacturerName)
{
    component.setComponentManufacturer(manufacturerName);

    std::cout << "Manufacturer for component "
              << component.getComponentIdentifier()
              << " set to "
              << component.getComponentManufacturer()
              << std::endl;
}

// Returns true if efficiency > 85.0
bool IsEfficient(const AerospaceComponent &component)
{
    if (component.getComponentEfficiency() > 85.0)
    {
        return true;
    }

    return false;
}

// Compare types of two components
bool IsSameType(const AerospaceComponent &componentA, const AerospaceComponent &componentB)
{
    if (componentA.getComponentType() == componentB.getComponentType())
    {
        return true;
    }

    return false;
}

// Compare status of two components
bool IsSameStatus(const AerospaceComponent &componentA, const AerospaceComponent &componentB)
{
    if (componentA.getComponentStatus() == componentB.getComponentStatus())
    {
        return true;
    }

    return false;
}

// Print formatted list of components
void PrintFormattedComponentList(const AerospaceComponent componentList[], const int listSize)
{
    int index;
    std::cout << std::left
              << std::setw(8) << "ID"
              << std::setw(18) << "Manufacturer"
              << std::setw(16) << "Type"
              << std::setw(12) << "Efficiency"
              << std::setw(18) << "Status"
              << std::endl;

    std::cout << "------------------------------------------------------------------"
              << std::endl;

    for (index = 0; index < listSize; index = index + 1)
    {
        std::cout << std::left
                  << std::setw(8) << componentList[index].getComponentIdentifier()
                  << std::setw(18) << componentList[index].getComponentManufacturer()
                  << std::setw(16) << componentTypeToString(componentList[index].getComponentType())
                  << std::setw(12) << componentList[index].getComponentEfficiency()
                  << std::setw(18) << componentStatusToString(componentList[index].getComponentStatus())
                  << std::endl;
    }
}

// Search by identifier - return index or -1
int SearchComponentByIdentifier(const AerospaceComponent componentList[], const int listSize, const int searchIdentifier)
{
    int index;
    for (index = 0; index < listSize; index = index + 1)
    {
        if (componentList[index].getComponentIdentifier() == searchIdentifier)
        {
            return index;
        }
    }

    return -1;
}

// Main
int main()
{
    const int LIST_SIZE = 3;

    // Sample data for testing
    AerospaceComponent componentList[LIST_SIZE] =
    {
        AerospaceComponent(101, 92.5, "GE Aviation", COMPONENT_TYPE_ENGINE, COMPONENT_STATUS_OPERATIONAL),
        AerospaceComponent(102, 45.0, "Honeywell", COMPONENT_TYPE_AVIONICS, COMPONENT_STATUS_FAILED),
        AerospaceComponent() // default
    };

    int choice;
    choice = 0;

    while (choice != 9)
    {
        std::cout << std::endl;
        std::cout << "=== Aerospace Component Monitoring Menu ==="
                  << std::endl;
        std::cout << "1. Add/Update Component Details"
                  << std::endl;
        std::cout << "2. Assign Manufacturer"
                  << std::endl;
        std::cout << "3. Simulate Usage (hours)"
                  << std::endl;
        std::cout << "4. Boost Efficiency"
                  << std::endl;
        std::cout << "5. Check Maintenance Status"
                  << std::endl;
        std::cout << "6. Compare Two Components (Type / Status)"
                  << std::endl;
        std::cout << "7. Search by Component ID"
                  << std::endl;
        std::cout << "8. Display All Components"
                  << std::endl;
        std::cout << "9. Exit"
                  << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            int index_local;
            std::cout << "Enter index to add/update (0 - 2): ";
            std::cin >> index_local;

            if ((index_local >= 0) && (index_local < LIST_SIZE))
            {
                int identifier_local;
                double efficiency_local;
                std::string manufacturer_local;
                int type_choice;
                ComponentType type_local;
                int status_choice;
                ComponentStatus status_local;

                std::cout << "Enter component identifier: ";
                std::cin >> identifier_local;

                do
                {
                    std::cout << "Enter efficiency (0.0 - 100.0): ";
                    std::cin >> efficiency_local;
                } while ((efficiency_local < 0.0) || (efficiency_local > 100.0));

                std::cin.ignore();

                do
                {
                    std::cout << "Enter manufacturer name (non-empty): ";
                    std::getline(std::cin, manufacturer_local);
                } while (manufacturer_local.empty());

                std::cout << "Select Type:"
                          << std::endl;
                std::cout << "0 - Engine"
                          << std::endl;
                std::cout << "1 - Avionics"
                          << std::endl;
                std::cout << "2 - Landing Gear"
                          << std::endl;
                std::cout << "3 - Fuel System"
                          << std::endl;
                std::cout << "Enter your choice (0-3): ";
                std::cin >> type_choice;

                if (type_choice == 0)
                {
                    type_local = COMPONENT_TYPE_ENGINE;
                }
                else if (type_choice == 1)
                {
                    type_local = COMPONENT_TYPE_AVIONICS;
                }
                else if (type_choice == 2)
                {
                    type_local = COMPONENT_TYPE_LANDING_GEAR;
                }
                else
                {
                    type_local = COMPONENT_TYPE_FUEL_SYSTEM;
                }

                std::cout << "Select Status:"
                          << std::endl;
                std::cout << "0 - Operational"
                          << std::endl;
                std::cout << "1 - Maintenance Required"
                          << std::endl;
                std::cout << "2 - Failed"
                          << std::endl;
                std::cout << "Enter your choice (0-2): ";
                std::cin >> status_choice;

                if (status_choice == 0)
                {
                    status_local = COMPONENT_STATUS_OPERATIONAL;
                }
                else if (status_choice == 1)
                {
                    status_local = COMPONENT_STATUS_MAINTENANCE_REQUIRED;
                }
                else
                {
                    status_local = COMPONENT_STATUS_FAILED;
                }

                componentList[index_local] = AerospaceComponent(identifier_local,
                                                                 efficiency_local,
                                                                 manufacturer_local,
                                                                 type_local,
                                                                 status_local);

                std::cout << "Component added/updated successfully."
                          << std::endl;
            }
            else
            {
                std::cout << "Invalid index. Please enter value between 0 and 2."
                          << std::endl;
            }
        }
        else if (choice == 2)
        {
            int search_id_local;
            std::string manufacturer_local;
            std::cout << "Enter component ID to assign manufacturer: ";
            std::cin >> search_id_local;

            int found_index_local;
            found_index_local = SearchComponentByIdentifier(componentList, LIST_SIZE, search_id_local);

            if (found_index_local != -1)
            {
                std::cin.ignore();

                do
                {
                    std::cout << "Enter manufacturer name (non-empty): ";
                    std::getline(std::cin, manufacturer_local);
                } while (manufacturer_local.empty());

                AssignManufacturer(componentList[found_index_local], manufacturer_local);
            }
            else
            {
                std::cout << "Component not found."
                          << std::endl;
            }
        }
        else if (choice == 3)
        {
            int search_id_local;
            int hours_local;
            std::cout << "Enter component ID to simulate usage: ";
            std::cin >> search_id_local;

            int found_index_local;
            found_index_local = SearchComponentByIdentifier(componentList, LIST_SIZE, search_id_local);

            if (found_index_local != -1)
            {
                std::cout << "Enter usage hours (non-negative integer): ";
                std::cin >> hours_local;

                if (hours_local < 0)
                {
                    std::cout << "Invalid hours. Must be non-negative."
                              << std::endl;
                }
                else
                {
                    componentList[found_index_local].SimulateUsage(hours_local);
                    std::cout << "Simulation complete. New efficiency: "
                              << componentList[found_index_local].getComponentEfficiency()
                              << std::endl;
                }
            }
            else
            {
                std::cout << "Component not found."
                          << std::endl;
            }
        }
        else if (choice == 4)
        {
            int search_id_local;
            std::cout << "Enter component ID to boost efficiency: ";
            std::cin >> search_id_local;

            int found_index_local;
            found_index_local = SearchComponentByIdentifier(componentList, LIST_SIZE, search_id_local);

            if (found_index_local != -1)
            {
                componentList[found_index_local].BoostEfficiency();

                std::cout << "Boost complete. Efficiency is now: "
                          << componentList[found_index_local].getComponentEfficiency()
                          << std::endl;
            }
            else
            {
                std::cout << "Component not found."
                          << std::endl;
            }
        }
        else if (choice == 5)
        {
            int search_id_local;
            std::cout << "Enter component ID to check maintenance status: ";
            std::cin >> search_id_local;

            int found_index_local;
            found_index_local = SearchComponentByIdentifier(componentList, LIST_SIZE, search_id_local);

            if (found_index_local != -1)
            {
                componentList[found_index_local].PerformMaintenanceCheck();
            }
            else
            {
                std::cout << "Component not found."
                          << std::endl;
            }
        }
        else if (choice == 6)
        {
            int id_a_local;
            int id_b_local;
            std::cout << "Enter first component ID: ";
            std::cin >> id_a_local;
            std::cout << "Enter second component ID: ";
            std::cin >> id_b_local;

            int index_a_local;
            int index_b_local;
            index_a_local = SearchComponentByIdentifier(componentList, LIST_SIZE, id_a_local);
            index_b_local = SearchComponentByIdentifier(componentList, LIST_SIZE, id_b_local);

            if ((index_a_local != -1) && (index_b_local != -1))
            {
                if (IsSameType(componentList[index_a_local], componentList[index_b_local]))
                {
                    std::cout << "Components are of the same type."
                              << std::endl;
                }
                else
                {
                    std::cout << "Components are of different types."
                              << std::endl;
                }

                if (IsSameStatus(componentList[index_a_local], componentList[index_b_local]))
                {
                    std::cout << "Components have the same status."
                              << std::endl;
                }
                else
                {
                    std::cout << "Components have different statuses."
                              << std::endl;
                }
            }
            else
            {
                std::cout << "One or both components not found."
                          << std::endl;
            }
        }
        else if (choice == 7)
        {
            int search_id_local;
            std::cout << "Enter component ID to search: ";
            std::cin >> search_id_local;

            int found_index_local;
            found_index_local = SearchComponentByIdentifier(componentList, LIST_SIZE, search_id_local);

            if (found_index_local != -1)
            {
                std::cout << "Component found at index: "
                          << found_index_local
                          << std::endl;
                componentList[found_index_local].DisplayDetails();
            }
            else
            {
                std::cout << "Component not found."
                          << std::endl;
            }
        }
        else if (choice == 8)
        {
            PrintFormattedComponentList(componentList, LIST_SIZE);
        }
        else if (choice == 9)
        {
            std::cout << "Exiting program."
                      << std::endl;
        }
        else
        {
            std::cout << "Invalid choice. Please select from menu."
                      << std::endl;
        }
    }

    return 0;
}
