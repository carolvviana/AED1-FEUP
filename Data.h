#ifndef AED_PROJECT1_DATA_H
#define AED_PROJECT1_DATA_H

#include <vector>
#include <set>
#include <queue>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "UCClass.h"
#include "Student.h"
#include "Lecture.h"
#include "Request.h"

using namespace std;

struct studentComparator {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode()) return (s1->get_studentName() < s2->get_studentName());
        return false;
    }
};

/*
struct ucClassComparator {
    bool operator()(UCClass *c1, UCClass *c2)
};
*/

class Data{
private:
    set<Student* , studentComparator> students_;
    vector<UCClass*> ucClasses_;
    queue<Request*> requests_;//como vai ser o request? pedidos únicos ou pode querer trocar várias aulas ao mm tempo
public:

    //getters
    set<Student *, studentComparator> get_students();
    vector<UCClass*> get_ucClasses();
    queue<Request*> get_requests();


    //auxiliary methods
    void add_ucClasses(UCClass* p);
    void add_student(Student student);

    //file reading methods
    void readFile(); //tem varios ifs e pergunta ao utilizador qual os ficheiros que queremos ler. consoante isso, chama diferentes funções
    void readFile_classes(string fname);
    void readFile_classes_per_uc(string fname);
    void readFile_students_classes(string fname);

    //request methods;
    void guardarPedidos();
    void processRequests();

};




#endif //AED_PROJECT1_CLASS_H
