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
  void  AllContact::Dop—on(Contact a);
  int  AllContact::i_poisk_fio(string i, string f, string o );
  friend bool operator==(const  AllContact& left, const  AllContact& right) {
    if (left.size == right.size) {
      for (int i = 0; i < right.size; i++) {
        if (left.con != right.con) return 0;
      }
      return 1;
    }
    return 0;
  }
  friend bool operator!=(const  AllContact& left, const  AllContact& right) {
    return (!(left == right));
  }
  //friend ostream& operator << (ostream& stream, const Contact& a);
  //friend istream& operator >> (istream& stream, Contact& a);
  ~AllContact();
};

#endif  // INCLUDE_AC_H_
