#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Hex {
public:
  Hex();
  Hex(unsigned char *a, bool m);
  Hex(unsigned char *a, int s, bool m);
  Hex(string a, bool m);
  friend ostream& operator << (ostream& stream, const Hex& a);
  friend istream& operator >> (istream& stream, Hex& a);
  Hex operator+(const Hex& t);
  Hex operator-(const Hex& t);
  Hex& operator=(const Hex& t);

  /*friend bool operator==(const Time& left, const Time& right) {
    bool res = 0;
    if ((left.min == right.min) && (left.hou == right.hou) && (left.sec == right.sec)) res = 1;
    return res;
  }*/

  friend bool operator==(const Hex& l, const Hex& t) {
    if ((l.zn == t.zn) && (l.size == t.size)) {
      int a = 0;
      for (int i = 0; i < l.size; i++) {
        if (l.h[i] == t.h[i]) a++;
        else break;
      }
      if (a == l.size) return 1;
    }
    return 0;
  }
  bool operator!=(const Hex& t);
  bool operator>(const Hex& t);
  bool operator<(const Hex& t);
  bool operator>=(const Hex& t);
  bool operator<=(const Hex& t);
  friend Hex sum(Hex a, Hex b);
  void correct();

private:
  unsigned char *h; //само число
  int size; //количество цифр
  bool zn; //1- минус, 0-плюс
};