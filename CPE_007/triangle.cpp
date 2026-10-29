#include <iostream>
using namespace std;

int main(){
    int height, base, area;
    cout << "The base of the triangle is: ";
    cin >> base;
    cout << "The height of the triangle is: ";
    cin >> height;
    area = (base * height) / 2;
    cout << "The area of the triangle is: " << area << endl;
    return 0;
}
