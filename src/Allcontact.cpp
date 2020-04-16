#include "..\include\Contacts.h"
#include "..\include\Contacts.h"
#include "..\include\Contacts.h"
#include "Allcontact.h"
#include "Fun.h"

AllContact::AllContact() {
  size = 0;
  con = 0;
}

AllContact::AllContact(Contact a)
{
  size = 1;
  con = new Contact[size];
  con[0] = a;
}

AllContact::AllContact(AllContact & a)
{
  if (size > 0) {
    delete[] con;
  }
  size = a.size;
  con = new Contact[a.size];
  for (int i = 0; i < size; i++) {
    con[i] = a.con[i];
  }
}

int AllContact::getSize()
{
  return size;
}



void AllContact::DopСon(Contact a) // тут ошибка, я устала
{
  AllContact res;
  res.size = size + 1;
  res.con = new Contact[res.size];
  for (int I = 0; I <= res.size - 2; I++) {
    res.con[I] = con[I];
  }
  res.con[res.size - 1] = a;
  (*this) = res;
}

int AllContact::i_poisk_fio(string i, string f, string o)
{
  bool q;
  for (int a = 0; a < size; a++) {
    q=checkFIO(i, f, o, con[a].getNAME(), con[a].getFn(), con[a].getPA());
    if (q) return a;
  }
  return (-1);
}



AllContact::~AllContact()
{
  delete[] con;
  size = 0;
}
