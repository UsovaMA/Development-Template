#include "Decima.h"
int main() {
  setlocale(LC_CTYPE, "Russian");
  Decima a = "43456";
  Decima b = "111";
  Decima c, f;
  cout << "a =  " ;
  cout << a;
  cout << "b =  ";
  cout << b;
  cout << "������� ������� ���������� ���� � �����, � ����� �����" << endl;
  cin >> f;
  cout << "���� ����� =  ";
  cout << f;
  cout << "a - b= " ;
  c = a - b;
  cout << c;
  cout << "a + b= " ;
  c = a + b;
  cout << c;
  
  if (a == b) {
    cout << " a ����� b";
  }
  else {
    cout << "a �� ����� b";
  }
  getchar();
  getchar();
  return 0;
}