#include"Tasc_2.h"

int main() {
  Octal a = "5555555";
  Octal b = "5555555";
  Octal c;
  cin >> c;
  cout << a;
  cout << endl;
  cout << b;
  cout << endl;
  cout << c << endl;
  if (a == b) {
    cout << "ravno ";
  }
  else {
    cout << "ne ravno ";
  }
  getchar();
  getchar();
  return 0;
}