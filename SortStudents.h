//
// Created by Guilherme Monteiro on 03/11/2022.
//

#ifndef AED_PROJECT1_SORTSTUDENTS_H
#define AED_PROJECT1_SORTSTUDENTS_H
#include "Data.h"
//set sorters
struct studentComparatorAlpha2 {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode()) return (s2->get_studentName() < s1->get_studentName());
        return false;
    }
};
struct studentCodeComparator {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode())
            return (s1->get_studentCode() < s2->get_studentCode());
        return false;
    }
};
struct studentCodeComparatorInv {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode())
            return (s2->get_studentCode() < s1->get_studentCode());
        return false;
    }
};
struct studentComparatorUC {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode())
            return s1->get_classes().size() < s2->get_classes().size();
        return false;
    }
};
struct studentComparatorUCInv {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode())
            return s1->get_classes().size() > s2->get_classes().size();
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
