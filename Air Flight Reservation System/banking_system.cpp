#include <iostream>
#include <string>
#include <iomanip> // For formatting output

class BankAccount {
private:
    std::string accountHolderName;
    double balance;

public:
    // Constructor to initialize account holder's name and balance
    BankAccount(const std::string& name, double initialBalance)
        : accountHolderName(name), balance(initialBalance) {}

    // Function to display the balance
    void showBalance() const {
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "$" << amount << " has been deposited." << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "$" << amount << " has been withdrawn." << std::endl;
        } else {
            std::cout << "Invalid or insufficient funds for withdrawal." << std::endl;
        }
    }
};

// Function to display the main menu
void displayMenu() {
    std::cout << "\n--- Main Menu ---" << std::endl;
    std::cout << "1. Show Balance" << std::endl;
    std::cout << "2. Deposit Money" << std::endl;
    std::cout << "3. Withdraw Money" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Please select an option (1-4): ";
}

int main() {
    // Create a sample bank account
    BankAccount account("John Doe", 0);

    int choice;
    do {
        displayMenu(); // Show the menu
        std::cin >> choice;

        switch (choice) {
        case 1: // Show balance
            account.showBalance();
            break;
        case 2: { // Deposit money
            double depositAmount;
            std::cout << "Enter amount to deposit: $";
            std::cin >> depositAmount;
            account.deposit(depositAmount);
            break;
        }
        case 3: { // Withdraw money
            double withdrawAmount;
            std::cout << "Enter amount to withdraw: $";
            std::cin >> withdrawAmount;
            account.withdraw(withdrawAmount);
            break;
        }
        case 4: // Exit
            std::cout << "Thank you for using our banking system. Goodbye!" << std::endl;
            break;
        default: // Invalid option
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    } while (choice != 4); // Continue until the user chooses to exit

    return 0;
}
