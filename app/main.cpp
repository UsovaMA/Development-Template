#include "ProcCenter.h"
#include "Bancai.h"


int main() 
{
  setlocale(LC_ALL, "Rus");
  Dop c("misha","alim","ser","0001",300,0000,0,0);
  ProcCenter cl(c);
  Bancai de;
  de.Start(cl);

 
}

