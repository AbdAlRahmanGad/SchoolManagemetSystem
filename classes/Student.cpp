//
// Created by abdo gad on 10/25/22.
//
#include <iostream>
using namespace std;

#include "Student.h"

#include <iterator>
#include <algorithm>
#include <vector>
#include "SubjectData.h"

//-FirstName
//-LastName
//-Age
//-PhoneNumber
//-Subjects[] (SubjectData)
//=Setters/Getters
//=CalculatePercentage
//         =PrintReport
const string &Student::getFirstName() const {
    return FirstName;
}

const string &Student::getLastName() const {
    return LastName;
}

int Student::getAge() const {
    return Age;
}

int Student::getBenchNumber() const {
    return BenchNumber;
}

const vector<SubjectData> &Student::getSubjects() const {
    return Subjects;
}

void Student::setFirstName(const string &firstName) {
    FirstName = firstName;
}

void Student::setLastName(const string &lastName) {
    LastName = lastName;
}

void Student::setAge(int age) {
    Age = age;
}

void Student::setBenchNumber(int BenchNumber) {
    this->BenchNumber = BenchNumber;
}

void Student::setSubjects(const vector<SubjectData> &subjects) {
    Subjects = subjects;
}

Student::Student(string first, string last, int age, int benchNum, vector<SubjectData> Subjects) {
    setFirstName(first);
    setLastName(last);
    setAge(age);
    setBenchNumber(benchNum);
    setSubjects(Subjects);
}

void Student::SetGradeStudentController(int G,string N) {
    vector<SubjectData>::iterator  it = Subjects.begin();
    for (int i=0;i<Subjects.size();i++) {

        if((*it).getSubDefinition().getName()==N){
            (*it).setGrade(G);
            return;
        }
        it++;
    }
  cout << " no such Subject";
}
    void Student::printReport(){
        cout << "first name "<< FirstName << endl
             << "Last name "<< LastName << endl
             << "Age "<< Age << endl
             << "BenchNumber "<< BenchNumber << endl;
        for (auto i : Subjects) {
            // i.subject.name
            cout << i.getSubDefinition().getName() <<" : "<< i.getGrade()<< endl;

        }

    }

void Student::CalculatePercentage() {
    int percent=0;
    int max=0;

    for (auto i : Subjects) {
        // i.subject.name
        percent+=  i.getGrade();
        max += i.getSubDefinition().getMaxGrade();
    }
    cout << "Percent = "<<(percent / max)*100 <<"%";
}

