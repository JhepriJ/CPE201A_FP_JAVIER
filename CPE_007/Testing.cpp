#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    char playAgain = 'y';

prjec        int randomNumber = rand() % 1000 + 1; // Generate random number between 1 and 1000
        int guess;
        cout << "Guess the number (between 1 and 1000): ";
        cin >> guess;

        while (guess != randomNumber) {
            if (guess < randomNumber) {
                cout << "Too low! Try again: ";
            } else {
                cout << "Too high! Try again: ";
            }
            cin >> guess;
        }

        cout << "Congratulations! You guessed the number: " << randomNumber << endl;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }





    return 0;
}