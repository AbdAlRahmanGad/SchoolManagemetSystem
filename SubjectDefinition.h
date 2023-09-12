//
// Created by abdo gad on 10/25/22.
//

#ifndef SCHOOLMANAGEMETSYSTEM_SUBJECTDEFINITION_H
#define SCHOOLMANAGEMETSYSTEM_SUBJECTDEFINITION_H
#include <iostream>

using namespace std;

//         =PrintReport

class SubjectDefinition {
string Name;
string Description;
int MaxGrade;
int MinGrade;
int SuccessGrade;
public:
    SubjectDefinition (string n,int Max,int Min,int sucGrade):Name(n),
    MaxGrade(Max),MinGrade(Min),SuccessGrade(sucGrade){}
    SubjectDefinition();
    string getName() const;
    void setName(string  name);
    const string &getDescription() const;
    void setDescription(const string &description);
    int getMaxGrade() const;
    void setMaxGrade(int maxGrade);
    int getMinGrade() const;
    void setMinGrade(int minGrade);
    int getSuccessGrade() const;
    void setSuccessGrade(int successGrade);
    void  PrintReport();
};


#endif //SCHOOLMANAGEMETSYSTEM_SUBJECTDEFINITION_H
