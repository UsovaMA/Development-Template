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

Contact::Contact() {
  surname = "Серебренников";
  name = "Мирон";
  patronymic = "Михайлович";
  tel_number = "89229610000";
  birthday = "23.03.2001";
  sex = "M";
  favorites = 0;
}

Contact::Contact(string _surname, string _name, string _patronymic, string _tel_number,
string _birthday, string _sex, int _favorites) {
  surname = _surname;
  name = _name;
  patronymic = _patronymic;
  tel_number = _tel_number;
  birthday = _birthday;
  sex = _sex;
  favorites = _favorites;
}

Contact::Contact(const Contact& c) {
  surname = c.surname;
  name = c.name;
  patronymic = c.patronymic;
  tel_number = c.tel_number;
  birthday = c.birthday;
  sex = c.sex;
  favorites = c.favorites;
  
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

std::istream& operator>>(std::istream& stream, Contact& c) {
  cout << "Фамилия: ";
  stream >> c.surname;
  cout << "Имя: ";
  stream >> c.name;
  cout << "Отчество: ";
  stream >> c.patronymic;
  cout << "Номер телефона: ";
  stream >> c.tel_number;
  cout << "День рождения: ";
  stream >> c.birthday;
  cout << "Пол: ";
  stream >> c.sex;
  cout << "Добавить в избранные: " << endl;
  cout << "1 - ДА | 2 - НЕТ " << endl;
  cout << "Добавить?: ";
  stream >> c.favorites;
  return stream;
}

std::ostream& operator<<(std::ostream& stream, const Contact& c) {
  stream << "ФИО: " << c.surname << " " << c.name << " " << c.patronymic << endl;
  stream << "Номер телефона: " << c.tel_number << endl;
  stream << "День рождения: " << c.birthday << endl;
  stream << "Пол: " << c.sex << endl;
  stream << c.favorites << endl;
  stream << "В избранных: ";
  if (c.favorites == 1)
    stream << "ДА" << endl;
  else
    stream << "НЕТ" << endl;
  return stream;
}

int Contact::returnFavorites() {
  return favorites;
}

void Contact::setFavorites() {
  favorites = 1;
}

string Contact::returnSurname() {
  return surname;
}

string Contact::returnName() {
  return name;
}

string Contact::returnPatronymic() {
  return patronymic;
}

string Contact::returnTelNumber() {
  return tel_number;
}

string Contact::returnBirthday() {
  return birthday;
}

string Contact::returnSex() {
  return sex;
}


void Contact::create_input(Contact &new_contact) {
  cout << "Создание нового пользователя в телекнижке:" << endl;
  cout << "Фамилия: ";
  cin >> new_contact.surname;
  cout << "Имя: ";
  cin >> new_contact.name;
  cout << "Отчество: ";
  cin >> new_contact.patronymic;
  cout << endl;
  cout << "Номер телефона в формате 8(ХХХ)ХХХ-ХХ-ХХ: ";
  cin >> new_contact.tel_number;
  cout << endl;
  cout << "День рождения в формате: " << endl;
  cout << "ДД.ММ.ГГГГ: ";
  cin >> new_contact.birthday;
  cout << endl;
  cout << "Пол (М/Ж) : ";
  cin >> new_contact.sex;
  cout << endl;
  cout << "Относиться ли контакт к избранным?" << endl;
  cout << "1 - ДА" << endl;
  cout << "0 - НЕТ" << endl;
  cout << "В избранном: ";
  int tmp12;
  cin >> tmp12;
  if (tmp12 == 1)
    new_contact.favorites = 1;
  else
    new_contact.favorites = 0;
}