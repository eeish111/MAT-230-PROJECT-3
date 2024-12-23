#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

class GroceryTracker {
public:
    // Reads data from the input file and builds the frequency map
    void loadInputFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cerr << "Error: Unable to open file: " << filename << endl;
            return;
        }
        string product;
        while (inputFile >> product) {
            itemFrequency[product]++;
        }
        inputFile.close();
    }

    // Retrieves the count of a specific item
    int getFrequency(const string& product) const {
        auto it = itemFrequency.find(product);
        return it != itemFrequency.end() ? it->second : 0;
    }

    // Displays all items with their frequencies
    void displayFrequencies() const {
        for (const auto& entry : itemFrequency) {
            cout << entry.first << ": " << entry.second << endl;
        }
    }

    // Displays a histogram of item frequencies
    void displayHistogram() const {
        for (const auto& entry : itemFrequency) {
            cout << entry.first << " ";
            cout << string(entry.second, '*') << endl;
        }
    }

    // Saves the frequency data to a backup file
    void saveBackupFile(const string& filename) const {
        ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            cerr << "Error: Unable to open file: " << filename << endl;
            return;
        }
        for (const auto& entry : itemFrequency) {
            outputFile << entry.first << ": " << entry.second << endl;
