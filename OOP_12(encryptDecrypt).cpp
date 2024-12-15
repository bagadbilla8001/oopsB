#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to encrypt or decrypt a file
void encryptDecrypt(const string& inputFile, const string& outputFile, char key) {
    ifstream input(inputFile, ios::binary);
    ofstream output(outputFile, ios::binary);

    if (!input || !output) {
        cout << "Error opening file." << endl;
        return;
    }

    char ch;
    while (input.get(ch)) {
        output.put(ch ^ key); // XOR operation for encryption/decryption
    }

    cout << "Operation completed successfully." << endl;
}

int main() {
    int choice = 0;
    string inputFile, outputFile;
    char key = 'X'; // Simple encryption key

    while (choice != 3) {
        cout << "\nFile Encryption & Decryption Menu:\n";
        cout << "1. Encrypt a File\n";
        cout << "2. Decrypt a File\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter input file name: ";
            cin >> inputFile;
            cout << "Enter output file name: ";
            cin >> outputFile;
            encryptDecrypt(inputFile, outputFile, key);
        } else if (choice == 2) {
            cout << "Enter encrypted file name: ";
            cin >> inputFile;
            cout << "Enter output file name: ";
            cin >> outputFile;
            encryptDecrypt(inputFile, outputFile, key);
        } else if (choice == 3) {
            cout << "Exiting program." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
