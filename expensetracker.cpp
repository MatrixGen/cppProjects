#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>

// Structure to hold expense details
struct Expense {
    std::string category;
    double amount;
    std::string date; // Format: YYYY-MM-DD
};

// Function to register a new user
bool registerUser(const std::string& filename) {
    std::string username, password;
    
    std::cout << "Create a new account\n";
    std::cout << "Enter a username: ";
    std::cin >> username;
    std::cout << "Enter a password: ";
    std::cin >> password;

    // Open the file to append user data
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << username << "," << password << "\n";
        file.close();
        std::cout << "Registration successful!\n";
        return true;
    } else {
        std::cerr << "Error: Unable to open file for writing.\n";
        return false;
    }
}

// Function to login a user
bool loginUser(const std::string& filename) {
    std::string username, password;
    std::string stored_username, stored_password;
    
    std::cout << "Login\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::ifstream file(filename);
    if (file.is_open()) {
        while (std::getline(file, stored_username, ',') && std::getline(file, stored_password)) {
            if (stored_username == username && stored_password == password) {
                file.close();
                std::cout << "Login successful!\n";
                return true;
            }
        }
        file.close();
        std::cout << "Invalid username or password. Please try again.\n";
        return false;
    } else {
        std::cerr << "Error: Unable to open file for reading.\n";
        return false;
    }
}

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
        std::cout << "There is no expenses found in this category.\n";
    }
}

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
