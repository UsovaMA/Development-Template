#include "octal.h"
#include <iostream>

int main() {
  Octal res("0", 5);
  //ofstream fout("output.txt");
 // fout << res;
 // fout.close();
  ifstream fin("input.txt");
  fin >> res;
  cout << res;
  fin.close();
  system("pause");

}
