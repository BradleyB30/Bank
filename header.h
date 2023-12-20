#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    BankAccount(const std::string& accNum, const std::string& accHolder, double initialBalance);

    std::string getAccountNumber() const;
    std::string getAccountHolder() const;
    double getBalance() const;

    void deposit(double amount);
    void withdraw(double amount);
    void changeAccountHolderName(const std::string& newAccHolder); // New function
    void display() const;
};

class Bank {
private:
    std::vector<BankAccount> accounts;

public:
    void addAccount(const std::string& accNum, const std::string& accHolder, double initialBalance);
    void displayAllAccounts() const;
    void performTransactions();
    void transferFunds(const std::string& sourceAccNum, const std::string& targetAccNum, double amount);
    void checkBalance(const std::string& accNum) const;
    void searchAccount(const std::string& accNum) const;
    void changeAccountHolderName(const std::string& accNum, const std::string& newAccHolder); // New function
};

#endif // HEADER_H
