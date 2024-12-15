
#include <iostream>
using namespace std;

// Base class
class Convert {
protected:
    double initialValue, convertedValue; // Initial and converted values

public:
    Convert(double initial = 0) : initialValue(initial), convertedValue(0) {}

    double getInitialValue() { return initialValue; }
    double getConvertedValue() { return convertedValue; }

    virtual void compute() = 0; // Pure virtual function
};

// Derived class for converting Celsius to Fahrenheit
class CelsiusToFahrenheit : public Convert {
public:
    CelsiusToFahrenheit(double celsius) : Convert(celsius) {}

    void compute() override {
        convertedValue = (initialValue * 9 / 5) + 32;
    }
};

// Derived class for converting Kilometers to Miles
class KilometersToMiles : public Convert {
public:
    KilometersToMiles(double kilometers) : Convert(kilometers) {}

    void compute() override {
        convertedValue = initialValue * 0.621371;
    }
};

int main() {
    double userInput;

    // Celsius to Fahrenheit conversion
    cout << "Enter temperature in Celsius: ";
    cin >> userInput;
    CelsiusToFahrenheit temperatureConverter(userInput);
    temperatureConverter.compute();
    cout << "Temperature in Fahrenheit: " << temperatureConverter.getConvertedValue() << endl;

    // Kilometers to Miles conversion
    cout << "Enter distance in Kilometers: ";
    cin >> userInput;
    KilometersToMiles distanceConverter(userInput);
    distanceConverter.compute();
    cout << "Distance in Miles: " << distanceConverter.getConvertedValue() << endl;

    return 0;
}
