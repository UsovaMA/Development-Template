// Copyright 2020 Podovinnikov
#include <iostream>
#include <clocale>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <Windows.h>

using namespace std;

class TextEditor {
private:
  int x;
  int y;
  int len;
public:
  void position(int xpos, int ypos);
  int options();
  void txt1();
  void leninit();
  void txt2();
  int getX();
  int getY();
  int getlen();
  void show(char *str);
  void textstr(char *str, int k);
  void textstredit(char* str, int k);
  TextEditor();
  TextEditor(const TextEditor &c);
  TextEditor(int _x, int _y, int _len);
  bool operator==(const TextEditor& c);
  friend bool operator==(const TextEditor &left, const TextEditor &right) {
    bool res = false;
    if (left.x == right.x && left.y == right.y) {
      res = true;
    }
    else {
      res = false;
    }
    return res;
  }
};