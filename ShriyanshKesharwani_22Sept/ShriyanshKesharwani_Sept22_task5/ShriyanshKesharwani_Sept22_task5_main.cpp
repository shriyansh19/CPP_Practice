// Program to demonstrate HealthProfile class

#include "ShriyanshKesharwani_Sept22_task5_HeartProfile.cpp"
#include <iostream>

int main() {
    std::string firstName;
    std::string lastName;
    std::string gender;
    int birthDay;
    int birthMonth;
    int birthYear;
    int height;
    int weight;

    int currentDay;
    int currentMonth;
    int currentYear;

    // Taking input from user
    std::cout << "Enter First Name: ";
    std::cin >> firstName;

    std::cout << "Enter Last Name: ";
    std::cin >> lastName;

    std::cout << "Enter Gender: ";
    std::cin >> gender;

    std::cout << "Enter Birth Day (dd): ";
    std::cin >> birthDay;

    std::cout << "Enter Birth Month (mm): ";
    std::cin >> birthMonth;

    std::cout << "Enter Birth Year (yyyy): ";
    std::cin >> birthYear;

    std::cout << "Enter Height (in inches): ";
    std::cin >> height;

    std::cout << "Enter Weight (in pounds): ";
    std::cin >> weight;

    std::cout << "Enter Current Day (dd): ";
    std::cin >> currentDay;

    std::cout << "Enter Current Month (mm): ";
    std::cin >> currentMonth;

    std::cout << "Enter Current Year (yyyy): ";
    std::cin >> currentYear;

    // Create object of HealthProfile
    HealthProfile profile(firstName, lastName, gender, birthDay, birthMonth, birthYear,height, weight);

    // Calculate values
    int age = profile.getAge(currentDay, currentMonth, currentYear);
    int maxRate = profile.getMaximumHeartRate(age);
    int lower, upper;
    
    profile.getTargetHeartRate(maxRate, lower, upper);
    double bmi = profile.getBMI();

    // Display results
    std::cout << "\n--- Health Profile Information ---" << std::endl;
    std::cout << "Name: " << profile.getFirstName() << " " << profile.getLastName() << std::endl;
    std::cout << "Gender: " << profile.getGender() << std::endl;
    std::cout << "Date of Birth: " << profile.getBirthDay() << "/" << profile.getBirthMonth() << "/" << profile.getBirthYear() << std::endl;
    std::cout << "Height: " << profile.getHeight() << " inches" << std::endl;
    std::cout << "Weight: " << profile.getWeight() << " pounds" << std::endl;
    std::cout << "Age: " << age << " years" << std::endl;
    std::cout << "Maximum Heart Rate: " << maxRate << " bpm" << std::endl;
    std::cout << "Target Heart Rate Range: " << lower << " - " << upper << " bpm" << std::endl;
    std::cout << "BMI: " << bmi << std::endl;

    // BMI chart
    std::cout << "\n--- BMI Values ---" << std::endl;
    std::cout << "Underweight: less than 18.5" << std::endl;
    std::cout << "Normal:      between 18.5 and 24.9" << std::endl;
    std::cout << "Overweight:  between 25 and 29.9" << std::endl;
    std::cout << "Obese:       30 or greater" << std::endl;

    return 0;
}
