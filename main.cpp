#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


// View function for Fruits
void viewFruits() {
    ifstream file("Fruits.csv");
    /*if (!file.is_open()) {
        cout << "Error opening fruits.csv!" << endl;
        return;
    }*/

    string line;
    bool isHeader = true;

    cout << "\n=== Fruits Section ===\n";
    while (getline(file, line)) {
        if (isHeader) {
            isHeader = false;
            continue; // skip header
        }

        stringstream ss(line);
        string name_en, name_ru, name_uz, code, price;

        getline(ss, name_en, ',');
        getline(ss, name_ru, ',');
        getline(ss, name_uz, ',');
        getline(ss, code, ',');
        getline(ss, price, ',');

        cout << "Name (EN): " << name_en
             << ", Name (RU): " << name_ru
             << ", Name (UZ): " << name_uz
             << ", Code: " << code
             << ", Price: " << price << endl;
    }
    file.close();
}

// View function for Meat (currently empty)
void viewMeat() {
    cout << "\n=== Meat Section ===\n";
    cout << "No meat items available yet.\n";
}

// View function for Bakery (currently empty)
void viewBakery() {
    cout << "\n=== Bakery Section ===\n";
    cout << "No bakery items available yet.\n";
}

// Main Menu
void customerMenu() {
    int choice;

    do {
        cout << "\n===== Customer Menu =====\n";
        cout << "1. View Fruits\n";
        cout << "2. View Meat\n";
        cout << "3. View Bakery\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewFruits();
                break;
            case 2:
                viewMeat();
                break;
            case 3:
                viewBakery();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

int main() {
    customerMenu();
    return 0;
}
