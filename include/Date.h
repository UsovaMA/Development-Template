#ifndef INCLUDE_Date_H_
#define INCLUDE_Date_H_
#pragma once
#include <clocale>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



class Date {
public:
	Date();
	Date(const Date& p);
	Date(int _day, int _month, int _year);
	Date(string s);
	~Date();

	Date& operator=(const Date& p);
	Date operator+(const Date& p);
	Date operator+(int p);
	bool operator==(const Date& p);
	Date operator-(int p);

	friend istream& operator>>(istream& stream, Date& p);
	friend ostream& operator<<(ostream& stream, const Date& p);

private:
	int day, month, year;
};


#endif  // INCLUDE_Date_H_
