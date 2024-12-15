#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

class Quadratic {
private:
    double a, b, c; // Coefficients of the quadratic equation

public:
    // Default constructor
    Quadratic() : a(0), b(0), c(0) {}

    // Parameterized constructor
    Quadratic(double coefA, double coefB, double coefC) : a(coefA), b(coefB), c(coefC) {}

    // Overloaded operator+ to add two quadratic equations
    Quadratic operator+(const Quadratic &q) const {
        return Quadratic(a + q.a, b + q.b, c + q.c);
    }

    // Overloaded << for output
    friend ostream &operator<<(ostream &out, const Quadratic &q) {
        out << q.a << "x^2 ";
        if (q.b >= 0) out << "+ ";
        out << q.b << "x ";
        if (q.c >= 0) out << "+ ";
        out << q.c;
        return out;
    }

    // Overloaded >> for input
    friend istream &operator>>(istream &in, Quadratic &q) {
        cout << "Enter coefficient for x^2: ";
        in >> q.a;
        cout << "Enter coefficient for x: ";
        in >> q.b;
        cout << "Enter constant term: ";
        in >> q.c;
        return in;
    }

    // Function to evaluate the polynomial for a given x
    double eval(double x) const {
        return a * x * x + b * x + c;
    }

    // Function to find the roots of the quadratic equation
    pair<double, double> findRoots() const {
        if (a == 0) {
            throw invalid_argument("Not a quadratic equation (a = 0)");
        }
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            throw runtime_error("No real roots");
        }
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        return make_pair(root1, root2);
    }
};

int main() {
    Quadratic q1, q2;

    cout << "Enter the first quadratic equation:\n";
    cin >> q1;

    cout << "Enter the second quadratic equation:\n";
    cin >> q2;

    Quadratic sum = q1 + q2;
    cout << "Sum of the equations: " << sum << endl;

    double x;
    cout << "Enter a value for x to evaluate the first equation: ";
    cin >> x;
    cout << "Value of the first equation at x = " << x << " is: " << q1.eval(x) << endl;

    try {
        auto roots = q1.findRoots();
        cout << "Roots of the first equation are: " << roots.first << " and " << roots.second << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
