#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <iostream>
#include <string>
#include <cmath>

// ================= Base Class ==================
class Quadrilateral {
protected:
    float* sides;   // dynamically allocated sides
    float* angles;  // dynamically allocated angles

public:
    // Constructor
    Quadrilateral(const float s[4], const float a[4]);

    // Copy constructor
    Quadrilateral(const Quadrilateral& other);

    // Assignment operator
    Quadrilateral& operator=(const Quadrilateral& other);

    // Destructor
    virtual ~Quadrilateral();

    // Virtual methods
    virtual bool isValid() const;      // default: check angle sum
    virtual float area() const;        // default: 0

    // Operator overloads
    bool operator==(const Quadrilateral& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Quadrilateral& q);
    float operator()() const;          // perimeter
    operator float() const;            // convert to area

    // Helper for printing type
    virtual std::string getType() const 
    { 
        return "Quadrilateral"; 
    }
};

// ================= Derived Classes ==================

// Trapezoid
class Trapezoid : public Quadrilateral {
public:
    Trapezoid(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;

    std::string getType() const override 
    { 
        return "Trapezoid"; 
    }
};

// Parallelogram
class Parallelogram : public Trapezoid {
public:
    Parallelogram(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;

    std::string getType() const override 
    { 
        return "Parallelogram"; 
    }
};

// Rectangle
class Rectangle : public Parallelogram {
public:
    Rectangle(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;

    std::string getType() const override 
    { 
        return "Rectangle"; 
    }
};

// Square
class Square : public Rectangle {
public:
    Square(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;
    
    std::string getType() const override 
    { 
        return "Square"; 
    }
};

#endif
