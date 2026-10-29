#include <iostream>
using namespace std;

// asking the user for a letter and checking if it is a vowel or not
int main() {
    
    char letter;
    cout << "Enter a letter: " << endl;
    cin >> letter;

    // || is or operator, it checks if any of the conditions are true
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
         letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {
        cout << letter << " is a vowel." << endl;
    } else {
        cout << letter << " is a consonant." << endl;
    }   

    return 0;
}