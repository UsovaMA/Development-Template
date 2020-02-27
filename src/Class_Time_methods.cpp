#include "Class_Time.hpp"

// Реализация стандартных конструкторов

Time::Time() {
  hour = 0;
  min = 0;
  sec = 0;
}

Time::Time(string str) {
  for (int i = 0; i < 2; i++) {
    hour = hour * 10 + str[i] - 0x30;
  }
  for (int i = 3; i < 5; i++) {
    min = min * 10 + str[i] - 0x30;
  }
  for (int i = 6; i < 8; i++) {
    sec = sec * 10 + str[i] - 0x30;
  }
}

Time::Time(int _hour, int _min, int _sec) {
  hour = _hour;
  min = _min;
  sec = _sec;
}

// Реализация дополнительных методов

string Time::IntToStr() {
  string _hour = to_string(hour);
  if (hour < 10) _hour = "0" + _hour;
  string _min = to_string(min);
  if (min < 10) _min = "0" + _min;
  string _sec = to_string(sec);
  if (sec < 10) _sec = "0" + _sec;
  string str = _hour + ":" + _min + ":" + _sec;
  return str;
}

Time Time::operator+(Time T) {                           // Перегруженный оператор сложения
  Time res;
  int overflow = 0;
  res.sec = sec + T.sec;
  if (res.sec > 59) {
    res.sec %= 60;
    overflow = 1;
  }
  res.min = min + T.min + overflow;
  overflow = 0;
  if (res.min > 59) {
    res.min %= 60;
    overflow = 1;
  }
  res.hour = (hour + T.hour + overflow) % 24;
  return res;
}

Time Time::operator-(Time T) {                           // Перегруженный оператор вычитания
  Time res;
  int flaw = 0;
  if (hour < T.hour) {
    res.hour = 0;
    res.min = 0;
    res.sec = 0;
  }
  else {
    res.sec = sec - T.sec;
    if (res.sec < 0) {
      res.sec += 60;
      flaw = 1;
    }
    res.min = min - T.min - flaw;
    flaw = 0;
    if (res.min < 0) {
      res.min += 60;
      flaw = 1;
    }
    res.hour = hour - T.hour - flaw;
    if (res.hour < 0) res.hour = 0;
  }
  return res;
}

bool operator>(const Time &T1, const Time &T2) {         // Перегруженный оператор сравнения
  int a = 0;
  int b = 0;
  a = T1.hour * 3600 + T1.min * 60 + T1.sec;
  b = T2.hour * 3600 + T2.min * 60 + T2.sec;
  return a > b;
}

bool operator<(const Time &T1, const Time &T2) {         // Перегруженный оператор сравнения
  int a = 0;
  int b = 0;
  a = T1.hour * 3600 + T1.min * 60 + T1.sec;
  b = T2.hour * 3600 + T2.min * 60 + T2.sec;
  return a < b;
}

bool operator==(const Time &T1, const Time &T2) {        // Перегруженный оператор сравнения
  int a = 0;
  int b = 0;
  a = T1.hour * 3600 + T1.min * 60 + T1.sec;
  b = T2.hour * 3600 + T2.min * 60 + T2.sec;
  return a == b;
}

ostream& operator<<(ostream &out, Time Time) {
  out << "Time " << Time.IntToStr() << endl;
  return out;
}

istream& operator>>(istream &in, Time &Time) {
  while (1) {
    cout << "hour: ";
    in >> Time.hour;
    if (Time.hour > 23) {
      cout << "From 0 to 23" << endl;
      continue;
    }
    while (1) {
      cout << "min: ";
      in >> Time.min;
      if (Time.min > 59) {
        cout << "From 0 to 59" << endl;
        continue;
      }
      while (1) {
        cout << "sec: ";
        in >> Time.sec;
        if (Time.sec > 59) {
          cout << "From 0 to 59" << endl;
          continue;
        }
        break;
      }
      break;
    }
    break;
  }
  return in;
}