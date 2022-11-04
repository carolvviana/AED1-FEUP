#ifndef AED_PROJECT1_FILTERS_H
#define AED_PROJECT1_FILTERS_H
# include "SortStudents.h"
//create filtered lists
list<Student*> methodsYear(char number, set<Student*,studentComparatorAlpha1> s);
list<Student*> methodsUC(string uc, set<Student*,studentComparatorAlpha1> s);
list<Student*> filterLess(int n, set<Student*,studentComparatorAlpha1> s);
list<Student*> filterMore(int n, set<Student*,studentComparatorAlpha1> s);
list<Student*> filterEqual(int n, set<Student*,studentComparatorAlpha1> s);

//printers
void printList(list<Student*> lista);

void printSetAlphaA(set<Student *, studentComparatorAlpha1> s);
void printSetAlphaZ(set<Student *, studentComparatorAlpha2> s);
void printSetNumb(set<Student *, studentCodeComparator> s);
void printSetNumbInv(set<Student *, studentCodeComparatorInv> s);
void printSetUC(set<Student* , studentComparatorUC> s);
void printSetUCInv(set<Student* , studentComparatorUCInv> s);
#endif //AED_PROJECT1_FILTERS_H
