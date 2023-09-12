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
void StudentController::setStudents(const vector<Student> &students) {
    StudentController::students = students;
}
bool StudentController::isValidNumber(string s){
    bool valid = true;
    for (int i = 0; i < s.size(); ++i) {
        if(isdigit(s[i]) == false){
            valid = false;
            break;
        }
    }
    if(!valid)return false;
    else return true;
}
void StudentController::addStudents(int num, vector<SubjectDefinition> subsDif) {
    for (int i = 0; i < num; ++i) {
        string benchNumber;
        string FirstName , LastName;
        cout << "enter first name of student : ";
        cin >> FirstName;
        cout << "enter last name of student : ";
        cin >> LastName;
        cout << "enter bench Number : ";
        while(cin >> benchNumber){
            if(!isValidNumber(benchNumber)){
                cout << "\nPlease enter a valid number : ";
            }else {
                break;
            }
        }
        vector<SubjectData> subData;
        cout << "enter the grade for "<<endl;
        for (int j = 0; j < subsDif.size(); ++j) {
            cout << "enter the student grade for "<<subsDif[j].getName()<<"  ";
            int maxGrade = subsDif[j].getMaxGrade();
            int minGrade = subsDif[j].getMinGrade();
            string grade;
            while(cin >> grade){
                if(!isValidNumber(grade)){
                    cout << "\nPlease enter a valid number : ";
                }else if ( stoi(grade) < minGrade || stoi(grade) > maxGrade ){
                    cout << "\nPlease enter a number between " << minGrade << " and " << maxGrade <<" : ";
                }else {
                    break;
                }
            }
            SubjectData s10(stoi(grade) , subsDif[j]);
            subData.push_back(s10);
        }
        Student s1(FirstName,LastName ,stoi(benchNumber),subData);

        students.push_back(s1);
    }
}

void StudentController::DeleteStudent(int benchN){
    vector<Student>::iterator  it = students.begin();
    for (int i=0;i<students.size();i++) {

        if((*it).getBenchNumber()==benchN){
            students.erase(it);
            return;
        }
        it++;
    }
    cout << "\nnot Found \n";
}

void StudentController::ModifyStudent(int benchN) {

    vector<Student>::iterator  it = students.begin();

    for (int i=0;i<students.size();i++) {

        if((*it).getBenchNumber()==benchN){
            cout << (*it).getFirstName()<<" "<<(*it).getLastName();
            for (int j = 0; j < (*it).getSubjects().size(); ++j) {
                cout << "enter the student grade for "<< (*it).getSubjects().at(j).getSubDefinition().getName()<<"  ";
                string grade;
                int maxGrade = (*it).getSubjects().at(j).getSubDefinition().getMaxGrade();
                int minGrade = (*it).getSubjects().at(j).getSubDefinition().getMinGrade();
                while(cin >> grade){
                    if(!isValidNumber(grade)){
                        cout << "\nPlease enter a valid number : ";
                    }else if ( stoi(grade) < minGrade || stoi(grade) > maxGrade ){
                        cout << "\nPlease enter a number between " << minGrade << " and " << maxGrade <<" : ";
                    }else {
                        break;
                    }
                }
                (*it).SetGradeStudentController(stoi(grade),(*it).getSubjects().at(j).getSubDefinition().getName());
            }
            return;
        }
        it++;
    }
    cout << "\nnot Found \n";
}
void StudentController::PrintStuWGrade() {
    for (int i = 0; i < students.size(); ++i) {
        students[i].printReport();
    }
}