#include "Funck.h"

int six_ten(string st)
{
  bool zn;
  int s;
    if (st[0] == '-') {
      zn = 0;
      s = st.size();
      for (int i = 0; i + 1 < s; i++) {
        st[i] = st[i + 1];
      }
      st.erase(s - 1);
    }
    else zn = 1;
    s = st.size();
  int res = 0;
  unsigned char uc;
  for (int i = 0; i < s; i++) {
    uc = st[i];
    res = res+ one_chislo(uc)*pow(16, (s - 1 - i));
  }
  if(zn==1) return res;
  return res*(-1);
}

string ten_six(int a)
{
  if (a == 0) return "0";
  int d = 0, d1=a;
  string res="", dop="0";
  while (d1 > 16) {
    d = d1 % 16;
    if (d > 9) {
      if (d == 10) dop = "A";
      if (d == 11) dop = "B";
      if (d == 12) dop = "C";
      if (d == 13) dop = "D";
      if (d == 14) dop = "E";
      if (d == 15) dop = "F";
    }
    else {
      if (d == 0) dop = "0";
      if (d == 1) dop = "1";
      if (d == 2) dop = "2";
      if (d == 3) dop = "3";
      if (d == 4) dop = "4";
      if (d == 5) dop = "5";
      if (d == 6) dop = "6";
      if (d == 7) dop = "7";
      if (d == 8) dop = "8";
      if (d == 9) dop = "9";
    }
    res = dop + res;
    d1 = d1 / 16;
  }
  if (d1 > 9) {
    if (d1 == 10) dop = "A";
    if (d1 == 11) dop = "B";
    if (d1 == 12) dop = "C";
    if (d1 == 13) dop = "D";
    if (d1 == 14) dop = "E";
    if (d1 == 15) dop = "F";
  }
  else {
    if (d1 == 0) dop = "";
    if (d1 == 1) dop = "1";
    if (d1 == 2) dop = "2";
    if (d1 == 3) dop = "3";
    if (d1 == 4) dop = "4";
    if (d1 == 5) dop = "5";
    if (d1 == 6) dop = "6";
    if (d1 == 7) dop = "7";
    if (d1 == 8) dop = "8";
    if (d1 == 9) dop = "9";
  }
  res = dop + res;
  return res;
}

int one_chislo(unsigned char a) {
  if (a == 'A') return 10;
  if (a == 'B') return 11;
  if (a == 'C') return 12;
  if (a == 'D') return 13;
  if (a == 'E') return 14;
  if (a == 'F') return 15;
  int res = a - '0';
  return res;
}