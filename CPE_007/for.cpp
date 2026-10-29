#include <iostream>
using namespace std;

int main () {

    int num;
    cout << "Enter num: ";
    cin >> num;

    // Interger is about  bytes a long is also 4 bytes || a long long is 8 bytes
    long long factorial = 1;
    for (int i = 1; i <= num; ++i) {
        factorial *= i;
    }
    cout << num << "! = " << factorial << endl;
    return 0;
}