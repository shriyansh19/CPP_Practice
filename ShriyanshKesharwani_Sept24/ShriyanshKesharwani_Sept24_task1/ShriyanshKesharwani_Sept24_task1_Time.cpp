// Member-function definitions for class Time

#include <iostream>
#include <iomanip>
#include "ShriyanshKesharwani_Sept24_task1_Time.h"

// Constructor
Time::Time(int hr, int min, int sec) {
    setTime(hr, min, sec);
}

// Set entire time
void Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

// Set hour
void Time::setHour(int h) {
    hour = (h >= 0 && h < 24) ? h : 0;
}

// Set minute
void Time::setMinute(int m) {
    minute = (m >= 0 && m < 60) ? m : 0;
}

// Set second
void Time::setSecond(int s) {
    second = (s >= 0 && s < 60) ? s : 0;
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
void Time::printUniversal() {
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":" << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond();
}

// Print time in standard format (HH:MM:SS AM/PM)
void Time::printStandard() {
    int displayHour = (hour == 0 || hour == 12) ? 12 : hour % 12;
    std::cout << displayHour << ":"<< std::setfill('0') << std::setw(2) << getMinute() << ":"<< std::setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
}

// Tick function: increments time by 1 second
void Time::tick() {
    second++;
    if (second == 60) 
    {
        second = 0;
        minute++;

        if (minute == 60) 
        {
            minute = 0;
            hour++;
            if (hour == 24) 
            {
                hour = 0; // New day
            }
        }
    }
}
