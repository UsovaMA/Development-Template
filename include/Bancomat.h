#pragma once
#include"ProcCenter.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>
#include <stdlib.h>

using namespace std;
struct CardPinStruct 
{
  int PIN;
  string NumCard;
};

class Bancomat
{
public:
  friend class ProcCenterVec;
  friend class ProcCenter;
 
  Bancomat() {}
  ~Bancomat() {}
  void Check_PIN(ProcCenterVec& c);
  void TakeCard(ProcCenterVec& c);
  void Start(ProcCenterVec& c);
  void Check(ProcCenterVec& c);
  void FindCard(ProcCenterVec& c);
  void Menu(ProcCenterVec& c);
  void BalancePerson(ProcCenterVec& c);
  void TakeMoney(ProcCenterVec& c);
  void PutMoney(ProcCenterVec& c);


private:
  int _10_ = 80;
  int _50_ = 80;
  int _100_ = 80;
  int _500_ = 80;
  int _1000_ = 80;
  int _5000_ = 80;
  CardPinStruct CardpiN;
  int Num;
  int takemoney;
  int putmoney;

};

