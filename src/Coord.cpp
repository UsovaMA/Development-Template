#include "Coord.h"

void Coord::up() {
  y++;
};

void Coord::doun() {
  y--;
};

void Coord::right() {
  x++;
};

void Coord::left() {
  x--;
}
int Coord::get_x() {
  return x;
}
int Coord::get_y() {
  return y;
}
;
void Coord::im_x(int a) {
  x = a;
}
void Coord::im_y(int a) {
  y = a;
}
Coord & Coord::operator=(const Coord & c) {
  x = c.x;
  y = c.y;
  return(*this);
};
