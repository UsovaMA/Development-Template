// Copyright free James-Bolt 2020

#include "Class_Hex.hpp"

int main() {
	Hex a("FF", 2);
	Hex b("AA", 2);
	Hex c("1", 1);
	cout << a + b << endl;
	a = c;
	cout << b + c - a << endl << a[0] << endl;
	return 0;
}
