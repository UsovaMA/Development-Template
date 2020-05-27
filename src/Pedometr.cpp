#include "Pedometr.h"
#include <iostream>
<<<<<<< Updated upstream
=======
#include <fstream>
#include <cstring>
#include <string>
#include <conio.h>
#include <sstream>        
#include <windows.h>
#include <stdlib.h>

using namespace std;
>>>>>>> Stashed changes

Time::Time() {
  for (int i = 0; i < 3; i++) {
    data[i] = 0;
  }
  for (int i = 0; i < 2; i++) {
    tSt[i] = 0;
<<<<<<< Updated upstream
  }
  for (int i = 0; i < 2; i++) {
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
  }
  for (int i = 0; i < 2; i++) {
=======
>>>>>>> Stashed changes
    tFn[i] = _tFn[i];
  }
  steps = _steps;
}

<<<<<<< Updated upstream
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
=======
Time::Time(const Time& t) {
  for (int i = 0; i < 3; i++) {
    data[i] = t.data[i];
  }
  for (int i = 0; i < 2; i++) {
    tSt[i] = t.tSt[i];
    tFn[i] = t.tFn[i];
  }
  steps = t.steps;
}

Time::~Time() {
  /*delete[] data;
  delete[] tSt;
  delete[] tFn;
  steps = 0;*/
>>>>>>> Stashed changes
}

Pedometr::Pedometr() {
  time = new Time();
<<<<<<< Updated upstream
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
=======
  num = 0;
}

Pedometr::Pedometr(int* _data, int* _tSt, int* _tFn, int _steps) {
  time = new Time[1];
  for (int i = 0; i < 3; i++) {
    time[0].data[i] = _data[i];
  }
  for (int i = 0; i < 2; i++) {
    time[0].tSt[i] = _tSt[i];
    time[0].tFn[i] = _tFn[i];
  }
  time[0].steps = _steps;
}

Pedometr::Pedometr(const Pedometr& p) {
  num = p.num;
  time = new Time[num];
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < 3; j++) {
      time[i].data[j] = p.time[i].data[j];
    }
    for (int j = 0; j < 2; j++) {
      time[i].tSt[j] = p.time[i].tSt[j];
      time[i].tFn[j] = p.time[i].tFn[j];
    }
    time[i].steps = p.time[i].steps;
  }
}

Pedometr::~Pedometr() {
  num = NULL;
}

void Pedometr::menu() {

  int answer = 0;

  cout << "Choose the act: " << endl;
  cout << "1) New Record" << endl;
  cout << "2) Get start data and time" << endl;
  cout << "3) Get info your choose" << endl;
  cout << "4) Find a middle count steps" << endl;
  cout << "5) Find max count steps in the mounth your choose" << endl;
  cout << "6) Find max count at the all time" << endl;
  cout << "7) Show all records" << endl;
  cin >> answer;
  while (abs(answer) > 8) {
    cout << "Enter norm chislo";
    cin >> answer;
  }

  switch (answer) {
  case 1:
    newRecord();
    num++;
    break;
  case 2:
    getStartTime();
    break;
  case 3:
    getInfoEpisode();
    break;
  case 4:
    int k;
    cout << "1 - middle at the mounth" << endl;
    cout << "2 - middle at the all time" << endl;
    cin >> k;
    if (k == 1) middleMounth();
    else middleAll();
    break;
  case 5:
    maxStepDay();
    break;
  case 6:
    maxStepAll();
    break;
  case 7:
    read();
    break;
  default:
    break;
  }

}


void Pedometr::newRecord() {

  int data[3];
  int tSt[2];
  int tFn[2];
  int steps;

  cout << "Enter year, mounth, day: ";
  cin >> data[0] >> data[1] >> data[2];
  cout << "Enter hour, minute of start: ";
  cin >> tSt[0] >> tSt[1];
  cout << "Enter hour, minute of finish: ";
  cin >> tFn[0] >> tFn[1];
  cout << "Enter count of steps: ";
  cin >> steps;

  Pedometr time(data, tSt, tFn, steps);
>>>>>>> Stashed changes

  string path = "expect.txt";

  ofstream fout;
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
  fout.open(path, ofstream::app);

  if (!fout.is_open()) {
    cout << "Error!" << endl;
<<<<<<< Updated upstream
  } else {
    cout << "File open.." << endl;
    fout.write((char*)&time, sizeof(Time));
=======
  }
  else {
    cout << "Success!" << endl;
    fout << data[0] << "." << data[1] << "." << data[2] << " " << tSt[0] << ":" << tSt[1] << " " << tFn[0] << ":" << tFn[1] << " " << steps << "\n";
>>>>>>> Stashed changes
  }

  fout.close();
}
<<<<<<< Updated upstream
=======

void Pedometr::read() {

  string path = "expect.txt";
  string str;
  int i = 0;

  ifstream fin;
  fin.open(path);

  if (!fin.is_open()) {
    cout << "Error!" << endl;
  }
  else {
    while (!fin.eof()) {
      i++;
      str = "";
      getline(fin, str);
      cout << i << "record: " << str << endl;
    }
  }
  fin.close();
}

void Pedometr::getStartTime() {

  string path = "expect.txt";
  string str;

  ifstream fin;
  fin.open(path);

  if (!fin.is_open()) {
    cout << "Error!" << endl;
  }
  else {
    cout << "First record: ";
    str = "";
    getline(fin, str);
    cout << str << endl;
  }
  fin.close();
}

void Pedometr::getInfoEpisode() {

  int data[3];
  int tSt[2];
  int tFn[2];
  int steps;
  string str;
  string dat0;
  string dat1;
  string dat2;
  string dat;
  string tS;
  string tF;
  string step;

  string st;

  cout << "Enter year, mounth, day: ";
  cin >> data[0] >> data[1] >> data[2];

  std::stringstream ss;
  ss << data[0];
  ss >> dat0;
  ss.clear();
  ss << data[1];
  ss >> dat1;
  ss.clear();
  ss << data[2];
  ss >> dat2;
  ss.clear();

  str = dat0 + "." + dat1 + "." + dat2;

  string path = "expect.txt";
  int i = 0;

  ifstream fin;
  fin.open(path);

  if (!fin.is_open()) {
    cout << "Error!" << endl;
  }
  else {
    while (getline(fin, st)) {
      istringstream iss(st);
      iss >> dat >> tS >> tF >> step;
      if (dat == str) {
        cout << tS << " " << tF << " " << step << endl;
      }
    }
  }
  fin.close();
}


void Pedometr::middleMounth() {

  int data[3];
  int tSt[2];
  int tFn[2];
  int steps;
  string str;
  string dat0;
  string dat1;
  string dat2;
  string dat;
  string tS;
  string tF;
  string step;

  string st;

  cout << "Enter mounth: ";
  cin >> data[1];

  std::stringstream ss;
  ss << data[1];
  ss >> dat1;
  ss.clear();

  str = "." + dat1 + ".";

  string path = "expect.txt";
  int k = 0;
  int n = 0;
  int res = 0;

  ifstream fin;
  fin.open(path);

  if (!fin.is_open()) {
    cout << "Error!" << endl;
  }
  else {
    while (getline(fin, st)) {
      istringstream iss(st);
      iss >> dat >> tS >> tF >> step;
      n = 0;
      size_t pos = dat.find(str);
      if (pos != string::npos) {
        k++;
        steps = atoi(step.c_str());
        res += steps;
      }
    }
  }
  cout << "Your middle count of steps in " << dat1 << " mounth ";

  if (k > 0 && res > 0) {
    int answer = res / k;
    cout << answer;
  }
  else cout << 0;
  fin.close();
}

void Pedometr::middleAll() {

  int steps;
  string str;
  string dat;
  string tS;
  string tF;
  string step;

  string st;

  string path = "expect.txt";
  int k = 0;
  int n = 0;
  int res = 0;

  ifstream fin;
  fin.open(path);

  if (!fin.is_open()) {
    cout << "Error!" << endl;
  }
  else {
    while (getline(fin, st)) {
      istringstream iss(st);
      iss >> dat >> tS >> tF >> step;
      steps = atoi(step.c_str());
      res += steps;
      k++;
    }
  }
  cout << "Your middle count of steps in the all time ";

  if (k > 0 && res > 0) {
    int answer = res / k;
    cout << answer;
  }
  else cout << 0;
  fin.close();
}

void Pedometr::maxStepDay() {

  int data[3];
  int tSt[2];
  int tFn[2];
  int steps;
  string str;
  string dat0;
  string dat1;
  string dat2;
  string dat;
  string tS;
  string tF;
  string step;

  string st;

  cout << "Enter mounth: ";
  cin >> data[1];

  std::stringstream ss;
  ss << data[1];
  ss >> dat1;
  ss.clear();

  str = "." + dat1 + ".";

  string path = "expect.txt";
  int n = 0;
  int res = 0;

  ifstream fin;
  fin.open(path);

  if (!fin.is_open()) {
    cout << "Error!" << endl;
  }
  else {
    while (getline(fin, st)) {
      istringstream iss(st);
      iss >> dat >> tS >> tF >> step;
      n = 0;
      size_t pos = dat.find(str);
      if (pos != string::npos) {
        steps = atoi(step.c_str());
        if (res < steps) {
          res = steps;
        }
      }
    }
  }
  cout << "Your max count of steps in " << dat1 << " mounth ";

  if (res > 0) {
    cout << res;
  }
  else cout << 0;
  fin.close();
}

void Pedometr::maxStepAll() {
  int data[3];
  int tSt[2];
  int tFn[2];
  int steps;
  string str;
  string dat0;
  string dat1;
  string dat2;
  string dat;
  string tS;
  string tF;
  string step;

  string st;

  string path = "expect.txt";
  int n = 0;
  int res = 0;

  ifstream fin;
  fin.open(path);

  if (!fin.is_open()) {
    cout << "Error!" << endl;
  }
  else {
    while (getline(fin, st)) {
      istringstream iss(st);
      iss >> dat >> tS >> tF >> step;
      steps = atoi(step.c_str());
      if (res < steps) {
        res = steps;
      }
    }
  }
  cout << "Your max count of steps in the all time: ";

  if (res > 0) {
    cout << res;
  }
  else cout << 0;
  fin.close();
}
>>>>>>> Stashed changes
