#include <iostream>
#include <string>
using namespace std;

int main(){

    float highestGrade = -1;
    int passed = 0;
    string highestName;

    struct Student{
        string name;
        string id;
        int age;
        float grade;
    };

    Student student[6];

        for(int i = 0; i<6; i++) {
            cout << "Enter student name: ";
            cin>> student[i].name;
            cout << "Enter student id: ";
            cin >> student[i].id;
            cout << "Enter student age: ";
            cin >> student[i].age;
            cout << "Enter grade: ";
            cin >> student[i].grade;
        };
        for(int i = 0; i < 6; i++){
            if(student[i].grade < 75){
                cout << "Student " << i++ << student[i].name << ": ID=" << student[i].id << ", Age = " << student[i].age << ", Grade = " << student[i].grade << " ---> FAILED" << endl;
            } else {
                cout << "Student " << i++ << student[i].name << ": ID=" << student[i].id << ", Age = " << student[i].age << ", Grade = " << student[i].grade << " ---> PASSED" << endl;
            };
        };
        for(int i = 0; i < 6; i++){
            if(student[i].grade > highestGrade) {
                highestGrade = student[i].grade;
                highestName = student[i].name;
            };
        };
        cout << "Total students passed: " << passed << endl;

        if(passed == 0){
            cout << "No students passed" << endl;
        } else {
            cout << "Highest Grade: " << highestName << " (Grade = " << highestGrade << ")" << endl; 
        }
    return 0;
}
