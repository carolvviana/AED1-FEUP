#ifndef AED_PROJECT1_SORTSTUDENTS_H
#define AED_PROJECT1_SORTSTUDENTS_H
#include "Data.h"
//set sorters


struct studentComparatorAlpha2 {
    /**
     * Função que dá overload ao operador "( )" e compara objetos do tipo Student por nome por ordem contraria à alfabética (Z a A).
     * COMPLEXIDADE: O(1)
     * @param s1 pointer para objeto do tipo Student incluido na comparação
     * @param s2 pointer para objeto do tipo Student incluido na comparação
     * @return valor booleano - true, se o nome do primeiro objeto for "maior" do que o do segundo (comparação entre caracteres).
     */
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode()) return (s2->get_studentName() < s1->get_studentName());
        return false;
    }
};
struct studentCodeComparator {
    /**
     * Função que dá overload ao operador "( )" e compara objetos do tipo Student por numero de estudante (crescente).
     * COMPLEXIDADE: O(1)
     * @param s1 pointer para objeto do tipo Student incluido na comparação
     * @param s2 pointer para objeto do tipo Student incluido na comparação
     * @return valor booleano - true, se o numero de estudante do primeiro objeto for "menor" do que o do segundo
     */
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode())
            return (s1->get_studentCode() < s2->get_studentCode());
        return false;
    }
};
struct studentCodeComparatorInv {
    /**
     * Função que dá overload ao operador "( )" e compara objetos do tipo Student por numero de estudante (decrescente).
     * COMPLEXIDADE: O(1)
     * @param s1 pointer para objeto do tipo Student incluido na comparação
     * @param s2 pointer para objeto do tipo Student incluido na comparação
     * @return valor booleano - true, se o numero de estudante do primeiro objeto for "maior" do que o do segundo
     */
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode())
            return (s2->get_studentCode() < s1->get_studentCode());
        return false;
    }
};
struct studentComparatorUC {
    /**
     * Função que dá overload ao operador "( )" e compara objetos do tipo Student por numero de UCs (crescente).
     * Caso o numero seja igual, organiza-os por ordem alfabética.
     * COMPLEXIDADE: O(1)
     * @param s1 pointer para objeto do tipo Student incluido na comparação
     * @param s2 pointer para objeto do tipo Student incluido na comparação
     * @return valor booleano - true, se o numero de UCs do primeiro objeto for "menor" do que o do segundo
     */
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode())
            return (s1->get_classes().size() < s2->get_classes().size()) || ((s1->get_classes().size() == s2->get_classes().size()) && (s1->get_studentName() < s2->get_studentName()));
        return false;
    }
};
struct studentComparatorUCInv {
    /**
     * Função que dá overload ao operador "( )" e compara objetos do tipo Student por numero de UCs (decrescente).
     * Caso o numero seja igual, organiza-os por ordem alfabética.
     * COMPLEXIDADE: O(1)
     * @param s1 pointer para objeto do tipo Student incluido na comparação
     * @param s2 pointer para objeto do tipo Student incluido na comparação
     * @return valor booleano - true, se o numero de UCs do primeiro objeto for "maior" do que o do segundo
     */
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode())
            return (s1->get_classes().size() > s2->get_classes().size()) || ((s1->get_classes().size() == s2->get_classes().size()) && (s1->get_studentName() < s2->get_studentName()));
        return false;
    }
};
//create sorted sets
set<Student* , studentComparatorAlpha2> s_alphaZ(set<Student *, studentComparatorAlpha1> s);
set<Student* , studentCodeComparator> s_numb(set<Student *, studentComparatorAlpha1> s);
set<Student* , studentCodeComparatorInv> s_numbInv(set<Student *, studentComparatorAlpha1> s);
set<Student* , studentComparatorUC> s_UC(set<Student *, studentComparatorAlpha1> s);
set<Student* , studentComparatorUCInv> s_UCInv(set<Student *, studentComparatorAlpha1> s);

//SORTERS PARA LISTAS DE ESTUDANTES
bool l_AlphaA (Student* s1, Student* s2);
bool l_AlphaZ (Student* s1, Student* s2);
bool l_Numb (Student* s1, Student* s2);
bool l_NumbInv (Student* s1, Student* s2);
bool l_UC (Student* s1, Student* s2);
bool l_UCInv (Student* s1, Student* s2);

#endif //AED_PROJECT1_SORTSTUDENTS_H
