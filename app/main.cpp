#include "octal.h"
#include <iostream>

int main() {
  Octal res("109", 3);
  //ofstream fout("output.txt");
 // fout << res;
 // fout.close();
  cout << res;
  cout << res[2];
  system("pause");

}
