#include <iostream>
#include <fstream>
#include <Windows.h>

#include "ContactClass.h"

int main() {
	Contacts kniga;
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	kniga.fill_mass_from_file();
	start:
	cout << "_______________________________________" << endl;
	cout << "|                                      |" << endl;
	cout << "| ------------------------------------ |" << endl;
	cout << "|| ��� ������������ ���������� �����! ||" << endl;
	cout << "||                                    ||" << endl;
	cout << "|| ��� �� �� ������ �������?          ||" << endl;
	cout << "||                                    ||" << endl;
	cout << "||     1.������� ����� �������        ||" << endl;
	cout << "||                                    ||" << endl;
	cout << "||     2.����� ������� �� ���         ||" << endl; 
	cout << "||                                    ||" << endl; 
	cout << "||     3.�������� ������� ���������   ||" << endl; 
	cout << "||             �� ���                 ||" << endl; 
	cout << "||     4.����� ������� �� ��������    ||" << endl;
	cout << "||                                    ||" << endl;
	cout << "||     5.������ �������� �� ������    ||" << endl;
	cout << "||           ����� �������            ||" << endl;
	cout << "||     6.������ ����� ���������       ||" << endl;
	cout << "||                                    ||" << endl;
	cout << "||     7.������ �������, ���������    ||" << endl;
	cout << "||       �� ��� � ������ ���������    ||" << endl;
	cout << "||     8.������� �������, ���������   ||" << endl;
	cout << "||       �� ��� �� ������ ���������   ||" << endl;
	cout << "||     9.������ ��� ��������          ||" << endl;
	cout << "||       �� ������ ���������          ||" << endl;
	cout << "||     10.������� ��� ��������        ||" << endl;
	cout << "||                                    ||" << endl;
	cout << "||     11.������� ������� �� ������   ||" << endl;
	cout << "||     12.����� �� ���������          ||" << endl;
	cout << "||____________________________________||" << endl;
	cout << "|              _________               |" << endl;
	cout << "|             |         |              |" << endl;
	cout << "|             |         |              |" << endl;
	cout << "|             |         |              |" << endl;
	cout << "|             |_________|              |" << endl;
	cout << "|______________________________________|" << endl;
	int input;
	string firstletter;
	cin >> input;
	system("cls");
	switch (input) {
	case 1:
		kniga.input_and_create();
		kniga.fill_file_from_mass();
		goto start;
		break;
	case 2:
		kniga.input_and_find();
		goto start;
		break;
	case 3:
		kniga.input_and_change();
		goto start;
		break;
	case 4:
		kniga.input_and_number();
		goto start;
		break;
	case 5:
		cout << "������� ������ ����� ������� �� ������� ����� ����������� �����" << endl;
		cin >> firstletter;
		kniga.output_info(kniga.search_by_first_letter(firstletter));
		goto start;
		break;
	case 6:
		kniga.numberreturn();
		goto start;
		break;
	case 7:
		kniga.add_fvv();
		goto start;
		break;
	case 8:
		kniga.input_and_fvv();
		goto start;
		break;
	case 9:
		kniga.retrun_all_favourites();
		goto start;
		break;
	case 10:
		kniga.outputall();
		goto start;
		break;
	case 11:
		kniga.input_and_delete_number();
		goto start;
		break;
	case 12:
		kniga.fill_file_from_mass();
		exit(0);
	default:
		cout << "���-�� �� �� �� �����...";
		break;
	}

	system("pause");
	
}