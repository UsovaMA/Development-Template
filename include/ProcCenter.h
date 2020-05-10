#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_
#include <string>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Dop
{
public:
  friend class Bancai;
  friend class ProcCenter;
  Dop(string Name_x, string Familia_x, string Ochestvo_x, string NomerCard_x, int summa_x, int PIN_x, bool bloked_x, int _Poca_ne_block);
  ~Dop() {};
  void setDop(string Name_x, string Familia_x, string Ochestvo_x, string NomerCard_x, int summa_x, int PIN_x, bool bloked_x, int _Poca_ne_block);

private:
  string Name;
  string Familia;
  string Ochestvo;
  string NomerCard;
  int summa;
  int PIN;
  bool bloked;
  int Poca_ne_block;
  
};


class ProcCenter {
public:
  friend class Bancai;
  friend class Dop;
  ProcCenter() {}
  ~ProcCenter() {}
  void AddPers();
  ProcCenter(const Dop& d);
  void SetINF(vector <Dop> _Chel) {
    Chel = _Chel;
  }
private:
  vector <Dop> Chel;
  
};


#endif  // INCLUDE_ADD_H_
