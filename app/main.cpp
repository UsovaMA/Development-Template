// Copyright free James-Bolt 2020

#include "Class_Time.hpp"

int main() {
  Time T1;
  Time T2;
  cout << "Enter the first time value" << endl;
  cin >> T1;
  cout << T1;
  cout << "Enter the second time value" << endl;
  cin >> T2;
  cout << T2;
  cout << endl;
  cout << "Amount is equal " << T1 + T2 << endl;
  cout << "Difference is equal " << T1 - T2 << endl;
  system("pause");
}