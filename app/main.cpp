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
	cout << "|| Вас приветствует контактная книга! ||" << endl;
	cout << "||                                    ||" << endl;
	cout << "|| Что бы вы хотели сделать?          ||" << endl;
	cout << "||                                    ||" << endl;
	cout << "||     1.Создать новый аккаунт        ||" << endl;
	cout << "||                                    ||" << endl;
	cout << "||     2.Найти контакт по ФИО         ||" << endl; 
	cout << "||                                    ||" << endl; 
	cout << "||     3.Изменить контакт выюранный   ||" << endl; 
	cout << "||             по ФИО                 ||" << endl; 
	cout << "||     4.Найти контакт по телефону    ||" << endl;
	cout << "||                                    ||" << endl;
	cout << "||     5.Выдать контакты по первой    ||" << endl;
	cout << "||           букве фамилии            ||" << endl;
	cout << "||     6.Узнать число контактов       ||" << endl;
	cout << "||                                    ||" << endl;
	cout << "||     7.Внести контакт, выбранный    ||" << endl;
	cout << "||       по ФИО в список избранных    ||" << endl;
	cout << "||     8.Удалить контакт, выбранный   ||" << endl;
	cout << "||       по ФИО из списка избранных   ||" << endl;
	cout << "||     9.Выдать все контакты          ||" << endl;
	cout << "||       из списка избранных          ||" << endl;
	cout << "||     10.Вывести все контакты        ||" << endl;
	cout << "||                                    ||" << endl;
	cout << "||     11.Удалить контакт по номеру   ||" << endl;
	cout << "||     12.Выход из программы          ||" << endl;
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
		cout << "Введите первую букву фамилии по которой будет оформляться поиск" << endl;
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
		cout << "Что-то не то вы ввели...";
		break;
	}

	system("pause");
	
}