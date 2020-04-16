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
  cout << "New contact:" << endl;
  cout << "name: ";
  string a1= "0", a2="0", a3="0";
  cin >> a1>> a2 >> a3;
  a.lname = a1;
  a.fname = a2;
  a.patro = a3;
  // фио есть
  bool v; //выбор
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
    } else {
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
  return stream;
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
