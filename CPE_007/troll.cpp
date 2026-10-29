#include <iostream>
#include <string>
using namespace std;

int main(){

    struct Student {
        string id;
        string name;
        int age;
        float grade;
    };

    Student students[6];

    for(int i = 0; i < 6; i++) {
        cout << "Enter student ID, Name, Age, Grade" << endl;
        cin >> students[i].id >> students[i].name >> students[i].age >> students[i].grade;
    }

    int passed = 0;
    float highestGrade = -1.0;
    string highestName = "";

    for(int i = 0; i < 6; i++) {
        cout << "Student " << (i + 1) << " (\"" << students[i].name << "\"): " << "ID = " << students[i].id
            << ", Age = " << students[i].age 
            << ", Grade = " << students[i].grade << " --> ";

        if(students[i].grade >= 75.0) {
            cout << "You passed bitch" << endl;
            passed++;
            
            if (students[i].grade > highestGrade) {
                highestGrade = students[i].grade;
                highestName = students[i].name;
            }
        } else {
            cout << "YOU FUCKING FAILED LMAOOOOO" << endl;
        }
    cout << endl;
    cout << "Total passers: " << passed << endl;

    if(passed == 0) {
        cout << "You're all bitches" << endl;
    } else {
        cout << "Highest Grade: " << highestName
        << " Grade = << highestGrade << endl;
    }

    }


    return 0;
}