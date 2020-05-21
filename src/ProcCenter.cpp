#include "..\include\ProcCenter.h"
#include "..\include\ProcCenter.h"
#include "..\include\ProcCenter.h"

#include "ProcCenter.h"


vector<Dop> help;
Dop::Dop(string Name_x, string Familia_x, string Ochestvo_x, string NomerCard_x, int summa_x, int PIN_x, bool bloked_x, int _Poca_ne_block)
{
  string Name_y, Familia_y, Ochestvo_y, NomerCard_y;
  int summa_y, PIN_y, _Poca_ne_block_y;
  bool bloked_y;
  Name_y = Name_x;
  Familia_y = Familia_x;
  Ochestvo_y = Ochestvo_x;
  if (NomerCard_x.length() < 4 || NomerCard_x.length() > 4) throw std::logic_error("Input error: wrong number!");
  NomerCard_y= NomerCard_x;
  if (summa_x < 0) throw std::logic_error("Input error: wrong number!");
  summa_y= summa_x;
  PIN_y= PIN_x;
  bloked_y= bloked_x;
  _Poca_ne_block_y= _Poca_ne_block;
  setDop(Name_y, Familia_y, Ochestvo_y, NomerCard_y, summa_y, PIN_y, bloked_y, _Poca_ne_block_y);

}
Dop::Dop()
{
  Name.crend();
  Familia.clear();
  Ochestvo.clear();
  NomerCard.clear();
  summa = 0;
  PIN = 0;
  bloked = 0;
  Poca_ne_block = 0;

}
void Dop::setDop(string Name_x, string Familia_x, string Ochestvo_x, string NomerCard_x, int summa_x, int PIN_x, bool bloked_x, int _Poca_ne_block)
{
  Name = Name_x;
  Familia = Familia_x;
  Ochestvo = Ochestvo_x;
  NomerCard = NomerCard_x;
  summa = summa_x;
  PIN = PIN_x;
  bloked = bloked_x;
  Poca_ne_block = _Poca_ne_block;

}

Dop& Dop::operator=(const Dop& vec)
{
  this->Name = vec.Name;
  this->Familia = vec.Familia;
  this->Ochestvo = vec.Ochestvo;
  this->NomerCard = vec.NomerCard;
  this->PIN = vec.PIN;
  this->summa = vec.summa;
  this->Poca_ne_block = vec.Poca_ne_block;
  this->bloked = vec.Poca_ne_block;
  return *this;
}

void ProcCenter::AddPers()
{
  Dop* new_Chel = new Dop[next + 1];
  if (next != 0) {
    for (int i = 0; i < next; ++i) {
      new_Chel[i] = Chel[i];
    }
  }
  string Namee, Famil, Otchestvo,NomerCard;
  int summa;
  int PIN;
  int Poca_ne_block;
  bool block = false;
  
  cout << endl;
  cout << "Имя: ";
  cin >> Namee;
  
  cout << endl<<"Фамилия: ";
  cin >> Famil;
  
  cout <<endl<<"Отчество: ";
  cin >> Otchestvo;
  
  cout <<endl<<"NomerCard ";
cin >> NomerCard;
  cout <<endl<<"Сколько денег на счету: ";
  cin >> summa;  
  cout <<endl<<"PIN ";
  cin >> PIN;

  Poca_ne_block = 0;
  
  new_Chel[next].setDop(Namee, Famil, Otchestvo, NomerCard, summa, PIN, block, Poca_ne_block);
  next++;

  Chel = new_Chel;
 
}
void ProcCenter::AddPers(Dop a)
{
  Dop* new_Chel = new Dop[next + 1];
  if (next != 0) {
    for (int i = 0; i < next; ++i) {
      new_Chel[i] = Chel[i];
    }
  }
  string Namee, Famil, Otchestvo, NomerCard;
  int summa;
  int PIN;
  int Poca_ne_block;
  bool block;

 
  Namee = a.Name;

  Famil = a.Familia;

  Otchestvo = a.Ochestvo;

  NomerCard = a.NomerCard;
  summa = a.summa;
  PIN = a.PIN;
  block = a.bloked;
  Poca_ne_block = a.Poca_ne_block;

  new_Chel[next].setDop(Namee, Famil, Otchestvo, NomerCard, summa, PIN, block, Poca_ne_block);
  next++;

  Chel = new_Chel;
}
ProcCenter::ProcCenter(const Dop& d)
{
  Chel[next].setDop(d.Name,d.Familia,d.Ochestvo,d.NomerCard,d.summa,d.PIN,d.bloked,d.Poca_ne_block);
  next++;

}
