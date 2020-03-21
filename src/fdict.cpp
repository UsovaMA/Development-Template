#include "dict.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
std::string del_ferst(std::string str) {
  int s = std::size(str);
  while (!((str[0] < 'Z') && (str[0] > 'A') || (str[0] < 'z') && (str[0] > 'a') || (str[0] > 'А') && (str[0] < 'Я') || (str[0] > 'а') && (str[0] < 'я'))) {
    for (int i = 1; i < (std::size(str)); i++) {
      str[i - 1] = str[i];
    }
    s = std::size(str);
    str.resize(s - 1);
  }
  return str;
}
bool en(std::string str) {
  int s = std::size(str);
  for (int i = 1; i < s; i++) {
    if ((str[0] >= 'А') && (str[0] <= 'Я') || (str[0] >= 'а') && (str[0] <= 'я')) {
      return 1;// error
    }
  }
  return 0; //ok
}
bool en(char a) {
  if ((a >= 'A') && (a <= 'Z') || (a >= 'a') && (a <= 'z')) return 1;
  return 0; 
}
bool ru(std::string str) {
  int s = std::size(str);
  for (int i = 1; i < s; i++) {
    if ((str[0] >= 'A') && (str[0] <= 'Z') || (str[0] >= 'a') && (str[0] <= 'Z')) {
      return 1;// error
    }
  }
  return 0; //ok
}
bool ru(char a) {
  if ((a >= 'А') && (a <= 'Я') || (a >= 'а') && (a <= 'я')) return 1;
  return 0; 
}
bool definition(std::string str) {
  int s = std::size(str);
  if ((str[s - 1] < 'Z') && (str[s - 1] > 'A') || (str[s - 1] < 'z') && (str[s - 1] > 'a'))
    return 1;
  else return 0;
}
string st() {
  string s;
  getline(cin, s);
  return s;
}
Dict::Dict() {
  word = "Введите слово";
  translation = "Input word";
}
string Dict::getW() {
  return word;
}
string Dict::getT() {
  return translation;
}
string getW(Dict a) {
  return a.word;
}
string getT(Dict a) {
  return a.translation;
}
void Dict::ImW(std::string a) {
  word = a;
}
void Dict::ImT(std::string a) {
  translation = a;
}

Dict::Dict(std::string a, std::string b) {
  word = a;
  translation = b;
  correct();
}
ostream& operator << (ostream& stream, const Dict& a) {
  cout << getW(a) << " - " << getT(a) << endl;
  return stream;
}
istream& operator >> (istream& stream, Dict &a) {
  std::string sch;
  //stream >> sch;
  sch = st();
  sch = del_ferst(sch);
  int i1, i2;
  bool l1, l2;
  l1 = definition(sch);
  l2= !(l1);
  //0-русский, 1-английский
  //находим стыковочные смволы 
  if (l1 == 0) { 
    for (int i = 0; i < size(sch); i++) {
    if (en(sch[i])) i1 = i;
    if (ru(sch[i])) { i2 = i; break; }
    }
  } else {
    for (int i = 0; i < size(sch); i++) {
    if (ru(sch[i])) i1 = i;
    if (en(sch[i])) { i2 = i; break; }
    }
  }
  //делим строку
  a.ImW(sch.substr(0, i1 + 1));
  a.ImT(sch.substr(i2));
  a.correct();
  return stream;
}
void Dict::correct() { 
  //редактор первого символа (w)
  word = del_ferst(word);
  int s = std::size(word);
  //редактор последнего символа (w)
  while (!((word[s-1] < 'Z') && (word[s - 1] > 'A') || (word[s - 1] < 'z') && (word[s - 1] > 'a') || (word[s - 1] > 'А') && (word[s] < 'Я') || (word[s - 1] > 'а') && (word[s - 1] < 'я'))) {
      word.resize(s - 1);
      s = std::size(word);
    }
    

  //редактор первого символа (t)
  translation = del_ferst(translation);
  s = std::size(translation);
  //редактор последнего символа (t)
  while (!((translation[s - 1] < 'Z') && (translation[s - 1] > 'A') || (translation[s - 1] < 'z') && (translation[s - 1] > 'a') || (translation[s - 1] > 'А') && (translation[s] < 'Я') || (translation[s - 1] > 'а') && (translation[s - 1] < 'я'))) {
    translation.resize(s - 1);
    s = std::size(translation);
  }

  //determine the language 
  bool language_w= definition(word), language_t = definition(translation); //0-русский, 1-английский
  if (language_w == language_t)  cout << "ERROR! Two identical languages" << endl;
  else {
    if (language_w == 1) {
//      if(en(word)) cout << "ERROR! Two different languages ​​on one line (w)" << endl;
//      if (ru(translation)) cout << "ERROR! Two different languages ​​on one line (t)" << endl;
    }
    else {
//      if (ru(word)) cout << "ERROR! Two different languages ​​on one line (w)" << endl;
//      if (en(translation)) cout << "ERROR! Two different languages ​​on one line (t)" << endl;
    }
  }
  //word=ru, translation=en;
  if (language_w) { 
  std:string dop = word;
    word = translation;
    translation = dop;
  }
}

ALLDict::ALLDict() {
  ALLD = new Dict[1];
  size = 1;
}
ALLDict::ALLDict(int i) {
  ALLD = new Dict[i];
  size = i;
}
ALLDict::ALLDict(Dict a) {
  ALLD = new Dict[1];
  size = 1; 
  ALLD[0] = a;
}

ALLDict::ALLDict(Dict a, Dict b) {
  ALLD = new Dict[2];
  size = 2;
  ALLD[0] = a;
  ALLD[1] = b;
}
ALLDict ALLDict::operator+(const ALLDict& t) {
  ALLDict res;
  res.size=size+t.size;
  res.ALLD = new Dict[res.size];
  for (int I = 0; I < res.size; I++) {
    int i = 0;
    for (; I < size; I++) {
      res.ALLD[I] = ALLD[i];
      i++;
    }
    i = 0;
    for (; I < t.size; I++) {
      res.ALLD[I] = t.ALLD[i];
      i++;
    }
  }
  return res;
}
//ALLDict& ALLDict::operator=(const ALLDict& t) {
//
//}
//ostream& operator << (ostream& stream, const ALLDict& a) {
//
// }
//istream& operator >> (istream& stream, ALLDict& a) {
//
// }

  
ALLDict::~ALLDict() {
  delete ALLD;
}