#include <iostream>
using namespace std;
//cost of sending a small parcel
int main() {

    double weight;
    double cost;

    cout << "Enter the weight of the parcel in pounds: ";
    cin >> weight;
        if (weight <= 300) {
            cost = 5.00;
        } else if (weight > 300 && weight <= 400) {
            cost = 7.00;
            cout << "The cost of sending the parcel is: P" << cost << endl;
        } else if (weight > 400 && weight <= 500) {
            cost = 9.00;
            cout << "The cost of sending the parcel is: P" << cost << endl;
        } else if (weight > 500 && weight <= 600) {
            cost = 11.00;
            cout << "The cost of sending the parcel is: P" << cost << endl; 
        } else if (weight > 600 && weight <= 700) {
            cost = 13.00;
            cout << "The cost of sending the parcel is: P" << cost << endl;
        } else if (weight > 700 && weight <= 800) {
            cost = 15.00;
            cout << "The cost of sending the parcel is: P" << cost << endl; 
        } else if (weight > 800 && weight <= 900) {
            cost = 17.00;
            cout << "The cost of sending the parcel is: P" << cost << endl;
        } else if (weight > 900 && weight <= 1000) {
            cost = 19.00;
            cout << "The cost of sending the parcel is: P" << cost << endl; 
        } else {
            cout << "The weight of the parcel exceeds the maximum limit of 1000 pounds." << endl;
        }
    return 0;
}