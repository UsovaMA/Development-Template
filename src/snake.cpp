
#include "snake.h"
#include <cassert>

using namespace std;

int Xshift, Yshift;

void Snake::start() {
  int i, j;
  char crs;
  srand(time(0));
  // draw walls
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      wall[i][j] = ' ';
  for (int i = 0; i < n; i++)
  {
    wall[0][i] = '#';
    wall[m - 1][i] = '#';
  }
  for (int j = 0; j < m; j++) {
    wall[j][0] = '#';
    wall[j][n - 1] = '#';
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      cout << wall[i][j];
    cout << endl;
  }
  snakeCoard[0].x = 2 + rand() % (n - 2);
  snakeCoard[0].y = 2 + rand() % (m - 2);
  setCursorPosition(snakeCoard[0].x, snakeCoard[0].y);
  cout << "@";
  spawnFruit();
  setCursorPosition(42, 1);
  cout << "Control: WASD";
  setCursorPosition(10, m + 5);
  cout << "Score: 0";
  while (!gameover) {
    crs = _getch();
    move(getCourse(crs));
  }
  setCursorPosition(42, 3);
  cout << "You lose =(";
  setCursorPosition(0, m + 1);
}

void Snake::setCursorPosition(int x, int y) {
  static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  std::cout.flush();
  COORD coord = { (SHORT)x, (SHORT)y };
  SetConsoleCursorPosition(hOut, coord);
}

void Snake::draw(int course, int XX, int YY) {
  int i;
  for (i = 0; i < size; ++i) {
    setCursorPosition(snakeCoard[i].x, snakeCoard[i].y);
    cout << snk[i];
  }

  switch (course) {
  case 1:
    setCursorPosition(XX, YY);
    cout << " ";
    break;
  case 2:
    setCursorPosition(XX, YY);
    cout << " ";
    break;
  case 3:
    //setCursorPosition(snakeCoard[size - 1].x + Xshift, snakeCoard[size - 1].y + Yshift);
    setCursorPosition(XX, YY);
    cout << " ";
    break;
  case 4:
    setCursorPosition(XX, YY);
    cout << " ";
    break;
  }
  setCursorPosition(snakeCoard[0].x, snakeCoard[0].y);
  
}

void Snake::move(int course) {
  string tmp;
  int i;
  int prevX, prevY, prevX2, prevY2;
  prevX = snakeCoard[0].x;
  prevY = snakeCoard[0].y;
  for (i = 1; i < size; ++i) {
    prevX2 = snakeCoard[i].x;
    prevY2 = snakeCoard[i].y;
    snakeCoard[i].x = prevX;
    snakeCoard[i].y = prevY;
    prevX = prevX2;
    prevY = prevY2;
  }

    switch (course) {
    case 1:
      snakeCoard[0].y--;
      Xshift = 0;
      Yshift = 1;
      break;
    case 2:
      snakeCoard[0].x++;
      Xshift = -1;
      Yshift = 0;
      break;
    case 3:
      snakeCoard[0].y++;
      Xshift = 0;
      Yshift = -1;
      break;
    case 4:
      snakeCoard[0].x--;
      Xshift = 1;
      Yshift = 0;
      break;
    }
    if (size > 1) {
      Xshift = 0;
      Yshift = 0;
    }
if (snakeCoard[0].x == fruit.x && snakeCoard[0].y == fruit.y) {
  score+=10;
  setCursorPosition(17, m + 5);
  cout << score;
  size++;
  snakeCoard[i].y = snakeCoard[i - 1].y;
  snakeCoard[i].x = snakeCoard[i - 1].x;
  switch (course) {
  case 1:
    snakeCoard[i].y++;
    break;
  case 2:
    snakeCoard[i].x--;
    break;
  case 3:
    snakeCoard[i].y--;
    break;
  case 4:
    snakeCoard[i].x++;
    break;
  }
  tmp = snk + "*";
  snk = tmp;
  spawnFruit();
}

if (snakeCoard[0].x == 0 || snakeCoard[0].x == n - 1
  || snakeCoard[0].y == 0 || snakeCoard[0].y == m - 1)
  gameover = true;
for (i = 1; i < size; ++i)
  if (snakeCoard[i].x == snakeCoard[0].x
    && snakeCoard[i].y == snakeCoard[0].y)
    gameover = true;
draw(course, prevX, prevY);
}


void Snake::spawnFruit() {
  int i = 0;
  bool flag;
  do {
    flag = false;
    fruit.x = 1 + rand() % (n - 2);
    fruit.y = 1 + rand() % (m - 2);
    for (i = 0; i < size; ++i)
      if (fruit.x == snakeCoard[i].x && fruit.y == snakeCoard[i].y)
        flag = true;
  } while (flag);
  setCursorPosition(fruit.x, fruit.y);
  cout << "0";
}

int Snake::getCourse(char crs) {
  switch ((int)(crs)) {
  case 119:
    return 1;
  case 100:
    return 2;
  case 115:
    return 3;
  case 97:
    return 4;
  }
  return 0;
}



/*
const int m = 20;
const int n = 40;
char a[m][n];
deque<int> sn;
bool st = true;
int head, eat;

Snake::Snake()
{
}


Snake::~Snake()
{
}

void Snake::setConsoleColour(unsigned short colour)
{
  static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  std::cout.flush();
  SetConsoleTextAttribute(hOut, colour);
}

void Snake::setCursorPosition(int y, int x)
{
  static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  std::cout.flush();
  COORD coord = { (SHORT)x, (SHORT)y };
  SetConsoleCursorPosition(hOut, coord);
}

int Snake::EatAdd() {
  int x;
  do {
    x = rand() % (m*n);
  } while (a[x / n][x%n] != ' ' || x == head);
  return x;
}

bool Snake::FindEl(int head) {
  for (int i = 1; i < sn.size(); i++)
    if (head == sn[i])
      return true;
  return false;
}

void Snake::PrintSnake() {
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      a[i][j] = ' ';
  for (int i = 0; i < n; i++)
  {
    a[0][i] = '#';
    a[m - 1][i] = '#';
  }
  for (int j = 0; j < m; j++) {
    a[j][0] = '#';
    a[j][n - 1] = '#';
  }

}

int Snake::Joy(char a) {
  if (a == 72)
    return -n;
  if (a == 80)
    return n;
  if (a == 75)
    return -1;
  if (a == 77)
    return 1;
  return 0;
}

bool Snake::StepBool(char a) {
  head += Joy(a);
  if (head<n || head>(m - 1)*n || head % n == 0 || head % n == n - 1 || FindEl(head)) {
    cout << "Error";
    return false;
  }
  return true;
}
void Snake::Step(char ar) {

  head += Joy(ar);
  setCursorPosition(m + 2, 0);
  cout << head;
  if (head<n || head>(m - 1)*n || head % n == 0 || head % n == n - 1 || FindEl(head)) {
    st = false;
    cout << "Error";
  }
  else {
    if (head == eat) {
      eat = EatAdd();
      setCursorPosition(eat / n, eat % n);
      cout << '&';
      setCursorPosition(sn.front() / n, sn.front() % n);
      cout << '*';
      sn.push_front(head);
      setCursorPosition(sn.front() / n, sn.front() % n);
      cout << '@';

      setCursorPosition(m + 1, 0);
      cout << "            ";
      setCursorPosition(m + 1, 0);
      for (int i = 0; i < sn.size(); i++) {
        cout << sn[i] << ' ';
      }
    }
    else {
      setCursorPosition(sn.front() / n, sn.front() % n);
      cout << '*';
      sn.push_front(head);
      setCursorPosition(sn.back() / n, sn.back() % n);
      cout << ' ';
      sn.pop_back();
      setCursorPosition(sn.back() / n, sn.back() % n);
      cout << '*';

      setCursorPosition(sn.front() / n, sn.front() % n);
      cout << '@';

      setCursorPosition(m + 1, 0);
      cout << "            ";
      setCursorPosition(m + 1, 0);
      for (int i = 0; i < sn.size(); i++) {
        cout << sn[i] << ' ';
      }
    }

    setCursorPosition(m + 1, 0);
    cout << "            ";
    setCursorPosition(m + 1, 0);
    for (int i = 0; i < sn.size(); i++) {
      cout << sn[i] << ' ';
    }
  }
}

void Snake::Start()
{
  system("chcp 1251");//ïîäêëþ÷åíèå êèðèëëèöû
  system("cls");
  head = n + 1;
  sn.push_front(head);
  head = sn.front();
  PrintSnake();
  eat = EatAdd();

  setConsoleColour(BRIGHT_BLUE);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      cout << a[i][j];
    cout << endl;
  }

  setCursorPosition(eat / n, eat % n);
  cout << '&';
  //Step(' ');
  while (st) {
    char ax;
    ax = _getch();
    Step(ax);
  }
  system("cls");
  cout << "End Game";
}
*/