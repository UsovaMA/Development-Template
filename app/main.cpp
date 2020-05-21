#include "ProcCenter.h"
#include "Bancai.h"


int main() 
{
  setlocale(LC_ALL, "Rus");
  Dop c("misha", "alim", "ser", "0001", 3000, 0000, 0, 0);
  ProcCenter cl;
  cl.AddPers(c);
  Bancai de;
  de.Start(cl);

 
}

