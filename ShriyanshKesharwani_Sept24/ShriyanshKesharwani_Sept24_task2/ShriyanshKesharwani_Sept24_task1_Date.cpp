// Member-function definitions for class Date

#include <iostream>
#include "ShriyanshKesharwani_Sept24_task1_Date.h"


// Constructor with validation
Date::Date(int m, int d, int y) {
    // Validate month
    month = (m >= 1 && m <= 12) ? m : 1;

    // Validate year
    year = (y >= 1) ? y : 2000;

    // Validate day (depends on month & leap year)
    int maxDay = daysInMonth(month, year);
    day = (d >= 1 && d <= maxDay) ? d : 1;
}

// Print date in mm/dd/yyyy format
void Date::print() {
    std::cout << month << "/" << day << "/" << year;
}

// Increment date by one day
void Date::nextDay() {
    day++;

    // If day goes beyond max days in month
    if (day > daysInMonth(month, year)) 
    {
        day = 1;      // Reset day
        month++;      // Increment month

        // If month goes beyond December
        if (month > 12) 
        {
            month = 1; // Reset month
            year++;    // Increment year
        }
    }
}

// Check if year is a leap year
bool Date::isLeapYear(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// Return number of days in a given month
int Date::daysInMonth(int m, int y) {
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(y) ? 29 : 28;
        default:
            return 31; // should never happen
    }
}
