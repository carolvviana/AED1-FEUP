#ifndef AED_PROJECT1_DATA_H
#define AED_PROJECT1_DATA_H

#include <vector>
#include <set>
#include <queue>
#include <tuple>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "UCClass.h"
#include "Student.h"
#include "Lecture.h"
#include "Request.h"


using namespace std;

struct studentComparatorAlpha1 {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode()) return (s1->get_studentName() < s2->get_studentName());
        return false;
    }
};

class Data{
private:
    set<Student* , studentComparatorAlpha1> students_;
    vector<UCClass*> ucClasses_;
    queue<Request*> requests_;
    vector<Request*> archive_;

public:
    //getters
    set<Student *, studentComparatorAlpha1> get_students() const;
    vector<UCClass*> get_ucClasses() const;
    queue<Request*> get_requests() const;
    vector<Request*> get_archive() const;

    //auxiliary methods
    void printSInfo(int code) const;
    Student * findStudent(int code) const;
    //file reading methods

    void readFile_classes(string fname);
    void readFile_students_classes(string fname);
    void file_writer(string fname) const;

    //request methods;
    void saveRequests(Student* student, vector<UCClass*> og, vector<UCClass*> final);
    void processRequests();


    void uc_timetable(string uccode) const;
    void class_timetable(string classcode) const;

    void data_pop();
    void clear_archive();
};




#endif //AED_PROJECT1_CLASS_H
