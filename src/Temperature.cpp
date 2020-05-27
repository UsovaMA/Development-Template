#include "Temperature.h"
#include <Windows.h>
#define MAX 100

// Определение кол-ва дней в месяце
int Def(int month) {
	int res;
	if ((month == 1) || (month == 3) || (month == 5) ||
		(month == 7) || (month == 9) || (month == 11) || (month == 12)) {
		res = 31;
	}
	if ((month == 4) || (month == 6) || (month == 8) || (month == 10)) { res = 30; }
	if (month == 2) { res = 28; }
	return res;
}

Temperature::Temperature() {
	Year = 0;
	for (int month = 1; month <= 12; ++month) {
		int N = Def(month);
		for (int day = 1; day <= N; ++day) {
			for (int hours = 1; hours <= 24; ++hours) {
				MMDDTT[month][day][hours] = 0;
			}
		}
	}
}

Temperature::Temperature(int _Year) {
	Year = _Year;
	for (int month = 1; month < 12; ++month) {
		int N = Def(month);
		for (int day = 1; day < N; ++day) {
			for (int hours = 1; hours < 24; ++hours) {
				MMDDTT[month][day][hours] = 0;
			}
		}
	}
}

Temperature::Temperature(const Temperature& p) {
	Year = p.Year;
	for (int month = 1; month <= 12; ++month) {
		int N = Def(month);
		for (int day = 1; day <= N; ++day) {
			for (int hours = 1; hours <= 24; ++hours) {
				MMDDTT[month][day][hours] = p.MMDDTT[month][day][hours];
			}
		}
	}
}

Temperature::~Temperature() {
	Year = 0;
	for (int month = 1; month <= 12; ++month) {
		int N = Def(month);
		for (int day = 1; day <= N; ++day) {
			for (int hours = 1; hours <= 24; ++hours) {
				MMDDTT[month][day][hours] = 0;
			}
		}
	}
}



// Рандомное заполнение данных температуры
void randomise(Temperature p) {
	int min = -30;
	int max = 30;
	for (int month = 1; month <= 12; ++month) {
		int N = Def(month);
		for (int day = 1; day <= N; ++day) {
			for (int hours = 1; hours <= 24; ++hours) {
				p.MMDDTT[month][day][hours] = (max - min) * ((double)rand() / RAND_MAX) + min;
			}
		}
	}
}

// Узнать начальную дату и время наблюдений
void ComeToStart(Temperature p) {
	cout << p.Year << "." << "1.1 01:00" << endl;
}

// Добавить наблюдение
void Add(Temperature p, int month, int day, int hours, int C) {
	cout << p.Year << "." << month << "." << day << " " << hours << ":00 = ";
	p.MMDDTT[month][day][hours] = C;
	cout << p.MMDDTT[month][day][hours] << endl;
}

// Узнать температуру в наблюдении, выбранном по дате и времени
void Get(Temperature p, int month, int day, int hours) {
	cout << p.Year << "." << month << "." << day << " " << hours << ":00 = " << p.MMDDTT[month][day][hours] << endl;
}

// Выдать серию наблюдений для выбранной даты
void GetSeries(Temperature p, int month, int day) {
	for (int hours = 1; hours <= 24; ++hours) {
		cout << p.Year << "." << month << "." << day << " " << hours << ":00 = " << p.MMDDTT[month][day][hours] << endl;
	}
}

/*Средняя температура для*/
//Выбранной даты
double GetSr(Temperature p, int month, int day) {
	double res = 0;
	for (int hours = 1; hours <= 24; ++hours) {
		res += p.MMDDTT[month][day][hours];
	}
	return res / 24;
}
//Выбранного месяца
double GetSr(Temperature p, int month) {
	double res = 0;
	int N = Def(month);
	for (int day = 1; day <= N; ++day) {
		for (int hours = 1; hours <= 24; ++hours) {
			res += p.MMDDTT[month][day][hours];
		}
	}
	return res / (N * 24);
}
//Выбранного года
double GetSr(Temperature p) {
	double res = 0;
	int temp = 24;
	for (int month = 1; month <= 12; ++month) {
		int N = Def(month);
		temp *= N;
		for (int day = 1; day <= N; ++day) {
			for (int hours = 1; hours <= 24; ++hours) {
				res += p.MMDDTT[month][day][hours];
			}
		}
	}
	return res / (temp * 12);
}

// Средняя температура выбранного месяца для утра, дня, вечера или ночи
double GetSrTime(Temperature p, int month, int sel) {
	int temp = Def(month);
	double res = -273;
	switch (sel) {
	default:
		cout << "Error, try again!" << endl;
		return res;
		break;
	case 1: //Утро		
		for (int day = 1; day <= temp; ++day) {
			for (int hours = 4; hours <= 9; ++hours) {
				res += p.MMDDTT[month][day][hours];
			}
		}
		break;
	case 2: //День
		for (int day = 1; day <= temp; ++day) {
			for (int hours = 10; hours <= 15; ++hours) {
				res += p.MMDDTT[month][day][hours];
			}
		}
		break;
	case 3: //Вечер
		for (int day = 1; day <= temp; ++day) {
			for (int hours = 16; hours <= 21; ++hours) {
				res += p.MMDDTT[month][day][hours];
			}
		}
		break;
	case 4: //Ночь
		for (int day = 1; day <= temp; ++day) {
			for (int hours = 22; hours <= 24; ++hours) {
				res += p.MMDDTT[month][day][hours];
			}
			for (int hours = 1; hours <= 3; ++hours) {
				res += p.MMDDTT[month][day][hours];
			}
		}
		break;

	}
	return res / (temp * 6);
}

// Запись данных в файл
void Write(Temperature p) {
	ofstream stout;
	stout.open("Write.txt");
	stout << p.Year << endl;
	for (int month = 1; month <= 12; ++month) {
		int N = Def(month);
		stout << "	Month is " << month << endl;
		for (int day = 1; day <= N; ++day) {
			stout << "		Day № " << day << endl;
			for (int hours = 1; hours <= 24; ++hours) {
				stout << "			" << hours << ":00 t°=" << p.MMDDTT[month][day][hours] << "°" << endl;
				stout.close();
			}
		}
	}
}

void Read(Temperature p) {
	ifstream stIn("Read.txt");
	p.Year = stIn;

}
