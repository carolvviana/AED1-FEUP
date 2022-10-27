#include "Lecture.h"


//constructors

Lecture::Lecture(string weekday, float startHour, float duration, string type) : weekDay_(weekday), startHour_(startHour), duration_(duration), type_(type){}

//setters
void Lecture::set_weekDay(string weekDay){weekDay_ = weekDay;}
void Lecture::set_startHour(float startHour) {startHour_ = startHour;}
void Lecture::set_duration(float duration){duration_ = duration;}
void Lecture::set_type(string type){type_=type;}

//getters
string Lecture::get_weekDay(){return weekDay_;}
float Lecture::get_startHour(){return startHour_;}
float Lecture::get_duration(){return duration_;}
string Lecture::get_type(){return type_;}
