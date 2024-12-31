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
