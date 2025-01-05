#include <iostream>
#include <vector>
#include <string>
#include "expense_tracker.h"
#include "user_auth.h"

int main() {
    const std::string user_file = "users.txt";  // File to store user credentials
    const std::string expense_file = "expenses.txt";  // File to store expenses
    std::vector<Expense> expenses;
    int choice;
    
    int option;
    do {
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;
        
        if (option == 1) {
            if (registerUser(user_file)) {
                break;  // Proceed to login after registration
            }
        } else if (option == 2) {
            if (loginUser(user_file)) {
                break;  // Proceed to expense tracker if login is successful
            }
        } else if (option == 3) {
            std::cout << "Exiting...\n";
            return 0;
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (true);

    do {
        std::cout << "\nExpense Tracker\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. View Expenses\n";
        std::cout << "3. Calculate Total Expenses\n";
        std::cout << "4. Save Expenses to File\n";
        std::cout << "5. Load Expenses from File\n";
        std::cout << "6. Search Expenses by Category\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addExpense(expenses);
                break;
            case 2:
                viewExpenses(expenses);
                break;
            case 3:
                std::cout << "Total Expenses: " << calculateTotal(expenses) << "\n";
                break;
            case 4: {
                saveToFile(expenses, expense_file);
                break;
            }
            case 5: {
                loadFromFile(expenses, expense_file);
                break;
            }
            case 6: {
                std::string category;
                std::cout << "Enter category to search: ";
                std::cin >> category;
                searchExpensesByCategory(expenses, category);
                break;
            }
            case 7:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
