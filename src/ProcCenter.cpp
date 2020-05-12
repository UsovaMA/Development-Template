
#include "ProcCenter.h"


vector<ProcCenter> buff;
ProcCenter::ProcCenter(string name, string middleName, string lastName, string cardNumber, int balance, int pin)
{
  string Name, MiddleName, LastName, CardNumber;
  int Balance, PIN;
  Name = name;
  LastName = lastName;
  MiddleName= middleName;
  Balance= balance;
  PIN= pin;
  SetProcC(Name, MiddleName, LastName, CardNumber, Balance, PIN);

}
void ProcCenter::SetProcC(string name, string middleName, string lastName, string cardNumber, int balance, int pin)
{
  Name = name;
  MiddleName = middleName;
  LastName = lastName;
  CardNumber = cardNumber;
  Balance = balance;
  PIN = pin;

}
void ProcCenterVec::AddPerson()
{
  string Name, MiddleName, LastName, CardNumber;
  int Balance;
  int PIN;
  
  cout << endl;
  cout << "Имя: ";
  cin >> Name;
  
  cout << endl<<"Фамилия: ";
  cin >> MiddleName;
  
  cout <<endl<<"Отчество: ";
  cin >> LastName;
  
  cout <<endl<<"NomerCard ";
  cin >> CardNumber;
  cout <<endl<<"Сколько денег на счету: ";
  cin >> Balance;  
  cout <<endl<<"PIN ";
  cin >> PIN;

  ProcCenter bufNabl(Name, MiddleName, LastName, CardNumber, Balance, PIN);
  Vect.push_back(bufNabl);
 
}
ProcCenterVec::ProcCenterVec(const ProcCenter& d)
{
  buff.push_back(d);
  SetnameV(buff);
  Vect.pop_back();
}
