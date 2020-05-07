#include "Credit.h"
#include "ProcCenter.h"

void Credit::poisk(ProcCenter & d) {
  bool t = false;
  for (int i = 0; i < d.pers.size(); i++) {
    if ((d.pers[i].parol == dann.porol) && (d.pers[i].schet == dann.schet)) { 
      nomer = i;
      t = true;
    }
  }
  if (t == false) {
    cout << "�������� ���� ��� ������" << endl;
    cout << "������� 1 ���� ������ ����������� �����" << endl;
    cout << "������� 2 ���� ������ ������������������" << endl;
    int v=-1;
    while (v < 1 || v > 2) {
      cin >> v;
    }
    switch (v) {
    case 1:  Vhod(d);                               break;
    case 2:  d.AddPers(); nomer=d.pers.size()-1;    break;
    }
  }
}
void Credit::podasN(ProcCenter &c) {
  if (c.pers[nomer].kol == 0) {
    cout << "� ��� ��� �������!" << endl;
  }
  else {
    c.pers[nomer].kol = c.pers[nomer].kol - 1;
    c.pers[nomer].money = c.pers[nomer].money - c.pers[nomer].plata_po_kredity;
    cout << "������� ������ �������..." << endl;
    if (c.pers[nomer].kol == 0) {
      c.pers[nomer].kredinf = false;
      c.pers[nomer].vzkredit = 0;
      c.pers[nomer].plata_po_kredity = 0;
    }
  }
  viborC(c);
}
void Credit::podasV(ProcCenter &c) {
  if (c.pers[nomer].kol == 0) {
    cout << "� ��� ��� �������!" << endl;
  }
  else {
    c.pers[nomer].money = (c.pers[nomer].money - (c.pers[nomer].plata_po_kredity * c.pers[nomer].kol));
    c.pers[nomer].kol = 0;
    c.pers[nomer].kredinf = false;
    c.pers[nomer].vzkredit = 0;
    c.pers[nomer].plata_po_kredity = 0;
    cout << "������� ������ �������..." << endl;
  }
  viborC(c);
}

void Credit::Vhod(ProcCenter &c) {
  cout << "������: ";
  cin >> dann.porol;
  cout << "��� ����� �����: ";
  cin >> dann.schet;
  poisk(c);
  viborC(c);
}
void Credit::VZCredit(ProcCenter &c) {
  if (c.pers[nomer].kredinf == false) {
    cout << "� ��� ��� �������" << endl;
    cout << "���:" << endl;
    cout << c.pers[nomer].persName << endl;
    cout << "�������:" << endl;
    cout << c.pers[nomer].persFamil << endl;
    cout << "��������:" << endl;
    cout << c.pers[nomer].persOtchestvo << endl;
    cout << "��� ����:" << endl;
    cout << c.pers[nomer].money << endl;
  }
  else {
    cout << "������ �� �������" << endl;
    cout << "���:" << endl;
    cout << c.pers[nomer].persName << endl;
    cout << "�������:" << endl;
    cout << c.pers[nomer].persFamil << endl;
    cout << "��������:" << endl;
    cout << c.pers[nomer].persOtchestvo << endl;
    cout << "��������:" << endl;
    cout << c.pers[nomer].persOtchestvo << endl;
    cout << "��� ����" << endl;
    cout << c.pers[nomer].money << endl;
    cout << "�� ����� � ������:" << endl;
    cout << c.pers[nomer].vzkredit << endl;
    cout << "����������� �������:" << endl;
    cout << c.pers[nomer].plata_po_kredity << endl;
    cout << "������ ��������:" << endl;
    cout << c.pers[nomer].kol << endl;
  }
  viborC(c);
}
int Credit::proverka(ProcCenter &c,int kredit) {
  int odobrenie=-1;
  if ((kredit*6) < c.pers[nomer].money) {
    odobrenie = 1;
  }
  return odobrenie;
}
int raschetC(int sum,int srok,int proc) {
  double i = (double)proc / 100/12;
  double m = srok * 12;
  double kredit = i/(1-(pow(1 + i, -m)));
  kredit = sum * kredit;
  return (int)kredit;
}
void Credit::polkredit(ProcCenter &c) {
  if (c.pers[nomer].kredinf == true) {
    cout << "� ��� ���� ������!" << endl;
  }
  else {
    int summ;
    int _kredit, v=-1;
    int odob = -1;
    cout << "������� ����� �������,������� �� ������ �����" << endl;
    cin >> summ;
    if (summ < 1 || summ > 3000000) throw std::logic_error("Input error: wrong number!");
    cout << endl;
    cout << "�������� ����" << endl;
    cout << "1 - 1 ���" << endl;
    cout << "2 - 2 ���� " << endl;
    cout << "3 - 3 ����" << endl;
    cout << "4 - 5 ���" << endl;
    cout << "5 - 15 ���" << endl;
    std::cout << "-------------------------------------------------" << std::endl;
    while (v < 1 || v > 5) {
      cin >> v;
    }
    switch (v) {
    case 1: _kredit = malo(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) {
        cout << "������  �������" << endl;
        c.pers[nomer].plata_po_kredity = _kredit;
        c.pers[nomer].vzkredit = summ;
        c.pers[nomer].kol = 12;
        c.pers[nomer].money = c.pers[nomer].money + summ;
        c.pers[nomer].kredinf = true;
      }
      else  cout << "������ ��� �� �������" << endl;
      break;
    case 2: _kredit = sred(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) {
        cout << "������  �������" << endl;
        c.pers[nomer].plata_po_kredity = _kredit;
        c.pers[nomer].vzkredit = summ;
        c.pers[nomer].kol = 24;
        c.pers[nomer].money = c.pers[nomer].money + summ;
        c.pers[nomer].kredinf = true;
      }
      else  cout << "������ ��� �� �������" << endl;
      break;
    case 3: _kredit = mnogo(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) {
        cout << "������  �������" << endl;
        c.pers[nomer].plata_po_kredity = _kredit;
        c.pers[nomer].vzkredit = summ;
        c.pers[nomer].kol = 36;
        c.pers[nomer].money = c.pers[nomer].money + summ;
        c.pers[nomer].kredinf = true;
      }
      else  cout << "������ ��� �� �������" << endl;
      break;
    case 4: _kredit = ogogo(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) {
        cout << "������  �������" << endl;
        c.pers[nomer].plata_po_kredity = _kredit;
        c.pers[nomer].vzkredit = summ;
        c.pers[nomer].kol = 60;
        c.pers[nomer].money = c.pers[nomer].money + summ;
        c.pers[nomer].kredinf = true;
      }
      else  cout << "������ ��� �� �������" << endl;
      break;
    case 5: _kredit = Wow(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) {
        cout << "������  �������" << endl;
        c.pers[nomer].plata_po_kredity = _kredit;
        c.pers[nomer].vzkredit = summ;
        c.pers[nomer].kol = 180;
        c.pers[nomer].money = c.pers[nomer].money + summ;
        c.pers[nomer].kredinf = true;
      }
      else  cout << "������ ��� �� �������" << endl;
      break;
    }
  }
  viborC(c);

}

int Credit::malo(int summ,ProcCenter &c) {
  int  proc;
  int srok=1;
  if (summ < 100000) {
    proc = 16;
  }
  else {
    if (summ >= 100000 && summ < 500000) {
      proc = 15;
    }
    else {
      if (summ >= 500000 && summ < 1000000) {
        proc = 13;
      }
      else {
        if (summ >= 1000000 && summ <= 3000000) {
          proc = 12;
        }
      }
    }
  }
  int kredit;
  kredit = raschetC(summ, srok, proc);
  return kredit;
 /* 1 - �� 100 ���
    2 - �� 100 �� 500 ���
    3 - �� 500 ��� �� 1 ���
    4 - �� 1 ��� �� 3 ���*/
}
int Credit::sred(int summ, ProcCenter &c) {
  int proc;
  int srok = 2;
  if (summ < 100000) {
    proc = 15;
  }
  else {
    if (summ >= 100000 && summ < 500000) {
      proc = 14;
    }
    else {
      if (summ >= 500000 && summ < 1000000) {
        proc = 13;
      }
      else {
        if (summ >= 1000000 && summ <= 3000000) {
          proc = 12;
        }
      }
    }
  }
  int kredit;
  kredit = raschetC(summ, srok, proc);
  return kredit;
}
int Credit::mnogo(int summ, ProcCenter &c) {
  int  proc;
  int srok = 3;
  if (summ < 100000) {
    proc = 15;
  }
  else {
    if (summ >= 100000 && summ < 500000) {
      proc = 13;
    }
    else {
      if (summ >= 500000 && summ < 1000000) {
        proc = 12;
      }
      else {
        if (summ >= 1000000 && summ <= 3000000) {
          proc = 9;
        }
      }
    }
  }
  int kredit;
  kredit = raschetC(summ, srok, proc);
  return kredit;
}
int Credit::ogogo(int summ, ProcCenter &c) {
  int  proc;
  int srok = 5;
  if (summ < 100000) {
    proc = 14;
  }
  else {
    if (summ >= 100000 && summ < 500000) {
      proc = 13;
    }
    else {
      if (summ >= 500000 && summ < 1000000) {
        proc = 12;
      }
      else {
        if (summ >= 1000000 && summ <= 3000000) {
          proc = 9;
        }
      }
    }
  }
  int kredit;
  kredit = raschetC(summ, srok, proc);
  return kredit;
}
int Credit::Wow(int summ, ProcCenter &c) {
  int  proc;
  int srok = 15;
  if (summ < 100000) {
    proc = 13;
  }
  else {
    if (summ >= 100000 && summ < 500000) {
      proc = 12;
    }
    else {
      if (summ >= 500000 && summ < 1000000) {
        proc = 9;
      }
      else {
        if (summ >= 1000000 && summ <=3000000) {
          proc = 8;
        }
      }
    }
  }
  int kredit;
  kredit = raschetC(summ, srok, proc);
  return kredit;
}

void Credit::infCredit(ProcCenter &c) {
  if (c.pers[nomer].kredinf == true) {
    cout << "� ��� ���� ������!" << endl;
  }
  else {
    int summ;
    cout << "������� ����� �������,������� �� ������ �����" << endl;
    cin >> summ;
    if (summ < 1 || summ > 3000000) throw std::logic_error("Input error: wrong number!");
    int v=-1;
    int odob = -1;
    int _kredit;
    cout << endl;
    cout << "�������� ����" << endl;
    cout << "1 - 1 ���" << endl;
    cout << "2 - 2 ���� " << endl;
    cout << "3 - 3 ����" << endl;
    cout << "4 - 5 ���" << endl;
    cout << "5 - 15 ���" << endl;
    std::cout << "-------------------------------------------------" << std::endl;
    while (v < 1 || v > 5) {
      cin >> v;
    }
    switch (v) {
    case 1: _kredit = malo(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) { cout << "������ ��� �� �������" << endl; }
      else  cout << "������ ��� �� �� �������" << endl;
      cout << "������� ��������� ��:  ";
      cout << _kredit;
      cout << "  ������ � �����" << endl; break;
    case 2: _kredit = sred(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) { cout << "������ ��� �� �������" << endl; }
      else  cout << "������ ��� �� �� �������" << endl;
      cout << "������� ��������� ��:  ";
      cout << _kredit;
      cout << "  ������ � �����" << endl; break;
    case 3: _kredit = mnogo(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) { cout << "������ ��� �� �������" << endl; }
      else  cout << "������ ��� �� �� �������" << endl;
      cout << "������� ��������� ��:  ";
      cout << _kredit;
      cout << "  ������ � �����" << endl; break;
    case 4: _kredit = ogogo(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) { cout << "������ ��� �� �������" << endl; }
      else  cout << "������ ��� �� �� �������" << endl;
      cout << "������� ��������� ��:  ";
      cout << _kredit;
      cout << "  ������ � �����" << endl; break;
    case 5: _kredit = Wow(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) { cout << "������ ��� �� �������" << endl; }
      else  cout << "������ ��� �� �� �������" << endl;
      cout << "������� ��������� ��:  ";
      cout << _kredit;
      cout << "  ������ � �����" << endl; break;
    }
  }
  viborC(c);
}
void Credit::infCreditNAL(ProcCenter &c) {
  if (c.pers[nomer].kredinf == false) {
    cout << "� ��� ��� �������" << endl;
  }
  else {
    cout << "� ��� ���� ������" << endl;
  }
  viborC(c);
}
void PrintMenut()
{
  cout << endl;
  cout << "�������� ��������" << endl;
  cout << "1 - ������� ������������" << endl;
  cout << "2 - �������� ���������� � �������" << endl;
  cout << "3 - ��������� ������� �������" << endl;
  cout << "4 - ��������� ����������� ����� ������" << endl;
  cout << "5 - �������� ��������� ������" << endl;
  cout << "6 - �������� ���������� �� �������" << endl;
  cout << "7 - �������� ������" << endl;
  cout << "8 - �����" << endl;
  std::cout << "-------------------------------------------------" << std::endl;
}
void Credit::viborA(ProcCenter &d) {
  cout << "���� � �������" << endl;;
  Vhod(d);   

}
void Credit::viborC (ProcCenter &d) {
  PrintMenut();
  int v=-1;
  while (v < 1 || v > 8) {
    cin >> v;
  }
  switch (v) {
  case 1: Vhod(d);           break;
  case 2: VZCredit(d);       break;
  case 3: infCreditNAL(d);   break;
  case 4: infCredit(d);      break;
  case 5: polkredit(d);      break;
  case 6: podasN(d);         break;
  case 7: podasV(d);         break;
  case 8: exit(0);           break;
  }
}

