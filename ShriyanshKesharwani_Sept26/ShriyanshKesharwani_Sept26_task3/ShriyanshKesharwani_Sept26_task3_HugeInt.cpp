#include "ShriyanshKesharwani_Sept26_task3_HugeInt.h"

// clear array
void HugeInt::zero() {
    for (int i = 0; i < digits; i++) 
    {
        integer[i] = 0;
    }
}

// constructor from long
HugeInt::HugeInt(long value) {
    zero();
    for (int j = digits - 1; value != 0 && j >= 0; j--) 
    {
        integer[j] = value % 10;
        value /= 10;
    }
}

// constructor from string
HugeInt::HugeInt(const std::string& number) {
    zero();
    int length = number.size();

    for (int j = digits - length, k = 0; j < digits; j++, k++) 
    {
        if (std::isdigit(number[k]))
        integer[j] = number[k] - '0';
    }
}

// addition
HugeInt HugeInt::operator+(const HugeInt& op2) const {
    HugeInt temp;
    int carry = 0;

    for (int i = digits - 1; i >= 0; i--) 
    {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;
        if (temp.integer[i] > 9) 
        {
            temp.integer[i] %= 10;
            carry = 1;
        } 
        else 
        {
            carry = 0;
        }
    }
    return temp;
}

// subtraction (assume *this >= op2)
HugeInt HugeInt::operator-(const HugeInt& op2) const {
    HugeInt temp;
    int borrow = 0;

    for (int i = digits - 1; i >= 0; i--) 
    {
        int diff = integer[i] - op2.integer[i] - borrow;
        if (diff < 0) 
        {
            diff += 10;
            borrow = 1;
        } 
        else 
        {
            borrow = 0;
        }

        temp.integer[i] = diff;
    }

    return temp;
}

// multiplication
HugeInt HugeInt::operator*(const HugeInt& op2) const {
    HugeInt temp;

    for (int i = digits - 1; i >= 0; i--) 
    {
        int carry = 0;
        for (int j = digits - 1, k = i; j >= 0 && k >= 0; j--, k--) 
        {
            int prod = integer[i] * op2.integer[j] + temp.integer[k] + carry;
            temp.integer[k] = prod % 10;
            carry = prod / 10;
        }
    }

    return temp;
}

// division (basic long division)
HugeInt HugeInt::operator/(const HugeInt& divisor) const {
    HugeInt quotient;
    HugeInt remainder;
    HugeInt one(1);

    HugeInt dividend(*this);

    while (dividend >= divisor) 
    {
        dividend = dividend - divisor;
        quotient = quotient + one;
    }
    return quotient;
}

// addition with int
HugeInt HugeInt::operator+(int op2) const 
{
    return *this + HugeInt(op2);
}

// addition with string
HugeInt HugeInt::operator+(const std::string& op2) const 
{
    return *this + HugeInt(op2);
}

// comparisons
bool HugeInt::operator==(const HugeInt& op2) const {
    for (int i = 0; i < digits; i++)
    {
        if (integer[i] != op2.integer[i]) 
        return false;
    }

    return true;
}

bool HugeInt::operator!=(const HugeInt& op2) const 
{
    return !(*this == op2);
}

bool HugeInt::operator<(const HugeInt& op2) const {
    for (int i = 0; i < digits; i++) 
    {
        if (integer[i] < op2.integer[i]) 
        return true;

        if (integer[i] > op2.integer[i]) 
        return false;
    }
    return false;
}

bool HugeInt::operator<=(const HugeInt& op2) const 
{
    return (*this < op2) || (*this == op2);
}

bool HugeInt::operator>(const HugeInt& op2) const 
{
    return !(*this <= op2);
}

bool HugeInt::operator>=(const HugeInt& op2) const 
{
    return !(*this < op2);
}

// output
std::ostream& operator<<(std::ostream& output, const HugeInt& num) {
    int i = 0;

    while (i < HugeInt::digits && num.integer[i] == 0) 
    {
        i++;
    }
    if (i == HugeInt::digits) 
    {
        output << 0;
    } 
    else 
    {
        for (; i < HugeInt::digits; i++) 
        {
            output << num.integer[i];
        }
    }
    return output;
}