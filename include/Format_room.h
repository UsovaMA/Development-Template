#pragma once
#ifndef INCLUDE_FORMAT_ROOM_H_
#define INCLUDE_FORMAT_ROOM_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
class Format_room {
private:
  int k_row_c; //число рядов classick
  int k_row_v; //число рядов  vip
  int k_seats; //число сидений в ряде

public:
  Format_room();
  Format_room(int kr_c, int kr_v, int k_seat);
  void UpFormat_room(int kr_c, int kr_v, int k_seat);
  Format_room(Format_room &a);
  Format_room& operator=(const Format_room& t);
  int get_k_row_c();
  int get_k_row_v();
  int get_k_seats();
  void im_k_row_c(int a);
  void im_k_row_v(int a);
  void im_k_seats(int a);
  int get_all_seats();
  friend bool operator==(const  Format_room& left, const  Format_room& right) {
    if ((left.k_row_c== right.k_row_c)&&(left.k_row_v == right.k_row_v)&&(left.k_seats == right.k_seats)) {
      return 1;
    }
    return 0;
  }
  friend class TicketOffice;
  friend class Room;
};
#endif  // INCLUDE_FORMAT_ROOM_H_