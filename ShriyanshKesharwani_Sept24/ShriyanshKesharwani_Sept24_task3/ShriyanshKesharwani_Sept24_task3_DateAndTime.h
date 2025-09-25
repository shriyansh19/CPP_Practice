#ifndef DATEANDTIME_H
#define DATEANDTIME_H

#include <iostream>
#include <iomanip>
using namespace std;

class DateAndTime {
public:
    DateAndTime(int m = 1, int d = 1, int y = 2000, int hr = 0, int min = 0, int sec = 0);

    // Set functions
    void setDate(int m, int d, int y);
    void setTime(int hr, int min, int sec);

    // Increment functions
    void tick();        // Increment 1 second
    void nextDay();     // Increment date

    // Print functions
    void printUniversal() const;
    void printStandard() const;

private:
    int month, day, year;
    int hour, minute, second;

    bool leapYear(int y) const;
    int daysInMonth(int m, int y) const;
};

#endif
