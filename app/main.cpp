<<<<<<< Updated upstream
#include "add.h"
#include <iostream>

int main() {
  std::cout << "5 + 5 = " << add(5, 5) << std::endl;
}
=======
#include "Menu.h"

int main() {

  int a = 0;
  cout << "use 'w' or 's' " << endl << endl;
  cout << "You want open menu?" << endl;
  cout << "(1)Yes  (2)No";
  cin >> a;

  if (a == 1) {
    vector <string> n1 = { "Info about window console", "Change size of console" ,"Minimize window", "Text change","Exit" };
    string g = "menuu.txt";
    const int k = n1.size();
    Menu a(n1, k, 1, 1, 700);
    choose(a);
  }

  cout << "You like it?  :)" << endl;
  cout << "(1)Yes  (2)No";
  cin >> a;

  if (a == 1) {
    cout << endl << endl << "Thanks! :)";
  }

  return 0;
}
>>>>>>> Stashed changes
