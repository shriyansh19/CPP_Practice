// Test program for AirlineReservation class

#include "ShriyanshKesharwani_Sept23_task3_AirlineReservation.cpp"

int main()
{
    AirlineReservation airline; // create airline system object
    int choice;                 // user choice
    char more = 'y';            // loop for multiple bookings

    while (more == 'y' || more == 'Y')
    {
        std::cout << "Please type 1 for First Class" << std::endl;
        std::cout << "Please type 2 for Economy" << std::endl;
        std::cin >> choice;

        bool booked = false;

        if (choice == 1)
        {
            booked = airline.bookFirstClass();

            // If First Class full, offer Economy
            if (!booked)
            {
                std::cout << "First Class is full. Is Economy acceptable? (y/n): ";
                char ans;
                std::cin >> ans;
                
                if (ans == 'y' || ans == 'Y')
                {
                    booked = airline.bookEconomy();
                }
            }
        }
        else if (choice == 2)
        {
            booked = airline.bookEconomy();

            // If Economy full, offer First Class
            if (!booked)
            {
                std::cout << "Economy is full. Is First Class acceptable? (y/n): ";
                char ans;
                std::cin >> ans;
                if (ans == 'y' || ans == 'Y')
                {
                    booked = airline.bookFirstClass();
                }
            }
        }
        else
        {
            std::cout << "Invalid choice. Please type 1 or 2." << std::endl;
        }

        // If no booking possible, plane is full
        if (!booked && airline.isFull())
        {
            std::cout << "Next flight leaves in 3 hours." << std::endl;
        }

        std::cout << "Do you want to book another seat? (y/n): ";
        std::cin >> more;
    }

    return 0;
}
