/*Introduction to the Expense Tracker Program

This document provides an overview of the C++ Expense Tracker program. The program is designed to help users manage and track their financial expenses effectively. It offers functionalities such as adding, viewing, and calculating total expenses, as well as saving and loading expense data from a file.

Features

Add Expense:

Allows the user to input a category, amount, and date for an expense.

Records the expense in the system for future reference.

View Expenses:

Displays all recorded expenses in a tabular format.

Columns include the date, category, and amount.

Calculate Total Expenses:

Computes the sum of all recorded expenses.

Provides an overview of total spending.

Save to File:

Saves all recorded expenses to a file in CSV format.

Ensures data persistence between program executions.

Load from File:

Reads expenses from a previously saved file.

Enables users to restore data into the program.

Program Flow

Main Menu:

The user is presented with a menu to select an option (e.g., add expense, view expenses, etc.).

User Input Validation:

Ensures the user enters valid data (e.g., correct date format, numeric values for amounts).

File Handling:

Implements file I/O operations to save and load data.

Code Components

Expense** Structure:**

Holds details of a single expense (category, amount, and date).

ExpenseTracker** Class:**

Manages a collection of Expense objects.

Contains methods to add, view, calculate totals, save, and load expenses.

Main Function:

Serves as the entry point of the program.

Provides a user interface to interact with the ExpenseTracker class.

How to Use

Run the program.

Use the menu to add expenses or view existing ones.

Save data to a file when exiting to ensure persistence.

Reload saved data when restarting the program to continue where you left off.

File Format

Saved files are in CSV format with each line representing an expense:
YYYY-MM-DD,Category,Amount
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

struct Expense {
    std::string category;
    double amount;
    std::string date; // Format: YYYY-MM-DD
};
class ExpenseTracker {
private:
    std::vector<Expense> expenses;

public:
    void addExpense(const std::string& category, double amount, const std::string& date) {
        expenses.push_back({category, amount, date});
        std::cout << "Expense added successfully!\n";
    }
    void viewExpenses() const {
        std::cout << "\nExpenses:\n";
        std::cout << std::left << std::setw(15) << "Date"
                  << std::setw(20) << "Category"
                  << std::setw(10) << "Amount" << "\n";
        std::cout << std::string(45, '-') << "\n";
        for (const auto& expense : expenses) {
            std::cout << std::setw(15) << expense.date
                      << std::setw(20) << expense.category
                      << std::setw(10) << expense.amount << "\n";
        }
    }
    double calculateTotal() const {
        double total = 0;
        for (const auto& expense : expenses) {
            total += expense.amount;
        }
        return total;
    }
      saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if void(file.is_open()) {
            for (const auto& expense : expenses) {
                file << expense.date << "," << expense.category << "," << expense.amount << "\n";
            }
            file.close();
            std::cout << "Expenses saved to " << filename << "\n";
        } else {
            std::cerr << "Error: Unable to open file for writing.\n";
        }
    }
 void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            expenses.clear();
            std::string line;
            while (std::getline(file, line)) {
                size_t pos1 = line.find(',');
                size_t pos2 = line.rfind(',');
                if (pos1 != std::string::npos && pos2 != std::string::npos && pos1 != pos2) {
                    std::string date = line.substr(0, pos1);
                    std::string category = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    double amount = std::stod(line.substr(pos2 + 1));
                    expenses.push_back({category, amount, date});
                }
            }
            file.close();
            std::cout << "Expenses loaded from " << filename << "\n";
        } else {
            std::cerr << "Error: Unable to open file for reading.\n";
        }
    }
};
