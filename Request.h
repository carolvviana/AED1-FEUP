//
// Created by carol on 18/10/2022.
//

#ifndef AED_PROJECT1_REQUEST_H
#define AED_PROJECT1_REQUEST_H

#include "UCClass.h"
#include "Student.h"


class Request{

private:
    Student* student_;
    vector<UCClass*> class_ogs_;
    vector<UCClass*> class_finals_;
    bool approved_;


public:
    //constructors
    Request();
    Request(Student* student, vector<UCClass*> class_ogs, vector<UCClass*> class_finals);

    //setters
    void set_student(Student* student);
    void set_class_og(vector<UCClass*> class_og);
    void set_class_final(vector<UCClass*> class_final);
    void set_approved(bool value);

    //getters
    Student* get_student();
    vector<UCClass*> get_class_og();
    vector<UCClass*> get_class_final();
    bool get_approved();
};

#endif //AED_PROJECT1_REQUEST_H
