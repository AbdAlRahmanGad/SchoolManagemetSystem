//
// Created by abdo gad on 10/28/22.
//
#include <iostream>
using namespace std;

#include "Student.h"

#include <iterator>
#include <algorithm>
#include <vector>
#include "SubjectData.h"
#include "SubjectDefinition.h"

#ifndef SCHOOLMANAGEMETSYSTEM_STUDENTCONTROLLER_H
#define SCHOOLMANAGEMETSYSTEM_STUDENTCONTROLLER_H


class StudentController {
private:
    vector<Student> students;
    bool isValidNumber(string s);
public:
    const vector<Student> &getStudents() ;
    void setStudents(const vector<Student> &students) ;
    void addStudents(int num,vector<SubjectDefinition> subsDif);
    void DeleteStudent(int benchN);
    void ModifyStudent(int benchN);
    void PrintStuWGrade();
};


#endif //SCHOOLMANAGEMETSYSTEM_STUDENTCONTROLLER_H
