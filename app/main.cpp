#include <clocale>
#include <iostream>
#include <fstream>
#include <string>
#include "FloorScales.h"
using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian");

  int num;
  int day, mon, year;
  double weight;

  FloorScales person;
  try
  {
    person.read();
    cout << person;
  }
  catch (ExFloorScales exp)
  {
    if (exp.type == nofile)
    {
      cout << "������ ��� �������� �����" << endl;
    }

  }
  
  PrintMenu();
  int flag = 1;
  while (flag)
  {
    try
    {
      cout << "������� �����: ";
      cin >> num;
      switch (num)
      {
      case 1:
      {
        Nabl res;
        res = person.startDate();
        cout << res;
        PrintMenu();
        break;
      }
      case 2:
      {
        cout << "������� ����: ";
        cin >> day >> mon >> year;
        cout << "������� ���: ";
        cin >> weight;
        person.setNabl(day, mon, year, weight);
        PrintMenu();
        break;

      }
      case 3:
      {
        cout << "������� ����: ";
        cin >> day >> mon >> year;
        weight = person.showWeight(day, mon, year);
        cout << "���: " << weight << endl;
        PrintMenu();
        break;
      }
      case 4:
      {
        cout << "������� ����: ";
        cin >> mon >> year;
        weight = person.averageWeightMon(mon, year);
        cout << "���: " << weight << endl;;
        PrintMenu();
        break;
      }
      case 5:
      {
        weight = person.averageWeight();
        cout << "���: " << weight << endl;
        PrintMenu();
        break;
      }
      case 6:
      {
        Nabl res;
        cout << "������� ����: ";
        cin >> mon >> year;
        res = person.maxWeightMon(mon, year);
        cout << res;
        PrintMenu();
        break;
      }
      case 7:
      {
        Nabl res;
        res = person.maxWeight();
        cout << res;
        PrintMenu();
        break;
      }
      case 8:
      {
        Nabl res;
        cout << "������� ����: ";
        cin >> mon >> year;
        res = person.minWeightMon(mon, year);
        cout << res;
        PrintMenu();
        break;
      }
      case 9:
      {
        Nabl res;
        res = person.minWeight();
        cout << res;
        PrintMenu();
        break;
      }
      case 0:
      {
        flag = 0;
        PrintMenu();
        break;
      }
      }
    }
    catch (ExFloorScales exp)
    {
      switch (exp.type)
      {
      case nodate:
      {
        cout << "�������� ����" << endl;
        break;
      }
      case bufOver:
      {
        cout << "���������� ������" << endl;
        person.newBuf();
        cout << person;
        break;
      }
      }
    }
    person.write();
  }

  return 0;
}