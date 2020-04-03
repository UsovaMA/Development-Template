// Copyright 2020 Serebrennikov
#pragma once
#include <iostream>

using namespace std;

class Integrals {

public:
  Integrals();
  Integrals(int _a, int _b, int _n);
  Integrals(const Integrals& c);

  
  double metod_centre();
  double metod_left();
  double metod_right();
  double sr_znach();

  void input();

private:
  int a;
  int b;
  int n;  // kol-vo otrezkov razbieniya
};

int numOffunc();