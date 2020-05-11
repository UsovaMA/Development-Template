#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include "Room.h"
#include "Film_show.h"
#include "..\include\Calendar.h"
using namespace std;

int hou() {
  time_t t;
  struct tm *t_m;
  t = time(NULL);
  t_m = localtime(&t);
  return (t_m->tm_hour);
}
int min() {
  time_t t;
  struct tm *t_m;
  t = time(NULL);
  t_m = localtime(&t);
  return (t_m->tm_min);
}
int day() {
  time_t now = time(0);
  tm *ltm = localtime(&now);
  return (ltm->tm_mday);
}
int mon() {
  time_t now = time(0);
  tm *ltm = localtime(&now);
  return (ltm->tm_mon);
}

void TicketOffice::change_time() {
  day_now = day();
  mon_now = mon();
  hou_now = hou();
  min_now = min();
}

TicketOffice::TicketOffice() {
  day_now = day();
  mon_now = mon()+1;  // For some reason, I got the wrong month (now it’s the 5th, but it showed 4)
  hou_now = hou();
  min_now = min();
  show = 0;
  k_Film_show = 0;
}

TicketOffice::TicketOffice(TicketOffice & fp) {
  day_now = fp.day_now;
  mon_now = fp.mon_now;
  hou_now = fp.hou_now;
  min_now = fp.min_now;
  if (k_Film_show != 0) {
    delete[]show;
  }
  k_Film_show = fp.k_Film_show;
  if (fp.k_Film_show != 0) show = new Film_show[fp.k_Film_show];
  for (int i = 0; i < k_Film_show; i++) {
    show[i] = fp.show[i];
  }
}

void TicketOffice::Plus_FS(Film_show newf) {
  Film_show *a = new Film_show[k_Film_show + 1];
  for (int i = 0; i < k_Film_show; i++) {
    a[i] = show[i];
  }
  a[k_Film_show] = newf;
  if (k_Film_show != 0) {
    delete[]show;
  }
  show = new Film_show[k_Film_show + 1];
  k_Film_show++;
  for (int i = 0; i < k_Film_show; i++) {
    show[i] = a[i];
  }
}

void TicketOffice::buy_tick() {
  int d = 0;
  while (d < day_now) {
    cout << "Input day of film (" << day_now << ", ";
    cout << day_now +1 << ", " << day_now +2 << ") ";
    cin >> d;
    change_time();
    if (d < day_now) cout << "Sorry, it is last date" << endl;
    if (d > day_now +2) cout << "Sorry, you can it by in future" << endl;
  }
  cout << "Input time of start film(ex. 13:09): ";
  string time;
  cin >> time;
  char l[2];
  l[0] = time[0];
  l[1] = time[1];
  int h = 0, s;
  if (l[0] != '0') h = l[0] - '0';
  if (l[1] != ':') { s = l[1] - '0'; h = h * 10 + s; }
  int i, m;
  l[0] = time[3];
  l[1] = time[4];
  m = l[0] - '0';
  s = l[1] - '0'; m = m * 10 + s;
  i = (h-hou_now) * 60+((d-day_now)*24*60);
  i = i + m - min_now + 10;
  if (i < 10) {
    cout << "Sorry... Time is over" << endl;
  } else {
    cout << "Film in this time: " <<endl;
    string a = name_time(time, d);
    if (a == "") {
      cout << "Sorry, in this time no films" << endl;
    } else {
      cout << a << endl;
      cout << "Input number room: ";
      cin >> i;
      i = name_nom(i-1, time, d);
      cout << "You was broned?(yes- 1, no-0) ";
      bool bo;
      cin >> bo;
      if (bo) {
        cout << "You want by(1) or delete(0) bron?";
        cin >> bo;
        if (bo) {
          show[i].pay_br_ticket();
        } else { show[i].del_br_ticket(); }
      } else { show[i].buy_ticket(); }
    }
  }
}

string TicketOffice::name_time(string t, int d) {
  string res = "";
  for (int i = 0; i < k_Film_show; i++) {
    if ((show[i].date == d) && (t == show[i].time))
      res = res + show[i].name_film+ "("+ to_string(show[i].nom_r+1)+ "- number of room), ";
  }
  return(res);
}

int TicketOffice::name_nom(int nk, string t, int d) {
  for (int i = 0; i < k_Film_show; i++) {
    if ((show[i].date == d) && (t == show[i].time)&&(nk== show[i].nom_r)) return i;
  }
  return -1;
}


TicketOffice::~TicketOffice() {
  if (k_Film_show != 0) delete[]show;
}


