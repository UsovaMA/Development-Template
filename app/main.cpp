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
	kniga.outputall();
	kniga.create();
	kniga.outputall();
	//kniga.fill_file_from_mass();


	system("pause");
}