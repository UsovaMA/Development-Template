#ifndef INCLUDE_CLASS_HEX_HPP_
#define INCLUDE_CLASS_HEX_HPP_
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Hex {

private:
	unsigned char *Number;
	int size;
public:
	Hex();
	Hex(string number, int size_);
	Hex(const Hex &a);

	unsigned char& operator[] (const int index);
	Hex operator=(const Hex &number);
	Hex operator+(const Hex &number);
	Hex operator-(const Hex &number);
	friend bool operator<(const Hex &number1, const Hex &number2);
	friend bool operator>(const Hex &number1, const Hex &number2);
	friend bool operator==(const Hex &number1, const Hex &number2);
	friend std::ostream& operator<<(ostream &out, const Hex &Hex);
	friend std::ofstream& operator<<(ofstream& file, const Hex &number);
	friend std::ifstream& operator>>(ifstream& file, const Hex &number);
};

char* ConvertCC(string x, int fromCC, int toCC);

#endif INCLUDE_CLASS_TIME_HPP_
