#include <iostream>

int main() {
    int unique[20]; // Array for storing unique numbers
    int count = 0;  // Keeps track of how many unique numbers have been entered

    // Loop 20 times for user input
    for (int i = 0; i < 20; ++i) 
    {
        int num;
        std::cout << "Enter number " << (i + 1) << " (10-100): ";
        std::cin >> num;

        // Check if input is in valid range
        if (num < 10 || num > 100) 
        {
            std::cout << "Number not in valid range." << std::endl;
            continue; // Skip to next iteration if not valid
        }

        // Flag to check if the number is a duplicate
        bool isDuplicate = false;
        // Loop through the array to check for duplicates
        for (int j = 0; j < count; ++j) 
        {
            if (unique[j] == num) 
            {
                isDuplicate = true; // Number already exists
                break;
            }
        }

        // If not a duplicate, store it in the array
        if (!isDuplicate) 
        {
            unique[count] = num;
            ++count; // Increment the count of unique numbers stored
            std::cout << "Accepted: " << num << std::endl;
        } 
        else 
        {
            std::cout << "Duplicate detected: " << num << std::endl;
        }
    }

    // Display all unique numbers entered by the user
    std::cout << "Unique numbers entered:" << std::endl;
    for (int i = 0; i < count; ++i) 
    {
        std::cout << unique[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
