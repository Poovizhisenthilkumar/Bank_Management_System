
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Account class
class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(int accountNumber, string accountHolderName, double balance) {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrew " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

// Customer class
class Customer {
private:
    int customerId;
    
    string address;
    vector<Account> accounts;

public:
    string name;
    Customer(int customerId, string name, string address) {
        this->customerId = customerId;
        this->name = name;
        this->address = address;
    }

    void addAccount(Account account) {
        accounts.push_back(account);
    }

    void displayAccounts() {
        cout << "Accounts for customer " << name << ":" << endl;
        for (int i = 0; i < accounts.size(); i++) {
            cout << "Account " << i + 1 << ": " << accounts[i].getBalance() << endl;
        }
    }
};

// Bank class
class Bank {
private:
    string bankName;
    vector<Customer> customers;

public:
    Bank(string bankName) {
        this->bankName = bankName;
    }

    void addCustomer(Customer customer) {
        customers.push_back(customer);
    }

    void displayCustomers() {
        cout << "Customers for bank " << bankName << ":" << endl;
        for (int i = 0; i < customers.size(); i++) {
            cout << "Customer " << i + 1 << ": " << customers[i].name << endl;
        }
    }
};

int main() {
    // Create bank
    Bank bank("Example Bank");

    // Create customers
    Customer customer1(1, "John Doe", "123 Main St");
    Customer customer2(2, "Jane Doe", "456 Elm St");

    // Add customers to bank
    bank.addCustomer(customer1);
    bank.addCustomer(customer2);

    // Create accounts for customers
    Account account1(1, "John Doe", 1000.0);
    Account account2(2, "Jane Doe", 500.0);

    customer1.addAccount(account1);
    customer2.addAccount(account2);

    // Display bank customers and accounts
    bank.displayCustomers();
    customer1.displayAccounts();
    customer2.displayAccounts();

    // Perform transactions
    account1.deposit(500.0);
    account2.withdraw(200.0);

    return 0;
}


