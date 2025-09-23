// Member-function definitions for class HeartRates

#include "ShriyanshKesharwani_Sept22_task4_HeartRates.h"
#include <iostream>  

// Constructor
HeartRates::HeartRates(std::string fName, std::string lName, int month, int day, int year) {
    firstName = fName;
    lastName = lName;
    birthMonth = month;
    birthDay = day;
    birthYear = year;
}

// Setters
void HeartRates::setFirstName(std::string fName) {
    firstName = fName;
}

void HeartRates::setLastName(std::string lName) {
    lastName = lName;
}

void HeartRates::setBirthMonth(int month) {
    birthMonth = month;
}

void HeartRates::setBirthDay(int day) {
    birthDay = day;
}

void HeartRates::setBirthYear(int year) {
    birthYear = year;
}

// Getters
std::string HeartRates::getFirstName() {
    return firstName;
}

std::string HeartRates::getLastName() {
    return lastName;
}

int HeartRates::getBirthMonth() {
    return birthMonth;
}

int HeartRates::getBirthDay() {
    return birthDay;
}

int HeartRates::getBirthYear() {
    return birthYear;
}

// Function to calculate age (asks user for current date)
int HeartRates::getAge() {
    int currentMonth, currentDay, currentYear;

    // Prompt user for today's date
    std::cout << "Enter current month (1-12): ";
    std::cin >> currentMonth;
    std::cout << "Enter current day (1-31): ";
    std::cin >> currentDay;
    std::cout << "Enter current year: ";
    std::cin >> currentYear;

    int age = currentYear - birthYear;

    // Adjust age if birthday has not yet occurred this year
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) 
    {
        age--;
    }

    return age;
}

// Function to calculate maximum heart rate
int HeartRates::getMaximumHeartRate(int age) {
    return 220 - age;
}

// Function to calculate target heart rate range (50–85% of max)
std::pair<int, int> HeartRates::getTargetHeartRate(int maxRate) 
{

    int lower = static_cast<int>(maxRate * 0.50);
    int upper = static_cast<int>(maxRate * 0.85);
    
    return std::make_pair(lower, upper);
}
