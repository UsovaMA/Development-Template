
#include "Bancomat.h"


void Bancomat::TakeCard(ProcCenter& c) 
{
  Start(c);
}
void PrintMenu()
{
  cout << endl;
  cout << "Выберите опцию" << endl;
  cout << "1 : Добавить пользователя" << endl;
  cout << "2 : Принять карту клиента" << endl;
  cout << "3 : Найти клиента по номеру карты" << endl;
  cout << "4 : Распечатать состояние счета клиента" << endl;
  cout << "5 : Выдать клиенту наличные" << endl;
  cout << "6 : Принять от клиента наличные" << endl;
  cout << "7 : Вернуть карту клиенту" << endl;
}
void Bancomat::CountCard(ProcCenter& c) 
{
  for (int i = 0; i < c.next; i++) {
         Num = i;
  }
}

void Bancomat::Start(ProcCenter& c)
{
  cout << "Введите номер карты ";
  cin >> CardpiN.NumCard;
  Check(c);
  Check_PIN(c);
  
}
void Bancomat::nexttest(ProcCenter& c)
{
  for (int i = 0; i < c.next; i++) {
    Num = i;
  }
}
void Bancomat::Check_PIN(ProcCenter& c)  
{
  int times = 0;
  do {
    times++;
    cout << endl << "Введите пин код ";
    cin >> CardpiN.PIN;
  } while (c.person[Num].PIN != CardpiN.PIN && times < 3);
  if (c.person[Num].PIN != CardpiN.PIN)
  {
    for (int i = 10; i > 0; i--) {
      cout << i << endl;
      Sleep(1000);
    }
  }
  Menu(c);
}

void Bancomat::Check(ProcCenter& c)
{
  bool t = false;
  for (int i = 0; i < c.next; i++) {
    if ((c.person[i].NumCard == CardpiN.NumCard)) {
      Num = i;
      t = true;
    }
  }
  if (t == false) {
    cout << "Неверный номер карты или пинкод" << endl;
    cout << "Нажмите 1 если хотите попробовать снова" << endl;
    cout << "Нажмите 2 если хотите зарегистрироваться" << endl;
    int select = -1;
    while (select < 1 || select > 2) {
      cin >> select;
    }
    switch (select) {
    case 1:  Start(c); break;
    case 2:  c.AddPers(); c.next = c.next + 1; Menu(c); break;
    }
  }
}
void Bancomat :: FindCardSup(ProcCenter& c)
{
  cout << "Введите номер карты ";
  cin >> CardpiN.NumCard;
  cout << endl;
}
int  Bancomat::FindCardMain(ProcCenter& c) 
{
  int sim = 0;
  bool none = 0;
  for (int i = 0; i < c.next; i++)
  {
    if (c.person[i].NumCard == CardpiN.NumCard)
    {
      sim = i;
      none = 1;
    }
  }
  if (none == 0)
  {
    return -1;
  }
  return sim;
}

void Bancomat::FindCard(ProcCenter& c)
{
  FindCardSup(c);
  int sim = FindCardMain(c);
  if (sim == -1)
  {
    cout << endl << "Пользователя с таким номером карты не существует" << endl;
  }
  else
  {
    cout << "Имя: ";
    cout << c.person[sim].Name << endl;
    cout << "Фамилия: ";
    cout << c.person[sim].MiddleName << endl;
    cout << "Отчество: ";
    cout << c.person[sim].LastName << endl;
    cout << "Номер карты: ";
    cout << c.person[sim].NumCard << endl;
    if (c.person[sim].Blocked == 1)
    {
      cout << "Карта заблокирована" << endl;
    }
    else
    {
      cout << "Карта не заблокирована" << endl;
    }
  }
  Menu(c);
}
void Bancomat::BalancePerson(ProcCenter& c) 
{
  cout << "Счет пользователя: ";
  cout << c.person[Num].Balance << endl;
  if (c.person[Num].Blocked == 1)
  {
    cout << "Карта заблокирована" << endl;
  }
  else
  {
    //cout << "Карта не заблокирована" << endl;
  }
  Menu(c);
}
int Bancomat::BalancePersonForTest(ProcCenter& c)
{ int i = c.person[Num].Balance;
return i;
}
void Bancomat::CheckTake(ProcCenter& c) 
{
  cout << "Введите сумму, которую хотите снять: ";
  cin >> takemoney;
}
void Bancomat::CheckTakeForTest(ProcCenter& c, int a)
{
  takemoney = a;
}

int Bancomat::CheckSum(ProcCenter& c) 
{
 
  if (takemoney > c.person[Num].Balance)
  {
    return 0;
  }
  return 1;
}

int Bancomat::TakeMoneyMain(ProcCenter& c)
{

  int count = 0;
  int takemoneysup = takemoney;
  int _5000sup = _5000_;
  int _2000sup = _2000_;
  int _1000sup = _1000_;
  int _500sup = _500_;
  int _200sup = _200_;
  int _100sup = _100_;
  int over40 = 0;
  int balancesup = c.person[Num].Balance;
  if (c.person[Num].Blocked == 1)
  {
    count = 9;
  }
  else
  {

    if (CheckSum(c) == 1)
    {
      
      if (takemoneysup % 100 == 0)
      {

        while (takemoneysup != 0)
        {
          while (takemoneysup / 5000 > 0)
          {
            _5000sup--;
            over40 = +1;
            if (over40 >= 41) {
              count = 40;
              return count;
            };
            if (_5000sup <= -1)
            {
              count = 1;
              break;
            }
            over40 = 0;
            balancesup = balancesup - 5000;
            takemoneysup = takemoneysup - 5000;

          }
          while (takemoneysup / 2000 > 0)
          {
            _2000sup--;
            over40 = +1;
            if (over40 >= 41) {
              count = 40;
              return count;
            };
            if (_2000sup <= -1)
            {
              count = 1;
              break;
            }
            over40 = 0;
            balancesup = balancesup - 2000;
            takemoneysup = takemoneysup - 2000;
          }
          while (takemoneysup / 1000 > 0)
          {
            _1000sup--;
            over40 = +1;
            if (over40 >= 41) {
              count = 40;
              return count;
            };
            if (_1000sup <= -1)
            {
              count = 1;
              break;
            }
            over40 = 0;
            balancesup = balancesup - 1000;
            takemoneysup = takemoneysup - 1000;
          }
          while (takemoneysup / 500 > 0)
          {
            _500sup--;
            over40 = +1;
            if (over40 >= 41) {
              count = 40;
              return count;
            };
            if (_500sup <= -1)
            {
              count = 1;
              break;
            }
            over40 = 0;
            balancesup = balancesup - 500;
            takemoneysup = takemoneysup - 500;
          }
          while (takemoneysup / 200 > 0)
          {
            _200sup--;
            over40 = +1;
            if (over40 >= 41) {
              count = 40;
              return count;
            };
            if (_200sup <= -1)
            {
              count = 1;
              break;
            }
            over40 = 0;
            balancesup = balancesup - 200;
            takemoneysup = takemoneysup - 200;
          }
          while (takemoneysup / 100 > 0)
          {
            _100sup--;
            over40 = +1;
            if (over40 >= 41) {
              count = 40;
              return count;
            };
            if (_100sup <= -1)
            {
              count = 6;
              return count;
              break;
            }
            over40 = 0;
            balancesup = balancesup - 100;
            takemoneysup = takemoneysup - 100;
          }


          c.person[Num].Balance = balancesup;
          _5000_ = _5000sup;
          _2000_ = _2000sup;
          _1000_ = _1000sup;
          _500_ = _500sup;
          _200_ = _200sup;
          _100_ = _100sup;


        }
      }
      else
      {
        count = 100;
        return count;
      }
    
  }
      else
      {
        count = 8;


      }
    }
  return count;
}

void Bancomat::TakeMoney(ProcCenter& c) 
{
  CheckTake(c);
  int count = 0;
  count = TakeMoneyMain(c);
  switch (count)
  {
    case 6:cout << "В банкомате кончились все купюры" << endl;
      Menu(c); 
      break;
    case 8:cout << "Недостаточно средств на карте" << endl;
      Menu(c); break;
    case 100: cout << "Число не кратно 100" << endl; Menu(c); break;
    case 9: cout << "Карта заблокирована, снятие средств невозможно" << endl;
      Menu(c); break;
    case 0: Menu(c); break;
  }
}
void Bancomat::CheckPutMoney(ProcCenter& c)
{
  cout << "Введите сумму которую хотите внести ";
  cin >> putmoney;
}
void Bancomat::CheckPutMoneyForTest(ProcCenter& c, int a)
{
  putmoney = a;
}
int Bancomat::PutMoneyMain(ProcCenter& c)
{
  int count = 0;
  int putmoneysup = putmoney;
  int _5000sup = _5000_;
  int _2000sup = _2000_;
  int _1000sup = _1000_;
  int _500sup = _500_;
  int _200sup = _200_;
  int _100sup = _100_;
  int over40 = 0;
  int balancesup = c.person[Num].Balance;
  if (c.person[Num].Blocked == 1)
  {
    count = 9;
  }
  else
  {
    
    if (putmoneysup % 100 == 0)
    {
      while (putmoneysup / 5000 > 0)
      {
        _5000sup++;
        over40 = +1;
        if (over40 >= 41) {
          count = 40;
          return count;
        };
        if (_5000sup >= 2001)
        {
          count = 1;
          break;
        }
        over40 = 0;
        balancesup = balancesup + 5000;
        putmoneysup = putmoneysup - 5000;

      }
      while (putmoneysup / 2000 > 0)
      {
        _2000sup++;
        over40 = +1;
        if (over40 >= 41) {
          count = 40;
          return count;
        };
        if (_2000sup >= 2001)
        {
          count = 1;
          break;
        }
        over40 = 0;
        balancesup = balancesup + 2000;
        putmoneysup = putmoneysup - 2000;
      }
      while (putmoneysup / 1000 > 0)
      {
        _1000sup++;
        over40 = +1;
        if (over40 >= 41) {
          count = 40;
          return count;
        };
        if (_1000sup >= 2001)
        {
          count = 1;
          break;
        }
        over40 = 0;
        balancesup = balancesup + 1000;
        putmoneysup = putmoneysup - 1000;
      }
      while (putmoneysup / 500 > 0)
      {
        _500sup++;
        over40 = +1;
        if (over40 >= 41) {
          count = 40;
          return count;
        };
        if (_500sup >= 2001)
        {
          count = 1;
          break;
        }
        over40 = 0;
        balancesup = balancesup + 500;
        putmoneysup = putmoneysup - 500;
      }
      while (putmoneysup / 200 > 0)
      {
        _200sup++;
        over40 = +1;
        if (over40 >= 41) {
          count = 40;
          return count;
        };
        if (_200sup >= 2001)
        {
          count = 1;
          break;
        }
        over40 = 0;
        balancesup = balancesup + 200;
        putmoneysup = putmoneysup - 200;
      }
      while (putmoneysup / 100 > 0)
      {
        _100sup++;
        over40 = +1;
        if (over40 >= 41) {
          count = 40;
          return count;
        };
        if (_100sup >= 2001)
        {
          count = 6;
          return count;
          break;
        }
        over40 = 0;
        balancesup = balancesup + 100;
        putmoneysup = putmoneysup - 100;
      }
      c.person[Num].Balance = balancesup;
      _5000_ = _5000sup;
      _2000_ = _2000sup;
      _1000_ = _1000sup;
      _500_ = _500sup;
      _200_ = _200sup;
      _100_ = _100sup;
    }

    else
    {
      count = 100;
      return count;
    }
  }
  return count;
}
void Bancomat::PutMoney(ProcCenter& c)
{
  CheckPutMoney(c);
  int count = 0;
  count = PutMoneyMain(c);
  switch (count)
  {
  case 6:cout << "В банкомате закончилось место для хранения купюр" << endl;
    Menu(c); break;
  case 100: cout << "Число не кратно 100" << endl; Menu(c); break;
  case 9: cout << "Карта заблокирована, снятие средств невозможно" << endl;
    Menu(c); break;
  case 0: Menu(c); break;
  }
}
  

void Bancomat::Menu(ProcCenter& c) 
{
  PrintMenu();
  int Vibor = -1;
  while (Vibor < 1 || Vibor > 8) {
    cin >> Vibor;
  }
  switch (Vibor) {
  case 1:c.AddPers();Menu(c); break;
  case 2:TakeCard(c); break;
  case 3:FindCard(c);break;
  case 4:BalancePerson(c);break;
  case 5:TakeMoney(c);break;
  case 6:PutMoney(c);break;
  case 7: exit(0);break;
  }

}

