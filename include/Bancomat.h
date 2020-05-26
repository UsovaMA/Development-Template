#pragma once
#include"ProcCenter.h"
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
struct CardPinStruct 
{
  int PIN;
  int NumCard;
};

class Bancomat
{
public:
  friend class ProcCenter;
  friend class Sup;
 
  Bancomat() {}
  ~Bancomat() {}
  void Check_PIN(ProcCenter& c);
  void TakeCard(ProcCenter& c);
  void Start(ProcCenter& c);
  void Check(ProcCenter& c);
  int CheckSum(ProcCenter& c);
  void FindCard(ProcCenter& c);
  void Menu(ProcCenter& c);
  void BalancePerson(ProcCenter& c);
  int BalancePersonForTest(ProcCenter& c);
  void PutMoney(ProcCenter& c);
  void TakeMoney(ProcCenter& c);
  int TakeMoneyMain(ProcCenter& c);
  void CheckPutMoney(ProcCenter& c);
  void CheckPutMoneyForTest(ProcCenter& c, int a);
  void nexttest(ProcCenter& c);
  int PutMoneyMain(ProcCenter& c);
  int FindCardMain(ProcCenter& c);
  void FindCardSup(ProcCenter& c);
  void CheckTake(ProcCenter& c);
  void CheckTakeForTest(ProcCenter& c, int a);
  void CountCard(ProcCenter& c);


private:
  
  int _100_ = 1600;
  int _200_ = 1600;
  int _500_ = 1600;
  int _1000_ = 1600;
  int _2000_ = 1600;
  int _5000_ = 1600;
  CardPinStruct CardpiN;
  int Num;
  int takemoney;
  int putmoney;


};

