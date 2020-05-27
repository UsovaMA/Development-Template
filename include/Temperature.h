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

	friend void randomise(const Temperature p); // ��������� ���������� ������ �����������
	friend void ComeToStart(Temperature p); // ������ ��������� ���� � ����� ����������
	friend void Add(Temperature p, int month, int day, int hours, int C); // �������� ����������
	friend void Get(Temperature p, int month, int day, int hours); // ������ ����������� � ����������, ��������� �� ���� � �������
	friend void GetSeries(Temperature p, int month, int day); // ������ ����� ���������� ��� ��������� ����
	friend double GetSr(Temperature p, int month, int day);
	friend double GetSr(Temperature p, int month);
	friend double GetSr(Temperature p);
	friend double GetSrTime(Temperature p, int month, int sel); // ������� ����������� ���������� ������ ��� ����, ���, ������ ��� ����
	friend void Write(Temperature p); // ������
	friend void Read(Temperature p); // ������

private:

	int Year;
	double MMDDTT[13][32][25]; // ������ ���� � ������� �� ���� 2020.12.31 23:00 � ����������� � �������� �������(�������� ������ �������)

};

#endif  // INCLUDE_Temperature_H_
