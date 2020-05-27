#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>        
#include <conio.h>
#include <windows.h>
#include <iostream>


using namespace std;

struct coor {
  int xCor;
  int yCor;
  int size;
};

class Menu {
private:

  vector <string> nazvan;
  coor Cor;
  int size;
  int kol;
  int xCor;
  int yCor;

public:

  Menu(vector <string> naz, int k, int x, int y, int d);
  Menu(string n);

  friend void doSomething(const Menu& d, int n);
  friend int choose(const Menu& d);
  friend void thisinfo(const Menu& c);
  friend void info(const Menu& c);
  friend void text();
  friend ostream& operator<<(ostream& stream, const Menu& d);
};