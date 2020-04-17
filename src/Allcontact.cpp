#include "..\include\Allcontact.h"
#include "..\include\Allcontact.h"
#include "..\include\Allcontact.h"
#include "..\include\Contacts.h"
#include "..\include\Contacts.h"
#include "..\include\Contacts.h"
#include "Allcontact.h"
#include "Fun.h"

AllContact::AllContact() {
  size = 0;
  con = 0;
}

AllContact::AllContact(Contact *a, int s)
{
  size = s;
  con = new Contact[size];
  for (int i = 0; i < size; i++) {
    con[i] = a[i];
  }
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

string AllContact::getPH(int nom)
{
  return con[nom].getPH();
}



void AllContact::DopСon(Contact a) 
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

void AllContact::to_screen(int num)
{
  cout << con[num] << endl;
}

void AllContact::ChangeC(int nom)
{
  con[nom].Change();
}



void AllContact::DelСon(int nom)
{
  AllContact res;
  bool a;
  if (nom == size - 1) a = 0; else a = 1;
  res.size = size - 1;
  res.con = new Contact[res.size];
  if (a) { //нужно перемещать
    res.con[nom] = con[res.size-1]; //на место nom ставим последний элемент
    for (int I = 0; I <= res.size - 1; I++) {
      if(I!=nom) res.con[I] = con[I];
    }
  }
  else {//нужно удалить посл элемент
    for (int I = 0; I <= res.size - 1; I++) {
      res.con[I] = con[I];
    }
  }
  (*this) = res;
}

void AllContact::imFav(int nom, bool like)
{
  con[nom].imFav(like);
}

bool AllContact::getFav(int nom)
{
  return con[nom].getFA();
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

AllContact&AllContact::operator=(const AllContact& t) {
  if (size != 0) {
    delete[] con;
  }
  size = t.size;
  con = new Contact[size];
  for (int a = 0; a < size; a++) {
    con[a] = t.con[a];
  }
  return (*this);
}

AllContact::~AllContact()
{
  delete[] con;
  size = 0;
}

ostream & operator<<(ostream & stream, const AllContact & a)
{
  Contact as;
  for (int i = 0; i < a.size; i++) {
    as = a.con[i];
    cout << as << endl;
  }
  return stream;
}
