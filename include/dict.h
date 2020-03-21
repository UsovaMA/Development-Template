//#pragma once
#ifndef INCLUDE_D_H_
#define INCLUDE_D_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Dict { //слово-перевод
public:
  Dict();
  Dict(std::string a, std::string b);
  string getW();
  string getT();
  friend string getW(Dict a);
  friend string getT(Dict a);
  void ImW(std::string a);
  void ImT(std::string a);
  void correct();
  friend ostream& operator << (ostream& stream, const Dict& a);
  friend istream& operator >> (istream& stream, Dict& a);
private:
  std::string word, translation;
};

class ALLDict{ // несколько 
public:
  ALLDict();
  ALLDict(int i);
  ALLDict(Dict a);
  ALLDict(Dict a, Dict b);
  ALLDict operator+(const ALLDict& t);
  ALLDict& operator=(const ALLDict& t);
  friend ostream& operator << (ostream& stream, const ALLDict& a);
  friend istream& operator >> (istream& stream, ALLDict& a);
  friend bool operator==(const  ALLDict& left, const  ALLDict& right) {
    int a=0;
    if (left.size == right.size) {
      for (int i = 0; i < left.size; i++) {
        if (left.ALLD[i].getW() == right.ALLD[i].getW())
          if (left.ALLD[i].getT() == right.ALLD[i].getT()) {
            a++;
          } else return 0;
      }
    }
    return 1;
  };
  ~ALLDict();
private:
  Dict * ALLD;
  int size;
};
#endif  // INCLUDE_ADD_H_