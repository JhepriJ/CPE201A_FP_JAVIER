#include <iostream>
using namespace std;

int main() {

    int AccountNumber = 81726354;
    int Balance = 5000;
    int Charges;
    int credits;
    int CreditLimit = 40000;
    int NewBalance;
    cout << "Enter account number (-1 to exit): ";
    cin >> AccountNumber;
        if (AccountNumber == 81726354) {
            cout << "Current balance: " << Balance << endl;
            cout << "Enter charges: ";
            cin >> Charges;
            cout << "Enter credits: ";
            cin >> credits;
            cout << "Credit limit is: " << CreditLimit << endl;
            cout << "New balance is: " << Balance + Charges - credits << endl;
                if (Balance + Charges - credits > CreditLimit) {
                    cout << "Credit limit exceeded." << endl;
                } else {
                    cout << "Credit limit not exceeded." << endl;
                }
        } else {
            cout << "Wrong account number." << endl;
        }

    return 0;
}