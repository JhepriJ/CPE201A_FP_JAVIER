#include <iostream>
using namespace std;

int main() {
    int wage, hours, salary;
    cout << "Hourly wage: ";
    cin >> wage;
    cout << "Hours worked: ";
    cin >> hours;
    salary = wage * hours;
    cout << "Gross salary: " << salary << endl;
    return 0;
}