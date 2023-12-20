# Bank Management system in C++

# Overview:
This C++ program implements a simple yet comprehensive bank management system. The system is designed to manage bank accounts, perform transactions, and provide essential banking functionalities.

# Key Features:
# Account Management:

Users can create multiple bank accounts by providing account numbers, account holder names, and initial balances.
The system maintains a collection of bank accounts, each represented by an instance of the BankAccount class.
Transaction Handling:

Users can perform transactions such as fund transfers between accounts.
The system ensures that transactions are executed securely and provides feedback on success or failure.
Account Information:

Users can check the balance of a specific account and search for accounts based on account numbers.
The system displays detailed information for each account, including the account number, account holder name, and balance.
# Account Modification:

Users can change the account holder's name for a specific account.
The system prompts users for the necessary information and updates the account details accordingly.
# Code Structure:
# Object-Oriented Design:

The code is structured using object-oriented principles, with classes for Bank and BankAccount.
Each bank account is an instance of the BankAccount class, and the Bank class manages the collection of accounts.
# Readability and Modularity:

The code is well-organized into header and implementation files (header.h and bank.cc).
Functions and operations are modularized for clarity, making it easy to understand and maintain.
Use Cases:
# Account Creation:

Users can input account details, including account number, account holder name, and initial balance.
The system creates new accounts based on user input.
# Transaction Execution:

Users can transfer funds between existing accounts, and the system ensures the availability of sufficient funds.
# Information Retrieval:

Users can check the balance of a specific account by providing the account number.
The system displays detailed information about each account, aiding users in managing their finances.
# Account Modification:

Users can change the account holder's name, offering flexibility in personalizing account details.
Use of C++ Features:
The code demonstrates the use of C++ features such as classes, vectors, and algorithms (std::find_if) for efficient account management.
Input validation is incorporated to ensure the robustness of the program.
