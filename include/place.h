#pragma once
#ifndef INCLUDE_Free_place_H_
#define INCLUDE_Free_place_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Format_room.h"
using namespace std;
class place {
private:
  bool vip; //0-no vip, 1- vip
  bool free;//1-место свободно, 0- занято
  int row; //ряд
  int pl; //место
public:
  place();
  place(int r, int p, bool v, bool f);
  place& operator=(const place& fp);
  friend bool operator==(const  place& left, const  place& right) {
    if ((left.vip == right.vip) && (left.free == right.free) && (left.row == right.row) && (left.pl == right.pl))
      return 1;
    return 0;
  }
  place(place &fp);
  bool get_vip();
  bool get_free();
  int get_row();
  int get_pl();
  void im_vip(bool v);
  void im_free(bool f);
  void im_row(int r);
  void im_pl(int p);
};
#endif  // INCLUDE_Free_place_H_
