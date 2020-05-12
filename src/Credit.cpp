#include "Credit.h"
#include <iostream>
#include <fstream>

using namespace std;

ProcCenter::ProcCenter() {
  number = "";
  fullname = "";
  sumChet = 0;
  year = 0;
  sumZaim = 0;
  stavka = 0;
  pogasheno = 0;
  ostalos = 0;
}

ProcCenter::ProcCenter(bool k) {
  number = "0001";
  fullname = "Mr Robot";
  sumChet = 100500;
  year = 3;
  sumZaim = 10000;
  stavka = 12;
  pogasheno = 1300;
  ostalos = 98200;
}

ProcCenter::ProcCenter(int k) {
  cout << "Your Account number: ";
  cin >> number;
  while (number.length() != 4) { // gde-to tut proverka na to, chto eto chisla
    cout << "Error! Enter correct number";
    cin >> number;
  }
  cout << "Your full name: ";
  getline(cin, fullname);
  cout << "Your sum on account: ";
  cin >> sumChet;
  year = 0;
  sumZaim = 0;
  stavka = 0;
  pogasheno = 0;
  ostalos = 0;
}

ProcCenter::ProcCenter(int _year, int _sumZaim, int _stavka) {
  year = 3;
  sumZaim = 10000;
  stavka = 12;
  const char* lol = number.c_str();
  int n = atoi(lol);
  update(n);
}

ProcCenter::~ProcCenter() {
  number = "";
  fullname = "";
  sumChet = NULL;
  year = NULL;
  sumZaim = NULL;
  stavka = NULL;
  pogasheno = NULL;
  ostalos = NULL;
}

bool ProcCenter::vhod() {
  bool num = false;
  //if 
  //num = true;
  //return num;
  return num;
}

void ProcCenter::setinfo(ProcCenter& person) {

  string path = "AccountsBank.txt";

  ofstream fout;
  fout.open(path, ofstream::app);

  if (!fout.is_open()) {
    cout << "Error! Not opened file" << endl;
  }
  else {
    fout.write((char*)&person, sizeof(ProcCenter));
    cout << "You are registered!";
  }
  fout.close();
}

void ProcCenter::getinfo(int num) {
  string path = "AccountsBank.txt";

  ofstream fin;
  fin.open(path, ofstream::app);

  if (!fin.is_open()) {
    cout << "Error! Not opened file" << endl;
  }
  else {
    ProcCenter person;

    while (fin.write((char*)&person, sizeof(ProcCenter))) {

    }

  }
  fin.close();
}