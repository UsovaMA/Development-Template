// Copyright 2020 Podovinnikov
#include <iostream>
#include <fstream>
#include "ClassOctal.h"

using namespace std;

int main() {
    
  fstream f;
  f.open("Octal3.txt", fstream::in| fstream::out| fstream::app);
  if (!f)
  {
    cout << "Close\n\n";
  }
  else
  {
    cout << "Open\n\n";
  }
 Octal c1("37251", 5);
  Octal c2("3122", 4);
  Octal c8("2305", 4);
  Octal c9("617", 3);
  Octal c11("1232", 4);
  Octal c12("420", 3);
  Octal c13(c12 + c11);
  Octal c3(c2 + c1);
  Octal c4;
  Octal c5(c2 - c1);
  Octal c6;
  Octal c7;
  Octal c10(c8 + c9);
  Octal c14(c11 - c12);
  Octal c30("420", 3);
  Octal c31("30",2);
  Octal c32(c31 - c30);
  cout << "30 - 420" << endl;
  //c5 = c2 - c1;
  cout << c32;
  cin >> c7;
  cout << endl;
  cout << "3122 - 37251" << endl;
  c5 = c2 - c1;
  cout << c5;
  cout << "1232 - 420" << endl;
  c14 = c11 - c12;
  cout << c14;
  cout << "420 + 1232" << endl;
  c13 = c12 + c11;
  cout << c13;
  
  cout << "2305 + 617" << endl;
  c10 = c8 + c9;
  cout << c10;
  cout << "3122 + 37251" << endl;
  c3 = c2 + c1;
  cout << c3; 
  cout << "37251 - 3122" << endl;
  c4 = c1 - c2;
  cout << c4;
  

  if (c1 == c1)
    cout << "c1 = c1" << endl;
  else
    cout << "c1 != c1" << endl;

  if (c1 != c2)
    cout << "c1 != c2" << endl;
  else
    cout << "c1 == c2" << endl;



  f << c1;

  f.close();
  
  system("pause");
}

