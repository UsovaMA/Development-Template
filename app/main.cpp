  // Copyright 2020 <Diana Lukashuk>
#include <iostream>
#include <fstream>
#include <clocale>
#include "Contacts.h"
#include "AllContact.h"
#include "FUN.h"
#include "windows.h"
using namespace std;

int main() {
  setlocale(LC_ALL, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int i = 0;
  Contact a;
  AllContact A;
  cout << "Hellow, it is a programm Contacts." << endl;
  cout << endl;
  string sdop1, sdop2, sdop3;
  int idop, i2, i3;
  while (i != 10) {
    switch (i) {
    case 0:
      cout << " ___________________ " << endl;
      cout << "| You can input:    |" << endl;
      cout << "|1- for txt document|" << endl;
      cout << "|2- by yourself     |" << endl;
      cout << "|3- Exit            |" << endl;
      cout << "|___________________|" << endl;
      cin >> i;
      if (i == 1) {
          A.read_from_file();
      }
      while (i == 2) {
        if (A.getSize() == 0)exampleIn();
        cin >> a;
        A.DopСon(a);
        cout << "Do you want input again? (0-no, 1-yes)";
        cin >> i;
        if (i == 1) i = 2;
        if (i == 0) i = 1;
      }
      if (i == 3) i = 10;
      A.Alphabet();
      break;
    case 1:
      cout << " _____________________________ " << endl;
      cout << "|  You can:                   |" << endl;
      cout << "|1- find contact              |" << endl;
      cout << "|2- how many contacts         |" << endl;
      cout << "|3- last step                 |" << endl;
      cout << "|4- next step (view contacts) |" << endl;
      cout << "|5- Exit                      |" << endl;
      cout << "|_____________________________|" << endl;
      cin >> i;
      i2 = -1;
      if (i == 3)  i3 = 0;
      if (i == 5)  i3 = 10;
      if (i == 1) {
        cout << " ___________________" << endl;
        cout << "|  By...            |" << endl;
        cout << "|1-phone number     |" << endl;
        cout << "|2-name             |" << endl;
        cout << "|___________________|" << endl;
        i2 = 0;
        while (i2 == 0) {
          cin >> i2;
        }
        if (i2 == 1) {
          cout << "Enter phone number- ";
          cin >> sdop1;
          idop = -1;
          for (int I = 0; I < A.getSize(); I++) {
            if (sdop1 == A.getPH(I)) {
              idop = I;
              break;
            }
          }
          if (idop == -1) {
            cout << "Contact not found" << endl;
            i3 = 1;
            break;
          } else {
            i3 = 2;
            A.to_screen(idop);
          }
        }
        if (i2 == 2) {
          cout << "Enter name(surname, name, patronymic)- ";
          cin >> sdop1 >> sdop2 >> sdop3;
          idop = A.i_poisk_fio(sdop2, sdop1, sdop3);
          if (idop == -1) {
            cout << "Contact not found" << endl;
            i3 = 1;
          } else {
            A.to_screen(idop);
            i3 = 2;
          }
        }
      }
      // 1/2
      if (i == 2) {
        cout << A.getSize() << " - sum of contacts" << endl;
        i3 = 1;
      }
      // будет 1
      if (i == 4)  i3 = 3;
      i = i3;
      A.Alphabet();
      break;
    case 2:
      cout << " _________________________________" << endl;
      cout << "|  You can do whith this contact: |" << endl;
      cout << "|1- delete contact                |" << endl;
      cout << "|2- add a contact to the list     |" << endl;
      cout << "|3- delete contact in list        |" << endl;
      cout << "|4- change contact                |" << endl;
      cout << "|5- comeback                      |" << endl;
      cout << "|_________________________________|" << endl;
      cin >> i2;
      if (i2 == 5) { i = 1;
      } else {
        if (i2 == 1) {
          A.DelСon(idop);
          cout << "|contact_deleted|" << endl;
          i = 1;
        }
        if (i2 == 2) {
          A.imFav(idop, 1);
          cout << "|contact added in list|" << endl;
        }
        if (i2 == 3) {
          A.imFav(idop, 0);
          cout << "|contact deleted in list|" << endl;
        }
        if (i2 == 4) {
          A.ChangeC(idop);
        }
      }
      A.Alphabet();
      break;
    case 3:
      cout << " ______________________________________" << endl;
      cout << "|  You can bring out:                  |" << endl;
      cout << "|1- all contact (consol)               |" << endl;
      cout << "|2- contact from the favorite (consol) |" << endl;
      cout << "|3- all contact (txt file)             |" << endl;
      cout << "|4- last step                          |" << endl;
      cout << "|5- exit                               |" << endl;
      cout << "|______________________________________|" << endl;
      cin >> i2;
      if (i2 == 1) {
        for (int I = 0; I < A.getSize(); I++) {
          A.to_screen(I);
        }
      }
      if (i2 == 2) {
        for (int I = 0; I < A.getSize(); I++) {
          if (A.getFav(I) == 1) A.to_screen(I);
        }
      }
      if (i2 == 3) {
        A.imput_in_file();
      }
      if (i2 == 4) i = 1;
      if (i2 == 5) i = 10;
      break;
    case 4:
    default:
      i = 0;
      break;
    }
  }
  system("pause");
}
