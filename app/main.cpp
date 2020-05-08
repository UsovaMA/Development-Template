// Copyright free James-Bolt 2020

#include "Class_Dictionary.hpp"

int main() {
	setlocale(LC_ALL, "Russian");
	string a = "Mother", b = "Мама";
	Word c("Mother", "Мама");
	c.show_word();
	Dictionary mass;
	mass.add_word(a, b);
	mass.show_translation(0);
	/*mass.set_data_to_file("C://Data.txt");
	mass.get_data_from_file("C://Data.txt");*/
	Dictionary mass1;
	mass1.add_word("Dad", "Папа");
	mass = mass1;
	mass.show_translation(0);
	Dictionary mass2;
  mass2 = mass + mass1;
	mass2.show_translation(1);
	delete[] mass.arr;
	return 0;
}
