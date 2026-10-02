# Bank Management System

## Project Description

The Bank Management System is a C++ console-based application designed to simulate basic banking operations. The project demonstrates Object-Oriented Programming (OOP) concepts and file handling for storing customer account information.

## Features

* Create a bank account
* Deposit money
* Withdraw money
* Check account balance
* Display account details
* Store customer records using file handling
* Prevent withdrawal when the balance is insufficient
* Prevent duplicate account numbers

## Technologies Used

* C++
* Object-Oriented Programming
* File Handling
* C++ Standard Library

## OOP Concepts Used

* Classes and Objects
* Encapsulation
* Constructors
* Member Functions
* Abstraction

## File Handling

The application uses `ifstream` and `ofstream` to read and write customer account records.

Account information is stored locally in a text file so that the data can persist after the application is closed.

## How to Run

### Compile

```bash
g++ BankManagementSystem.cpp -o BankManagementSystem
```

### Run

```bash
./BankManagementSystem
```

On Windows PowerShell:

```powershell
.\BankManagementSystem.exe
```

## Main Operations

1. Create Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. Display Account
6. Exit

## Expected Outcome

The application provides a functional simulation of basic banking operations while demonstrating C++ Object-Oriented Programming and persistent file storage.

## Note

This project is intended for educational purposes and is not designed for use as a real banking system.
