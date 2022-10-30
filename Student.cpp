#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>
#include "Student.h"
#include "UCClass.h"

using namespace std;

Student :: Student(){studentName_ = ""; studentCode_ = 0;}
Student :: Student(string studentName, int studentCode){studentName_ = studentName; studentCode_ = studentCode;}
// Student :: Student(string studentName, int studentCode, list<UCClass> turma){studentName_ = studentName; studentCode_ = studentCode; classes_ = turma;}
Student :: Student(const Student& student){studentName_ = student.studentName_; studentCode_ = student.studentCode_;}

void Student :: set_studentName(string studentName){studentName_ = studentName;}
void Student :: set_studentCode(int studentCode){studentCode_ = studentCode;}

void Student ::add_class(UCClass* ucClass) {classes_.push_back(ucClass);}

string Student :: get_studentName(){return studentName_;}
int Student :: get_studentCode(){return studentCode_;}
vector<UCClass*> Student :: get_classes(){return classes_;};

struct sorted_vector{
    bool operator()(tuple<string,Lecture> t1, tuple<string,Lecture> t2){
        if (get<1>(t1).get_startHour() < get<1>(t2).get_startHour()) return true;
        return false;
    }
};
void Student :: cout_tt (vector<tuple<string,Lecture>> t1){
    for (tuple<string,Lecture> t: t1){
        cout << get<1>(t).get_startHour()<< " | " << get<0>(t) << " | " << get<1>(t).get_type() << endl;
    }
}

void Student :: student_timetable(){
    vector<tuple<string,Lecture>> monday;
    vector<tuple<string,Lecture>> tuesday;
    vector<tuple<string,Lecture>> wednesday;
    vector<tuple<string,Lecture>> thursday;
    vector<tuple<string,Lecture>> friday;
    for (UCClass* uc: classes_) {
        for (Lecture *lec: uc->get_lectures()){
            tuple<string,Lecture> par(uc->get_ucCode(), *lec);
            if (lec->get_weekDay() == "Monday") monday.push_back(par);
            if (lec->get_weekDay() == "Tuesday") tuesday.push_back(par);
            if (lec->get_weekDay() == "Wednesday") wednesday.push_back(par);
            if (lec->get_weekDay() == "Thursday") thursday.push_back(par);
            if (lec->get_weekDay() == "Friday") friday.push_back(par);
        }
    }
    sort(monday.begin(), monday.end(), sorted_vector());
    sort(tuesday.begin(), tuesday.end(), sorted_vector());
    sort(wednesday.begin(), wednesday.end(), sorted_vector());
    sort(thursday.begin(), thursday.end(), sorted_vector());
    sort(friday.begin(), friday.end(), sorted_vector());

    cout << "MONDAY" << endl;
    cout_tt (monday);
    cout << '\n';
    cout << "TUESDAY" << endl;
    cout_tt (tuesday);
    cout << '\n';
    cout << "WEDNESDAY" << endl;
    cout_tt (wednesday);
    cout << '\n';
    cout << "THURSDAY" << endl;
    cout_tt (thursday);
    cout << '\n';
    cout << "FRIDAY" << endl;
    cout_tt (friday);
    cout << '\n';

// SE HOUVER TEMPO, CONVERTER HORAS E COLOCAR HORA FINAL NO HORARIO
}