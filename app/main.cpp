#include "ProcCenter.h"
#include "Bancomat.h"


int main() 
{
  setlocale(LC_ALL, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  cout << "Добро пожаловать.\n";
  cout << "Тестовая карта: CardNum: 1234 PIN: 1234\n";
  Sup c("name", "mid", "last", 1234, 30000, 1234, 0, 0);
  ProcCenter c1;
  c1.AddPers(c);
  Bancomat t;
  t.Start(c1);

 
}

