#include "DictionaryClassNew.h"
#include <iostream>
#include <Windows.h>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dictionary slovar;
	slovar.fill_mass_from_file();
	slovar.outputall();
	cout << "���������� ������ �����" << endl;
	slovar.input_and_create();
	slovar.outputall();
	cout << "��������� �������� ���������� �����" << endl;
	slovar.input_and_change();
	cout << "������ ������� ���������� �����" << endl;
	slovar.input_and_find();
	cout << "��������� ������� ����� � �������" << endl;
	slovar.find_find();
	cout << "������ ����� ���� � �������" << endl;
	slovar.return_number();
	slovar.fill_file_from_mass();
}
