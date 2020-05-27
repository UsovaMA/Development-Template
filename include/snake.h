#ifndef INCLUDE_SNAKE_H_
#define INCLUDE_SNAKE_H_

#pragma once


#include<iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

const int m = 20;
const int n = 40;


/*
1 - top 115
2 - right 100
3 - bottom 119
4 - left 97
*/

class Coard {
public:
  int x;
  int y;

  Coard() {
    x = -1;
    y = -1;
  }
};

class Snake {
  char wall[m][n];
  int size = 1;
  string snk = "@";
  Coard snakeCoard[100];
  Coard fruit;
  int score;
  bool gameover = false;
public:
  void setCursorPosition(int y, int x);
  void start();
  void draw(int course);
  void move(int course);
  void spawnFruit();
  int getCourse(char crs);
};



/*



const unsigned short DARK_BLUE = FOREGROUND_BLUE;
  const unsigned short BRIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;


  void setConsoleColour(unsigned short colour);//öâåò êîíñîëè
  void setCursorPosition(int y, int x);//ïîçèöèÿ êóðñîðà
  int EatAdd();//äîáàâèòü åäó íà ïîëå
  bool FindEl(int head);//ïåðåñå÷åíèå ãîëîâû ñ òåëîì
  void PrintSnake();//îòðèñîâêà ïîëÿ
  int Joy(char a);//óïðàâëåíèå
  bool StepBool(char a);//âîçìîæíîñòü øàãà
  void Step(char ar);//øàã


public:
  Snake();
  ~Snake();
  void Start();//çàïóñê
*/
#endif  // INCLUDE_SNAKE_H_
