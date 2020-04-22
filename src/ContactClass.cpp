#include <string>
#include <vector>
#include <locale>
#include <iostream>
#include <fstream>
#include <Windows.h>

#include "ContactClass.h"

#define MAX 1000

using namespace std;
int num = 0;

//реализация конструкторов
//по умолчанию
Contact::Contact() {
	surname = "Не задано";
	name = "Не задано";
	otch = "Не задано";
	number = "+7.***.***.**.**";
	birthday = "ДД.ММ.ГГ";
	pol = "М/Ж";
	status = "Не избран";
}
//инициализации
Contact::Contact(string _surname, string _name, string _otch, string _number, string _birthday, string _pol, string _status)
{
	surname = _surname;
	name = _name;
	otch = _otch;
	number = _number;
	birthday = _birthday;
	pol = _pol;
	status = _status;
}
//копирования
Contact::Contact(const Contact& v) {
	surname = v.surname;
	name = v.name;
	otch = v.otch;
	number = v.number;
	birthday = v.birthday;
	pol = v.pol;
	status = v.status;
}


Contacts::Contacts() {
	book = nullptr;
	number = 0;
}

Contacts::Contacts(int number_, Contact* book_) {
	book = new Contact[number_];
	number = number_;
	for (int i = 0; i < number; i++) {
		book[i] = book_[i];
	}
}


//реализация методов
void Contacts::fill_mass_from_file() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);//подключаем русский в консоль
	//далее суперспособ Марины Андреевны по чтению из файла

	std::ifstream fs;

	fs.open("C:/temp1/book.txt", ios::in );

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
			if (number != 0) delete[]book;
			fs >> number;
			book = new Contact[number];
			for (int i = 0; i < number; i++) {
				fs >> book[i].surname;
				fs >> book[i].name;
				fs >> book[i].otch;
				fs >> book[i].number;
				fs >> book[i].birthday;
				fs >> book[i].pol;
				fs >> book[i].status;
				std::cout << "Данные успешно считаны" << std::endl << std::endl;
			}
		}
	}
	fs.close();
}

void Contacts::outputall() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	for (int i = 0; i < number; i++) {
		cout << "Данные контакта: " << book[i].surname << " " << book[i].name << " " << book[i].otch << endl;
		cout << "Номер телефона: " << book[i].number << endl;
		cout << "День рождения: " << book[i].birthday << endl;
		cout << "Пол: " << book[i].pol << endl;
		cout << "В избранных: " << book[i].status << endl;
	}
}
//наполняем файл из массива
void Contacts::fill_file_from_mass(){
  int count;
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  ofstream f("C:/temp1/book.txt", ios::out);
  if (f.is_open())
  {
	f << num << endl;
	book = new Contact[number];
	for (int i = 0; i <= num - 1; i++) {
	  f << book[i].surname << endl;
	  f << book[i].name << endl;
	  f << book[i].otch << endl;
	  f << book[i].number << endl;
	  f << book[i].birthday << endl;
	  f << book[i].pol << endl;
	  f << book[i].status << endl;
	}
	f.close();
  }
  else
  {
	cout << "Ошибка при открывании файла";
  }

}
//создание контакта с примитивным меню
void Contacts::create() {
	Contact* book;
  cout << "Меню создания нового контакта" << endl;
  cout << "Введите Фамилию : ";
  cin >> book[num].surname;
  cout << endl << "Имя: ";
  cin >> book[num].name;
  cout << endl << "Отчество: ";
  cin >> book[num].otch;
  cout << endl << "Введите номер телефона в формате +7-(***)***-**-**(если телефон является домашним,то код города уточняйте) : ";
  cin >> book[num].number;
  cout << endl;
  cout << "Введите дату рождения в формате ДД.ММ.ГГ: ";
  cin >> book[num].birthday;
  cout << endl;
  cout << "Пол М/Ж: ";
  cin >> book[num].pol;
  cout << endl;
  cout << "Введите статус контакта Избранный/VIP/Родственик/Незвонитькогдапьяный";
  cin >> book[num].status;
  cout << endl;
  num++;
}
//далее метод поиска по ФИО
/*void Book::find_by_fio() {
  string tmp_surname, tmp_name, tmp_otch;
  cout << "Выполняется поиск контакта по ФИО" << endl;
  cout << "Введите Фамилию Имя и Отчество контакта через enter: ";
  cin >> tmp_surname >> tmp_name >> tmp_otch;
  cout << "Выполняется поиск по запросу: " << tmp_surname << " " << tmp_name << " " << tmp_otch << endl;
  cout << "Вот что удалось найти по запросу..." << endl;
  for (int i = 0; i <= num; i++) {
	if (mass[i].surname == tmp_surname) {
	  if (mass[i].name == tmp_name) {
		if (mass[i].patronymic == tmp_otch) {
		  cout << "Данные контакта: " << srch_surname << " " << srch_name << endl;
		  cout << "Номер телефона: " << base[i].tel_number << endl;
		  cout << "День рождения: " << base[i].birthday << endl;
		  cout << "Пол: " << base[i].sex << endl;
		  cout << "В избранных: "<<base[i].status<<endl;
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
*/
/*Contacts& Contacts::addNewContact(const Contact new_contact) {
	Contacts result;
	result.book = new Contacts[this->number + 1];
	for (int i = 0; i < this->number; i++) {
		result.book[i] = this->book[i];
	}
	result.book[number] = new_contact;
	result.number = this->number + 1;
	return result;
}*/