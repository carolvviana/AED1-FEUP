
#include "UCClass.h"
#include "Student.h"
#include <tuple>
#include <string>

using namespace std;

UCClass :: UCClass(){ucCode_ = "x"; classCode_ = 'y';}
UCClass :: UCClass(string ucCode, string classCode){ucCode_ = ucCode; classCode_=classCode;}

void UCClass :: set_ucCode(string ucCode){ucCode_ = ucCode;}
void UCClass :: set_classCode(string classCode){classCode_ = classCode;}

void UCClass ::add_lecture(Lecture *lecture) {lectures_.push_back(lecture);}
void UCClass::add_student(Student* student){students_.push_back(student);}

string UCClass :: get_ucCode(){return ucCode_;}
string UCClass :: get_classCode(){return classCode_;}
vector<Lecture*> UCClass ::get_lectures() {return lectures_;}
list<Student*> UCClass::get_students(){return students_;}

bool UCClass :: operator==(const UCClass& ucc) const{
    return (ucCode_ == ucc.ucCode_ && classCode_ == ucc.classCode_);
}


