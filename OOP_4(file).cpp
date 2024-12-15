#include <iostream>
#include <fstream>

using namespace std;

void writeToLogFile(const string& data) {
    ofstream logFile("output.txt", ios::app);

    if (logFile.is_open()) {
        logFile << data << endl;
        logFile.close();
    } else {
        cout << "Unable to open output file." << endl;
    }
}

void displayFileContents() {
    ifstream logFile("output.txt");

    if (logFile.is_open()) {
        string line;

        cout << "\nContents of the file:\n";
        while (getline(logFile, line)) {
            cout << line << endl;
        }

        logFile.close();
    } else {
        cout << "Unable to open input file." << endl;
    }
}

void deleteLineFromFile(int lineToDelete) {
    ifstream inputFile("output.txt");
    ofstream tempFile("temp.txt");

    if (!inputFile || !tempFile) {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
    int lineNum = 0;

    while (getline(inputFile, line)) {
        lineNum++;
        if (lineNum != lineToDelete) {
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    remove("output.txt");
    rename("temp.txt", "output.txt");
}

int main() {
    char choice;

    while (true) {
        cout << "Choose an option:\n";
        cout << "1. Write to file\n";
        cout << "2. Display file contents\n";
        cout << "3. Delete a line from file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '1') {
            cin.ignore();
            cout << "Enter data to write to the file: ";
            string data;
            getline(cin, data);
            writeToLogFile(data);
        } else if (choice == '2') {
            displayFileContents();
        } else if (choice == '3') {
            int lineToDelete;
            cout << "Enter the line number to delete: ";
            cin >> lineToDelete;
            deleteLineFromFile(lineToDelete);
        } else if (choice == '4') {
            cout << "Exiting the program.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
