#include <iostream>
using namespace std;

int main(){
    int product, price, quantity, pay;
    cout << "Product name: "<< "Steak" << endl;
    cout << "Unit price: ";
    cin >> price;
    cout << "Quantity purchased: ";
    cin >> quantity;
    pay = price * quantity;
    cout << "Total amount to pay: " << pay << endl;
    return 0;
}