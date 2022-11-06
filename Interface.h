#ifndef AED_PROJECT1_INTERFACE_H
#define AED_PROJECT1_INTERFACE_H

#include "Filters.h"


class Interface {

public:
    Data d_;

    Interface();
    void setData(Data d){d_ = d;}
    //0
    void welcomePage();
    //1
    void readFiles();
    void credits() const;

    //2
    void mainMenu();
    //3
    void studentsMenu() const;
    void timetablesMenu() const;
    void requestsMenu() ;
    //4-students
    void studentsInfo() const;
    void studentsList() const;
    //4-classes

    //4-timetables

    //4-requests
    void createRMenu() ;
    void processRMenu() ;
    //extra
    void lastPage() const;

    //sorter menu
    void sortMenuList(list<Student*> l) const;
    void sortMenuSet(set<Student*,studentComparatorAlpha1> s) const;
    //general
    void exitProgram() const;
    //utils
    vector<UCClass*> createVec() const;

};


#endif //AED_PROJECT1_INTERFACE_H
