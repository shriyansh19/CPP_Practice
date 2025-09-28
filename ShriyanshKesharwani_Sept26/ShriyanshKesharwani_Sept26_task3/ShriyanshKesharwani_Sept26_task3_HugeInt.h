#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
#include <cctype>

class HugeInt {
    friend std::ostream& operator<<(std::ostream&, const HugeInt&);

public:
    static const int digits = 30; // max digits

    HugeInt(long = 0);                // constructor from long
    HugeInt(const std::string&);      // constructor from string

    HugeInt operator+(const HugeInt&) const;
    HugeInt operator-(const HugeInt&) const;
    HugeInt operator*(const HugeInt&) const;
    HugeInt operator/(const HugeInt&) const;

    HugeInt operator+(int) const;
    HugeInt operator+(const std::string&) const;

    bool operator==(const HugeInt&) const;
    bool operator!=(const HugeInt&) const;
    bool operator<(const HugeInt&) const;
    bool operator<=(const HugeInt&) const;
    bool operator>(const HugeInt&) const;
    bool operator>=(const HugeInt&) const;

private:
    short integer[digits];
    void zero(); // helper to clear array
};

#endif

