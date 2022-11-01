#include "Request.h"


//constructors
Request::Request(Student* student, vector<UCClass*> class_ogs, vector<UCClass*> class_finals) : student_(student), class_ogs_(class_ogs), class_finals_(class_finals){}

//setters
void Request::set_student(Student* student){student_ = student;}
void Request::set_class_og(vector<UCClass*> class_og){class_ogs_=class_og;}
void Request::set_class_final(vector<UCClass*> class_final){class_finals_=class_final;}


//getters
Student* Request::get_student(){return student_;};
vector<UCClass*> Request::get_class_og(){return class_ogs_;}
vector<UCClass*> Request::get_class_final(){return class_finals_;}


