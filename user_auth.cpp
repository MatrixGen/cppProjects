#include "user_auth.h"
#include <iostream>
#include <fstream>
#include <string>

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
