#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>


// Base Class: Student

// Represents a general student in the university.
// This will be the root of our deep inheritance hierarchy.
class Student {
protected:
    std::string name;        // Student's name
    std::string studentID;   // Unique student ID
    std::string department;  // Department name

public:
    // Constructor to initialize basic student details
    Student(const std::string& n, const std::string& id, const std::string& dept);

    // Virtual destructor ensures correct cleanup of derived objects
    virtual ~Student();

    // Display student's basic information (to be overridden by derived classes)
    virtual void displayInfo() const;

    // Returns student level (default "Student", overridden in derived classes)
    virtual std::string getLevel() const;
};

#endif
