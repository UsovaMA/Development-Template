#include <iostream>
#include <fstream>
#include <clocale>
#include "windows.h"
#include "Format_room.h"

Format_room::Format_room() {
  k_row_c = 0;
  k_row_v = 0;
  k_seats = 0;
}

Format_room::Format_room(int kr_c, int kr_v, int k_seat) {
  k_row_c = kr_c;
  k_row_v = kr_v;
  k_seats = k_seat;
}
void Format_room::UpFormat_room(int kr_c, int kr_v, int k_seat) {
  k_row_c = kr_c;
  k_row_v = kr_v;
  k_seats = k_seat;
}
Format_room::Format_room(Format_room & a) {
  k_row_c = a.k_row_c;
  k_row_v = a.k_row_v;
  k_seats = a.k_seats;
}

Format_room & Format_room::operator=(const Format_room & a) {
  k_row_c = a.k_row_c;
  k_row_v = a.k_row_v;
  k_seats = a.k_seats;
  return (*this);
}


int Format_room::get_k_row_c() {
  return k_row_c;
}

int Format_room::get_k_row_v() {
  return k_row_v;
}

int Format_room::get_k_seats() {
  return k_seats;
}

void Format_room::im_k_row_c(int a) {
  k_row_c = a;
}

void Format_room::im_k_row_v(int a) {
  k_row_v = a;
}

void Format_room::im_k_seats(int a) {
  k_seats = a;
}

int Format_room::get_all_seats() {
  int a = (k_row_c + k_row_v)*k_seats;
  return a;
}
