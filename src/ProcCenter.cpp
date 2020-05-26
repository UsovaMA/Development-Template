

#include "ProcCenter.h"



Sup::Sup(string name, string middlename, string lastname, int cardnumber, int balance, int pin, bool bloked, int incorrectpintimes)
{
  string Name, MiddleName, LastName ;
  int Balance, PIN, Incorectpintimes, CardNumber;
  bool Blocked;
  Name = name;
  MiddleName = middlename;
  LastName = lastname;
  CardNumber= cardnumber;
  Balance= balance;
  PIN= pin;
  Blocked= bloked;
  Incorectpintimes= incorrectpintimes;
  SetProcC(Name, MiddleName, LastName, CardNumber, Balance, PIN, Blocked, Incorectpintimes);

}
Sup::Sup()
{
  Name.clear();
  MiddleName.clear();
  LastName.clear();
  NumCard = 0;
  Balance = 0;
  PIN = 0;
  Blocked = 0;
  incorrectPinTimes = 0;

}
void Sup::SetProcC(string name, string middlename, string lastname, int cardnumber, int balance, int pin, bool bloked, int incorrectpintimes)
{
  Name = name;
  MiddleName = middlename;
  LastName = lastname;
  NumCard = cardnumber;
  Balance = balance;
  PIN = pin;
  Blocked = bloked;
  incorrectPinTimes = incorrectpintimes;

}
Sup& Sup::operator=(const Sup& a)
{
  Name = a.Name;

  MiddleName = a.MiddleName;

  LastName = a.LastName;

  NumCard = a.NumCard;
  Balance = a.Balance;
  PIN = a.PIN;
  Blocked = a.Blocked;
  incorrectPinTimes = a.incorrectPinTimes;
  return *this;
}
void ProcCenter::AddPers()
{
  string Name, MiddleName, LastName;
  int Balance;
  int PIN, NumCard;
  int incorrectPinTimes;
  bool block = false;
  Sup* personNew = new Sup[next + 1];
  if (next != 0) {
    for (int i = 0; i < next; ++i) {
      personNew[i] = person[i];
    }
  }
  cout << endl;
  cout << "Имя: ";
  cin >> Name;
  
  cout << endl<<"Фамилия: ";
  cin >> MiddleName;
  
  cout <<endl<<"Отчество: ";
  cin >> LastName;
  do {
    cout << endl << "Номер карты: ";
    cin >> NumCard;
    if (!std::cin) {
      cout << "Введите число." << endl;
      throw logic_error("error");
      std::cin.clear();
      std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    }

  }while(NumCard < 0001 || NumCard >9999);
  cout <<endl<<"Баланс ";
  cin >> Balance;  
  PIN = -1;
  string str;
  do {
    cout << endl << "PIN ";
    cin >> PIN;
    str = to_string(PIN);
    if (!std::cin) {
      cout << "Введите число." << endl;
      throw logic_error("error");
      std::cin.clear();
      std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); 

    }
     } while (PIN < 0001 || PIN > 9999 || str.length() < 4);
  cout << PIN;
  incorrectPinTimes = 0;
  
  personNew[next].SetProcC(Name, MiddleName, LastName, NumCard, Balance, PIN, block, incorrectPinTimes);
  next++;
  person = personNew;
 
}
void ProcCenter::AddPers(Sup a)
{
  string Name, MiddleName, LastName;
  int Balance;
  int PIN, NumCard;
  int incorrectPinTimes;
  bool block;

  Sup* personNew = new Sup[next + 1];
  if (next != 0) {
    for (int i = 0; i < next; ++i) {
      personNew[i] = person[i];
    }
  }
  Name = a.Name;

  MiddleName = a.MiddleName;

  LastName = a.LastName;

  NumCard = a.NumCard;
  Balance = a.Balance;
  PIN = a.PIN;
  block = a.Blocked;
  incorrectPinTimes = a.incorrectPinTimes;

  personNew[next].SetProcC(Name, MiddleName, LastName, NumCard, Balance, PIN, block, incorrectPinTimes);
  next++;
  person = personNew;


}
ProcCenter::ProcCenter(const Sup& d)
{
  person[next].SetProcC(d.Name,d.MiddleName,d.LastName,d.NumCard,d.Balance,d.PIN,d.Blocked,d.incorrectPinTimes);
  next++;

}
