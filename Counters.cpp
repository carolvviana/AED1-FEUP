
// nºestudentes em turma/ano/uc + nome de estudantes em turma/ano/uc
// funcao para cout disto de forma bonita

#include "Data.h"

/* n estudantes em turma - DONE
 * nome estudantes em turma
 * n estudantes em cadeira - DONE
 * nome estudantes em cadeira
 * n estudantes ano - DONE
 * nome estudantes ano
 * */

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

void printTurma (UCClass ucC){
    list<Student*> lista = ucC.get_students();

    cout << "Students in the class " << ucC.get_ucCode() << ":" << endl;

    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ";" << endl;
    }

}

void printYear (char number, set<Student*,studentComparatorAlpha1> s){
    list<Student*> lista = methodsYear(number, s);
    cout << "Students in year " << number << ":" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ";" << endl;
    }
}

void printUC (string uc, set<Student*,studentComparatorAlpha1> s){
    list<Student*> lista = methodsUC(uc, s);
    cout << "Students in the UC " << uc << ":" << endl;
    for (Student* stu : lista) {
        cout << "- " << stu->get_studentName() << ";" << endl;
    }
}
