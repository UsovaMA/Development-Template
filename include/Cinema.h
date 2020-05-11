//#pragma once
#ifndef INCLUDE_CINEMA_H_
#define INCLUDE_CINEMA_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Room.h"
#include "Film_show.h"
#include "Calendar.h"
using namespace std;
class Cinema {
private:
  TicketOffice cal;
  Room *r;
  int s_r;
public:
  Cinema();
  Cinema(Cinema &fp);
  void plus_Room( Room ru);
  void by_b();
  void All_Room();
  void All_fs();
  int get_s_r();
  int get_k_fs();
  Room get_Room(int n);
  void Plus_FSC(Film_show fs);
  ~Cinema();
  friend class TicketOffice;
};
#endif  // INCLUDE_CALENDAR_H_
