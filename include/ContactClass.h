#ifndef CONTACTCLASS_H
#define CONTACTCLASS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Contact {
	friend class Contacts;
public:
	//конструкторы
	Contact();
	Contact(const Contact& v);
	Contact(string _surname, string _name, string _otch, string _number, string _birthday, string _pol, string _status);

	//методы
	/*Класс должен предоставлять следующие операции: ,
  11) сохранить контакты в файл и считать контакты из файла.
  1) создать новый контакт, 2) найти контакт по ФИО; 3) изменить контакт, выбранный по ФИО, 4)
  найти контакт по телефону, 5) выдать все контакты на заданную начальную букву ФИО, 6) узнать
  текущее число контактов, 7) внести контакт, выбранный по ФИО в список избранных, 8) удалить
  контакт, выбранный по ФИО из списка избранных, 9) выдать все избранные контакты, 10) удалить
  контакт, выбранный по телефону
  */

	
	void change_by_fio();

private:
	//поля класса
	string surname;
	string name;
	string otch;
	string number;
	string birthday;
	string pol;
	string status;
};

class Contacts {
	friend class Contact;
private:
	Contact* book;

	int number;
public:
	void create();
	Contacts();
	Contacts(int number_, Contact* book_);
	Contacts(const Contacts& c);
	Contact *base = new Contact[number];
	void fill_mass_from_file();
	void outputall();

	void find_by_fio(string _surname, string _name, string _otch);
	void fill_file_from_mass();
	void search_by_number();
	void search_by_first_letter();
	void retrun_all_favourites();
	void delete_by_number();
	void delete_by_surname();
	int  return_count(int count);

	Contacts& addNewContact(const Contact new_contact);
};
#endif //CONTACTCLASS_H