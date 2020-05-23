// Copyright 2020 <Diana>
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Hex {
public:
  Hex();
  Hex(string a); //можно с минусом
  int get_i_h();
  bool get_zn();
  int get_s_h();
  unsigned char get_c_h(int nom);
  Hex(const Hex& a);
  
  Hex operator+(const Hex& t);
  Hex operator-(const Hex& t);
  Hex& operator=(const Hex& t);
  bool operator!=(const Hex& t);
  bool operator>(const Hex& t);
  bool operator<(const Hex& t);
  bool operator>=(const Hex& t);
  bool operator<=(const Hex& t);
  friend bool operator==(const  Hex& left, const  Hex& right) {
    if ((left.zn == right.zn) && (left.s_h == right.s_h)) {
      if (left.i_h == right.i_h) return 1;
    }
    return 0;
  };
  friend ostream& operator << (ostream& stream, const Hex& a);
  friend istream& operator >> (istream& stream, Hex& a);
  ~Hex();
private:
  unsigned char *c_h;
  int s_h; //Размер выделяется на все, кроме '/0'
  bool zn; //0- minus, 1-plus
  int i_h; //всегда положительно 
};