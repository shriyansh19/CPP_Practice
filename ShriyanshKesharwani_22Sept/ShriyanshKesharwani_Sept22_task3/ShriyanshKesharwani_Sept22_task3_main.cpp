// ShriyanshKesharwani_Sept22_task2_main.cpp
// Test program for class Invoice

#include <iostream>
#include "ShriyanshKesharwani_Sept22_task3_Invoice.cpp"

int main() {
    // Create first invoice with valid details
    Invoice invoice1("101", "Hammer", 5, 120);

    // Create second invoice with invalid quantity (-3)
    Invoice invoice2("102", "Screwdriver", -3, 80);

    // Display details of first invoice
    std::cout << "Invoice 1:" << std::endl;
    std::cout << "Part Number: " << invoice1.getPartNumber() << std::endl;
    std::cout << "Part Description: " << invoice1.getPartDescription() << std::endl;
    std::cout << "Quantity: " << invoice1.getQuantity() << std::endl;
    std::cout << "Price per Item: " << invoice1.getPricePerItem() << std::endl;
    std::cout << "Invoice Amount: " << invoice1.getInvoiceAmount() << std::endl;

    std::cout << std::endl;

    // Display details of second invoice
    std::cout << "Invoice 2:" << std::endl;
    std::cout << "Part Number: " << invoice2.getPartNumber() << std::endl;
    std::cout << "Part Description: " << invoice2.getPartDescription() << std::endl;
    std::cout << "Quantity: " << invoice2.getQuantity() << std::endl;  // should be 0
    std::cout << "Price per Item: " << invoice2.getPricePerItem() << std::endl;
    std::cout << "Invoice Amount: " << invoice2.getInvoiceAmount() << std::endl;

    return 0;
}
