#include"ProcCenter.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>
#include <stdlib.h>

using namespace std;
struct PIN_CARD 
{
  int PIN;
  string NomerCard;
};

class Bancai
{
public:
  friend class ProcCenter;
  friend class Dop;
 
  Bancai() {}
  ~Bancai() {}
  void Chec_PIN(ProcCenter& c);
  void Vzat_Card(ProcCenter& c);
  void Start(ProcCenter& c);
  void Chek(ProcCenter& c);
  void Finde_card(ProcCenter& c);
  void Menu(ProcCenter& c);
  void Schet_Chel(ProcCenter& c);
  void Vzat_dengi(ProcCenter& c);
  void Vidat_denfi(ProcCenter& c);


private:
  
  int Desyat_rub = 80;
  int Patdesat_rub = 80;
  int sto_rub = 80;
  int Patsot_rub = 80;
  int tisha_rub = 80;
  int Pattisach_rub = 80;
  PIN_CARD Card_PIN;
  int nomer;
  int Snat;
  int Vvesti;

};

