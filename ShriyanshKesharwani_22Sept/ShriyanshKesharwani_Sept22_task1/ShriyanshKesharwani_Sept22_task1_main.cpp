// Fig. Modified: ShriyanshKesharwani_Sept22_task1_main.cpp
// Test program for the modified GradeBook class

#include "ShriyanshKesharwani_Sept22_task1_GradeBook.cpp"
#include <iostream>

int main()
{
    // Create GradeBook object with course and instructor
    GradeBook gradeBook1("C++ Programming", "Prof. Kesharwani");

    // Display message
    gradeBook1.displayMessage();

    std::cout << std::endl;

    // Change instructor name
    gradeBook1.setInstructorName("Dr. Iyer");

    // Display message again
    gradeBook1.displayMessage();

    return 0;
}
