
#include "Data.h"
//falta meter aqui a ordem alfabetica

struct studentComparatorAlpha2 {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode()) return (s2->get_studentName() < s1->get_studentName());
        return false;
    }
};
struct studentCodeComparator {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode()) return (s1->get_studentCode() < s2->get_studentCode());
    }
};
struct studentCodeComparatorInv {
    bool operator()(Student *s1, Student *s2) {
        if (s1->get_studentCode() != s2->get_studentCode()) return (s2->get_studentCode() < s1->get_studentCode());
    }
};


set<Student* , studentComparatorAlpha2> alphaZ(Data d){
    set<Student* , studentComparatorAlpha2> studentsA2;
    for(Student* p :d.get_students()) studentsA2.insert(p);
    return studentsA2;
    //for (Student *stu : studentsA2){
    //    cout << stu->get_studentName() <<','<<stu->get_studentCode();
    //}
}
set<Student* , studentCodeComparator> numb(Data d){
    set<Student* , studentCodeComparator> studentNum;
    for (Student* p:d.get_students()) studentNum.insert(p);
    return studentNum;
}
set<Student* , studentCodeComparatorInv> numbInv(Data d){
    set<Student* , studentCodeComparatorInv> studentInv;
    for (Student* p:d.get_students()) studentInv.insert(p);
    return studentInv;
}

//create function that shows student beautifully
//função que mostra numero /nome de estudantes com menos/mais de N cadeiras
