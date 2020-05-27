#ifndef INCLUDE_Temperature_H_
#define INCLUDE_Temperature_H_
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
using namespace std;

class Temperature
{
public:
	Temperature();
	Temperature(int _Year);
	Temperature(const Temperature& p);
	~Temperature();

	friend void randomise(const Temperature p); // Рандомное заполнение данных температуры
	friend void ComeToStart(Temperature p); // Узнать начальную дату и время наблюдений
	friend void Add(Temperature p, int month, int day, int hours, int C); // Добавить наблюдение
	friend void Get(Temperature p, int month, int day, int hours); // Узнать температуру в наблюдении, выбранном по дате и времени
	friend void GetSeries(Temperature p, int month, int day); // Выдать серию наблюдений для выбранной даты
	friend double GetSr(Temperature p, int month, int day);
	friend double GetSr(Temperature p, int month);
	friend double GetSr(Temperature p);
	friend double GetSrTime(Temperature p, int month, int sel); // Средняя температура выбранного месяца для утра, дня, вечера или ночи
	friend void Write(Temperature p); // Запись
	friend void Read(Temperature p); // Чтение

private:

	int Year;
	double MMDDTT[13][32][25]; // Формат даты и времени по типу 2020.12.31 23:00 и температуры в градусах цельсия(значение ячейки массива)

};

#endif  // INCLUDE_Temperature_H_
