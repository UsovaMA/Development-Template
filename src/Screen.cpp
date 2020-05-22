#include <ctime>
#include <iostream>
#include <conio.h>
#include "Screen.h"
#include "Coord.h"
using namespace std;

Screen::Screen() {
  cout << "Введите размеры поля (они должны быть больше 7 Х 7):" << endl;
  cout << "m = ";
  cin >> m;
  cout << "n = ";
  cin >> n;
  while ((m < 6) && (n < 6)) {
    cout << "Ошибка! Слишком маленькое поле" << endl;
    cout << "Введите размеры поля (они должны быть больше 7 Х 7):" << endl;
    cout << "m = ";
    cin >> m;
    cout << "n = ";
    cin >> n;
  }
  pitosha.new_coord(m, n);
  new_fruct();
  cout << "Введите необходимый результат для победы(больше 5): ";
  cin >> res;
  while (res<5) {
    cout << "Ошибка, число меньше 5. ";
    cout << "Введите необходимый результат для победы(больше 5): ";
    cin >> res;
  }
}

Screen::Screen(const Screen & s) {
  m = s.m;
  n = s.n;
  res = s.res;
  fruct = s.fruct;
  pitosha = s.pitosha;
}

int Screen::get_m() {
  return m;
}

int Screen::get_n() {
  return n;
}

int Screen::get_res() {
  return res;
}

bool Screen::new_cadr(int napr) {
  if (pitosha.hea.c == fruct) { 
    pitosha.new_step(napr, 1);
    new_fruct(); } 
  else pitosha.new_step(napr, 0);
  if (res == pitosha.size_body + 1) {
    system("cls");
    cout << "Победа!!!";
    return 0;
  }
  if(pitosha.losing(m, n)) {
    system("cls");
    cout << "Вы проиграли...";
    return 0;
  }
  return 1;
}

void Screen::draw() {
  system("cls");
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  for (int i = 0; i < m + 2; i++) {
    cout << "# ";
  }
  cout << endl;
  for (int y = 0; y < n; y++) {
    cout << "# ";
    for (int x = 0; x < m; x++) {
      if ((fruct.x == x) && (fruct.x == y)) cout << "$ ";
      else {
      if (pitosha.check_free(x, y)) cout << "  ";
      else {
        if ((pitosha.hea.c.x == x) && (pitosha.hea.c.y == y)) {
          SetConsoleTextAttribute(handle, FOREGROUND_RED);
          cout << pitosha.hea.simv << " ";
          SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        else cout << "% ";
      }
    }
    }
    cout << "#";
    cout << endl;
  }
  for (int i = 0; i < m + 2; i++) {
    cout << "# ";
  }
  //system("cls");
}

void Screen::new_fruct()
{
  srand(time(0));
  int _x = rand() % m;
  srand(time(0));
  int _y = rand() % n;
  while (!pitosha.check_free(_x, _y)) {
    srand(time(0));
    _x = rand() % m;
    srand(time(0));
    _y = rand() % n;
  }
  fruct.x = _x;
  fruct.y = _y;
}

Screen::~Screen()
{
  m = 0;
  n = 0;
  fruct.x=0;
  fruct.y = 0;
}
