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
  ~Time();

  friend std::ostream& operator<<(std::ostream& stream, const Pedometr& s);
  friend std::istream& operator>>(std::istream& stream, Time& s);

  void info();
};

class Pedometr {
private:
  Time* time;

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
  void getInfoEpisode();
  void middleMounth();
  void middleAll();
  void maxStepDay();
  void maxStepAll();

};