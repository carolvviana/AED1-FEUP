//
// create timetable for student, uc and class;
// create function that couts timetable (independentemente do timetable que for)

#include "Data.h"

struct sort_lectures{
    bool operator()(UCClass uc1, UCClass uc2){
        vector<string> weekday {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        return (uc1.get_lectures()[1].get_weekDay())
    }
};

struct sorted_classes{
    bool operator()(UCClass uc1, UCClass uc2){
        vector<string> weekday {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        return (uc1.get_lectures().)
    }
};

vector<UCClass> student_timetable(Student student){
    vector<UCClass> tt;
    sort(tt.begin(), tt.end(), )
}