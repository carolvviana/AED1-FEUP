
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

//CONTAGENS DE ESTUDANTES

// #1 retorna numero de pessoas numa certa turma
int counterTurma(UCClass ucC){
    set<Student*, studentComparatorAlpha1> s;
    int counter = 0;
    for (Student* stu : s){
        for(UCClass *ucClass : stu->get_classes()){
            if(*ucClass == ucC)
                counter++;
        }
    }
    return counter;
//    countif(s.begin(), s.end(), s.get_classes())
}

// #2 numero de estudantes num certo ano
int counterYear(char number){
    set<Student*, studentComparatorAlpha1> s;
    int counter = 0;
    for (Student* stu : s){
        for(UCClass *ucClass :stu->get_classes()){
            if(ucClass->get_classCode()[0] == number)
                counter++;
        }
    }
    return counter;
}

// #3 numero de estudantes numa certa UC
int counterUC(string uc){
    set<Student*, studentComparatorAlpha1> s;
    int counter = 0;
    for (Student* stu : s){
        for(UCClass *ucClass :stu->get_classes()){
            if(ucClass->get_ucCode() == uc)
                counter++;
        }
    }
    return counter;
}

//LISTAGENS DE ESTUDANTES

