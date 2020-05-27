#include "Menu.h"
#include <conio.h>


ostream& operator<<(ostream& stream, const Menu& d);


Menu::Menu(vector <string> naz, int k, int x, int y, int d) {

  kol = k;
  if (kol < 0 || kol >naz.size()) throw std::logic_error("cant be a negative value");
  for (int i = 0; i < kol; i++) nazvan.insert(nazvan.end(), naz.at(i));
  if (x < 0 || y < 0) throw std::logic_error("cant be a negative value");
  Cor.xCor = x;
  Cor.yCor = y;
  if (d < 80) throw std::logic_error("cant be less 80");
  Cor.size = d;

}
Menu::Menu(string n) {

  ifstream str(n);
  if (!str.is_open())
    cout << "Error\n";
  else
  {
    str >> Cor.xCor;
    str >> Cor.yCor;
    if (Cor.xCor < 0 || Cor.yCor < 0) throw std::logic_error("cant be a negative value");
    str >> Cor.size;
    cout << "\n";
    if (Cor.size < 80) throw std::logic_error("cant be less 80");
    str >> kol;
    if (kol < 0) throw std::logic_error("cant be a negative value");
    for (int i = 0; i < kol; i++) {
      nazvan.push_back("");
      str >> nazvan.at(i);
    }
    str.close();
  }
}
ostream& operator<<(ostream& stream, const Menu& d) {
  for (int i = 0; i < d.kol; i++) {
    stream << d.nazvan[i];
    stream << endl;
  }
  stream << d.Cor.xCor;
  stream << endl;
  stream << d.Cor.yCor;
  stream << endl;
  stream << d.Cor.size;
  return stream;
}

void thisinfo(const Menu& c) {
  vector <string> n1;
  for (int i = 0; i < c.kol; i++) {
    n1.push_back(" ");
    n1.at(i) = c.nazvan[i];
  }
  cout << c.Cor.xCor << " " << c.Cor.yCor << " " << c.Cor.size << endl;

  for (int i = 0; i < n1.size(); i++)
    cout << n1[i] << endl;

  int a = 0;
  cout << "Return to menu?" << endl;
  cout << "(1)Yes  (2)No";
  cin >> a;

  if (a == 1) {
    vector <string> n1 = { "Info about window console", "Change size of window", "Minimize window", "Text change","Exit" };
    string g = "menuu.txt";
    const int k = n1.size();
    Menu a(n1, k, 1, 1, 700);
    choose(a);
  }
}

void info(const Menu& c) {
  vector <string> n1;
  for (int i = 0; i < c.kol; i++) {
    n1.push_back(" ");
    n1.at(i) = c.nazvan[i];
  }
  cout << "Coor x:";
  int x;
  cin >> x;
  cout << "Coor y:";
  int y;
  cin >> y;
  cout << "Elements menu: ";
  int d;
  cin >> d;
  Menu b(n1, 3, x, y, d);
  choose(b);
}

void text() {

  system("color 30");
  system("cls");

  cout << "Look At Me!!" << endl << endl;

  int a = 0;
  cout << "Return to menu?" << endl;
  cout << "(1)Yes  (2)No";
  cin >> a;

  if (a == 1) {
    vector <string> n1 = { "Info about window console", "Change size of window", "Minimize window", "Text change","Exit" };
    string g = "menuu.txt";
    const int k = n1.size();
    Menu a(n1, k, 1, 1, 700);
    choose(a);
  }
}

int choose(const Menu& d) {
  HWND hwnd = GetConsoleWindow();
  RECT rect = { d.Cor.xCor,d.Cor.yCor,d.Cor.size, d.Cor.size };
  MoveWindow(hwnd, rect.top, rect.left, rect.bottom - rect.top, rect.right - rect.left, TRUE);

  int counter = 1, chosen_option = counter;
  int nom = 0;
  while (chosen_option != 2)
  {
    system("cls");
    for (size_t i = 0; i < d.kol; ++i)
    {
      if ((i + 1) == counter) {
        nom = i + 1;
        cout << "-> " << d.nazvan[i] << endl;
      }
      else {
        cout << d.nazvan[i] << endl;
      }
    }
    char pressed = _getch();

    if (pressed == 'w' && counter != 1)
      counter--;
    if (pressed == 's' && counter != d.kol)
      counter++;

    if (pressed == '\r' || pressed == '\n') {
      chosen_option = counter;
      system("cls");
      doSomething(d, nom);
      return 0;
      _getch();
    }
  }
}

void doSomething(const Menu& d, int n) {
  system("cls");
  HWND hwnd = GetConsoleWindow();
  cout << d.nazvan[n - 1] << endl;
  switch (n) {
  case 1:
    thisinfo(d);
    break;
  case 2:
    info(d);
    break;
  case 3:
    ShowWindow(hwnd, SW_MINIMIZE);
    choose(d);
    break;
  case 4:
    text();
    break;
  case 5:
    break;
  default:
    break;
  }
}