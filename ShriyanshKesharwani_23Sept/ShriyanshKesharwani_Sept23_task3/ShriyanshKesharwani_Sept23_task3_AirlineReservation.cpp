// AirlineReservation.cpp
// Class implementation for AirlineReservation system

#include "ShriyanshKesharwani_Sept23_task3_AirlineReservation.h"

// Constructor initializes all seats as empty
AirlineReservation::AirlineReservation()
{
    for (int i = 0; i < 10; i++)
    {
        seats[i] = false;
    }
}

// Try booking First Class (seats 1–5)
bool AirlineReservation::bookFirstClass()
{
    for (int i = 0; i < 5; i++)
    {
        if (!seats[i])
        {
            seats[i] = true;
            printBoardingPass(i + 1, "First Class");
            return true;
        }
    }
    return false; // all First Class full
}

// Try booking Economy (seats 6–10)
bool AirlineReservation::bookEconomy()
{
    for (int i = 5; i < 10; i++)
    {
        if (!seats[i])
        {
            seats[i] = true;
            printBoardingPass(i + 1, "Economy");
            return true;
        }
    }
    return false; // all Economy full
}

// Print boarding pass
void AirlineReservation::printBoardingPass(int seatNumber, const std::string &section)
{
    std::cout << "Boarding Pass: Seat " << seatNumber << " (" << section << ")" << std::endl;
}

// Check if plane is completely full
bool AirlineReservation::isFull()
{
    for (int i = 0; i < 10; i++)
    {
        if (!seats[i])
        {
            return false; // at least one seat empty
        }
    }
    return true; // all booked
}
