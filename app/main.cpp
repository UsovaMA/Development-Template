#include "Decima.h"
int main() {
  setlocale(LC_CTYPE, "Russian");
  Decima a = "33";
  Decima b = "11";
  Decima c, f;
  cout << "a =  " ;
  cout << a;
  cout << "b =  ";
  cout << b;
  cout << "������� ������� ���������� ���� � �����, � ����� �����" << endl;
  
  cout << "���� ����� =  ";
  
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