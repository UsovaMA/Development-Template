#include <clocale>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include "FloorScales.h"
using namespace std;


Nabl::Nabl()
{
  day = 0;
  mon = 0;
  year = 0;
  weight = 0;
}


Nabl::~Nabl()
{
  day = 0;
  mon = 0;
  year = 0;
  weight = 0;
}


Nabl& Nabl::operator=(const Nabl& n)
{
  day = n.day;
  mon = n.mon;
  year = n.year;
  weight = n.weight;
  return *this;
}


ostream& operator<<(ostream& out, const Nabl& n)
{
  out << n.day << "." << n.mon << "." << n.year << " Вес: " << n.weight << endl;
  return out;
}


FloorScales::FloorScales()
{
  name = "";
  bufSize = 100;
  count = 0;
  nabList = new Nabl[bufSize];
}


FloorScales::FloorScales(string _name, int _day, int _mon, int _year)
{
  name = _name;
  count = 1;
  bufSize = 100;
  nabList = new Nabl[bufSize];
  nabList[0].setDay(_day);
  nabList[0].setMon(_mon);
  nabList[0].setYear(_year);
}


void FloorScales::newBuf()
{
  FloorScales tmp;
  tmp = *this;
  this->~FloorScales();
  name = tmp.name;
  count = tmp.count;
  bufSize = 2 * tmp.bufSize;
  nabList = new Nabl[bufSize];
  for (int i = 0; i < count; i++)
  {
    nabList[i] = tmp[i];
  }
}


Nabl FloorScales::startDate()
{
  Nabl tmp;
  tmp.setDay(nabList[0].getDay());
  tmp.setMon(nabList[0].getMon());
  tmp.setYear(nabList[0].getYear());
  tmp.setWeight(nabList[0].getWeight());
  return tmp;
}


void FloorScales::setNabl(int _day, int _mon, int _year, double _weight)
{
  if (count == bufSize)
    throw ExFloorScales(bufOver);
  else
    for (int i = 0; i < count + 1; i++)
    {
      if (nabList[i].getDay() == _day && nabList[i].getMon() == _mon && nabList[i].getYear() == _year)
      {
        nabList[i].setWeight(_weight);
        break;
      }
      if (nabList[i].getDay() == 0)
      {
        nabList[i].setDay(_day);
        nabList[i].setMon(_mon);
        nabList[i].setYear(_year);
        nabList[i].setWeight(_weight);
        count++;
        break;
      }
    }
}


double FloorScales::showWeight(int _day, int _mon, int _year)
{
  for (int i = 0; i < count; i++)
  {
    if (nabList[i].getDay() == _day && nabList[i].getMon() == _mon && nabList[i].getYear() == _year)
    {
      return nabList[i].getWeight();
    }
  }
  throw ExFloorScales(nodate);
}
double FloorScales::averageWeight()
{
  double sum = 0;
  int c = 0;
  double averW = 0;
  for (int i = 0; i < count; i++)
  {
    if (nabList[i].getDay() != 0)
    {
      sum += nabList[i].getWeight();
      c++;
    }
  }
  averW = sum / c;
  if (averW != 0)
    return averW;
  else throw ExFloorScales(nodate);
}
double FloorScales::averageWeightMon(int _mon, int _year)
{
  double sum = 0;
  int c = 0;
  double averW = 0;
  for (int i = 0; i < count; i++)
  {
    if (nabList[i].getMon() == _mon && nabList[i].getYear() == _year)
    {
      sum += nabList[i].getWeight();
      c++;
    }
  }
  averW = sum / c;
  if (averW != 0)
    return averW;
  else throw ExFloorScales(nodate);
}

Nabl FloorScales::maxWeight()
{
  Nabl mw;
  double maxW = 0;
  int im = 0;
  for (int i = 0; i < count; i++)
  {
    if (nabList[i].getDay() != 0)
    {
      if (nabList[i].getWeight() > maxW)
      {
        maxW = nabList[i].getWeight();
        im = i;
      }
    }
  }
  mw.setDay(nabList[im].getDay());
  mw.setMon(nabList[im].getMon());
  mw.setYear(nabList[im].getYear());
  mw.setWeight(maxW);
  return mw;
}

Nabl FloorScales::maxWeightMon(int _mon, int _year)
{
  Nabl mw;
  double maxW = 0;
  int im = 0;
  for (int i = 0; i < count; i++)
  {
    if (nabList[i].getMon() == _mon && nabList[i].getYear() == _year)
    {
      if (nabList[i].getWeight() > maxW)
      {
        maxW = nabList[i].getWeight();
        im = i;
      }
    }
  }
  mw.setDay(nabList[im].getDay());
  mw.setMon(nabList[im].getMon());
  mw.setYear(nabList[im].getYear());
  mw.setWeight(maxW);
  return mw;
}

Nabl FloorScales::minWeight()
{
  Nabl mw;
  double minW = nabList[0].getWeight();
  int im = 0;
  for (int i = 1; i < count; i++)
  {
    if (nabList[i].getDay() != 0)
    {
      if (nabList[i].getWeight() < minW)
      {
        minW = nabList[i].getWeight();
        im = i;
      }
    }
  }
  mw.setDay(nabList[im].getDay());
  mw.setMon(nabList[im].getMon());
  mw.setYear(nabList[im].getYear());
  mw.setWeight(minW);
  return mw;
}

Nabl FloorScales::minWeightMon(int _mon, int _year)
{
  Nabl mw;
  double minW = nabList[0].getWeight();
  int im = 0;
  for (int i = 1; i < count; i++)
  {
    if (nabList[i].getMon() == _mon && nabList[i].getYear() == _year)
    {
      if (nabList[i].getWeight() < minW)
      {
        minW = nabList[i].getWeight();
        im = i;
      }

    }
  }
  mw.setDay(nabList[im].getDay());
  mw.setMon(nabList[im].getMon());
  mw.setYear(nabList[im].getYear());
  mw.setWeight(minW);
  return mw;
}

void FloorScales::read()
{
  ifstream fIn;
  if (fIn)
  {
    fIn.open("file.txt");
    fIn >> *this;
    fIn.close();
  }
  else throw ExFloorScales(nofile);
}


void FloorScales::write()
{
  ofstream fOut;
  if (fOut)
  {
    fOut.open("file.txt");
    fOut << *this;
    fOut.close();
  }
  else throw ExFloorScales(nofile);
}


FloorScales::~FloorScales() {
  name.clear();
  delete[] nabList;
  nabList = 0;
  bufSize = 0;
  count = 0;
}


Nabl& FloorScales::operator[](int ind) {
  if (ind >= 0 && ind < count)
    return nabList[ind];
}


ostream& operator<<(ostream& out, const FloorScales& p)
{
  out << p.name << endl;
  out << p.count << endl;
  for (int i = 0; i < p.count; i++)
  {
    out << p.nabList[i].getDay() << " " << p.nabList[i].getMon() << " " << p.nabList[i].getYear() << "    ";
    out << p.nabList[i].getWeight() << endl;
  }
  return out;
}

istream& operator>>(istream& in, FloorScales& p)
{
  int d, m, y;
  double w;
  string n = "";
  in >> n;
  p.name = n;
  in >> p.count;
  for (int i = 0; i < p.count; i++)
  {
    in >> d >> m >> y >> w;
    p.nabList[i].setDay(d);
    p.nabList[i].setMon(m);
    p.nabList[i].setYear(y);
    p.nabList[i].setWeight(w);
  }
  return in;
}

void PrintMenu()
{
  
    cout << "Выберете действие:" << endl;
    cout << "1. Узнать начальные дату наблюдений." << endl;
    cout << "2. Задать наблюдение." << endl;
    cout << "3. Узнать вес." << endl;
    cout << "4. Средний вес за месяц." << endl;
    cout << "5. Средний вес за всю историю наблюдений." << endl;
    cout << "6. Максимальный вес за месяц." << endl;
    cout << "7. Максимальный вес за всю историю наблюдений." << endl;
    cout << "8. Минимальный вес за месяц." << endl;
    cout << "9. Минимальный вес за всю историю наблюдений " << endl;
    cout << "0. Завершить работу" << endl;
  
}


FloorScales& FloorScales::operator=(const FloorScales& p)
{
  name = p.name;
  bufSize = p.bufSize;
  count = p.count;
  for (int i = 0; i < bufSize; i++)
  {
    nabList[i].setDay(p.nabList[i].getDay());
    nabList[i].setMon(p.nabList[i].getMon());
    nabList[i].setYear(p.nabList[i].getYear());
    nabList[i].setWeight(p.nabList[i].getWeight());
  }
  return *this;
}

