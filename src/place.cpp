#include <iostream>
#include <fstream>
#include <clocale>
#include "windows.h"
#include "place.h"
#include "Format_room.h"

place::place() {
  vip = 0;
  free = 1;
  row = 0;
  pl = 0;
}

place::place(int r, int p, bool v, bool f) {
  vip = v;
  free = f;
  row = r;
  pl = p;
}

place & place::operator=(const place & fp) {
  vip = fp.vip;
  free = fp.free;
  row = fp.row;
  pl = fp.pl;
  return(*this);
}

place::place(place & fp) {
  vip = fp.vip;
  free = fp.free;
  row = fp.row;
  pl = fp.pl;
}

bool place::get_vip() {
  return vip;
}

bool place::get_free() {
  return free;
}

int place::get_row() {
  return row;
}

int place::get_pl() {
  return pl;
}

void place::im_vip(bool v) {
  vip = v;
}

void place::im_free(bool f) {
  free = f;
}

void place::im_row(int r) {
  row = r;
}

void place::im_pl(int p) {
  pl = p;
}
