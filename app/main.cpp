// Copyright 2020 Serebrennikov
#include <iostream>
#include "ClassIntegrals.h"

using namespace std;

int main() {

  int _f;
  double tmp;
  double s_sr = 0;
  Integrals c1;
  int numOffunc();
  
  c1.input();
  cout << endl;
  cout << "1 - middle rectangle method" << endl;
  cout << "2 - left rectangle method" << endl;
  cout << "3 - right rectangle method" << endl;
  cout << "4 - all methods" << endl;
  cout << "Select a method to find integral (enter the appropriate number): ";
  
  int method;
  cin >> method;
  
  if (method < 1 || method > 4) {
    cout << "Wrong method number!" << endl << endl;
    system("pause");
    return 1;
  } else {
    if (method == 1) 
      c1.metod_centre();
    else {
      if (method == 2) 
        c1.metod_left();
      else {
        if (method == 3)
          c1.metod_right();
        else {
          if (method == 4) {
            c1.metod_centre();
            c1.metod_left();
            c1.metod_right();
            c1.sr_znach();
          }
        }
      }
    }
  }
  system("pause");
}