#include "pedometer.h"



Data::Data() {
  time_start = 0;
  time_finish = 0;
  num_of_steps = 0;
  for (int i = 0; i < 3; ++i)
    date[i] = 0;
}

Data::Data(string _date, string _time_start, string _time_finish,
  int _num_of_steps) {
  time_start = StringTimeToMin(_time_start);
  time_finish = StringTimeToMin(_time_finish);
  num_of_steps = _num_of_steps;
  StringDateToIntArr(_date, date);
}

Data Data::operator=(Data &c) {
  int i;
  time_start = c.time_start;
  time_finish = c.time_finish;
  num_of_steps = c.num_of_steps;
  for (i = 0; i < 3; ++i)
    date[i] = c.date[i];
  return *this;
}

// maksimal'noe preispolnenie
Data* Data::operator=(Data* c) {
  int i;
  time_start = c->time_start;
  time_finish = c->time_finish;
  num_of_steps = c->num_of_steps;
  for (i = 0; i < 3; ++i)
    date[i] = c->date[i];
  return this;
}

Data::~Data() {
  int i;
  time_finish = 0;
  time_start = 0;
  num_of_steps = 0;
  for (i = 0; i < 3; ++i)
    date[i] = 0;
}

Pedometer::Pedometer() {
  counting = 0;
  history = new Data[0];
}

Pedometer::Pedometer(string date, string _time_start, string _time_finish,
  int _num_of_steps) {
  int i;
  counting = 1;
  history = new Data[1];
  history[0].time_start = StringTimeToMin(_time_start);
  history[0].time_finish = StringTimeToMin(_time_finish);
  history[0].num_of_steps = _num_of_steps;
  StringDateToIntArr(date, history[0].date);
}


bool Pedometer::operator==(Pedometer &c) {
  int i, j;
  if (counting == c.counting) {
    for (i = 0; i < counting; ++i) {
      if (c.history[i].num_of_steps == history[i].num_of_steps
        && c.history[i].time_finish == history[i].time_finish
        && c.history[i].time_start == history[i].time_start) {
        for (j = 0; j < 2; ++j) {
          if (c.history[i].date[j] != history[i].date[j])
            return false;
        }
      } else{
        return false;
      }
    }
  } else {
    return false;
  }
  return true;
}

bool operator==(myPair const & c1, myPair const & c2)
{
  if (c1.first == c2.first && c1.second == c2.second)
    return true;
  return false;
}

bool operator==(Pedometer const &c1, Pedometer const &c2) {
  int i, j;
  if (c1.counting == c2.counting) {
    for (i = 0; i < c1.counting; ++i) {
      if (c1.history[i].num_of_steps == c2.history[i].num_of_steps
        && c1.history[i].time_finish == c2.history[i].time_finish
        && c1.history[i].time_start == c2.history[i].time_start) {
        for (j = 0; j < 2; ++j) {
          if (c1.history[i].date[j] != c2.history[i].date[j])
            return false;
        }
      } else {
        return false;
      }
    }
  }
  return true;
}

Pedometer::~Pedometer() {
  int i, j;
  counting = 0;
  
}

Pedometer Pedometer::operator=(Pedometer &c) {
  int i, j;
  counting = c.counting;
  // kak glybako...
  history = new Data[counting];
  for (i = 0; i < counting; ++i) {
    history[i].time_start = c.history[i].time_start;
    history[i].time_finish = c.history[i].time_finish;
    history[i].num_of_steps = c.history[i].num_of_steps;
    for (j = 0; j < 3; ++j)
      history[i].date[j] = c.history[i].date[j];
  }
  delete[] c.history;  // Could it crash progarm?
  // Because now Destector for Pedometer don't has it
  return *this;
}

Pedometer Pedometer::operator=(pointerPair &c) {
  counting = c.count;
  history = c.histr;
  delete[] c.histr;
  return *this;
}

void Pedometer::addCounting(string date, string _time_start, string _time_finish,
  int _num_of_steps) {
  history = Resize(history, counting, counting + 1);
  StringDateToIntArr(date, history[counting].date);
  history[counting].time_start = StringTimeToMin(_time_start);
  history[counting].time_finish = StringTimeToMin(_time_finish);
  history[counting].num_of_steps = _num_of_steps;
  counting++;
}

void Pedometer::addCounting() {
  history = Resize(history, counting, counting + 1);
  string data;
  cout << "input date in format 'DD.MM.YY'" << endl;
  cin >> data;
  StringDateToIntArr(data, history[counting].date);
  cout << "input start time in format 'HH:MM'" << endl;
  cin >> data;
  history[counting].time_start = StringTimeToMin(data);
  cout << "input end time in format 'HH:MM'" << endl;
  cin >> data;
  history[counting].time_finish = StringTimeToMin(data);
  cout << "input number of steps: ";
  cin >> history[counting].num_of_steps;
  cout << "Count was added" << endl;
  counting++;
}

Pedometer Pedometer::getInfo(string _date, string _time_start,
  string _time_finish) {
  Pedometer res, resReturn;
  int i, j, k;
  int *found;  // array to remember suitable countings
  found = new int[1];
  found[0] = -1;
  Data finding(_date, _time_start, _time_finish, 0);
  for (i = 0, j = 0; i < counting + 1; i++) {
    if (finding.date[0] == history[i].date[0] &&
      finding.date[1] == history[i].date[1] &&
      finding.date[2] == history[i].date[2]) {
      if (history[i].time_start >= finding.time_start &&
        history[i].time_finish <= finding.time_finish) {
        found[j] = i;
        found = Resize(found, j + 1, j + 2);
        j++;
      }
    }
  }
  if (found[0] == -1) {
    throw logic_error("No data");
  }
  res.history = new Data[j];
  res.counting = j;
  for (i = 0; i < j; ++i) {
    res.history[i].time_start = history[found[i]].time_start;
    res.history[i].time_finish = history[found[i]].time_finish;
    res.history[i].num_of_steps = history[found[i]].num_of_steps;
    for (k = 0; k < 3; ++k)
      res.history[i].date[k] = history[found[i]].date[k];
  }
  return res;
}

void Pedometer::getInfo() const {
  string _time_start, _time_finish, _date;
  int i, j;
  int *found;  // array to remember suitable countings
  found = new int[1];
  found[0] = -1;
  cout << "Input date in format 'DD.MM.YY'" << endl;
  cin >> _date;
  cout << "input start time of interval in format 'HH:MM'" << endl;
  cin >> _time_start;
  cout << "input end time of interval in format 'HH:MM'" << endl;
  cin >> _time_finish;
  Data finding(_date, _time_start, _time_finish, 0);
  for (i = 0, j = 0; i < counting + 1; i++) {
    if (finding.date[0] == history[i].date[0] &&
      finding.date[1] == history[i].date[1] &&
      finding.date[2] == history[i].date[2]) {
      if (history[i].time_start >= finding.time_start &&
        history[i].time_finish <= finding.time_finish) {
        found[j] = i;
        found = Resize(found, j + 1, j + 2);
        j++;
      }
    }
  }
  if (found[0] == -1) {
    cout << "in this interval there is no any data" << endl;
    return;
  }
  cout << "in this interval there is some data:" << endl;
  for (i = 0; i < j; ++i) {
    cout << "#" << i + 1 << endl;
    cout << "time start:" << history[found[i]].time_start / 60 << ":" <<
      history[found[i]].time_start %60 << endl;
    cout << "time finish:" << history[found[i]].time_finish / 60 << ":" <<
      history[found[i]].time_finish % 60 << endl;
    cout << "number of steps:" << history[found[i]].num_of_steps << endl;
  }
}

myPair Pedometer::findAvarageOrMaxNumOfSteps(string _month_year,
  bool for_all_history, bool MaxOrAvarage) const {
    myPair res;  // first - num of steps, second use just for finding
    // max num of steps and save number of count in what date it were got
    res.first = 0;
    long long all_steps = 0;
    bool flag = false, once = false;
    int i = 0, j = 0, month = 0, year = 0;
    /*
    23:47, I started at 12:00, but just now I understed, that
    I could creat new string right here to write into it mount/year etc.
    and then convert it to int
    =((( GRYSTNA
    */
    while (_month_year[i++] != '\0');
    i -= 2;
    while (_month_year[i] != '.')
      year += (int)(_month_year[i--] - '0') * pow(10, j++);
    j = 0; i--;
    while (i != -1)
      month += (int)(_month_year[i--] - '0') * pow(10, j++);
    if (!MaxOrAvarage) {
      if (for_all_history) {
        for (i = 0; i < counting; ++i)
          all_steps += history[i].num_of_steps;
        res.first = all_steps / counting;
        res.second = 0;
        if (i == 0)
          throw logic_error("No data");
        return res;
      }
    // finding same date
    for (i = 0; i < counting; ++i) {
      // when found count all steps
      while (month == history[i].date[1] && year == history[i].date[2]) {
        if (!once) {
          j = i;  // remember entry point
          once = true;
        }
        all_steps += history[i++].num_of_steps;
        flag = true;
      }
      if (flag) {
        res.first = all_steps / (i - j);
        res.second = 0;
        return res;
      }
      throw logic_error("No data");
    }
  }
    if (MaxOrAvarage) {
      if (for_all_history) {
        for (i; i < counting; ++i) {
          if (history[i].num_of_steps > res.first) {
            res.first = history[i].num_of_steps;
            res.second = i;
            flag = true;
          }
        }
        if (flag)
          return res;
      throw logic_error("No data");
      }
      // finding same date
      for (i = 0; i < counting; ++i) {
        // when found count all steps
        while (month == history[i].date[1] && year == history[i].date[2]) {
          if (history[i].num_of_steps > res.first) {
            res.first = history[i].num_of_steps;
            res.second = i++;
          }
          flag = true;
        }
        if (flag)
          return res;
      }
    }
    throw logic_error("No data");
}

void Pedometer::start_menu() {
  int choice;
  bool for_all_time = false;
  myPair answer;
  string _date;
  bool menu, submenu;
  menu = submenu = true;
  while (true) {
    cout << "This menu to control count of your steps" << endl;
    cout << "1. Add new count" << endl;
    cout << "2. Get info by date and time interval" << endl;
    cout << "3. Find avarage number of steps in mount or for all time" << endl;
    cout << "4. Find max number of steps in mount or for all time" << endl;
    cout << "5. To know start date and count" << endl;
    cout << "6. Save history of count to file" << endl;
    cout << "7. Read history of count from file" << endl;
    cout << "8. Close programm" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
      this->addCounting();
      break;
    case 2:
      this->getInfo();
      break;
    case 3:
      while (submenu) {
        cout << "1. To find avarage number of steps in mount" << endl;
        cout << "2. To find avarage number of steps for all time" << endl;
        cout << "3. Back to menu" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
          cout << "input date in format 'MM.YY'" << endl;
          cin >> _date;
          submenu = false;
          break;
        case 2:
          for_all_time = true;
          submenu = false;
          _date = "0.0";
          break;
        case 3:
          // back to menu
          break;
        default:
          cout << "Ops, something went wrong, try again" << endl;
          break;
        }
      }
      submenu = true;
      answer = this->findAvarageOrMaxNumOfSteps(_date, for_all_time, false);
      cout << "Avarage count: " << answer.first << endl;
      break;
    case 4:
      while (submenu) {
        cout << "1. To find max number of steps in mount" << endl;
        cout << "2. To find max number of steps for all time" << endl;
        cout << "3. Back to menu" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
          cout << "input date in format MM.YY'" << endl;
          cin >> _date;
          submenu = false;
          break;
        case 2:
          for_all_time = true;
          submenu = false;
          _date = "0.0";
          break;
        case 3:
          // back to menu
          break;
        default:
          cout << "Ops, something went wrong, try again" << endl;
          break;
        }
      }
      submenu = true;
      answer = this->findAvarageOrMaxNumOfSteps(_date, for_all_time, true);
      cout << "Max count: " << answer.first << endl;
      cout << "Date: " << history[answer.second].date[0] << ":" <<
        history[answer.second].date[1] << ":" <<
        history[answer.second].date[2] << endl;
      break;
    case 5:
      cout << "Date: " << history[0].date[0] << ":" << history[0].date[1] <<
        ":" << history[0].date[2] << endl;
      cout << "Count: " << history[0].num_of_steps << endl;
      break;
    case 6:
        this->writeHistoryToFile();
        cout << "success" << endl;
      break;
    case 7:
      cout << "input file name: ";
      cin >> _date;
      this->readHistoryFromFile(_date, true);
      break;
    case 8:
      exit(0);
      break;
    default:
      cout << "Ops, something went wrong, try again" << endl;
      break;
    }
    cout << endl;
  }
}

void Pedometer::writeHistoryToFile() {
  ofstream file;
  int i, j;
  file.open("Count's-history.txt");
  if (file.is_open()) {
    for (i = 0; i < counting; ++i) {
      file << "record #" << i + 1 << "\0" << "\n" ;
      file << "date: ";
      for (j = 0; j < 2; ++j)
        file << history[i].date[j] << ".";
      file << history[i].date[j] << "\0" << "\n"; // j = 2
      file << "start time: " << history[i].time_start / 60 << ":" <<
        history[i].time_start % 60 << "\0" << "\n";
      file << "end time: " << history[i].time_finish / 60 << ":" <<
        history[i].time_finish % 60 << "\0" << "\n";
      file << "count of steps: " << history[i].num_of_steps << "\0" << "\n";
      file << "\n";
    }
    file.close();
    return;
  }
  throw -1;
  return;
}

void Pedometer::readHistoryFromFile(string filename, bool output) {
  ifstream file;
  string num;
  history = new Data[1];
  char line[255];
  char tmp[255];
  int i, j, count = 0;
  int help;
  file.open(filename);
  if (file.is_open()) {
    // OK C++ you win =(((((
    while (file.getline(line, 255, '\n')) {
      j = 0;
      if (output)
        cout << line << endl;
      switch (line[0]) {
      case 'r':
        i = 8;
        // 2 hours and it's work =)))))))))))))
        while (line[i] != '\0') {
          tmp[j] = line[i]; j++; i++;
        }
        tmp[j] = '\0';
        num = (string)(tmp);
        counting = toInt(num);
        break;
      case 'd':
        i = 6;
        while (line[i] != '\0') {
          tmp[j] = line[i]; j++; i++;
        }
        tmp[j] = '\0';
        num = (string)(tmp);
        StringDateToIntArr(num, history[counting - 1].date);
        break;
      case 's':
        i = 12;
        while (line[i] != '\0') {
          tmp[j] = line[i]; j++; i++;
        }
        tmp[j] = '\0';
        num = (string)(tmp);
        history[counting - 1].time_start = StringTimeToMin(num);
        break;
      case 'e':
        i = 10;
        while (line[i] != '\0') {
          tmp[j] = line[i]; j++; i++;
        }
        tmp[j] = '\0';
        num = (string)(tmp);
        history[counting - 1].time_finish = StringTimeToMin(num);
        break;
      case 'c':
        i = 16;
        while (line[i] != '\0') {
          tmp[j] = line[i]; j++; i++;
        }
        tmp[j] = '\0';
        num = (string)(tmp);
        history[counting - 1].num_of_steps = toInt(num);
        break;
      default:
        continue;
        break;
      }
      count++;
      history = Resize(history, count, count + 1);
    }
    file.close();
    return;
  }
  throw logic_error("No data");

}

Data* Resize(Data *a, int oldSize, int newSize) {
  int i;
  Data *tmp = new Data[newSize];
  for (i = 0; i < min(oldSize, newSize); ++i) {
    tmp[i] = a[i];
  }
  delete[] a;
  return tmp;
}

int* Resize(int *a, int oldSize, int newSize) {
  int i;
  int *tmp = new int[newSize];
  for (i = 0; i < min(oldSize, newSize); ++i) {
    tmp[i] = a[i];
  }
  delete[] a;
  return tmp;
}

int min(int a, int b) {
  if (a > b)
    return b;
  return a;
}
int StringTimeToMin(string time) {
  int i = 0, j = 0;
  int res = 0;
  int hour = 0;
  while (time[i++] != '\0');  // count num of symbols
  i -= 2;
  while (time[i] != ':') {
    res += (int)(time[i] - '0') * pow(10, j);
    j++;
    i--;
  }
  j = 0;
  i--;
  while (i != -1) {
    hour += (int)(time[i] - '0') * pow(10, j);
    j++;
    i--;
  }
  res += hour * 60;
  return res;
}

void StringDateToIntArr(string date, int* arr) {
  int i, j, k;
  i = j = 0;
  for (i; i < 3; ++i)
    arr[i] = 0;
  while (date[i++] != '\0');  // count num of symbols
  i -= 2;
  for (int k = 2; k > -1; --k) {
    while (date[i] != '.') {
      arr[k] += (int)(date[i] - '0') * pow(10, j);
      i--;
      j++;
      if (i == -1)
        break;
    }
    if (i == -1)
      break;
    i--;
    j = 0;
  }
}

int toInt(string number) {
  int len = number.length() - 1;
  int i, j;
  int answer = 0;
  for (i = len, j = 0; i > -1; --i, j++)
    answer += (int)(number[i] - '0') * pow(10, j);
  return answer;
}
