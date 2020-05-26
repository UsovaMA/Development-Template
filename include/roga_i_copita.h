#ifndef INCLUDE_Game_H_
#define INCLUDE_Game_H_
#include <iostream>
#include <ctime>
#define MAX 9
using namespace std;
class roga_i_copita {
private:
  int kol=0;
  int nOurs;       //число, введенное пользователем
  int bools = 0;	 // быки
  int cows = 0;	   // коровы
  char mech[MAX];  //загаданно
  char ours[MAX];  //пользователь
  int raz = 0;
public:
  void SetNom(char* n) {
    for (int i = 0; i < kol; i++) {
      mech[i] = n[i];
    }
  }
  roga_i_copita(int i);
  roga_i_copita() { kol = 0; }
  ~roga_i_copita() {}
  void game1();
  void Move2Array(int value, char ar[], int n);
  bool SameDigits(char ar[], int n);
  void rand_4(char ar[], int n);
};
#endif  // INCLUDE_Game_H_
