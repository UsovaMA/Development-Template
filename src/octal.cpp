
#include "octal.h"
#include <cassert>

int add(int x, int y) {
  return x + y;
}

char ToHex(int num);
int whatBigger(int a, int b);
int whatLowwer(int a, int b);

Octal Octal::operator=(const Octal &c) {
  int i;
  size = c.size;
  num = new unsigned char[size];
  for (i = 0; i < size; ++i) {
    num[i] = c.num[i];
  }
  return *this;
}

Octal Octal::operator+(const Octal &c) {
  int perenos = 0;
  int _size, i, length;
  int flag = 0;
  int *tmp;
  _size = 0;
  length = 0;
  // считаем кол-во цифр

  Octal tmpHex("0", whatBigger(size, c.size) + 1);
  Octal res("0", whatBigger(size, c.size) + 1);
  length = whatBigger(size, c.size);
  if (size > c.size) {
    for (i = 0; i < c.size; ++i)
      tmpHex.num[i] = c.num[i];
    flag = 1;
  }
  else {
    for (i = 0; i < size; ++i)
      tmpHex.num[i] = num[i];
    flag = 2;
  }
  // на 1 больше, чтобы не было проблем с перемолнением
  tmp = new int[length + 1];
  for (i = 0; i < length; ++i) {
    if (flag == 2) {
      if (tmpHex.num[i] > 57)
        tmp[i] = int(tmpHex.num[i] - 55);
      else
        tmp[i] = int(tmpHex.num[i] - 48);
    }
    else {
      if (num[i] > 57)
        tmp[i] = int(num[i] - 55);
      else
        tmp[i] = int(num[i] - 48);
    }
    if (flag == 1) {
      if (tmpHex.num[i] > 57)
        tmp[i] += int(tmpHex.num[i] - 55);
      else
        tmp[i] += int(tmpHex.num[i] - 48);
    }
    else {
      if (c.num[i] > 57)
        tmp[i] += int(c.num[i] - 55);
      else
        tmp[i] += int(c.num[i] - 48);
    }
    if (perenos)
      ++tmp[i];
    perenos = 0;
    if (perenos && i + 1 == _size)
      perenos = 1;
    if (tmp[i] > 15) {
      perenos = 1;
      tmp[i] = tmp[i] % 16;
    }
    if (tmp[i] > 9)
      res.num[i] = ToHex(tmp[i]);
    else
      res.num[i] = char(tmp[i] + 48);
  }
  return res;
}

char ToHex(int num) {
  switch (num) {
  case 10:
    return 'A';
    break;
  case 11:
    return 'B';
    break;
  case 12:
    return 'C';
    break;
  case 13:
    return 'D';
    break;
  case 14:
    return 'E';
    break;
  case 15:
    return 'F';
    break;
  default:
    return '-';
    break;
  }
}

int whatBigger(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int whatLowwer(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}

Octal Octal::operator-(const Octal &c) {
  // сделано на основе сложения
  // если первое число больше, то просиходит переполнение (по красоте)
  int perenos = 0;
  int _size, i, length, temp;
  int flag = 0;
  int *tmp;
  _size = 0;
  length = 0;
  // считаем кол-во цифр

  Octal tmpHex("0", whatBigger(size, c.size) + 1);
  Octal res("0", whatBigger(size, c.size) + 1);
  length = whatBigger(size, c.size);
  if (size > c.size) {
    for (i = 0; i < c.size; ++i)
      tmpHex.num[i] = c.num[i];
    flag = 1;
  }
  else {
    for (i = 0; i < size; ++i)
      tmpHex.num[i] = num[i];
    flag = 2;
  }
  // на 1 больше, чтобы не было проблем с перемолнением
  tmp = new int[length + 1];
  for (i = 0; i < length; ++i) {
    if (flag == 2) {
      if (tmpHex.num[i] > 57)
        tmp[i] = int(tmpHex.num[i] - 55);
      else
        tmp[i] = int(tmpHex.num[i] - 48);
    }
    else {
      if (num[i] > 57)
        tmp[i] = int(num[i] - 55);
      else
        tmp[i] = int(num[i] - 48);
    }
    if (flag == 1) {
      if (tmpHex.num[i] > 57)
        tmp[i] -= int(tmpHex.num[i] - 55);
      else
        tmp[i] -= int(tmpHex.num[i] - 48);
    }
    else {
      if (c.num[i] > 57)
        tmp[i] -= int(c.num[i] - 55);
      else
        tmp[i] -= int(c.num[i] - 48);
    }
    if (perenos)
      --tmp[i];
    perenos = 0;
    if (perenos && i + 1 == _size)
      perenos = 1;
    if (tmp[i] < 0) {
      perenos = 1;
      tmp[i] += 16;
    }
    if (tmp[i] > 9)
      res.num[i] = ToHex(tmp[i]);
    else
      res.num[i] = char(tmp[i] + 48);
  }
  return res;
}

bool Octal::operator==(const Octal &c) {
  int _size = whatLowwer(size, c.size);
  int i, flag = 0;
  if (_size == size)
    flag = 1;
  for (i = 0; i < _size; ++i)
    if (num[i] != c.num[i])
      return false;
  if (flag) {
    for (i; i < c.size; ++i)
      if (c.num[i] != '0')
        return false;
  }
  else {
    for (i; i < size; ++i)
      if (num[i] != '0')
        return false;
  }
  return true;  // если дошли сюда, то числа равны
}

bool Octal::operator<(const Octal &c) {
  int _size = whatLowwer(size, c.size);
  int i, flag = 0, flag2 = 0;
  if (_size == size)
    flag = 1;
  if (c.size == size) {
    for (i = _size - 2; i > 0; --i)
      if (num[i] > c.num[i])
        return false;
  } else {
    for (i = 0; i < _size; ++i)
      if (num[i] > c.num[i])
        flag2 = 1;
    if (flag2) {
      if (flag) {
        // если нашли в массиве что-то != 0 то он больше
        for (i; i < c.size; ++i)
          if (c.num[i] != '0')
            return true;
        return false;
      }
      else {
        for (i; i < size; ++i) {
          if (num[i] != '0')
            return false;
          return true;
        }
      }
    } else {
      if (!flag) {  // если число, которе должно быть меньше длиннее, то остальные
    // его разряды должны быть равны 0
        for (i; i < size; ++i) {
          if (num[i] != '0')
            return false;
        }
      }
    }
  }
  return true;
}

bool Octal::operator>(const Octal &c) {
  int _size = whatLowwer(size, c.size);
  int i, flag = 0, flag2 = 0;
  if (_size == size)
    flag = 1;
  if (c.size == size) {
    for (i = _size - 2; i > 0; --i)
      if (num[i] < c.num[i])
        return false;
  } else {
    for (i = 0; i < _size; ++i)
      if (num[i] < c.num[i])
        flag2 = 1;
    if (flag2) {
      if (flag) {
        // если нашли в массиве что-то != 0 то он больше
        for (i; i < c.size; ++i)
          if (c.num[i] != '0')
            return false;
        return true;
      } else {
        for (i; i < size; ++i) {
          if (num[i] != '0')
            return true;
        return false;
        }
      }
    }
  }              
  return true;
}

bool operator<(const Octal &c1, const Octal &c2) {
  int _size = whatLowwer(c1.size, c2.size);
  int i, flag = 0;
  if (_size == c1.size)
    flag = 1;
  for (i = 0; i < _size; ++i) {
    if (c1.num[i] > c2.num[i])
      return false;
  }
  if (!flag) {  // если число, которе должно быть меньше длиннее, то остальные
    // его разряды должны быть равны 0
    for (i; i < c1.size; ++i) {
      if (c1.num[i] != '0')
        return false;
    }
  }
  return true;  // если дошли сюда, то числа равны

}

bool operator>(const Octal &c1, const Octal &c2) {
  int _size = whatLowwer(c1.size, c2.size);
  int i, flag = 0;
  if (_size == c1.size)
    flag = 1;
  for (i = 0; i < _size; ++i) {
    if (c1.num[i] < c2.num[i])
      return false;
  }
  if (flag) {  // если число, которе должно быть меньше длиннее, то остальные
    // его разряды должны быть равны 0
    for (i; i < c2.size; ++i) {
      if (c2.num[i] != '0')
        return false;
    }
  }
  return true;
}



bool operator==(const Octal &c1, const Octal &c2) {
  int _size = whatLowwer(c1.size, c2.size);
  int i, flag = 0;
  if (_size == c1.size)
    flag = 1;
  for (i = 0; i < _size; ++i) {
    if (c1.num[i] != c2.num[i])
      return false;
  }
  if (flag) {
    for (i; i < c2.size; ++i) {
      if (c2.num[i] != '0')
        return false;
    }
  }
  else {
    for (i; i < c1.size; ++i) {
      if (c1.num[i] != '0')
        return false;
    }
  }
  return true;  // если дошли сюда, то числа равны
}

unsigned char& Octal::operator[](const int index) {
  if (index < 0)  // защита от выхода из диапазона
    throw logic_error("Input error: index cannot be negative value.");
  if (index >= this->size)
    throw out_of_range("Input error: index is out of range.");
  return num[index];
}


std::ostream& operator<< (std::ostream &out, const Octal &c) {
  int i;
  i = c.size - 1;
  while (c.num[i] == '0')
    --i;
  if (i == -1)
    out << '0';
  for (i; i >= 0; --i)
    out << c.num[i];
  out << endl;
  return out;
}

// странно, но из-за этого не хочет работать чтение из файла, говорит, что
// не может определиться, какой оператор ему исользовать
/*
std::istream& operator>> (std::istream &in, Octal &c) {
  string number;
  int i = 0, j;
  cin >> number;
  while (number[i] != '\0')
    ++i;
  c.size = i;
  for (i = c.size - 1, j = 0; i >= 0; --i, j++) {
    c.num[i] = number[j];
  }
  return in;
}
*/
// ввод/вывод в файл

std::ofstream& operator<<(std::ofstream &ofs, const Octal &c) {
  int i = c.size - 1;
  while (i != -1)
    ofs << c.num[i--];
  return ofs;
}

std::ifstream& operator>>(std::ifstream &ifs, const Octal &c) {
  int i = c.size - 1;
  char symbol;
  while (ifs >> symbol || i != -1)
    c.num[i--] = symbol;
  return ifs;
}
