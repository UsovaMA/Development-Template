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
	//������������
	Contact();//����
	Contact(const Contact& v);//����
	Contact(string _surname, string _name, string _otch, string _number, string _birthday, string _pol, string _status);//����

	~Contact();//����
	friend bool operator==(const Contact& a, const Contact& c) {
		bool res = 0;
		if ((a.surname == c.surname) && (a.name == c.name) && (a.otch == c.otch) && (a.birthday == c.birthday) && (a.number == c.number) && (a.pol == c.pol) && (a.status == c.status)) {
			res = 1;
		}
		return res;
	}

	//������
	/*����� ������ ������������� ��������� ��������: ,
  11) ��������� �������� � ���� � ������� �������� �� �����.
  1) ������� ����� �������, 2) ����� ������� �� ���; 3) �������� �������, ��������� �� ���, 4)
  ����� ������� �� ��������, 5) ������ ��� �������� �� �������� ��������� ����� ���, 6) ������
  ������� ����� ���������, 7) ������ �������, ��������� �� ��� � ������ ���������, 8) �������
  �������, ��������� �� ��� �� ������ ���������, 9) ������ ��� ��������� ��������, 10) �������
  �������, ��������� �� ��������
  */
	string Contact::getSurname() {
		Contact res;
		res.surname = this->surname;
		return res.surname;
	}
	string Contact::getName() {
		Contact res;
		res.name = this->name;
		return res.name;
	}
	string Contact::getOtch() {
		Contact res;
		res.otch = this->otch;
		return res.otch;
	}
	string Contact::getNumber() {
		Contact res;
		res.number = this->number;
		return res.number;
	}
	string Contact::getBirthday() {
		Contact res;
		res.birthday = this->birthday;
		return res.birthday;
	}
	string Contact::getPol(){
		Contact res;
		res.pol = this->pol;
		return res.pol;
	}
	string Contact::getStatus() {
		Contact res;
		res.status = this->status;
		return res.status;
	}
	//����
	void input_all_data();//
	Contact& operator =(const Contact& c);
	bool operator ==(const Contact& c);
	void input_fio();
	void input_number();
private:
	//���� ������
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
	Contacts();
	Contacts(int number_, Contact* book_);
	Contacts(const Contacts& c);

	~Contacts();

	Contacts& operator =(const Contacts& c);
	int Contacts::getNumber() {
		Contacts res;
		res.number = this->number;
		return res.number;
	}
	int find_by_fio(const Contact &new_contact);
	void input_and_number();
	int find_by_number(const string new_number);
	//int find_by_number(const Contact & new_contact);
	void output_info(int index);
	void change_by_fio(const Contact &new_contact);
	void add_to_favourites(const Contact & new_contact);
	void add_fvv();
	void create(const Contact &new_contact);
	void numberreturn();
	void input_and_create();
	void input_and_create_testver1();
	void input_and_create_testver2();
	int find_by_fio(string surname, string name, string otch);
	void input_and_find();
	void fill_mass_from_file();//
	void outputall();
	void fill_file_from_mass();//
	int search_by_first_letter(string firstletter);
	void retrun_all_favourites();
	void delete_from_favourites(const Contact & new_contact);
	void input_and_fvv();
	void input_and_delete_number();
	void find_and_delete(const Contact & new_contact);
	void input_and_change();
};
#endif //CONTACTCLASS_H