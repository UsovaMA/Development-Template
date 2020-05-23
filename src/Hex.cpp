#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Hex.h"
#include "Funck.h"
using namespace std;


Hex::Hex() {
  c_h = new unsigned char[2];
  c_h[0] = '0';
  c_h[1] = '\0';
  s_h = 1;
  zn = 1;
  i_h = 0;
}

Hex::Hex(string a)
{
  if (a[0] == '-') {
    zn = 0;
    int s = a.size();
    for (int i = 0; i+1 < s; i++) {
      a[i] = a[i + 1];
    }
    a.erase(s - 1);
  } else zn = 1;
  //решили вопрос со знаком (если был минус, то в строке его нет)
  s_h= a.size();
  c_h= new unsigned char[s_h+1]; //выделили пам€ть
  for (int i = 0; i < s_h; i++) {
    c_h[i] = a[i];
  }
  c_h[s_h] = '\0'; //заполнили буквами.
  //—читаем в int
  i_h = six_ten(a);
}

int Hex::get_i_h()
{
  return i_h;
}

bool Hex::get_zn()
{
  return zn;
}

int Hex::get_s_h()
{
  return s_h;
}

unsigned char Hex::get_c_h(int nom)
{
  if(nom< s_h) return c_h[nom];
  return c_h[0];
}

Hex::Hex(const Hex& a) {
  s_h = a.s_h;
  zn = a.zn;
  i_h = a.i_h;
  c_h = new unsigned char[s_h+1];
  for (int i = 0; i < s_h+1; i++) {
    c_h[i] = a.c_h[i];
  }
}


ostream& operator << (ostream& stream, const Hex& a) {
  if (!a.zn) {
    cout << "-";
  }
  for (int i = 0; i < a.s_h; i++) {
    cout << a.c_h[i];
  }
  return stream;
}

istream& operator >> (istream& stream, Hex& a) {
  string S;
  cin >> S;
  if (S[0] == '-') {
    a.zn = 0;
    int s = S.size();
    for (int i = 0; i + 1 < s; i++) {
      S[i] = S[i + 1];
    }
    S.erase(s - 1);
  }
  else a.zn = 1;
  //решили вопрос со знаком (если был минус, то в строке его нет)
  a.s_h = S.size();
  a.c_h = new unsigned char[a.s_h + 1]; //выделили пам€ть
  for (int i = 0; i < a.s_h; i++) {
    a.c_h[i] = S[i];
  }
  a.c_h[a.s_h] = '\0'; //заполнили буквами.
  //—читаем в int
  a.i_h = six_ten(S);
  return stream;
}



Hex Hex::operator+(const Hex & t)
{
  Hex res;
  if (zn == t.zn) {
    res.zn = zn;
    res.i_h = i_h + t.i_h;
    string a = ten_six(res.i_h);
    res.s_h = a.size();
    delete[] res.c_h ;
    res.c_h = new  unsigned char[res.s_h+1];
    for (int i = 0; i < res.s_h; i++) {
      res.c_h[i] = a[i];
    }
    res.c_h[res.s_h] = '\0';
  }
  else {
    int a, b;
    if (zn == 0) a = i_h * (-1);
    else a = i_h;
    if (t.zn == 0) b = t.i_h*(-1);
    else b = t.i_h;
    int c = a + b;
    string s;
    if (c >= 0) {
      res.zn = 1;
    }
    else {
      res.zn = 0;
      c = c * (-1);
    }
    s = ten_six(c);
    res.s_h = s.size();
    res.i_h = c;
    delete[] res.c_h;
    res.c_h = new unsigned char[res.s_h + 1];
    for (int i = 0; i < res.s_h; i++) {
      res.c_h[i] = s[i];
    }
    res.c_h[res.s_h] = '\0';
  }
  return res;
}

Hex Hex::operator-(const Hex & t)
{
  Hex res, dop=t;
  if (dop.zn == 0) dop.zn = 1;
  else dop.zn = 0;
  res = (*this) + dop;
  return res;
}

Hex& Hex::operator=(const Hex& t) {
  delete[] c_h;
  s_h = t.s_h;
  zn = t.zn;
  i_h = t.i_h;
  c_h = new unsigned char[s_h + 1];
  for (int i = 0; i < s_h; i++) {
    c_h[i] = t.c_h[i];
  }
  c_h[s_h] = '\0';
  return *this;
}

bool Hex::operator!=(const Hex& t) {
  if ((zn != t.zn) || (s_h != t.s_h))return 1;
  else {
    if(i_h==t.i_h) return 0;
  }
  return 1;
}

bool Hex::operator>(const Hex& t) {
  if (zn > t.zn) return 0;
  if (zn < t.zn) return 1;
  if (s_h < t.s_h) return 0;
  if (s_h > t.s_h) return 1;
  if ((*this) == t) return 0;
  if (zn == 0) {
    if(i_h > t.i_h) return 0;
  }
  if (zn == 1) {
    if (i_h > t.i_h) return 1;
  }
  return 0;
}

bool Hex::operator>=(const Hex& t) {
  if (zn > t.zn) return 0;
  if (zn < t.zn) return 1;
  if (s_h < t.s_h) return 0;
  if (s_h > t.s_h) return 1;
  if ((*this) == t) return 1;
  if (zn == 0) {
    if (i_h > t.i_h) return 0;
  }
  if (zn == 1) {
    if (i_h > t.i_h) return 1;
  }
  return 0;
}

bool Hex::operator<(const Hex& t) {
  if (zn < t.zn) return 0;
  if (zn > t.zn) return 1;
  if (s_h > t.s_h) return 0;
  if (s_h < t.s_h) return 0;
  if ((*this) == t) return 0;
  if (zn == 0) {
    if (i_h < t.i_h) return 0;
  }
  if (zn == 1) {
    if (i_h < t.i_h) return 1;
  }
  return 0;
}

bool Hex::operator<=(const Hex& t) {
  if (zn < t.zn) return 0;
  if (zn > t.zn) return 1;
  if (s_h > t.s_h) return 0;
  if (s_h < t.s_h) return 0;
  if ((*this) == t) return 1;
  if (zn == 0) {
    if (i_h < t.i_h) return 0;
  }
  if (zn == 1) {
    if (i_h < t.i_h) return 1;
  }
  return 0;
}

Hex::~Hex()
{
  delete[] c_h;
  s_h = 0;
  zn = 1;
  i_h = 0;
}
