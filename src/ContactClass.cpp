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

//���������� �������������
//�� ���������
Contact::Contact() {
	surname = "�� ������";
	name = "�� ������";
	otch = "�� ������";
	number = "+7.***.***.**.**";
	birthday = "��.��.��";
	pol = "�/�";
	status = "�� ������";
}
//�������������
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
//�����������
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


//���������� �������
void Contacts::fill_mass_from_file() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);//���������� ������� � �������
	//����� ����������� ������ ��������� �� ������ �� �����

	std::ifstream fs;

	fs.open("C:/temp1/book.txt", ios::in );

	if (!fs.is_open()) {
		std::cout << "������ �������� �����!" << std::endl;
	}
	else {
		std::cout << "���� ������\n" << std::endl;
		if (fs.peek() == EOF)
		{
			std::cout << "���� ����\n";
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
				std::cout << "������ ������� �������" << std::endl << std::endl;
			}
		}
	}
	fs.close();
}

void Contacts::outputall() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	for (int i = 0; i < number; i++) {
		cout << "������ ��������: " << book[i].surname << " " << book[i].name << " " << book[i].otch << endl;
		cout << "����� ��������: " << book[i].number << endl;
		cout << "���� ��������: " << book[i].birthday << endl;
		cout << "���: " << book[i].pol << endl;
		cout << "� ���������: " << book[i].status << endl;
	}
}
//��������� ���� �� �������
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
	cout << "������ ��� ���������� �����";
  }

}
//�������� �������� � ����������� ����
void Contacts::create() {
	Contact* book;
  cout << "���� �������� ������ ��������" << endl;
  cout << "������� ������� : ";
  cin >> book[num].surname;
  cout << endl << "���: ";
  cin >> book[num].name;
  cout << endl << "��������: ";
  cin >> book[num].otch;
  cout << endl << "������� ����� �������� � ������� +7-(***)***-**-**(���� ������� �������� ��������,�� ��� ������ ���������) : ";
  cin >> book[num].number;
  cout << endl;
  cout << "������� ���� �������� � ������� ��.��.��: ";
  cin >> book[num].birthday;
  cout << endl;
  cout << "��� �/�: ";
  cin >> book[num].pol;
  cout << endl;
  cout << "������� ������ �������� ���������/VIP/����������/��������������������";
  cin >> book[num].status;
  cout << endl;
  num++;
}
//����� ����� ������ �� ���
/*void Book::find_by_fio() {
  string tmp_surname, tmp_name, tmp_otch;
  cout << "����������� ����� �������� �� ���" << endl;
  cout << "������� ������� ��� � �������� �������� ����� enter: ";
  cin >> tmp_surname >> tmp_name >> tmp_otch;
  cout << "����������� ����� �� �������: " << tmp_surname << " " << tmp_name << " " << tmp_otch << endl;
  cout << "��� ��� ������� ����� �� �������..." << endl;
  for (int i = 0; i <= num; i++) {
	if (mass[i].surname == tmp_surname) {
	  if (mass[i].name == tmp_name) {
		if (mass[i].patronymic == tmp_otch) {
		  cout << "������ ��������: " << srch_surname << " " << srch_name << endl;
		  cout << "����� ��������: " << base[i].tel_number << endl;
		  cout << "���� ��������: " << base[i].birthday << endl;
		  cout << "���: " << base[i].sex << endl;
		  cout << "� ���������: "<<base[i].status<<endl;
		}
		else {
		  cout << "������� �� ������" << endl;
		  break;
		}
	  }
	  else {
		cout << "������� �� ������" << endl;
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