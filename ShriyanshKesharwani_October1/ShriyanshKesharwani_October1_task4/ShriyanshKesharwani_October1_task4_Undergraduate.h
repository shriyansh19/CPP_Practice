#ifndef UNDERGRADUATE_H
#define UNDERGRADUATE_H

#include "ShriyanshKesharwani_October1_task4_Student.h"


// UndergraduateStudent Class

// Represents undergraduates (Freshman → Senior)
class UndergraduateStudent : public Student {
protected:
    int year;            // Current year of study (1-4)
    int creditsEarned;   // Credits completed so far

public:
    UndergraduateStudent(const std::string& n, const std::string& id, const std::string& dept, int y, int credits);

    void displayInfo() const override;     // Show details
    std::string getLevel() const override; // Returns "Undergraduate"
};


// Freshman Class

// Represents 1st year students
class Freshman : public UndergraduateStudent {
public:
    Freshman(const std::string& n, const std::string& id, const std::string& dept, int y, int credits);

    std::string getLevel() const override; // Returns "Freshman"
};


// Senior Class

// Represents 4th year students
class Senior : public UndergraduateStudent {
public:
    Senior(const std::string& n, const std::string& id, const std::string& dept, int y, int credits);

    std::string getLevel() const override; // Returns "Senior"
};

// HonorsSenior Class

// Specialization of Senior who does a thesis
class HonorsSenior : public Senior {
    std::string thesisTitle;   // Thesis work
public:
    HonorsSenior(const std::string& n, const std::string& id, const std::string& dept, int y, int credits, const std::string& thesis);

    void displayInfo() const override;     // Includes thesis
    std::string getLevel() const override; // Returns "HonorsSenior"
};

// ExchangeSenior Class

// Specialization of Senior from another university
class ExchangeSenior : public Senior {
    std::string homeUniversity;   // Origin university
public:
    ExchangeSenior(const std::string& n, const std::string& id, const std::string& dept, int y, int credits, const std::string& homeUni);

    void displayInfo() const override;     // Includes home university
    std::string getLevel() const override; // Returns "ExchangeSenior"
};

#endif
