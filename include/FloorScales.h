#ifndef INCLUDE_Game_H_
#define INCLUDE_Game_H_
#include <iostream>
#include <ctime>
using namespace std;

enum ExceptionType { nodate, bufOver, nofile };
struct ExFloorScales {
  ExceptionType type;
  ExFloorScales(ExceptionType _type) {
    type = _type;
  }
};

class Nabl {
private:
  int day;
  int mon;
  int year;
  double weight;
public:
  Nabl();
  ~Nabl(); 
  void setDay(int _day) { day = _day; }
  void setMon(int _mon) { mon = _mon; }
  void setYear(int _year) { year = _year; }
  void setWeight(double _weight) { weight = _weight; }
  int getDay() { return day; }
  int getMon() { return mon; }
  int getYear() { return year; }
  double getWeight() { return weight; }
  Nabl& operator=(const Nabl& n);
  friend ostream& operator<<(ostream&, const Nabl& n);
};

class FloorScales {
private:
  string name;
  int bufSize; 
  int count; 
  Nabl* nabList;
public:
  FloorScales();
  FloorScales(string _name, int _day, int _mon, int _year); 
  ~FloorScales(); 
  void newBuf(); 
  Nabl startDate(); 
  void setNabl(int _day, int _mon, int _year, double _weight); 
  double showWeight(int _day, int _mon, int _year); 
  double averageWeight(); 
  double averageWeightMon(int _mon, int _year); 
  Nabl maxWeight(); 
  Nabl maxWeightMon(int _mon, int _year);
  Nabl minWeight();
  Nabl minWeightMon(int _mon, int _year);
  void read(); 
  void write(); 
  friend ostream& operator<<(ostream&, const FloorScales& p);
  friend istream& operator>>(istream&, FloorScales& p); 
  FloorScales& operator=(const FloorScales& p);
  Nabl& operator[](int ind); 
};
void PrintMenu();


#endif  // INCLUDE_Game_H_
