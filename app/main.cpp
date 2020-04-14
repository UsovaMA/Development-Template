// Copyright 2020 <Diana Lukashuk>
#include <iostream>
#include <fstream>
#include <clocale>
#include "Contacts.h"
#include "AllContact.h"
#include "FUN.h"
#include "windows.h"
using namespace std;

int main() {
  setlocale(LC_ALL, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int i = 0;
  //exampleIn();
  Contact a("Mary", "I", "Sh");
  AllContact A;
  A.DopСon(a);
  int s = A.getSize();
  
  /*Hex a("5FA", 0), b("5FA", 0);
  while (i != 4) {
    switch (i) {
    case 0:
      cout << " ________________ " << endl;
      cout << "| Make a choice  |" << endl;
      cout << "|1- Manual entery|" << endl;
      cout << "|3- Guick check  |" << endl;
      cout << "|4- Exit         |" << endl;
      cout << "|________________|" << endl;
      cin >> i;
      break;
    case 1:
      cout << "Enter ferst number: ";
      cin >> a;
      cout << "Enter second number: ";
      cin >> b;
      cout << "Entered numbers: " << a << ", " << b << endl;
      i = 5;
      break;
    case 3:
      cout << "number A " << a << ", number B " << b << endl;
      cout << "number A + B = " << a + b << endl;
      cout << "number A - B = " << a - b << endl;
      cout << "A < B = " << (a < b);
      cout << "   A <= B = " << (a <= b) << endl;
      cout << "A > B = " << (a > b);
      cout << "   A >= B = " << (a >= b) << endl;
      cout << "(A == B) = " << (a == b);
      cout << "   (A != B) = " << (a != b) << endl;
      i = 0;
      break;
    case 5:
      cout << " ________________ " << endl;
      cout << "| Make a choice  |" << endl;
      cout << "|1- Compare      |" << endl;
      cout << "|2- A + B        |" << endl;
      cout << "|3- A - B        |" << endl;
      cout << "|4- Exit         |" << endl;
      cout << "|5- Step back    |" << endl;
      cout << "|________________|" << endl;
      cin >> i;
      if (i == 5) i = 0;
      if (i == 3) {
        cout << "number A - B = " << a - b << endl;
        i = 5;
      }
      if (i == 2) {
        cout << "number A + B = " << a + b << endl;
        i = 5;
      }
      if (i == 1) {
        if (a == b) cout << "A == B";
        if (a != b) cout << "A != B";
        cout << endl;
        if (a > b) cout << "A > B   ";
        if (a < b) cout << "A < B   ";
        if (a >= b) cout << "A >= B   ";
        if (a <= b) cout << "A <= B   ";
        cout << endl;
        i = 5;
      }
      break;
    default:
      i = 0;
      break;
    }
  }*/
  system("pause");
}