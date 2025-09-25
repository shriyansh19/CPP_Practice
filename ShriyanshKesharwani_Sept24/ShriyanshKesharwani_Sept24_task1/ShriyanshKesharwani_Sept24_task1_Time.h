// Definition of the Time class

#ifndef TIME_H
#define TIME_H

class Time {
public:
    // Constructor with default arguments
    Time(int = 0, int = 0, int = 0);

    // Set functions
    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    // Get functions
    int getHour();
    int getMinute();
    int getSecond();

    // Print functions
    void printUniversal();  // 24-hour format
    void printStandard();   // 12-hour format

    // Tick function to increment time by one second
    void tick();

private:
    int hour;   // 0 - 23
    int minute; // 0 - 59
    int second; // 0 - 59
};

#endif
