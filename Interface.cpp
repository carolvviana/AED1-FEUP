//
// Created by Guilherme Monteiro on 01/11/2022.
//

#include "Interface.h"
Interface::Interface()= default;

//0
void Interface::welcomePage() {
    cout << endl << "=========WELCOME PAGE=========" << endl;
    cout << endl << "Options:   1-Select files to read\t2-Credits\te-Exit"<<endl;
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
    cout << endl << "Options:   1-Default files\tb-Back\te-Exit"<<endl;
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
}//WIP -> Read files
void Interface::credits() const {
    cout << endl << "=========CREDITS=========" << endl;
    cout << endl;
    cout << "Made by:" << endl;
    cout << "Carolina Viana, up202108802" << endl;
    cout << "Guilherme Monteiro, up202108668" << endl;
    cout << "Sofia Sá, up202108676" << endl;

    cout << endl << endl << "Options:   b-Back\te-Exit"<< endl;
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
    cout << endl << "Options:   1-Students\t2-Classes\t3-Timetables\t4-Requests\tb-Back\te-Exit"<<endl;
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
}//WIP -> Explicar opções

//3
void Interface::studentsMenu() const {
    cout << endl << "=========STUDENTS MENU=========" << endl;
    cout << endl;
    cout << endl << "Options:   1-View student's info\t2-List students\tb-Back\tq-Main Menu\te-Exit"<<endl;
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

}//TO DO
void Interface::requestsMenu() const {
    cout << endl << "=========REQUESTS MENU=========" << endl;
    cout << endl;
    cout << endl << "Options:   1-Create Request\t2-Process Requests\tb-Back\tq-Main Menu\te-Exit"<<endl;
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
    cout << endl << "=========STUDENTS INFO=========" << endl;
    cout << endl;
    cout << "Search student by: " << endl;
    cout << endl << "Options:   1-Code\tb-Back\tq-Main Menu\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option: ";
        cin >> input;
        string name;
        int code;
        switch (input) {
            case ('1'):
                cout << endl << "Student's code: ";
                cin >> code;
                //search student and show info
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

}//WIP
void Interface::studentsList() const{
    cout << endl << "=========LIST STUDENTS=========" << endl;
    cout << endl;
    cout << "Select the filter you want to apply: " << endl;
    cout << endl << "Options:   1-All students\t2-By year\t3-By UC\t4-By class\t5-By nr of UCs\tb-Back\tq-Main Menu\te-Exit"<<endl;
    char input;
    int nr; //alterar para char?
    string ucClass;
    char op;
    bool flag = true;
    //list<int> l = {1,2,3};
    while (true){
        cout << "Choose option: ";
        cin >> input;
        switch (input) {
            case ('1'):
                //get set
                //sortMenuSet(s);
                //TO DO
                return studentsList();
            case ('2'):
                cout << endl << "Insert year: ";
                cin >> nr; cout << endl;
                //get list(nr)
                //sortMenuList(l);
                //TO DO
                return studentsList();
            case ('3'):
                cout << endl << "Insert UC number: ";
                cin >> nr; cout << endl;
                //get list(nr
                //sortMenuList(l);
                //TO DO
                return studentsList();
            case ('4'):
                cout << endl <<"Example:" << endl << "UCCode ClassCode" << endl;
                cout << "Insert 'UCCode' and 'ClassCode', like in the example " << endl; //tentar REGEX
                cin >> ucClass; cout << endl;
                //get list(ucClass);
                //sortMenuList(l);
                //TO DO
                return studentsList();
            case ('5'):
                cout << endl << "Insert number: ";
                cin >> nr; cout << endl;
                cout << "Equal to('='), More('>') or Less('<') than your number: ";
                cin >> op; cout << endl;
                switch(op){
                    case ('<'):
                        //get list(nr)
                        break;
                    case ('>'):
                        //get list(nr)
                        break;
                    case ('='):
                        //get list(nr)
                        break;
                    default:
                        cout << "Operator not recognized. Please choose your filter again"<<endl;
                        flag = false;
                }
                if (flag) {
                    //sortMenuList(l);
                    //TO DO
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

}//WIP -> Implementar funções, PASSAR PARA REGEX

//4-requests
void Interface::createRMenu() const {
    cout << endl << "=========CREATE REQUESTS=========" << endl;
    cout << endl;
    cout << endl << "Select the type of request you want to make: " << endl;
    cout << endl << "Options:   1-Remove student from class\t2-Add student to class\t3-replace student's classes\tb-Back\tq-Main Menu\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option: ";
        cin >> input;
        switch (input) {
            case ('1'):
                studentsInfo();
                return requestsMenu();
            case ('2'):
                studentsList();
                return requestsMenu();
            case ('3'):
                studentsList();
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
}//TO DO
void Interface::processRMenu() const {

}//TO DO

//sorter menus
void Interface::sortMenuList(list<int> l) const {
    cout << endl << "=========SORT MENU=========" << endl;
    cout << endl;
    cout << "How do you want to sort the students? " << endl;
    cout << endl << "Options:   1-Alphabetical(A-Z)\t2-Alphabetical(Z-A)\t3-Code(low to high\t4-Code(high to low)\tb-Back\tq-Main Menu\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option: ";
        cin >> input;
        switch (input) {
            case ('1'):
                l.sort(); //alpha1
                print(l);
                lastPage();
                return sortMenuList(l);
            case ('2'):
                l.sort(); //alpha2
                //print(l);
                lastPage();
                return sortMenuList(l);
            case ('3'):
                l.sort(); //numb
                //print(l);
                lastPage();
                return sortMenuList(l);
            case ('4'):
                l.sort(); //numbinv
                //print(l);
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
}//WIP -> Aplicar sorters e Prints.
void Interface::sortMenuSet(set<int> s) const {
    cout << endl << "=========SORT MENU=========" << endl;
    cout << endl;
    cout << "How do you want to sort the students? " << endl;
    cout << endl << "Options:   1-Alphabetical(A-Z)\t2-Alphabetical(Z-A)\t3-Code(low to high\t4-Code(high to low)\tb-Back\tq-Main Menu\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option: ";
        cin >> input;
        switch (input) {
            case ('1'):
                //print(s); //alpha1
                lastPage();
                return sortMenuSet(s);
            case ('2'):
                //alphaZ(s); //alpha2
                //print(s);
                lastPage();
                return sortMenuSet(s);
            case ('3'):
                //numb(s); //numb
                //print(s);
                lastPage();
                return sortMenuSet(s);
            case ('4'):
                //numbInv(s); //numbinv
                //print(s);
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
}//WIP -> Aplicar sorters e Prints.

//extra
void Interface::lastPage() const {
    cout << endl << endl;
    cout << endl << "Options:   b-Back\tq-Main Menu\te-Exit"<<endl;
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
} //REVISION VERY NECESSARY
void Interface::quitMenu() const {}//WIP -> Actually work ain't even started
//utils
void Interface::print(list<int> l) const{
    for (auto i: l){
        cout << i <<endl;
    }
}
