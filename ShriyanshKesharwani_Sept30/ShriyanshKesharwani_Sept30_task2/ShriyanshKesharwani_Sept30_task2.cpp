#include <iostream>
using std::cout;
using std::endl;

// Function to swap two integers
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function: places pivot at correct position
int partition(int arr[], int start, int end) {
    int pivot = arr[start];   // take first element as pivot
    int left = start + 1;     // left index
    int right = end;          // right index

    while (true) {
        // move from right until element < pivot is found
        while (left <= right && arr[right] >= pivot) 
        {
            right--;
        }

        // move from left until element > pivot is found
        while (left <= right && arr[left] <= pivot) 
        {
            left++;
        }

        // if pointers cross, break
        if (left > right) 
        {
            break;
        }

        // swap out-of-place elements
        swap(arr[left], arr[right]);
    }

    // place pivot at correct position
    swap(arr[start], arr[right]);

    return right;  // return pivot's final position
}

// Recursive quicksort function
void quickSort(int arr[], int start, int end) {
    if (start < end) 
    {
        // partition the array and get pivot index
        int pivotIndex = partition(arr, start, end);

        // recursively sort left subarray
        quickSort(arr, start, pivotIndex - 1);

        // recursively sort right subarray
        quickSort(arr, pivotIndex + 1, end);
    }
}

int main() {
    const int SIZE = 10;
    int arr[SIZE] = {7, 12, 66, 41, 8, 80, 10, 19, 6, 96};

    cout << "Original array: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call quickSort on entire array
    quickSort(arr, 0, SIZE - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
