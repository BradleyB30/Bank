#include "header.h"
#include <algorithm>
#include <limits>

BankAccount::BankAccount(const std::string& accNum, const std::string& accHolder, double initialBalance)
    : accountNumber(accNum), accountHolder(accHolder), balance(initialBalance) {}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

std::string BankAccount::getAccountHolder() const {
    return accountHolder;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    } else {
        std::cout << "Insufficient funds!" << std::endl;
    }
}

void BankAccount::changeAccountHolderName(const std::string& newAccHolder) {
    accountHolder = newAccHolder;
    std::cout << "Account holder name changed to: " << accountHolder << std::endl;
}

void BankAccount::display() const {
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Account Holder: " << accountHolder << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
}

void Bank::addAccount(const std::string& accNum, const std::string& accHolder, double initialBalance) {
    BankAccount account(accNum, accHolder, initialBalance);
    accounts.push_back(account);
}

void Bank::displayAllAccounts() const {
    for (const auto& account : accounts) {
        account.display();
        std::cout << "-----------------------" << std::endl;
    }
}

void Bank::performTransactions() {
    if (accounts.size() >= 2) {
        std::string sourceAccNum, targetAccNum;
        double amount;

        std::cout << "Enter source account number: ";
        std::cin >> sourceAccNum;

        std::cout << "Enter target account number: ";
        std::cin >> targetAccNum;

        std::cout << "Enter amount to transfer: ";
        std::cin >> amount;

        transferFunds(sourceAccNum, targetAccNum, amount);
    }
}

void Bank::transferFunds(const std::string& sourceAccNum, const std::string& targetAccNum, double amount) {
    auto sourceAccount = std::find_if(accounts.begin(), accounts.end(),
        [&sourceAccNum](const BankAccount& acc) { return acc.getAccountNumber() == sourceAccNum; });

    auto targetAccount = std::find_if(accounts.begin(), accounts.end(),
        [&targetAccNum](const BankAccount& acc) { return acc.getAccountNumber() == targetAccNum; });

    if (sourceAccount != accounts.end() && targetAccount != accounts.end()) {
        if (sourceAccount->getBalance() >= amount) {
            sourceAccount->withdraw(amount);
            targetAccount->deposit(amount);
            std::cout << "Transfer successful!" << std::endl;
        } else {
            std::cout << "Transfer failed. Insufficient funds in the source account." << std::endl;
        }
    } else {
        std::cout << "One or both accounts not found." << std::endl;
    }
}

void Bank::checkBalance(const std::string& accNum) const {
    auto account = std::find_if(accounts.begin(), accounts.end(),
        [&accNum](const BankAccount& acc) { return acc.getAccountNumber() == accNum; });

    if (account != accounts.end()) {
        std::cout << "Account Balance for " << account->getAccountHolder() << ": $" << account->getBalance() << std::endl;
    } else {
        std::cout << "Account not found." << std::endl;
    }
}

void Bank::searchAccount(const std::string& accNum) const {
    auto account = std::find_if(accounts.begin(), accounts.end(),
        [&accNum](const BankAccount& acc) { return acc.getAccountNumber() == accNum; });

    if (account != accounts.end()) {
        std::cout << "Account Found:" << std::endl;
        account->display();
    } else {
        std::cout << "Account not found." << std::endl;
    }
}

void Bank::changeAccountHolderName(const std::string& accNum, const std::string& newAccHolder) {
    auto account = std::find_if(accounts.begin(), accounts.end(),
        [&accNum](const BankAccount& acc) { return acc.getAccountNumber() == accNum; });

    if (account != accounts.end()) {
        account->changeAccountHolderName(newAccHolder);
    } else {
        std::cout << "Account not found." << std::endl;
    }
}

int main() {
    Bank myBank;

    std::string accNum, accHolder;
    double initialBalance;

    // Adding accounts based on user input
    for (int i = 0; i < 2; ++i) {
        std::cout << "Enter account number for account " << i + 1 << ": ";
        std::cin >> accNum;

        std::cout << "Enter account holder name for account " << i + 1 << ": ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character left in the buffer
        std::getline(std::cin, accHolder);  // Allowing spaces in the account holder name

        std::cout << "Enter initial balance for account " << i + 1 << ": $";
        std::cin >> initialBalance;

        myBank.addAccount(accNum, accHolder, initialBalance);
    }

    // Displaying all accounts
    std::cout << "All Accounts:" << std::endl;
    myBank.displayAllAccounts();

    // Performing transactions based on user input
    myBank.performTransactions();

    // Displaying all accounts after transactions
    std::cout << "\nAll Accounts after Transactions:" << std::endl;
    myBank.displayAllAccounts();

    // Checking balance for an account based on user input
    std::string checkAccNum;
    std::cout << "Enter account number to check balance: ";
    std::cin >> checkAccNum;
    myBank.checkBalance(checkAccNum);

    // Searching for an account based on user input
    std::string searchAccNum;
    std::cout << "Enter account number to search: ";
    std::cin >> searchAccNum;
    myBank.searchAccount(searchAccNum);

    // Changing account holder name based on user input
    std::string changeAccNum, newAccHolder;
    std::cout << "Enter account number to change account holder name: ";
    std::cin >> changeAccNum;

    std::cout << "Enter new account holder name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, newAccHolder);

    myBank.changeAccountHolderName(changeAccNum, newAccHolder);

    // Displaying all accounts after changing account holder name
    std::cout << "\nAll Accounts after Changing Account Holder Name:" << std::endl;
    myBank.displayAllAccounts();

    return 0;
}
