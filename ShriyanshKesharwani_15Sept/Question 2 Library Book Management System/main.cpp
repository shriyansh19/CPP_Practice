#include <iostream>
#include <iomanip>   // For formatted output
#include <string>

// Enum for book genre
enum Genre { 
    FICTION, NONFICTION, SCIENCE, HISTORY, TECHNOLOGY 
};

// Function to convert Genre enum to string
std::string genreToString(Genre g) {
    switch (g) {
        case FICTION: 
            return "Fiction";
        case NONFICTION: 
            return "Non-Fiction";
        case SCIENCE: 
            return "Science";
        case HISTORY: 
            return "History";
        case TECHNOLOGY: 
            return "Technology";
        default: 
            return "Unknown";
    }
}

// Class Book
class Book {
private:
    int bookID;
    float rating;
    double price;
    char availabilityStatus;  
    bool isReferenceOnly;
    std::string title;
    Genre genre;

public:
    // Default constructor
    Book() {
        bookID = 0;
        rating = 0.0;
        price = 0.0;
        availabilityStatus = 'A';
        isReferenceOnly = false;
        title = "Untitled";
        genre = FICTION;
    }

    // Parameterized constructor
    Book(int id, float r, double p, char status, bool ref, std::string t, Genre g) {
        bookID = id;
        rating = r;
        price = p;
        availabilityStatus = status;
        isReferenceOnly = ref;
        title = t;
        genre = g;
    }

    // Destructor
    ~Book() {
        std::cout << "Book object with ID " << bookID << " destroyed." << std::endl;
    }

    // Getters and setters
    int getBookID() const {
        return bookID;
    }

    void setBookID(int id) {
        bookID = id;
    }

    float getRating() const {
        return rating;
    }

    void setRating(float r) {
        rating = r;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double p) {
        price = p;
    }

    char getAvailabilityStatus() const {
        return availabilityStatus;
    }

    void setAvailabilityStatus(char s) {
        availabilityStatus = s;
    }

    bool getIsReferenceOnly() const {
        return isReferenceOnly;
    }

    void setIsReferenceOnly(bool ref) {
        isReferenceOnly = ref;
    }

    std::string getTitle() const {
        return title;
    }

    void setTitle(const std::string& t) {
        title = t;
    }

    Genre getGenre() const {
        return genre;
    }

    void setGenre(Genre g) {
        genre = g;
    }

    // Update availability
    void updateAvailability(bool isBorrowed) {
        if (isBorrowed) {
            availabilityStatus = 'B';
        } else {
            availabilityStatus = 'A';
        }
    }

    // Display details
    void displayDetails() const {
        std::cout << "Book ID: " << bookID << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Rating: " << rating << std::endl;

        if (availabilityStatus == 'A') {
            std::cout << "Availability: Available" << std::endl;
        } 
        else {
            std::cout << "Availability: Borrowed" << std::endl;
        }

        if (isReferenceOnly) {
            std::cout << "Reference Only: Yes" << std::endl;
        } 
        else {
            std::cout << "Reference Only: No" << std::endl;
        }

        std::cout << "Genre: " << genreToString(genre) << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }
};

// Global Functions
void markAsReference(Book &book) {
    book.setIsReferenceOnly(true);

    std::cout << "Book \"" << book.getTitle() << "\" is now marked as Reference Only." << std::endl;
}

bool isAffordable(const Book &book, const double budget) {
    if (book.getPrice() <= budget) {
        return true;
    } 
    else {
        return false;
    }
}

void printFormattedBookList(const Book books[], const int size) {
    std::cout << std::left << std::setw(5) << "ID"<< std::setw(20) << "Title"<< std::setw(10) << "Price"<< std::setw(8) << "Rating"<< std::setw(10) << "Status"<< std::setw(12) << "Reference"<< std::endl;

    std::cout << "-------------------------------------------------------------" << std::endl;

    for (int i = 0; i < size; i++) {
        std::cout << std::left << std::setw(5) << books[i].getBookID()<< std::setw(20) << books[i].getTitle()<< std::setw(10) << books[i].getPrice()<< std::setw(8) << books[i].getRating();

        if (books[i].getAvailabilityStatus() == 'A') {
            std::cout << std::setw(10) << "Available";
        } 
        else {
            std::cout << std::setw(10) << "Borrowed";
        }

        if (books[i].getIsReferenceOnly()) {
            std::cout << std::setw(12) << "Yes";
        } 
        else {
            std::cout << std::setw(12) << "No";
        }

        std::cout << std::endl;
    }
}

// Main function
int main() {
    const int SIZE = 3;

    Book books[SIZE] = {
        Book(101, 4.5, 299.99, 'A', false, "C++ Primer", TECHNOLOGY),
        Book(102, 3.8, 150.00, 'B', true, "Design Patterns", SCIENCE),
        Book() // default constructor
    };

    int choice;

    do {
        std::cout << std::endl;
        std::cout << "--- Library Menu ---" << std::endl;
        std::cout << "1. Add/Update Book Details" << std::endl;
        std::cout << "2. Mark Book as Reference Only" << std::endl;
        std::cout << "3. Check if Book is Affordable" << std::endl;
        std::cout << "4. Update Availability" << std::endl;
        std::cout << "5. Display Book Details" << std::endl;
        std::cout << "6. Display All Books" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int index;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;

            if (index >= 0 && index < SIZE) {
                int id;
                int g;
                float rating;
                double price;
                char status;
                bool ref;
                std::string title;

                std::cout << "Enter Book ID: ";
                std::cin >> id;

                do {
                    std::cout << "Enter Rating (0.0 - 5.0): ";
                    std::cin >> rating;
                } while (rating < 0.0 || rating > 5.0);

                do {
                    std::cout << "Enter Price (>0): ";
                    std::cin >> price;
                } while (price <= 0);

                std::cout << "Enter Status (A=Available, B=Borrowed): ";
                std::cin >> status;

                std::cout << "Is Reference Only? (1=Yes, 0=No): ";
                std::cin >> ref;

                std::cin.ignore();

                do {
                    std::cout << "Enter Title: ";
                    std::getline(std::cin, title);
                } while (title.empty());

                std::cout << "Select Genre (0=Fiction,1=NonFiction,2=Science,3=History,4=Technology): ";
                std::cin >> g;

                books[index] = Book(id, rating, price, status, ref, title, (Genre)g);

                std::cout << "Book details updated successfully!" << std::endl;
            }
        }
        else if (choice == 2) {
            int id;
            std::cout << "Enter Book ID: ";
            std::cin >> id;

            for (int i = 0; i < SIZE; i++) {
                if (books[i].getBookID() == id) {
                    markAsReference(books[i]);
                }
            }
        }
        else if (choice == 3) {
            int id;
            double budget;

            std::cout << "Enter Book ID: ";
            std::cin >> id;

            std::cout << "Enter Budget: ";
            std::cin >> budget;

            for (int i = 0; i < SIZE; i++) {
                if (books[i].getBookID() == id) {
                    if (isAffordable(books[i], budget)) {
                        std::cout << "The book is affordable." << std::endl;
                    } else {
                        std::cout << "The book is too expensive." << std::endl;
                    }
                }
            }
        }
        else if (choice == 4) {
            int id;
            std::cout << "Enter Book ID: ";
            std::cin >> id;

            for (int i = 0; i < SIZE; i++) {
                if (books[i].getBookID() == id) {
                    bool isBorrowed;

                    std::cout << "Is Borrowed? (1=Yes, 0=No): ";
                    std::cin >> isBorrowed;

                    books[i].updateAvailability(isBorrowed);

                    std::cout << "Availability updated successfully!" << std::endl;
                }
            }
        }
        else if (choice == 5) {
            int id;
            std::cout << "Enter Book ID: ";
            std::cin >> id;

            for (int i = 0; i < SIZE; i++) {
                if (books[i].getBookID() == id) {
                    books[i].displayDetails();
                }
            }
        }
        else if (choice == 6) {
            printFormattedBookList(books, SIZE);
        }
        else if (choice == 7) {
            std::cout << "Exiting program..." << std::endl;
        }
        else {
            std::cout << "Invalid choice!" << std::endl;
        }

    } while (choice != 7);

    return 0;
}