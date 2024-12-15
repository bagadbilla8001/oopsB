#include <iostream>
#include <stack>
using namespace std;

// Function to add two binary numbers using stacks
string addBinary(string binary1, string binary2) {
    stack<int> stack1, stack2, resultStack;

    // Push each bit of the binary numbers into their respective stacks
    for (char bit : binary1)
        stack1.push(bit - '0');
    for (char bit : binary2)
        stack2.push(bit - '0');

    int carry = 0;

    // Perform addition while either stack is not empty or there is a carry
    while (!stack1.empty() || !stack2.empty() || carry != 0) {
        int bit1 = stack1.empty() ? 0 : stack1.top();
        if (!stack1.empty()) stack1.pop();

        int bit2 = stack2.empty() ? 0 : stack2.top();
        if (!stack2.empty()) stack2.pop();

        // Binary addition
        int sum = bit1 + bit2 + carry;
        resultStack.push(sum % 2); // Push the result bit (0 or 1)
        carry = sum / 2;          // Update the carry
    }

    // Construct the result string from the result stack
    string result = "";
    while (!resultStack.empty()) {
        result += to_string(resultStack.top());
        resultStack.pop();
    }

    return result;
}

int main() {
    string binary1, binary2;

    cout << "Enter the first binary number: ";
    cin >> binary1;
    cout << "Enter the second binary number: ";
    cin >> binary2;

    string result = addBinary(binary1, binary2);

    cout << "The sum of the binary numbers is: " << result << endl;

    return 0;
}
