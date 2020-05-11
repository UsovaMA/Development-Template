#pragma once
#ifndef INCLUDE_FILM_SHOW_H_
#define INCLUDE_FILM_SHOW_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Room.h"
using namespace std;
class Film_show {
private:
  string name_film;
  int nom_r;
  int date;
  string time;
  Room zal;
  int brv;
  int brc;
  place *p;
public:
  Film_show();
  Film_show::Film_show(string name_of_film, int date_of_film, int nom_room, string time_of_f, Room ro);
  void Upgr(string name_of_film, int date_of_film, int nom_room, string time_of_f, Room ro);
  Film_show(Film_show &fp);
  Film_show& operator=(const Film_show& fp);
  int type_time();
  void info();
  void buy_ticket();
  void pay_br_ticket();
  void del_br_ticket();
  ~Film_show();
  friend class Room;
  friend class TicketOffice;
};
#endif  // INCLUDE_FILM_SHOW_H_
