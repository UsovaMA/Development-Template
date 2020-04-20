<<<<<<< Updated upstream
#include "add.h"
#include <iostream>

int main() {
  std::cout << "5 + 5 = " << add(5, 5) << std::endl;
}
=======
#include <fstream>
#include <iostream>
#include "Pedometr.h"

using namespace std;

int main() {

  int data[3];
  int tSt[2];
  int tFn[2];
  int steps;

  cout << "Enter year, mounth, day: ";
  cin >> data[0] >> data[1] >> data[2];
  cout << "Enter hour, minute of start: ";
  cin >> tSt[0] >> tSt[1];
  cout << "Enter hour, minute of finish: ";
  cin >> tFn[0] >> tFn[1];
  cout << "Enter count of steps: ";
  cin >> steps;

 

  return 0;
}
>>>>>>> Stashed changes
