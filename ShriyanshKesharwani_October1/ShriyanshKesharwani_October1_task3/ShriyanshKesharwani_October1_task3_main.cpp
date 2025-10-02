#include "ShriyanshKesharwani_October1_task3_Quadrilateral.h"
#include <iostream>

int main() {
    // Sample data
    float sqSides[4] = {5,5,5,5}, sqAngles[4] = {90,90,90,90};
    float rectSides[4] = {6,4,6,4}, rectAngles[4] = {90,90,90,90};
    float paraSides[4] = {6,4,6,4}, paraAngles[4] = {110,70,110,70};
    float trapSides[4] = {6,5,4,3}, trapAngles[4] = {100,80,100,80};
    float quadSides[4] = {3,4,5,6}, quadAngles[4] = {90,90,90,90};

    Quadrilateral* shapes[5];
    shapes[0] = new Quadrilateral(quadSides, quadAngles);
    shapes[1] = new Trapezoid(trapSides, trapAngles);
    shapes[2] = new Parallelogram(paraSides, paraAngles);
    shapes[3] = new Rectangle(rectSides, rectAngles);
    shapes[4] = new Square(sqSides, sqAngles);

    // Demonstrate polymorphism
    for (int i = 0; i < 5; i++) 
    {
        std::cout << *shapes[i] << std::endl;
        std::cout << "Valid? " << (shapes[i]->isValid() ? "Yes" : "No") << std::endl;
        std::cout << "Area: " << shapes[i]->area() << std::endl;
        std::cout << "Perimeter: " << (*shapes[i])() << std::endl;

        std::cout << "---------------------------------\n";
    }

    // Compare Rectangle & Square
    if (*shapes[3] == *shapes[4])
    {
        std::cout << "Rectangle and Square have equal area\n";
    }
    else
    {
        std::cout << "Rectangle and Square have different area\n";
    }

    // Cast to float (area)
    float sqArea = float(*shapes[4]);
    std::cout << "Square area via typecast: " << sqArea << std::endl;

    // Cleanup
    for (int i = 0; i < 5; i++) 
    {
        delete shapes[i];
    }

    return 0;
}
