<<<<<<< Updated upstream
=======
#ifndef INCLUDE_Pedometr_H_
#define INCLUDE_Pedometr_H_

>>>>>>> Stashed changes
#pragma once
#include <fstream>

using namespace std;

class Time {
private:
  int data[3];
  int tSt[2];
  int tFn[2];
  int steps;

public:
  Time();
  Time(int* _data, int* _tSt, int* _tFn, int _steps);
<<<<<<< Updated upstream
  ~Time();

  friend std::ostream& operator<<(std::ostream& stream, const Pedometr& s);
  friend std::istream& operator>>(std::istream& stream, Time& s);

  void info();
=======
  Time(const Time& t);
  ~Time();

  friend class Pedometr;
>>>>>>> Stashed changes
};

class Pedometr {
private:
  Time* time;
<<<<<<< Updated upstream

public:
  Pedometr();
  Pedometr(int* data, int *tSt, int* tFn, int steps);
  ~Pedometr();

  friend std::ostream& operator<<(std::ostream& stream, const Pedometr& s);
  friend std::istream& operator>>(std::istream& stream, Pedometr& s);

  void getStartTime();
  void getStartData();
  void getData();
  void startInfo();
  void addCount();
=======
  int num;

public:
  Pedometr();
  Pedometr(int* _data, int* _tSt, int* _tFn, int _steps);
  Pedometr(const Pedometr& p);
  ~Pedometr();

  void menu();
  void newRecord();
  void read();
  void getStartTime();
>>>>>>> Stashed changes
  void getInfoEpisode();
  void middleMounth();
  void middleAll();
  void maxStepDay();
  void maxStepAll();

<<<<<<< Updated upstream
};
=======
};

#endif  // INCLUDE_Pedometr_H_
>>>>>>> Stashed changes
