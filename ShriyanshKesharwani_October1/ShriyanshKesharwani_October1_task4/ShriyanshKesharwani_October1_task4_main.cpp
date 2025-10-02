#include "ShriyanshKesharwani_October1_task4_Student.h"
#include "ShriyanshKesharwani_October1_task4_Undergraduate.h"
#include "ShriyanshKesharwani_October1_task4_Graduate.h"
#include <vector>

int main() {

    // Creating sample students
    Freshman f("Brock", "UG101", "Computer Science", 1, 15);
    HonorsSenior hs("Neha", "UG401", "Physics", 4, 120, "Quantum Entanglement Thesis");
    ExchangeSenior es("Luca", "UG402", "Mechanical", 4, 110, "Politecnico di Milano");

    ThesisMastersStudent tm("Shriyansh", "GR201", "Electrical", "Dr. Rao", "Smart Grid Optimization");
    NonThesisMastersStudent ntm("Roger", "GR202", "Civil", "Dr. Murphy", "Bridge Load Simulation");

    PhDCandidate phd("Blake", "GR301", "Biotech", "Dr. Kapoor", "Gene Editing Ethics", 3);
    PostDocFellow pdf("Dr. Jonas", "GR401", "AI Research", "Dr. Dwayne", "DARPA Grant");

    // Store all students in a vector of Student* (polymorphism)
    std::vector<Student*> students = {&f, &hs, &es, &tm, &ntm, &phd, &pdf};

    // Demonstrate polymorphism
    for (auto s : students) 
    {
        s->displayInfo();   // Calls correct overridden method
        std::cout << "Level: " << s->getLevel() << "\n" << std::endl;
    }

    return 0;
}
