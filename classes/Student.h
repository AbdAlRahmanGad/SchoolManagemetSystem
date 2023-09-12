//
// Created by abdo gad on 10/25/22.
//
#include <iostream>
using namespace std;
#include <vector>
#include "SubjectData.h"

#ifndef SCHOOLMANAGEMETSYSTEM_STUDENT_H
#define SCHOOLMANAGEMETSYSTEM_STUDENT_H


//    -Subjects[] (SubjectData)
//    =CalculatePercentage
//    =PrintReport
// constructior
/// maybe change setter and getter for vector
class Student {
private:
    string FirstName;
    string LastName;
    int Age;
    int BenchNumber;
    vector<SubjectData>Subjects;
    void SetGradeStudentController(int G,string N);

public:
    Student(){};
    Student(string first, string last, int age , int benchNum,vector<SubjectData>subjects);
    const string &getFirstName() const;

    const string &getLastName() const;

    int getAge() const;

    int getBenchNumber() const;

    const vector<SubjectData> &getSubjects() const;

    void setFirstName(const string &firstName);

    void setLastName(const string &lastName);

    void setAge(int age);

    void setBenchNumber(int phoneNumber);

    void setSubjects(const vector<SubjectData> &subjects);
    void printReport();
    void CalculatePercentage();
    friend class StudentController;

//    void SetGradeStudentController(int G, string N);
};


#endif //SCHOOLMANAGEMETSYSTEM_STUDENT_H
