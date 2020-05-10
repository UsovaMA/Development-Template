#include "DictionaryClassNew.h"
#include <iostream>
#include <Windows.h>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dictionary slovar;
	slovar.fill_mass_from_file();
	slovar.outputall();
	cout << "Добавление нового слова" << endl;
	slovar.input_and_create();
	slovar.outputall();
	cout << "Изменение перевода указанного слова" << endl;
	slovar.input_and_change();
	cout << "Узнать перевод выбранного слова" << endl;
	slovar.input_and_find();
	cout << "Проверить наличие слова в словаре" << endl;
	slovar.find_find();
	cout << "Узнать число слов в словаре" << endl;
	slovar.return_number();
	slovar.fill_file_from_mass();
}
