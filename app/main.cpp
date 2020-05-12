#include "ProcCenter.h"
#include "Bancomat.h"


int main() 
{
  setlocale(LC_ALL, "Rus");
  ProcCenter c1("name","sec","last","1234",700000,1234);
  ProcCenterVec c2(c1);
  Bancomat m;
  m.Start(c2);

 
}

