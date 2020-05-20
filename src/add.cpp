#include "add.h"

ProcCenter::ProcCenter() {
  Dano = new string[3];
  for (int i = 0; i < 3; i++) {
    Dano[i] = '\0';
  }
  password = '\0';
  money = 0;
  het = 0;
  cred = 0;
  srokk = 0;
  viplat = 0;
}

ProcCenter::ProcCenter(string* _Dano, string _password, int _money, int _het, int _cred, int _srokk, int _viplat) {
  Dano = new string[3];
  for (int i = 0; i < 3; i++) {
    Dano[i] = _Dano[i];
  }
  password = _password;
  money = _money;
  het = _het;
  cred = _cred;
  srokk = _srokk;
  viplat = _viplat;
}

ProcCenter::ProcCenter(const ProcCenter& c) {
  Dano = new string[3];
  for (int i = 0; i < 3; i++) {
    Dano[i] = c.Dano[i];
  }
  password = c.password;
  money = c.money;
  het = c.het;
  cred = c.cred;
  srokk = c.srokk;
  viplat = c.viplat;
}

ProcCenter::~ProcCenter() {
  delete[] Dano;
  password = '\0';
  money = 0;
  het = 0;
  cred = 0;
  srokk = 0;
  viplat = 0;
}

Credit::Credit() {
  count = 0;
}

Credit::~Credit() {
  if (count != 0) {
    count = 0;
    delete[] arr;
  }
}

ProcCenter ProcCenter::operator=(ProcCenter& c) {
  for (int i = 0; i < 3; i++) {
    Dano[i] = c.Dano[i];
  }
  money = c.money;
  password = c.password;
  het = c.het;
  cred = c.cred;
  srokk = c.srokk;
  viplat = c.viplat;
  return *this;
}

Credit::Credit(string* _Dano, string _password, int _money, int _het, int _cred, int _srokk, int _viplat) {
  arr = new ProcCenter[1];
  for (int i = 0; i < 3; i++) {
    arr[0].Dano[i] = _Dano[i];
  }
  arr[0].password = _password;
  arr[0].money = _money;
  arr[0].het = _het;
  arr[0].cred = _cred;
  arr[0].srokk = _srokk;
  arr[0].viplat = _viplat;
}

Credit::Credit(const Credit& c) {
  count = c.count;
  arr = new ProcCenter[count];
  for (int j = 0; j < c.count; ++j) {
    for (int i = 0; i < 3; i++) {
      arr[j].Dano[i] = c.arr[j].Dano[i];
    }
    arr[j].money = c.arr[j].money;
    arr[j].password = c.arr[j].password;
    arr[j].het = c.arr[j].het;
    arr[j].srokk = c.arr[j].srokk;
    arr[j].viplat = c.arr[j].viplat;
  }
}

Credit Credit::operator=(Credit& c) {
  if (count != c.count) {
    if (count != 0) delete[] arr;
    arr = new ProcCenter[count];
    count = c.count;
  }

  for (int i = 0; i < count; i++) {
    arr[i] = c.arr[i];
  }
  for (int i = 0; i < count; i++) {
    arr[i].money = c.arr[i].money;
    arr[i].password = c.arr[i].password;
    arr[i].het = c.arr[i].het;
    arr[i].cred = c.arr[i].cred;
    arr[i].srokk = c.arr[i].srokk;
    arr[i].viplat = c.arr[i].viplat;
    for (int j = 0; j < 3; j++)
      arr[i].Dano[j] = c.arr[i].Dano[j];
  }
  return *this;
}

int ProcCenter::getdate() {
  int i;
  do {
    cout << "������� ���� <���>. ������: Ivan. ����� ����� �� 3 �� 15 ��������: " << endl;
    cout << "����: ";
    cin >> Dano[0];
    i = Dano[0].length();
    if (i < 3 || i>15) {
      cout << "����� ����� ����� �� ������� �����������. [3-12 ��������]. ��������� �������" << endl;
    }
  } while (i < 3 || i>15);
  do {
    cout << "������� ���� <�������>. ������: Ivanov. ����� ������� �� 3 �� 20 ��������: " << endl;
    cout << "����: ";
    cin >> Dano[1];
    i = Dano[1].length();
    if (i < 3 || i>20) {
      cout << "����� ������� ����� �� ������� �����������. [3-20 ��������]. ��������� �������" << endl;
    }
  } while (i < 3 || i>20);
  do {
    cout << "������� ���� <��������>. ������: Ivanovich. ����� �������� �� 3 �� 20 ��������: " << endl;
    cout << "����: ";
    cin >> Dano[2];
    i = Dano[2].length();
    if (i < 3 || i>20) {
      cout << "����� �������� ����� �� ������� �����������. [3-20 ��������]. ��������� �������" << endl;
    }
  } while (i < 3 || i>20);
  do {
    cout << "���������� <������>. ������: Ivan123123. ����� ������ �� 6 �� 20 ��������: " << endl;
    cout << "����: ";
    cin >> password;
    i = password.length();
    if (i < 6 || i>20) {
      cout << "����� ������ ����� �� ������� �����������. [6-20 ��������]. ��������� �������" << endl;
    }
  } while (i < 6 || i>20);
  do {
    cout << "������� � ��� �����: " << endl;
    cout << "����: ";
    cin >> money;
    if (money < 0 || money>1000000000) {
      cout << "��� ���� �� ����� ���� ������������� ��� ��������� 1.000.000.000 ������." << endl;
      cout << "��������� ������� �����." << endl;
    }
  } while (money < 0 || money>1000000000);
  system("CLS");
  cout << endl << "�� ������� ����������������." << endl << endl;
  return het++;
}

void Credit::menu() {
  int w = 0;
  int is=0;
  int r=-10;
  int or = 0;
  int vozm = 0;
  int newcr = 0;
  cout << "� ��� ��� ��� �������� ��� ��������-�����. �����������������:" << endl;
  ProcCenter first;
  is = first.getdate();
  (*this).setdate(first);
  first.inpsetdate();
  cout << "����� �����: " << arr[0].money << endl;
  cout << "������: �� �������" << endl << endl;

  while (w != 8) {
    do {
      cout << "���� �������� ��������-�����:" << endl;
      cout << "<1> �������� ���������� �� ��������" << endl;
      cout << "<2> ����� ������" << endl;
      cout << "<3> ����� �� ��������" << endl;
      cout << "<4> ���������� � �������" << endl;
      cout << "<5> ��������� ����������� ����� ������" << endl;
      cout << "<6> �������� ���������� �� �������" << endl;
      cout << "<7> �������� ���� ������ ��������" << endl;
      cout << "<8> �����" << endl;
      cout << "�����: ";
      cin >> w;
      if (w < 1 || w>8) {
        cout << endl << "�� ����� ������������ ����� ��������. ���������:" << endl << endl;
      }
    } while (w < 1 || w>8);
    if (w == 1) {
      cout << endl;
      if (count == 1) {
        first.inpsetdate();
        if (arr[0].viplat == 0) {
          cout << "����� �����: " << arr[0].money << endl;
          cout << "������: �� �������" << endl << endl;
          arr[0].cred = 0;
        }
        else {
          cout << "����� �����: " << arr[0].money + arr[0].cred << endl;
          cout << "������: " << arr[0].cred << " RUB." << endl;
          cout << "��������� ��������: " << arr[0].viplat << " ���(�)." << endl << endl;
        }
      }
      else {
        if (r == -1) {
          inf(is);
          if (arr[is].viplat == 0) {
            arr[is].cred = 0;
            cout << "����� �����: " << arr[is].money << endl;
            cout << "������: �� �������" << endl << endl;
          }
          else {
            cout << "����� �����: " << arr[is].money + arr[is].cred << endl;
            cout << "������: " << arr[is].cred << " RUB." << endl;
            cout << "��������� ��������: " << arr[is].viplat << " ���(�)." << endl << endl;
          }
        }
        else {
          inf(or);
          if (arr[or].viplat == 0) {
            arr[or].cred = 0;
            cout << "����� �����: " << arr[or].money<< endl;
            cout << "������: �� �������" << endl << endl;
          }
          else {
            cout << "����� �����: " << arr[or].money + arr[or].cred << endl;
            cout << "������: " << arr[or].cred << " RUB." << endl;
            cout << "��������� ��������: " << arr[is].viplat << " ���(�)." << endl << endl;
          }
        }
      }

    }
    if (w == 2) {
      getcred(is, or , r);
    }
    if (w == 3) {
      system("CLS");
      r = exitandpreset();
      if (r == -1) {
        system("CLS");
        is = first.getdate();
        (*this).setdate(first);
        inf(is);
        if (arr[is].viplat == 0) {
          arr[is].cred = 0;
          cout << "����� �����: " << arr[is].money<< endl;
          cout << "������: �� �������" << endl << endl;
        }
        else {
          cout << "����� �����: " << arr[is].money + arr[is].cred << endl;
          cout << "������: " << arr[is].cred << " RUB." << endl;
          cout << "��������� ��������: " << arr[is].viplat << " ���(�)." << endl << endl;
        }
      }
      else {
        or = r;
        inf(or);
        if (arr[or].viplat == 0) {
          arr[or].cred = 0;
          cout << "����� �����: " << arr[or].money << endl;
          cout << "������: �� �������" << endl;
        }
        else {
          cout << "����� �����: " << arr[or].money + arr[or].cred << endl;
          cout << "������: " << arr[or].cred << " RUB." << endl;
          cout << "��������� ��������: " << arr[or ].viplat << " ���(�)." << endl << endl;
        }
      }
    }
    if (w == 4) {
      if (count == 1) {
        infoostkred(is, r, or , arr[0].cred);
      }
      else {
        if (r == -1) {
          infoostkred(is, r, or , arr[is].cred);
        }
        else {
          infoostkred(is, r, or , arr[or].cred);
        }
      }
    }
    if (w == 5) {
      fiktcred(is, or , r);
    }
    if (w == 6) {
      odinnachkred(is, or , r);
    }
    if (w == 7) {
      dosrochno(is, or , r);
    }
    if (w == 8) {
      system("pause");
    }
  }
}

void Credit::getcred(int is, int or , int r) {
  if (count == 1) {
    arr[0].cred = arr[0].cred + creditmenu(is, or , r);

  }
  else {
    if (r == -1) {
      arr[is].cred = arr[is].cred + creditmenu(is, or , r);
    }
    else {
      arr[or ].cred = arr[or ].cred + creditmenu(is, or , r);
    }
  }
}

void Credit::dosrochno(int is, int or , int r) {
  int nado = 0;
  int proverka = 0;
  system("CLS");
  if (count == 1) {
    if (arr[0].viplat == 0) {
      cout << endl << "��� �� ����� ����������� ������." << endl << endl;
    }
    else {
      if (arr[0].srokk == 1) nado = one(is, or , r, arr[0].cred);
      if (arr[0].srokk == 2) nado = two(is, or , r, arr[0].cred);
      if (arr[0].srokk == 3) nado = three(is, or , r, arr[0].cred);
      if (arr[0].srokk == 4) nado = four(is, or , r, arr[0].cred);
      if (arr[0].srokk == 5) nado = five(is, or , r, arr[0].cred);
      proverka = arr[0].money - (nado * arr[0].viplat);
      if (proverka < 0) {
        system("CLS");
        cout << endl << "������ �� ����� ���� ������� ��������." << endl << endl;

      }
      else {
        arr[0].money = arr[0].money - (nado * arr[0].viplat);
        cout << endl << "�� �������� ������ ���������" << endl;
        cout << "��������� ������ ���������: " << nado * arr[0].viplat << " RUB." << endl;
        cout << "����� ����� ����� ������: " << arr[0].money + arr[0].cred << endl << endl;
        arr[0].viplat = 0;
      }
    }
  }
  else {
    if (r == -1) {
      if (arr[is].viplat == 0) {
        cout << endl << "��� �� ����� ����������� ������." << endl << endl;
      }
      else {
        if (arr[is].srokk == 1) nado = one(is, or , r, arr[is].cred);
        if (arr[is].srokk == 2) nado = two(is, or , r, arr[is].cred);
        if (arr[is].srokk == 3) nado = three(is, or , r, arr[is].cred);
        if (arr[is].srokk == 4) nado = four(is, or , r, arr[is].cred);
        if (arr[is].srokk == 5) nado = five(is, or , r, arr[is].cred);
        proverka = arr[is].money - (nado * arr[is].viplat);
        if (proverka < 0) {
          system("CLS");
          cout << endl << "������ �� ����� ���� ������� ��������." << endl << endl;
        }
        else {
          arr[is].money = arr[is].money - (nado * arr[is].viplat);
          cout << endl << "�� �������� ������ ���������" << endl;
          cout << "��������� ������ ���������: " << nado * arr[is].viplat << " RUB." << endl;
          cout << "����� ����� ����� ������: " << arr[is].money + arr[is].cred << endl << endl;
          arr[0].viplat = 0;
        }
      }
    }
    else {
      if (arr[or ].viplat == 0) {
        cout << endl << "��� �� ����� ����������� ������." << endl << endl;
      }
      else {
        if (arr[or ].srokk == 1) nado = one(is, or , r, arr[or ].cred);
        if (arr[or ].srokk == 2) nado = two(is, or , r, arr[or ].cred);
        if (arr[or ].srokk == 3) nado = three(is, or , r, arr[or ].cred);
        if (arr[or ].srokk == 4) nado = four(is, or , r, arr[or ].cred);
        if (arr[or ].srokk == 5) nado = five(is, or , r, arr[or ].cred);
        proverka = arr[or ].money - (nado * arr[or ].viplat);
        if (proverka < 0) {
          system("CLS");
          cout << endl << "������ �� ����� ���� ������� ��������." << endl << endl;
        }
        else {
          arr[or ].money = arr[or ].money - (nado * arr[or ].viplat);
          cout << endl << "�� �������� ������ ���������" << endl;
          cout << "��������� ������ ���������: " << nado * arr[or ].viplat << " RUB." << endl;
          cout << "����� ����� ����� ������: " << arr[or ].money + arr[or ].cred << endl << endl;
          arr[0].viplat = 0;
        }
      }
    }
  }
}

void Credit::odinnachkred(int is, int or , int r) {
  int nado = 0;
  system("CLS");
  if (count == 1) {
    if (arr[0].viplat == 0) {
      cout << endl << "��� �� ����� ����������� ������." << endl << endl;
    }
    else {
      if (arr[0].srokk == 1) nado = one(is, or , r, arr[0].cred);
      if (arr[0].srokk == 2) nado = two(is, or , r, arr[0].cred);
      if (arr[0].srokk == 3) nado = three(is, or , r, arr[0].cred);
      if (arr[0].srokk == 4) nado = four(is, or , r, arr[0].cred);
      if (arr[0].srokk == 5) nado = five(is, or , r, arr[0].cred);
      arr[0].viplat = arr[0].viplat - 1;
      arr[0].money = arr[0].money - nado;
      cout << endl << "�� �������� ������ �� ���� �����." << endl;
      cout << "��������� ������ �� 1 ����� ��������: " << nado << " RUB." << endl;
      cout << "����� ����� ����� ������: " << arr[0].money + arr[0].cred << endl;
      cout << "�������� ������: " << arr[0].viplat << " �� ��������� �������." << endl << endl;
    }
  }
  else {
    if (r == -1) {
      if (arr[is].viplat == 0) {
        cout << endl << "��� �� ����� ����������� ������." << endl << endl;
      }
      else {
        if (arr[is].srokk == 1) nado = one(is, or , r, arr[is].cred);
        if (arr[is].srokk == 2) nado = two(is, or , r, arr[is].cred);
        if (arr[is].srokk == 3) nado = three(is, or , r, arr[is].cred);
        if (arr[is].srokk == 4) nado = four(is, or , r, arr[is].cred);
        if (arr[is].srokk == 5) nado = five(is, or , r, arr[is].cred);
        arr[is].viplat = arr[is].viplat - 1;
        arr[is].money = arr[is].money - nado;
        cout << endl << "�� �������� ������ �� ���� �����." << endl;
        cout << "��������� ������ �� 1 ����� ��������: " << nado << " RUB." << endl;
        cout << "����� ����� ����� ������: " << arr[is].money + arr[is].cred << endl;
        cout << "�������� ������: " << arr[is].viplat << " �� ��������� �������." << endl << endl;

      }
    }
    else {
      if (arr[or].viplat == 0) {
        cout << endl << "��� �� ����� ����������� ������." << endl << endl;
      }
      else {
        if (arr[or].srokk == 1) nado = one(is, or , r, arr[or ].cred);
        if (arr[or ].srokk == 2) nado = two(is, or , r, arr[or ].cred);
        if (arr[or ].srokk == 3) nado = three(is, or , r, arr[or ].cred);
        if (arr[or ].srokk == 4) nado = four(is, or , r, arr[or ].cred);
        if (arr[or ].srokk == 5) nado = five(is, or , r, arr[or ].cred);
        arr[or].viplat = arr[or].viplat - 1;
        arr[or].money = arr[or].money - nado;
        cout << endl << "�� �������� ������ �� ���� �����." << endl;
        cout << "��������� ������ �� 1 ����� ��������: " << nado << " RUB." << endl;
        cout << "����� ����� ����� ������: " << arr[or ].money + arr[or ].cred << endl;
        cout << "�������� ������: " << arr[or].viplat << " �� ��������� �������." << endl << endl;
      }
    }
  }
}

void Credit::fiktcred(int is, int or , int r) {
  int non = 0;
  int res = 0;
  int cred1 = 0;
  system("CLS");
  if (count == 1) {
    if (arr[0].viplat != 0) {
      cout << endl << "[�������� ����������� ������ �������]";
      cout << endl << "�� ��� ������ ������." << endl << endl;
    }
    else {
      do {
        system("CLS");
        cout << endl << "[�������� ����������� ������ �������]" << endl;
        cout << "���� ����� �������, ������� �� ������ ��������." << endl;
        cout << "����������� ����� ��������� = 1.000 RUB. ������������ = 3.000.000 RUB" << endl;
        cout << "���� >> ";
        cin >> non;
      } while (non < 1000 || non >3000000);
      cred1 = funstav(is, r, or , non);
      res = ress(cred1, r, or , is);
      if (res == 0) {
        system("CLS");
        cout << endl << "[�������� ����������� ������ �������]";
        cout << endl << "������ �� ����� �������." << endl << endl;
      }
      else {
        system("CLS");
        cout << endl << "[�������� ����������� ������ �������]";
        cout << endl << "������ ����� �������." << endl << endl;
      }
    }
  }
  else {
    if (r == -1) {
      if (arr[is].viplat != 0) {
        cout << endl << "[�������� ����������� ������ �������]";
        cout << endl << "�� ��� ������ ������." << endl << endl;
      }
      else {
        do {
          system("CLS");
          cout << endl << "[�������� ����������� ������ �������]" << endl;
          cout << "���� ����� �������, ������� �� ������ ��������." << endl;
          cout << "����������� ����� ��������� = 1.000 RUB. ������������ = 3.000.000 RUB" << endl;
          cout << "���� >> ";
          cin >> non;
        } while (non < 1000 || non >3000000);
        cred1 = funstav(is, r, or , non);
        res = ress(cred1, r, or , is);
        if (res == 0) {
          system("CLS");
          cout << endl << "[�������� ����������� ������ �������]";
          cout << endl << "������ �� ����� �������." << endl << endl;
        }
        else {
          system("CLS");
          cout << endl << "[�������� ����������� ������ �������]";
          cout << endl << "������ ����� �������." << endl << endl;
        }
      }
    }
    else {
      if (arr[or ].viplat != 0) {
        cout << endl << "[�������� ����������� ������ �������]";
        cout << endl << "�� ��� ������ ������." << endl << endl;
      }
      else {
        do {
          system("CLS");
          cout << endl << "[�������� ����������� ������ �������]" << endl;
          cout << "���� ����� �������, ������� �� ������ ��������." << endl;
          cout << "����������� ����� ��������� = 1.000 RUB. ������������ = 3.000.000 RUB" << endl;
          cout << "���� >> ";
          cin >> non;
        } while (non < 1000 || non >3000000);
        cred1 = funstav(is, r, or , non);
        res = ress(cred1, r, or , is);
        if (res == 0) {
          system("CLS");
          cout << endl << "[�������� ����������� ������ �������]";
          cout << endl << "������ �� ����� �������." << endl << endl;
        }
        else {
          system("CLS");
          cout << endl << "[�������� ����������� ������ �������]";
          cout << endl << "������ ����� �������." << endl << endl;
        }
      }
    }
  }
}

void Credit::infoostkred(int is, int r, int or , int non) {
  int vipl=0;
  if (count == 1) {
    if (arr[0].cred == 0) {
      system("CLS");
      cout << endl << "������ �����������." << endl << endl;
    }
    else {
      system("CLS");
      if (arr[0].srokk == 1) {
        vipl = one(is, or , r, non);
        cout << endl << "� ��� ���� ������ �� �����: " << arr[0].cred << " RUB." << endl;
      }
      else {
        if (arr[0].srokk == 2) {
          vipl = two(is, or , r, non);
          cout << endl << "� ��� ���� ������ �� �����: " << arr[0].cred << " RUB." << endl;
        }
        else {
          if (arr[0].srokk == 3) {
            vipl = three(is, or , r, non);
            cout << endl << "� ��� ���� ������ �� �����: " << arr[0].cred << " RUB." << endl;
          }
          else {
            if (arr[0].srokk == 4) {
              vipl = four(is, or , r, non);
              cout << endl << "� ��� ���� ������ �� �����: " << arr[0].cred << " RUB." << endl;
            }
            else {
              if (arr[0].srokk == 5) {
                vipl = five(is, or , r, non);
                cout << endl << "� ��� ���� ������ �� �����: " << arr[0].cred << " RUB." << endl;
              }
            }
          }
        }
      }
      cout << "������� �� ������� � ����� ��������: " << vipl << " RUB." << endl << endl;
    }
  }
  else {
    if (r == -1) {
      if (arr[is].cred == 0) {
        system("CLS");
        cout << endl << "������ �����������." << endl << endl;
      }
      else {
        system("CLS");
        if (arr[is].srokk == 1) {
          vipl = one(is, or , r, non);
          cout << endl << "� ��� ���� ������ �� �����: " << arr[is].cred << " RUB." << endl;
        }
        else {
          if (arr[is].srokk == 2) {
            vipl = two(is, or , r, non);
            cout << endl << "� ��� ���� ������ �� �����: " << arr[is].cred << " RUB." << endl;
          }
          else {
            if (arr[is].srokk == 3) {
              vipl = three(is, or , r, non);
              cout << endl << "� ��� ���� ������ �� �����: " << arr[is].cred << " RUB." << endl;
            }
            else {
              if (arr[is].srokk == 4) {
                vipl = four(is, or , r, non);
                cout << endl << "� ��� ���� ������ �� �����: " << arr[is].cred << " RUB." << endl;
              }
              else {
                if (arr[is].srokk == 5) {
                  vipl = five(is, or , r, non);
                  cout << endl << "� ��� ���� ������ �� �����: " << arr[is].cred << " RUB." << endl;
                }
              }
            }
          }
        }
        cout << "������� �� ������� � ����� ��������: " << vipl << " RUB." << endl << endl;
      }
    }
    else {
      if (arr[or].cred == 0) {
        system("CLS");
        cout << endl << "������ �����������." << endl << endl;
      }
      else {
        system("CLS");
        if (arr[or].srokk == 1) {
          vipl = one(is, or , r, non);
          cout << endl << "� ��� ���� ������ �� �����: " << arr[or ].cred << " RUB." << endl;
        }
        else {
          if (arr[is].srokk == 2) {
            vipl = two(is, or , r, non);
            cout << endl << "� ��� ���� ������ �� �����: " << arr[or ].cred << " RUB." << endl;
          }
          else {
            if (arr[or ].srokk == 3) {
              vipl = three(is, or , r, non);
              cout << endl << "� ��� ���� ������ �� �����: " << arr[or ].cred << " RUB." << endl;
            }
            else {
              if (arr[or ].srokk == 4) {
                vipl = four(is, or , r, non);
                cout << endl << "� ��� ���� ������ �� �����: " << arr[or ].cred << " RUB." << endl;
              }
              else {
                if (arr[or ].srokk == 5) {
                  vipl = five(is, or , r, non);
                  cout << endl << "� ��� ���� ������ �� �����: " << arr[or ].cred << " RUB." << endl;
                }
              }
            }
          }
        }
        cout << "������� �� ������� � ����� ��������: " << vipl << " RUB." << endl << endl;
      }
    }
  }
}

int Credit::creditmenu(int is, int or , int r) {
  int non = 0;
  int res = 0;
  int cred1=0;
  int end = 0;
  system("CLS");
    if (count == 1) {
      if (arr[0].viplat != 0) {
        cout << endl << "�� ��� ������ ������." << endl << endl;
        end = 0;
        
      }
      else {
        do {
          system("CLS");
          cout << "���� ����� �������, ������� �� ������ ��������." << endl;
          cout << "����������� ����� ��������� = 1.000 RUB. ������������ = 3.000.000 RUB" << endl;
          cout << "���� >> ";
          cin >> non;
        } while (non < 1000 || non >3000000);
        cred1 = funstav(is, r, or , non);
        res = ress(cred1, r, or , is);
        if (res == 0) {
          system("CLS");
          cout << endl << "������ �� �������." << endl << endl;
          end = res;
        }
        else {
          system("CLS");
          cout << endl << "������ �������." << endl << endl;
          end = non;
        }
      }
    }
    else {
      if (r == -1) {
        if (arr[is].viplat != 0) {
          cout << endl << "�� ��� ������ ������." << endl << endl;
          end = 0;
        }
        else {
          do {
            system("CLS");
            cout << "���� ����� �������, ������� �� ������ ��������." << endl;
            cout << "����������� ����� ��������� = 1.000 RUB. ������������ = 3.000.000 RUB" << endl;
            cout << "���� >> ";
            cin >> non;
          } while (non < 1000 || non >3000000);
          cred1 = funstav(is, r, or , non);
          res = ress(cred1, r, or , is);
          if (res == 0) {
            system("CLS");
            cout << endl << "������ �� �������." << endl << endl;
            end = res;
          }
          else {
            system("CLS");
            cout << endl << "������ �������." << endl << endl;
            end = non;
          }
        }
      }
      else {
        if (arr[or ].viplat != 0) {
          cout << endl << "�� ��� ������ ������." << endl << endl;
          end = 0;
        }
        else {
          do {
            system("CLS");
            cout << "���� ����� �������, ������� �� ������ ��������." << endl;
            cout << "����������� ����� ��������� = 1.000 RUB. ������������ = 3.000.000 RUB" << endl;
            cout << "���� >> ";
            cin >> non;
          } while (non < 1000 || non >3000000);
          cred1 = funstav(is, r, or , non);
          res = ress(cred1, r, or , is);
          if (res == 0) {
            system("CLS");
            cout << endl << "������ �� �������." << endl << endl;
            end = res;
          }
          else {
            system("CLS");
            cout << endl << "������ �������." << endl << endl;
            end = non;
          }
        }
      }
    }
    return end;
}

int Credit::ss(int is, int r, int or , int non, int s, int cred1) {
  int res;
  if (s == 1) {
    cred1 = one(is, or , r, non);
  }
  else {
    if (s == 2) {
      cred1 = two(is, or , r, non);
    }
    else {
      if (s == 3) {
        cred1 = three(is, or , r, non);
      }
      else {
        if (s == 4) {
          cred1 = four(is, or , r, non);
        }
        else {
          if (s == 5) {
            cred1 = five(is, or , r, non);
          }
        }
      }
    }
  }
  res = cred1;
  return res;
}

int Credit::funstav(int is,int r, int or, int non) {
  int cred1 = 0;
  int s;
  do {
    cout << endl << "�� ����� ���� �� ������ ����� ������?" << endl;
    cout << "<1> �� 1 ���." << endl;
    cout << "<2> �� 2 ����." << endl;
    cout << "<3> �� 3 ����." << endl;
    cout << "<4> �� 5 ���." << endl;
    cout << "<5> �� 15 ���." << endl;
    cout << "����� �������� <> >> ";
    cin >> s;
    if (s < 1 || s>5) {
      cout << endl << "�� ������� �� ���������� �������. ��������� �������.." << endl;
    }
  } while (s < 1 || s>5);
  cred1 = ss(is, r, or , non, s, cred1);
  vsegoviplat(is, r, or , s);
  return cred1;
}

void Credit::vsegoviplat(int is, int r, int or, int s) {
if (count == 1) {
  arr[0].srokk = s;
  if (s == 1) {
    arr[0].viplat = 12; // �������
  }
  else {
    if (s == 2) {
      arr[0].viplat = 24; // ������
    }
    else {
      if (s == 3) {
        arr[0].viplat = 36; // �������
      }
      else {
        if (s == 4) {
          arr[0].viplat = 60; // �������
        }
        else {
          if (s == 5) {
            arr[0].viplat = 180; // �������
          }
        }
      }
    }
  }
}
else {
  if (r == -1) {
    arr[is].srokk = s;
    if (s == 1) {
      arr[is].viplat = 12; // �������
    }
    else {
      if (s == 2) {
        arr[is].viplat = 24; // ������
      }
      else {
        if (s == 3) {
          arr[is].viplat = 36; // �������
        }
        else {
          if (s == 4) {
            arr[is].viplat = 60; // �������
          }
          else {
            if (s == 5) {
              arr[is].viplat = 180; // �������
            }
          }
        }
      }
    }
  }
  else {
    arr[or ].srokk = s;
    if (s == 1) {
      arr[or ].viplat = 12; // �������
    }
    else {
      if (s == 2) {
        arr[or ].viplat = 24; // ������
      }
      else {
        if (s == 3) {
          arr[or ].viplat = 36; // �������
        }
        else {
          if (s == 4) {
            arr[or ].viplat = 60; // �������
          }
          else {
            if (s == 5) {
              arr[or ].viplat = 180; // �������
            }
          }
        }
      }
    }
  }
}
}

int Credit::ress(int cr, int r, int or, int is) {
  int res = 0;
  if (count == 1) {
    if ((cr * 6) < arr[0].money) {
      res = 1;
    }
  }
  else {
    if (r == -1) {
      if ((cr * 6) < arr[is].money) {
        res = 1;
      }
    }
    else {
      if ((cr * 6) < arr[or].money) {
        res = 1;
      }
    }
  }
  return res;
}

int Credit::one(int is, int or , int r, int non) {
  int stavka=0;
  int var = 1;
  int cred1;
  if (non < 100000) {
    stavka = 20;
  }
  else {
    if (non >= 100000 && non < 500000) {
      stavka = 15;
    }
    else {
      if (non >= 500000 && non < 1000000) {
        stavka = 10;
      }
      else {
        if (non >= 1000000 && non <= 3000000) {
          stavka = 7;
        }
      }
    }
  }
  cred1 = algoritm(stavka, var, non);
  return cred1;
}

int Credit::algoritm(int stavka, int var, int non) {
  double v = var;
  double sta = (double)stavka / 100 / 12;
  double va = v * 12;
  double cr = sta / (1 - (pow(sta+1, -va)));
  cr = non * cr;
  return (int)cr; // ������� � ������ ���� ��� double
}

int Credit::two(int is, int or , int r, int non) {
  int stavka=0;
  int var = 2;
  int cred1;
  if (non < 100000) {
    stavka = 19;
  }
  else {
    if (non >= 100000 && non < 500000) {
      stavka = 14;
    }
    else {
      if (non >= 500000 && non < 1000000) {
        stavka = 9;
      }
      else {
        if (non >= 1000000 && non <= 3000000) {
          stavka = 6;
        }
      }
    }
  }
  cred1 = algoritm(stavka, var, non);
  return cred1;
}

int Credit::three(int is, int or , int r, int non) {
  int stavka=0;
  int var = 3;
  int cred1;
  if (non < 100000) {
    stavka = 12;
  }
  else {
    if (non >= 100000 && non < 500000) {
      stavka = 8;
    }
    else {
      if (non >= 500000 && non < 1000000) {
        stavka = 5;
      }
      else {
        if (non >= 1000000 && non <= 3000000) {
          stavka = 4;
        }
      }
    }
  }
  cred1 = algoritm(stavka, var, non);
  return cred1;
}

int Credit::four(int is, int or , int r, int non) {
  int stavka=0;
  int var = 4;
  int cred1;
  if (non < 100000) {
    stavka = 10;
  }
  else {
    if (non >= 100000 && non < 500000) {
      stavka = 7;
    }
    else {
      if (non >= 500000 && non < 1000000) {
        stavka = 4;
      }
      else {
        if (non >= 1000000 && non <= 3000000) {
          stavka = 3;
        }
      }
    }
  }
  cred1 = algoritm(stavka, var, non);
  return cred1;
}

int Credit::five(int is, int or , int r, int non) {
  int stavka=0;
  int var = 5;
  int cred1;
  if (non < 100000) {
    stavka = 5;
  }
  else {
    if (non >= 100000 && non < 500000) {
      stavka = 4;
    }
    else {
      if (non >= 500000 && non < 1000000) {
        stavka = 3;
      }
      else {
        if (non >= 1000000 && non <= 3000000) {
          stavka = 2;
        }
      }
    }
  }
  cred1 = algoritm(stavka, var, non);
  return cred1;
}

void Credit::inf(int r) {
  system("CLS");
  cout << endl << "������� ���������� �� ��������." << endl;
  if (r + 1 < 10) {
    cout << "����� �����: 000" << r + 1 << endl;
  }
  else {
    if (r + 1 >= 10 && r + 1 < 100) {
      cout << "����� �����: 00" << r + 1 << endl;
    }
    else {
      if (r + 1 >= 100 && r + 1 < 1000) {
        cout << "����� �����: 0" << r + 1 << endl;
      }
      else {
        cout << "����� �����: " << r + 1 << endl << endl;
      }
    }
  }
  cout << "�������: " << arr[r].Dano[1] << endl;
  cout << "���: " << arr[r].Dano[0] << endl;
  cout << "��������: " << arr[r].Dano[2] << endl;
}

int Credit::exitandpreset() {
  int pre=0;
  int nomer=0;
  int index=0;
  int reg = -1;
  int res = 0;
  char p[20];
  ProcCenter get;
  cout << "��� �������� �������� ��������: " << endl;
  do {
    cout << "<1> ����� � ������������ ������� ������." << endl;
    cout << "<2> ���������������� ����� �������." << endl;
    cout << "�����: ";
    cin >> pre;
  } while (pre < 1 || pre>2);
  if (pre == 1) {
    do {
      system("CLS");
      cout << "������� ��� ����� �����:(�������� ���� � ��� ����� ����� 0007, ����: 7 " << endl;
      cout << "����� �����: ";
      cin >> nomer;
      cout << endl;
      if (nomer < 1 || nomer > 9999) {
        cout << "����� ����� �� ����� ���� ������������� � ������ ����������� ��������(9999)" << endl;
        cout << "��������� �������." << endl;
      }
    } while (nomer < 1 || nomer > 9999);
    if (nomer <= count) {
      cout << "������� ������ �� ������� ������ �����: ";
      cin >> p;
      for (int i = 0; i < count; i++) {
        if (p == arr[i].password && nomer == i+1) {
          system("CLS");
          cout << "�� ������� ����� � �������." << endl << endl;
          res = i;
          break;
        }
        else {
          if (p != arr[i].password && i + 1 == count) {
            if (nomer < 10) {
              cout << "�� ����� �������� ������ ��� ����� #000" << nomer << endl;
              cout << "����������� � ���� ��������." << endl << endl;
            }
            else {
              if (nomer >= 10 && nomer < 100) {
                cout << "�� ����� �������� ������ ��� ����� #00" << nomer << endl;
                cout << "����������� � ���� ��������." << endl << endl;
              }
              else {
                if (nomer >= 100 && nomer < 1000) {
                  cout << "�� ����� �������� ������ ��� ����� #0" << nomer << endl;
                  cout << "����������� � ���� ��������." << endl << endl;
                }
                else {
                  cout << "�� ����� �������� ������ ��� ����� #" << nomer << endl;
                  cout << "����������� � ���� ��������." << endl << endl;
                }
              }
            }
            exitandpreset();
          }
        }
      }
    }
    else {
      cout << "����� ����� �� ������." << endl;
      exitandpreset();
    }
  }
  if (pre == 2) {
    res = reg;
  }
  return res;
}

void ProcCenter::inpsetdate() {
  system("CLS");
    cout << endl << "������� ���������� �� ��������." << endl;
    if (het < 10) {
      cout << "����� �����: 000" << het << endl;
    }
    else {
      if (het >= 10 && het < 100) {
        cout << "����� �����: 00" << het << endl;
      }
      else {
        if (het >= 100 && het < 1000) {
          cout << "����� �����: 0" << het << endl;
        }
        else {
          cout << "����� �����: " << het << endl << endl;
        }
      }
    }
    cout << "���: " << Dano[0] << endl;
    cout << "�������: " << Dano[1] << endl;
    cout << "��������: " << Dano[2] << endl;
}

void Credit::setdate(ProcCenter first) {
  Credit copy(*this);
  if (count != 0) {
    delete[] arr;
  }
  arr = new ProcCenter[count + 1];
  count = count + 1;
  for (int i = 0; i < count - 1; ++i) {
    arr[i] = copy.arr[i];
  }
  arr[count - 1] = first;
}