/**
 * @ Author: Your name
 * @ Create Time: 2022-10-28 23:16:30
 * @ Modified by: Your name
 * @ Modified time: 2022-11-01 01:38:51
 * @ Description:
 */
// Created by abdo gad on 10/25/22.
//

//
// Created by abdo gad on 10/28/22.
//
#include <iostream>
using namespace std;
#include <iterator>
#include <algorithm>
#include <vector>
/// class declarations
class SubjectDefinition;
class SubjectData;
class SubjectController ;
class StudentController ;
class Student;
/// class headers

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
class Student {
private:
    string FirstName;
    string LastName;
    int Age;
    int BenchNumber;
    vector<SubjectData>Subjects;
    void SetGradeStudentController(int G,string N);

public:
    Student();
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
class StudentController {
private:
    vector<Student> students;
//    vector<SubjectData> subjects;
public:
    const vector<Student> &getStudents() ;

    void setStudents1(const vector<Student> &students) ;



    void setStudents(int num, vector<SubjectDefinition> subsDif);
    void addStudents(int num,vector<SubjectDefinition> subsDif);
    void DeleteStudent(int benchN);
    void ModifyStudent(int benchN);
    void PrintStuWGrade();
};
/// StudentController implementations
const vector<Student> &StudentController::getStudents()  {
    return students;

}

void StudentController::setStudents1(const vector<Student> &students) {
    StudentController::students = students;

}

void StudentController::setStudents(int num, vector<SubjectDefinition> subsDif) {
    for (int i = 0; i < num; ++i) {
        int age,benchNumber;
        string FirstName , LastName;
        cout << "enter first name of student : ";
        cin >> FirstName;
        cout << "enter last name of student : ";
        cin >> LastName;
        cout << "enter Age  : ";
        cin >> age;
        cout << "enter bench Number : ";
        cin >> benchNumber;
        vector<SubjectData> subData;
        cout << "enter the grade for "<<endl;
        for (int j = 0; j < subsDif.size(); ++j) {
            cout << "enter the student grade for "<<subsDif[j].getName()<<"  ";
            int grade;
            cin >> grade;
            SubjectData s10(grade , subsDif[j]);
            subData.push_back(s10);
        }
        Student s1(FirstName,LastName,age ,benchNumber,subData);

        students.push_back(s1);
    }
}

void StudentController::addStudents(int num, vector<SubjectDefinition> subsDif) {
    for (int i = 0; i < num; ++i) {
        int age,benchNumber;
        string FirstName , LastName;
        cout << "enter first name of student : ";
        cin >> FirstName;
        cout << "enter last name of student : ";
        cin >> LastName;
        cout << "enter Age  : ";
        cin >> age;
        cout << "enter bench Number : ";
        cin >> benchNumber;
        vector<SubjectData> subData;
        cout << "enter the grade for "<<endl;
        for (int j = 0; j < subsDif.size(); ++j) {
            cout << "enter the student grade for "<<subsDif[j].getName()<<"  ";
            int grade;
            cin >> grade;
            SubjectData s10(grade , subsDif[j]);
            subData.push_back(s10);
        }
        Student s1(FirstName,LastName,age ,benchNumber,subData);

        students.push_back(s1);
    }
}

void StudentController::DeleteStudent(int benchN){
    vector<Student>::iterator  it = students.begin();

    for (int i=0;i<students.size();i++) {

        if((*it).getBenchNumber()==benchN){
            students.erase(it);
        }
        it++;
    }
    cout << "not Found ";
}

void StudentController::ModifyStudent(int benchN) {

    vector<Student>::iterator  it = students.begin();

    for (int i=0;i<students.size();i++) {

        if((*it).getBenchNumber()==benchN){
            cout << (*it).getFirstName()<<" "<<(*it).getLastName();
//               cout <<endl << "press 1 to edit 0 to skip  "<<endl;
//                (*it).;
//                        vector<SubjectData> subData;

//            cout << "enter the grade for "<<endl;
            for (int j = 0; j < (*it).getSubjects().size(); ++j) {
                cout << "enter the student grade for "<< (*it).getSubjects().at(j).getSubDefinition().getName()<<"  ";
                int grade;
                cin >> grade;
                (*it).SetGradeStudentController(grade,(*it).getSubjects().at(j).getSubDefinition().getName());

//                    (*it).getSubjects().at(j).
            }
            return;
        }
        it++;
    }
    cout << "not Found ";
}

void StudentController::PrintStuWGrade() {
    for (int i = 0; i < students.size(); ++i) {
        students[i].printReport();
    }
}

/// student implementations

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


/// SubjectData implementations

int SubjectData::getGrade() const {
    return grade;
}

void SubjectData::setGrade(int grade) {
    SubjectData::grade = grade;
//    subDefinition.
}

SubjectData::SubjectData(int g, SubjectDefinition subDef) {
    setGrade(g);
    subDefinition = subDef;
}

const SubjectDefinition &SubjectData::getSubDefinition() const {
    return subDefinition;
}

void SubjectData::setSubDefinition(const SubjectDefinition &subDefinition) {
    SubjectData::subDefinition = subDefinition;
}
/// SubjectController implementations

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
///SubjectDefinition implementations
string SubjectDefinition::getName() const {
    return Name;
}

void SubjectDefinition::setName(string name) {
    Name = name;
}

const string &SubjectDefinition::getDescription() const {
    return Description;
}

void SubjectDefinition::setDescription(const string &description) {
    Description = description;
}

int SubjectDefinition::getMaxGrade() const {
    return MaxGrade;
}

void SubjectDefinition::setMaxGrade(int maxGrade) {
    MaxGrade = maxGrade;
}

int SubjectDefinition::getMinGrade() const {
    return MinGrade;
}

void SubjectDefinition::setMinGrade(int minGrade) {
    MinGrade = minGrade;
}

int SubjectDefinition::getSuccessGrade() const {
    return SuccessGrade;
}

void SubjectDefinition::setSuccessGrade(int successGrade) {
    SuccessGrade = successGrade;
}

void SubjectDefinition::PrintReport() {
    cout << "subject name :" << Name << endl
         <<  "Description :" << Description << endl
         <<  "MaxGrade :" << MaxGrade << endl
         <<  "MinGrade :" << MinGrade << endl
         <<  "SuccessGrade :" << SuccessGrade << endl;
}

SubjectDefinition::SubjectDefinition() {}

/// main functions
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
    int chose = 0;

    while(chose!=-1) {
        cout << "enter 1 to add new subject " << endl
             << "enter 2 to modify a subject " << endl
             << "enter 3 to delete a subject " << endl
             << "enter 4 to print  a subjects " << endl
             << "enter -1 to quit " << endl;

        cin >> chose;
        if (chose == 1) {
            cout << "enter num of subjects to add ";
            int x;
            cin >> x;
            subjectController1.addSubjects(x);
        } else if (chose == 2) {
            cout << "enter name of subjects to modify ";
            string x;
            cin >> x;
            subjectController1.modifySubjects(x);
        } else if (chose == 3) {
            cout << "enter name of subjects to delete ";
            string x;
            cin >> x;
            subjectController1.deleteSubjects(x);
        } else if (chose == 4) {
            subjectController1.printSubjects();
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
    std::cout << "Hello, sir " << std::endl<< " enter 1 if you are a student or 2 if you are an admin ,-1 to quit ";
    int option;
    cin >> option;
    SubjectController subjectController1;
    StudentController studentController1;

    vector<SubjectDefinition> AllSubjects;
    vector<Student> studentsResults;
    while(option != -1){
        if(option == 1 ){
            //function student
            if(studentsResults.empty()){
                cout << "please insert students \n enter 1 if you are a student or 2 if you are a admin ,-1 to quit";
                cin >> option;
                continue;
            }
            student(studentsResults);
        }else if (option == 2 ){
            cout << " enter 0 if you are subject controller else for student Controller  " << endl;
            int adminOption;
            cin >> adminOption;
            if(adminOption){

                studentsResults =   studentController(AllSubjects ,studentController1 );

            }else{

                AllSubjects =  subjectController(subjectController1);

            }
        }
        std::cout << "Hello, sir " << std::endl<< " enter 1 if you are an student or 2 if you are an admin ,-1 to quit ";
        cin >> option;
    }
    return 0;
}
