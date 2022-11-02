
//#include "Data.h"
#include "Interface.h"
using namespace std;
int main() {
    Data d = Data();
    Interface iFace = Interface();
    iFace.setData(d);

    try {
        iFace.welcomePage();
    }
    catch (int exit) {
        return 0;
    }

    return 0;
}
   //d.readFile_classes_per_uc("C:\\Users\\carol\\AEDP1\\AED-Project1_v2\\AED-Project1.v2\\csv\\classes_per_uc.csv");
    //d.readFile_classes("..\\csv\\classes.csv");

/*

    for ( int i= 0; i < d.get_ucClasses().size(); i++){
        cout << d.get_ucClasses()[i]->get_ucCode() << ',' << d.get_ucClasses()[i]->get_classCode() << endl;
        for (auto lecture : d.get_ucClasses()[i]->get_lectures()){
            cout << lecture->get_weekDay() << ',' << lecture->get_startHour() << ',' << lecture->get_duration() << ',' << lecture->get_type() << ',' << endl;
    }
         }


//d.readFile_students_classes("..\\csv\\students_classes.csv");
/*
    for (auto student : d.get_students()){
   cout << student->get_studentName() << ',' << student->get_studentCode() << ',';
   for (auto ucclass : student->get_classes()){
   cout << ucclass.get_classCode() << ',' << ucclass.get_ucCode() << "| ";
   }
   cout << endl;
}
 *//*
    set<Student* , studentComparatorAlpha2> aux = alphaZ(d);
    for (auto student : aux) {
        cout << student->get_studentName() << ',' << student->get_studentCode() << endl;
    }
    set<Student* , studentCodeComparator> auxi = numb(d);
    for (auto student : auxi) {
        cout << student->get_studentName() << ',' << student->get_studentCode() << endl;
    }
    set<Student* , studentCodeComparatorInv> auxil = numbInv(d);
    for (auto student : auxil) {
        cout << student->get_studentName() << ',' << student->get_studentCode() << endl;
    }
    */
/*
    cout << "===========TENTATIVA DA SOFIA E GUI:" << endl;
    UCClass* ucclass = d.get_ucClasses()[0];
    for (Student* student : ucclass->get_students()) {
        cout << student->get_studentName() << endl;
    }

    cout << "=========COUNTER TURMA: (funciona)" << endl << counterTurma(*ucclass) << endl;

    cout <<"==========COUNTER YEAR: (funciona)" << endl << counterYear(1, d);*/

    /* for (Student *s : d.get_students()){
        s->student_timetable();
    }*/
    /*
    d.class_timetable("1LEIC08");
    set<Student*,studentComparatorAlpha1> s = d.get_students();
    string uc = d.get_ucClasses()[0]->get_ucCode();

    cout <<"==========COUNTER UC: " << endl << counterUC(uc, s) << endl;
    //cout <<"==========PRINT UC: " << endl; printUC(uc, s);

    return 0;
 */
