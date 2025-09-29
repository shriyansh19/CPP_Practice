#include <iostream>
using std::cout;
using std::endl;

int main() {
    // Given variables
    float number1 = 8.9f;
    float number2;
    char* ptr;
    char s1[100] = "Cristiano";
    char s2[100] = "Ronaldo";

    // a) Declare the variable fPtr to be a pointer to an object of type double.
    double* fPtr;

    // b) Assign the address of variable number1 to pointer variable fPtr.
    fPtr = (double*) &number1;

    // c) Print the value of the object pointed to by fPtr.
    cout << "Value pointed to by fPtr: " << *fPtr << endl;

    // d) Assign the value of the object pointed to by fPtr to variable number2.
    number2 = (float) (*fPtr);

    // e) Print the value of number2.
    cout << "Value of number2: " << number2 << endl;

    // f) Print the address of number1.
    cout << "Address of number1: " << &number1 << endl;

    // g) Print the address stored in fPtr.
    cout << "Address stored in fPtr: " << fPtr << endl;
    cout << "Is it same as address of number1? -> " << ((fPtr == (double*) &number1) ? "Yes" : "No") << endl;

    return 0;
}

