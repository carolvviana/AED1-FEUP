
#ifndef AED_PROJECT1_LECTURE_H
#define AED_PROJECT1_LECTURE_H

#include <string>
using namespace std;



class Lecture{
private:
    string weekDay_;
    float startHour_;
    float duration_;
    float endHour_ = (startHour_ + duration_);
    string type_;

public:

    //constructors
    Lecture();
    Lecture(string weekday, float startHour, float duration, string type);

    //setters
    void set_weekDay(string weekDay);
    void set_startHour(float startHour);
    void set_endHour(float endHour);
    void set_duration(float duration);
    void set_type(string type);

    //getters
    string get_weekDay();
    float get_startHour();
    float get_endHour();
    float get_duration();
    string get_type();
};
#endif //AED_PROJECT1_LECTURE_H
