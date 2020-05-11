#pragma once
#ifndef INCLUDE_CALENDAR_H_
#define INCLUDE_CALENDAR_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Film_show.h"
using namespace std;
class TicketOffice {
private:
  int day_now;
  int mon_now;
  int hou_now;
  int min_now;
  Film_show *show;
  int k_Film_show;
  void change_time();
public:
  TicketOffice();
  TicketOffice(TicketOffice &fp);
  void Plus_FS(Film_show newf);
  void buy_tick();
  string name_time(string t, int d);
  int name_nom(int nk, string t, int d);
  friend class Cinema;
  ~TicketOffice();
};
#endif  // INCLUDE_CALENDAR_H_