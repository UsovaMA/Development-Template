#include <iostream>
#include "Menu.h"
#include <clocale>
using namespace std;

int main()
{
  setlocale(LC_ALL, "rus");
    cout << "¬ведите координаты меню в виде x y:  ";
    int x = 2, y = 2;
    cin >> x >> y;
    cout << "¬ведите размер строки меню   ";
    int size = 20;
    cin >> size;
    cout << "¬ведите количество пунктов меню    ";
    int num = 3;
    cin >> num;
    cout << "¬ведите назвоние пунктов меню   ";
    string* mn = new string[num];


    for (int i = 0; i < num; i++)
    {
      cin >> mn[i];
    }
    system("cls");
    Menu m(x, y, size, num, mn);
    m.Display();
    int p = m.SelectionMenu();
    m.Clear();
    system("cls");
    cout << p << endl;
  

  /*catch (ExMenu exp)
  {
    switch (exp.type)
    {
    case(wrongSize):
      cout << "WrongSize\n";
      cout << "Error on size = " << exp.intSize;
      break;
    case(outofAr):
      cout << "Arror: Size Array\n";
      cout << "Size Array != Num String: Size Array = " << exp.intSize;
      break;
    default:
      break;
    }
  }*/

  
    Menu m("Menu.txt");
    m.Display();
    int k = m.SelectionMenu();
    m.Clear();
    cout << k;
  return 0;
}
