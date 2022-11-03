//
// Created by Guilherme Monteiro on 01/11/2022.
//

#include "Interface.h"

#include <regex>

Interface::Interface()= default;

//using namespace std;
//0
void Interface::welcomePage() {
    cout << endl << "=========WELCOME PAGE=========" << endl;
    cout << endl << "Options:\n\t1-Select files to read\n\t2-Credits\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option: ";
        cin >> input;

        switch (input) {
            case ('1'):
                readFiles();
                return welcomePage();
            case ('2'):
                credits();
                return welcomePage();
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}

//1
void Interface::readFiles() {
    cout << endl << "=========READ FILES=========" << endl;
    cout << endl;
    cout << "Which files do you want to read?" << endl;
    cout << endl << "Options:\n\t1-Default files\n\tb-Back\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option: ";
        cin >> input;
        switch (input) {
            case ('1'):
                d_.readFile_classes("..\\csv\\classes.csv");
                d_.readFile_students_classes("..\\csv\\students_classes.csv");
                mainMenu();
                return readFiles();
                /*case ('2'):
                    customFiles();
                    mainMenu();
                    return readFiles();*/
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void Interface::credits() const {
    cout << endl << "=========CREDITS=========" << endl;
    cout << endl;
    cout << "Made by:" << endl;
    cout << "Carolina Viana, up202108802" << endl;
    cout << "Guilherme Monteiro, up202108668" << endl;
    cout << "Sofia Sa, up202108676" << endl;

    cout << endl << endl << "Options:\n\tb-Back\n\te-Exit"<< endl;
    char input;
    while (true) {
        cout << "Choose option: ";
        cin >> input;

        switch (input) {
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
//1.5
/*void Interface::customFiles() const {
    cout << endl << "=========CUSTOM FILES=========" << endl;
    cout << endl;
    string inp1,inp2,inp3;
    //is the first input really necessary?
    //also, what if the file isn´t correctly read?
    //figure out a way to back from here
    cout << "Please write the path to the desired 'classes.csv' file, or 'd' for the default file: ";
    cin >> inp1;
    //inp1 == "d" ? inp1 = defaultPath1;
    //readfiles1(inp1);
    cout << "Please write the path to the desired 'classes_per_uc.csv' file, or 'd' for the default file: ";
    cin >> inp2;
    //inp2 == "d" ? inp2 = defaultPath2;
    //readfiles2(inp2);
    cout << "Please write the path to the desired 'students_classes.csv' file, or 'd' for the default file: ";
    cin >> inp3;
    //inp3 == "d" ? inp3 = defaultPath3;
    //readfiles3(inp3);
}//WIP -> is it really needed? */

//2
void Interface::mainMenu() const {
    cout << endl << "=========MAIN MENU=========" << endl;
    cout << endl;
    //explain the options
    cout << "Students -> View students info and filter lists of students." << endl;
    cout << "Classes -> View a class's number of students, capacity, and organize them." << endl;
    cout << "Timetables -> View student's/class's/UC's timetables" << endl;
    cout << "Requests -> Create and process requests" << endl;
    cout << endl << "Options:\n\t1-Students\n\t2-Classes\n\t3-Timetables\n\t4-Requests\n\tb-Back\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option: ";
        cin >> input;

        switch (input) {
            case ('1'):
                studentsMenu();
                return mainMenu();
            case ('2'):
                classesMenu();
                return mainMenu();
            case ('3'):
                timetablesMenu();
                return mainMenu();
            case ('4'):
                requestsMenu();
                return mainMenu();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}

//3
void Interface::studentsMenu() const {
    cout << endl << "=========STUDENTS MENU=========" << endl;
    cout << endl;
    cout << endl << "Options:\n\t1-View student's info\n\t2-List students\n\tb-Back\n\tq-Main Menu\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option: ";
        cin >> input;
        switch (input) {
            case ('1'):
                studentsInfo();
                return studentsMenu();
            case ('2'):
                studentsList();
                return studentsMenu();
            case ('b'):
                return;
            case ('q'):
                return quitMenu(); // WIP
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void Interface::classesMenu() const {
//listar alunos numa class, nr
}//TO DO
void Interface::timetablesMenu() const {
    cout << endl << "=========TIMETABLES MENU=========" << endl;
    cout << endl;
    cout << "Select which type of timetable you want to see." << endl;
    cout << endl << "Options:\n\t1-Student\n\t2-UC\n\t3-Class\n\tb-Back\n\tq-Main Menu\n\te-Exit"<<endl;
    char input;
    string ucCode, classCode;
    Student stu;
    int code;
    while (true){
        cout << "Choose option: ";
        cin >> input;

        switch (input) {
            case ('1'):
                cout << endl << "Student's code:";
                cin >> code;
                cout << endl;
                stu = d_.findStudent(code);
                if(stu.get_studentCode() != 0) stu.student_timetable(); //student is real
                lastPage();
                return timetablesMenu();
            case ('2'):
                cout << endl << "Insert UC code ('L.EIC0xx', with 'xx' being from 01 to 25): ";
                cin >> ucCode; cout << endl;
                if(regex_match(ucCode, regex("(L\\.EIC0)((1[0-9])|(2[0-5])|(0[1-9]))"))) {
                    d_.uc_timetable(ucCode);
                    lastPage();
                }
                else {
                    cout << "ERROR: Could not find UC." << endl;
                    lastPage();
                }
                return timetablesMenu();
            case ('3'):
                cout << endl << "Class's code ('yLEICxx', with 'y' being the year and 'xx' the class number):";
                cin >> classCode;
                cout << endl;
                d_.class_timetable(classCode);
                lastPage();
                return timetablesMenu();
            case ('b'):
                return;
            case ('q'):
                return quitMenu(); // WIP
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }

}
void Interface::requestsMenu() const {
    cout << endl << "=========REQUESTS MENU=========" << endl;
    cout << endl;
    cout << endl << "Options:\n\t1-Create Request\n\t2-Process Requests\n\tb-Back\n\tq-Main Menu\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option: ";
        cin >> input;
        switch (input) {
            case ('1'):
                createRMenu();
                return requestsMenu();
            case ('2'):
                processRMenu();
                return requestsMenu();
            case ('b'):
                return;
            case ('q'):
                return quitMenu(); // WIP
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}

//4-students
void Interface::studentsInfo() const {
    cout << endl << "=========STUDENT'S INFO=========" << endl;
    cout << endl;
    cout << "Search student by: " << endl;
    cout << endl << "Options:\n\t1-Code\n\tb-Back\n\tq-Main Menu\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option: ";
        cin >> input;
        //string name;
        int code;
        switch (input) {
            case ('1'):
                cout << endl << "Student's code:";
                cin >> code;
                cout << endl;
                d_.printSInfo(code);
                lastPage();
                return studentsInfo();
            case ('b'):
                return;
            case ('q'):
                return quitMenu(); // WIP
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void Interface::studentsList() const{
    cout << endl << "=========LIST STUDENTS=========" << endl;
    cout << endl;
    cout << "Select the filter you want to apply: " << endl;
    cout << endl << "Options:\n\t1-All students\n\t2-By year\n\t3-By UC\n\t4-By class\n\t5-By nr of UCs\n\tb-Back\n\tq-Main Menu\n\te-Exit"<<endl;
    char input;
    int nr;
    string ucCode, classCode;
    char op;
    bool flag = true;
    list<Student*> l = {};
    UCClass *ucClass;
    while (true){
        cout << "Choose option: ";
        cin >> input;
        switch (input) {
            case ('1'):
                sortMenuSet(d_.get_students());
                return studentsList();
            case ('2'):
                cout << endl << "Insert year: ";
                cin >> nr; cout << endl;
                l = methodsYear(char(nr),d_.get_students());
                sortMenuList(l);
                return studentsList();
            case ('3'):
                cout << endl << "Insert UC code ('L.EIC0xx', with 'xx' being from 01 to 25): ";
                cin >> ucCode; cout << endl;
                if(regex_match(ucCode, regex("(L\\.EIC0)((1[0-9])|(2[0-5])|(0[1-9]))"))) {
                    l = methodsUC(ucCode, d_.get_students());
                    sortMenuList(l);
                }
                else {
                    cout << "ERROR: Could not find UC." << endl;
                    lastPage();
                }
                return studentsList();
            case ('4'):
                cout << endl << "Insert UC code ('L.EIC0xx', with 'xx' being from 01 to 25): ";
                cin >> ucCode; cout << endl;
                if(regex_match(ucCode, regex("(L\\.EIC0)((1[0-9])|(2[0-5])|(0[1-9]))"))){
                    cout << endl << "Insert Class code ('yLEICxx', with 'y' being the year and 'xx' the class number): ";
                    cin >> classCode; cout << endl;
                    auto iter = find_if(d_.get_ucClasses().begin(), d_.get_ucClasses().end(), [ucCode, classCode](
                            UCClass *uc2)->bool {return (uc2->get_ucCode() == ucCode && uc2->get_classCode() == classCode );});     //DOESN'T WORK
                    if(iter != d_.get_ucClasses().end()){
                        ucClass = *iter;
                        l = ucClass->get_students();
                        sortMenuList(l);
                    }
                    else{cout << "ERROR: Could not find Class." << endl;
                        lastPage();}
                }
                else {
                    cout << "ERROR: Could not find UC." << endl;
                    lastPage();
                }
                return studentsList();
            case ('5'):
                cout << endl << "Insert number: ";
                cin >> nr; cout << endl;
                cout << "Equal to('='), More('>') or Less('<') than " << nr << ": ";
                cin >> op; cout << endl;
                switch(op){
                    case ('<'):
                        l = filterLess(nr, d_.get_students());
                        break;
                    case ('>'):
                        l = filterMore(nr, d_.get_students());
                        break;
                    case ('='):
                        l = filterEqual(nr, d_.get_students());
                        break;
                    default:
                        cout << "Operator not recognized. Please choose your filter again"<<endl;
                        flag = false;
                }
                if (flag) {
                    sortMenuList(l);
                }
                return studentsList();
            case ('b'):
                return;
            case ('q'):
                return quitMenu(); // WIP
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }

}//TESTAR -> 1 bug, case 4

//4-requests
void Interface::createRMenu() const {
    cout << endl << "=========CREATE REQUESTS=========" << endl;
    cout << endl;
    cout << endl << "Insert Student's code: ";
    int code;
    cin >> code;
    Student stu = d_.findStudent(code);
    if (stu.get_studentCode() == 0) return createRMenu();
    else {
        cout << "Current classes:" << endl;
        for (UCClass *uc : stu.get_classes()){
            cout << "\t" << uc->get_ucCode() << ", " << uc->get_classCode() << ";" << endl;
        }
        cout << endl << "Select the type of request you want to make: " << endl;
        cout << endl
             << "Options:\n\t1-Remove student from class\n\t2-Add student to class\n\t3-Replace student's classes\n\tb-Back\n\tq-Main Menu\n\te-Exit"
             << endl;
        char input;
        while (true) {
            cout << "Choose option: ";
            cin >> input;
            switch (input) {
                case ('1'):
                    studentsInfo();
                    return createRMenu();
                case ('2'):
                    studentsList();
                    return createRMenu();
                case ('3'):
                    studentsList();
                    return createRMenu();
                case ('b'):
                    return;
                case ('q'):
                    return quitMenu(); // WIP
                case ('e'):
                    return exitProgram();
                default:
                    cout << endl << "Not a valid option" << endl;
            }
        }
    }
}//TO DO
void Interface::processRMenu() const {

}//TO DO

//sorter menus
void Interface::sortMenuList(list<Student*> l) const {
    cout << endl << "=========SORT MENU=========" << endl;
    cout << endl;
    cout << "How do you want to sort the students? " << endl;
    cout << endl << "Options:\n\t1-Alphabetical(A-Z)\n\t2-Alphabetical(Z-A)\n\t3-Code(low to high\n\t4-Code(high to low)\n\t5-Number of UCs(low to high)\n\t6-Number of UCs(high to low)\n\tb-Back\n\tq-Main Menu\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option: ";
        cin >> input;
        switch (input) {
            case ('1'):
                l.sort(l_AlphaA); //alpha1
                printList(l);
                lastPage();
                return sortMenuList(l);
            case ('2'):
                l.sort(l_AlphaZ); //alpha2
                printList(l);
                lastPage();
                return sortMenuList(l);
            case ('3'):
                l.sort(l_Numb); //numb
                printList(l);
                lastPage();
                return sortMenuList(l);
            case ('4'):
                l.sort(l_NumbInv); //numbinv
                printList(l);
                lastPage();
                return sortMenuList(l);
            case ('5'):
                l.sort(l_UC); // <n UCs
                printList(l);
                lastPage();
                return sortMenuList(l);
            case ('6'):
                l.sort(l_UCInv); // >n UCs
                printList(l);
                lastPage();
                return sortMenuList(l);
            case ('b'):
                return;
            case ('q'):
                return quitMenu(); // WIP
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void Interface::sortMenuSet(set<Student*,studentComparatorAlpha1> s) const {
    cout << endl << "=========SORT MENU=========" << endl;
    cout << endl;
    cout << "How do you want to sort the students? " << endl;
    cout << endl << "Options:\n\t1-Alphabetical(A-Z)\n\t2-Alphabetical(Z-A)\n\t3-Code(low to high)\n\t4-Code(high to low)\n\t5-Number of UCs(low to high)\n\t6-Number of UCs(high to low)\n\tb-Back\n\tq-Main Menu\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option: ";
        cin >> input;
        switch (input) {
            case ('1'):
                printSetAlphaA(s);
                lastPage();
                return sortMenuSet(s);
            case ('2'):
                printSetAlphaZ(s_alphaZ(s));
                lastPage();
                return sortMenuSet(s);
            case ('3'):
                printSetNumb(s_numb(s));
                lastPage();
                return sortMenuSet(s);
            case ('4'):
                printSetNumbInv(s_numbInv(s));
                lastPage();
                return sortMenuSet(s);
            case ('5'): //DOESN'T WORK CORRECTLY
                printSetUC(s_UC(s));
                lastPage();
                return sortMenuSet(s);
            case ('6'): //DOESN'T WORK CORRECTLY
                printSetUCInv(s_UCInv(s));
                lastPage();
                return sortMenuSet(s);
            case ('b'):
                return;
            case ('q'):
                return quitMenu(); // WIP
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
} //2 Bugs - case 5 & 6

//extra
void Interface::lastPage() const {
    cout << endl << endl;
    cout << endl << "Options:\n\tb-Back\n\tq-Main Menu\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option: ";
        cin >> input;
        switch (input) {
            case ('b'):
                return;
            case ('q'):
                return quitMenu(); // WIP
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
//general
void Interface::exitProgram() const {
    cout << endl << "Exiting program..." << endl;
    throw 200;
}
void Interface::quitMenu() const {}//WIP -> Actually work ain't even started
//utils
/*
void Interface::print(list<int> l) const{
    for (auto i: l){
        cout << i <<endl;
    }
}*/
