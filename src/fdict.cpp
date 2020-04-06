#include "..\include\ALLDict.h"
#include "..\include\dict.h"
#include "..\include\ALLDict.h"
#include "dict.h"
#include "ALLDict.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;
bool en(std::string str) {
  int s = std::size(str);
  for (int i = 1; i < s; i++) {
    if ((str[0] >= 'А') && (str[0] <= 'Я') || (str[0] >= 'а') && (str[0] <= 'я')) {
      return 1;  // error
    }
  }
  return 0;  // ok
}
bool en(char a) {
  if ((a >= 'A') && (a <= 'Z') || (a >= 'a') && (a <= 'z')) return 1;
  return 0;
}
bool ru(std::string str) {
  int s = std::size(str);
  for (int i = 1; i < s; i++) {
    if ((str[0] >= 'A') && (str[0] <= 'Z') || (str[0] >= 'a') && (str[0] <= 'Z')) {
      return 1;  // error
    }
  }
  return 0;  // ok
}
bool ru(char a) {
  if ((a >= 'А') && (a <= 'Я') || (a >= 'а') && (a <= 'я')) return 1;
  return 0;
}
bool definition(std::string str) {
  int s = std::size(str);
  if ((str[0] <= 'Z') && (str[0] >= 'A') || (str[0] <= 'z') && (str[0] >= 'a')) {
    return 1;
  } else {
  return 0;
  }
}
std::string del_ferst(std::string str) {
  int s = std::size(str);
  while (!((ru(str[0])) || (en(str[0])))) {
    if (s == 1) return str;
    for (int i = 1; i < (std::size(str)); i++) {
      str[i - 1] = str[i];
    }
    s = std::size(str);
    str.resize(s);
  }
  return str;
}

string st() {
  string s;
  getline(cin, s);
  return s;
}
Dict::Dict() {
  word = "Cлово";
  translation = "Word";
}
Dict::Dict(const Dict & a) {
  word = a.word;
  translation = a.translation;
}
string Dict::getW() {
  return word;
}
string Dict::getT() {
  return translation;
}
int ALLDict::getS() {
  return size;
}

bool ALLDict::Poisk(string str) {  // bool Poisk(string str);
  bool leng = definition(str);  // 1 en, 0 ru
  string g;
  if (leng) {
    for (int i = 0; i < size; i++) {
      g = ALLD[i].getT();
      if (g== str) return 1;
    }
  } else {
    for (int i = 0; i < size; i++) {
      g = ALLD[i].getW();
      if (g == str) return 1;
    }
  }
  return 0;
}
string ALLDict::Tran(string str) {
  bool leng = definition(str);  // 1 en, 0 ru
  string g, r;
  if (leng) {
    for (int i = 0; i < std::size(str); i++) {
      g = ALLD[i].getT();
      if (g == str) {
        r = ALLD[i].getW();
        return r;
      }
    }
  } else { 
    for (int i = 0; i < std::size(str); i++) {
      g = ALLD[i].getW();
      if (g == str) {
        r = ALLD[i].getT();
        return r;
      }
    }
  }
  return "-";
}
void ALLDict::ChTran(string str, string zam) {
  bool leng = definition(str);  // 1 en, 0 ru
  string g, r;
  if (leng) {
    for (int i = 0; i < size; i++) {
      g = ALLD[i].getT();
      if (g == str) {
        ALLD[i].ImW(zam);
        break;
      }
    }
  } else {
    for (int i = 0; i < size; i++) {
      g = ALLD[i].getW();
      if (g == str) {
        ALLD[i].ImT(zam);
        break;
      }
    }
  }
}
string getW(Dict a) {
  return a.word;
}
string getT(Dict a) {
  return a.translation;
}
void Dict::OB(std::string a) {
  string sch = a;
  sch = del_ferst(sch);
  int i1, i2;
  bool l1, l2;
  l1 = definition(sch);
  l2 = !(l1);
  // 0-Russian, 1-English
  // find docking symbols
  if (l1 == 0) {
    for (int i = 0; i < size(sch); i++) {
      if (ru(sch[i])) i1 = i;
      if (en(sch[i])) { i2 = i; break; }
    }
  } else {
    for (int i = 0; i < size(sch); i++) {
      if (en(sch[i])) i2 = i;
      if (ru(sch[i])) { i1 = i; break; }
    }
  }
  // divide the line
  if ((i1 > -1) && (i2 > -1)) {
    if (i1 < i2) {  // word, translation
      word = (sch.substr(0, i1 + 1));
      translation = (sch.substr(i2));
    } else {
      word = (sch.substr(0, i2 + 1));
      translation = (sch.substr(i1));
    } correct();
  } else {
    cout << "two identical languages" << endl;
    word = ("Ошибка");
    translation = ("ERROR");
  }
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
  while (sch == "") {
  getline(cin, sch);
  }
  sch = del_ferst(sch);
  int i1 = -1, i2 = -1;
  bool l1, l2;
  l1 = definition(sch);
  l2 = !(l1);
  // 0-Russian, 1-English
  // find docking symbols
  if (l1 == 0) {
    for (int i = 0; i < size(sch); i++) {
    if (ru(sch[i])) i1 = i;
    if (en(sch[i])) { i2 = i; break; }
    }
  } else {
    for (int i = 0; i < size(sch); i++) {
    if (en(sch[i])) i2 = i;
    if (ru(sch[i])) { i1 = i; break; }
    }
  }
  // divide the line
  if ((i1 > -1) && (i2 > -1)) {
    if (i1 < i2) {
      a.ImW(sch.substr(0, i1 + 1));
      a.ImT(sch.substr(i2));
    } else {
      a.ImW(sch.substr(0, i2 + 1));
      a.ImT(sch.substr(i1));
    } a.correct();
  } else {
    cout << "two identical languages" << endl;
    a.ImW("Ошибка");
    a.ImT("ERROR");
  }
  return stream;
}
void Dict::correct() {
  // first character editor (w)
  word = del_ferst(word);
  int s = std::size(word);
  // last character editor (w)
  if (s > 1) {
    while (!((ru(word[s-1])) || (en(word[s - 1])))) {
      if (s > 1) {
        word.resize(s - 1);
        s = std::size(word);
      }
    }
  }

  // first character editor (t)
  translation = del_ferst(translation);
  s = std::size(translation);
  // last character editor (t)
  if (s > 1) {
    while (!((ru(translation[s - 1])) || (en(translation[s - 1])))) {
      translation.resize(s - 1);
      s = std::size(translation);
    }
  }
  // determine the language
  bool language_w = definition(word), language_t = definition(translation);
  // 0-Russian, 1-English
  if (language_w == language_t) {
  cout << "ERROR! Two identical languages" << endl;
  } else {
    if (language_w) {
    std:string dop = word;
    word = translation;
    translation = dop;
    }
  }
  // word=ru, translation=en;
}

ALLDict::ALLDict() {
  ALLD = 0;
  size = 0;
}
ALLDict::ALLDict(const ALLDict & a) {
  if (size >= 0) {
    delete[] ALLD;
  }
  size = a.size;
  ALLD = new Dict[a.size];
  for (int i = 0; i < size; i++) {
    ALLD[i] = a.ALLD[i];
  }
}
void  ALLDict::DopSTR(Dict a) {
  ALLDict res;
  res.size = size + 1;
  res.ALLD = new Dict[res.size];
  for (int I = 0; I <= res.size - 2; I++) {
    res.ALLD[I] = ALLD[I];
  }
  res.ALLD[res.size - 1] = a;
  (*this) = res;
}
ALLDict::ALLDict(Dict a, Dict b) {
  ALLD = new Dict[2];
  size = 2;
  ALLD[0] = a;
  ALLD[1] = b;
}
ALLDict::ALLDict(Dict a) {
  ALLD = new Dict[1];
  size = 1;
  ALLD[0] = a;
}

ALLDict ALLDict::operator+(const ALLDict& t) {
  ALLDict res;
  res.size = size+t.size;
  res.ALLD = new Dict[res.size];
  for (int I = 0; I < res.size; I++) {
    int i = 0;
    for (; I < size; I++) {
      res.ALLD[I] = ALLD[i];
      i++;
    }
    i = 0;
    for (; I < res.size; I++) {
      res.ALLD[I] = t.ALLD[i];
      i++;
    }
  }
  return res;
}
ALLDict& ALLDict::operator=(const ALLDict& t) {
  size = t.size;
  if (ALLD) { delete[] ALLD; }
  ALLD = new Dict[t.size];
  for (int i = 0; i < t.size; i++) {
    ALLD[i] = t.ALLD[i];
  }
  return (*this);
}
ostream& operator << (ostream& stream, const ALLDict& a) {
  string T, W;
  for (int i = 0; i < a.size; i++) {
    cout << a.ALLD[i].getW() << " - " << a.ALLD[i].getT() << endl;
  }
  return stream;
}
istream& operator >> (istream& stream, ALLDict& a) {
  cout << "How many words do you want input?  ";
  stream >> a.size;
  if (a.size <= 0)
    throw std::logic_error("Error: incorrect choice\n");
  a.ALLD = new Dict[a.size];
  cout << "example- Russia Россия" << endl;
  for (int i = 0; i < a.size; i++) {
    cin >> a.ALLD[i];
  }
  return stream;
}

Dict::~Dict() {
}

ALLDict::~ALLDict() {
  delete[] ALLD;
  size = 0;
}

