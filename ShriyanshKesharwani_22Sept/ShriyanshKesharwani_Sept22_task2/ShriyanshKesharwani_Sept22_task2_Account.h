// ShriyanshKesharwani_Sept22_task2_Account.h - Header file for Account class
// Declares the Account class 

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    int balance; // account balance
public:
    // Constructor with validation
    Account(int initialBalance);

    // Add money to the account
    void credit(int amount);

    // Withdraw money if balance is enough
    void debit(int amount);

    // Return current balance
    int getBalance() const;

    
};

#endif
