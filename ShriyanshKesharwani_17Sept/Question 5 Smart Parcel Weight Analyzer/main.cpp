#include <iostream>
#include <string>

// Class to analyze parcel weights
class ParcelAnalyzer
{
public:
    // Function to classify weight in grams
    std::string classifyWeight(int grams)
    {
        if (grams < 500)
        {
            return "Light";
        }
        else if (grams <= 2000)
        {
            return "Medium";
        }
        else
        {
            return "Heavy";
        }
    }

    // Function to classify weight in kilograms
    std::string classifyWeight(float kilograms)
    {
        if (kilograms < 0.5f)
        {
            return "Light";
        }
        else if (kilograms <= 2.0f)
        {
            return "Medium";
        }
        else
        {
            return "Heavy";
        }
    }

    // Function to classify weight in pounds
    std::string classifyWeight(double pounds)
    {
        if (pounds < 1.1)
        {
            return "Light";
        }
        else if (pounds <= 4.4)
        {
            return "Medium";
        }
        else
        {
            return "Heavy";
        }
    }
};

// Global function to print classification result
void printClassification(const std::string& label)
{
    std::cout << "Classification: " << label << std::endl;
}

// Main function
int main()
{
    // Create object of ParcelAnalyzer
    ParcelAnalyzer analyzer;

    // Test with grams
    printClassification(analyzer.classifyWeight(450));    // Light
    printClassification(analyzer.classifyWeight(1500));   // Medium
    printClassification(analyzer.classifyWeight(2500));   // Heavy

    // Test with kilograms
    printClassification(analyzer.classifyWeight(0.3f));   // Light
    printClassification(analyzer.classifyWeight(1.5f));   // Medium
    printClassification(analyzer.classifyWeight(3.0f));   // Heavy

    // Test with pounds
    printClassification(analyzer.classifyWeight(0.9));    // Light
    printClassification(analyzer.classifyWeight(2.5));    // Medium
    printClassification(analyzer.classifyWeight(5.0));    // Heavy

    return 0;
}
