#include "add.h"

Date::Date() {
  for (int i = 0; i < 2; i++) {
    h_s[i] = 0;
    h_e[i] = 0;
  }
  for (int i = 0; i < 3; i++) {
    data[i] = 0;
  }
  st = 0;
}

Date::~Date() {
  for (int i = 0; i < 2; i++) {
    h_s[i] = 0;
    h_e[i] = 0;
  }
  for (int i = 0; i < 3; i++) {
    data[i] = 0;
  }
  st = 0;
}

Date Date::operator=(Date &c) {
  for (int i = 0; i < 2; i++) {
    h_s[i] = c.h_s[i];
    h_e[i] = c.h_e[i];
  }
  for (int i = 0; i < 3; i++) {
    data[i] = c.data[i];
  }
  st = c.st;
  return *this;
}

Date::Date(int *_h_s, int *_h_e, int *_data, int _st) {
  for (int i = 0; i < 2; i++) {
    h_s[i] = _h_s[i];
    h_e[i] = _h_e[i];
  }
  for (int i = 0; i < 3; i++) {
    data[i] = _data[i];
  }
  st = _st;
}

Pedometer::Pedometer() {
  count = 0;
  num = new Date[count];
}

Pedometer::~Pedometer() {
  count = 0;
  delete[] num;
}

Pedometer::Pedometer(int *_h_s, int *_h_e, int *_data, int _st) {
  for (int i = 0; i < 2; i++) {
    num[0].h_s[i] = _h_s[i];
    num[0].h_e[i] = _h_e[i];
  }
  for (int i = 0; i < 3; i++) {
    num[0].data[i] = _data[i];
  }
  num[0].st = _st;
}

Pedometer Pedometer::operator=(Pedometer &c) {
  if (count != c.count) {
    //delete[] num;
    num = new Date[count];
  }
  count = c.count;
  for (int i = 0; i < count; i++) {
    num[i] = c.num[i];
  }
  for (int i = 0; i < count; i++) {
    num[i].h_s[i] = c.num[i].h_s[i];
    num[i].h_e[i] = c.num[i].h_e[i];
    num[i].st = c.num[i].st;
    for (int j = 0; j < 3; j++)
      num[i].data[j] = c.num[i].data[j];
  }
  delete[] c.num;
  return *this;
}

void Pedometer::menu() {
  int w = 0;
  setdate(count);
  count++;
  infile(count);
  while (w != 8) {
    do {
      cout << "���� ���������� ����� ���������:" << endl;
      cout << "'1' �������� ������� �����." << endl;
      cout << "'2' ���������� � ����������� ���������." << endl;
      cout << "'3' ����� ������� ����� ����� � ��������� ������ �� ��� ������� ����������." << endl;
      cout << "'4' ����� ������������ ����� ����� � ��������� ������ �� ��� ������� ����������." << endl;
      cout << "'5' ��������� ������� ��������� � ����." << endl;
      cout << "'6' ������� �� ����� ������� ���������." << endl;
      cout << "'7' ������ ���������� � ������ �������� ��������." << endl;
      cout << "'8' ��������� ���������." << endl;
      cout << "�����: ";
      cin >> w;
      if (w < 1 || w>8) {
        cout << endl << "�� ����� ������������ ����� ��������. ���������:" << endl << endl;
      }
    } while (w < 1 || w>8);
    if (w == 1) {
      setdate(count);
      count++;
    }
    if (w == 2) {
      info(count);
    }
    if (w == 3) {
      srmonth(count);
    }
    if (w == 4) {
      maxmonth(count);
    }
    if (w == 5) {
      infile(count);
    }
    if (w == 6) {
      outfile(count);
    }
    if (w == 7) {
      onedate(count);
    }
    if (w == 8) {
      system("pause");
    }
  }
}

void Pedometer::onedate(int count) {

  cout << endl << "��������� ���� ������� ��������: ";
  if (num[0].data[0] < 10) {
    cout << "0" << num[0].data[0];
  }
  else {
    cout << num[0].data[0];
  }
  if (num[0].data[1] < 10) {
    cout << ":" << "0" << num[0].data[1];
  }
  else {
    cout << ":" << num[0].data[1];
  }
  cout << ":" << num[0].data[2] << endl;
  if (num[0].h_s[0] < 10) {
    cout << "����� ������|��������� ��������: " << "0" << num[0].h_s[0];
  }
  else {
    cout << "����� ������|��������� ��������: " << num[0].h_s[0];
  }
  if (num[0].h_s[1] < 10) {
    cout << ":" << "0" << num[0].h_s[1] << " | ";
  }
  else {
    cout << ":" << num[0].h_s[1] << " | ";
  }
  if (num[0].h_e[0] < 10) {
    cout << "0" << num[0].h_e[0] << ":";
  }
  else {
    cout << num[0].h_e[0] << ":";
  }
  if (num[0].h_e[1] < 10) {
    cout << "0" << num[0].h_e[1] << endl;
  }
  else {
    cout << num[0].h_e[1] << endl;
  }
  cout << "����� ������� �� ������ ������: " << num[0].st << endl << endl;
}

void Pedometer::infile(int count) {
  ofstream in;
  in.open("Info.txt");
  for (int i = 0; i < count; i++) {
    if (count == 1) {
      in << "��������� ����: ";
    }
    else {
      in << "����: ";
    }
    if (num[i].data[0] < 10) {
      in << "0" << num[i].data[0];
    }
    else {
      in << num[i].data[0];
    }
    if (num[i].data[1] < 10) {
      in << ":" << "0" << num[i].data[1];
    }
    else {
      in << ":" << num[i].data[1];
    }
    in << ":" << num[i].data[2] << endl;
    if (num[i].h_s[0] < 10) {
      if (count == 1)
        in << "��������� ����� ������|��������� ��������: " << "0" << num[i].h_s[0];
      else in << "����� ������|��������� ��������: " << "0" << num[i].h_s[0];
    }
    else {
      if (count == 1)
        in << "��������� ����� ������|��������� ��������: " << num[i].h_s[0];
      else in << "����� ������|��������� ��������: " << num[i].h_s[0];
    }
    if (num[i].h_s[1] < 10) {
      in << ":" << "0" << num[i].h_s[1] << " | ";
    }
    else {
      in << ":" << num[i].h_s[1] << " | ";
    }
    if (num[i].h_e[0] < 10) {
      in << "0" << num[i].h_e[0] << ":";
    }
    else {
      in << num[i].h_e[0] << ":";
    }
    if (num[i].h_e[1] < 10) {
      in << "0" << num[i].h_e[1] << endl;
    }
    else {
      in << num[i].h_e[1] << endl;
    }
    in << "����� ������� �� ������ ������: " << num[i].st << endl << endl;
  }
  in.close();
}

void Pedometer::outfile(int count) {
  string str;
  ifstream out("Info.txt");
  if (!out.is_open()) {
    cout << "�� ������� ������� ����" << endl;
  }
  else {
    while (!out.eof()) {
      str = "";
      getline(out, str);
      cout << str << endl;
    }
  }
  out.close();
}

int Pedometer::inpmonth(int count) {
  Date mon;
  do {
    cout << "������� �����, �� �������� �������� ������� ���-�� ����� �� ���� ������ ������� ������� ������:" << endl;
    cout << "�����[1-12]: ";
    cin >> mon.data[1];
    if (mon.data[1] < 1 || mon.data[1] > 12) {
      cout << "����� 12 ����������� �������. ������� ����� �� 1 �� 12:" << endl;
    }
  } while (mon.data[1] < 1 || mon.data[1] > 12);
  return mon.data[1];
}

void Pedometer::srmonth(int count) {
  int k = 0;
  int res = 0;
  int f;
  int month = inpmonth(count);
  int *steep = new int;
  for (int i = 0; i < count; i++) {
    if (month == num[i].data[1]) {
      steep[k] = num[i].st;
      k++;
      f = i;
    }
  }
  if (count >= 2) {
    for (int i = 0; i < k; i++) {
      res = res + steep[i];
    }
    if (k > 1) {
      res = res / k;
      cout << "������� ���������� �����: " << res << endl << endl;
    }
    else {
      for (int i = 0; i < count; i++) {
        if (month == num[i].data[1]) {
          cout << "������� ���������� �����: " << num[i].st << endl;
        }
        else {
          if (month != num[i].data[1] && i == count - 1) {
            cout << "�� ������� ��������� � ���� ������." << endl;
          }
        }
      }
    }
  }
  else {
    for (int i = 0; i < count; i++) {
      if (month == num[i].data[1]) {
        cout << "������� ���������� �����: " << num[i].st << endl;
      }
      else {
        if (month != num[i].data[1] && i == count - 1) {
          cout << "�� ������� ��������� � ���� ������." << endl;
        }
      }
    }
  }
}

void Pedometer::maxmonth(int count) {
  int *steep = new int;
  int k = 0;
  int f;
  int month = inpmonth(count);
  if (count >= 2) {
    for (int i = 0; i < count; i++) {
      if (month == num[i].data[1]) {
        steep[k] = num[i].st;
        k++;
        f = i;
      }
    }
    if (k > 1) {
      int max = steep[0];
      for (int i = 1; i < k; i++) {
        if (steep[i] > max) {
          max = steep[i];
        }
      }
      cout << "������������ ���������� �����: " << max << endl;
    }
    else {
      for (int i = 0; i < count; i++) {
        if (month == num[i].data[1]) {
          cout << "������������ ���������� �����: " << num[i].st << endl;
        }
        else {
          if (month != num[i].data[1] && i == count - 1) {
            cout << "�� ������� ��������� � ���� ������." << endl;
          }
        }
      }
    }
  }
  else {
    for (int i = 0; i < count; i++) {
      if (month == num[i].data[1]) {
        cout << "������������ ���������� �����: " << num[i].st << endl;
      }
      else {
        if (month != num[i].data[1] && i == count - 1) {
          cout << "�� ������� ��������� � ���� ������." << endl;
        }
      }
    }
  }
}

int Pedometer::inpinfoday(int count) {
  Date get;
  cout << "������� ����, ����� �������� ���������� � ���������. ����,�����,���:" << endl;
  do {
    cout << "����[1-31]: ";
    cin >> get.data[0];
    if (get.data[0] < 1 || get.data[0] > 31) {
      cout << "����� 31 ����������� ����. ������� ���� �� 1 �� 31:" << endl;
    }
  } while (get.data[0] < 1 || get.data[0] > 31);
  return get.data[0];
}

int Pedometer::inpinfomonth(int count) {
  Date get;
  do {
    cout << "�����[1-12]: ";
    cin >> get.data[1];
    if (get.data[1] < 1 || get.data[1] > 12) {
      cout << "����� 12 ����������� �������. ������� ����� �� 1 �� 12:" << endl;
    }
  } while (get.data[1] < 1 || get.data[1] > 12);
  return get.data[1];
}

int Pedometer::inpinfoyear(int count) {
  Date get;
  do {
    cout << "���[������ YYYY]: ";
    cin >> get.data[2];
    if (get.data[2] < 1000 || get.data[2] > 9999) {
      cout << "��������� ���� ������ �� ������������� � �������� ����� YYYY, ���������:" << endl;
    }
  } while (get.data[2] < 1000 || get.data[2] > 9999);
  return get.data[2];
}

int Pedometer::inpinfoh_s0(int count) {
  Date get;
  cout << "������� �������� ������� ����������. ���, ������ (������ ��������)" << endl;
  do {
    cout << "���[0-23]: ";
    cin >> get.h_s[0];
    if (get.h_s[0] < 0 || get.h_s[0] > 23) {
      cout << "��������� �����(���) �� ������������� ������� �� 0 �� 23, ���������:" << endl;
    }
  } while (get.h_s[0] < 0 || get.h_s[0] > 23);
  return get.h_s[0];
}

int Pedometer::inpinfoh_s1(int count) {
  Date get;
  do {
    cout << "������[0-59]: ";
    cin >> get.h_s[1];
    if (get.h_s[1] < 0 || get.h_s[1] > 59) {
      cout << "��������� �����(������) �� ������������� ������� �� 0 �� 59, ���������:" << endl;
    }
  } while (get.h_s[1] < 0 || get.h_s[1] > 59);
  return get.h_s[1];
}

int Pedometer::inpinfoh_e0(int count) {
  Date get;
  cout << "������� �������� ������� ����������. ���, ������ (��������� ��������)" << endl;
  do {
    cout << "���[0-23]: ";
    cin >> get.h_e[0];
    if (get.h_e[0] < 0 || get.h_e[0] > 23) {
      cout << "��������� �����(���) �� ������������� ������� �� 0 �� 23, ���������:" << endl;
    }
  } while (get.h_e[0] < 0 || get.h_e[0] > 23);
  return get.h_e[0];
}

int Pedometer::inpinfoh_e1(int count) {
  Date get;
  do {
    cout << "������[0-59]: ";
    cin >> get.h_e[1];
    if (get.h_e[1] < 0 || get.h_e[1] > 59) {
      cout << "��������� �����(������) �� ������������� ������� �� 0 �� 59, ���������:" << endl;
    }
  } while (get.h_e[1] < 0 || get.h_e[1] > 59);
  return get.h_e[1];
}

void Pedometer::info(int count) {

  cout << endl;
  int *arr = new int[count];
  int day = inpinfoday(count);
  int month = inpinfomonth(count);
  int year = inpinfoyear(count);
  int hs0 = inpinfoh_s0(count);
  int hs1 = inpinfoh_s1(count);
  int he0 = inpinfoh_e0(count);
  int he1 = inpinfoh_e1(count);
  for (int i = 0, j = 1; i < count; i++) {
    if (day == num[i].data[0] && month == num[i].data[1] && year == num[i].data[2]) {
      if (hs0 <= num[i].h_s[0] && he0 >= num[i].h_e[0] && hs0 <= num[i].h_e[0] && he0 >= num[i].h_s[0] &&
        hs1 <= num[i].h_s[1] && he0 >= num[i].h_e[1] && hs1 <= num[i].h_e[1] && he1 >= num[i].h_s[1]) {
        cout << "������� �" << j << endl;
        if (num[i].h_s[0] < 10) {
          cout << "����� ������|��������� ��������: " << "0" << num[i].h_s[0];
        }
        else {
          cout << "����� ������|��������� ��������: " << num[i].h_s[0];
        }
        if (num[i].h_s[1] < 10) {
          cout << ":" << "0" << num[i].h_s[1] << " | ";
        }
        else {
          cout << ":" << num[i].h_s[1] << " | ";
        }
        if (num[i].h_e[0] < 10) {
          cout << "0" << num[i].h_e[0] << ":";
        }
        else {
          cout << num[i].h_e[0] << ":";
        }
        if (num[i].h_e[1] < 10) {
          cout << "0" << num[i].h_e[1] << endl;
        }
        else {
          cout << num[i].h_e[1] << endl;
        }
        cout << "����� ������� �� ������ ������: " << num[i].st << endl << endl;
      }
      else {
        cout << endl << "��������� �� �������." << endl;
      }
    }
  }
}

void Pedometer::setdate(int count) {
  if (count == 0) {
    cout << "������� ��������� ����. ����,�����,���:" << endl;
  }
  else {
    cout << "������� ����. ����,�����,���:" << endl;
  }
  do {
    cout << "����[1-31]: ";
    cin >> num[count].data[0];
    if (num[count].data[0] < 1 || num[count].data[0] > 31) {
      cout << "����� 31 ����������� ����. ������� ���� �� 1 �� 31:" << endl;
    }
  } while (num[count].data[0] < 1 || num[count].data[0] > 31);
  do {
    cout << "�����[1-12]: ";
    cin >> num[count].data[1];
    if (num[count].data[1] < 1 || num[count].data[1] > 12) {
      cout << "����� 12 ����������� �������. ������� ����� �� 1 �� 12:" << endl;
    }
  } while (num[count].data[1] < 1 || num[count].data[1] > 12);
  do {
    cout << "���[������ YYYY]: ";
    cin >> num[count].data[2];
    if (num[count].data[2] < 1000 || num[count].data[2] > 9999) {
      cout << "��������� ���� ������ �� ������������� � �������� ����� YYYY, ���������:" << endl;
    }
  } while (num[count].data[2] < 1000 || num[count].data[2] > 9999);
  if (count == 0) {
    cout << "������� ��������� ����� ����������. ���, ������ (������ ��������)" << endl;
  }
  else {
    cout << "������� ����� ����������. ���, ������ (������ ��������)" << endl;
  }
  do {
    cout << "���[0-23]: ";
    cin >> num[count].h_s[0];
    if (num[count].h_s[0] < 0 || num[count].h_s[0] > 23) {
      cout << "��������� �����(���) �� ������������� ������� �� 0 �� 23, ���������:" << endl;
    }
  } while (num[count].h_s[0] < 0 || num[count].h_s[0] > 23);
  do {
    cout << "������[0-59]: ";
    cin >> num[count].h_s[1];
    if (num[count].h_s[1] < 0 || num[count].h_s[1] > 59) {
      cout << "��������� �����(������) �� ������������� ������� �� 0 �� 59, ���������:" << endl;
    }
  } while (num[count].h_s[1] < 0 || num[count].h_s[1] > 59);
  if (count == 0) {
    cout << "������� ��������� ����� ����������. ���, ������ (��������� ��������)" << endl;
  }
  else {
    cout << "������� ����� ����������. ���, ������ (��������� ��������)" << endl;
  }
  do {
    cout << "���[0-23]: ";
    cin >> num[count].h_e[0];
    if (num[count].h_e[0] < 0 || num[count].h_e[0] > 23) {
      cout << "��������� �����(���) �� ������������� ������� �� 0 �� 23, ���������:" << endl;
    }
  } while (num[count].h_e[0] < 0 || num[count].h_e[0] > 23);
  do {
    cout << "������[0-59]: ";
    cin >> num[count].h_e[1];
    if (num[count].h_e[1] < 0 || num[count].h_e[1] > 59) {
      cout << "��������� �����(������) �� ������������� ������� �� 0 �� 59, ���������:" << endl;
    }
  } while (num[count].h_e[1] < 0 || num[count].h_e[1] > 59);
  cout << "������� ���������� ���������� ����� �� ��������� ������ �������:" << endl;
  do {
    cin >> num[count].st;
    if (num[count].st < 0) {
      cout << "��������� ���� ���������� ����� �� ����� ���� �������������, ���������:" << endl;
    }
  } while (num[count].st < 0);
  system("CLS");
  inpsetdate(count);
}

void Pedometer::inpsetdate(int count) {
  if (count == 0) {
    cout << "��������� ���� ���������(������) ������:" << endl;
  }
  else {
    cout << "��������� ���� ������:" << endl;
  }
  cout << "����: ";
  if (num[count].data[0] < 10) {
    cout << "0" << num[count].data[0];
  }
  else {
    cout << num[count].data[0];
  }
  if (num[count].data[1] < 10) {
    cout << ":" << "0" << num[count].data[1];
  }
  else {
    cout << ":" << num[count].data[1];
  }
  cout << ":" << num[count].data[2] << endl;
  if (num[count].h_s[0] < 10) {
    cout << "����� ������|��������� ��������: " << "0" << num[count].h_s[0];
  }
  else {
    cout << "����� ������|��������� ��������: " << num[count].h_s[0];
  }
  if (num[count].h_s[1] < 10) {
    cout << ":" << "0" << num[count].h_s[1] << " | ";
  }
  else {
    cout << ":" << num[count].h_s[1] << " | ";
  }
  if (num[count].h_e[0] < 10) {
    cout << "0" << num[count].h_e[0] << ":";
  }
  else {
    cout << num[count].h_e[0] << ":";
  }
  if (num[count].h_e[1] < 10) {
    cout << "0" << num[count].h_e[1] << endl;
  }
  else {
    cout << num[count].h_e[1] << endl;
  }
  cout << "����� ������� �� ������ ������: " << num[count].st << endl << endl;
}