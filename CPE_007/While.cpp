#include <iostream>
using namespace std;

int main() {
    // Example > input: 1234 === OUTPUT is 4321
    int num, digit, reversed = 0;
    cout << "Enter a number: ";
    cin >> num;

    while (num != 0) { // While num is not equal to 0, print the whole body
        digit = num % 10; // Get the last digit of the number
        reversed = reversed * 10 + digit; // Add the digit to the reversed number
        num /= 10; // Remove the last digit from the number

    }

    cout << "Reversed number: " << reversed << endl; // Print the reversed number


    return 0;
}