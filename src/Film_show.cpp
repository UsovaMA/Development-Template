#include "..\include\Film_show.h"
#include "Room.h"

Film_show::Film_show() {
  brv = 0;
  brc = 0;
  name_film = "0";
  nom_r = 0;
  date = 0;
  time = "0";
  Room a;
  zal = a;
  p = 0;
}

Film_show::Film_show(string name_of_film, int date_of_film, int nom_room, string time_of_f, Room ro) {
  name_film = name_of_film;
  nom_r = nom_room;
  date = date_of_film;
  time = time_of_f;
  zal = ro;
  brv = 0;
  brc = 0;

  int sit;
  sit = ro.get_size_room();
  int dop = ro.get_size_room();
  p = new place[dop];
  int rad, mesto;  // get_k_row_v()
  Format_room f_dop = ro.get_format();
  place dop_place(0, 0, 1, 1);
  int idop = 0;
  for (int i = 0; i < f_dop.get_k_row_v(); i++) {
    dop_place.im_row(i);
    for (int j = 0; j < f_dop.get_k_seats(); j++) {
      dop_place.im_pl(j);
      p[idop] = dop_place;
      idop++;
    }
  }

  dop_place.im_vip(0);

  for (int i = f_dop.get_k_row_v(); i < f_dop.get_k_row_c()+ f_dop.get_k_row_v(); i++) {
    dop_place.im_row(i);
    for (int j = 0; j < f_dop.get_k_seats(); j++) {
      dop_place.im_pl(idop);
      p[idop] = dop_place;
      idop++;
    }
  }
}

void Film_show::Upgr(string name_of_film, int date_of_film, int nom_room, string time_of_f, Room ro) {
  name_film = name_of_film;
  nom_r = nom_room;
  date = date_of_film;
  time = time_of_f;
  zal = ro;
  brv = 0;
  brc = 0;

  int sit;
  sit = ro.get_size_room();
  int dop = ro.get_size_room();
  if (p != 0) {
    delete[]p;
  }
  p = new place[dop];
  int rad, mesto;  // get_k_row_v()
  Format_room f_dop = ro.get_format();
  place dop_place(0, 0, 1, 1);
  int idop = 0;
  for (int i = 0; i < f_dop.get_k_row_v(); i++) {
    dop_place.im_row(i);
    for (int j = 0; j < f_dop.get_k_seats(); j++) {
      dop_place.im_pl(j);
      p[idop] = dop_place;
      idop++;
    }
  }

  dop_place.im_vip(0);

  for (int i = f_dop.get_k_row_v(); i < f_dop.get_k_row_c() + f_dop.get_k_row_v(); i++) {
    dop_place.im_row(i);
    for (int j = 0; j < f_dop.get_k_seats(); j++) {
      dop_place.im_pl(idop);
      p[idop] = dop_place;
      idop++;
    }
  }
}

Film_show::Film_show(Film_show & fp) {
  nom_r = fp.nom_r;
  brv = fp.brv;
  brc = fp.brc;
  if (zal.get_size_room() != 0) {
    delete[] p;
  }
  name_film = fp.name_film;
  date = fp.date;
  time = fp.time;
  zal = fp.zal;
  int sit = zal.get_size_room();
  p = new place[sit];
  for (int i = 0; i < sit; i++) {
    p[i] = fp.p[i];
  }
}

Film_show & Film_show::operator=(const Film_show & fp) {
  nom_r = fp.nom_r;
  brv = fp.brv;
  brc = fp.brc;
  if (zal.get_size_room() != 0) {
    delete[] p;
  }
  name_film = fp.name_film;
  date = fp.date;
  time = fp.time;
  zal = fp.zal;
  int sit = zal.get_size_room();
  p = new place[sit];
  for (int i = 0; i < sit; i++) {
    p[i] = fp.p[i];
  }
  return (*this);
}

int Film_show::type_time() {  // 1- morning, 2-day, 3-night
  char a[2];
  a[0] = time[0];
  a[1] = time[1];
  int f = 0, s;
  if ((a[0] == '0') && (a[1] == '0')) return 3;
  if (a[0] != '0') f = a[0] - '0';
  if (a[1] != ':') { s = a[1] - '0'; f= f*10+s; }
  int ty;
  ty = 0;
  if ((f >= 6) && (f < 12)) ty = 1;
  if ((f >= 12) && (f < 18)) ty = 2;
  if ((f >= 18) || (f < 6)) ty = 3;
  return ty;
}

void Film_show::info() {
  cout << "   Name of film: " << name_film << endl;
  cout << "    Hall number: " << nom_r+1 << endl;
  cout << "     Date, time: " << date << ", " << time << endl;
  double prc, prv;
  if (type_time() == 1) {
    prc = zal.price_cl_morning();
    prv = zal.price_vip_morning();
  }
  if (type_time() == 2) {
    prc = zal.price_base_cl();
    prv = zal.price_base_vip();
  }
  if (type_time() == 3) {
    prc = zal.price_cl_night();
    prv = zal.price_vip_night();
  }
  cout << "      Price vip: " << prv << endl;
  cout << "Price classical: " << prc << endl;
}


void Film_show::buy_ticket() {
  int i = 0;
  bool vip;
  info();
  cout << "Vip(1), Classick(0)- ";
  cin >> vip;
  int ty = type_time();
  double pr;
  int k_vo_free;
  if (vip) {
    if (ty = 1) pr = zal.price_vip_morning();
    if (ty = 2) pr = zal.price_base_vip();
    if (ty = 3) pr = zal.price_vip_night();
    k_vo_free = (-1)*brv;
  } else {
    if (ty = 1) pr = zal.price_cl_morning();
    if (ty = 2) pr = zal.price_base_cl();
    if (ty = 3) pr = zal.price_cl_night();
    k_vo_free = (-1)*brc;
  }

  if (vip) {
    while ((p[i].get_free() != 1) && (p[i].get_vip() == 1))
      i++;
  } else {
    while (p[i].get_vip() == 1)
      i++;
    while ((p[i].get_free() == 0) && (zal.get_size_room() - 1 != i)) {
      i++;
    }
  }
  k_vo_free = k_vo_free + zal.get_size_room() - i;
  if (vip == 0) {
    k_vo_free = k_vo_free - zal.format.get_k_row_v()*zal.format.get_k_seats();
  } else {
    k_vo_free = k_vo_free - zal.format.get_k_row_c()*zal.format.get_k_seats();
  }
  if (k_vo_free != 0) {
    cout << k_vo_free << " It number of free places. How many tickets you want? (if no imput 0) ";
    int k_vo;
    cin >> k_vo;
    if (k_vo > k_vo_free) {
      cout << "You cannot buy more " << k_vo_free << " seats." << endl;
    } else {
      cout << k_vo << " place booked" << endl;
      cout << k_vo * pr << " Ru." << endl;
      cout << "You will pay? (0-no (and it broned), 1-yes) " << endl;
      bool a;
      cin >> a;
      if (a) {
        cout << endl << "_______Ticket____________" << endl;
        cout << "   Name of film: " << name_film << endl;
        cout << "     Date, time: " << date << ", " << time << endl;
        cout << "    Hall number: " << nom_r << endl;
        for (int j = 0; j < k_vo; j++) {
          p[i + j].im_free(0);
          cout << "row-" << p[i + j].get_row() + 1;
          cout << ", place-" << p[i + j].get_pl() + 1 << " Paid" << endl;
        }
        cout << "________________________" << endl << endl;
      } else {
        cout << "This plase broned" << endl;
        if (vip) {
          brv = brv + k_vo;
        } else { brc = brc + k_vo; }
      }
    }
  } else { cout << "All sold or broned" << endl; }
}

void Film_show::pay_br_ticket() {
  int i = 0;
  bool vip;
  info();
  int br;
  cout << "Vip(1), Classick(0)- ";
  cin >> vip;
  int ty = type_time();
  double pr;
  int k_vo_free;
  if (vip) {
    if (ty = 1) pr = zal.price_vip_morning();
    if (ty = 2) pr = zal.price_base_vip();
    if (ty = 3) pr = zal.price_vip_night();
    br = brv;
  } else {
    if (ty = 1) pr = zal.price_cl_morning();
    if (ty = 2) pr = zal.price_base_cl();
    if (ty = 3) pr = zal.price_cl_night();
    br = brc;
  }
  if (vip) {
    while ((p[i].get_free() != 1) && (p[i].get_vip() == 1))
      i++;
  } else {
    while (p[i].get_vip() == 1)
      i++;
    while ((p[i].get_free() == 0) && (zal.get_size_room() - 1 != i)) {
      i++;
    }
  }

  k_vo_free = zal.get_size_room() - i;
  if (vip == 0) {
    k_vo_free = k_vo_free - zal.format.get_k_row_v()*zal.format.get_k_seats();
  } else {
    k_vo_free = k_vo_free - zal.format.get_k_row_c()*zal.format.get_k_seats();
}
  if (k_vo_free != 0) {
    cout << br << " It number of broned places. How many tickets you want? (if no imput 0) ";
    int k_vo;
    cin >> k_vo;
    if (k_vo > br) {
      cout << "You cannot buy more " << br << " seats." << endl;
    } else {
      cout << k_vo * pr << " Ru." << endl;
      cout << "You will pay? (0-no (bron saved), 1-yes) " << endl;
      bool a;
      cin >> a;
      if (a) {
        cout << endl << "_______Ticket____________" << endl;
        cout << "   Name of film: " << name_film << endl;
        cout << "     Date, time: " << date << ", " << time << endl;
        cout << "    Hall number: " << nom_r << endl;
        for (int j = 0; j < k_vo; j++) {
          p[i + j].im_free(0);
          cout << "row-" << p[i + j].get_row() + 1;
          cout << ", place-" << p[i + j].get_pl() + 1 << " Paid" << endl;
        }
        cout << "________________________" << endl << endl;
        br = br - k_vo;
      }
    }
  } else { cout << "All sold or broned" << endl; }
  if (vip) {
    brv = br;
  } else {
    brc = br;
  }
}

void Film_show::del_br_ticket() {
  bool vip;
  int br;
  cout << "Vip(1), Classick(0)- ";
  cin >> vip;
  if (vip) {
    br = brv;
  } else {
    br = brc;
  }
  cout << br <<" place is bron" <<endl;
  cout << "How much cancel bron? ";
  int a;
  cin >> a;
  if (br >= a) { br = br - a; cout << "Bron deleted" << endl;
  } else {
    cout << "Place not cancel" << endl;
  }
  if (vip) {
    brv = br;
  } else {
    brc = br;
  }
}


Film_show::~Film_show() {
  delete[]p;
  name_film = "0";
  date = 0;
  time = "0";
  Room a;
  zal = a;
  p = 0;
}

