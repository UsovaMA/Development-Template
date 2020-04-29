// Copyright 2020 Serebrennikov
#pragma once
#include <iostream>

using namespace std;

class Contact {
public:
  Contact();
  Contact(string _surname, string _name, string _patronymic, string tel_number,
    string _birthday, string _sex, int _favorites);
  Contact(const Contact& c);

  Contact& operator=(const Contact &c);
  friend std::istream& operator>>(std::istream& stream, Contact& c);
  friend std::ostream& operator<<(std::ostream& stream, const Contact& c);

  int returnFavorites();
  void setFavorites();
  string returnSurname();
  string returnName();
  string returnPatronymic();
  string returnTelNumber();
  string returnBirthday();
  string returnSex();

  void create_input(Contact& new_contact);              //создать новый контакт
  
  //void add_to_array(); // добавление контактов из файла в массив
  
  void end(); // обязательно в конце, перенос новых данных из массива в файл

private:
  string surname;
  string name;
  string patronymic;
  string tel_number;
  string birthday;
  string sex;
  int favorites; 
};

//int add_to_array(); //заполнение массива контактами из файла 
