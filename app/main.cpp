#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include "dict.h"
using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  Dict a("Lol", "Ћол"), b("Lola", "Ћола");
  ALLDict A(a);

  cin >> a;
  cout << a;
  system("pause");
}
