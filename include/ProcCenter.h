#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>
#include <stdlib.h>

using namespace std;

class ProcCenter
{
public:
  friend class Bancomat;
  friend class ProcCenterVec;
  ProcCenter(string name, string MiddleName, string LastName, string CardNumber, int balance, int pin);
  ~ProcCenter() {};
  void SetProcC(string name, string MiddleName, string LastName, string CardNumber, int balance, int pin);

private:
  string Name;
  string MiddleName;
  string LastName;
  string CardNumber;
  int Balance;
  int PIN;
  int incorrectPinTimes;
};


class ProcCenterVec {
public:
  friend class Bancomat;
  friend class ProcCenter;
  ProcCenterVec() {}
  ~ProcCenterVec() {}
  void AddPerson();
  ProcCenterVec(const ProcCenter& d);
  void SetnameV(vector <ProcCenter> pers) {
    Vect = pers;
  }
private:
  vector <ProcCenter> Vect;
  
};
