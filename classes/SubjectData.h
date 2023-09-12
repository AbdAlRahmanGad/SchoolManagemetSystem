//
// Created by abdo gad on 10/25/22.
//

#ifndef SCHOOLMANAGEMETSYSTEM_SUBJECTDATA_H
#define SCHOOLMANAGEMETSYSTEM_SUBJECTDATA_H
#include "SubjectDefinition.h"

//SubjectData
//-SubjectDefinition ___Setter/Getter
// constructior
// Print


class SubjectData {
private:
    SubjectDefinition subDefinition;
    int grade;
public:
    const SubjectDefinition &getSubDefinition() const;
    void setSubDefinition(const SubjectDefinition &subDefinition);
    SubjectData(int g, SubjectDefinition subDef);
    int getGrade() const;
    void setGrade(int grade);
};


#endif //SCHOOLMANAGEMETSYSTEM_SUBJECTDATA_H
