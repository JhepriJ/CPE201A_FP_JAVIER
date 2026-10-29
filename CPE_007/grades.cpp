#include <iostream>
using namespace std;

int main() {
    int midterm, final, laboratory, average;
    cout << "The Midterm Grade is: ";
    cin >> midterm;
    cout << "The Final Grade is: ";
    cin >> final;
    cout << "The Laboratory Grade is: ";
    cin >> laboratory;
    average = (midterm + final + laboratory) / 3;
    cout << "The average grade is: " << average << endl;
    return 0;
}