//
// Created by abdo gad on 10/28/22.
//

#include "StudentController.h"
#include <iostream>
using namespace std;

#include "Student.h"

#include <iterator>
#include <algorithm>
#include <vector>
#include "SubjectData.h"
#include "SubjectDefinition.h"

const vector<Student> &StudentController::getStudents()  {
    return students;

}

void StudentController::setStudents1(const vector<Student> &students) {
    StudentController::students = students;

}

void StudentController::setStudents(int num, vector<SubjectDefinition> subsDif) {
    for (int i = 0; i < num; ++i) {
        int age,benchNumber;
        string FirstName , LastName;
        cout << "enter first name of student : ";
        cin >> FirstName;
        cout << "enter last name of student : ";
        cin >> LastName;
        cout << "enter Age  : ";
        cin >> age;
        cout << "enter bench Number : ";
        cin >> benchNumber;
        vector<SubjectData> subData;
        cout << "enter the grade for "<<endl;
        for (int j = 0; j < subsDif.size(); ++j) {
            cout << "enter the student grade for "<<subsDif[j].getName()<<"  ";
            int grade;
            cin >> grade;
            SubjectData s10(grade , subsDif[j]);
            subData.push_back(s10);
        }
        Student s1(FirstName,LastName,age ,benchNumber,subData);

        students.push_back(s1);
    }
}

void StudentController::addStudents(int num, vector<SubjectDefinition> subsDif) {
    for (int i = 0; i < num; ++i) {
        int age,benchNumber;
        string FirstName , LastName;
        cout << "enter first name of student : ";
        cin >> FirstName;
        cout << "enter last name of student : ";
        cin >> LastName;
        cout << "enter Age  : ";
        cin >> age;
        cout << "enter bench Number : ";
        cin >> benchNumber;
        vector<SubjectData> subData;
        cout << "enter the grade for "<<endl;
        for (int j = 0; j < subsDif.size(); ++j) {
            cout << "enter the student grade for "<<subsDif[j].getName()<<"  ";
            int grade;
            cin >> grade;
            SubjectData s10(grade , subsDif[j]);
            subData.push_back(s10);
        }
        Student s1(FirstName,LastName,age ,benchNumber,subData);

        students.push_back(s1);
    }
}

void StudentController::DeleteStudent(int benchN){
    vector<Student>::iterator  it = students.begin();

    for (int i=0;i<students.size();i++) {

        if((*it).getBenchNumber()==benchN){
            students.erase(it);
        }
        it++;
    }
    cout << "not Found ";
}

void StudentController::ModifyStudent(int benchN) {

    vector<Student>::iterator  it = students.begin();

    for (int i=0;i<students.size();i++) {

        if((*it).getBenchNumber()==benchN){
            cout << (*it).getFirstName()<<" "<<(*it).getLastName();
//               cout <<endl << "press 1 to edit 0 to skip  "<<endl;
//                (*it).;
//                        vector<SubjectData> subData;

//            cout << "enter the grade for "<<endl;
            for (int j = 0; j < (*it).getSubjects().size(); ++j) {
                cout << "enter the student grade for "<< (*it).getSubjects().at(j).getSubDefinition().getName()<<"  ";
                int grade;
                cin >> grade;
                (*it).SetGradeStudentController(grade,(*it).getSubjects().at(j).getSubDefinition().getName());

//                    (*it).getSubjects().at(j).
            }
            return;
        }
        it++;
    }
    cout << "not Found ";
}

void StudentController::PrintStuWGrade() {
    for (int i = 0; i < students.size(); ++i) {
        students[i].printReport();
    }
}
