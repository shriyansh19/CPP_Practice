// Class definition for HeartRates

#ifndef HEARTRATES_H
#define HEARTRATES_H

#include <string>   
#include <utility>  

class HeartRates {
private:
    std::string firstName;   // person's first name
    std::string lastName;    // person's last name
    int birthMonth;          // month of birth
    int birthDay;            // day of birth
    int birthYear;           // year of birth

public:
    // Constructor
    HeartRates(std::string fName, std::string lName, int month, int day, int year);

    // Setter functions
    void setFirstName(std::string fName);
    void setLastName(std::string lName);
    void setBirthMonth(int month);
    void setBirthDay(int day);
    void setBirthYear(int year);

    // Getter functions
    std::string getFirstName();
    std::string getLastName();
    int getBirthMonth();
    int getBirthDay();
    int getBirthYear();

    // Business logic functions
    int getAge(); // calculates age based on user-input current date
    int getMaximumHeartRate(int age); // 220 - age
    std::pair<int, int> getTargetHeartRate(int maxRate); // 50–85% of max
};

#endif
