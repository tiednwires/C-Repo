#ifndef GROCERYITEMS_H
#define GROCERYITEMS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Class to manage the item tracking system
class GroceryTracker {
private:
    vector<pair<string, int>> itemFrequency; // Vector to hold item names and their frequencies

    // Private method to load data from file into the vector
    void loadDataFromFile(const string& inventoryFileName);

    // Private method to create a backup file
    void createBackupFile(const string& backupFileName);

    // Helper function to find an item in the vector
    int findItemIndex(const string& itemName) const;

public:
    // Constructor to load data and create backup file
    GroceryTracker(const string& inventoryFileName, const string& backupFileName);

    // Method to get the frequency of a specific item
    void getItemFrequency() const;

    // Method to print the frequency of all items
    void printItemFrequencyList() const;

    // Method to print the histogram of item frequencies
    void printHistogram() const;
};

#endif // GROCERYITEMS_H
