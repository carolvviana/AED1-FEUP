//
// Created by carol on 18/10/2022.
//

#ifndef AED_PROJECT1_REQUEST_H
#define AED_PROJECT1_REQUEST_H

#include "UCClass.h"
#include "Student.h"


class Request{

private:
    Student student_;
    UCClass class_og_;
    UCClass class_final_;


public:
    //constructors
    Request();
    Request(Student student, UCClass class_og, UCClass class_final);

    //setters
    void set_student(Student student);
    void set_class_og(UCClass class_og);
    void set_class_final(UCClass class_final);


    //getters
    Student get_student();
    UCClass get_class_og();
    UCClass get_class_final();

};

#endif //AED_PROJECT1_REQUEST_H
