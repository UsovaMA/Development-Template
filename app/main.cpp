#include "add.h"

int main()
{
  setlocale(LC_ALL, "Russian");

  decimal a = "24";
  decimal b = "21";
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
  cout << a << " + " << b << " = ";

  cout << endl << endl;

  cout << "�� ���������:" << endl;
  cout << a << " - " << b << " = ";

  cout << endl;

  return 0;
}