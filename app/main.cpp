#include <iostream>
#include <clocale>
#include <fstream>
#include "add.h"
using namespace std;
int main()
{
  setlocale(LC_ALL, "Russian");
  decimal a = "1123";
  decimal b = "2224";
  cout << "������ ����� = " << a << endl;
  cout << "������ ����� = " << b << endl;
  if (a == b) {
    cout << "��� �����." << endl;
  }
  else {
    cout << "��� �� �����" << endl;
  }
  cout << "�� ��������:" << endl;
  cout << a << " + " << b << " = ";

  cout << endl;



  cout << "�� ���������:" << endl;
  cout << a << " - " << b << " = ";

  cout << endl;
  return 0;
}