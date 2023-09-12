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

vector<SubjectDefinition>  subjectController(    SubjectController &subjectController1){
//    vector<subject> allSubjects  ;
//    cout << "enter the number of subjects ";
//    int numOfSub;
//    cin >> numOfSub;
//    SubjectController subjectController1;
//    subjectController1.setSubjects(numOfSub);
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
        cin >> x;
        bool valid = true;
        for (int i = 0; i < x.size(); ++i) {
            if(isdigit(x[i]) == false){
                valid = false;
                break;
            }
        }
        if(!valid){
            cout << "\nPlease enter a valid number\n\n";
            continue;
        }

//        subjectController1.addSubjects(stoi(x));
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
        cout << "\nPlease enter a valid option\n\n";
    }
}
  return  subjectController1.getSubjects();


}
vector<Student> studentController(vector<SubjectDefinition>  &All,StudentController &studentController1
){
    if(All.empty()){
        cout << " add subjects first ";
        vector<Student> s;
        return  s;
    }

//    cout << "enter the number of Students ";
//    int numOfStu;
//    cin >> numOfStu;
//    StudentController studentController1;
//    studentController1.setStudents(numOfStu,All);
    int chose = 0;
while(chose != -1) {
    cout << "enter 1 to add new student " << endl
         << "enter 2 to modify grade for a student  " << endl
         << "enter 3 to delete a student  " << endl
         << "enter 4 to print  student with their grades " << endl
            << "enter -1 to quit " << endl;


    cin >> chose;
    if (chose == 1) {
        cout << "enter num of student to add ";
        int x;
        cin >> x;
        studentController1.addStudents(x, All);
    } else if (chose == 2) {
        cout << "enter Bench number of the student  to modify ";
        int x;
        cin >> x;
        studentController1.ModifyStudent(x);
    } else if (chose == 3) {
        cout << "enter  Bench number of student to delete ";
        int x;
        cin >> x;
        studentController1.DeleteStudent(x);
    } else if (chose == 4) {
        studentController1.PrintStuWGrade();
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
