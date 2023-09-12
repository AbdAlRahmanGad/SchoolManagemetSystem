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
        string max , min, sucGrade;
        cout << "enter name of subject : ";
        cin >> name;
        cout << "enter Max grade  : ";
        max = setGrade(0,0,0);
        cout << "enter Min grade  : ";
        min = setGrade(1,-1, stoi(max));
        cout << "enter Success grade  : ";
        sucGrade = setGrade(2, stoi(min), stoi(max));
        cout << "\n";
        SubjectDefinition s1(name, stoi(max), stoi(min), stoi(sucGrade) );
        subjects.push_back(s1);
    }
}
vector<SubjectDefinition> SubjectController::getSubjects() {
    return subjects;

}
void SubjectController::printSubjects() {
    if(subjects.empty()){
        cout << "no subjects Found "<<endl << endl;
        return;
    }
    int count = 1;
    for (auto it:subjects) {
        cout << "subject "<< count++ <<" : "<< endl;
        it.PrintReport();
    }
}
void SubjectController::deleteSubjects(string name) {
    vector<SubjectDefinition>::iterator  it = subjects.begin();
    for (int i=0;i<subjects.size();i++) {
        if((*it).getName()==name){
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
            string max , min,sucGrade;
            cout << "enter name of subject : ";
            cin >> name;
            (*it).setName(name);
            cout << "enter Max grade  : ";
            max = setGrade(0,0,0);
            cout << "enter Min grade  : ";
            min = setGrade(1,-1, stoi(max));
            cout << "enter Success grade  : ";
            sucGrade = setGrade(2, stoi(min), stoi(max));
            (*it).setMaxGrade(stoi(max));
            (*it).setMinGrade(stoi(min));
            (*it).setSuccessGrade(stoi(sucGrade));
            return;
        }
        it++;
    }
    cout << "name not matched \n";
}
string SubjectController::setGrade(int type, int min, int max) {
    string grade;
    while(cin >> grade) {
        bool valid = true;
        for (int i = 0; i < grade.size(); ++i) {
            if (isdigit(grade[i]) == false) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << "\nPlease enter a valid number\n";
        }
        else if (stoi(grade) > max && type == 1) {
            cout << "\nmin grade can't be greater than max\n";
        }
        else if ((stoi(grade) < min || stoi(grade) > max) && type == 2){
            cout << "\nSuccess grade must be between min and max grade\n";
        }
        else{
            break;
        }
    }
    return grade;
}
