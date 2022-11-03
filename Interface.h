//
// Created by Guilherme Monteiro on 01/11/2022.
//

#ifndef AED_PROJECT1_INTERFACE_H
#define AED_PROJECT1_INTERFACE_H

//#include "Data.h"
//#include "SortStudents.cpp"
#include "Filters.h"
//#include "Timetables.cpp"

class Interface {

public:
    Data d_;

    Interface();
    void setData(Data d){d_ = d;}
    //Data getData(){return d;}
    //0
    void welcomePage();
    //1
    void readFiles() ;
    void credits() const;
    //1.5
    // void customFiles() const;
    //2
    void mainMenu() const;
    //3
    void studentsMenu() const;
    void classesMenu() const;
    void timetablesMenu() const;
    void requestsMenu()  const;
    //4-students
    void studentsInfo() const;
    void studentsList() const;
    //4-classes

    //4-timetables

    //4-requests
    void createRMenu() const;
    void processRMenu() const;
    //extra
    void lastPage() const;

    //sorter menu
    void sortMenuList(list<Student*> l) const;
    void sortMenuSet(set<Student*,studentComparatorAlpha1> s) const;
    //general
    void exitProgram() const;
    void quitMenu() const;
    //utils


};


#endif //AED_PROJECT1_INTERFACE_H
