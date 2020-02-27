#ifndef INCLUDE_CLASS_TIME_HPP_
#define INCLUDE_CLASS_TIME_HPP_
#include <string>
#include <iostream>

using namespace std;

class Time {

private:
  int hour = 0;                                            // Часы
  int min = 0;                                             // Минуты
  int sec = 0;                                             // Секунды

public:
  Time();                                                  // Конструктор по умолчанию
  Time(string str);                                        // Конструктор преобразования типа
  Time(int _hour, int _min, int _sec);                     // Конструктор инициализации

  string IntToStr();                                       // Метод преобразования типа
  Time operator+(Time T);                                  // Метод сложения
  Time operator-(Time T);                                  // Метод вычитания

  friend bool operator>(const Time &T1, const Time &T2);   // Перегруженный оператор сравнения
  friend bool operator<(const Time &T1, const Time &T2);   // Перегруженный оператор сравнения
  friend bool operator==(const Time &T1, const Time &T2);  // Перегруженный оператор сравнения
  friend ostream& operator<<(ostream &out, Time Time);     // Перегруженный оператор вывода
  friend istream& operator>>(istream &in, Time &Time);     // Перегруженный оператор ввода

  ~Time() {}                                               // Деструктор ( Написал его только по тому что так сказано в задании, хотя он здесь вовсе не нужен, т.к. он создался бы автоматически)
};

#endif INCLUDE_CLASS_TIME_HPP_