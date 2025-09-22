// Fig. Modified: ShriyanshKesharwani_Sept22_task1_GradeBook.cpp
// GradeBook member-function definitions.

#include <iostream>
#include "ShriyanshKesharwani_Sept22_task1_GradeBook.h" // include definition of class GradeBook

// constructor initializes courseName and instructorName
GradeBook::GradeBook(std::string course, std::string instructor)
{
    setCourseName(course);
    setInstructorName(instructor);
}

// function to set the course name
void GradeBook::setCourseName(std::string name)
{
    courseName = name; // store the course name in the object
}

// function to get the course name
std::string GradeBook::getCourseName()
{
    return courseName; // return object's courseName
}

// function to set the instructor name
void GradeBook::setInstructorName(std::string name)
{
    instructorName = name; // store instructor name in the object
}

// function to get the instructor name
std::string GradeBook::getInstructorName()
{
    return instructorName; // return object's instructorName
}

// display a welcome message to the GradeBook user
void GradeBook::displayMessage()
{
    std::cout << "Welcome to the grade book for\n"
              << getCourseName() << "!" << std::endl;
    std::cout << "This course is presented by: "
              << getInstructorName() << std::endl;
}
