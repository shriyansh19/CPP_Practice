// Test program for HeartRates class

#include <iostream>
#include "ShriyanshKesharwani_Sept22_task4_HeartRates.cpp"

int main() {
    
    std::string first, last;
    int month, day, year;

    // Prompt user for personal information
    std::cout << "Enter first name: ";
    std::cin >> first;
    std::cout << "Enter last name: ";
    std::cin >> last;
    std::cout << "Enter birth month (1-12): ";
    std::cin >> month;
    std::cout << "Enter birth day (1-31): ";
    std::cin >> day;
    std::cout << "Enter birth year: ";
    std::cin >> year;

    // Create HeartRates object
    HeartRates person(first, last, month, day, year);

    // Display personal info
    std::cout << "\n--- Person Information ---" << std::endl;
    std::cout << "Name: " << person.getFirstName() << " " << person.getLastName() << std::endl;
    std::cout << "Date of Birth: " << person.getBirthMonth() << "/" << person.getBirthDay() << "/" << person.getBirthYear() << std::endl;

    // Calculate and display age, max HR, target HR
    int age = person.getAge();
    std::cout << "\nAge: " << age << " years" << std::endl;

    int maxHR = person.getMaximumHeartRate(age);
    std::cout << "Maximum Heart Rate: " << maxHR << " bpm" << std::endl;

    std::pair<int, int> targetRange = person.getTargetHeartRate(maxHR);
    std::cout << "Target Heart Rate Range: " << targetRange.first << " - " << targetRange.second << " bpm" << std::endl;

    return 0;
}
