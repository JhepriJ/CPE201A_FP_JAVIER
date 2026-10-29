#include <iostream>
using namespace std;

int main() {
    int AreaOfCircle;
    int AreaOfTriangle;
    int AreaOfSquare;
    int AreaOfRectangle;

    if (1) {
        cout << "Area Calculation Menu" << endl;
        cout << "1. Area of Circle" << endl;
        cout << "2. Area of Triangle" << endl;
        cout << "3. Area of Square" << endl;
        cout << "4. Area of Rectangle" << endl;
        cout << "5. Exit" << endl;

        if (1) {
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                double radius;
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                AreaOfCircle = 3.14159 * radius * radius;
                cout << "The area of the circle is: " << AreaOfCircle << endl;
            } else if (choice == 2) {
                double base, height;
                cout << "Enter the base of the triangle: ";
                cin >> base;
                cout << "Enter the height of the triangle: ";
                cin >> height;
                AreaOfTriangle = 0.5 * base * height;
                cout << "The area of the triangle is: " << AreaOfTriangle << endl;
            } else if (choice == 3) {
                double side;
                cout << "Enter the side length of the square: ";
                cin >> side;
                AreaOfSquare = side * side;
                cout << "The area of the square is: " << AreaOfSquare << endl;
            } else if (choice == 4) {
                double length, width;
                cout << "Enter the length of the rectangle: ";
                cin >> length;
                cout << "Enter the width of the rectangle: ";
                cin >> width;
                AreaOfRectangle = length * width;
                cout << "The area of the rectangle is: " << AreaOfRectangle << endl;
            } else if (choice == 5) {
                cout << "Exiting the program." << endl;
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    } char playAgain;
    cout << "Do you want to perform another area calculation? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        main();
    } else {
        cout << "Thank you for using the area calculation program." << endl;
    }

    return 0;
}