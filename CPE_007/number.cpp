#include <iostream>
using namespace std;
// asking the user if a number is divisible by 3, 5, or both

int main () {

    int num;
    cout << "Enter number: ";
    cin >> num;

    if (num % 3 == 0 && num % 5 == 0) { //modulus gets the remainder, it only works if the variable is an integer
        cout << "The number is divisible by both 3 and 5.";
    } else if (num % 3 == 0) {
        cout << "Is only divisible by 3.";
    } else if (num % 5 == 0) {
        cout << "Is only divisible by 5.";    
    }
    
    return 0;
}