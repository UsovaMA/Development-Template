#ifndef INCLUDE_CINEMACLASS_H_
#define INCLUDE_CINEMACLASS_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Place { //класс места,в нём определяется тип места
public:
	bool placeFree;
	bool placeVIP;
	Place() { placeFree = true, placeVIP = false; }
};
class Hall { //класс зала в котором распределены места
public:
	Place room[20][20];
	Hall() {
		int i, j;
		for (i = 0; i < 5; ++i)
			for (j = 0; j < 10; ++j)
				room[i][j].placeVIP = free;
	}

	Hall& operator=(Hall &c1) {
		int i, j;
		for (i = 0; i < 15; ++i)
			for (j = 0; j < 15; ++j)
				room[i][j] = c1.room[i][j];
		return *this;
	}
};
class Film { //класс фильма,с его характеристиками
public:
	int numberOfHall;
	int numberOfFilm;
	string timeOfStart;
	string NameOfFilm;
	string duration;
	string ageRate;
	Film() {
		NameOfFilm = " ";
		numberOfHall = -1;
		timeOfStart = -1;
		duration = -1;
		numberOfHall = -1;
		ageRate = "0+";
	}
	Film(string _NameOfFilm, int _numberOfHall, string _timeOfStart, string _duration, int _numberOfFilm,string _ageRate) {
		NameOfFilm = _NameOfFilm;
		numberOfHall = _numberOfHall;
		timeOfStart = _timeOfStart;
		duration = _duration;
		numberOfFilm = _numberOfFilm;
		ageRate = _ageRate;
	}
	Film& operator=(Film &c1) {
		NameOfFilm = c1.NameOfFilm;
		numberOfHall = c1.numberOfHall;
		timeOfStart = c1.timeOfStart;
		duration = c1.duration;
		numberOfFilm = c1.numberOfFilm;
		ageRate = c1.ageRate;
		return *this;
	}
};
class DayTable { //расписание на день,в котором массив фильмов,тип зала,количество фильмов
public:
	Film* films;
	Hall types[3];
	int countFilms;
	DayTable() {
		films = new Film[15];
		countFilms = 0;
	}
};
class MonthTable { //рассписание на месяц и оставшееся место для записи(до 30 дней)
public:
	DayTable* days;
	int remainDays;
	MonthTable() {
		days = new DayTable[30];
		remainDays = 30;
	}
};
class Cinema { //собственно класс кинотеатра в котором у нас расписание на месяц и на день
public:
	DayTable day;
	MonthTable month;

	DayTable* get_info_for_3days(int day);
	void add_new_day(Film *film, int _countOfFilms);
	MonthTable move_array();
};
#endif  // INCLUDE_CINEMACLASS_H_
