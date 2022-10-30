//
// create timetable for student, uc and class;
// create function that couts timetable (independentemente do timetable que for)


/*
#include "Data.h"
#include <tuple>
using namespace std;

struct sorted_lectures{
    bool operator()(Lecture *lec1, Lecture *lec2){
        vector<string> weekdays {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        string weekday1 = lec1->get_weekDay();
        string weekday2 = lec2->get_weekDay();
        float start1 = lec1->get_startHour();
        float start2 = lec2->get_startHour();
        int ind1, ind2;
        for (int i = 0; i< weekdays.size(); i++){
            if (weekday1 == weekdays[i]) ind1 = i;
            if (weekday2 == weekdays[i]) ind2 = i;
        }
        if (ind1 < ind2) return true;
        else if (ind1 == ind2 && start1 < start2) return true;
        return false;
    }
};
struct sorted_vector{
    bool operator()(tuple<string,Lecture> t1, tuple<string,Lecture> t2){
        if (get<1>(t1).get_startHour() < get<1>(t2).get_startHour()) return true;
        return false;
    }
};
void cout_tt (vector<tuple<string,Lecture>> t1){
    for (tuple<string,Lecture> t: t1){
        cout << get<0>(t) << endl;
        cout << get<1>(t).get_startHour() << endl;
        cout << get<1>(t).get_type() << endl;
        cout << '\n';
        cout << '\n';
    }
}

void student_timetable(Student *student){
    vector<tuple<string,Lecture>> monday;
    vector<tuple<string,Lecture>> tuesday;
    vector<tuple<string,Lecture>> wednesday;
    vector<tuple<string,Lecture>> thursday;
    vector<tuple<string,Lecture>> friday;
    for (UCClass* uc: student->get_classes()) {
        sort(uc->get_lectures().begin(), uc->get_lectures().end(), sorted_lectures());
        for (Lecture *lec: uc->get_lectures()){
            tuple<string,Lecture> par(uc->get_ucCode(), *lec);
            if (lec->get_weekDay() == "Monday") monday.push_back(par);
            if (lec->get_weekDay() == "Tuesday") tuesday.push_back(par);
            if (lec->get_weekDay() == "Wednesday") wednesday.push_back(par);
            if (lec->get_weekDay() == "Thursday") thursday.push_back(par);
            if (lec->get_weekDay() == "Friday") friday.push_back(par);
        }
    }
    sort(monday.begin(), monday.end(), sorted_vector());
    sort(tuesday.begin(), tuesday.end(), sorted_vector());
    sort(wednesday.begin(), wednesday.end(), sorted_vector());
    sort(thursday.begin(), thursday.end(), sorted_vector());
    sort(friday.begin(), friday.end(), sorted_vector());

    cout << "Monday";
    cout << '\n' <<'\n';
    cout_tt (monday);
    cout << "Tuesday";
    cout << '\n' <<'\n';
    cout_tt (tuesday);
    cout << "Wednesday";
    cout << '\n' <<'\n';
    cout_tt (wednesday);
    cout << "Thursday";
    cout << '\n' <<'\n';
    cout_tt (thursday);
    cout << "Friday";
    cout << '\n' <<'\n';
    cout_tt (friday);
}

 */