// Copyright 2020 <Diana>
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Header.h"
using namespace std;

class Hex { //слово-перевод
public:
  Hex();
  void correct();
  friend Hex sum(Hex a, Hex b);
  Hex(unsigned char* a, bool m);
  Hex(unsigned char *a, int s, bool m);
  Hex(string a, bool m);
  Hex operator+(const Hex& t);
  Hex operator-(const Hex& t);
  Hex& operator=(const Hex& t);
  bool operator!=(const Hex& t);
  bool operator>(const Hex& t);
  bool operator<(const Hex& t);
  bool operator>=(const Hex& t);
  bool operator<=(const Hex& t);
  friend bool operator==(const  Hex& left, const  Hex& right) {
    if ((left.zn == right.zn) && (left.size == right.size)) {
          int a = 0;
          for (int i = 0; i < left.size; i++) {
            if (left.h[i] == right.h[i]) a++;
            else break;
          }
          if(a== left.size) return 1;
        }
        return 0;
  }
  friend ostream& operator << (ostream& stream, const Hex& a);
  friend istream& operator >> (istream& stream, Hex& a);
  ~Hex();
private:
  unsigned char *h;
  int size;
  bool zn;
};