#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_

#pragma once
#include <iostream>
#include <stdexcept>


using namespace std;
class Octal {
private:
  size_t size;
  unsigned char* dec;
public:
  Octal();
  ~Octal();
  Octal(const Octal& c);
  Octal(const char* get);
  Octal operator+(const Octal& c);
  bool operator == (const Octal& c);
  Octal& operator = (const Octal& c);
  friend ostream& operator<<(ostream& stream, const Octal& c);
  friend istream& operator>>(istream& stream, Octal& c);
};
#endif  // INCLUDE_ADD_H_