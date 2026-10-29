#include <iostream>
using namespace std;
// miles per gallon
int main () {

    int milesDriven;
    int gallonsUsed;
    int tankCapacity = 40;

    cout << "Enter miles driven: ";
    cin >> milesDriven;
    cout << "Enter gallons used: ";
    cin >> gallonsUsed;
    cout << "Tank capacity: " << tankCapacity << endl;
    cout << "Miles per gallon: " << milesDriven / gallonsUsed << endl;

    return 0;
}