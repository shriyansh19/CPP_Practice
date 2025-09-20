#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// ---------------------- CLASS ServiceRecord ----------------------
class ServiceRecord {
private:
    string date_;          // Service date in YYYY-MM-DD
    int mileage_;          // Mileage at service (must be >= 0)
    string description_;   // Description of the service

public:
    // Default constructor
    ServiceRecord() 
    {
        date_= ""; 
        mileage_= 0;
        description_= "";
    }

    // Parameterized constructor (validates mileage)
    ServiceRecord(const string& date, int mileage, const string& description) 
    {
        if (mileage < 0) 
        throw invalid_argument("Mileage cannot be negative");
        
        date_ = date;
        mileage_ = mileage;
        description_ = description;
    }

    // Copy constructor
    ServiceRecord(const ServiceRecord& other) 
    {
        date_ = other.date_;
        mileage_ = other.mileage_;
        description_ = other.description_;
    }

    // Assignment operator
    ServiceRecord& operator=(const ServiceRecord& other) {
        if (this != &other) 
        {
            date_ = other.date_;
            mileage_ = other.mileage_;
            description_ = other.description_;
        }

        return *this;
    }

    // Getters (read-only)
    const string& getDate() const { 
        return date_; 
    }
    int getMileage() const 
    { 
        return mileage_; 
    }
    const string& getDescription() const { 
        return description_; 
    }

    // Utility to print the record
    void print() const 
    {
        cout << "Date: " << date_ << ", Mileage: " << mileage_ << ", Description: " << description_ << endl;
    }
};

// ---------------------- Class Car ----------------------
class Car {
private:
    string vin_;      // Vehicle Identification Number
    string make_;     // Manufacturer
    string model_;    // Model
    double price_;    // Price (>= 0)

    // Dynamic array of ServiceRecord
    ServiceRecord* serviceHistory_;
    size_t serviceCount_;
    size_t serviceCap_;

    // Dynamic array of damage codes
    int* damageCodes_;
    size_t damageCount_;
    size_t damageCap_;

    // Static counter for all Car objects
    static size_t totalCars_;

    // Helper function to expand service array
    void reserveService(size_t newCap) 
    {
        if (newCap <= serviceCap_) 
        return;

        ServiceRecord* newArr = new ServiceRecord[newCap];

        for (size_t i = 0; i < serviceCount_; i++)
        newArr[i] = serviceHistory_[i]; // copy existing records
        
        delete[] serviceHistory_;
        serviceHistory_ = newArr;
        serviceCap_ = newCap;
    }

    // Helper function to expand damage array
    void reserveDamage(size_t newCap) 
    {
        if (newCap <= damageCap_) 
        return;

        int* newArr = new int[newCap];

        for (size_t i = 0; i < damageCount_; i++) 
        newArr[i] = damageCodes_[i]; // copy existing codes
       
        delete[] damageCodes_;
        damageCodes_ = newArr;
        damageCap_ = newCap;
    }

public:
    // Default constructor
Car() {
    vin_ = "";
    make_ = "";
    model_ = "";
    price_ = 0.0;

    serviceHistory_ = nullptr;
    serviceCount_ = 0;
    serviceCap_ = 0;

    damageCodes_ = nullptr;
    damageCount_ = 0;
    damageCap_ = 0;

    totalCars_++;
}

// Parameterized constructor
Car(const string& vin, const string& make, const string& model, double price) {
    if (price < 0) 
    {
        throw invalid_argument("Price cannot be negative");
    }

    vin_ = vin;
    make_ = make;
    model_ = model;
    price_ = price;

    serviceHistory_ = nullptr;
    serviceCount_ = 0;
    serviceCap_ = 0;

    damageCodes_ = nullptr;
    damageCount_ = 0;
    damageCap_ = 0;

    totalCars_++;
}

// Copy constructor (deep copy)
Car(const Car& other) 
{
    vin_ = other.vin_;
    make_ = other.make_;
    model_ = other.model_;
    price_ = other.price_;

    serviceCount_ = other.serviceCount_;
    serviceCap_ = other.serviceCap_;
    serviceHistory_ = new ServiceRecord[serviceCap_];

    for (size_t i = 0; i < serviceCount_; i++) 
    {
        serviceHistory_[i] = other.serviceHistory_[i];
    }

    damageCount_ = other.damageCount_;
    damageCap_ = other.damageCap_;
    damageCodes_ = new int[damageCap_];

    for (size_t i = 0; i < damageCount_; i++) 
    damageCodes_[i] = other.damageCodes_[i];
    

    totalCars_++;
}


    // Destructor
    ~Car() {
        delete[] serviceHistory_;
        delete[] damageCodes_;
        totalCars_--;
    }

    
    Car& operator=(Car other) {
        swap(*this, other);
        return *this;
    }

    // Friend swap function
    friend void swap(Car& lhs, Car& rhs) noexcept {
        std::swap(lhs.vin_, rhs.vin_);
        std::swap(lhs.make_, rhs.make_);
        std::swap(lhs.model_, rhs.model_);
        std::swap(lhs.price_, rhs.price_);
        std::swap(lhs.serviceHistory_, rhs.serviceHistory_);
        std::swap(lhs.serviceCount_, rhs.serviceCount_);
        std::swap(lhs.serviceCap_, rhs.serviceCap_);
        std::swap(lhs.damageCodes_, rhs.damageCodes_);
        std::swap(lhs.damageCount_, rhs.damageCount_);
        std::swap(lhs.damageCap_, rhs.damageCap_);
    }

    // Static accessor
    static size_t getTotalCars() {
        return totalCars_; 
    }

    // Setters
    void setVIN(const string& vin) 
    { 
        vin_ = vin; 
    }
    void setMake(const string& make) 
    { 
        make_ = make; 
    }
    void setModel(const string& model) {
        model_ = model; 
    }
    void setPrice(double price) 
    {
        if (price < 0) 
        throw invalid_argument("Price cannot be negative");

        price_ = price;
    }

    // Getters
    const string& getVIN() const { 
        return vin_; 
    }
    const string& getMake() const { 
        return make_; 
    }
    const string& getModel() const { 
        return model_; 
    }
    double getPrice() const { 
        return price_; 
    }
    size_t getServiceCount() const 
    { 
        return serviceCount_; 
    }
    size_t getDamageCount() const { 
        return damageCount_; 
    }
    const ServiceRecord* getServiceHistory() const { 
        return serviceHistory_; 
    }
    const int* getDamageCodes() const { 
        return damageCodes_; 
    }

    // Business logic: add a service record
    void addService(const ServiceRecord& rec) {

        if (serviceCount_ == serviceCap_) 
        {
            size_t newCap = (serviceCap_ == 0) ? 2 : serviceCap_ * 2;
            reserveService(newCap);
        }

        serviceHistory_[serviceCount_++] = rec;
    }

    // Business logic: add a damage code
    void addDamageCode(int code) 
    {
        if (damageCount_ == damageCap_) 
        {
            size_t newCap = (damageCap_ == 0) ? 2 : damageCap_ * 2;
            reserveDamage(newCap);
        }

        damageCodes_[damageCount_++] = code;
    }

    // Print car info
    void printInfo() const 
    {
        cout << "VIN: " << vin_ << ", Make: " << make_ << ", Model: " << model_ << ", Price: $" << price_ << ", Services: " << serviceCount_ << ", Damages: " << damageCount_ << endl;
    }
};

// Initialize static member
size_t Car::totalCars_ = 0;

// ---------------------- GLOBAL FUNCTIONS ----------------------

// Average price of array of cars
double averagePrice(const Car* arr, size_t n) 
{
    if (n == 0) 
    return 0.0;

    double sum = 0;

    for (size_t i = 0; i < n; i++) 
    {
        sum += arr[i].getPrice();
    }

    return sum / n;
}

// Compare by price ascending
bool compareByPriceAsc(const Car& a, const Car& b) 
{
    return a.getPrice() < b.getPrice();
}

// Compare by price descending
bool compareByPriceDesc(const Car& a, const Car& b) 
{
    return a.getPrice() > b.getPrice();
}

// Check equality by VIN
bool areCarsEqual(const Car& a, const Car& b) 
{
    return a.getVIN() == b.getVIN();
}

// Max price car
const Car* maxPriceCar(const Car* arr, size_t n) {
    if (n == 0) 
    return NULL;

    const Car* maxCar = &arr[0];

    for (size_t i = 1; i < n; i++) 
    {
        if (arr[i].getPrice() > maxCar->getPrice()) 
        {
            maxCar = &arr[i];
        }
    }

    return maxCar;
}

// Find car by VIN
const Car* findCarByVIN(const Car* arr, size_t n, const string& vin) 
{
    for (size_t i = 0; i < n; i++) 
    {
        if (arr[i].getVIN() == vin) 
        {
            return &arr[i];
        }
    }
    return NULL;
}

// Count cars with given damage code
size_t countCarsWithDamage(const Car* arr, size_t n, int code) 
{
    size_t count = 0;

    for (size_t i = 0; i < n; i++) 
    {
        const int* codes = arr[i].getDamageCodes();
        for (size_t j = 0; j < arr[i].getDamageCount(); j++) 
        {
            if (codes[j] == code) 
            {
                count++;
                break;
            }
        }
    }
    return count;
}

// Swap two cars (non-member)
void swapCars(Car& a, Car& b) 
{
    swap(a, b);
}

// ---------------------- MAIN FUNCTION ----------------------
int main() 
{
    cout << "Initial Car count: " << Car::getTotalCars() << endl;

    // Default Car
    Car cDefault;
    cDefault.printInfo();

    // Parameterized Car
    Car cHonda("1HGCM", "Honda", "Accord", 19999.99);
    cHonda.printInfo();

    // Add damage codes
    cHonda.addDamageCode(101);
    cHonda.addDamageCode(205);
    cHonda.addDamageCode(307);

    // Add service records
    ServiceRecord sr1("2022-03-15", 15000, "Oil change");
    ServiceRecord sr2("2023-01-10", 25000, "Brake replacement");

    cHonda.addService(sr1);
    cHonda.addService(sr2);

    cHonda.printInfo();

    // Copy constructor
    Car cCopy(cHonda);
    cCopy.printInfo();

    // Assignment operator
    Car cAssign;
    cAssign = cHonda;
    cAssign.printInfo();

    // Heap array of Cars
    size_t N = 3;
    Car* garage = new Car[N];

    garage[0] = Car("JH4KA", "Acura", "TLX", 27999.49);
    garage[1] = Car("5YJ3E", "Tesla", "Model 3", 39999.00);
    garage[2] = Car("WBA4", "BMW", "3 Series", 34999.99);

    cout << "Average price of garage: " << averagePrice(garage, N) << endl;

    const Car* maxCar = maxPriceCar(garage, N);
    
    if (maxCar) 
    cout << "Most expensive car VIN: " << maxCar->getVIN() << endl;
   

    // Cleanup
    delete[] garage;

    cout << "Final Car count: " << Car::getTotalCars() << endl;

    return 0;
}
