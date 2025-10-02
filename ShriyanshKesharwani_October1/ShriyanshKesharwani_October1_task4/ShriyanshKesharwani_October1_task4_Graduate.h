#ifndef GRADUATE_H
#define GRADUATE_H

#include "ShriyanshKesharwani_October1_task4_Student.h"


// GraduateStudent Base Class
// Parent for Masters and Doctoral students
class GraduateStudent : public Student {
protected:
    std::string advisor;   // Academic advisor

public:
    GraduateStudent(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv);

    void displayInfo() const override;
    std::string getLevel() const override;
};


// Thesis Masters Student
class ThesisMastersStudent : public GraduateStudent {
    std::string thesisTitle;
public:
    ThesisMastersStudent(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& thesis);
    void displayInfo() const override;
    std::string getLevel() const override;
};

// Non-Thesis Masters Student
class NonThesisMastersStudent : public GraduateStudent {
    std::string projectTitle;
public:
    NonThesisMastersStudent(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& project);
    void displayInfo() const override;
    std::string getLevel() const override;
};

// Doctoral Student
class DoctoralStudent : public GraduateStudent {
protected:
    std::string dissertationTitle;
    int yearsInProgram;
public:
    DoctoralStudent(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& dissertation, int years);
    void displayInfo() const override;
    std::string getLevel() const override;
};

// PhD Candidate
class PhDCandidate : public DoctoralStudent {
public:
    PhDCandidate(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& dissertation, int years);
    std::string getLevel() const override;
};


// PostDoc Fellow
class PostDocFellow : public GraduateStudent {
    std::string researchGrant;   // Grant information
public:
    PostDocFellow(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& grant);

    void displayInfo() const override;
    std::string getLevel() const override;
};

#endif
