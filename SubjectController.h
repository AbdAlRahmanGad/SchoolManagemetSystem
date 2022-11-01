//
// Created by abdo gad on 10/28/22.
//

#ifndef SCHOOLMANAGEMETSYSTEM_SUBJECTCONTROLLER_H
#define SCHOOLMANAGEMETSYSTEM_SUBJECTCONTROLLER_H

#include "SubjectDefinition.h"

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class SubjectController {
private:
    vector<SubjectDefinition> subjects;
public:
//   SubjectController():subjects(){};
     void   setSubjects(int num);
    vector<SubjectDefinition> getSubjects();
   void printSubjects();
    ///   modify
    void   addSubjects(int num);
    void   deleteSubjects(string name);
    void   modifySubjects(string name);
};


#endif //SCHOOLMANAGEMETSYSTEM_SUBJECTCONTROLLER_H
