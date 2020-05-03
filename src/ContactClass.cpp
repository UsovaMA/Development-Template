#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include "..\include\ContactClass.h"
#include <string>
#include <vector>
#include <locale>
#include <iostream>
#include <fstream>
#include <Windows.h>

#include "ContactClass.h"

#define MAX 1000

using namespace std;

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
Contact::Contact(string _surname, string _name, string _otch, string _number, string _birthday, string _pol, string _status) :
	surname(_surname),
	name(_name),
	otch(_otch),
	number(_number),
	birthday(_birthday),
	pol(_pol),
	status(_status)
{ }
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

Contact::~Contact() {
	surname = "";
	name = "";
	otch = "";
	number = "";
	birthday = "";
	pol = "";
	status = "";
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

Contacts::Contacts(const Contacts& c) {
	book = new Contact[c.number];
	number = c.number;
	for (int i = 0; i < number; i++) {
		book[i] = c.book[i];
	}
}

Contacts::~Contacts() {
	delete[] book;
	number = 0;
}
Contact& Contact::operator=(const Contact& c) {
		surname = c.surname;
		name = c.name;
		otch = c.otch;
		birthday = c.birthday;
		number = c.number;
		pol = c.pol;
		status = c.status;
		return *this;
	}
bool Contact::operator==(const Contact& c) {
	bool res = 0;
	if ((surname == c.surname) && (name == c.name) && (otch == c.otch) && (birthday == c.birthday) && (number == c.number) && (pol == c.pol) && (status == c.status)) {
		res = 1;
	}
	return res;
}

Contacts& Contacts::operator =(const Contacts& c) {
	if (number != 0 && number != c.number) {
		delete[] book;
		number = 0;
		book = new Contact[c.number];
	}
	number = c.number;
	for (int i = 0; i < number; i++) {
		book[i] = c.book[i];
	}

	return *this;
}

//реализация методов
void Contacts::fill_mass_from_file() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);//подключаем русский в консоль
	//далее суперспособ Марины Андреевны по чтению из файла

	std::ifstream fs;

	fs.open("C:/temp1/book.txt", ios::in);

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
			if (number != 0) {
				delete[]book;
				number = 0;
			}
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
void Contacts::fill_file_from_mass() {
	int count;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream f("C:/temp1/book.txt", ios::out);
	if (f.is_open())
	{
		f << number << endl;
		for (int i = 0; i <= number - 1; i++) {
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
void Contacts::create(const Contact &new_contact) {
	//Contact* book; - поясню, что ты пытаешься сделать:
  // у тебя дома есть ящик, туда мамка пришла и накидала яблок, 
  // ты хочешь взять яблоко и сделать из него яблоко в карамели,
  // идёшь к ящику, достаёшь из чулана второй пустой ящик и оттуда пытаешься достать яблоко
  // а мамка (компилятор) тебе такой: "ты чего в пустом ящике ищещь? я ж блин купила целый ящик"

  /* а вот теперь правильный код*/
	Contacts result;

	result.number = number + 1;
	result.book = new Contact[number + 1];
	for (int i = 0; i < number; i++) {
		result.book[i] = book[i];
	}


	result.book[result.number - 1].surname = new_contact.surname;
	result.book[result.number - 1].name = new_contact.name;
	result.book[result.number - 1].otch = new_contact.otch;
	result.book[result.number - 1].number = new_contact.number;
	result.book[result.number - 1].birthday = new_contact.birthday;
	result.book[result.number - 1].pol = new_contact.pol;
	result.book[result.number - 1].status = new_contact.status;
	(*this) = result;
}
// общая функция с созданием и вводом
void Contacts::input_and_create() {
	Contact new_contact;
	new_contact.input_all_data();         // ввод
	(*this).create(new_contact);          // алгоритм вставки
}
void Contacts::input_and_create_testver1() {
	Contact new_contact	("Грошева", "Дарья", "Дмитриевна", "+79113117958", "06.06.2001", "М", "Избран");     
	(*this).create(new_contact);          // алгоритм вставки
}
void Contacts::input_and_create_testver2() {
	Contact new_contact("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");;
	(*this).create(new_contact);          // алгоритм вставки
}
void Contacts::numberreturn() {
	int count = number;
	cout << "Количество контактов в книге: " << count << endl;
}
/* ВВОД ДОЛЖЕН БЫТЬ ОТДЕЛЁН ОТ АЛГОРИТМОВ */
void Contact::input_all_data() {
	cout << "Меню создания нового контакта" << endl;
	cout << "Введите Фамилию : ";
	cin >> surname;
	cout << endl << "Имя: ";
	cin >> name;
	cout << endl << "Отчество: ";
	cin >> otch;
	cout << endl << "Введите номер телефона в формате +7-(***)***-**-**(если телефон является домашним,то код города уточняйте) : ";
	cin >> number;
	cout << endl;
	cout << "Введите дату рождения в формате ДД.ММ.ГГ: ";
	cin >> birthday;
	cout << endl;
	cout << "Пол М/Ж: ";
	cin >> pol;
	cout << endl;
	cout << "Введите статус контакта Избранный/VIP/Родственик/Незвонитькогдапьяный" << endl;
	cin >> status;
	cout << endl;
}
void Contact::input_fio() {
	cout << "Введите фио для поиска" << endl;
	cin >> surname >> name >> otch;
}
int Contacts::find_by_fio(string surname,string name, string otch) {
	for (int i = 0; i <= number; i++) {
		if (book[i].surname == surname) {
			if (book[i].name == name) {
				if (book[i].otch == otch) {
					return i;
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
void Contacts::input_and_find() {
	string surname; string name; string otch;
	cout << "Введите фио для поиска" << endl;
	cin >> surname >> name >> otch;
	int i = (*this).find_by_fio(surname,name,otch);
	output_info(i);
}
void Contact::input_number() {
	cout << "Введите номер для поиска" << endl;
	cin >> number;
}

void Contacts::input_and_number() {
	cout << "Введите номер для поиска" << endl;
	string number_tel;
	cin >> number_tel;
	int k =(*this).find_by_number(number_tel);
	output_info(k);
 }
int Contacts::find_by_number(const string new_number) {
	for (int i = 0; i <= number; i++) {
		if (book[i].number == new_number) {
			return i;
		}
	}
}
void Contacts::output_info(int i) {
	cout << "Данные контакта: " << book[i].surname << " " << book[i].name << " " << book[i].otch << endl;
	cout << "Номер телефона: " << book[i].number << endl;
	cout << "День рождения: " << book[i].birthday << endl;
	cout << "Пол: " << book[i].pol << endl;
	cout << "В избранных: " << book[i].status << endl;
}
void Contacts::change_by_fio(const Contact &new_contact) {
	cout << "Вы изменяете данный контакт: " << endl;
	for (int i = 0; i <= number; i++) {
		if (book[i].surname == new_contact.surname) {
			if (book[i].name == new_contact.name) {
				if (book[i].otch == new_contact.otch) {
					cout << "Данные контакта: " << book[i].surname << " " << book[i].name << " " << book[i].otch << endl;
					cout << "Номер телефона: " << book[i].number << endl;
					cout << "День рождения: " << book[i].birthday << endl;
					cout << "Пол: " << book[i].pol << endl;
					cout << "В избранных: " << book[i].status << endl;
					cout << endl;
					cout << "Выберете то,что вы хотите изменить" << endl;
					cout << "1. ФИО" << endl;
					cout << "2. Номер" << endl;
					cout << "3. Дату рождения" << endl;
					cout << "4. Пол " << endl;
					cout << "5. Статус" << endl;
					int input;
					cin >> input;
					switch (input) {
					case 1:
						cout << "Введите новое ФИО через Enter" << endl;
						cin >> book[i].surname >> book[i].name >> book[i].otch;
						break;
					case 2:
						cout << "Введите новый номер телефона" << endl;
						cin >> book[i].number;
						break;
					case 3:
						cout << "Введите новую дату рождения" << endl;
						cin >> book[i].birthday;
						break;
					case 4:
						cout << "Введите новый пол (с чем судьба не шутит...)" << endl;
						cin >> book[i].pol;
						break;
					case 5:
						cout << "Введите новый статус" << endl;
						cin >> book[i].status;
					default:
						cout << "Что-то не то вы ввели...";
						break;
					}
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
void Contacts::add_to_favourites(const Contact &new_contact) {
	cout << "Вы добавляете в избранные данный контакт: " << endl;
	for (int i = 0; i <= number; i++) {
		if (book[i].surname == new_contact.surname) {
			if (book[i].name == new_contact.name) {
				if (book[i].otch == new_contact.otch) {
					cout << "Введите статус который вы хотите присвоить контакту" << endl;
					cout << "Избранный / VIP / Родственик / Незвонитькогдапьяный" << endl;
					string tmp_stat;
					book[i].status = tmp_stat;
				}
			}
		}
	}
}
void Contacts::add_fvv() {
	Contact new_contact;
	new_contact.input_fio();
	(*this).add_to_favourites(new_contact);
}

void Contacts::input_and_change() {
	Contact new_contact;
	new_contact.input_fio();
	(*this).change_by_fio(new_contact);
	cout << "Контакт изменен" << endl;
}


int Contacts::search_by_first_letter(string firstletter) {

	for (int i = 0; i <= number; i++) {
		if ((firstletter.substr(0, 1)) == book[i].surname.substr(0, 1)) {
			return i;
		}
	}
}
void Contacts::retrun_all_favourites() {
	cout << "Введите статус,контакты с которым вы хотели бы видеть" << endl;
	cout << "Избранный/VIP/Родственик/Незвонитькогдапьяный" << endl;
	string tmpstatus;
	cin >> tmpstatus;
	for (int i = 0; i <= number; i++) {
		if (book[i].status == tmpstatus) {
			cout << "Данные контакта: " << book[i].surname << " " << book[i].name << " " << book[i].otch << endl;
			cout << "Номер телефона: " << book[i].number << endl;
			cout << "День рождения: " << book[i].birthday << endl;
			cout << "Пол: " << book[i].pol << endl;
			cout << "В избранных: " << book[i].status << endl;
		}
	}
}
void Contacts::delete_from_favourites(const Contact &new_contact) {

	for (int i = 0; i <= number; i++) {
		if (book[i].surname == new_contact.surname) {
			if (book[i].name == new_contact.name) {
				if (book[i].otch == new_contact.otch) {
					book[i].status = "Не имеет статуса";
				}
				
			}
		}
	}
}
void Contacts::input_and_fvv() {
	Contact new_contact;
	new_contact.input_fio();         
	(*this).delete_from_favourites(new_contact); 
}
void Contacts::input_and_delete_number() {
	Contact new_contact;
	new_contact.input_number();
	(*this).find_and_delete(new_contact);
}
void Contacts::find_and_delete(const Contact &new_contact) {
	cout << "Вы пытаетесь удалить по номеру данный контакт: " << endl;
	for (int i = 0; i <= number; i++) {
		if (book[i].number == new_contact.number) {
			Contacts result;
			result.number = number + 1;
			for (int i = 0; i < number; i++) {
				result.book[i] = book[i];
			}
			result.book[result.number + 1].surname = new_contact.surname;
			result.book[result.number + 1].name = new_contact.name;
			result.book[result.number + 1].otch = new_contact.otch;
			result.book[result.number + 1].number = new_contact.number;
			result.book[result.number + 1].birthday = new_contact.birthday;
			result.book[result.number + 1].pol = new_contact.pol;
			result.book[result.number + 1].status = new_contact.status;
			(*this) = result;
		}
	}
}
