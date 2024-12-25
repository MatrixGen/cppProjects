#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
void displayMenu();
void createItem(vector<string>& items);
void readItems(const vector<string>& items);
void updateItem(vector<string>& items);
void deleteItem(vector<string>& items);

int main() {
    vector<string> items;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createItem(items);
                break;
            case 2:
                readItems(items);
                break;
            case 3:
                updateItem(items);
                break;
            case 4:
                deleteItem(items);
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void displayMenu() {
    cout << "\n--- CRUD Application ---\n";
    cout << "1. Create Item\n";
    cout << "2. Read Items\n";
    cout << "3. Update Item\n";
    cout << "4. Delete Item\n";
    cout << "5. Exit\n";
}

void createItem(vector<string>& items) {
    string item;
    cout << "Enter the name of the item to add: ";
    cin.ignore(); // Clear input buffer
    getline(cin, item);
    items.push_back(item);
    cout << "Item added successfully!" << endl;
}

void readItems(const vector<string>& items) {
    if (items.empty()) {
        cout << "No items to display." << endl;
    } else {
        cout << "List of items:\n";
        int index = 1;
        for (const auto& item : items) {
            cout << index++ << ". " << item << endl;
        }
    }
}

void updateItem(vector<string>& items) {
    if (items.empty()) {
        cout << "No items available to update." << endl;
        return;
    }

    int index;
    cout << "Enter the index of the item to update (1 to " << items.size() << "): ";
    cin >> index;

    if (index < 1 || index > static_cast<int>(items.size())) {
        cout << "Invalid index. Please try again." << endl;
        return;
    }

    string newItem;
    cout << "Enter the new name for the item: ";
    cin.ignore(); // Clear input buffer
    getline(cin, newItem);

    items[index - 1] = newItem;
    cout << "Item updated successfully!" << endl;
}

void deleteItem(vector<string>& items) {
    if (items.empty()) {
        cout << "No items available to delete." << endl;
        return;
    }

    int index;
    cout << "Enter the index of the item to delete (1 to " << items.size() << "): ";
    cin >> index;

    if (index < 1 || index > static_cast<int>(items.size())) {
        cout << "Invalid index. Please try again." << endl;
        return;
    }

    items.erase(items.begin() + index - 1);
    cout << "Item deleted successfully!" << endl;
}
