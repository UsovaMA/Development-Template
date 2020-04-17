#include "..\include\Contacts.h"
#include "..\include\Contacts.h"
#include "..\include\Contacts.h"
#include "..\include\Contacts.h"
#include "Contacts.h"
#include "Fun.h"

Contact::Contact()
{
  lname = "Иван";
  fname = "Иванов";
  patro = "Иванович";
  phone = "88005553535";
  DatBir = "20.20.67";
  fav = 0;
}

Contact::Contact(string s)
{
  lname = breakdown1(s);
  fname = breakdown2(s);
  patro = breakdown3(s);
  phone = "0";
  DatBir = "0";
  fav = 0;
}

Contact::Contact(string n, string f, string pat)
{
  lname = n;
  fname = f;
  patro = pat;
  phone = "0";
  DatBir = "0";
  fav = 0;
}

Contact::Contact(string n, string f, string pat, string ph, bool like)
{
  lname = n;
  fname = f;
  patro = pat;
  phone = ph;
  DatBir = "0";
  fav = like;
}

Contact::Contact(Contact & a)
{
  lname = a.lname;
  fname = a.fname;
  patro = a.patro;
  phone = a.phone;
  DatBir = a.DatBir;
  fav = a.fav;
}


Contact& Contact::operator=(const Contact& t) {
  lname = t.lname;
  fname = t.fname;
  patro = t.patro;
  phone = t.phone;
  DatBir = t.DatBir;
  fav = t.fav;
  return (*this);
}

//Contact& Contact::operator=(const Contact* t) {
//  lname = t->lname;
//  fname = t->fname;
//  patro = t->patro;
//  phone = t->phone;
//  DatBir = t->DatBir;
//  fav = t->fav;
//  return (*this);
//}

string Contact::getNAME() {
  return lname;
}
string  Contact::getFn() {
  return fname;
}
string  Contact::getPA() {
  return patro;
}
string Contact::getPH() {
  return phone;
}
string Contact::getBD() {
  return DatBir;
}
bool Contact::getFA() {
  return fav;
}

void Contact::imNAME(string n) {
  lname = n;
}
void Contact::imFn(string n) {
  fname = n;
}
void Contact::imPA(string n) {
  patro = n;
}
void Contact::imPH(string n) {
  phone = n;
}

void Contact::imFav(bool a)
{
  fav = a;
}

ostream& operator << (ostream& stream, const Contact& a) {
  cout <<"            name: " << a.lname <<" " << a.fname << " " << a.patro << endl;
  if(a.phone !="0") cout <<"           phone:" << " " << a.phone << endl;
  string B = a.DatBir;
  if (a.DatBir != "0") cout <<"date of birthday: "<< a.DatBir  <<  endl;
  cout << "       favorites:";
  if (a.fav) cout << " Yes" << endl;
  else cout << " No" << endl;
  return stream;
}
istream& operator >> (istream& stream, Contact &a) {
  
  string a1= "0", a2="0", a3="0";
  bool v=1; //выбор
  if (v) {
    cout << "New contact:" << endl;
    cout << "name: ";
    cin >> a1 >> a2 >> a3;
    a.lname = a1;
    a.fname = a2;
    a.patro = a3;
    // фио есть
    cout << "Do you want enter more information? (0-No, 1-Yes) ";
    cin >> v;
    if (v) {
      cout << "All information? (0-No, 1-Yes) ";
      cin >> v;
      if (v) {
        cout << "           phone: ";
        cin >> a.phone;
        cout << "date of birthday: ";
        cin >> a.DatBir;
        cout << "       favorites:(0-No, 1-Yes)";
        cin >> a.fav;
      }
      else {
        cout << "Do you want enter phone? (0-No, 1-Yes) ";
        cin >> v;
        if (v) {
          cout << "           phone: ";
          cin >> a.phone;
        }
        cout << "Do you want enter date of birthday? (0-No, 1-Yes) ";
        cin >> v;
        if (v) {
          cout << "date of birthday: ";
          cin >> a.DatBir;
        }
        cout << "Is it your favorite? (0-No, 1-Yes) ";
        cin >> a.fav;
      }
    }
  }
  return stream;
}

void Contact::Change()
{
  int i = 0;
  string a1 = "0", a2 = "0", a3 = "0";
  while (i != 5) {
    switch (i) {
    case 0:
      cout << " _________________________________" << endl;
      cout << "|  What do you want to change?    |" << endl;
      cout << "|1- Name, Last name,  patronymic  |" << endl;
      cout << "|2- phone                         |" << endl;
      cout << "|3- birthday                      |" << endl;
      cout << "|4- favorite                      |" << endl;
      cout << "|5- comeback                      |" << endl;
      cout << "|_________________________________|" << endl;
      cin >> i;
      break;
    case 1:
      cout << "name: ";
      cin >> a1 >> a2 >> a3;
      lname = a1;
      fname = a2;
      patro = a3;
      i = 0;
      break;
    case 2:
      cout << "phone: ";
      cin >> phone;
      i = 0;
      break;
    case 3:
      cout << "date of birthday: ";
      cin >> DatBir;
      i = 0;
      break;
    case 4:
      cout << "favorites:(0-No, 1-Yes)";
      cin >> fav;
      i = 0;
      break;
    default:
      i = 0;
      break;
    }
  }
}

Contact::~Contact()
{
  lname = "0";
  fname = "0";
  patro = "0";
  phone = "0";
  DatBir = "0";
  fav = 0;
}
