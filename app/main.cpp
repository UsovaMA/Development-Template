#include "add.h"

int main()
{
  setlocale(LC_ALL, "Russian");

  decimal a = "2123";
  decimal b = "123";
  decimal res;
  cout << "������ ����� = " << a << endl;
  cout << "������ ����� = " << b << endl;
  if (a == b) {
    cout << "��� �����." << endl << endl;
  }
  else {
    cout << "��� �� �����" << endl << endl;
  }
  cout << "�� ��������:" << endl;
  res = a + b;
  cout << a << " + " << b << " = ";
  cout << res;

  cout << endl << endl;

  cout << "�� ���������:" << endl;
  res = a - b;
  cout << a << " - " << b << " = ";
  cout << res;

  cout << endl;

  return 0;
}