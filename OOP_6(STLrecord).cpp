#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct PersonalRecord {
    string name;
    string dob;
    string telephoneNumber;
};

bool compareNames(const PersonalRecord& a, const PersonalRecord& b) {
    return a.name < b.name;
}

bool compareDob(const PersonalRecord& a, const PersonalRecord& b) {
    return a.dob < b.dob;
}

bool compareTelephone(const PersonalRecord& a, const PersonalRecord& b) {
    return a.telephoneNumber < b.telephoneNumber;
}

void sortByName(vector<PersonalRecord>& records) {
    sort(records.begin(), records.end(), compareNames);
}

void sortByDob(vector<PersonalRecord>& records) {
    sort(records.begin(), records.end(), compareDob);
}

void sortByTelephone(vector<PersonalRecord>& records) {
    sort(records.begin(), records.end(), compareTelephone);
}

void displayRecords(const vector<PersonalRecord>& records) {
    for (const auto& record : records) {
        cout << "Name: " << record.name << ", DOB: " << record.dob << ", Telephone: " << record.telephoneNumber << endl;
    }
}

void findByName(const vector<PersonalRecord>& records, const string& name) {
    auto it = find_if(records.begin(), records.end(), [name](const PersonalRecord& record) {
        return record.name == name;
    });
    if (it != records.end()) {
        cout << "\nRecord found: " << it->name << ", DOB: " << it->dob << ", Telephone: " << it->telephoneNumber << endl;
    } else {
        cout << "\nRecord with name '" << name << "' not found." << endl;
    }
}

void findByDob(const vector<PersonalRecord>& records, const string& dob) {
    auto it = find_if(records.begin(), records.end(), [dob](const PersonalRecord& record) {
        return record.dob == dob;
    });
    if (it != records.end()) {
        cout << "\nRecord found: " << it->name << ", DOB: " << it->dob << ", Telephone: " << it->telephoneNumber << endl;
    } else {
        cout << "\nRecord with DOB '" << dob << "' not found." << endl;
    }
}

void findByTelephone(const vector<PersonalRecord>& records, const string& telephone) {
    auto it = find_if(records.begin(), records.end(), [telephone](const PersonalRecord& record) {
        return record.telephoneNumber == telephone;
    });
    if (it != records.end()) {
        cout << "\nRecord found: " << it->name << ", DOB: " << it->dob << ", Telephone: " << it->telephoneNumber << endl;
    } else {
        cout << "\nRecord with telephone number '" << telephone << "' not found." << endl;
    }
}

int main() {
    vector<PersonalRecord> records = {
        {"Alice", "1990-05-15", "1234567890"},
        {"Bob", "1985-08-21", "9876543210"},
        {"Charlie", "1995-02-10", "4567890123"}
    };

    int choice;
    while (true) {
        cout << "\nMENU\n";
        cout << "1. Sort by Name\n";
        cout << "2. Sort by Date of Birth\n";
        cout << "3. Sort by Telephone Number\n";
        cout << "4. Find by Name\n";
        cout << "5. Find by Date of Birth\n";
        cout << "6. Find by Telephone Number\n";
        cout << "7. Display All Records\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            sortByName(records);
        } else if (choice == 2) {
            sortByDob(records);
        } else if (choice == 3) {
            sortByTelephone(records);
        } else if (choice == 4) {
            string searchName;
            cout << "Enter name to find: ";
            cin.ignore();
            getline(cin, searchName);
            findByName(records, searchName);
        } else if (choice == 5) {
            string searchDob;
            cout << "Enter DOB to find (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, searchDob);
            findByDob(records, searchDob);
        } else if (choice == 6) {
            string searchTelephone;
            cout << "Enter Telephone number to find: ";
            cin.ignore();
            getline(cin, searchTelephone);
            findByTelephone(records, searchTelephone);
        } else if (choice == 7) {
            displayRecords(records);
        } else if (choice == 8) {
            return 0;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
