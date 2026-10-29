#include <iostream>
using namespace std;

//displays a menu for simple conversions
int main() {
    int cm;
    int inches;
    int feet;
    int meter;

    if (1) {
        cout << "Conversion Menu" << endl;
        cout << "1. Centimeters to Inches" << endl;
        cout << "2. Inches to Centimeters" << endl;
        cout << "3. Feet to Meters" << endl;
        cout << "4. Meters to Feet" << endl;
        cout << "5. Exit" << endl;
            if (1) {
                cout << "Enter your choice: ";
                int choice;
                cin >> choice;
                    if (choice == 1) {
                        cout << "Enter centimeters: ";
                        cin >> cm;
                        inches = cm / 2.54;
                        cout << cm << " centimeters is equal to " << inches << " inches." << endl;
                    } else if (choice == 2) {
                        cout << "Enter inches: ";
                        cin >> inches;
                        cm = inches * 2.54;
                        cout << inches << " inches is equal to " << cm << " centimeters." << endl;
                    } else if (choice == 3) {
                        cout << "Enter feet: ";
                        cin >> feet;
                        meter = feet * 0.3048;
                        cout << feet << " feet is equal to " << meter << " meters." << endl;
                    } else if (choice == 4) {
                        cout << "Enter meters: ";
                        cin >> meter;
                        feet = meter / 0.3048;
                        cout << meter << " meters is equal to " << feet << " feet." << endl;
                    } else if (choice == 5) {
                        cout << "Exiting the program." << endl;
                    } else {
                        cout << "Invalid choice. Please try again." << endl;
                    }
            }   char playAgain;
                cout << "Do you want to perform another conversion? (y/n): ";
                cin >> playAgain;
                    if (playAgain == 'y' || playAgain == 'Y') {
                        main();
                    } else {
                        cout << "Thank you for using the conversion program." << endl;
                    }
    } 
    return 0;
}