//
// Created by Chuck Mills on 12/13/24.
//

#include "GroceryItems.h"

void GroceryTracker::loadDataFromFile(const string& inventoryFileName) {
    ifstream fileStream (inventoryFileName);
    string itemName;

    if (!fileStream.is_open()) {
        cerr << "Could not open file " << inventoryFileName << " for reading." << endl;
        return;
    }

    while (fileStream >> itemName) {
        //find index of item in vector
        int index = findItemIndex(itemName);
        if (index != -1) {
            itemFrequency[index].second++;
        }
        else {
            itemFrequency.push_back({ itemName, 1});
        }
    }

    fileStream.close();
}

