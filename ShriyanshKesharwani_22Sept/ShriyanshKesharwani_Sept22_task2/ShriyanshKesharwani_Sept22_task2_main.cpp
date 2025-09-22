// ShriyanshKesharwani_Sept22_task2_main.cpp - Test program for Account class
#include <iostream>
#include "ShriyanshKesharwani_Sept22_task2_Account.cpp"

int main() {
    // Create two Account objects
    Account account1(50);   // valid balance
    Account account2(-10);  // invalid balance, should reset to 0

    // Show initial balances
    std::cout << "Account1 balance: " << account1.getBalance() << std::endl;
    std::cout << "Account2 balance: " << account2.getBalance() << std::endl;

    // Credit money to account1
    account1.credit(25);
    std::cout << "Account1 balance after crediting 25: " << account1.getBalance() << std::endl;

    // Debit money from account1
    account1.debit(30);
    std::cout << "Account1 balance after debiting 30: " << account1.getBalance() << std::endl;

    // Try to debit more than balance
    account1.debit(100);

    // Credit money to account2
    account2.credit(40);
    std::cout << "Account2 balance after crediting 40: " << account2.getBalance() << std::endl;

    return 0;
}
