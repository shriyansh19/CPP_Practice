#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main() {
    const int SIZE = 10;

    // a) Declare and initialize array
    double numbers[SIZE] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};

    // b) Declare pointer
    double* nPtr = NULL;

    // c) Print using array subscript notation
    cout << "Array elements (subscript notation): ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << fixed << setprecision(1) << numbers[i] << " ";
    }
    cout << endl;

    // d) Assign starting address of numbers to nPtr
    nPtr = numbers;       // array name is base address
    nPtr = &numbers[0];   // equivalent form

    // e) Print using pointer/offset notation with nPtr
    cout << "Array elements (pointer/offset with nPtr): ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << fixed << setprecision(1) << *(nPtr + i) << " ";
    }
    cout << endl;

    // f) Print using pointer/offset notation with array name
    cout << "Array elements (pointer/offset with array name): ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << fixed << setprecision(1) << *(numbers + i) << " ";
    }
    cout << endl;

    // g) Print using pointer/subscript notation with nPtr
    cout << "Array elements (pointer/subscript with nPtr): ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << fixed << setprecision(1) << nPtr[i] << " ";
    }
    cout << endl;

    // h) Refer to 4th element in 4 different ways
    cout << "\nFourth element of numbers:\n";
    cout << "Subscript notation: numbers[3] = " << numbers[3] << endl;
    cout << "Pointer/offset with array name: *(numbers + 3) = " << *(numbers + 3) << endl;
    cout << "Pointer/subscript with nPtr: nPtr[3] = " << nPtr[3] << endl;
    cout << "Pointer/offset with nPtr: *(nPtr + 3) = " << *(nPtr + 3) << endl;

    // i) nPtr + 8 (points to numbers[8])
    cout << "\nnPtr + 8 points to address: " << (nPtr + 8) << " value = " << *(nPtr + 8) << endl;

    // j) nPtr points to numbers[5], then nPtr -= 4
    nPtr = &numbers[5];
    nPtr -= 4;  // now points to numbers[1]
    cout << "After nPtr -= 4, address: " << nPtr << " value = " << *nPtr << endl;

    return 0;
}

