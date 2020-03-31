#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Header.h"
using namespace std;


Hex::Hex() {
  h = new unsigned char[2];
  h[0] = '0';
  h[1] = '\0';
  size = 2;
  zn = 0;
}

void Hex::correct() {
  char dop;
  while (size < 0) {
    cout << "size cannot be less than 0, please input again-" << endl;
    cin >> size;
  } 
  int ch = 0;
    for (int i = 0; i < size; i++) {
      if (h[i] != '0') { ch++; continue; }
      ch = ch + h[i];
    }
    if (ch == 0) Hex();
    else {
      while ((h[0] == '0') && (size != 1)) {
      for (int i = 0; i < size-1; i++) {
        h[i] = h[i + 1];
        }
      size--;
      }
    }
      for (int i = 0; i < size; i++) {
        while (!(((h[i] >= 'A') && (h[i] <= 'F')) || ((h[i] >= '0') && (h[i] <= '9')))) {
          cout << i + 1 << " character is wrong, please input again(character)-";
          cin >> h[i];
        }
      }
    if (h[size + 1] != '\0') h[size + 1] = '\0';
}

Hex::Hex(unsigned char* a, bool m) {
  size = 1;
  h = new unsigned char[size+1];
  h[0] = a[0];
  h[1] = '\0';
  zn = m;
  correct();
}
Hex::Hex(unsigned char *a, int s, bool m) {
    size = s;
    h = new unsigned char[s+1];
    for (int i = 0; i < size; i++) {
      h[i] = a[i];
    }
    zn = m;
    h[size] = '\0';
    correct();
}
Hex::Hex(string a, bool m) {
  Hex::size = ::size(a);
  h = new unsigned char[size+1];
  for (int i = 0; i < size+1; i++) {
    h[i] = a[i];
  }
  zn = m;
  correct();
}

ostream& operator << (ostream& stream, const Hex& a) {
  if (a.zn) {
    cout << "-";
  }
  for (int i = 0; i < a.size; i++) {
    cout << a.h[i]; 
  }
  return stream;
}
istream& operator >> (istream& stream, Hex& a) {
  string S;
  cin >> S;
  int s = size(S);
  a.size = s;
  a.h = new unsigned char[s+1];
  if (S[0] == '-') {
    a.zn = 1;
    for (int i = 1; i < s + 1; i++) {
      a.h[i-1] = S[i];
    }
  } else {
    a.zn = 0;
    for (int i = 0; i < s+1; i++) {
    a.h[i] = S[i];
  }
  a.correct();
  }
  return stream;
}

int AB(unsigned char a) {
  if ((a > '0') && (a <= '9')) return (a - '0');
  else {
    if (a == 'A')return (10);
    if (a == 'B')return (11);
    if (a == 'C')return (12);
    if (a == 'D')return (13);
    if (a == 'E')return (14);
    if (a == 'F')return (15);
  }
  return (0);
}
unsigned char BA(int a) {
  if ((a >= 0) && (a <= 9)) return (a + '0');
  else {
    if (a == 10)return ('A');
    if (a == 11)return ('B');
    if (a == 12)return ('C');
    if (a == 13)return ('D');
    if (a == 14)return ('E');
    if (a == 15)return ('F');
  }
  return ('M');
}
int max(int a, int b) {
  if (a > b) return a;
  else return b;
}


Hex sum(Hex a, Hex b) {
    int SizeOb = max(a.size, b.size) + 1;
    unsigned char*T, *T1;
    T = new unsigned char[SizeOb + 1];
    T1 = new unsigned char[SizeOb + 1];
    T[0] = '0';
    T1[0] = '0';
    int Na= a.size-1, Nb = b.size - 1;
    for (int i = SizeOb - 1; i > 0; i--) {
      if (Na >= 0) {
        T[i] = a.h[Na];
        Na--;
      }
      else T[i] = '0';
      if (Nb >= 0) {
        T1[i] = b.h[Nb];
        Nb--;
      }
      else T1[i] = '0';
    }
    T[SizeOb] = '\0';
    T1[SizeOb] = '\0';
    //дублируем все в строки
    int dop = 0;
    int q, w, e;
    //если оба + или -
    if (a.zn == b.zn) {
      for (int i = SizeOb - 1; i >= 0; i--) {
        q = AB(T[i]);
        w = AB(T1[i]);
        e = q + w + dop;
        dop = 0;
        if (e < 15) T[i] = BA(e);
        else {
          while (e > 15) {
            e = e - 16;
            dop++;
          }
          T[i] = BA(e);
        }
      } //ссумируем 
    }
    else { //если разные
      Hex A = a, B = b;
      A.zn = 0; B.zn = 0;
      //знаки
      if ((a > b) && (A > B)) a.zn = 0;
      else a.zn = 1;
      if (A<B) { //ставим в начало MAX
        Hex d= a;
        a = b;
        b = d;
      } 
      
      for (int i = SizeOb - 1; i >= 0; i--) {//вычитаем
        q = AB(a.h[i]);
        w = AB(b.h[i]);
        e = q - w - dop;
        dop = 0;
        if (e > 0) T[i] = BA(e);
        else {
          if ((e < 0) && (i != 1)) {
            e = e + 16;
            dop++;
          }
          T[i] = BA(abs(e));
        }
        //if ((i == 1) && (e < 0)) {
        //  a.zn = 1;
        //  break;
        //}
      } 

      SizeOb--;
    }
    //проверка
    Hex res(T, SizeOb, a.zn);
    res.correct();
    delete[] T;
    delete[] T1;
    return res;
}
Hex Hex::operator+(const Hex& t) {
  Hex res = sum((*this), t);
  res.correct();
  return res;
}

Hex Hex::operator-(const Hex& t) {
  if (t.zn != zn) { //если знаки разные
    Hex t1, t2;
    t1 = (*this);
    t1.zn = zn;
    t2 = t;
    if(t1.zn==1){ //если знак первого "-"
      t2.zn = 1;
      Hex res = sum(t1, t2);
      return res;
    } else { //если знак второго "-"
      t2.zn = 0;
      Hex res = sum(t1, t2);
      return res;
    }
  } else {
    if ((t.zn == zn)&&(zn == 1)) {//если знак обоих "-"
    Hex t1, t2;
    t1 = (*this);
    t2 = t;
    t2.zn = 0;
    Hex res = sum(t1, t2); 
    return res;
    } else {//если знак обоих "+"
      Hex t1, t2;
      t1 = (*this);
      t2 = t;
      t2.zn = 1;
      Hex res = sum(t1, t2);
      res.correct();
      return res;
    }
  }
}

Hex& Hex::operator=(const Hex& t) {
  size = t.size;
  zn = t.zn;
  h = new unsigned char[size];
  for (int i = 0; i < size; i++) {
    h[i] = t.h[i];
  }
  return *this;
}

//bool Hex::operator==(const Hex& t) {
//  if ((zn==t.zn)&&(size==t.size)) {
//    int a = 0;
//    for (int i = 0; i < size; i++) {
//      if (h[i] == t.h[i]) a++;
//      else break;
//    }
//    if(a==size) return 1;
//  }
//  return 0;
//}

bool Hex::operator!=(const Hex& t) {
  if ((zn != t.zn) ||(size != t.size))return 1;
  else {
        int a = 0;
        for (int i = 0; i < size; i++) {
          if (h[i] == t.h[i]) a++;
          else return 1;
        }
        if(a==size) return 0;
  }
  return 1;
}

bool Hex::operator>(const Hex& t) {
  if (zn > t.zn) return 0;
  if (zn < t.zn) return 1;
  if (size < t.size) return 0;
  if (size > t.size) return 1;
  if ((*this) ==t) return 0;
  if(zn==0){
    for (int i = 0; i < size; i++) {
      if (h[i] > t.h[i]) return 1;
    }
  }
  if (zn == 1) {
    for (int i = 0; i < size; i++) {
      if (h[i] < t.h[i]) return 1;
    }
  }
  return 0;
}

bool Hex::operator>=(const Hex& t) {
  if (zn > t.zn) return 0;
  if (zn < t.zn) return 1;
  if (size < t.size) return 0;
  if (size > t.size) return 1;
  if ((*this) == t) return 1;
  if (zn == 0) {
    for (int i = 0; i < size; i++) {
      if (h[i] > t.h[i]) return 1;
    }
  }
  if (zn == 1) {
    for (int i = 0; i < size; i++) {
      if (h[i] < t.h[i]) return 1;
    }
  }
  return 0;
}

bool Hex::operator<(const Hex& t) {
    if (zn < t.zn) return 0;
  if (zn > t.zn) return 1;
  if (size > t.size) return 0;
  if (size < t.size) return 0;
  if ((*this) ==t) return 0;
  if(zn==0){
    for (int i = 0; i < size; i++) {
      if (h[i] < t.h[i]) return 1;
    }
  }
  if (zn == 1) {
    for (int i = 0; i < size; i++) {
      if (h[i] > t.h[i]) return 1;
    }
  }
  return 0;
}

bool Hex::operator<=(const Hex& t) {
  if (zn < t.zn) return 0;
  if (zn > t.zn) return 1;
  if (size > t.size) return 0;
  if (size < t.size) return 0;
  if ((*this) == t) return 1;
  if (zn == 0) {
    for (int i = 0; i < size; i++) {
      if (h[i] < t.h[i]) return 1;
    }
  }
  if (zn == 1) {
    for (int i = 0; i < size; i++) {
      if (h[i] > t.h[i]) return 1;
    }
  }
  return 0;
}