
#include "Bancomat.h"

void PrintMenu()
{
  cout << endl;
  cout << "Выбирите действие" << endl;
  cout << "1 - Добавить пользователя" << endl;
  cout << "2 - Принять карту клиента" << endl;
  cout << "3 - Найти клиента по номеру карты" << endl;
  cout << "4 - Проверить PIN-код" << endl;
  cout << "5 - Распечатать состояние счета клиента" << endl;
  cout << "6 - Выдать клиенту наличные" << endl;
  cout << "7 - Принять от клиента наличные" << endl;
  cout << "8 - Вернуть карту клиенту" << endl;
}

void Bancomat::TakeCard(ProcCenterVec& c) 
{
  Start(c);
}

void Bancomat::Start(ProcCenterVec& c)
{
  cout << "Введите номер карты ";
  cin >> CardpiN.NumCard;
  Check(c);
  Check_PIN(c);
  
}
void Bancomat::Check_PIN(ProcCenterVec& c) 
{
  cout << endl << "Введите пин код ";
  cin >> CardpiN.PIN;
  if (c.Vect[Num].PIN != CardpiN.PIN)
  {
    cout << endl << "НЕВЕРНЫЙ ПИН КОД"<<endl;
    cout << "Введите пин код заново: ";
    cin >> CardpiN.PIN;
    c.Vect[Num].incorrectPinTimes++;
    if (c.Vect[Num].PIN != CardpiN.PIN)
    {
      cout << endl << "НЕВЕРНЫЙ ПИН КОД" << endl;
      cout << "Введите пин код заново: ";
      cin >> CardpiN.PIN;
      c.Vect[Num].incorrectPinTimes++;
    }
  }
  if (c.Vect[Num].incorrectPinTimes == 2)
  {
    cout << endl << "Карта забокирована на 10 сек"<<endl;
    for (int i = 0; i < 10; ++i) {
      printf("%d\n", (10 - i));
      Sleep(1000);
    }
    Check_PIN(c);
  
  }
  Menu(c);
}

void Bancomat::Check(ProcCenterVec& c)
{
  bool t = false;
  for (int i = 0; i < c.Vect.size(); i++) {
    if ((c.Vect[i].CardNumber == CardpiN.NumCard)) {
      Num = i;
      t = true;
    }
  }
  if (t == false) {
    cout << "Неверный Номера карты" << endl;
    cout << "Нажмите 1 если хотите попробовать снова" << endl;
    cout << "Нажмите 2 если хотите зарегистрироваться" << endl;
    int Select = -1;
    while (Select < 1 || Select > 2) {
      cin >> Select;
    }
    switch (Select) {
    case 1:  Start(c); break;
    case 2:  c.AddPerson(); Num = c.Vect.size() - 1; Menu(c); break;
    }
  }
}
void Bancomat::FindCard(ProcCenterVec& c)
{
  int posres=0;
  cout << "Введите номер карты ";
  cin >> CardpiN.NumCard;
  cout << endl;
  for (int i = 0; i < c.Vect.size(); i++) {
    if (c.Vect[i].CardNumber == CardpiN.NumCard) {
      posres = 1;
      cout << "Имя: ";
      cout << c.Vect[i].Name<< endl;
      cout << "Фамилия: ";
      cout << c.Vect[i].MiddleName<< endl;
      cout << "Отчество: ";
      cout << c.Vect[i].LastName<< endl;
      cout << "Номер карты: ";
      cout << c.Vect[i].CardNumber<< endl;
      break;
    }
 
  }
  if (posres == 0)
  {
    cout << "Пользователя с таким номером не сушествует" << endl;
  }
  Menu(c);
}
void Bancomat::BalancePerson(ProcCenterVec& c) 
{
  cout << "Счёт пользователя: ";
  cout << c.Vect[Num].Balance << endl;
  Menu(c);
}
void Bancomat::TakeMoney(ProcCenterVec& c) 
{
  

    cout << "Введите сумму которую хотите снять: ";
    cin >> takemoney;
    if (takemoney > c.Vect[Num].Balance)
    {
      cout << "Не достаточно средств на карте" << endl;
      Menu(c);
    }
    else
    {
      if (c.Vect[Num].Balance % 10 == 0)
      {
        while (takemoney != 0)
        {
          while (takemoney / 5000 > 0)
          {
            _5000_--;
            if (_5000_ == -1)
            {
              cout << "В банкомате кончились купюры номинала пять тысяч рублей" << endl;
              Menu(c);
            }
            c.Vect[Num].Balance = c.Vect[Num].Balance - 5000;
            takemoney = takemoney - 5000;

          }
          while (takemoney / 1000 > 0)
          {
            _1000_--;
            if (_1000_ == -1)
            {
              cout << "В банкомате кончились купюры номинала тысячи рублей" << endl;
              Menu(c);
            }
            c.Vect[Num].Balance = c.Vect[Num].Balance - 1000;
            takemoney = takemoney - 1000;
          }
          while (takemoney / 500 > 0)
          {
            _500_--;
            if (_500_ == -1)
            {
              cout << "В банкомате кончились купюры номинала пятьсот рублей" << endl;
              Menu(c);
            }
            c.Vect[Num].Balance = c.Vect[Num].Balance - 500;
            takemoney = takemoney - 500;
          }
          while (takemoney / 100 > 0)
          {
            _100_--;
            if (_100_ == -1)
            {
              cout << "В банкомате кончились купюры номинала ста рублей" << endl;
              Menu(c);
            }
            c.Vect[Num].Balance = c.Vect[Num].Balance - 100;
            takemoney = takemoney - 100;
          }
          while (takemoney / 50 > 0)
          {
            _50_--;
            if (_50_ == -1)
            {
              cout << "В банкомате кончились купюры номинала пятьдесят рублей" << endl;
              Menu(c);
            }
            c.Vect[Num].Balance = c.Vect[Num].Balance - 50;
            takemoney = takemoney - 50;
          }
          while (takemoney / 10 > 0)
          {
            _10_--;
            if (_10_ == -1)
            {
              cout << "В банкомате кончились купюры номинала десять рублей" << endl;
              Menu(c);
            }
            c.Vect[Num].Balance = c.Vect[Num].Balance - 10;
            takemoney = takemoney - 10;
          }

        }
      }
        else
        {
          cout << "Число не кратно 10" << endl;

        
        }
    }

  
  Menu(c);
}
void Bancomat::PutMoney(ProcCenterVec& c) 
{
  int count = 0;

    cout << "Введите сумму которую хотите внести";
    cin >> putmoney;
      if (c.Vect[Num].Balance % 10 == 0)
      {
        while (putmoney / 5000 > 0)
        {
          _5000_++;
          if (_5000_ == 101)
          {
            cout << "В банкомате закончилось место для хранения купюр номинала пять тысяч рублей" << endl;
            Menu(c);
          }
          c.Vect[Num].Balance = c.Vect[Num].Balance + 5000;
          putmoney = putmoney - 5000;

        }
        while (putmoney / 1000 > 0)
        {
          _1000_++;
          if (_1000_ == 101)
          {
            cout << "В банкомате закончилось место для хранения купюр номинала тысяча рублей" << endl;
            Menu(c);
          }
          c.Vect[Num].Balance = c.Vect[Num].Balance + 1000;
          putmoney = putmoney - 1000;
        }
        while (putmoney / 500 > 0)
        {
          _500_++;
          if (_500_ == 101)
          {
            cout << "В банкомате закончилось место для хранения купюр номинала пятьсот рублей" << endl;
            Menu(c);
          }
          c.Vect[Num].Balance = c.Vect[Num].Balance + 500;
          putmoney = putmoney - 500;
        }
        while (putmoney / 100 > 0)
        {
          _100_++;
          if (_100_ == 101)
          {
            cout << "В банкомате закончилось место для хранения купюр номинала сто рублей" << endl;
            Menu(c);
          }
          c.Vect[Num].Balance = c.Vect[Num].Balance + 100;
          putmoney = putmoney - 100;
        }
        while (putmoney / 50 > 0)
        {
          _50_++;
          if (_50_ == 101)
          {
            cout << "В банкомате закончилось место для хранения купюр номинала пятьдесят рублей" << endl;
            Menu(c);
          }
          c.Vect[Num].Balance = c.Vect[Num].Balance + 50;
          putmoney = putmoney - 50;
        }
        while (putmoney / 10 > 0)
        {
          _10_++;
          if (_10_ == 101)
          {
            cout << "В банкомате закончилось место для хранения купюр номинала десять рублей" << endl;
            Menu(c);
          }
          c.Vect[Num].Balance = c.Vect[Num].Balance + 10;
          putmoney = putmoney - 10;
        }

      }
      else
      {
        cout << "Номинал купюр меньше 10ти не принимается" << endl;
      }
    
  Menu(c);
 }

void Bancomat::Menu(ProcCenterVec& c) 
{
  PrintMenu();
  int Select = -1;
  while (Select < 1 || Select > 8) {
    cin >> Select;
  }
  switch (Select) {
  case 1:c.AddPerson();Menu(c); break;
  case 2:TakeCard(c); break;
  case 3:FindCard(c);break;
  case 4:Check_PIN(c);break;
  case 5:BalancePerson(c);break;
  case 6:TakeMoney(c);break;
  case 7:PutMoney(c);break;
  case 8: exit(0);break;
  }
}

