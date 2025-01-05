#ifndef EXPENSE_TRACKER_H
#define EXPENSE_TRACKER_H

#include <vector>
#include <string>

struct Expense {
    std::string category;
    double amount;
    std::string date; // Format: YYYY-MM-DD
};

void addExpense(std::vector<Expense>& expenses);
void viewExpenses(const std::vector<Expense>& expenses);
double calculateTotal(const std::vector<Expense>& expenses);
void saveToFile(const std::vector<Expense>& expenses, const std::string& filename);
void loadFromFile(std::vector<Expense>& expenses, const std::string& filename);
void searchExpensesByCategory(const std::vector<Expense>& expenses, const std::string& category);

#endif // EXPENSE_TRACKER_H
