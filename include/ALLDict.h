// Copyright 2020 <Diana>
#pragma once
#ifndef INCLUDE_AD_H_
#define INCLUDE_AD_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "dict.h"
using namespace std;

class ALLDict {  // Dictionary
 public:
  ALLDict();
  ALLDict(const ALLDict &a);
  void ImS(int s);
  int getS();
  bool Poisk(string str);
  string Tran(string str);
  void ChTran(string str, string zam);
  void DopSTR(Dict a);
  ALLDict(Dict a, Dict b);
  ALLDict(Dict a);
  ALLDict operator+(const ALLDict& t);
  ALLDict& operator=(const ALLDict& t);
  friend ostream& operator << (ostream& stream, const ALLDict& a);
  friend istream& operator >> (istream& stream, ALLDict& a);
  friend bool operator==(const  ALLDict& left, const  ALLDict& right) {
    int a = 0;
    if (left.size == right.size) {
      for (int i = 0; i < left.size; i++) {
        if (left.ALLD[i].getW() == right.ALLD[i].getW()) {
          if (left.ALLD[i].getT() == right.ALLD[i].getT()) {
            a++;
          } else {
            return 0;
          }
        }
      }
    }
    return 1;
  }
  ~ALLDict();

 private:
  Dict * ALLD;
  int size;
};
bool en(std::string str);
bool definition(std::string str);

#endif
