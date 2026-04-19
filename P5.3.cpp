#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Convert string to lowercase
string toLowerStr(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }
    return s;
}

// Add item
void addItem() {
    ofstream file("inventory.txt", ios::app);

    string name;
    int qty;
    float price;

    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter quantity: ";
    cin >> qty;
    cout << "Enter price: ";
    cin >> price;

    file << name << " " << qty << " " << price << endl;

    file.close();
    cout << "Item added successfully!\n";
}

// View all items
void viewItems() {
    ifstream file("inventory.txt");

    string name;
    int qty;
    float price;

    cout << "\nInventory List:\n";

    while (file >> name >> qty >> price) {
        cout << "Name: " << name
             << ", Quantity: " << qty
             << ", Price: " << price << endl;
    }

    file.close();
}

// Search item
void searchItem() {
    ifstream file("inventory.txt");

    string searchName;
    cout << "Enter item name to search: ";
    cin >> searchName;

    string name;
    int qty;
    float price;
    bool found = false;

    searchName = toLowerStr(searchName);

    while (file >> name >> qty >> price) {
        if (toLowerStr(name) == searchName) {
            cout << "\nItem Found:\n";
            cout << "Name: " << name
                 << ", Quantity: " << qty
                 << ", Price: " << price << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Item not found!\n";
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n\n1. Add Item";
        cout << "\n2. View All Items";
        cout << "\n3. Search Item";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewItems(); break;
            case 3: searchItem(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}