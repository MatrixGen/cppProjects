#include "expense_tracker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

// Function to add an expense
void addExpense(std::vector<Expense>& expenses) {
    std::string category, date;
    double amount;
    std::cout << "Enter category: ";
    std::cin >> category;
    std::cout << "Enter amount: ";
    std::cin >> amount;
    std::cout << "Enter date (YYYY-MM-DD): ";
    std::cin >> date;
    expenses.push_back({category, amount, date});
    std::cout << "Expense added successfully!\n";
}

// Function to view expenses
void viewExpenses(const std::vector<Expense>& expenses) {
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

// Function to calculate total expenses
double calculateTotal(const std::vector<Expense>& expenses) {
    double total = 0;
    for (const auto& expense : expenses) {
        total += expense.amount;
    }
    return total;
}

// Function to save expenses to a file
void saveToFile(const std::vector<Expense>& expenses, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& expense : expenses) {
            file << expense.date << "," << expense.category << "," << expense.amount << "\n";
        }
        file.close();
        std::cout << "Expenses saved to " << filename << "\n";
    } else {
        std::cerr << "Error: Unable to open file for writing.\n";
    }
}

// Function to load expenses from a file
void loadFromFile(std::vector<Expense>& expenses, const std::string& filename) {
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

// Function to search expenses by category
void searchExpensesByCategory(const std::vector<Expense>& expenses, const std::string& category) {
    std::cout << "\nExpenses in category: " << category << "\n";
    std::cout << std::left << std::setw(15) << "Date"
              << std::setw(20) << "Category"
              << std::setw(10) << "Amount" << "\n";
    std::cout << std::string(45, '-') << "\n";
    bool found = false;
    for (const auto& expense : expenses) {
        if (expense.category == category) {
            std::cout << std::setw(15) << expense.date
                      << std::setw(20) << expense.category
                      << std::setw(10) << expense.amount << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "There are no expenses found in this category.\n";
    }
}
