#pragma once
#include <iostream>
#include <ctime>
#define MAX 10
using namespace std;
class BullsCows {
private:
  char setriddle[MAX];
  char playerinput[MAX];
  int CountofNums=0;
  int PlayerNum;    
  int Bulls = 0;	 
  int Cows = 0;	   
  int Times = 0;
public:
  void NumSet(char* n) {
    for (int i = 0; i < CountofNums; i++) {
      setriddle[i] = n[i];
    }
  }
  BullsCows(int i);
  BullsCows() { CountofNums = 0; }
  ~BullsCows() {}
  void GameStart();
  void Inttostr(int value, char arr[], int n);
  bool SimillarNums(char arr[], int n);
  void Random_(char arr[], int n);
};
