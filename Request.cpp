#include "Request.h"


//constructors

Request::Request(Student student, UCClass class_og, UCClass class_final) : student_(student), class_og_(class_og), class_final_(class_final){}

//setters
void Request::set_student(Student student){student_ = student;}
void Request::set_class_og(UCClass class_og){class_og_=class_og;}
void Request::set_class_final(UCClass class_final){class_final_=class_final_;}

//getters
Student Request::get_student(){return student_;};
UCClass Request::get_class_og(){return class_og_;}
UCClass Request::get_class_final(){return class_final_;}
