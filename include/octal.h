#ifndef INCLUDE_OCTAL_H_
#define INCLUDE_OCTAL_H_

int add(int x, int y);

#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Octal {
  unsigned char *num;
  int size;

public:
  Octal() {
    size = 1;
    num = new unsigned char[size];
    num[0] = 0;
  }

  Octal(const Octal &c) {
    int i;
    size = c.size;
    num = new unsigned char[size];
    // иначе два объекта будут ссылаться на один и тот же отдел памяти
    for (i = 0; i < size; ++i) {
      num[i] = c.num[i];
    }
  }

  Octal(string hexNum, int _size) {
    int i = 0, j;
    size = _size + 1;
    num = new unsigned char[size];
    while (hexNum[i] != '\0')
      ++i;
    for (--i, j = 0; i >= 0; --i, ++j)
      num[j] = hexNum[i];
    for (j; j < size; ++j)
      num[j] = '0';
  }

  Octal operator=(const Octal &c);
  Octal operator+(const Octal &c);
  Octal operator-(const Octal &c);
  bool operator==(const Octal &c);
  bool operator<(const Octal &c);
  bool operator>(const Octal &c);
  friend bool operator<(const Octal &c1, const Octal &c2);
  friend bool operator>(const Octal &c1, const Octal &c2);
  friend bool operator==(const Octal &c1, const Octal &c2);
  unsigned char& operator[](const int index);
  friend std::ostream& operator<< (std::ostream &out, const Octal &c);
  //friend std::istream& operator>> (std::istream &in, Octal &c);
  friend std::ofstream& operator<<(std::ofstream& ofs, const Octal &c);
  friend std::ifstream& operator>>(std::ifstream& ifs, const Octal &c);

};

#endif  // INCLUDE_OCTAL_H_
