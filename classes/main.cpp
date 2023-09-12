/**
 * @ Author: Your name
 * @ Create Time: 2022-10-28 23:16:30
 * @ Modified by: Your name
 * @ Modified time: 2022-11-01 01:38:51
 * @ Description:
 */

#include <iostream>
#include <vector>

using namespace std;
#include "Student.h"
#include "SubjectData.h"
#include "SubjectController.h"
#include "StudentController.h"
#include "SubjectDefinition.h"

void student(vector <Student> studentsResults){
    cout << " enter your  bench number  " << endl;
    int x =1 ;
    while (x) {
        int bench;
        cin >> bench;
///    ///  Read from file file file
        int flag = 1;
        for (int i = 0; i < studentsResults.size(); ++i) {
            if (studentsResults[i].getBenchNumber() == bench) {
                studentsResults[i].printReport();
                flag = 0;
            }
        }
//        Student result ;
//    ///
//    result.setSubjects(allSubjects);
//    result.printReport();
        if (flag)
            cout << " not found , " << endl;
            cout << " enter any number to try again or 0 to quit  ";
        cin >> x;
    }
}
bool isValidNumber(string s){
    bool valid = true;
    for (int i = 0; i < s.size(); ++i) {
        if(isdigit(s[i]) == false){
            valid = false;
            break;
        }
    }
    if(valid)return true;
    else return false;
}

vector<SubjectDefinition>  subjectController(    SubjectController &subjectController1){
    string chose = "";
    while(chose!="-1") {
    cout << "enter 1 to add new subject " << endl
         << "enter 2 to modify a subject " << endl
         << "enter 3 to delete a subject " << endl
         << "enter 4 to print  a subjects " << endl
         << "enter -1 to quit " << endl;
    cin >> chose;
    if (chose == "1") {
        cout << "enter num of subjects to add ";
        string x;
       while(cin >> x){
           bool valid = isValidNumber(x);
           if(!valid){
               cout << "\nPlease enter a valid number : ";
           }else{
               break;
           }
       }

        subjectController1.setSubjects(stoi(x));
    } else if (chose == "2") {
        cout << "enter name of subjects to modify ";
        string x;
        cin >> x;
        subjectController1.modifySubjects(x);
    } else if (chose == "3") {
        cout << "enter name of subjects to delete ";
        string x;
        cin >> x;
        subjectController1.deleteSubjects(x);
    } else if (chose == "4") {
        subjectController1.printSubjects();
    }else{
        cout << "\nPlease enter a valid number : ";
    }
}
  return  subjectController1.getSubjects();
}
vector<Student> studentController(vector<SubjectDefinition>  &All,StudentController &studentController1
){
    if(All.empty()){
        cout << "Add subjects first \n";
        vector<Student> s;
        return  s;
    }
    string chose = "";
while(chose != "-1") {
    cout << "enter 1 to add new student " << endl
         << "enter 2 to modify grade for a student  " << endl
         << "enter 3 to delete a student  " << endl
         << "enter 4 to print  student with their grades " << endl
            << "enter -1 to quit " << endl;
    cin >> chose;
    if (chose == "1") {
        cout << "enter num of student to add ";
        string x;
        while(cin >> x){
            bool valid = isValidNumber(x);
            if(!valid){
                cout << "\nPlease enter a valid number : ";
            }else{
                break;
            }
        }
        studentController1.addStudents(stoi(x), All);
    } else if (chose == "2") {
        cout << "enter Bench number of the student  to modify ";
        string x;
        while(cin >> x){
            bool valid = isValidNumber(x);
            if(!valid){
                cout << "\nPlease enter a valid number : ";
            }else{
                break;
            }
        }
        studentController1.ModifyStudent(stoi(x));
    } else if (chose == "3") {
        cout << "enter Bench number of the student to delete : ";
        string x;
        while(cin >> x){
            bool valid = isValidNumber(x);
            if(!valid){
                cout << "\nPlease enter a valid number : ";
            }else{
                break;
            }
        }
        studentController1.DeleteStudent(stoi(x));
    } else if (chose == "4") {
        studentController1.PrintStuWGrade();
    }else{
        cout << "\nPlease enter a valid option\n\n";
    }
}
    vector<Student> resultedStudets(studentController1.getStudents());

    return resultedStudets;

}
int main() {
    std::cout << "Hello, sir " << std::endl<< "Enter \n 1 - if you are a student \n 2 - if you are an admin \n-1 - to quit ";
    string option;
    cin >> option;
    SubjectController subjectController1;
    StudentController studentController1;

    vector<SubjectDefinition> AllSubjects;
    vector<Student> studentsResults;
    while(option != "-1"){
        if(option == "1" ){
            //function student
            if(studentsResults.empty()){
                cout << "\nplease insert students first As an admin  \n\nenter 2 please if you are an admin or -1 to quit: ";
                cin >> option;
                continue;
            }
            student(studentsResults);
        }else if (option == "2" ){
            cout << "\n Enter\n 1 if you are a student controller \n 2 if you are a subject Controller " << endl;
            string adminOption;
            cin >> adminOption;
            if(adminOption == "1"){

                studentsResults =   studentController(AllSubjects ,studentController1 );

            }else if(adminOption == "2"){

                AllSubjects =  subjectController(subjectController1);

            }else{
                cout << "\nPlease enter a valid option\n\n";
            }
        }else {
            cout << "\nPlease enter a valid option\n\n";
        }
        cout << "Enter \n 1 - if you are a student \n 2 - if you are an admin \n-1 - to quit ";
        cin >> option;
    }
    return 0;
}
