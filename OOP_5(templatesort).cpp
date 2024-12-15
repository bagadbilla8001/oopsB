#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void selectionSort(vector<T>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void performOperations(const string& dataType) {
    int arraySize;
    cout << "Enter the size of the " << dataType << " array: ";
    cin >> arraySize;
    vector<T> data(arraySize);

    cout << "Enter elements for the " << dataType << " array:" << endl;
    for (auto& element : data) {
        cin >> element;
    }

    selectionSort(data);

    cout << "Sorted " << dataType << " array: ";
    for (const auto& element : data) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\nMENU\n";
        cout << "1. Sort integer array\n";
        cout << "2. Sort float array\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            performOperations<int>("integer");
        } else if (choice == 2) {
            performOperations<float>("float");
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
