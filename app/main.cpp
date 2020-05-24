// Copyright 2020 Podovinnikov
#include "TextEditorH.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  char str[300];
  TextEditor t1;
  t1.options();
  t1.leninit();
  t1.position(t1.getX() , t1.getY());
  cout << "¬ведите текст:";
  t1.position(t1.getX(), t1.getY()+1);
  cout << ">> ";
  t1.textstr(str, t1.getlen()+1);
  system("CLS");
  t1.show(str);
}