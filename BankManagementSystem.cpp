#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string name;
    double balance;

public:
    // Constructor
    BankAccount()
    {
        accountNumber = 0;
        name = "";
        balance = 0.0;
    }

    // Create new account
    void createAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Deposit: ";
        cin >> balance;

        if (balance < 0)
        {
            balance = 0;
            cout << "Invalid amount. Balance set to 0.\n";
        }

        cout << "\nAccount created successfully!\n";
    }

    // Display account details
    void displayAccount()
    {
        cout << "\n--------------------------------\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << name << endl;
        cout << "Balance        : Rs. "
             << fixed << setprecision(2) << balance << endl;
        cout << "--------------------------------\n";
    }

    // Deposit money
    void deposit()
    {
        double amount;

        cout << "\nEnter amount to deposit: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid deposit amount.\n";
            return;
        }

        balance += amount;

        cout << "Deposit successful!\n";
        cout << "Current Balance: Rs. "
             << fixed << setprecision(2) << balance << endl;
    }

    // Withdraw money
    void withdraw()
    {
        double amount;

        cout << "\nEnter amount to withdraw: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount.\n";
            return;
        }

        if (amount > balance)
        {
            cout << "Insufficient balance!\n";
            return;
        }

        balance -= amount;

        cout << "Withdrawal successful!\n";
        cout << "Current Balance: Rs. "
             << fixed << setprecision(2) << balance << endl;
    }

    // Check balance
    void checkBalance()
    {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Customer Name : " << name << endl;
        cout << "Balance       : Rs. "
             << fixed << setprecision(2) << balance << endl;
    }

    // Get account number
    int getAccountNumber()
    {
        return accountNumber;
    }

    // Save account to file
    void saveToFile()
    {
        ofstream file("bank_accounts.txt", ios::app);

        if (!file)
        {
            cout << "Error opening file!\n";
            return;
        }

        file << accountNumber << endl;
        file << name << endl;
        file << balance << endl;

        file.close();
    }

    // Save updated account
    void saveUpdatedAccount(ofstream &file)
    {
        file << accountNumber << endl;
        file << name << endl;
        file << balance << endl;
    }

    // Load account from file
    bool loadFromFile(ifstream &file)
    {
        if (!(file >> accountNumber))
        {
            return false;
        }

        file.ignore();

        getline(file, name);

        file >> balance;

        return true;
    }
};

// Find account by account number
bool findAccount(int number, BankAccount &account)
{
    ifstream file("bank_accounts.txt");

    if (!file)
    {
        return false;
    }

    BankAccount temp;

    while (temp.loadFromFile(file))
    {
        if (temp.getAccountNumber() == number)
        {
            account = temp;
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Update account in file
bool updateAccount(BankAccount updatedAccount)
{
    ifstream inputFile("bank_accounts.txt");
    ofstream tempFile("temp.txt");

    if (!inputFile || !tempFile)
    {
        return false;
    }

    BankAccount account;

    while (account.loadFromFile(inputFile))
    {
        if (account.getAccountNumber() ==
            updatedAccount.getAccountNumber())
        {
            updatedAccount.saveUpdatedAccount(tempFile);
        }
        else
        {
            account.saveUpdatedAccount(tempFile);
        }
    }

    inputFile.close();
    tempFile.close();

    remove("bank_accounts.txt");
    rename("temp.txt", "bank_accounts.txt");

    return true;
}

int main()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "       BANK MANAGEMENT SYSTEM       \n";
        cout << "====================================\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account\n";
        cout << "6. Exit\n";
        cout << "====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            BankAccount account;

            account.createAccount();

            // Check duplicate account number
            BankAccount existing;

            if (findAccount(account.getAccountNumber(), existing))
            {
                cout << "Account number already exists!\n";
            }
            else
            {
                account.saveToFile();
                cout << "Account saved successfully.\n";
            }

            break;
        }

        case 2:
        {
            int number;

            cout << "\nEnter Account Number: ";
            cin >> number;

            BankAccount account;

            if (findAccount(number, account))
            {
                account.deposit();
                updateAccount(account);
            }
            else
            {
                cout << "Account not found!\n";
            }

            break;
        }

        case 3:
        {
            int number;

            cout << "\nEnter Account Number: ";
            cin >> number;

            BankAccount account;

            if (findAccount(number, account))
            {
                account.withdraw();
                updateAccount(account);
            }
            else
            {
                cout << "Account not found!\n";
            }

            break;
        }

        case 4:
        {
            int number;

            cout << "\nEnter Account Number: ";
            cin >> number;

            BankAccount account;

            if (findAccount(number, account))
            {
                account.checkBalance();
            }
            else
            {
                cout << "Account not found!\n";
            }

            break;
        }

        case 5:
        {
            int number;

            cout << "\nEnter Account Number: ";
            cin >> number;

            BankAccount account;

            if (findAccount(number, account))
            {
                account.displayAccount();
            }
            else
            {
                cout << "Account not found!\n";
            }

            break;
        }

        case 6:
            cout << "\nThank you for using Bank Management System!\n";
            break;

        default:
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}