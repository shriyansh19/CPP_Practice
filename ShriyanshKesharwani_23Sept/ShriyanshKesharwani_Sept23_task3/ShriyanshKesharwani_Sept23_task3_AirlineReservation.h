// Class definition for AirlineReservation system

#ifndef AIRLINERESERVATION_H
#define AIRLINERESERVATION_H

#include <iostream>

class AirlineReservation
{
private:
    bool seats[10]; // false = available, true = booked

public:
    // Constructor - initialize all seats as empty
    AirlineReservation();

    // Book a seat in first class (1–5)
    bool bookFirstClass();

    // Book a seat in economy (6–10)
    bool bookEconomy();

    // Print a boarding pass
    void printBoardingPass(int seatNumber, const std::string &section);

    // Check if plane is full
    bool isFull();
};

#endif
