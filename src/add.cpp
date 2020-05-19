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
}

ProcCenter::ProcCenter(string* _Dano, string _password, int _money, int _het, int _cred) {
  Dano = new string[3];
  for (int i = 0; i < 3; i++) {
    Dano[i] = _Dano[i];
  }
  password = _password;
  money = _money;
  het = _het;
  cred = _cred;
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
}

ProcCenter::~ProcCenter() {
  delete[] Dano;
  password = '\0';
  money = 0;
  het = 0;
  cred = 0;
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
  return *this;
}

Credit::Credit(string* _Dano, string _password, int _money, int _het, int _cred) {
  arr = new ProcCenter[1];
  for (int i = 0; i < 3; i++) {
    arr[0].Dano[i] = _Dano[i];
  }
  arr[0].password = _password;
  arr[0].money = _money;
  arr[0].het = _het;
  arr[0].cred = _cred;
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
  cout << "� ��� ��� ��� �������� ��� ��������-�����. �����������������:" << endl;
  ProcCenter first;
  is = first.getdate();
  (*this).setdate(first);
  first.inpsetdate();

  while (w != 8) {
    do {
      cout << endl << "���� �������� ��������-�����:" << endl;
      cout << "<1> �������� ���������� �� ��������" << endl;
      cout << "<2> ����� ������" << endl;
      cout << "<3> ����� �� ��������" << endl;
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
      }
      else {
        if (r == -1) {
          inf(is);
          if (arr[is].cred == 0) {
            cout << "������: �� �������" << endl;
          }
          else {
            cout << "������: " << arr[is].cred << " RUB.";
          }
        }
        else {
          inf(or);
          if (arr[or].cred == 0) {
            cout << "������: �� �������" << endl;
          }
          else {
            cout << "������: " << arr[or].cred << " RUB.";
          }
        }
      }

    }
    if (w == 2) {
      creditmenu(is, or, r);
    }
    if (w == 3) {
      system("CLS");
      r = exitandpreset();
      if (r == -1) {
        system("CLS");
        is = first.getdate();
        (*this).setdate(first);
        inf(is);
        if (arr[is].cred == 0) {
          cout << "������: �� �������" << endl;
        }
        else {
          cout << "������: " << arr[is].cred << " RUB.";
        }
      }
      else {
        or = r;
        inf(r);
        if (arr[r].cred == 0) {
          cout << "������: �� �������" << endl;
        }
        else {
          cout << "������: " << arr[r].cred << " RUB.";
        }
      }
    }
    if (w == 8) {
      system("pause");
    }
  }
}

void Credit::creditmenu(int is, int or , int r) {
  int non = 0;

  system("CLS");
  if (non == 1) {
    cout << endl << "�� ��� ������ ������." << endl << endl;
  }
  else {
    if (count == 1) {
      do {
        system("CLS");
        if (arr[0].cred < 1000 || arr[0].cred >500000) {
          cout << "��������� ������� �����." << endl;
        }
        cout << "���� ����� �������, ������� �� ������ ��������." << endl;
        cout << "����������� ����� ��������� = 1.000 RUB. ������������ = 500.000 RUB" << endl;
        cout << "���� >> ";
        cin >> arr[0].cred;
      } while (arr[0].cred < 1000 || arr[0].cred >500000);
    }
    else {
      if (r == -1) {
        do {
          system("CLS");
          if (arr[is].cred < 1000 || arr[is].cred >500000) {
            cout << "��������� ������� �����." << endl;
          }
          cout << "���� ����� �������, ������� �� ������ ��������." << endl;
          cout << "����������� ����� ��������� = 1.000 RUB. ������������ = 500.000 RUB" << endl;
          cout << "���� >> ";
          cin >> arr[is].cred;
        } while (arr[is].cred < 1000 || arr[is].cred >500000);
      }
      else {
        do {
          system("CLS");
          if (arr[or ].cred < 1000 || arr[or ].cred >500000) {
            cout << "��������� ������� �����." << endl;
          }
          cout << "���� ����� �������, ������� �� ������ ��������." << endl;
          cout << "����������� ����� ��������� = 1.000 RUB. ������������ = 500.000 RUB" << endl;
          cout << "���� >> ";
          cin >> arr[or ].cred;
        } while (arr[or ].cred < 1000 || arr[or ].cred >500000);
      }
    }
  }
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
  cout << "����� �����: " << arr[r].money << " RUB." << endl;
}

//void Credit::infile() {
//  ofstream in;
//  in.open("Info.txt");
//  for (int i = 0; i < count; i++) {
//    in << "���� ���: " << arr[i].Dano[0] << endl;
//    in << "���� �������: " << arr[i].Dano[1] << endl;
//    in << "���� ��������: " << arr[i].Dano[2] << endl;
//    in << "����� �����: " << arr[i].money << " RUB." << endl;
//  }
//  in.close();
//}
//
//void Credit::outfile() {
//  string str;
//  ifstream out("Info.txt");
//  if (!out.is_open()) {
//    throw logic_error("not find file");
//    cout << "�� ������� ������� ����" << endl;
//  }
//  else {
//    while (!out.eof()) {
//      str = "";
//      getline(out, str);
//      cout << str << endl;
//    }
//  }
//  out.close();
//}

int Credit::exitandpreset() {
  int pre;
  int nomer;
  int index=0;
  int ex;
  int reg = -1;
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
      char p[20];
      cout << "������� ������ �� ������� ������ �����: ";
      cin >> p;
      for (int i = 0; i < count; i++) {
        if (p == arr[i].password && nomer == i+1) {
          index = i;
          system("CLS");
          cout << "�� ������� ����� � �������." << endl << endl;
          return index;
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
    return reg;
  }

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
    cout << "����� �����: " << money << endl;
    if (cred == 0) {
      cout << "������: �� �������" << endl;
    }
    else {
      cout << "������: " << cred << " RUB.";
    }
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