
#include "UCClass.h"
#include "Student.h"
#include <tuple>
#include <algorithm>
#include <string>

using namespace std;

UCClass :: UCClass(){ucCode_ = "x"; classCode_ = 'y';}
UCClass :: UCClass(string ucCode, string classCode){ucCode_ = ucCode; classCode_=classCode;}

void UCClass :: set_ucCode(string ucCode){ucCode_ = ucCode;}
void UCClass :: set_classCode(string classCode){classCode_ = classCode;}

/**
 * Função adiciona um objeto do tipo Lecture ao vetor de pointers para objetos de Lectures.
 *
 * COMPLEXIDADE: O(1).
 * @param lecture pointer para objeto do tipo Lecture a ser adicionado ao vector de pointers para objetos Lecture
 */
void UCClass ::add_lecture(Lecture *lecture) {lectures_.push_back(lecture);}
/**
 * Função adiciona um objeto do tipo Student à lista de pointers para objetos de Students.
 *
 * COMPLEXIDADE: O(1).
 * @param ucClass pointer para objeto do tipo Student a ser adicionado à lista de pointers para objetos Student
 */
void UCClass::add_student(Student* student){students_.push_back(student);}

string UCClass :: get_ucCode(){return ucCode_;}
string UCClass :: get_classCode(){return classCode_;}
vector<Lecture*> UCClass ::get_lectures() {return lectures_;}
list<Student*> UCClass::get_students(){return students_;}

bool UCClass :: operator==(const UCClass& ucc) const{
    return (ucCode_ == ucc.ucCode_ && classCode_ == ucc.classCode_);
}

/**
 * Função remove um objeto do tipo Student à lista de pointers para objetos de Students, caso esteja presente.
 *
 * COMPLEXIDADE: O(n).
 * @param uc pointer para objeto do tipo Student a ser removido da lista de pointers para objetos Student
 */
void UCClass :: remo(Student* s){
    auto it = find_if(students_.begin(),students_.end(),[s] (Student* st){ return s->get_studentCode() == st->get_studentCode();});
    students_.erase(it);
}
