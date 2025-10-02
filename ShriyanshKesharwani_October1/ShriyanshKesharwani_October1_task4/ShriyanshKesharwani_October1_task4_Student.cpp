#include "ShriyanshKesharwani_October1_task4_Student.h"

// Constructor implementation
Student::Student(const std::string& n, const std::string& id, const std::string& dept) : name(n), studentID(id), department(dept) {}

// Virtual destructor
Student::~Student() {}

// Prints base student info (common for all)
void Student::displayInfo() const 
{
    std::cout << "Name: " << name << ", ID: " << studentID << ", Department: " << department << std::endl;
}

// Default getLevel() method
std::string Student::getLevel() const 
{
    return "Student";
}
