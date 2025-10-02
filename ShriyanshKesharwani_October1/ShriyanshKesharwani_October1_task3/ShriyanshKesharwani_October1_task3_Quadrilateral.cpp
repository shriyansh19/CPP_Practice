#include "ShriyanshKesharwani_October1_task3_Quadrilateral.h"

// ================= Base Class ==================

// Constructor
Quadrilateral::Quadrilateral(const float s[4], const float a[4]) {
    sides = new float[4];
    angles = new float[4];

    for (int i = 0; i < 4; i++) 
    {
        sides[i] = s[i];
        angles[i] = a[i];
    }
}

// Copy constructor
Quadrilateral::Quadrilateral(const Quadrilateral& other) {
    sides = new float[4];
    angles = new float[4];

    for (int i = 0; i < 4; i++) 
    {
        sides[i] = other.sides[i];
        angles[i] = other.angles[i];
    }
}

// Assignment operator
Quadrilateral& Quadrilateral::operator=(const Quadrilateral& other) {
    if (this != &other) 
    {
        delete[] sides;
        delete[] angles;
        sides = new float[4];
        angles = new float[4];

        for (int i = 0; i < 4; i++) 
        {
            sides[i] = other.sides[i];
            angles[i] = other.angles[i];
        }
    }
    return *this;
}

// Destructor
Quadrilateral::~Quadrilateral() {
    delete[] sides;
    delete[] angles;
}

// Valid if angle sum = 360
bool Quadrilateral::isValid() const {
    float sum = 0;

    for (int i = 0; i < 4; i++) 
    {
        sum += angles[i];
    }

    return std::fabs(sum - 360.0f) < 1e-3;
}

// Base area (unknown)
float Quadrilateral::area() const {
    return 0.0f;
}

// Compare area
bool Quadrilateral::operator==(const Quadrilateral& other) const 
{
    return std::fabs(area() - other.area()) < 1e-3;
}

// Print details
std::ostream& operator<<(std::ostream& os, const Quadrilateral& q) {
    os << q.getType() << " [Sides: ";

    for (int i = 0; i < 4; i++) 
    {
        os << q.sides[i] << (i < 3 ? ", " : "");
    }

    os << " | Angles: ";

    for (int i = 0; i < 4; i++) 
    {
        os << q.angles[i] << (i < 3 ? ", " : "");
    }

    os << "]";

    return os;
}

// Perimeter
float Quadrilateral::operator()() const 
{
    return sides[0] + sides[1] + sides[2] + sides[3];
}

// Convert to area
Quadrilateral::operator float() const 
{
    return area();
}

// ================= Derived Classes ==================

// Trapezoid: at least one pair of parallel sides
Trapezoid::Trapezoid(const float s[4], const float a[4]) : Quadrilateral(s, a) {}

bool Trapezoid::isValid() const 
{
    return Quadrilateral::isValid(); // simple validation
}

float Trapezoid::area() const {
    // Approximation: (sum of parallel sides)/2 * height
    float base1 = sides[0], base2 = sides[2];
    float height = std::sin(angles[0] * M_PI / 180.0f) * sides[1];

    return (base1 + base2) / 2 * height;
}

// Parallelogram: opposite sides parallel
Parallelogram::Parallelogram(const float s[4], const float a[4]) : Trapezoid(s, a) {}

bool Parallelogram::isValid() const 
{
    return Quadrilateral::isValid() && (std::fabs(sides[0] - sides[2]) < 1e-3) && (std::fabs(sides[1] - sides[3]) < 1e-3);
}

float Parallelogram::area() const {
    float base = sides[0];
    float height = sides[1] * std::sin(angles[0] * M_PI / 180.0f);

    return base * height;
}

// Rectangle: all angles 90
Rectangle::Rectangle(const float s[4], const float a[4]) : Parallelogram(s, a) {}

bool Rectangle::isValid() const {
    for (int i = 0; i < 4; i++) 
    {
        if (std::fabs(angles[i] - 90.0f) > 1e-3) 
        return false;
    }

    return Parallelogram::isValid();
}

float Rectangle::area() const {
    return sides[0] * sides[1];
}

// Square: all sides equal + 90 angles
Square::Square(const float s[4], const float a[4]) : Rectangle(s, a) {}

bool Square::isValid() const {
    for (int i = 0; i < 4; i++) 
    {
        if (std::fabs(sides[i] - sides[0]) > 1e-3) 
        return false;

        if (std::fabs(angles[i] - 90.0f) > 1e-3) 
        return false;
    }
    return Rectangle::isValid();
}

float Square::area() const 
{
    return sides[0] * sides[0];
}
