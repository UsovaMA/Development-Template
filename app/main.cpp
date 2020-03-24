#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <stdexcept>
#include "dict.h"
#include "ALLDict.h"
using namespace std;

void meny1(bool a) {
  if (a) {
    cout << " ________________ " << endl;
    cout << "| Make a choice  |" << endl;
    cout << "|0- Exit         |" << endl;
    cout << "|1- file input   |" << endl;
    cout << "|2- Manual entery|" << endl;
    cout << "|3- Next step    |" << endl;
    cout << "|________________|" << endl;
  } else {
    cout << " ________________ " << endl;
    cout << "| Make a choice  |" << endl;
    cout << "|0- Exit         |" << endl;
    cout << "|1- file input   |" << endl;
    cout << "|2- Manual entery|" << endl;
    cout << "|________________|" << endl;
  }
}
void meny2() {
  cout << " __________________________________________________ " << endl;
  cout << "| Make a choice                                    |" << endl;
  cout << "|0- Exit                                           |" << endl;
  cout << "|1- change the translation of the specified word   |" << endl;
  cout << "|2- find out the translation of the selected word  |" << endl;
  cout << "|3- check the presence of a word in the dictionary |" << endl;
  cout << "|4- find out the number of words in the dictionary |" << endl;
  cout << "|5- Last step<-------------------------------------|" << endl;
  cout << "|6----------------------------------> Next step    |" << endl;
  cout << "|__________________________________________________|" << endl;
}
void meny3() {
  cout << " ______________________" << endl;
  cout << "| Make a choice        |" << endl;
  cout << "|0- Exit               |" << endl;
  cout << "|1- file output        |" << endl;
  cout << "|2- console dictionary |" << endl;
  cout << "|3<-----Last step      |" << endl;
  cout << "|______________________|" << endl;
}

//2) change the translation of the specified word,
//3) find out the translation of the selected word,
//4) check the presence of a word in the dictionary,
//5) find out the number of words in the dictionary,

int main() {
  setlocale(LC_ALL, "Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  Dict a("Словарь", "Dictionary");
  ALLDict A(a);
  int i = 1;
  int v;
  string search_word, Sres;
  meny1(0);
  cin >> v;
  if ((v > 2) || (v < 0))
    throw std::logic_error("Error: incorrect choice\n");
  while (i != 0) {
    switch (i) {
    case 1:
      if (v == 1) {
        ifstream in;
        in.open("input.txt");
        string str;
        while (getline(in, str)) {
          a.OB(str);
          A.DopSTR(a);
        }
        in.close();
      }
      if (v == 2) {
        cin >> A;
      }
      meny1(1);
      cin >> v;
      if (v == 3) i = 2;
      if (v==0)   i = 0;
      break;
    case 2:
      meny2();
      cin >> v;
      if ((v > 6) || (v < 0))
        throw std::logic_error("Error: incorrect choice\n");
      if (v == 1) {
        cout << "Enter the word- ";
        cin >> search_word;
        cout << "Enter the change(translate) word- ";
        cin >> Sres;
        A.ChTran(search_word, Sres);
        break;
      }
      if (v == 2) {
        cout << "Enter the search word- ";
        cin >> search_word;
        cout << "Translate is" << A.Tran(search_word) << endl;
        break;
      }
      if (v == 3) {
        cout << "Enter the word- ";
        cin >> search_word;
        bool res=A.Poisk(search_word);
        if (res) {
          Sres=A.Tran(search_word);
          cout << Sres << " -translation of this word" << endl;
        }
        else {
          cout << "No, This word is not in the dictionary." << endl;
        }
        break;
      }
      if (v == 4) {
        cout << "Size is "<< A.getS() << endl;
      }
      if (v == 5) i = 1;
      if (v == 6) i = 3;
      if (v == 0) i = 0;
      break;
    case 3:
      meny3();
      cin >> v;
      if (v == 0) i = 0;
      if (v == 1){
        ofstream out;
        out.open("output.txt");
        for (int i = 0; i < A.getS(); i++) {
          out << A << endl;
        }
        out.close();
      }
      if (v == 2) {
        for (int i = 0; i < A.getS(); i++) {
          cout << A << endl;
        }
      }
      if (v == 3) i = 2;
      break;
    }
  }
  system("pause");
}
