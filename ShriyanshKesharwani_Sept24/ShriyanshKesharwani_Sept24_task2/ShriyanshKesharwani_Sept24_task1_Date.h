// Date.h
// Definition of the Date class

#ifndef DATE_H
#define DATE_H

class Date {
public:
    // Constructor with default values
    Date(int m = 1, int d = 1, int y = 2000);

    // Print date in mm/dd/yyyy format
    void print();

    // Increment date by one day
    void nextDay();

private:
    int month; // 1 - 12
    int day;   // 1 - 31 (depends on month)
    int year;  // any positive year

    // Helper function: check if year is leap year
    bool isLeapYear(int y);

    // Helper function: return number of days in a given month
    int daysInMonth(int m, int y);
};

#endif
