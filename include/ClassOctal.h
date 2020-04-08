// Copyright 2020 Podovinnikov
#include <iostream>
#include <fstream>

#define MAX 1000

using namespace std;

class Octal {
public:
  Octal();
  Octal(int _size);
  Octal(const Octal& c);
  Octal(const char _number[], int _size);

  void input();
  void output();
  friend ostream& operator<<(ostream& stream, const Octal& c);
  friend istream& operator>>(istream& stream, Octal& c);

  Octal& operator=(const Octal& c);

  bool operator!=(const Octal& c);

  bool operator==(const Octal& c) {
    bool res = true;
    if (size == c.size) {
      for (int i = 0; i < c.size; i++) {
        if (number[i] != c.number[i]) {
          res = false;
          break;
        }
      }
    }
    else {
      res = false;
    }
    return res;
  }

  friend bool operator==(const Octal& left, const Octal& right) {
    bool res = true;
    if (left.size == right.size) {
      for (int i = 0; i < left.size; i++) {
        if (left.number[i] != right.number[i]) {
          res = false;
          break;
        }
      }
    }
    else {
      res = false;
    }
    return res;
  }

  Octal operator+(const Octal& c);
  Octal operator-(const Octal& c);

private: 
  int size;
  char* number;
};
