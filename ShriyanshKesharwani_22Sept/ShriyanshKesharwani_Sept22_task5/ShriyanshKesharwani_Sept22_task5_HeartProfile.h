// Declaration of the HealthProfile class

#ifndef HEALTHPROFILE_H
#define HEALTHPROFILE_H

#include <string>
#include <utility> 

class HealthProfile {
private:
    // Basic details
    std::string firstName;
    std::string lastName;
    std::string gender;

    // Date of birth
    int birthDay;
    int birthMonth;
    int birthYear;

    // Physical attributes
    int heightInInches;
    int weightInPounds;

public:
    // Constructor
    HealthProfile(std::string fName, std::string lName, std::string gen, int day, int month, int year, int height, int weight);

    // Setter and Getter functions
    void setFirstName(const std::string& fName);
    std::string getFirstName() const;

    void setLastName(const std::string& lName);
    std::string getLastName() const;

    void setGender(const std::string& gen);
    std::string getGender() const;

    void setBirthDay(int day);
    int getBirthDay();
    int getBirthDay() const;

    void setBirthMonth(int month);
    int getBirthMonth();
    int getBirthMonth() const;

    void setBirthYear(int year);
    int getBirthYear();
    int getBirthYear() const;

    void setHeight(int height);
    int getHeight();
    int getHeight() const;

    void setWeight(int weight);
    int getWeight();
    int getAge(int currentDay, int currentMonth, int currentYear);
    int getMaximumHeartRate(int age);
    void getTargetHeartRate(int maxRate, int &lower, int &upper);
    double getBMI();
    int getWeight() const;

    // Business logic functions    
    int getMaximumHeartRate(int age) const;
    std::pair<int, int> getTargetHeartRate(int maxRate) const;
    double getBMI() const;
    
    void setFirstName(std::string fName);
    std::string getFirstName();
    void setLastName(std::string lName);
    std::string getLastName();
    void setGender(std::string gen);
    std::string getGender();
};

#endif
