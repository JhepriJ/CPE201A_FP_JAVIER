#include <iostream>
using namespace std;

int main() {
    
    int yearsofservice;
    int rating;

    cout << "Total years of service: " << endl;
    cin >> yearsofservice;
    cout << "Performance rating (1-5): " << endl;
    cin >> rating;

        if (yearsofservice >= 10 && rating >= 4 && rating <= 5) {
            cout << "Your bonus is 20,000 Pesos" << endl;
        } 
            else if (yearsofservice >= 5 && yearsofservice <= 9 && rating >= 4 && rating <= 5) {
            cout << "Your bonus is 15,000 Pesos" << endl;
        } 
            else if (yearsofservice < 5 && rating >= 4 && rating <= 5) {
            cout << "Your bonus is 10,000 Pesos" << endl;
        } 
            else if (yearsofservice >= 10 && rating >= 2 && rating <= 3) {
            cout << "Your bonus is 15,000 Pesos" << endl;
        } 
            else if (yearsofservice >= 5 && yearsofservice <= 9 && rating >= 2 && rating <= 3) {
            cout << "Your bonus is 10,000 Pesos" << endl;
        }
            else if (yearsofservice < 5 && rating >=2 && rating <= 3) {
            cout << "Your bonus is 5,000 Pesos" << endl; 
        }
            else if (yearsofservice >= 10 && rating == 1) {
            cout << "Your bonus is 10,000 Pesos" << endl;
        }
            else if (yearsofservice >= 5 && yearsofservice <= 9 && rating == 1) {
            cout << "Your bonus is 5,000 Pesos" << endl;
        }
            else if (yearsofservice < 5 && rating == 1) {
            cout << "You do not get a bonus" << endl;
        }
    char playAgain;
    cout << "Do you want to check again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        main();
    } else {
        cout << "Thank you for checking your bonus" << endl;
    }


    return 0;
}