#include "ShriyanshKesharwani_October1_task4_Graduate.h"

// GraduateStudent Implementation
GraduateStudent::GraduateStudent(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv) : Student(n, id, dept), advisor(adv) {}

void GraduateStudent::displayInfo() const {
    Student::displayInfo();
    std::cout << "Advisor: " << advisor << std::endl;
}

std::string GraduateStudent::getLevel() const {
    return "Graduate";
}

// Thesis Masters
ThesisMastersStudent::ThesisMastersStudent(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& thesis) : GraduateStudent(n, id, dept, adv), thesisTitle(thesis) {}

void ThesisMastersStudent::displayInfo() const {
    GraduateStudent::displayInfo();
    std::cout << "Thesis Title: " << thesisTitle << std::endl;
}

std::string ThesisMastersStudent::getLevel() const {
    return "ThesisMastersStudent";
}

// Non-Thesis Masters
NonThesisMastersStudent::NonThesisMastersStudent(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& project) : GraduateStudent(n, id, dept, adv), projectTitle(project) {}

void NonThesisMastersStudent::displayInfo() const {
    GraduateStudent::displayInfo();
    std::cout << "Project Title: " << projectTitle << std::endl;
}

std::string NonThesisMastersStudent::getLevel() const {
    return "NonThesisMastersStudent";
}

// Doctoral Student
DoctoralStudent::DoctoralStudent(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& dissertation, int years) : GraduateStudent(n, id, dept, adv), dissertationTitle(dissertation), yearsInProgram(years) {}

void DoctoralStudent::displayInfo() const {
    GraduateStudent::displayInfo();
    std::cout << "Dissertation: " << dissertationTitle << ", Years in Program: " << yearsInProgram << std::endl;
}

std::string DoctoralStudent::getLevel() const 
{
    return "DoctoralStudent";
}

// PhD Candidate
PhDCandidate::PhDCandidate(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& dissertation, int years) : DoctoralStudent(n, id, dept, adv, dissertation, years) {}

std::string PhDCandidate::getLevel() const {
    return "PhDCandidate";
}

// PostDoc Fellow
PostDocFellow::PostDocFellow(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& grant) : GraduateStudent(n, id, dept, adv), researchGrant(grant) {}

void PostDocFellow::displayInfo() const {
    GraduateStudent::displayInfo();
    std::cout << "Research Grant: " << researchGrant << std::endl;
}

std::string PostDocFellow::getLevel() const {
    return "PostDocFellow";
}
