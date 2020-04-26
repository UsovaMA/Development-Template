// Copyright 2020 Podovinnikov
#include "TextEditorH.h"

using namespace std;

TextEditor::TextEditor() {
  x = 1;
  y = 1;
  len = 1;
}

TextEditor::TextEditor(const TextEditor &c) {
  x = c.x;
  y = c.y;
  len = c.len;
}

TextEditor::TextEditor(int _x, int _y, int _len) {
  x = _x;
  y = _y;
  len = _len;
}

bool TextEditor::operator==(const TextEditor &c) {
  bool res = 0;
  if (x == c.x && y == c.y) {
    res = 1;
  }
  else {
    res = 0;
  }
  return res;
}
int TextEditor::getX() { return x; }
int TextEditor::getY() { return y; }


void TextEditor::txt1() {
  SetWindowPos(GetConsoleWindow(), HWND_TOP, 10, 10, 1500, 800, NULL);
  position(45, 15);
  cout << "ВВЕДИТЕ РАЗМЕР ПОЛЯ (КОЛ-ВО СИМВОЛОВ В СТРОКЕ)\n";
  position(45, 16);
  cout << ">> ";
}
void TextEditor::leninit() {
  txt1();
  cin >> len;
  system("CLS");
}
int TextEditor::getlen() {
  return len;
}
void TextEditor::txt2 (){
  do{
  position(85, 18);
  cout << "По горизонтали <Позиция по оси X> меньше 101, больше 0: ";
  cin >> x;
  system("CLS");
} while (x < 0 || x >100);
do {
  position(85, 18);
  cout << "По вертикали <Позиция по оси Y> меньше 46, больше 0: ";
  cin >> y;
  system("CLS");
} while (y < 0 || y>45);
system("CLS");
}


void TextEditor::position(int xpos, int ypos) {
  if (xpos < 0 || ypos < 0)
    throw logic_error("Input error xpos ypos");
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD cursorPos;
  cursorPos.X = xpos;
  cursorPos.Y = ypos;
  SetConsoleCursorPosition(hStdOut, cursorPos);
}





void TextEditor::show(char *str, int gEtx, int gEty) {
  int ab;
  do {
    position(0, 5);
    cout << "Ваш текст:";
    cout << str << ".";
    position(18, 8);
    cout << "Нажмите <1>, чтобы скрыть редактор.";
    position(18, 9);
    cout << "Нажмите <2>, чтобы завершить программу.";
    position(18, 10);
    cout << "Нажмите <3>, редактировать строку.";
    position(18, 11);
    cout << "CMD>> ";
    cin >> ab;
    if (ab != 1 || ab != 2 || ab !=3) {
      system("CLS");
    }
    if (ab == 1) {
      HWND hWnd = GetConsoleWindow();
      ShowWindow(hWnd, SW_MINIMIZE);
    }
    if (ab == 3) {
      textstredit(str, getlen(),gEtx,gEty);
      show(str, gEtx, gEty);
      system("pause");
    }
  } while (ab != 2);
  if (ab == 2) {
    system("pause");
  }

}

void TextEditor::textstr(char* str, int k, int gEtx, int gEty) {
  string st;

  do{
    position(gEtx, gEty);
    printf("Введите строку длинны %d: ", k);
    cin >> str;
    st = str;
    system("CLS");
  }
  while (st.length() > k+1);
  
}
void TextEditor::textstredit(char* str, int k, int gEtx, int gEty) {
  string st1;

  do {
    position(gEtx, gEty);
    printf("Введите новую строку длинны %d: ", k);
    cin >> str;
    st1 = str;
    system("CLS");
  } while (st1.length() > k + 1);

}