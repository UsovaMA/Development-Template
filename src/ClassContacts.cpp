// Copyright 2020 Serebrennikov
#include <iostream>
#include <locale>
#include <Windows.h>
#include <string>
#include <fstream>
#include "ClassContacts.h"
#include "ClassContact.h"

using namespace std;

#define MAX 100

Contacts::Contacts() {
  kolvo = 0;
}

Contacts::Contacts(int _kolvo) {
  kolvo = _kolvo;
  base = new Contact[kolvo];
}

Contacts::Contacts(int _kolvo, const Contact* c) {
  kolvo = _kolvo;
  base = new Contact[kolvo];
  for (int i = 0; i < kolvo; i++) {
    base[i] = c[i];
  }
}

Contacts::Contacts(const Contacts& c) {
  kolvo = c.kolvo;
  base = new Contact[kolvo];
  for (int i = 0; i < kolvo; i++) {
    base[i] = c.base[i];
  }
}

Contacts& Contacts::operator=(const Contacts &c) {
  base = c.base;
  kolvo = c.kolvo;
  return *this;
}

void Contacts::create_add(const Contact& new_contact) {
  Contact* new_base = new Contact[kolvo + 1];
  for (int i = 0; i < kolvo; i++) {
    new_base[i] = base[i];
  }
  new_base[kolvo] = new_contact;

  Contacts new_book(kolvo + 1, new_base);
  *this = new_book;
}

Contact& Contact::operator=(const Contact &c) {
  surname = c.surname;
  name = c.name;
  patronymic = c.patronymic;
  birthday = c.birthday;
  tel_number = c.tel_number;
  sex = c.sex;
  favorites = c.favorites;
  return *this;
}

int Contacts::kolvo_contacts() {
  int count;
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  /*ifstream f("D:\\user\\Desktop\\Tor Browser\\Contacts.txt");
  if (f.is_open()) {
    cout << "file open" << endl;
    f >> kolvo;
  } else {
    cout << "Unable to open file";
  }
  int count;
  count = kolvo;*/
  cout <<"Количество контактов = " << /*count*/ kolvo << endl;
  //kolvo = count;
  return kolvo;
}

void Contacts::add_to_array() { //запись инфы о контактах в массив структур
  int count;
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
 
  ifstream f("D:\\user\\Desktop\\Tor Browser\\Contacts.txt");
  if (f.is_open())
  {
    f >> count;
    kolvo = count;
    for (int i = 0; i <= count; i++) {
      f >> base[i];                             // чтобы так можно было я дописала перегрузку оператора >> в Contact
    }
    f.close();
  } else {
    cout << "Unable to open file";
  }
}

void Contacts::all_favorites() {
  cout << "Список избранных: ";
  int tmp1 = 0;
  for (int i = 0; i <= kolvo; i++) {
    if (base[i].returnFavorites() == 1) {
      cout << endl << base[i] << endl;
      tmp1++;
    }
  }
  if (tmp1 == 0)
    cout << "Пуст";
}

void Contacts::output_array() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  for (int i = 0; i <= kolvo - 1; i++) {
    cout << base[i] << endl;
  }
}


void Contacts::surname_input(string& _surname, string& _name, string& _patronymic) { //поиск по фамилии
  cout << "Введите Фамилию: ";
  cin >> _surname;
  cout << "Введите Имя: ";
  cin >> _name;
  cout << "Введите Отчество: ";
  cin >> _patronymic;
}

void Contacts::search_by_surname(string _surname, string _name, string _patronymic) {
  for (int i = 0; i < kolvo; i++) {
    if (base[i].returnSurname() == _surname) {
      if (base[i].returnName() == _name) {
        if (base[i].returnPatronymic() == _patronymic) {
          cout << base[i] << endl;
        } else {
          cout << "Контакт не найден" << endl;
          break;
        }
      } else {
        cout << "Контакт не найден" << endl;
        break;
      }
    }
  }
}

int Contacts::search_by_surname_return_index(string _surname, string _name, string _patronymic) {
  for (int i = 0; i < kolvo; i++) {
    if (base[i].returnSurname() == _surname) {
      if (base[i].returnName() == _name) {
        if (base[i].returnPatronymic() == _patronymic) {
          return i;
        } else {
          return -1;
          break;
        }
      }
      else {
        return -1;
        break;
      }
    }
  }
}

void Contacts::add_to_favorites() {
  string _surname, _name, _patronymic;
  surname_input(_surname, _name, _patronymic);

  for (int i = 0; i < kolvo; i++) {
    if (base[i].returnSurname() == _surname) {
      if (base[i].returnName() == _name) {
        if (base[i].returnPatronymic() == _patronymic) {
          cout << "Контакт добавлен в список избранных" << endl;
          base[i].setFavorites();
          break;
        } else {
          cout << "Контакт не найден" << endl;
          break;
        }
      } else {
        cout << "Контакт не найден" << endl;
        break;
      }
    }
  }
}

void Contacts::search_tel_number_input(string& tel_number) { //поиск по номеру телефона
  cout << "Введите номер телефона в формате 8(ХХХ)ХХХ-ХХ-ХХ: ";
  cin >> tel_number;
}

void Contacts::search_tel_number_add(string tel_number) {
  int tmp1 = 0;
  for (int i = 0; i <= kolvo; i++) {
    if (base[i].returnTelNumber() == tel_number) {
      tmp1++;
      cout << "Данные контакта: " << base[i].returnSurname() << " " << base[i].returnName() << endl;
      cout << "Номер телефона: " << base[i].returnTelNumber() << endl;
      cout << "День рождения: " << base[i].returnBirthday() << endl;
      cout << "Пол: " << base[i].returnSex() << endl;
      cout << "В избранных: ";
      if (base[i].returnFavorites() == 1)
        cout << "Да" << endl;
      else
        cout << "Нет" << endl;
      break;
    }
  }
  if (tmp1 == 0)
    cout << "Контакт не найден" << endl;
}


void Contacts::change_contact_input(string& new_surname, string& new_name, string& new_patronymic, Contact& modifide_contact) {
   cout << "Введите новые данные контакта: " << endl;
   cin >> modifide_contact;
}


void Contacts::change_contact_add(string _surname, string _name, string _patronymic, const Contact& modifide_contact) {
  int index = search_by_surname_return_index(_surname, _name, _patronymic);
  if (index != -1) {
    base[index] = modifide_contact;
  } else {
     cout << "Контакт не найден" << endl;
  }
}

void Contacts::search_letter_input(char b) {
  cout << "Введите первую букву фамилии: ";
  cin >> b;
}
void Contacts::search_letter_add(char b) {
  int tmp1 = 0;
  for (int i = 0; i <= kolvo; i++) {
    string tmppp = base[i].returnSurname();
    if (tmppp[0] ==  b) {
      tmp1++;
      cout << "Данные контакта: " << base[i].returnSurname() << " " << base[i].returnName() << endl;
      cout << "Номер телефона: " << base[i].returnTelNumber() << endl;
      cout << "День рождения: " << base[i].returnBirthday() << endl;
      cout << "Пол: " << base[i].returnSex() << endl;
      cout << "В избранных: ";
      if (base[i].returnFavorites() == 1)
        cout << "Да" << endl;
      else
        cout << "Нет" << endl;
      break;
    }
  }
  if (tmp1 == 0)
    cout << "Контакт не найден" << endl;
}


void Contacts::delete_surname_add(Contact &contact) {
  Contact delete_("", "", "", "", "", "", 3);
  Contact offset;

  for (int i = 0; i <= kolvo; i++) {
    if (base[i].returnSurname() == contact.returnSurname()) {
      if (base[i].returnName() == contact.returnName()) {
        if (base[i].returnPatronymic() == contact.returnPatronymic()) {
          int ii = i;
          cout << "Контакт удален" << endl;
          base[i] = delete_;

          for (ii; ii <= kolvo; ii++) {
            offset = base[i];
            base[i] = base[i + 1];
            base[i + 1] = offset;
          }
          kolvo--;
          break;
        }
        else {
          cout << "Контакт не найден" << endl;
          break;
        }
      }
      else {
        cout << "Контакт не найден" << endl;
        break;
      }
    }
  }
}

void Contacts::delete_tel_number_input(Contact &contact) {
  cout << "Введите номер телефона в формате 8(ХХХ)ХХХ-ХХ-ХХ: ";
  cin >> contact.returnTelNumber();
}
void Contacts::delete_tel_number_add(Contact &contact) {
  int p = 0;
  
  Contact delete_("","","","","","",3);
  Contact offset;

  for (int i = 0; i <= kolvo; i++) {
    if (base[i].returnTelNumber() == contact.returnTelNumber()) {
      int ii = i;
      cout << "Контакт удален" << endl;
      base[i] = delete_;

      for (ii; ii <= kolvo; ii++) {
        offset = base[i];
        base[i] = base[i + 1];
        base[i + 1] = offset;

        /*string tmppp;
        int tmppp1;
        tmppp = base[i + 1].returnSurname;
        base[i + 1].returnSurname = base[i].returnSurname;
        base[i].returnSurname = tmppp;
        tmppp = base[i + 1].returnName;
        base[i + 1].returnName = base[i].returnName;
        base[i].returnName = tmppp;
        tmppp = base[i + 1].returnPatronymic;
        base[i + 1].returnPatronymic = base[i].returnPatronymic;
        base[i].returnPatronymic = tmppp;
        tmppp = base[i + 1].returnBirthday;
        base[i + 1].returnBirthday = base[i].returnBirthday;
        base[i].returnBirthday = tmppp;
        tmppp = base[i + 1].returnTelNumber;
        base[i + 1].returnTelNumber = base[i].returnTelNumber;
        base[i].returnTelNumber = tmppp;
        tmppp = base[i + 1].returnSex;
        base[i + 1].returnSex = base[i].returnSex;
        base[i].returnSex = tmppp;
        tmppp1 = base[i + 1].returnFavorites;
        base[i + 1].returnFavorites = base[i].returnFavorites;
        base[i].returnFavorites = tmppp1;*/
      }
      kolvo--; p++;
      break;
    }
  }
  if (p == 0)
    cout << "Контакт не найден" << endl;
}

void Contacts::end() {
  int count;
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  ofstream f("D:\\user\\Desktop\\Tor Browser\\Contacts.txt");
  if (f.is_open())
  {
    f << kolvo << endl;

    for (int i = 0; i <= kolvo - 1; i++) {
      f << base[i].returnSurname() << endl;
      f << base[i].returnName() << endl;
      f << base[i].returnPatronymic() << endl;
      f << base[i].returnTelNumber() << endl;
      f << base[i].returnBirthday() << endl;
      f << base[i].returnSex() << endl;
      f << base[i].returnFavorites() << endl;
    }
    f.close();
  }
  else
  {
    cout << "Unable to open file";
  }
}