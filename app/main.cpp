// Copyright 2020 <Diana Lukashuk>
#include <iostream>
#include <fstream>
#include <clocale>
#include "Contacts.h"
#include "AllContact.h"
#include "FUN.h"
#include "windows.h"
using namespace std;

void meny() {
  cout << " _____________________________ " << endl;
  cout << "|  You can:                   |" << endl; 
  cout << "|1- find contact              |" << endl;
  cout << "|2- how many contacts         |" << endl;
  cout << "|7- last step                 |" << endl;
  cout << "|8- next step (view contacts) |" << endl;
  cout << "|9- Exit                      |" << endl;
  cout << "|_____________________________|" << endl;
  /////
  cout << " ___________________" << endl;
  cout << "|  By...            |" << endl; 
  cout << "|1-phone number     |" << endl;
  cout << "|2-name             |" << endl;
  cout << "|___________________|" << endl;
  //////
  cout << " _________________________________" << endl;
  cout << "|  You can do whith this contact: |" << endl;
  cout << "|1- delete contact                |" << endl;
  cout << "|2- add a contact to the list     |" << endl;
  cout << "|3- delete contact in list        |" << endl;
  cout << "|4- change contact                |" << endl;
  cout << "|5- comeback                      |" << endl;
  cout << "|_________________________________|" << endl;
  ///////
  cout << " _________________________________" << endl;
  cout << "|  You can:                       |" << endl;
  cout << "|1- output all contacts           |" << endl;
  cout << "|2- output favorite contacts      |" << endl;
  cout << "|3- delete contact in list        |" << endl;
  cout << "|4- output to file                |" << endl;
  cout << "|5- Last step (change contacts)   |" << endl;
  cout << "|6- Exit                          |" << endl;
  cout << "|_________________________________|" << endl;
}

int main() {
  setlocale(LC_ALL, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int i = 0;
  //exampleIn();
  Contact a;
  AllContact A;
  cout << "Hellow, it is a programm Contacts." << endl;
  cout << endl;
  string sdop1, sdop2, sdop3;
  int idop;
  while (i != 4) {
    switch (i) {
    case 0:
      cout << " ___________________ " << endl;
      cout << "| You can input:    |" << endl;
      cout << "|1- for txt document|" << endl;
      cout << "|2- by yourself     |" << endl;
      cout << "|4- Exit            |" << endl;
      cout << "|___________________|" << endl;
      cin >> i;
      break;
    case 1:

      break;
    case 2:
      exampleIn();
      cin >> a;
      A.DopСon(a);
      cout << "Do you want input again? (0-no, 1-yes)" << endl;
      cin >> i;
      if (i == 1) i = 2;
      if (i==0) i = 3;
      break;
    case 3:
      cout << " _____________________________ " << endl;
      cout << "|  You can:                   |" << endl;
      cout << "|1- find contact              |" << endl;
      cout << "|2- how many contacts         |" << endl;
      cout << "|3- last step                 |" << endl;
      cout << "|4- next step (view contacts) |" << endl;
      cout << "|5- Exit                      |" << endl;
      cout << "|_____________________________|" << endl;
      cin >> i;
      if (i==1){
        cout << " ___________________" << endl;
        cout << "|  By...            |" << endl;
        cout << "|1-phone number     |" << endl;
        cout << "|2-name             |" << endl;
        cout << "|___________________|" << endl;
        cin >> i;
        if (i == 1) {
          cout << "Enter phone number- " << endl;
          cin >> sdop1;
        }
        if (i == 2) {
          cout << "Enter name(surname, name, patronymic)- " << endl;
          cin >> sdop1 >> sdop2 >> sdop3;
          idop = A.i_poisk_fio(sdop1, sdop2, sdop3);
          if (idop==-1) {
            cout << "Contact not found" << endl;
          }
          else {
            i = 4;
            break;
          }
        }
      }
      if (i == 2) {}
      if (i == 3) {}
      if (i == 4) {}
      if (i == 5) {}
      break;
    case 4:
      cout << " _________________________________" << endl;
      cout << "|  You can do whith this contact: |" << endl;
      cout << "|1- delete contact                |" << endl;
      cout << "|2- add a contact to the list     |" << endl;
      cout << "|3- delete contact in list        |" << endl;
      cout << "|4- change contact                |" << endl;
      cout << "|5- comeback                      |" << endl;
      cout << "|_________________________________|" << endl;
      cin >> i;
      if (i == 1) {}
      if (i == 2) {}
      if (i == 3) {}
      if (i == 4) {}
      if (i == 5) {}
    default:
      i = 0;
      break;
    }
  }
  system("pause");
}