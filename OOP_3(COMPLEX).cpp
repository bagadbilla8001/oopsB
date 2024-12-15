#include <iostream>
using namespace std;

class Complex {
public:
    float real;
    float imaginary;

public:
    Complex() {
        real = 0;
        imaginary = 0;
    }

    Complex(float r, float i) {
        real = r;
        imaginary = i;
    }

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imaginary + c.imaginary);
    }

    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imaginary * c.imaginary, real * c.imaginary + imaginary * c.real);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imaginary << "i";
        return out;
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Real Part: ";
        in >> c.real;
        cout << "Imaginary Part: ";
        in >> c.imaginary;
        return in;
    }
};

int main() {
    Complex c1, c2, result;
    int choice;

    while (true) {
        cout << "\nMENU\n";
        cout << "1. Enter First Complex Number\n";
        cout << "2. Enter Second Complex Number\n";
        cout << "3. Calculate Sum\n";
        cout << "4. Calculate Product\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the first complex number:" << endl;
            cin >> c1;
        } else if (choice == 2) {
            cout << "Enter the second complex number:" << endl;
            cin >> c2;
        } else if (choice == 3) {
            result = c1 + c2;
            cout << "Sum: " << result << endl;
        } else if (choice == 4) {
            result = c1 * c2;
            cout << "Product: " << result << endl;
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
