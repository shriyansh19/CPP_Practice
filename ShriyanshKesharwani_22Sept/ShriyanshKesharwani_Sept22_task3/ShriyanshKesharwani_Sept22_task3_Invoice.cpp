#include "ShriyanshKesharwani_Sept22_task3_Invoice.h"
#include <iostream>

// Constructor definition
Invoice::Invoice(std::string pNumber, std::string pDescription, int qty, int price) {
    partNumber = pNumber;
    partDescription = pDescription;

    // Initialize quantity (must not be negative)
    if (qty > 0) 
    {
        quantity = qty;
    } 
    else {
        quantity = 0;
    }

    // Initialize price per item (must not be negative)
    if (price > 0) 
    {
        pricePerItem = price;
    } 
    else 
    {
        pricePerItem = 0;
    }
}

// Setter for partNumber
void Invoice::setPartNumber(std::string pNumber) {
    partNumber = pNumber;
}

// Setter for partDescription
void Invoice::setPartDescription(std::string pDescription) {
    partDescription = pDescription;
}

// Setter for quantity
// Only accepts positive values; sets to 0 if invalid
void Invoice::setQuantity(int qty) {
    if (qty > 0) 
    {
        quantity = qty;
    } 
    else 
    {
        quantity = 0;
    }
}

// Setter for pricePerItem
// Only accepts positive values; sets to 0 if invalid
void Invoice::setPricePerItem(int price) {
    if (price > 0) 
    {
        pricePerItem = price;
    } 
    else 
    {
        pricePerItem = 0;
    }
}

// Getter for partNumber
std::string Invoice::getPartNumber() {
    return partNumber;
}

// Getter for partDescription
std::string Invoice::getPartDescription() {
    return partDescription;
}

// Getter for quantity
int Invoice::getQuantity() {
    return quantity;
}

// Getter for pricePerItem
int Invoice::getPricePerItem() {
    return pricePerItem;
}

// Returns the total amount for the invoice
int Invoice::getInvoiceAmount() {
    return (quantity * pricePerItem);
}
