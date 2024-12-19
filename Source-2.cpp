#include "GroceryItems.h"


 // Constructor for the GroceryTracker class
 // It initializes the tracker by loading data from the input file and creating a backup file
 
GroceryTracker::GroceryTracker(const string& inputFileName, const string& backupFileName) {
    loadDataFromFile(inputFileName);
    createBackupFile(backupFileName);
}


 // Loads data from the input file and populates the item frequency vector
 // Each unique item is added to the vector, and its frequency is updated if it already exists

void GroceryTracker::loadDataFromFile(const string& fileName) {
    ifstream inputFile(fileName);
    string item;

    // Check that file has opened
    if (!inputFile) {
        cerr << "Error: Unable to open file " << fileName << endl;
        return;
    }

    while (inputFile >> item) {
        // Find the index of the item in the vector
        int index = findItemIndex(item);
        if (index != -1) {
            // If item is found, increment its frequency
            itemFrequency[index].second++;
        }
        else {
            // If item is not found, add it to the vector with a frequency of 1
            itemFrequency.push_back({ item, 1 });
        }
    }

    inputFile.close();
}


 // Creates a backup file containing each item's name and frequency
 // The file is used as a backup to store the inventory data

void GroceryTracker::createBackupFile(const string& backupFileName) {
    ofstream backupFile(backupFileName);

    if (!backupFile) {
        cerr << "Error: Unable to create backup file " << backupFileName << endl;
        return;
    }

    // Write each item and its frequency to the backup file
    for (const auto& pair : itemFrequency) {
        backupFile << pair.first << " " << pair.second << endl;
    }

    backupFile.close();
}


 // Finds the index of an item in the itemFrequency vector

int GroceryTracker::findItemIndex(const string& item) const {
    for (int i = 0; i < itemFrequency.size(); ++i) {
        if (itemFrequency[i].first == item) {
            return i; // Return the index where the item was found
        }
    }
    return -1; // Item not found
}


 // Prompts the user to enter an item name and displays its frequency
 
void GroceryTracker::getItemFrequency() const {
    string item;
    cout << "Enter the item name to look for: ";
    cin >> item;

    int index = findItemIndex(item);
    if (index != -1) {
        // Display the frequency of the item if found
        cout << "The item '" << item << "' appears " << itemFrequency[index].second << " times." << endl;
    }
    else {
        // Inform the user that the item was not found
        cout << "The item '" << item << "' was not found in the records." << endl;
    }
}


 // Prints the list of all items and their corresponding frequencies
 // Each item and its frequency are displayed on a new line
 
void GroceryTracker::printItemFrequencyList() const {
    cout << "\nItem Frequency List:\n";
    cout << "-------------------\n";
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}


 // Prints a histogram of item frequencies
 // Each item is displayed along with a series of asterisks representing its frequency
 
void GroceryTracker::printHistogram() const {
    cout << "\nItem Histogram:\n";
    cout << "----------------\n";
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}
