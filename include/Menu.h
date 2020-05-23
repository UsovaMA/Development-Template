#ifndef INCLUDE_Menu_H_
#define INCLUDE_Menu_H_
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>

enum ExceptionType { wrongSize, outofAr};
struct ExMenu 
{
	ExceptionType type;
	int intSize;
	ExMenu(ExceptionType _type, int _intSize)
	{
		type = _type;
		intSize = _intSize;
	}
};


class Menu
{
private:
	int xCor;
	int yCor;
	int size;
	int numMenu;
	std::string* menu;

public:
	Menu();
	Menu(int x, int y, int sz, int num, std::string* Mn);
	Menu(const Menu& m);
	Menu(std::string nameMenu);
	~Menu();

	void Display();
	void Clear();
	int SelectionMenu();

	
};
#endif  // INCLUDE_Menu_H_
