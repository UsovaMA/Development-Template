#include"roga_i_copita.h"
int main() {
  setlocale(LC_CTYPE, "Russian");
  int n=6872;
  roga_i_copita a(n);
  roga_i_copita b;
  a.game1();
  getchar();
  getchar();
  return 0;
}