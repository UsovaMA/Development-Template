#include "add.h"
#include <string>

void Help::seth(string _firstname, string _secondname, string _thname, int _ID, int _money, int _PIN, bool _block)
{
	firstname = _firstname;
	secondname = _secondname;
	thname = _thname;
	ID = _ID;
	money = _money;
	PIN = _PIN;
	block = _block;
}

vector <Help> n;

Help::Help(string _firstname, string _secondname, string _thname, int _ID, int _money, int _PIN, bool _block) {
	int newmoney, newPIN, newID;
	bool newblock;
	string newfirstname, newsecondname, newthname;
	newfirstname = _firstname;
	newsecondname = _secondname;
	newthname = _thname;
	newblock = _block;
	do {
		newPIN = _PIN;
	} while (_PIN > 0 || _PIN < 9999);
	do {
		newmoney = _money;
	} while (_money > 0);
	do {
		newID = _ID;
	} while (_PIN > 0 || _PIN < 9999);
	seth(newfirstname, newsecondname, newthname, newID, newmoney, newPIN, newblock);
}

void ProcCenter::getp()
{
	string firstname, secondname, thname;
	int ID, PIN, money;
	bool block = false;
	cout << "Введите имя: ";
	cin >> firstname;
	cout << endl << "Введите фамилию: ";
	cin >> secondname;
	cout << endl << "Введите отчество: ";
	cin >> thname;
	cout << endl << "Введите номер карты: ";
	cin >> ID;
	cout << endl << "Введите кол-во денег на карте: ";
	cin >> money;
	cout << endl << "Введите PIN";
	cin >> PIN;

	Help buffer(firstname, secondname, thname, ID, money, PIN, block); // Векторы топ. Зачем я использовал динмас в 4 лабе?Хм, но переписывать я ее конечно не буду 
	person.push_back(buffer);
}

