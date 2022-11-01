#ifndef AED_PROJECT1_COUNTERS_CPP
#define AED_PROJECT1_COUNTERS_CPP
#include "Data.h"

//LISTAGENS DE ESTUDANTES
 //=================TO BE CHECKED, após interface e atenção à Data d que as funcs recebem

//os counter podem ser só sizes da lista...
//por isso os métodos podem criar só as listas


/**
 * Função retorna a lista de estudantes de uma determinada turma (ucC) bem como o número de estudantes nessa turma.
 *
 * COMPLEXIDADE: O(1).
 */
//ELIMINADA

/**
 * Função retorna a lista de estudantes de um determinado ano (number) bem como o número de estudantes nesse ano.
 *
 * COMPLEXIDADE: O(n^2).
 */
list<Student*> methodsYear(char number, set<Student*,studentComparatorAlpha1> s){
    list<Student*> lista = {};
    number+=48;
    for (Student* stu : s){
        for(UCClass *ucClass :stu->get_classes()){
            if(ucClass->get_classCode()[0] == number) {
                lista.push_back(stu);
            }
        }
    }
    return lista;
}

/**
 * Função retorna a lista de estudantes de uma determinada cadeira (uc) bem como o número de estudantes dessa cadeira.
 *
 * COMPLEXIDADE: O(n^2).
 */
list<Student*> methodsUC(string uc, set<Student*,studentComparatorAlpha1> s){
    list<Student*> lista = {};
    for (Student* stu : s){
        for(UCClass *ucClass :stu->get_classes()){
            if(ucClass->get_ucCode() == uc) {
                lista.push_back(stu);
            }
        }
    }
    return lista;
}

//CONTAGENS DE ESTUDANTES

// #1 retorna numero de pessoas numa certa turma
/**
 * Função retorna o número de estudantes de uma determinada turma (ucC).
 *
 * COMPLEXIDADE: O(1).
 */
int counterTurma(UCClass ucC){
    return ucC.get_students().size();
}

// #2 numero de estudantes num certo ano
/**
 * Função retorna o número de estudantes de um determinado ano (number).
 *
 * COMPLEXIDADE: O(1).
 */
int counterYear(char number, set<Student*, studentComparatorAlpha1> s){
    return methodsYear(number, s).size();
}

// #3 numero de estudantes numa certa UC
/**
 * Função retorna o número de estudantes de uma determinada UC (uc).
 *
 * COMPLEXIDADE: O(1).
 */
int counterUC(string uc, set<Student*,studentComparatorAlpha1> s){
    return methodsUC(uc, s).size();
}

//PRINTS ÀS LISTAS

void printTurma (list<Student*> lista){
    cout << "Students in the class:" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ";" << endl;
    }

}

void printYear ( list<Student*> lista){
    cout << "Students in year:" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ";" << endl;
    }
}


void printUC (list<Student*> lista){
    cout << "Students in the UC:" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ";" << endl;
    }
}

// função pra filtrar estudantes por numeros de UCs menor que n, maior, igual

list<Student*> filterLess(int n, set<Student*,studentComparatorAlpha1> s){
    list<Student*> lista = {};
    for (Student* stu : s){
        if (stu->get_classes().size()<n){
            lista.push_back(stu);
        }
    }
    return lista;
}

list<Student*> filterMore(int n, set<Student*,studentComparatorAlpha1> s){
    list<Student*> lista = {};
    for (Student* stu : s){
        if (stu->get_classes().size()>n){
            lista.push_back(stu);
        }
    }
    return lista;
}

list<Student*> filterEqual(int n, set<Student*,studentComparatorAlpha1> s){
    list<Student*> lista = {};
    for (Student* stu : s){
        if (stu->get_classes().size()==n){
            lista.push_back(stu);
        }
    }
    return lista;
}

//COUNTERS: probably sao desnecessarios pq basta fazer methods.size(), etc...
int counterFilterLess(int n, set<Student*,studentComparatorAlpha1> s){
    return filterLess(n, s).size();
}

int counterFilterMore(int n, set<Student*,studentComparatorAlpha1> s){
    return filterMore(n, s).size();
}

int counterFilterEqual(int n, set<Student*,studentComparatorAlpha1> s){
    return filterEqual(n , s).size();
}

void printFilterLess (list<Student*> lista){
    cout << "Students with less than the number of UCs you picked:" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ";" << endl;
    }
}

void printFilterMore (list<Student*> lista){
    cout << "Students with more than the number of UCs you picked:" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ";" << endl;
    }
}

void printFilterEqual (list<Student*> lista){
    cout << "Students with the number of classes you picked:" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ";" << endl;
    }
}
#endif //AED_PROJECT1_COUNTERS_CPP