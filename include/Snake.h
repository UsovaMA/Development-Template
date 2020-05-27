#pragma once
#include <iostream>
#include <clocale>
#include <Windows.h>
#include <conio.h>

using namespace std;

class Position {

  friend class Zmeika;

private:

  int xp;
  int yp;

public:

  Position();
  Position(const Position& c);
  Position(int _xp, int _yp);
  void positiontext(int xpos, int ypos);

  friend bool operator==(const Position& left, const Position& right) {
    bool res = false;
    if (left.xp == right.xp && left.yp == right.yp) {
      res = true;
    }
    else {
      res = false;
    }
    return res;
  }

};

enum class key { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Zmeika {

private:
  bool end;
  key dir;
  const int hir = 60;
  const int vis = 20;
  int score = 0;
  int frx, fry;
  int x, y;
  int* tx = new int[101];
  int* ty = new int[101];
  int count = 0;
  int win = 0;

public:

  Zmeika();
  ~Zmeika();
  Zmeika(const Zmeika& c);

  friend bool operator==(const Zmeika& left, const Zmeika& right) {
    bool res = false;
    if (left.score == right.score && left.frx == right.frx && left.fry == right.fry &&
      left.x == right.x && left.y == right.y && left.count == right.count && left.win == right.win) {
      res = true;
    }
    else {
      res = false;
    }
    return res;
  }

  void startmenu();
  void Setup();
  void Draw();
  void Input();
  void Logic(int w);
};