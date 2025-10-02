#include "ShriyanshKesharwani_October1_task4_Undergraduate.h"


// UndergraduateStudent Implementation
UndergraduateStudent::UndergraduateStudent(const std::string& n, const std::string& id, const std::string& dept, int y, int credits) : Student(n, id, dept), year(y), creditsEarned(credits) {}

void UndergraduateStudent::displayInfo() const {
    Student::displayInfo();
    std::cout << "Year: " << year << ", Credits: " << creditsEarned << std::endl;
}

std::string UndergraduateStudent::getLevel() const 
{
    return "Undergraduate";
}


// Freshman
Freshman::Freshman(const std::string& n, const std::string& id, const std::string& dept, int y, int credits) : UndergraduateStudent(n, id, dept, y, credits) {}

std::string Freshman::getLevel() const {
    return "Freshman";
}


// Senior
Senior::Senior(const std::string& n, const std::string& id, const std::string& dept, int y, int credits) : UndergraduateStudent(n, id, dept, y, credits) {}

std::string Senior::getLevel() const {
    return "Senior";
}

// HonorsSenior
HonorsSenior::HonorsSenior(const std::string& n, const std::string& id, const std::string& dept, int y, int credits, const std::string& thesis) : Senior(n, id, dept, y, credits), thesisTitle(thesis) {}

void HonorsSenior::displayInfo() const {
    Senior::displayInfo();
    std::cout << "Thesis Title: " << thesisTitle << std::endl;
}

std::string HonorsSenior::getLevel() const {
    return "HonorsSenior";
}

// ExchangeSenior
ExchangeSenior::ExchangeSenior(const std::string& n, const std::string& id, const std::string& dept, int y, int credits, const std::string& homeUni) : Senior(n, id, dept, y, credits), homeUniversity(homeUni) {}

void ExchangeSenior::displayInfo() const {
    Senior::displayInfo();
    std::cout << "Home University: " << homeUniversity << std::endl;
}

std::string ExchangeSenior::getLevel() const {
    return "ExchangeSenior";
}
