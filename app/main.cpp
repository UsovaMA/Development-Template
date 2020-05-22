// Copyright 2020 <Diana Lukashuk>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "Coord.h"
#include "Screen.h"
#include "Snake.h"
using namespace std;

int press() {
  if (!kbhit()) { return 0; }
  int k1, k2;
  k1 = _getch();
  if (k1 == 0xE0 || k1 == 0x00)
  {
    k2 = _getch();
    switch (k2)
    {

    case 0x4B: return 4; // <-
    case 0x48: return 2; // ^
    case 0x4D: return 3; // ->
    case 0x50: return 1; // V
    }
  }
  return 0;
}

void play(Screen a) {
  while (a.new_cadr(press())) {
    a.draw();
    Sleep(100);
  }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int v = 1;
    cout << endl << endl << "Добро пожаловать в игру змейка. Начнем? ";
    cout << endl << endl << "    *(нажмите на любую кнопку)* ";
    _getch();
    system("cls");
    Screen* a;
    while (v) {
      a = new Screen[1];
      while (a[0].new_cadr(press())) {
        a[0].draw();
        Sleep(100);
      }
      delete[]a;
      cout << endl << endl << "Хотите сыграть еще раз? (1-да, 0-нет) ";
      cin >> v;
    }
    cout << endl << endl << "Желаем удачного дня ";
    return 0;
}
