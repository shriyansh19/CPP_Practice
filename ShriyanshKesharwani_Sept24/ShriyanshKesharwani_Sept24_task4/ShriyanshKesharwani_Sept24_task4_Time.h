// Definition of the Time class

#ifndef TIME_H
#define TIME_H

class Time {
public:
    // Constructor with default arguments
    Time(int hr = 0, int min = 0, int sec = 0);

    // Set functions
    bool setTime(int h, int m , int s);
    bool setHour(int h);
    bool setMinute(int m);
    bool setSecond(int s);

    // Get functions
    int getHour() ;
    int getMinute();
    int getSecond();

    // Print functions
    void printUniversal();  // 24-hour format
    void printStandard();   // 12-hour format

private:
    int hour;   // 0 - 23
    int minute; // 0 - 59
    int second; // 0 - 59
};

#endif
