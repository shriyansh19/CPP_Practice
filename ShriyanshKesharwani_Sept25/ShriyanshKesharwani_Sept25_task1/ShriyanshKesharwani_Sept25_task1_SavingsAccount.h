// SavingsAccount class

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount {
    double savingsBalance;                // Current balance of the saver
    static double annualInterestRate;     // Annual interest rate (shared by all savers)
public:
    // Constructor
    SavingsAccount(double balance = 0.0);

    // Calculate monthly interest and add to savingsBalance
    void calculateMonthlyInterest();

    // Display current balance
    void displayBalance();

    // Static function to modify interest rate
    static void modifyInterestRate(double newRate);
};

#endif
