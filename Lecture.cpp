#include "Lecture.h"
//constructors
/**
 * Função cria um objeto Lecture com atributos a definir pelo utilizador.
 *
 * COMPLEXIDADE: O(1).
 */
Lecture::Lecture(string weekday, float startHour, float duration, string type) : weekDay_(weekday), startHour_(startHour), duration_(duration), type_(type){}

//setters
/**
 * Função define dia da semana de uma Lecture.
 *
 * COMPLEXIDADE: O(1).
 */
void Lecture::set_weekDay(string weekDay){weekDay_ = weekDay;}
/**
 * Função define hora de início de uma Lecture.
 *
 * COMPLEXIDADE: O(1).
 */
void Lecture::set_startHour(float startHour) {startHour_ = startHour;}
/**
 * Função define duração de uma Lecture.
 *
 * COMPLEXIDADE: O(1).
 */
void Lecture::set_duration(float duration){duration_ = duration;}
/**
 * Função define tipo (Teórico, Teórico-Prático ou Prática Laboratorial) de uma Lecture.
 *
 * COMPLEXIDADE: O(1).
 */
void Lecture::set_type(string type){type_=type;}
/**
 * Função define hora de término de uma Lecture.
 *
 * COMPLEXIDADE: O(1).
 */
void Lecture::set_endHour(float endHour){endHour_ = endHour;};

//getters
/**
 * Função retorn dia da semana de uma Lecture.
 *
 * COMPLEXIDADE: O(1).
 */
string Lecture::get_weekDay(){return weekDay_;}
/**
 * Função retorna hora de início de uma Lecture.
 *
 * COMPLEXIDADE: O(1).
 */
float Lecture::get_startHour(){return startHour_;}
/**
 * Função retorna duração de uma Lecture.
 *
 * COMPLEXIDADE: O(1).
 */
float Lecture::get_duration(){return duration_;}
/**
 * Função retorna tipo (Teórico, Teórico-Prático ou Prática Laboratorial) de uma Lecture.
 *
 * COMPLEXIDADE: O(1).
 */
string Lecture::get_type(){return type_;}
/**
 * Função retorna hora de término de uma Lecture.
 *
 * COMPLEXIDADE: O(1).
 */
float Lecture::get_endHour(){return endHour_;};
