#ifndef INVOICE_H
#define INVOICE_H

#include <string>

// Class definition for Invoice
class Invoice {
private:
    std::string partNumber;       // Unique string identifier for the item
    std::string partDescription;  // Text description of the item
    int quantity;                 // Number of units purchased (must be >= 0)
    int pricePerItem;             // Price of a single unit (must be >= 0)

public:
    // Constructs an Invoice object with all details provided.
    // If quantity or price are less than 0, they will be set to 0.
    Invoice(std::string pNumber, std::string pDescription, int qty, int price);

    // Sets the item part number.
    void setPartNumber(std::string pNumber);

    // Sets the item description.
    void setPartDescription(std::string pDescription);

    // Sets the purchase quantity (uses 0 if a negative value is given).
    void setQuantity(int qty);

    // Sets the price per item (uses 0 if a negative value is given).
    void setPricePerItem(int price);

    // Returns the item part number.
    std::string getPartNumber();

    // Returns the item description.
    std::string getPartDescription();

    // Returns the purchase quantity.
    int getQuantity();

    // Returns the price per item.
    int getPricePerItem();

    // Calculates and returns the total amount for the invoice.
    int getInvoiceAmount();
};

#endif
