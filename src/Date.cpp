#include "Date.h"

using namespace std;
ostream& operator<<(ostream& stream, const Date& p);

Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(const Date& p) {
	day = p.day;
	month = p.month;
	year = p.year;
}

Date::Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {  }

Date::Date(string s) {
	string s1;
	string s2;
	string s3;
	s1.assign(s, 0, 2);
	int i = std::stoi(s1);
	s2.assign(s, 3, 5);
	int i2 = std::stoi(s2);
	day = i;
	s3.assign(s, 5, 11);
	int i3 = std::stoi(s3);
	month = i2;
	year = i3;
}

Date::~Date() {
	day = 0;
	month = 0;
	year = 0;
}

Date& Date::operator=(const Date& p) {
	(*this).day = p.day;
	month = p.month;
	year = p.year;
	return *this;
}

Date Date::operator+(int p) {
	Date res;
	day += p;
Point1:
	if ((day > 31) && ((month == 1) || (month == 3) || (month == 5) ||
		(month == 7) || (month == 9) || (month == 11) || (month == 12))) {
		month++;
		day -= 31;
		goto Point1;
	}
	else {
		if ((day > 30) && ((month == 4) || (month == 6) || (month == 8) ||
			(month == 10))) {
			month++;
			day -= 30;
			goto Point1;
		}
		else {
			if ((day > 28) && (month == 2)) {
				month++;
				day -= 28;
				goto Point1;
			}
		}
	}
	if (month > 12) {
		year++;
		month -= 12;
		goto Point1;
	}
	res.day = day;
	res.month = month;
	res.year = year;
	return res;
}

Date Date::operator-(int p) {
	Date res;
	day -= p;
Point2:
	if ((day < 1) && (month > 0)) {
		if ((month == 1) || (month == 3) || (month == 5) ||
			(month == 7) || (month == 9) || (month == 11) || (month == 12)) {
			month--;
			day += 31;
			goto Point2;
		}
		else {
			if ((month == 4) || (month == 6) || (month == 8) ||
				(month == 10)) {
				month--;
				day += 30;
				goto Point2;
			}
			else {
				if (month == 2) {
					month--;
					day += 28;
					goto Point2;
				}
			}
		}
	}
	if (month == 0) {
		month += 12;
		year--;
		goto Point2;
	}
	res.day = day;
	res.month = month;
	res.year = year;
	return res;
}

Date Date::operator+(const Date& p) {
	Date res;
	res.day = day + p.day;
	res.month = month + p.month;
	res.year = year + p.year;
	if (res.month > 12) {
		res.year++;
		res.month = res.month - 12;
	}
	if ((res.day > 31) && ((res.month == 1) || (res.month == 3) || (res.month == 5) ||
		(res.month == 7) || (res.month == 9) || (res.month == 11) || (res.month == 12))) {
		res.month++;
		res.day = res.day - 31;
	}
	else {
		if ((res.day > 30) && ((res.month == 4) || (res.month == 6) || (res.month == 8) ||
			(res.month == 10))) {
			res.month++;
			res.day = res.day - 30;
		}
		else {
			if ((res.day > 28) && (res.month == 2)) {
				res.month++;
				res.day = res.day - 28;
			}
		}
	}
	if (res.month > 12) {
		res.year++;
		res.month = res.month - 12;
	}
	return res;
}

bool Date::operator==(const Date& p) {
	bool res;
	if ((day == p.day) && (month == p.month) && (year == p.year)) { res = 1; }
	return res;
}

istream& operator>>(istream& stream, Date& p) {
	stream >> p.day >> p.month >> p.year;
	return stream;
}

ostream& operator<<(ostream& stream, const Date& p) {
	if (p.year < 0) {
		stream << p.day << "." << p.month << " " << p.year << " BC" << endl;
	}
	else {
		stream << p.day << "." << p.month << "." << p.year << endl;
	}
	return stream;
}