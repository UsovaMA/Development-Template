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
  void txt1();
  void leninit();
  void txt2();
  int getX();
  int getY();
  int getlen();
  void show(char *str, int gEtx, int gEty);
  void textstr(char *str, int k, int gEtx, int gEty);
  void textstredit(char* str, int k, int gEtx, int gEty);
  TextEditor();
  TextEditor(int _x, int _y, int _len);
  TextEditor(const TextEditor &c);
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