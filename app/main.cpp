#include "pedometer.h"
using namespace std;
int main() {
  int arr[4];
  Pedometer res("12.12.12", "12:20", "14:30", 2000), x;
  x.readHistoryFromFile("Count's-history.txt", true);
  if (x == res)
    cout << "true" << endl;
  x.start_menu();
  system("pause");
}
