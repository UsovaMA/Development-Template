  // Copyright 2020 <Diana Lukashuk>
#include <iostream>
#include <fstream>
#include <clocale>
#include <time.h>
#include "Film_show.h"
#include "Room.h"
#include "Format_room.h"
#include "Calendar.h"
#include "Cinema.h"
using namespace std;
void menu(int v) {
  if (v == 0) {
    cout << " ________________" << endl << endl;
    cout << "|     Meny:      |" << endl << endl;
    cout << "| 0-Exit         |" << endl << endl;
    cout << "| 1-Cinema       |" << endl << endl;
    cout << "| 2-Ticket Office|" << endl << endl;
    cout << "|________________|" << endl << endl;
  }
  if (v == 1) {
    cout << " ________________________" << endl << endl;
    cout << "|     Meny:              |" << endl << endl;
    cout << "| 0-Exit                 |" << endl << endl;
    cout << "| 1-Add room             |" << endl << endl;
    cout << "| 2-View all rooms       |" << endl << endl;
    cout << "| 3-Add show film        |" << endl << endl;
    cout << "| 4-View all show films  |" << endl << endl;
    cout << "| 5-Next                 |" << endl << endl;
    cout << "|________________________|" << endl << endl;
  }
}
int dday() {
  time_t now = time(0);
  tm *ltm = localtime(&now);
  return (ltm->tm_mday);
}


int main() {
  Cinema ci;
  Format_room fr;
  Room r;
  Film_show fs;
  cout << "Cinema" << endl << endl;
  cout << "You can do cinema(1), or use pattern(0)" << endl;
  bool bv;
  string nf, time;
  int iv, iv1, iv2, ivd;
  cin >> bv;
  if (bv) {
    iv = 1;
    while (iv != 5) {
      menu(1);
      cin >> iv;
      if (iv == 0) return 0;
      if (iv == 1) {
        cin >> r;
        ci.plus_Room(r);
      }
      if (iv == 2) {
        ci.All_Room();
      }
      if (iv == 3) {
        cout << "Enter movie title ";
        cin >> nf;
        cout << "Enter time (ex. 09:09) ";
        cin >> time;
        cout << "Enter num of room ";
        cin >> iv1;
        cout << "Enter day of film ";
        cin >> iv2;
        while (iv1 > ci.get_s_r() + 1) {
          cout << "Error, such number does not exist.Enter num of room ";
          cin >> iv1;
        }
        fs.Upgr(nf, iv2, iv1-1, time, ci.get_Room(iv1-1));
        ci.Plus_FSC(fs);
      }
      if (iv == 4) {
        ci.All_fs();
      }
      if (iv == 5) iv = 5;
    }
  } else {
    fr.UpFormat_room(7, 5, 20);
    r.UpRoom(220, 390, fr);
    ci.plus_Room(r);

    fr.UpFormat_room(5, 3, 10);
    r.UpRoom(200, 300, fr);
    ci.plus_Room(r);

    fr.UpFormat_room(10, 3, 20);
    r.UpRoom(250, 340, fr);
    ci.plus_Room(r);

    int d = dday();
    fs.Upgr("Hunger games", d, 0, "10:00", ci.get_Room(0));
    ci.Plus_FSC(fs);

    fs.Upgr("Hachiko", d + 1, 0, "12:00", ci.get_Room(1));
    ci.Plus_FSC(fs);

    fs.Upgr("Men in Black", d + 2, 0, "18:20", ci.get_Room(2));
    ci.Plus_FSC(fs);

    fs.Upgr("T-34", d, 0, "11:00", ci.get_Room(0));
    ci.Plus_FSC(fs);

    fs.Upgr("Hachiko", d + 1, 0, "10:00", ci.get_Room(1));
    ci.Plus_FSC(fs);

    fs.Upgr("Men in Black", d + 2, 0, "16:00", ci.get_Room(2));
    ci.Plus_FSC(fs);

    fs.Upgr("T-34", d, 0, "20:00", ci.get_Room(0));
    ci.Plus_FSC(fs);

    fs.Upgr("Hunger games", d + 1, 0, "20:00", ci.get_Room(1));
    ci.Plus_FSC(fs);

    fs.Upgr("Men in Black", d + 2, 0, "20:00", ci.get_Room(2));
    ci.Plus_FSC(fs);
  }
  iv = 1;
  while (iv != 0) {
    cout << " ________________" << endl << endl;
    cout << "|     Meny:      |" << endl << endl;
    cout << "| 0-Exit         |" << endl << endl;
    cout << "| 1-Cinema       |" << endl << endl;
    cout << "| 2-Ticket Office|" << endl << endl;
    cout << "|________________|" << endl << endl;
    cin >> iv;
    if (iv == 0) return 0;
    if (iv == 1) {
      //  Cinema
      ivd = iv;
      while (ivd != 5) {
        menu(1);
        cin >> ivd;
        if (ivd == 0) return 0;
        if (ivd == 1) {
          cin >> r;
          ci.plus_Room(r);
        }
        if (ivd == 2) {
          ci.All_Room();
        }
        if (ivd == 3) {
          cout << "Enter movie title ";
          cin >> nf;
          cout << "Enter time (ex. 09:09) ";
          cin >> time;
          cout << "Enter num of room ";
          cin >> iv1;
          cout << "Enter day of film ";
          cin >> iv2;
          while (iv1 > ci.get_s_r() + 1) {
            cout << "Error, such number does not exist.Enter num of room ";
            cin >> iv1;
          }
          fs.Upgr(nf, iv2, iv1 - 1, time, ci.get_Room(iv1 - 1));
          ci.Plus_FSC(fs);
        }
        if (ivd == 4) {
          ci.All_fs();
        }
        if (ivd == 5) ivd = 5;
      }
    } else {
      ci.by_b();
    }
  }
  system("pause");
}
