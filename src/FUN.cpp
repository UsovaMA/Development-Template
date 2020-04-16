
#include "FUN.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;

bool ver_let_char(char a) {
  if ((a >= 'А') && (a <= 'Я') || (a >= 'а') && (a <= 'я')) return 1;
  if ((a >= 'A') && (a <= 'Z') || (a >= 'a') && (a <= 'z')) return 1;
  return 0;
}

bool ver_one_word(string str) {
  int s = str.size();
    for (int i = 0; i < s; i++) {
      if (ver_let_char(str[i])) return 1;
    }
    return 0;
}
bool ver_three_word(string str) {
  setlocale(LC_ALL, "Russian");
  int s = str.size(), nl=-1;
  for (int i = 0; i < s; i++) {
    if (ver_let_char(str[i])) {
      nl = i;
      break;
    }  // первое слово
  }
  if (nl == -1) { 
    cout << "Error! Must be three letters (words) separated by spaces" << endl;
    return 0;
  }
  int nld = nl;
  for (int i = nl+1; i < s; i++) {
    if (!(ver_let_char(str[i]))) {
      nl = i;
      break;
    } 
  }  // пробел между первым и вторым
  if (nl == nld) {
    cout << "Program found only one word, need three (maybe you missed a space?)" << endl;
    return 0;
  }
  nld = nl;
  for (int i = nl + 1; i < s; i++) {
    if (ver_let_char(str[i])) {
      nl = i;
      break;
    }
  }  // второе слово
  if (nl == nld) {
    cout << "Pprogram did not find the second word, need three (maybe you missed a space?)" << endl;
    return 0;
  }
  nld = nl;
  for (int i = nl + 1; i < s; i++) {
    if (!(ver_let_char(str[i]))) {
      nl = i;
      break;
    }
  }  // пробел между вторым и третьим
  if (nl == nld) {
    cout << "Program found only two word, need three (maybe you missed a space?)" << endl;
    return 0;
  }
  for (int i = nl + 1; i < s; i++) {
    if (ver_let_char(str[i])) {
      nl = i;
      break;
    }
  }  // третье слово
  if (nl == nld) {
    cout << "Program found only two word, need three" << endl;
    return 0;
  }
  return 1;
}
bool checkFIO(string f1, string i1, string o1, string f2, string i2, string o2) {
  if ((f1 == f2) && (o1 == o2) && (i1 == i2)) return 1;
  return 0;
}
//проверка одинаковые ли имя и фамилия
bool poisk_let_word(char a, string f) {
    if (f.size() > 0) {
      if (f[0] == a) return 1;
    }
    return 0;
}
//Поиск по первой букве


string breakdown1(string str) {
  int s = str.size();
  string res=" ";
  while (!(ver_let_char(str[0]))) {
      for (int i = 1; i < s; i++) {
        str[i - 1] = str[i];
      }
    s--;
    str.resize(s);
  } //  Remove extra spaces at the beginning
  int j = 0;
  for (int i = 0; i < s; i++) {
    if (ver_let_char(str[i])) {
      res.resize(j + 1);
      res[j] = str[i]; 
      j++;
    } else break;
  }
  return res;
}
string breakdown2(string str) {
  int s = str.size();
  string res=" ";
  while (!(ver_let_char(str[0]))) {
    for (int i = 1; i < s; i++) {
      str[i - 1] = str[i];
    }
    s--;
    str.resize(s);
  } //  Remove extra spaces at the beginning
  int i = 0;
    while (ver_let_char(str[i])) {
      i++;
    }  // word
    while (!(ver_let_char(str[i]))) {
      i++;
    }  // space
    int j = 0;
    while ((ver_let_char(str[i]))) {
      res.resize(j + 1);
      res[j] = str[i];
      j++;
      i++;
    } // 2 word
  return res;
}
string breakdown3(string str) {
  int s = str.size();
  string res= " ";
  while (!(ver_let_char(str[0]))) {
    for (int i = 1; i < s; i++) {
      str[i - 1] = str[i];
    }
    s--;
    str.resize(s);
  } //  Remove extra spaces at the beginning
  int i = 0;
    while (ver_let_char(str[i])) {
      i++;
    }  // word
    while (!(ver_let_char(str[i]))) {
      i++;
    }  // space
    while ((ver_let_char(str[i]))) {
      i++;
    } // 2 word
    while (!(ver_let_char(str[i]))) {
      i++;
    }  // space
    int j = 0;
    while ((ver_let_char(str[i]))) {
      res.resize(j + 1);
      res[j] = str[i];
      j++;
      i++;
    } // 3 word
  return res;
}



void exampleIn() {
  cout << "input example" << endl;
  cout << "            name: Марья Ивановна Королева" << endl;
  cout << "           phone: 88005553535"<< endl;
  cout << "date of birthday: 21.05.1995" << endl;
  cout << "       favorites: 1 (or 0)        (Comment: 1- yes, 0- no)" << endl;
}