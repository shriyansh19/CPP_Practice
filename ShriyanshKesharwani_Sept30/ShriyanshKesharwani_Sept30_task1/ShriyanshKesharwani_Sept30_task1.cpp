#include <iostream>
using std::cout;
using std::endl;


int main() {
    const int SIZE = 5;

    // (a) Declare an array and initialize it
    unsigned int values[SIZE] = {2, 4, 6, 8, 10};

    // (b) Declare a pointer to unsigned int
    unsigned int *vPtr;

    // (c) Print elements using array subscript notation
    cout << "(c) Using array subscript notation: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << values[i] << " ";
    }
    cout << endl;

    // (d) Assign starting address of array to vPtr
    vPtr = values;      // method 1
    vPtr = &values[0];  // method 2

    // (e) Print elements using pointer/offset notation
    cout << "(e) Using pointer/offset notation with vPtr: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << *(vPtr + i) << " ";
    }
    cout << endl;

    // (f) Using array name as pointer
    cout << "(f) Using array name as pointer: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << *(values + i) << " ";
    }
    cout << endl;

    // (g) Subscript the pointer directly
    cout << "(g) Subscript pointer to array: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << vPtr[i] << " ";
    }
    cout << endl;

    // (h) Refer to 5th element in four different ways
    cout << "(h) Fifth element references:" << endl;
    cout << "Array subscript: " << values[4] << endl;
    cout << "Pointer/offset with array name: " << *(values + 4) << endl;
    cout << "Pointer subscript: " << vPtr[4] << endl;
    cout << "Pointer/offset with vPtr: " << *(vPtr + 4) << endl;

    // (i) vPtr + 3
    cout << "(i) vPtr + 3 points to address: " << (vPtr + 3) << endl;
    cout << "Value at that address: " << *(vPtr + 3) << endl;

    // (j) If vPtr points to values[4], vPtr -= 4
    vPtr = &values[4];
    vPtr -= 4;
    cout << "(j) vPtr after -= 4 points to: " << vPtr << endl;
    cout << "Value at that address: " << *vPtr << endl;

    return 0;
}
