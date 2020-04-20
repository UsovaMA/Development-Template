#ifndef INCLUDE_PEDOMETER_H_
#define INCLUDE_PEDOMETER_H_

#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct myPair
{
public:
  int first;
  int second;
  friend bool operator==(myPair const &c1, myPair const &c2);
};


class Data {
public:
  int time_start;
  int time_finish;
  int date[3];
  int num_of_steps;
  Data();
  Data(string _time_start, string _time_finish, string date,
    int _num_of_steps);
  Data operator=(Data &c);
  Data* Data::operator=(Data* c);
  ~Data();
};

// pointers one love
struct pointerPair {
  int count;
  Data *histr;
};

class Pedometer {
private:
  Data *history;
  int counting;  // count of records
public:
  Pedometer();
  Pedometer(string date, string _time_start, string _time_finish,
    int _num_of_steps);
  bool operator==(Pedometer &c);
  friend bool operator==(Pedometer const &c1, Pedometer const &c2);
  Pedometer operator=(Pedometer &c);
  Pedometer operator=(pointerPair &c);
  void addCounting(string date, string _time_start, string _time_finish,
    int _num_of_steps);  // for devoloper
  void addCounting();  // for menu
  Pedometer getInfo(string date, string _time_start, string _time_finish);
  void getInfo() const;
  myPair findAvarageOrMaxNumOfSteps(string _month_year,bool for_all_history,
    bool MaxOrAvarage) const; // true to max, false to avarage
  void start_menu();
  void writeHistoryToFile();
  void readHistoryFromFile(string filename, bool output);
  ~Pedometer();
};



#endif  // INCLUDE_PEDOMETER_H_
