// Copyright 2020 <Diana>
  // #pragma once
#ifndef INCLUDE_DICT_H_
#define INCLUDE_DICT_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Dict { //слово-перевод
 public:
  Dict();
  Dict(const Dict &a);
  Dict(std::string a, std::string b);
  void OB(std::string a);
  string getW();
  string getT();
  friend string getW(Dict a);
  friend string getT(Dict a);
  void ImW(std::string a);
  void ImT(std::string a);
  void correct();
  friend ostream& operator << (ostream& stream, const Dict& a);
  friend istream& operator >> (istream& stream, Dict& a);
  ~Dict();

 private:
  std::string word, translation;
};

#endif  // INCLUDE_DICT_H_
