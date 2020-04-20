#include "Pedometr.h"
#include <iostream>

Time::Time() {
  for (int i = 0; i < 3; i++) {
    data[i] = 0;
  }
  for (int i = 0; i < 2; i++) {
    tSt[i] = 0;
  }
  for (int i = 0; i < 2; i++) {
    tFn[i] = 0;
  }
  steps = 0;
}

Time::Time(int* _data, int* _tSt, int* _tFn, int _steps) {
  for (int i = 0; i < 3; i++) {
    data[i] = _data[i];
  }
  for (int i = 0; i < 2; i++) {
    tSt[i] = _tSt[i];
  }
  for (int i = 0; i < 2; i++) {
    tFn[i] = _tFn[i];
  }
  steps = _steps;
}

Time::~Time() {
  for (int i = 0; i < 3; i++) {
    data[i] = 0;
  }
  for (int i = 0; i < 2; i++) {
    tSt[i] = 0;
  }
  for (int i = 0; i < 2; i++) {
    tFn[i] = 0;
  }
  steps = 0;
}

Pedometr::Pedometr() {
  time = new Time();
}

Pedometr::Pedometr(int* data, int* tSt, int* tFn, int steps) {
  Time time(int* data, int* tSt, int* tFn, int steps);
}

Pedometr::~Pedometr() {
  time-> ~Time();
}

std::ostream& operator<<(std::ostream& stream, const Pedometr& s) {
 // stream << 
}

std::istream& operator>>(std::istream& stream, Time& s) {

  Time* time = new Time();

  cout << "Enter year, mounth, day: ";
  cin >> s.data[0] >> s.data[1] >> s.data[2];
  cout << "Enter hour, minute of start: ";
  cin >> s.tSt[0] >> s.tSt[1];
  cout << "Enter hour, minute of finish: ";
  cin >> s.tFn[0] >> s.tFn[1];
  cout << "Enter count of steps: ";
  cin >> s.steps;

  string path = "expect.txt";

  ofstream fout;
  fout.open(path, ofstream::app);

  if (!fout.is_open()) {
    cout << "Error!" << endl;
  } else {
    cout << "File open.." << endl;
    fout.write((char*)&time, sizeof(Time));
  }

  fout.close();
}
