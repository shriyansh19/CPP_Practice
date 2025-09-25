// Member-function definitions for SavingsAccount class

#include <iostream>
#include <iomanip>
#include "ShriyanshKesharwani_Sept25_task1_SavingsAccount.h"

// Initialize static member
double SavingsAccount::annualInterestRate = 0.0;

// Constructor
SavingsAccount::SavingsAccount(double balance) {
    savingsBalance = (balance >= 0.0) ? balance : 0.0;  // validation: no negative balance
}

// Calculate monthly interest and add to balance
void SavingsAccount::calculateMonthlyInterest() {
    double interest = savingsBalance * (annualInterestRate / 12.0);
    savingsBalance += interest;
}

// Display current balance
void SavingsAccount::displayBalance() {
    std::cout << std::fixed << std::setprecision(2) << "$" << savingsBalance;
}

// Static function to modify interest rate
void SavingsAccount::modifyInterestRate(double newRate) {

    if (newRate >= 0.0) 
    {
        annualInterestRate = newRate;
    }
}
