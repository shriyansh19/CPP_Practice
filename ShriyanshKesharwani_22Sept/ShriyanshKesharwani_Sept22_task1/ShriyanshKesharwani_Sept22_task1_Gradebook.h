// Fig. Modified: ShriyanshKesharwani_Sept22_task1_GradeBook.h
// GradeBook class definition with instructor name added.

#include <string>   // class GradeBook uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
    // constructor that initializes courseName and instructorName
    GradeBook(std::string course, std::string instructor);

    // function that sets the course name
    void setCourseName(std::string name);

    // function that gets the course name
    std::string getCourseName();

    // function that sets the instructor name
    void setInstructorName(std::string name);

    // function that gets the instructor name
    std::string getInstructorName();

    // function that displays a welcome message
    void displayMessage();

private:
    std::string courseName;       // course name for this GradeBook
    std::string instructorName;   // instructor name for this GradeBook
}; // end class GradeBook
