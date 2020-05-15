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
  int Check_sum(ProcCenter& c);
  void Finde_card(ProcCenter& c);
  void Menu(ProcCenter& c);
  void Schet_Chel(ProcCenter& c);
  void Vzat_dengi(ProcCenter& c);
  void Vidat_denfi(ProcCenter& c);
  void VVod_NOMERA_FOR_TEST(string a);
  int Vidat_dengi_prog(ProcCenter& c);
  void Check_vnes(ProcCenter& c);
  int Vzat_dengi_prog(ProcCenter& c);
  int Finde_card_prog(ProcCenter& c);
  void Finde_card_Chel(ProcCenter& c);
  void Check_snam(ProcCenter& c);
  void VVOD_SUUMMi_SNAT_FOR_TEST(int a);
  void qwertyuiop(ProcCenter& c);
  void CHECK_FOR_VVODA_DENEG(int a);


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

