#include "..\include\Room.h"

Room::Room() {
  price_cl = 0;
  price_vip = 0;
  size_room = 0;
  Format_room a;
  format = a;
}

Format_room Room::get_format() {
  return  format;
}

Room::Room(int cl, int vip, Format_room a) {
  price_cl = cl;
  price_vip = vip;
  size_room = a.get_all_seats();
  format = a;
}

void Room::UpRoom(int cl, int vip, Format_room a) {
  price_cl = cl;
  price_vip = vip;
  size_room = a.get_all_seats();
  format = a;
}

Room & Room::operator=(const Room & fp) {
  price_cl = fp.price_cl;
  price_vip = fp.price_vip;
  size_room = fp.size_room;
  format = fp.format;
  return (*this);
}

Room::Room(Room & fp) {
  price_cl = fp.price_cl;
  price_vip = fp.price_vip;
  size_room = fp.size_room;
  format = fp.format;
}

int Room::price_base_cl() {
  return price_cl;
}

int Room::price_base_vip() {
  return  price_vip;
}

int Room::get_size_room() {
  return size_room;
}

double Room::price_vip_morning() {
  double a = (price_vip/4) * 3;
  return a;
}

double Room::price_cl_morning() {
  double a = (price_cl / 4) * 3;
  return a;
}

double Room::price_vip_night() {
  double a = price_vip * (1.5);
  return a;
}

double Room::price_cl_night() {
  double a = price_cl * (1.5);
  return a;
}

istream & operator>>(istream & stream, Room & a) {
  Format_room fr;
  int iv1;
  cout << "Enter the size of row for vip place: ";
  cin >> iv1;
  fr.im_k_row_v(iv1);
  cout << "Enter the size of row for classical place: ";
  cin >> iv1;
  fr.im_k_row_c(iv1);
  cout << "Enter place in row: ";
  cin >> iv1;
  fr.im_k_seats(iv1);
  cout << "Enter base price for VIP place: ";
  cin >> iv1;
  a.price_vip = iv1;
  cout << "Enter base price for classical place: ";
  cin >> iv1;
  a.price_cl = iv1;
  a.format = fr;
  a.size_room = fr.get_all_seats();
  return stream;
}
