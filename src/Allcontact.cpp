#include "..\include\Allcontact.h"
#include "..\include\Allcontact.h"
#include "..\include\Allcontact.h"
#include "..\include\Allcontact.h"
#include "..\include\Contacts.h"
#include "..\include\Contacts.h"
#include "..\include\Contacts.h"
#include <iostream>
#include <fstream>
#include <clocale>
#include "Allcontact.h"
#include "windows.h"
#include "Fun.h"

AllContact::AllContact() {
  size = 0;
  con = 0;
}

AllContact::AllContact(Contact *a, int s) {
  size = s;
  con = new Contact[size];
  for (int i = 0; i < size; i++) {
    con[i] = a[i];
  }
}

AllContact::AllContact(AllContact & a) {
  if (size > 0) {
    delete[] con;
  }
  size = a.size;
  con = new Contact[a.size];
  for (int i = 0; i < size; i++) {
    con[i] = a.con[i];
  }
}

int AllContact::getSize() {
  return size;
}

string AllContact::getPH(int nom) {
  return con[nom].getPH();
}

int AllContact::minc(int f_el) {
  if (size > 0) {
    Contact m = con[f_el];
    int n = f_el;
    for (int i = f_el+1; i < size; i++) {
      if (con[i] > m) {
        m = con[i];
        n = i;
      }
    }
    return n;
  }
  return -1;
}

void AllContact::Alphabet() {
  int n;
  for (int i1 = 0; i1 < size-1; i1++) {
    n =minc(i1);
    if (n != i1) swap_con(con[n], con[i1]);
  }
}



void AllContact::DopСon(Contact a) {
  AllContact res;
  res.size = size + 1;
  res.con = new Contact[res.size];
  for (int I = 0; I <= res.size - 2; I++) {
    res.con[I] = con[I];
  }
  res.con[res.size - 1] = a;
  (*this) = res;
}

void AllContact::to_screen(int num) {
  cout << con[num] << endl;
}

void AllContact::ChangeC(int nom) {
  con[nom].Change();
}



void AllContact::DelСon(int nom) {
  AllContact res;
  bool a;
    if (nom == size - 1) {
      a = 0;
    } else {
      a = 1;
    }
    res.size = size - 1;
    res.con = new Contact[res.size];
    if (a) {
      con[nom] = con[res.size];
    }
    for (int I = 0; I <= res.size - 1; I++) {
      res.con[I] = con[I];
    }
  (*this) = res;
}

void AllContact::imFav(int nom, bool like) {
  con[nom].imFav(like);
}

bool AllContact::getFav(int nom) {
  return con[nom].getFA();
}

int AllContact::i_poisk_fio(string i, string f, string o) {
  bool q;
  for (int a = 0; a < size; a++) {
    q = checkFIO(i, f, o, con[a].getNAME(), con[a].getFn(), con[a].getPA());
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

AllContact::~AllContact() {
  delete[] con;
  size = 0;
}

ostream & operator<<(ostream & stream, const AllContact & a) {
  Contact as;
  for (int i = 0; i < a.size; i++) {
    as = a.con[i];
    cout << as << endl;
  }
  return stream;
}

void AllContact::read_from_file() {
  //ifstream in;
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  std::fstream fs;

  fs.open("C:\\projects\\contacts.txt", std::fstream::in | std::fstream::out);

  if (!fs.is_open()) {
    std::cout << "Ошибка открытия файла!" << std::endl;
  }
  else {
    std::cout << "Файл открыт\n" << std::endl;
    if (fs.peek() == EOF)
    {
      std::cout << "Файл пуст\n";
    }
    else
    {
      if (size != 0) {
        delete[]con;
        size = 0;
      }
      fs >> size;
      con = new Contact[size];
      for (int i = 0; i < size; i++) {
        void imNAME(string n);
        void imFn(string n);
        void imPA(string n);
        void imPH(string n);
        void imFav(bool a);
        string name, fn, pa, bd, ph, fav;
        fs >> fn;
        con[i].imFn(fn);
        fs >> name;
        con[i].imNAME(name);
        fs >> pa;
        con[i].imPA(pa);
        fs >> ph;
        con[i].imPH(ph);
        fs >> bd;
        con[i].imBD(bd);
        fs >> fav;
        if (fav == "0") {
         con[i].imFav(0);
        } else {
          con[i].imFav(1);
        }

      }
      std::cout << "Данные успешно считаны" << std::endl << std::endl;
    }
  }
  fs.close();
}

void AllContact::imput_in_file()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  std::fstream fs;
  fs.open("C:\\projects\\contacts1.txt");

  if (!fs.is_open()) {
    std::cout << "Ошибка открытия файла!" << std::endl;
  }
  else {
    std::cout << "Файл открыт\n" << std::endl;
    if (fs.peek() != EOF)
    {
      std::cout << "Файл должен быть пустым\n" << std::endl;
    }
    else
    {
      for (int i = 0; i < size; i++) {
        string name, fn, pa, bd, ph, fav;
        bool f;
        name = con[i].getNAME();
        fn = con[i].getFn();
        pa = con[i].getPA();
        bd = con[i].getBD();
        ph = con[i].getPH();
        f = con[i].getFA();
        if (f == 0) {
          fav = "No";
        } else {
          fav = "Yes";
        }
        fs << "            name: " << fn << " " << name << " " << pa << std::endl;
        if ((ph != "0") && (ph != ""))  fs << "           phone:" << " " << ph << endl << std::endl;
        if (bd != "0") fs << "date of birthday: " << bd << endl << std::endl;
        fs << "       favorites: " << fav << std::endl;
      }
      std::cout << "Данные успешно выведены в файл" << std::endl << std::endl;
    }
  }
  fs.close();
}
