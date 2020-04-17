#include "Octal.h"
int main() {

  Octal a = "4";
  Octal b = "45";
  Octal c, f;
  cout << "a =  " ;
  cout << a;
  cout << "b =  ";
  cout << b;
  cout << "a - b= " ;
  c = a - b;
  cout << c;
  cout << "a + b= " ;
  c = a + b;
  cout << c;
  
  if (a == b) {
    cout << " a pavno b";
  }
  else {
    cout << "a ne ravno b";
  }

  getchar();
  getchar();
  return 0;
}