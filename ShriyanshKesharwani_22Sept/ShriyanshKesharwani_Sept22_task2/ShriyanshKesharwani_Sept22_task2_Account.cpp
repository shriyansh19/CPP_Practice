// ShriyanshKesharwani_Sept22_task2_Account.cpp - Implementation of Account class
#include <iostream>
#include "ShriyanshKesharwani_Sept22_task2_Account.h"

// Constructor with validation
Account::Account(int initialBalance) 
{
    if (initialBalance >= 0) {
        balance = initialBalance;
    } 
    else 
    {
        balance = 0;
        std::cout << "Error: Initial balance invalid, set to 0." << std::endl;
    }
}

// Add money to balance
void Account::credit(int amount) 
{
    balance = balance + amount;
}

// Withdraw money if enough balance
void Account::debit(int amount) 
{
    if (amount > balance) {
        std::cout << "Debit amount exceeded account balance." << std::endl;
    } 
    else {
        balance = balance - amount;
    }
}

// Getter for balance
int Account::getBalance() const 
{
    return balance;
}
