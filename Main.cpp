#include <iostream>
#include "GroceryItems.h"

using namespace std;

// Display the menu options
void displayMenu() {
    cout << "\nCorner Grocer Item Tracking Program\n";
    cout << "------------------------------------\n";
    cout << "1. Look up the frequency of a specific item\n";
    cout << "2. Print the frequency of all items\n";
    cout << "3. Print a histogram of item frequencies\n";
    cout << "4. Exit the program\n";
}

// Get user input
int main() {
    const string inventoryFileName = "inventory.txt";
    const string backupFileName = "frequency.dat";

    GroceryTracker tracker(inventoryFileName, backupFileName);

    int choice;

    do {
        displayMenu();
        cout << "\nEnter your choice (1-4): ";
        while (!(cin >> choice) || (choice < 1 || choice > 4)) {
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
            tracker.getItemFrequency();
            break;
        case 2:
            tracker.printItemFrequencyList();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option. Enter a number between 1 and 3, or 4 to exit." << endl;
        }
    } while (choice != 4);

    return 0;
}
