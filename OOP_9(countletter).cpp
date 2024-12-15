#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to count letters, words, and lines in a file
void countFileContent(const string& fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }
 
    int letterCount = 0, wordCount = 0, lineCount = 0;
    string line;

    while (getline(file, line)) {
        lineCount++;
        bool inWord = false;

        for (char ch : line) {
            if (isalpha(ch)) {
                letterCount++;
            }

            if (isspace(ch)) {
                if (inWord) {
                    wordCount++;
                    inWord = false;
                }
            } else {
                inWord = true;
            }
        }

        if (inWord) {
            wordCount++; // Count the last word in the line
        }
    }

    file.close();

    cout << "Letters: " << letterCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Lines: " << lineCount << endl;
}

// Function to calculate the file size
void calculateFileSize(const string& fileName) {
    ifstream file(fileName, ios::binary | ios::ate);

    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    streamsize size = file.tellg();
    file.close();

    cout << "File size: " << size << " bytes" << endl;
}

int main() {
    string fileName;

    cout << "Enter the file name: ";
    cin >> fileName;

    cout << "\nAnalyzing the file...\n";
    countFileContent(fileName);
    calculateFileSize(fileName);

    return 0;
}
