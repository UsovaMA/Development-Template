#include "..\include\Cinema.h"

Cinema::Cinema() {
  s_r = 0;
}

Cinema::Cinema(Cinema & fp) {
  cal = fp.cal;
  if (s_r != 0) delete[]r;
  r = new Room[fp.s_r];
  s_r = fp.s_r;
  for (int i = 0; i < fp.s_r; i++) {
    r[i] = fp.r[i];
  }
}

void Cinema::plus_Room(Room ru) {
  Room* ro = new Room[s_r + 1];
  for (int i = 0; i < s_r; i++) {
    ro[i] = r[i];
  }
  ro[s_r] = ru;
  if (s_r != 0) {
    delete[]r;
  }
  r = new Room[s_r + 1];
  s_r++;
  for (int i = 0; i < s_r; i++) {
    r[i] = ro[i];
  }
  delete[]ro;
}

void Cinema::by_b() {
  cal.buy_tick();
}

void Cinema::All_Room() {
  for (int i = 0; i < s_r; i++) {
    cout << "Number of room: " << i + 1 << endl;
    cout << "Row : " << r[i].format.get_k_row_c()+ r[i].format.get_k_row_v() << endl;
    cout << "Place : " << r[i].format.get_k_seats() << endl;
    cout << "Price base vip: " << r[i].price_base_vip() << endl;
    cout << "Price base classical: " << r[i].price_base_cl() << endl;
    cout << "_________________________________________" << endl;
  }
}

void Cinema::All_fs() {
  int s = cal.k_Film_show;
  for (int i = 0; i < s; i++) {
    cal.show[i].info();
    cout << "_________________________________________" << endl;
  }
}

int Cinema::get_s_r() {
  return s_r;
}

int Cinema::get_k_fs() {
  return cal.k_Film_show;
}

Room Cinema::get_Room(int n) {
  if (n < s_r) return r[n];
  return r[0];
}

void Cinema::Plus_FSC(Film_show fs) {
  cal.Plus_FS(fs);
}

Cinema::~Cinema() {
  if (s_r != 0) delete[]r;
}
