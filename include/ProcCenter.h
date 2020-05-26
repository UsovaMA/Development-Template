#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <functional>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Sup
{
public:
  friend class Bancomat;
  friend class ProcCenter;

  Sup(string name, string MiddleName, string LastName, int CardNumber, int balance, int pin, bool Blocked, int incorrectpintimes);
  Sup();
  ~Sup() {};
  void SetProcC(string name, string middlename, string lastname, int cardnumber, int balance, int pin, bool Blocked, int incorrectpintimes);
  Sup& operator=(const Sup& a);

private:
  string Name;
  string MiddleName;
  string LastName;
  int NumCard;
  int Balance;
  int PIN;
  bool Blocked;
  int incorrectPinTimes;
  
  
};


class ProcCenter {
public:
  friend class Bancomat;
  friend class Sup;
  ProcCenter() {}
  ~ProcCenter() { delete[] person; }
  void AddPers();
  void AddPers(Sup a);
  ProcCenter(const Sup& d);


private:
  Sup* person;
  int next = 0;
};

