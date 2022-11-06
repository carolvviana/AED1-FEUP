
#ifndef AED_PROJECT1_UCCLASS_H
#define AED_PROJECT1_UCCLASS_H

#include <vector>
#include <list>
#include <iostream>
#include "Lecture.h"



using namespace std;

class Student;

class UCClass{ //turma
private:
    string ucCode_;
    string classCode_;
    vector<Lecture*> lectures_;
    list<Student*> students_;

public:
    //constructors
    UCClass();
    UCClass(string ucCode, string classCode);

    //setters
    void set_ucCode(string ucCode);
    void set_classCode(string classCode);

    //adders
    void add_lecture(Lecture* lecture);
    void add_student(Student* student);

    //getters
    string get_ucCode();
    string get_classCode();
    vector<Lecture*> get_lectures(); //pair
    list<Student*> get_students();

    //overloads
    bool operator== (const UCClass& ucc) const;
    void remo(Student* s);
};




#endif //AED_PROJECT1_UCCLASS_H
