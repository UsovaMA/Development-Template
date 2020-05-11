#pragma once
#ifndef INCLUDE_ROOM_H_
#define INCLUDE_ROOM_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Format_room.h"
#include "place.h"
using namespace std;
class Room {
private:
  int price_cl;
  int price_vip;
  int size_room;
  Format_room format;
public:
  Room();
  Format_room get_format();
  Room(int cl, int vip, Format_room a);
  void UpRoom(int cl, int vip, Format_room a);
  Room& operator=(const Room& fp);
  friend istream& operator >> (istream& stream, Room& a);
  friend bool operator==(const  Room& left, const  Room& right) {
    if ((left.price_cl == right.price_cl) && (left.price_vip == right.price_vip) && (left.size_room == right.size_room))
      return 1;
    return 0;
  }
  Room(Room &fp);
  int price_base_cl();
  int price_base_vip();
  int get_size_room();
  double price_vip_morning();
  double price_cl_morning();
  double price_vip_night();
  double price_cl_night();
  friend class Film_show;
  friend class Cinema;
};
#endif  // INCLUDE_ROOM_H_