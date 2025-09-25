// Member-function definitions for class DateAndTime

#include <iostream>
#include "ShriyanshKesharwani_Sept24_task3_DateAndTime.h"

// Constructor
DateAndTime::DateAndTime(int m, int d, int y, int hr, int min, int sec) {
    setDate(m, d, y);
    setTime(hr, min, sec);
}

// Set date
void DateAndTime::setDate(int m, int d, int y) {
    month = (m >= 1 && m <= 12) ? m : 1;
    year = (y >= 1900) ? y : 2000;

    int maxDay = daysInMonth(month, year);

    day = (d >= 1 && d <= maxDay) ? d : 1;
}

// Set time
void DateAndTime::setTime(int hr, int min, int sec) {
    hour = (hr >= 0 && hr < 24) ? hr : 0;
    minute = (min >= 0 && min < 60) ? min : 0;
    second = (sec >= 0 && sec < 60) ? sec : 0;
}

// Tick: advance time by one second
void DateAndTime::tick() {
    second++;
    if (second >= 60) 
    {
        second = 0;
        minute++;
        if (minute >= 60) 
        {
            minute = 0;
            hour++;
            if (hour >= 24) 
            {
                hour = 0;
                nextDay();
            }
        }
    }
}

// Increment date by one day
void DateAndTime::nextDay() {
    day++;
    if (day > daysInMonth(month, year)) 
    {
        day = 1;
        month++;
        if (month > 12) 
        {
            month = 1;
            year++;
        }
    }
}

// Leap year check
bool DateAndTime::leapYear(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// Days in a given month
int DateAndTime::daysInMonth(int m, int y) const{
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return leapYear(y) ? 29 : 28;
        default:
            return 31; // should never happen
    }
}

// Print in universal format
void DateAndTime::printUniversal() const {
    cout << setfill('0');
    cout << month << "/" << day << "/" << year << " " << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second << endl;
}

// Print in standard format
void DateAndTime::printStandard() const {
    cout << setfill('0');
    int stdHour = (hour == 0 || hour == 12) ? 12 : hour % 12;
    cout << month << "/" << day << "/" << year << " " << setw(2) << stdHour << ":" << setw(2) << minute << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM") << endl;
}
