// Test program for SavingsAccount class

#include <iostream>
#include "ShriyanshKesharwani_Sept25_task1_SavingsAccount.h"
int main() {
    // Create two saver objects with initial balances
    SavingsAccount saver1(2000.0);
    SavingsAccount saver2(3000.0);

    // Set interest rate to 3%
    SavingsAccount::modifyInterestRate(0.03);

    std::cout << "Balances after applying 3% annual interest (1 month): " << std::endl;
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "Saver1 balance: ";
    saver1.displayBalance();
    std::cout << std::endl;

    std::cout << "Saver2 balance: ";
    saver2.displayBalance();
    std::cout << std::endl << std::endl;

    // Change interest rate to 4%
    SavingsAccount::modifyInterestRate(0.04);

    std::cout << "Balances after applying 4% annual interest (next month): " << std::endl;
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "Saver1 balance: ";
    saver1.displayBalance();
    std::cout << std::endl;

    std::cout << "Saver2 balance: ";
    saver2.displayBalance();
    std::cout << std::endl;

    return 0;
}
