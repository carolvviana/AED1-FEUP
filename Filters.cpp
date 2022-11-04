#ifndef AED_PROJECT1_FILTERS_CPP
#define AED_PROJECT1_FILTERS_CPP

#include "Filters.h"


/**
 * Fornece uma lista de pointers para objetos do tipo Student de um determinado ano, recebido como parâmetro.
 *
 * COMPLEXIDADE: O(n^2).
 * @param number char que indica o ano em que os estudantes filtrados estarão
 * @param s set default pointers para objetos do tipo Student (ordenados alfabeticamente)
 * @return lista de pointers para objetos do tipo Student no ano recebido como parametro
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
 * Fornece uma lista de pointers para objetos do tipo Student de uma determinada cadeira, recebida como parametro
 *
 * COMPLEXIDADE: O(n^2).
 * @param uc uma string que indica a cadeira em que os estudantes filtrados estarão inscritos
 * @param s set default de pointers para objetos do tipo Student (ordenados alfabeticamente)
 * @return lista de pointers para objetos do tipo Student na cadeira recebida como parametro
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

/**
 * Função retorna a lista de pointers para objetos do tipo Student com menos de n UCs.
 *
 * COMPLEXIDADE: O(n).
 * @param n um int que indica o numero de UCs e os estudantes filtrados terão menos do que esse numero de UCs
 * @param s set default de pointers para objetos do tipo Student (ordenados alfabeticamente)
 * @return lista de pointers para objetos do tipo Student com menos de n UCs
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
 * Função retorna a lista de estudantes com mais de n UCs.
 *
 * COMPLEXIDADE: O(n).
 * @param n um int que indica o numero de UCs e os estudantes filtrados terão mais do que esse numero de UCs
 * @param s set default de pointers para objetos do tipo Student (ordenados alfabeticamente)
 * @return lista de pointers para objetos do tipo Student com mais de n UCs
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
 * Função retorna a lista de estudantes com n UCs.
 *
 * COMPLEXIDADE: O(n).
 * @param n um int que indica o numero de UCs e os estudantes filtrados terão esse numero de UCs
 * @param s set default de pointers para objetos do tipo Student (ordenados alfabeticamente)
 * @return lista de pointers para objetos do tipo Student com n UCs
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

/**
 * Função dá output ao utilizador de uma determinada lista de estudantes, recebida como parametro.
 * COMPLEXIDADE: O(n).
 * @param lista lista de pointers para objetos do tipo Student
 *
 */
//PRINTS ÀS LISTAS
void printList(list<Student*> lista){
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }

    cout << "\n\nNumber of students: " << lista.size() << endl;
}


/**
 * Função dá output ao utilizador de um set de pointers para objetos do tipo Student ordenado alfabeticamente.
 *
 * COMPLEXIDADE: O(n).
 *
 * @param s set default de pointers para objetos do tipo Student (ordenados alfabeticamente)
 */
//prints aos sets
void printSetAlphaA(set<Student *, studentComparatorAlpha1> s){
    for (Student* stu : s){
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
    cout << "\n\nNumber of students: " << s.size() << endl;

}

/**
 * Função dá output ao utilizador de um set de pointers para objetos do tipo Student ordenado pelo inverso da ordem alfabética.
 *
 * COMPLEXIDADE: O(n).
 *
 * @param s set de pointers para objetos do tipo Student, ordenados ao inverso de alfabeticamente (de Z a A)
 */
void printSetAlphaZ(set<Student *, studentComparatorAlpha2> s){
    for (Student* stu : s){
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
    cout << "\n\nNumber of students: " << s.size() << endl;
}
/**
 * Função dá output ao utilizador de um set de pointers para objetos do tipo Student ordenado por número de estudante crescente.
 *
 * COMPLEXIDADE: O(n).
 * @param s set de pointers para objetos do tipo Student, ordenados pelo seu código de estudante (por ordem crescente)
 */
void printSetNumb(set<Student *, studentCodeComparator> s){
    for (Student* stu : s){
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
    cout << "\n\nNumber of students: " << s.size() << endl;
}

/**
 * Função dá output ao utilizador de um set de pointers para objetos do tipo Student ordenado por número de estudante decrescente.
 *
 * COMPLEXIDADE: O(n).
 *
 * @param s set de pointers para objetos do tipo Student, ordenados pelo seu código de estudante (por ordem decrescente)
 */
void printSetNumbInv(set<Student *, studentCodeComparatorInv> s){
    for (Student* stu : s){
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ";" << endl;
    }
    cout << "\n\nNumber of students: " << s.size() << endl;
}
/**
 * Função dá output ao utilizador de um set de pointers para objetos do tipo Student ordenada por número de UCs crescente.
 *
 * COMPLEXIDADE: O(n).
 * @param s set de pointers para objetos do tipo Student, ordenados por número de UCs crescente
 */
void printSetUC(set<Student* , studentComparatorUC> s){
    for (Student* stu : s){
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ", " << stu->get_classes().size() << ";" << endl;
    }
    cout << "\n\nNumber of students: " << s.size() << endl;
}

/**
 * Função dá output ao utilizador de um set de pointers para objetos do tipo Student ordenada por número de UCs decrescente.
 *
 * COMPLEXIDADE: O(n).
 * @param s set de pointers para objetos do tipo Student, ordenados por número de UCs decrescente
 */
void printSetUCInv(set<Student* , studentComparatorUCInv> s){
    for (Student* stu : s){
        cout << "- " << stu->get_studentName() << ", " << stu->get_studentCode() << ", " << stu->get_classes().size() << ";" << endl;
    }
    cout << "\n\nNumber of students: " << s.size() << endl;
}

#endif //AED_PROJECT1_FILTERS_CPP