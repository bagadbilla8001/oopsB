#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class StudData {
private:
    string contactAddress;
    string telephoneNumber;
    string drivingLicense;

public:
    StudData() {
        contactAddress = "";
        telephoneNumber = "";
        drivingLicense = "";
    }

    StudData(const string& contact, const string& telephone, const string& license)
        : contactAddress(contact), telephoneNumber(telephone), drivingLicense(license) {}

    void displayStudData() const {
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License: " << drivingLicense << endl;
    }

    friend class Student;
};

class Student {
private:
    string name;
    int rollNumber;
    string className;
    string division;
    string dob;
    string bloodGroup;
    StudData* studentData;

    static int totalStudents; // Static member to keep track of total students

public:
    Student() : name(""), rollNumber(0), className(""), division(""), dob(""), bloodGroup(""), studentData(nullptr) {
        totalStudents++;
    }

    Student(const string& name, int roll, const string& cls, const string& div,
            const string& dob, const string& blood) : name(name), rollNumber(roll), className(cls), division(div),
                dob(dob), bloodGroup(blood), studentData(nullptr) {
        totalStudents++;
    }

    ~Student() {
        totalStudents--;
        delete studentData;
    }

    void setStudentData(const string& contact, const string& telephone, const string& license) {
        if (studentData == nullptr) {
            studentData = new StudData(contact, telephone, license);
        } else {
            studentData->contactAddress = contact;
            studentData->telephoneNumber = telephone;
            studentData->drivingLicense = license;
        }
    }

    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << " - Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        if (studentData != nullptr) {
            studentData->displayStudData();
        }
    }

    static int getTotalStudents() {
        return totalStudents;
    }
};

int Student::totalStudents = 0; // Initializing static member

void displayMenu() {
    cout << "Menu:\n"
         << "1. Create a new student\n"
         << "2. Display student information\n"
         << "3. Total number of students\n"
         << "4. Exit\n";
}

int main() {
    int choice;
    bool exit = false;
    Student* students[100] = { nullptr }; // Assuming a maximum of 100 students

    while (!exit) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To clear the newline from the input buffer

        try {
            if (choice == 1) {
                string name, cls, div, dob, blood, contact, telephone, license;
                int roll;

                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter roll number: ";
                cin >> roll;
                cin.ignore(); // Clear newline from the buffer
                cout << "Enter class: ";
                getline(cin, cls);
                cout << "Enter division: ";
                getline(cin, div);
                cout << "Enter date of birth (YYYY-MM-DD): ";
                getline(cin, dob);
                cout << "Enter blood group: ";
                getline(cin, blood);
                cout << "Enter contact address: ";
                getline(cin, contact);
                cout << "Enter telephone number: ";
                getline(cin, telephone);
                cout << "Enter driving license: ";
                getline(cin, license);

                if (roll < 0) {
                    throw invalid_argument("Roll number cannot be negative.");
                }

                students[Student::getTotalStudents() - 1] = new Student(name, roll, cls, div, dob, blood);
                students[Student::getTotalStudents() - 1]->setStudentData(contact, telephone, license);

                cout << "Student created successfully!\n";
            } else if (choice == 2) {
                int index;
                cout << "Enter student index to display information: ";
                cin >> index;

                if (index >= 0 && index < Student::getTotalStudents() && students[index] != nullptr) {
                    students[index]->displayInfo();
                } else {
                    cout << "Invalid index or no student exists at that index!\n";
                }
            } else if (choice == 3) {
                cout << "Total students: " << Student::getTotalStudents() << endl;
            } else if (choice == 4) {
                exit = true;
            } else {
                cout << "Invalid choice. Please enter a valid option.\n";
            }
        } catch (const exception& ex) {
            cout << "Exception caught: " << ex.what() << endl;
        }
    }

    // Free memory for dynamically allocated students
    for (int i = 0; i < Student::getTotalStudents(); ++i) {
        delete students[i];
    }

    return 0;
}
