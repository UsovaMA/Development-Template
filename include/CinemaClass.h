#ifndef INCLUDE_CINEMACLASS_H_
#define INCLUDE_CINEMACLASS_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Cinema : public TicketOffice
{
  friend class TicketOffice;

public:
  int numberOfHall;
  string timeOfStart;
  string NameOfFilm;
  string duration;
  string ageRate;
  bool status;
  int numberOfFilm;
  Cinema();
  Cinema(const Cinema& v);
  Cinema(int _numberOfHall, int _numberOfFilm, string _timeOfStart, string _NameOfFilm, string _duration, string _ageRate, bool _status );
  Cinema& operator =(const Cinema& c);
};
class DayTable {
public:
  Cinema* films;
  int countFilms;
  DayTable() {
    films = new Cinema[15];
    countFilms = 0;
  }
};
class MonthTable {
public:
  DayTable* days;
  int remainDays;
  MonthTable() {
    days = new DayTable[30];
    remainDays = 30;
  }
};
#endif  // INCLUDE_CINEMACLASS_H_
