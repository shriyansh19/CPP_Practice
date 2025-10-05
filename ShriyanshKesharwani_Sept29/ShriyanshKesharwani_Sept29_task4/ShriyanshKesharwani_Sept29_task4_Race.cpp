#include <iostream>
#include <cstdlib>
#include "ShriyanshKesharwani_Sept29_task4_Race.h"

// Function to move the tortoise according to rules
void moveTortoise(int* pos) {
    int i = std::rand() % 10 + 1; // random number between 1 and 10

    if (i >= 1 && i <= 5) 
    {         // Fast plod (50%)
        *pos += 3;
    } 
    else if (i == 6 || i == 7) 
    {  // Slip (20%)
        *pos -= 6;
    } 
    else 
    {                        // Slow plod (30%)
        *pos += 1;
    }
}

// Function to move the hare according to rules
void moveHare(int* pos) {
    int i = std::rand() % 10 + 1; // random number between 1 and 10

    if (i == 1 || i == 2) 
    {   // Sleep (20%)
        *pos += 0;
    } 
    else if (i == 3 || i == 4) 
    {    // Big hop (20%)
        *pos += 9;
    } 
    else if (i == 5) 
    {              // Big slip (10%)
        *pos -= 12;
    } 
    else if (i >= 6 && i <= 8) 
    {    // Small hop (30%)
        *pos += 1;
    } 
    else 
    {                          // Small slip (20%)
        *pos -= 2;
    }
}

// Function to print the race track
void printRace(const int* tortoisePos, const int* harePos) {
    for (int i = 1; i <= FINISH_LINE; i++) 
    {
        if (*tortoisePos == i && *harePos == i) 
        {
            std::cout << "OUCH!!!"; // Collision case
            i += 5; // Skip printing for the length of "OUCH!!!"
        } 
        else if (*tortoisePos == i) 
        {
            std::cout << "T";       // Tortoise position
        } 
        else if (*harePos == i) 
        {
            std::cout << "H";       // Hare position
        } 
        else 
        {
            std::cout << " ";       // Empty track space
        }
    }
    
    std::cout << std::endl;
}
