// Copyright 2020 Podovinnikov
#include <iostream>
#include <fstream>
#include "ClassOctal.h"


#define MAX 1000

using namespace std;

Octal::Octal() {
  size = 5;
  number = 0;
  char* number = new char[1000];
  for (int i = 0; i < size; i++)
    number[i] = '0';
}
Octal::Octal(int _size){
  size = _size;
  number = 0;
  char* number = new char[1000];
  for (int i = 0; i < _size; i++)
    number[i] = '0';
}

Octal::Octal(const Octal& c) {
  size = c.size;
  number = c.number;
  const int s = size;
  char* number = new char[s];
}

Octal::Octal(const char _number[], int _size) {
  size = _size;
  number = (char*)_number;
  const int s = size;
  char* number = new char[s];
}

ostream& operator<<(ostream& stream, const Octal& c);
istream& operator>>(istream& stream, Octal& c);

Octal& Octal::operator=(const Octal& c) {
  const int size_ = c.size;
  (*this).number = new char[size_];
  (*this).size = c.size;
  for (int i = 0; i < size_; i++) {
    (*this).number[i] = c.number[i];
  }
  return *this;
}

bool Octal::operator!=(const Octal& c) {
  bool res = true;
  if (size != c.size) {
    res = true;
    return res;
  }
  if (size == c.size) {
    for (int i = 0; i < c.size; i++) {
      if (number[i] != c.number[i]) {
        res = true;
        break;
      }
    }
  }
  else {
    res = false;
    return res;
 
  }
  }


int u = 0;

void Octal::output() {
  
  

   cout << "Number = ";
     
   for (int i =0; i<u; i++) {
     cout << number[i];
   }
   cout << endl;
}

ostream& operator<<(ostream& stream, const Octal& c) {

  


  for (int i = 0; i < c.size; i++) {
    stream << c.number[i];
  }

  cout << endl;
  return stream;
}

void Octal::input() {
  cout << "Innput size of Octal number: ";
  cin >> size;
  cout << endl;
  cout << "Input Octal Number: " << endl;
  const int _s = size;
  number = new char[_s];

  for (int i = 0; i < size; i++) {
    cin >> number[i];
  }
}

istream& operator>>(istream& stream_, Octal& c) {

  cout << "Input size of Octal number: ";
  stream_ >> c.size;
  cout << endl;
  cout << "Input Octal Number: " << endl;

  const int _s = c.size;
  c.number = new char[_s];


  for (int i = 0; i < c.size; i++)
    stream_ >> c.number[i];

  return stream_;

}

Octal Octal::operator+(const Octal& c) {

  int numberInt1[1000];
  int numberInt2[1000];
  int s = 0;
  int res_numberInt[1000];
  
  if (size > c.size || size==c.size)
    s = size;
  else
    s = c.size;
  u = s;
  for (int i = 0; i < s; i++) {
    switch (c.number[i])
    {
    case '0':
    {
      numberInt2[i] = 0;
      break;
    }
    case '1':
    {
      numberInt2[i] = 1;
      break;
    }
    case '2':
    {
      numberInt2[i] = 2;
      break;
    }
    case '3':
    {
      numberInt2[i] = 3;
      break;
    }
    case '4':
    {
      numberInt2[i] = 4;
      break;
    }
    case '5':
    {
      numberInt2[i] = 5;
      break;
    }
    case '6':
    {
      numberInt2[i] = 6;
      break;
    }
    case '7':
    {
      numberInt2[i] = 7;
      break;
    }
    
    }
  }

  for (int i = 0; i < s; i++) {
    switch (number[i])
    {
    case '0':
    {
      numberInt1[i] = 0;
      break;
    }
    case '1':
    {
      numberInt1[i] = 1;
      break;
    }
    case '2':
    {
      numberInt1[i] = 2;
      break;
    }
    case '3':
    {
      numberInt1[i] = 3;
      break;
    }
    case '4':
    {
      numberInt1[i] = 4;
      break;
    }
    case '5':
    {
      numberInt1[i] = 5;
      break;
    }
    case '6':
    {
      numberInt1[i] =6;
      break;
    }
    case '7':
    {
      numberInt1[i] = 7;
      break;
    }
    }
  }
  int tmp = 0;

  for (int i = 0; i < size/2; i++) {           
    tmp = numberInt1[i];
    numberInt1[i] = numberInt1[size - 1 - i];
    numberInt1[size - 1 - i] = tmp;
  }
  for(int i = 0; i < c.size/2;i++) {
    tmp = numberInt2[i];
    numberInt2[i] = numberInt2[c.size - 1 - i];
    numberInt2[c.size - 1 - i] = tmp;
  }

  Octal res;
  const int _s = s;
  res.size = _s;
  res.number = new char[_s];
  
  for (int i = 0; i<s; i++) {          
    if (numberInt1[i] < 0) {
      numberInt1[i] = 0;
    }
    if (numberInt2[i] < 0) {
      numberInt2[i] = 0;
    }
      res_numberInt[i] =  numberInt1[i] + numberInt2[i];
      if (res_numberInt[i] > 7) {
        if (numberInt1[i+1] < 0) 
          numberInt1[i+1] = 1;
         else
        numberInt1[i + 1]++;
        res_numberInt[i] = res_numberInt[i] - 8;
        if (abs(size - c.size) <1 || abs(c.size - size) <1)   
        s++;
      }
  }
  for (int i = 0; i < s; i++) {
    res.number[i] = (res_numberInt[i]) + '0';
  }
  int tmp3 = 0;

  for (int i = 0; i < _s / 2; i++) {
    tmp3 = res.number[i];
    res.number[i] = res.number[u - 1 - i];
    res.number[u - 1 - i] = tmp3;
  }
  
    return res;
}

Octal Octal::operator-(const Octal& c) {
  int numberInt1_[1000];
  int numberInt2_[1000];
  int res_numberInt_[1000];
  int s = 0;
  if (size > c.size || size == c.size) {
    s = size;
  }
  else {
    s = c.size;
  }

  u = s;
  char sh;
  for (int i = 0; i < s; i++) {
    if (size > c.size || size == c.size) {
      sh = c.number[i];
    }
    else {
      sh = number[i];
    }
    switch (sh)
    {
    case '0':
    {
      numberInt2_[i] = 0;
      break;
    }
    case '1':
    {
      numberInt2_[i] = 1;
      break;
    }
    case '2':
    {
      numberInt2_[i] = 2;
      break;
    }
    case '3':
    {
      numberInt2_[i] = 3;
      break;
    }
    case '4':
    {
      numberInt2_[i] = 4;
      break;
    }
    case '5':
    {
      numberInt2_[i] = 5;
      break;
    }
    case '6':
    {
      numberInt2_[i] = 6;
      break;
    }
    case '7':
    {
      numberInt2_[i] = 7;
      break;
    }
    case ' ':        
    {
      numberInt2_[i] = 0;
      break;
    }

    }
  }

  for (int i = 0; i < s; i++) {
    if (size > c.size || size == c.size) {
      sh = number[i];
    }
    else {
      sh = c.number[i];
    }
    switch (sh)
    {
    case '0':
    {
      numberInt1_[i] = 0;
      break;
    }
    case '1':
    {
      numberInt1_[i] = 1;
      break;
    }
    case '2':
    {
      numberInt1_[i] = 2;
      break;
    }
    case '3':
    {
      numberInt1_[i] = 3;
      break;
    }
    case '4':
    {
      numberInt1_[i] = 4;
      break;
    }
    case '5':
    {
      numberInt1_[i] = 5;
      break;
    }
    case '6':
    {
      numberInt1_[i] = 6;
      break;
    }
    case '7':
    {
      numberInt1_[i] = 7;
      break;
    }
    case ' ':                     
    {
      numberInt1_[i] = 0;
      break;
    }
    }
  }
  int tmp = 0;
  int size1=0;
  int size2 = 0;
  int sizeMax = 0;
  if (size > c.size || size == c.size) {
    size1 = size;
   sizeMax = size;
    size2 = c.size;
  }
  else {
    size1 = c.size;
    sizeMax = c.size;
    size2 = size;
  }
  for (int i = 0; i < size1 / 2; i++) {             
    tmp = numberInt1_[i];
    numberInt1_[i] = numberInt1_[size1 - 1 - i];
    numberInt1_[size1 - 1 - i] = tmp;
  }
  for (int i = 0; i < size2 / 2; i++) {
    tmp = numberInt2_[i];
    numberInt2_[i] = numberInt2_[size2 - 1 - i];
    numberInt2_[size2 - 1 - i] = tmp;
  }

  for (int i = 0; i < s; i++) {
    if (numberInt2_[i] < 0 || numberInt1_[i] < 0) {
      res_numberInt_[i] = numberInt1_[i];
    }
    else {
      if (numberInt1_[i] > numberInt2_[i]) {
        res_numberInt_[i] = numberInt1_[i] - numberInt2_[i];
      }
      else {
        if (numberInt1_[i] == numberInt2_[i]) {
          res_numberInt_[i] = 0;
        }
        else {
          if (numberInt1_[i] < numberInt2_[i]) {
            numberInt1_[i + 1] --;
            numberInt1_[i] = numberInt1_[i] + 8;
            res_numberInt_[i] = numberInt1_[i] - numberInt2_[i];
          }
        }
      }
    }
  }

  int p;
  if (size > c.size || size == c.size) {
    p = s;
  }
  else {
    p = s + 1;
  }
  Octal res(p);
  const int _s = s;
  if (size > c.size || size == c.size) {
    res.number = new char[_s];
    res.size = _s;
  }
  else {
    res.number = new char[_s + 1];
    res.size = _s + 1;
  }
  
    for (int i = 0; i < s; i++) {
      res.number[i] = (res_numberInt_[i]) + '0';
    }

    if (size < c.size) {
      res.number[p-1] = '-';
    }
    char tmp3 = '1';

    for (int i = 0; i < p / 2; i++) {
      tmp3 = res.number[i];
      res.number[i] = res.number[p - 1 - i];
      res.number[p - 1 - i] = tmp3;

    }

    return res;
  }
