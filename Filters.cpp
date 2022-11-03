#ifndef AED_PROJECT1_FILTERS_CPP
#define AED_PROJECT1_FILTERS_CPP

#include "Filters.h"
//LISTAGENS DE ESTUDANTES
 //=================TO BE CHECKED, após interface e atenção à Data d que as funcs recebem

//os counter podem ser só sizes da lista...
//por isso os métodos podem criar só as listas


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
                break;
            }
        }
    }
    return lista;
}

/**
 * Função retorna a lista de estudantes de uma determinada cadeira (uc) bem como o número de estudantes dessa cadeira.
 *
 * COMPLEXIDADE: O(n^2). //o segundo n é só 5...
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

// função pra filtrar estudantes por numeros de UCs menor que n, maior, igual
/**
 * Função retorna a lista de estudantes com menos de N UCs.
 *
 * COMPLEXIDADE: O(n).
 */
list<Student*> filterLess(int n, set<Student*,studentComparatorAlpha1> s){
    list<Student*> lista = {};
    for (Student* stu : s){
        if (stu->get_classes().size()<n){
            lista.push_back(stu);
        }
    }
    return lista;
}
/**
 * Função retorna a lista de estudantes com mais de N UCs.
 *
 * COMPLEXIDADE: O(n).
 */
list<Student*> filterMore(int n, set<Student*,studentComparatorAlpha1> s){
    list<Student*> lista = {};
    for (Student* stu : s){
        if (stu->get_classes().size()>n){
            lista.push_back(stu);
        }
    }
    return lista;
}

/**
 * Função retorna a lista de estudantes com N UCs.
 *
 * COMPLEXIDADE: O(n).
 */
list<Student*> filterEqual(int n, set<Student*,studentComparatorAlpha1> s){
    list<Student*> lista = {};
    for (Student* stu : s){
        if (stu->get_classes().size()==n){
            lista.push_back(stu);
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

//COUNTERS: probably sao desnecessarios pq basta fazer methods.size(), etc...
/**
 * Função retorna o número de estudantes com menos de N UCs.
 *
 * COMPLEXIDADE: O(1).
 */
int counterFilterLess(int n, set<Student*,studentComparatorAlpha1> s){
    return filterLess(n, s).size();
}
/**
 * Função retorna o número de estudantes com mais de N UCs.
 *
 * COMPLEXIDADE: O(1).
 */
int counterFilterMore(int n, set<Student*,studentComparatorAlpha1> s){
    return filterMore(n, s).size();
}
/**
 * Função retorna o número de estudantes com N UCs.
 *
 * COMPLEXIDADE: O(1).
 */
int counterFilterEqual(int n, set<Student*,studentComparatorAlpha1> s){
    return filterEqual(n , s).size();
}

/**
 * Função dá output ao utilizador de uma determinada lista de estudantes.
 *
 * COMPLEXIDADE: O(n).
 */
//PRINTS ÀS LISTAS
void printList(list<Student*> lista){
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }

    cout << "\n\nNumber of students: " << lista.size() << endl;
}
/*
void printTurma (list<Student*> lista){
    cout << "Students in the class:" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
}

void printYear ( list<Student*> lista){
    cout << "Students in year:" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
}

void printUC (list<Student*> lista){
    cout << "Students in the UC:" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
}

void printFilterLess (list<Student*> lista){
    cout << "Students with less than the number of UCs you picked:" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
}

void printFilterMore (list<Student*> lista){
    cout << "Students with more than the number of UCs you picked:" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
}

void printFilterEqual (list<Student*> lista){
    cout << "Students with the number of classes you picked:" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
}
*/

/**
 * Função dá output ao utilizador de uma lista de estudantes ordenada alfabeticamente.
 *
 * COMPLEXIDADE: O(n).
 */
//prints aos sets
void printSetAlphaA(set<Student *, studentComparatorAlpha1> s){
    for (Student* stu : s){
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
    cout << "\n\nNumber of students: " << s.size() << endl;

}

/**
 * Função dá output ao utilizador de uma lista de estudantes ordenada pelo inverso da ordem alfabética.
 *
 * COMPLEXIDADE: O(n).
 */
void printSetAlphaZ(set<Student *, studentComparatorAlpha2> s){
    for (Student* stu : s){
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
    cout << "\n\nNumber of students: " << s.size() << endl;
}
/**
 * Função dá output ao utilizador de uma lista de estudantes ordenada por número de estudante crescente.
 *
 * COMPLEXIDADE: O(n).
 */
void printSetNumb(set<Student *, studentCodeComparator> s){
    for (Student* stu : s){
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
    cout << "\n\nNumber of students: " << s.size() << endl;
}

/**
 * Função dá output ao utilizador de uma lista de estudantes ordenada por número de estudante decrescente.
 *
 * COMPLEXIDADE: O(n).
 */
void printSetNumbInv(set<Student *, studentCodeComparatorInv> s){
    for (Student* stu : s){
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
    cout << "\n\nNumber of students: " << s.size() << endl;
}
/**
 * Função dá output ao utilizador de uma lista de estudantes ordenada por número de UCs crescente.
 *
 * COMPLEXIDADE: O(n).
 */
void printSetUC(set<Student* , studentComparatorUC> s){
    for (Student* stu : s){
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ", " << stu->get_classes().size() << ";" << endl;
    }
    cout << "\n\nNumber of students: " << s.size() << endl;
}

/**
 * Função dá output ao utilizador de uma lista de estudantes ordenada por número de UCs decrescente.
 *
 * COMPLEXIDADE: O(n).
 */
void printSetUCInv(set<Student* , studentComparatorUCInv> s){
    for (Student* stu : s){
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ", " << stu->get_classes().size() << ";" << endl;
    }
    cout << "\n\nNumber of students: " << s.size() << endl;
}

#endif //AED_PROJECT1_FILTERS_CPP