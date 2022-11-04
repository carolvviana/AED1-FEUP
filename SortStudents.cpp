#ifndef AED_PROJECT1_SORTSTUDENTS_CPP
#define AED_PROJECT1_SORTSTUDENTS_CPP
#include "SortStudents.h"

/**
 * Função retorna um set de pointers de estudantes ordenado com ordem inversa à alfabética.
 *
 * COMPLEXIDADE: O(n).
 * @param s set de pointers para objetos do tipo Student ordenados alfabeticamente (ordenação default)
 * @return set de pointers para objetos do tipo Student ordenados com ordem inversa à alfabética
 */
set<Student* , studentComparatorAlpha2> s_alphaZ(set<Student *, studentComparatorAlpha1> s){
    set<Student* , studentComparatorAlpha2> studentsA2;
    for(Student* p :s) studentsA2.insert(p);
    return studentsA2;
}

/**
 * Função retorna um set de pointers de estudantes ordenado com número de estudante crescente.
 *
 * COMPLEXIDADE: O(n).
 * @param s set de pointers para objetos do tipo Student ordenados alfabeticamente (ordenação default)
 * @return set de pointers para objetos do tipo Student ordenados por numero de estudante crescente
 */
set<Student* , studentCodeComparator> s_numb(set<Student *, studentComparatorAlpha1> s){
    set<Student* , studentCodeComparator> studentNum;
    for (Student* p:s) studentNum.insert(p);
    return studentNum;
}

/**
 * Função retorna um set de estudantes ordenado com número de estudante decrescente.
 *
 * COMPLEXIDADE: O(n).
 * @param s set de pointers para objetos do tipo Student ordenados alfabeticamente (ordenação default)
 * @return set de pointers para objetos do tipo Student ordenados por numero de estudante decrescente
 */
set<Student* , studentCodeComparatorInv> s_numbInv(set<Student *, studentComparatorAlpha1> s){
    set<Student* , studentCodeComparatorInv> studentInv;
    for (Student* p:s) studentInv.insert(p);
    return studentInv;
}

/**
 * Função retorna um set de estudantes ordenado com número de UCs crescente.
 *
 * COMPLEXIDADE: O(n).
 * @param s set de pointers para objetos do tipo Student ordenados alfabeticamente (ordenação default)
 * @return set de pointers para objetos do tipo Student ordenados por numero de UCs crescente
 */
set<Student* , studentComparatorUC> s_UC(set<Student *, studentComparatorAlpha1> s){
    set<Student* , studentComparatorUC> studentsUC;
    for (Student* p :s) studentsUC.insert(p);
    return studentsUC;
}
/**
 * Função retorna um set de estudantes ordenado com número de UCs decrescente.
 *
 * COMPLEXIDADE: O(n).
 * @param s set de pointers para objetos do tipo Student ordenados alfabeticamente (ordenação default)
 * @return set de pointers para objetos do tipo Student ordenados por numero de UCs decrescente
 */
set<Student* , studentComparatorUCInv> s_UCInv(set<Student *, studentComparatorAlpha1> s){
    set<Student* , studentComparatorUCInv> studentsUC;
    for(Student* p :s) studentsUC.insert(p);
    return studentsUC;
}



//SORTERS PARA LISTAS DE ESTUDANTES
/**
 * Função compara estudantes por nome (alfabeticamente)
 *
 * COMPLEXIDADE: O(1).
 * @param s1 pointer para objeto do tipo Student presente na comparação
 * @param s2 pointer para objeto do tipo Student presente na comparação
 * @return valor booleano - true se o nome do objeto Student s1 for "menor" do que o nome de s2 (comparação entre caracteres)
 */
bool l_AlphaA (Student* s1, Student* s2){
    return s1->get_studentName()<s2->get_studentName();
}
/**
 * Função compara estudantes por nome (ordem inversa à alfabética)
 *
 * COMPLEXIDADE: O(1).
 * @param s1 pointer para objeto do tipo Student presente na comparação
 * @param s2 pointer para objeto do tipo Student presente na comparação
 * @return valor booleano - true se o nome do objeto Student s1 for "maior" do que o nome de s2 (comparação entre caracteres)
 */
bool l_AlphaZ (Student* s1, Student* s2){
    return s1->get_studentName()>s2->get_studentName();
}

/**
 * Função compara estudantes por número de estudante (ordem decrescente).
 *
 * COMPLEXIDADE: O(1).
 * @param s1 pointer para objeto do tipo Student presente na comparação
 * @param s2 pointer para objeto do tipo Student presente na comparação
 * @return valor booleano - true se o codigo do objeto Student s1 for maior do que o codigo de s2
 */
bool l_NumbInv (Student* s1, Student* s2){
    return s1->get_studentCode()>s2->get_studentCode();
}
/**
 * Função compara estudantes por número de estudante (ordem crescente).
 *
 * COMPLEXIDADE: O(1).
 * @param s1 pointer para objeto do tipo Student presente na comparação
 * @param s2 pointer para objeto do tipo Student presente na comparação
 * @return valor booleano - true se o codigo do objeto Student s1 for menor do que o codigo de s2
 */
bool l_Numb (Student* s1, Student* s2){
    return s1->get_studentCode()<s2->get_studentCode();
}

/**
 * Função compara estudantes por número de UCs (crescente).
 *
 * COMPLEXIDADE: O(1).
 * @param s1 pointer para objeto do tipo Student presente na comparação
 * @param s2 pointer para objeto do tipo Student presente na comparação
 * @return valor booleano - true se o numero de UCs do objeto Student s1 for menor do que o de s2
 */
bool l_UC (Student* s1, Student* s2){
    return s1->get_classes().size() < s2->get_classes().size();
}

/**
 * Função compara estudantes por número de UCs (decrescente).
 *
 * COMPLEXIDADE: O(1).
 * @param s1 pointer para objeto do tipo Student presente na comparação
 * @param s2 pointer para objeto do tipo Student presente na comparação
 * @return valor booleano - true se o numero de UCs do objeto Student s1 for maior do que o de s2
 */
bool l_UCInv (Student* s1, Student* s2){
    return s1->get_classes().size() > s2->get_classes().size();
}
#endif //AED_PROJECT1_SORTSTUDENTS_CPP