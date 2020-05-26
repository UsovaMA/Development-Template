#include "BullsAndCows.h"
int main() {
  setlocale(LC_CTYPE, "Russian");
  int n=31246;
  BullsCows a(n);
  BullsCows b;
  a.GameStart();
  return 0;
}