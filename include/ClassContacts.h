// Copyright 2020 Serebrennikov
#pragma once
#include <iostream>
#include "ClassContact.h"

using namespace std;

class Contacts {
public:
  Contacts();
  Contacts(int _kolvo);
  Contacts(int _kolvo, const Contact* c);
  Contacts(const Contacts& c);
  
  int kolvo_contacts();                                       // вывести количество контактов

  void create_add(const Contact& new_contact);                // добавить новый контакт

  void output_array();                                        // вывод всех контактов
  void all_favorites();                                       // вывести всех избранных

  void add_to_array();

  Contacts& operator=(const Contacts &c);

  //int kolvo_contacts(int kolvo); // вывести количество контактов // »«Ѕџ“ќ„Ќќ

  void surname_input(string& _surname, string& _name, string& _patronymic);                // поиск по фамилии
  void search_by_surname(string _surname, string _name, string _patronymic);
  int search_by_surname_return_index(string _surname, string _name, string _patronymic);

  void search_tel_number_input(string& tel_number);             // поиск по телефону

  void search_tel_number_add(string tel_number);

  void add_to_favorites();              // добавить в избранные

  // изменение контакта
  void change_contact_input(string& new_surname, string& new_name, string& new_patronymic, Contact& modifide_contact);
  void change_contact_add(string _surname, string _name, string _patronymic, const Contact& modifide_contact);

  void search_letter_input(char b);
  void search_letter_add(char b);

  void delete_surname_add(Contact &contact);
  // удалить по номеру телефона
  void delete_tel_number_input(Contact &contact);
  void delete_tel_number_add(Contact &contact);
  void end(); // об€зательно в конце, перенос новых данных из массива в файл

private:
  Contact *base = new Contact [kolvo];
  int kolvo; 
};


