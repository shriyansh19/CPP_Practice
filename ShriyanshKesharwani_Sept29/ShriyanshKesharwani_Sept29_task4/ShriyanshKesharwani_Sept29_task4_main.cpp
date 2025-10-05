#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ShriyanshKesharwani_Sept29_task4_Race.h"   // Include race functions and constants

int main() {
    // Seed random number generator
    std::srand(static_cast<unsigned>(std::time(0)));

    // Initialize positions of tortoise and hare
    int tortoisePos = 1;
    int harePos = 1;

    // Race start messages
    std::cout << "BANG !!!!!" << std::endl;
    std::cout << "AND THEY'RE OFF !!!!!" << std::endl << std::endl;

    // Run the race until one or both reach the finish line
    while (tortoisePos < FINISH_LINE && harePos < FINISH_LINE) 
    {
        // Move both racers
        moveTortoise(&tortoisePos);
        moveHare(&harePos);

        // Clamp positions so they never go below 1
        if (tortoisePos < 1) 
        tortoisePos = 1;

        if (harePos < 1) 
        harePos = 1;

        // Print current race track state
        printRace(&tortoisePos, &harePos);
    }

    // Print race results
    if (tortoisePos >= FINISH_LINE && harePos >= FINISH_LINE) 
    {
        std::cout << "\nIt's a tie. (But favor the tortoise!)" << std::endl;
    } 
    else if (tortoisePos >= FINISH_LINE) 
    {
        std::cout << "\nTORTOISE WINS!!! YAY!!!" << std::endl;
    } 
    else 
    {
        std::cout << "\nHare wins. Yuch." << std::endl;
    }

    return 0;
}
