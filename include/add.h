#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_

#pragma once
#include <string>
#include <stdio.h>
#include <vector>
#include <locale.h>
#include <iostream>

using namespace std;

class Bankomat
{
public:

private:

};

class ProcCenter
{
public:
	void getp();
private:
	vector <Help> person;
};

class Help {
public:
	Help(string _firstname, string _secondname, string _thname, int _ID, int _money, int _PIN, bool _block);
	void seth(string _firstname, string _secondname, string _thname, int _ID, int _money, int _PIN, bool _block);
	~Help() {};
private:
	string firstname;
	string secondname;
	string thname;
	int ID;
	int money;
	int PIN;
	bool block;
};
#endif  // INCLUDE_ADD_H_
