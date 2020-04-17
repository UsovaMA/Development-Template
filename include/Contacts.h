#pragma once
#ifndef INCLUDE_C_H_
#define INCLUDE_C_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Contact { 
private:
  std::string lname;  // Name
  std::string fname;  // Familia
  std::string patro;  // Otchestvo
  std::string phone;  // Number of phpone
  std::string DatBir;  // Date of birthday
  bool fav;  // 1-like, 0-dislike
public:
  Contact();
  Contact(string s);
  Contact(string n, string f, string pat);
  Contact(string n, string f, string pat, string ph, bool like);
  Contact(Contact &a);
  friend bool operator==(const  Contact& left, const  Contact& right) {
    if (left.fname != right.fname) return 0;
    if (left.lname != right.lname) return 0;
    if (left.patro != right.patro) return 0;
    if (left.phone != right.phone) return 0;
    if (left.DatBir != right.DatBir) return 0;
    if (left.fav != right.fav) return 0;
    return 1;
  }
  friend bool operator!=(const  Contact& left, const  Contact& right) {
    return (!(left == right));
  }
  Contact& operator=(const Contact& t);
  Contact& operator=(const Contact* t);
  string getNAME(); 
  string getFn();
  string getPA();
  string getPH();
  string getBD();
  bool getFA();
  void imNAME(string n);
  void imFn(string n);
  void imPA(string n);
  void imPH(string n);
  void imFav(bool a);
  friend ostream& operator << (ostream& stream, const Contact& a);
  friend istream& operator >> (istream& stream, Contact& a);
  void  Contact::Change();
  ~Contact();
  friend class Allcontact;
};

#endif  // INCLUDE_C_H_