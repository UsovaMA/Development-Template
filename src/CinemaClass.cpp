#include "CinemaClass.h"
#include "TicketOffice.h"
Cinema::Cinema() {
  numberOfHall = 0;
  timeOfStart = "";
  NameOfFilm = "";
  duration = "";
  ageRate = "";
  status = "";
}
Cinema::Cinema(int _numberOfHall, int _numberOfFilm ,string _timeOfStart, string _NameOfFilm, string _duration, string _ageRate, bool _status) :
  numberOfHall(_numberOfHall),
  numberOfFilm(_numberOfFilm),
  timeOfStart(_timeOfStart),
  NameOfFilm(_NameOfFilm),
  duration(_duration),
  ageRate (_ageRate),
  status (_status)
{}
Cinema::Cinema() {
  numberOfHall = 0;
  numberOfFilm = 0;
  timeOfStart = "";
  NameOfFilm = "";
  duration = "";
  ageRate = "";
  status = "";
}
Cinema& Cinema::operator=(const Cinema& c) {
  numberOfHall = c.numberOfHall;
  numberOfFilm = c.numberOfFilm;
  timeOfStart = c.timeOfStart;
  NameOfFilm = c.NameOfFilm;
  duration = c.duration;
  ageRate = c.ageRate;
  status = c.status;
  return *this;
}