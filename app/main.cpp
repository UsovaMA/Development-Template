#include "Date.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	Date D1, D2(25, 2, 2020), D3(D2), D4("15.7.1990"), D5, D6;
	cout << "Success" << endl;
	cout << D2 << endl;
	D1 = D2 + D3;
	cout << D1 << endl;
	cout << D4 << endl;
	D4 = D4 + 75;
	cout << D4 << endl;
	D5 = D1 - 365;
	cout << D5 << endl;
	cin >> D6;
	cout << endl << D6 << endl;
	system("pause");
}