#include "Snake.h"

Position::Position() {
  xp = 0;
  yp = 0;
}

Position::Position(const Position& c) {
  xp = c.xp;
  yp = c.yp;
}

Position::Position(int _xp, int _yp) {
  xp = _xp;
  yp = _yp;
}

void Position::positiontext(int xpos, int ypos) {
  if (xpos <= 0 || ypos <= 0)
    throw logic_error("Input error xpos ypos");
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD cursorPos;
  cursorPos.X = xpos;
  cursorPos.Y = ypos;
  SetConsoleCursorPosition(hStdOut, cursorPos);
}

Zmeika::Zmeika()
{
  end = false;
  score = 0;
  frx = 0;
  fry = 0;
  x = hir / 2;
  y = vis / 2;
  count = 0;
  dir = key::STOP;
  win = 0;
}

Zmeika::~Zmeika()
{
  delete[] tx;
  delete[] ty;
}

Zmeika::Zmeika(const Zmeika& c)
{
  if (count != 0) {
    count = c.count;
    delete[] tx;
    delete[] ty;
  }

  score = c.score;
  frx = c.frx;
  fry = c.fry;
  x = c.x;
  y = c.y;
  dir = c.dir;
  end = c.end;
  win = c.win;
}

void Zmeika::startmenu() {

  Position p;

  do {

    int w = 0;

    do {
      cout << "Game 'Snake'" << endl;
      cout << "Choose count of your $" << endl;
      cout << "You may choose at 3 to 100: ";
      cin >> win;
      system("CLS");
    } while (win < 3 || win>100);

    p.positiontext(55, 13);
    cout << "START";
    Sleep(1000);
    system("CLS");

    Setup();

    while (!end) {
      Draw();
      Input();
      Logic(w);
      if (score == win) end = true;
    }
    system("CLS");
    cout << "Your score: " << score << " / " << win << endl << endl;
    if (end == true || score == win) {
      Setup();
      cout << "Type then repeat";
      _getch();
      system("CLS");
      win = 0;
    }
  } while (!end);
}

void Zmeika::Setup() {
  end = false;
  dir = key::STOP;
  x = hir / 2 - 1;
  y = vis / 2 - 1;
  frx = rand() % hir;
  fry = rand() % vis;
  score = 0;
  count = 0;
}

void Zmeika::Draw() {
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  Sleep(100);
  system("CLS");
  cout << "Your score: " << score << "  You need: " << win - score << endl;

  for (int i = 0; i < hir + 1; i++) {
    cout << "_";
  }
  cout << endl;
  for (int i = 0; i < vis; i++) {
    for (int j = 0; j < hir; j++) {
      if (j == 0 || j == hir - 1) {
        cout << "|";
      }
      if (i == y && j == x) {
        SetConsoleTextAttribute(handle, 9);
        cout << "*";
        SetConsoleTextAttribute(handle, 7);
      }
      else {
        if (i == fry && j == frx) {
          SetConsoleTextAttribute(handle, 4);
          cout << "$";
          SetConsoleTextAttribute(handle, 7);
        }
        else {
          bool go = false;
          for (int k = 0; k < count; k++) {
            if (tx[k] == j && ty[k] == i) {
              go = true;
              SetConsoleTextAttribute(handle, 14);
              cout << "*";
              SetConsoleTextAttribute(handle, 7);
            }
          }
          if (!go) {
            cout << " ";
          }
        }
      }
    }
    cout << endl;
  }
  for (int i = 0; i < hir + 1; i++) {
    cout << "_";
  }
}

void Zmeika::Input() {
  if (_kbhit()) {
    switch (_getch())
    {
    case 0x4B:
      if (dir != key::RIGHT || count == 0) {
        dir = key::LEFT;
      }
      break;
    case 0x4D:
      if (dir != key::LEFT || count == 0) {
        dir = key::RIGHT;
      }
      break;
    case 0x48:
      if (dir != key::DOWN || count == 0) {
        dir = key::UP;
      }
      break;
    case 0x50:
      if (dir != key::UP || count == 0) {
        dir = key::DOWN;
      }
      break;
    }
  }
}

void Zmeika::Logic(int w) {
  int pred2x, pred2y;
  int predx = tx[0];
  int predy = ty[0];
  tx[0] = x;
  ty[0] = y;
  for (int i = 1; i < count; i++) {
    pred2x = tx[i];
    pred2y = ty[i];
    tx[i] = predx;
    ty[i] = predy;
    predx = pred2x;
    predy = pred2y;
  }
  switch (dir)
  {
  case key::LEFT:
    x--;
    if (count < 5)
      count++;
    break;
  case key::RIGHT:
    x++;
    if (count < 5)
      count++;
    break;
  case key::UP:
    y--;
    if (count < 5)
      count++;
    break;
  case key::DOWN:
    y++;
    if (count < 5)
      count++;
    break;
  }

  if (x > hir || x<0 || y>vis || y < 0) {
    end = true;
  }

  for (int i = 0; i < count; i++) {
    if (tx[i] == x && ty[i] == y) {
      end = true;
    }
  }
  if (x == frx && y == fry) {
    score = score + 1;
    frx = rand() % hir;
    fry = rand() % vis;
    count++;
  }
}