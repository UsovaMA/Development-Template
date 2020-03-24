#pragma once
#include <iostream>

using namespace std;

class Integrals {

public:
  Integrals();
  Integrals(int _a, int _b, int _n);
  Integrals(const Integrals& c);

  void metod_centre();
  void metod_left();
  void metod_right();
  void sr_znach();

  void input();

private:
  int a;
  int b;
  int n;  // kol-vo otrezkov razbieniya
};