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
	Contact();
	Contact(const Contact& v);
	Contact(string _surname, string _name, string _otch, string _number, string _birthday, string _pol, string _status);

	//������
	/*����� ������ ������������� ��������� ��������: ,
  11) ��������� �������� � ���� � ������� �������� �� �����.
  1) ������� ����� �������, 2) ����� ������� �� ���; 3) �������� �������, ��������� �� ���, 4)
  ����� ������� �� ��������, 5) ������ ��� �������� �� �������� ��������� ����� ���, 6) ������
  ������� ����� ���������, 7) ������ �������, ��������� �� ��� � ������ ���������, 8) �������
  �������, ��������� �� ��� �� ������ ���������, 9) ������ ��� ��������� ��������, 10) �������
  �������, ��������� �� ��������
  */

	
	void change_by_fio();

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