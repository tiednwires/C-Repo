//
// Created by Chuck Mills on 12/13/24.
//

#ifndef GROCERYITEMS_H
#define GROCERYITEMS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Grocerytracker {
private:
    vector<pair<string, int>> itemFrequency;

    void loadDataFromFile(const string& inventoryFileName);

    void createBackupFile(const string& backupFileName);

    void findItemIndex(const string& itemName)const;

public:
    //constructor to load data and create backup file
    GroceryTracker(const string& inventoryFileName, const string& backupFileName);

    //method to get frequency of item
    void getItemFrequency()const;

    //method to print frequency of an item
    void printItemFrequency()const;

    //method to print frequency of all items
    void printAllItems()const;

    //method to print histogram
    void printHistogram()const;
};

#endif //GROCERYITEMS_H
