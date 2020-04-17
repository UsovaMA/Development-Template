#pragma once
#ifndef INCLUDE_AC_H_
#define INCLUDE_AC_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Contacts.h"
using namespace std;
class AllContact {
 private:
  Contact *con;
  int size;

 public:
  AllContact();
  AllContact(Contact *a, int s);
  AllContact(AllContact &a);
  AllContact& operator=(const AllContact& t);
  int getSize();
  string AllContact::getPH(int nom);
  int AllContact::min(int f_el);
  void  AllContact::Alphabet();
  void  AllContact::Dop—on(Contact a);
  void  AllContact::to_screen(int num);
  void  AllContact::ChangeC(int nom);
  void  AllContact::Del—on(int nom);
  void imFav(int nom, bool like);
  bool getFav(int nom);
  int  AllContact::i_poisk_fio(string i, string f, string o);
  friend bool operator==(const  AllContact& left, const  AllContact& right) {
    if (left.size == right.size) {
      for (int i = 0; i < right.size; i++) {
        if (left.con[i] != right.con[i]) return 0;
      }
      return 1;
    }
    return 0;
  }
  friend bool operator!=(const  AllContact& left, const  AllContact& right) {
    return (!(left == right));
  }
  friend ostream& operator << (ostream& stream, const AllContact& a);
  ~AllContact();
};

#endif  // INCLUDE_AC_H_
