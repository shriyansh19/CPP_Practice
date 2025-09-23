// Implementation of HealthProfile class

#include "ShriyanshKesharwani_Sept22_task5_HeartProfile.h"
#include <iostream>

// Constructor
HealthProfile::HealthProfile(std::string fName, std::string lName, std::string gen,
                             int day, int month, int year, int height, int weight) {
    firstName = fName;
    lastName = lName;
    gender = gen;
    birthDay = day;
    birthMonth = month;
    birthYear = year;
    heightInInches = height;
    weightInPounds = weight;
}

// Setter and Getter implementations
void HealthProfile::setFirstName(std::string fName) 
{ 
    firstName = fName; 
}
std::string HealthProfile::getFirstName() 
{ 
    return firstName; 
}

void HealthProfile::setLastName(std::string lName) 
{ 
    lastName = lName; 
}
std::string HealthProfile::getLastName() { 
    return lastName; 
}

void HealthProfile::setGender(std::string gen) 
{ 
    gender = gen; 
}
std::string HealthProfile::getGender() 
{ 
    return gender; 
}

void HealthProfile::setBirthDay(int day) { 
    birthDay = day; 
}
int HealthProfile::getBirthDay() { 
    return birthDay; 
}

void HealthProfile::setBirthMonth(int month) { 
    birthMonth = month; 
}
int HealthProfile::getBirthMonth() { 
    return birthMonth; 
}

void HealthProfile::setBirthYear(int year) { 
    birthYear = year; 
}
int HealthProfile::getBirthYear() { 
    return birthYear; 
}

void HealthProfile::setHeight(int height) { 
    heightInInches = height; 
}
int HealthProfile::getHeight() { 
    return heightInInches; 
}

void HealthProfile::setWeight(int weight) { 
    weightInPounds = weight; 
}
int HealthProfile::getWeight() { 
    return weightInPounds; 
}

// Function to calculate age
int HealthProfile::getAge(int currentDay, int currentMonth, int currentYear) {
    int age = currentYear - birthYear;

    // Adjust if birthday has not occurred this year
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) 
    {
        age = age - 1;
    }

    return age;
}

// Function to calculate maximum heart rate
int HealthProfile::getMaximumHeartRate(int age) {
    return 220 - age;
}

// Function to calculate target heart rate range
void HealthProfile::getTargetHeartRate(int maxRate, int &lower, int &upper) {
    lower = (maxRate * 50) / 100; // 50%
    upper = (maxRate * 85) / 100; // 85%
}

// Function to calculate BMI
double HealthProfile::getBMI() {
    // Formula: BMI = (weight * 703) / (height * height)
    return ((weightInPounds * 703.0) / (heightInInches * heightInInches));
}
