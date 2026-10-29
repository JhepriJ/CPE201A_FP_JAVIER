#include <iostream>
using namespace std;

int main () {

    int age;
    cout << "Enter your age: ";
    cin >> age;
        if (age >= 60) {
            cout << "You are eligible for a senior citizen discount." << endl;
        } else if (age >= 18 && age <= 25) {
            cout << "You are eligible for a student discount." << endl;
        } else {
            cout << "You are not eligible for any discount." << endl;
        } 
    double fare, discount, finalPrice;
    cout << "Enter the fare: ";
    cin >> fare;
        if (age >= 60) {
            discount = fare * 0.1;
        } else if (age >= 18 && age <= 25) {
            discount = fare * 0.08;
        } else {
            discount = 0;
        }
    finalPrice = fare - discount;
    cout << "Final price after discount: P" << finalPrice << endl;

    return 0;
}