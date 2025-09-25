// Member-function definitions for class Time
#include <iostream>
#include <iomanip>
#include "ShriyanshKesharwani_Sept24_task4_Time.h"

// Constructor
Time::Time(int hr, int min, int sec) {
    if (!setTime(hr, min, sec)) 
    {
        hour = minute = second = 0; // reset to safe state if invalid
    }
}

// Set hour
bool Time::setHour(int h) {
    if (h >= 0 && h < 24) 
    {
        hour = h;
        return true;
    }
    return false;
}

// Set minute
bool Time::setMinute(int m) {
    if (m >= 0 && m < 60) 
    {
        minute = m;
        return true;
    }
    return false;
}

// Set second
bool Time::setSecond(int s) {
    if (s >= 0 && s < 60) 
    {
        second = s;
        return true;
    }
    return false;
}


// Get hour
int Time::getHour() {
    return hour;
}

// Get minute
int Time::getMinute() {
    return minute;
}

// Get second
int Time::getSecond() {
    return second;
}

// Print time in universal format (HH:MM:SS)
// Print Universal format
void Time::printUniversal() {
    std::cout << std::setfill('0') << std:: setw(2) << hour << ":" << std::setw(2) << minute << ":"<< std::setw(2) << second;
}

// Print Standard format
void Time::printStandard() {
    int stdHour = (hour == 0 || hour == 12) ? 12 : hour % 12;
    std::cout << stdHour << ":"<< std::setfill('0') << std::setw(2) << minute << ":"<< std::setw(2) << second<< (hour < 12 ? " AM" : " PM");
}

