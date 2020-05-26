#include "BullsAndCows.h"

void BullsCows::Random_(char arr[], int n)
{
  Inttostr(rand() % 9999, arr, CountofNums);
}

void BullsCows::Inttostr(int value, char arr[], int n)
{
  for (int i = CountofNums - 1; i >= 0; i--)
  {
    arr[i] = '0' + value % 10;
    value = value / 10;
  }
}
BullsCows::BullsCows(int n) {
  if (n < 1 && n > 9999) throw std::logic_error("error");
  int k = n;
  for (; n > 0; CountofNums++) {
    n /= 10;
  }
  Inttostr(k, setriddle, CountofNums);
}
bool BullsCows::SimillarNums(char arr[], int n)
{
  int count = 0;
  for (int i = 0; i < CountofNums; i++)
    for (int j = i + 1; j < CountofNums; j++)
    {
      if (arr[i] == arr[j])
        count++;
    }

  return (count != 0);
}


void BullsCows::GameStart() {

  do {
    Times++;
    Bulls = 0;
    Cows = 0;
    if (CountofNums == 0) {
      srand(time(NULL));
      for (int i = 1; i < 15; i++)
        rand();
      int i=-1;
      cout << "Введите количество цифр, не больше 8" << endl;
      while (i < 1 || i > 8) {
        cin >> i;
      }
      CountofNums = i;
      do {
        Random_(setriddle, CountofNums);
      } while (SimillarNums(setriddle, CountofNums));
    }
    cout << "Введите число из " << CountofNums << " цифр " << endl;
    cout << "Введите '0' чтобы выйти из игры " << endl;
    cin >> PlayerNum;
    if (PlayerNum == 0)
    {
      exit(0);
    }
    if (PlayerNum > (pow(10, CountofNums) - 1))
    {
      cout << "Вы ввели слишком много цифр \n";
      continue;
    }
    if (PlayerNum < pow(10, CountofNums - 1))
    {
      cout << "Вы ввели слишком мало цифр \n";
      continue;
    }
    Inttostr(PlayerNum, playerinput, CountofNums);

    if (SimillarNums(playerinput, CountofNums))
    {
      cout << "Нельзя вводить одинаковые цифры";
      continue;
    }
    for (int i = 0; i < CountofNums; i++)
    {
      if (setriddle[i] == playerinput[i])
        Bulls++;
      for (int j = 0; j < CountofNums; j++)
        if (setriddle[i] == playerinput[j])
          Cows++;
    }
    Cows -= Bulls;
    cout << "Попытка №" << Times << ": Быков " << Bulls << "; Коров " << Cows << endl;
  } while (Bulls != CountofNums);
  cout << "Вы победили." << endl;
  cout << "1:Играть снова" << endl;
  cout << "2:Выход" << endl;
  int select=-1;
  while (select < 1 || select > 2) {
    cin >> select;
  }
  switch (select) {
  case 1:
    CountofNums = 0;
    GameStart();  break;
  case 2:
    exit(0);  break;
  };
}