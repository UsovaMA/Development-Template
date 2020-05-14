#include "add.h"

ProcCenter::ProcCenter() {
  Dano = new string[3];
  for (int i = 0; i < 3; i++) {
    Dano[i] = '\0';
  }
  password = '\0';
  money = 0;
  het = 0;
}

ProcCenter::ProcCenter(string* _Dano, string _password, int _money, int _het) {
  Dano = new string[3];
  for (int i = 0; i < 3; i++) {
    Dano[i] = _Dano[i];
  }
  password = _password;
  money = _money;
  het = _het;
}

ProcCenter::ProcCenter(const ProcCenter& c) {
  Dano = new string[3];
  for (int i = 0; i < 3; i++) {
    Dano[i] = c.Dano[i];
  }
  password = c.password;
  money = c.money;
  het = c.het;
}

ProcCenter::~ProcCenter() {
  delete[] Dano;
  password = '\0';
  money = 0;
  het = 0;
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
  return *this;
}

Credit::Credit(string* _Dano, string _password, int _money, int _het) {
  arr = new ProcCenter[1];
  for (int i = 0; i < 3; i++) {
    arr[0].Dano[i] = _Dano[i];
  }
  arr[0].password = _password;
  arr[0].money = _money;
  arr[0].het = _het;
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
    for (int j = 0; j < 3; j++)
      arr[i].Dano[j] = c.arr[i].Dano[j];
  }
  return *this;
}

void ProcCenter::getdate() {
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
  het++;
}

void Credit::menu() {
  int w = 0;
  cout << "� ��� ��� ��� �������� ��� ��������-�����. �����������������:" << endl;
  ProcCenter first_data;
  first_data.getdate();
  (*this).setdate(first_data);
  first_data.infile();

  while (w != 8) {
    do {
      cout << endl << "���� �������� ��������-�����:" << endl;
      cout << "<1> �������� ���������� �� ��������" << endl;
      cout << "<2> ����� �� ��������" << endl;
      cout << ".....��� ����� ��� ����� ��������......" << endl;
      cout << "<8> �����" << endl;
      cout << "�����: ";
      cin >> w;
      if (w < 1 || w>8) {
        cout << endl << "�� ����� ������������ ����� ��������. ���������:" << endl << endl;
      }
    } while (w < 1 || w>8);
    if (w == 1) {
      cout << endl;
      first_data.outfile();
    }
    if (w == 2) {
      system("CLS");
      exitandpreset();
    }
    if (w == 8) {
      system("pause");
    }
  }
}

void ProcCenter::infile() {
  ofstream in;
  in.open("Info.txt");
    in << "���� ���: "<< Dano[0] << endl;
    in << "���� �������: "<< Dano[1] << endl;
    in << "���� ��������: "<< Dano[2] << endl;
    in << "����� �����: "<< money << " RUB."<< endl;
  in.close();
}

void ProcCenter::outfile() {
  string str;
  ifstream out("Info.txt");
  if (!out.is_open()) {
    throw logic_error("not find file");
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

void Credit::exitandpreset() {
  int pre;
  int nomer;
  int index;
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
        if (p == arr[i].password) {
          index = i;
          system("CLS");
          cout << "�� ������� ����� � �������." << endl << endl;

        }
        else {
          if (p != arr[i].password && i + 1 <= count) {
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
          }
          exitandpreset();
        }
      }
    }
    else {
      cout << "����� ����� �� ������." << endl;
      exitandpreset();
    }
  }
  if (pre == 2) {
    system("CLS");
    get.getdate();
    get.infile();
  }
}

void ProcCenter::inpsetdate() {
  system("CLS");
  for (int i = 0; i < het; i++) {
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
  }
}

void Credit::setdate(ProcCenter new_data) {
  Credit copy(*this);
  if (count != 0) {
    delete[] arr;
  }
  arr = new ProcCenter[count + 1];
  count = count + 1;
  for (int i = 0; i < count - 1; ++i) {
    arr[i] = copy.arr[i];
  }
  arr[count - 1] = new_data;
}