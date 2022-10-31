
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
pair<list<Student*>, int> methodsTurma(UCClass ucC){
    pair<list<Student*>, int> p1;
    p1.first = ucC.get_students();
    p1.second = ucC.get_students().size();;
    return p1;
}

/**
 * Função retorna a lista de estudantes de um determinado ano (number) bem como o número de estudantes nesse ano.
 *
 * COMPLEXIDADE: O(n^2).
 */
pair<list<Student*>, int> methodsYear(char number, Data d){
    //pair<list<Student*>, int> p1 = new pair<list<Student*>, int>;
    list<Student*> lista = {};
    set<Student*, studentComparatorAlpha1> s = d.get_students();
    int counter = 0;
    number+=48;
    for (Student* stu : s){
        for(UCClass *ucClass :stu->get_classes()){
            char teste = ucClass->get_classCode()[0];
            if(teste == number) {
                counter++;
                lista.push_back(stu);
            }
        }
    }
    pair<list<Student*>, int> p1;
    p1.first = lista;
    p1.second = counter;
    return p1;
}

/**
 * Função retorna a lista de estudantes de uma determinada cadeira (uc) bem como o número de estudantes dessa cadeira.
 *
 * COMPLEXIDADE: O(n^2).
 */
pair<list<Student*>, int> methodsUC(string uc, Data d){
    list<Student*> lista = {};
    set<Student*, studentComparatorAlpha1> s = d.get_students();
    int counter = 0;
    for (Student* stu : s){
        for(UCClass *ucClass :stu->get_classes()){
            if(ucClass->get_ucCode() == uc) {
                counter++;
                lista.push_back(stu);
            }
        }
    }
    pair<list<Student*>, int> p1;
    p1.first = lista;
    p1.second = counter;
    return p1;
}




//CONTAGENS DE ESTUDANTES

// #1 retorna numero de pessoas numa certa turma
/**
 * Função retorna o número de estudantes de uma determinada turma (ucC).
 *
 * COMPLEXIDADE: O(1).
 */
int counterTurma(UCClass ucC){
    return methodsTurma(ucC).second;
}

// #2 numero de estudantes num certo ano
/**
 * Função retorna o número de estudantes de um determinado ano (number).
 *
 * COMPLEXIDADE: O(1).
 */
int counterYear(char number, Data d){
    return methodsYear(number, d).second;
}

// #3 numero de estudantes numa certa UC
/**
 * Função retorna o número de estudantes de uma determinada UC (uc).
 *
 * COMPLEXIDADE: O(1).
 */
int counterUC(string uc, Data d){
    return methodsUC(uc, d).second;
}

//PRINTS ÀS LISTAS