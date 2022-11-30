//
// Created by abdo gad on 10/28/22.
//

#include "SubjectController.h"

#include "SubjectDefinition.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>


using namespace std;

void SubjectController::setSubjects(int num) {
    for (int i = 0; i < num; ++i) {
        string name;
        int max , min,sucGrade;
        cout << "enter name of subject : ";
        cin >> name;
        cout << "enter Max grade  : ";
        cin >> max;
        cout << "enter Min grade  : ";
        cin >> min;
        cout << "enter Success grade  : ";
        cin >> sucGrade;
        SubjectDefinition s1(name, max, min,sucGrade );
        subjects.push_back(s1);

    }
}

vector<SubjectDefinition> SubjectController::getSubjects() {
    return subjects;

}

void SubjectController::printSubjects() {
    if(subjects.empty()){
        cout << " no subjects Found "<<endl;
        return;
    }
    int count = 1;
    for (auto it:subjects) {
        cout << " subject "<< count++ <<" : "<< endl;
        it.PrintReport();
    }
}

void SubjectController::addSubjects(int num) {
    for (int i = 0; i < num; ++i) {
        string name;
        int max , min,sucGrade;
        cout << "enter name of subject : ";
        cin >> name;
        cout << "enter Max grade  : ";
        cin >> max;
        cout << "enter Min grade  : ";
        cin >> min;
        cout << "enter Success grade  : ";
        cin >> sucGrade;
        SubjectDefinition s1(name, max, min,sucGrade );
        subjects.push_back(s1);

    }
}

void SubjectController::deleteSubjects(string name) {
    vector<SubjectDefinition>::iterator  it = subjects.begin();
    for (int i=0;i<subjects.size();i++) {

        if((*it).getName()==name){
//vector<SubjectDefinition>::iterator  del = it ;
//                std::remove(subjects.begin(), subjects.end(),it);
            subjects.erase(it);
        }
        it++;
    }
}

void SubjectController::modifySubjects(string name) {

    vector<SubjectDefinition>::iterator  it = subjects.begin();
    for (int i=0;i<subjects.size();i++) {

        if((*it).getName()==name){
            string name;
            int max , min,sucGrade;
            cout << "enter name of subject : ";
            cin >> name;
            (*it).setName(name);
            cout << "enter Max grade  : ";
            cin >> max;
            (*it).setMaxGrade(max);

            cout << "enter Min grade  : ";
            cin >> min;
            (*it).setMinGrade(min);

            cout << "enter Success grade  : ";
            cin >> sucGrade;
            (*it).setSuccessGrade(sucGrade);
            return;
        }
        it++;
    }
    cout << "name not matched ";
}
