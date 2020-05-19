#pragma once
#include <string>
#include <iostream>

using std::string;

class ProcCenter {
private:
  string number;
  string fullname;
  int sumChet;
  int year;
  int sumZaim;
  int stavka;
  int pogasheno;
  int ostalos;

public:
  ProcCenter();
  ProcCenter(bool k);
  ProcCenter(int k);
  ProcCenter(int _year, int _sumZaim, int _stavka);
  ~ProcCenter();

  friend class Credit;

  bool vhod();
  void setinfo(ProcCenter& person);
  void getinfo(int num);
  void update(int num);
};

class Credit {
private:

  int year;
  int sumZaim;
  int stavka;
  int mounth;
  int k;

public:
  Credit();
  ~Credit();

  friend class ProcCenter;

  void menu();

  void avtorizazia();
  void infoDostCredits();
  void chekMyCredit();
  void chekSetCredit();
  void setCredit();
  void showMyCredit();
  void pogasitMounth();
  void pogasitAll();
};