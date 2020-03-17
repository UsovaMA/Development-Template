#include"Tasc_2.h"

ostream& operator<<(ostream& stream, const Octal& c);
istream& operator>>(istream& stream, Octal& c);
Octal::Octal() {
  dec = 0;
  size = 0;
}
Octal::~Octal() {
  delete[] dec;
  size = 0;
}
Octal::Octal(const Octal& c) {
  dec = c.dec;
  size = c.size;
}
Octal::Octal(const char* get) {

  size = strlen(get);
  dec = new unsigned char[size];
  for (int i = size - 1; i >= 0; i--, get++)
  {
    dec[i] = *get;
  }
}
Octal& Octal::operator=(const Octal& c) {
  (*this).dec = c.dec;
  (*this).size = c.size;
  return *this;
}
bool Octal::operator==(const Octal& c) {
  bool res;
  for (int i = 0; (i < size) && (i < c.size) && (res = true); i++) {
    if (dec[i] == c.dec[i]) {
      res = true;
    }
    else {
      res = false;
    }
    return res;
  }
}
Octal Octal::operator+(const Octal& c) {
  Octal res;
  unsigned char k = 0;
  res.size = (size < c.size) ? c.size : size;
  for (int i = 0; i < res.size; i++) {
    res.dec[i] = dec[i] + c.dec[i] + k;
    k = 0;
    if (res.dec[i] > 57) {
      res.dec[i] = fmod(res.dec[i], 10);
      k = 1;
    }
  }
  return res;
}
ostream& operator<<(ostream& stream, const Octal& c) {
  for (int i = c.size - 1; i < c.size; --i)
  {
    stream << c.dec[i];
  }
  return stream;
}
istream& operator>>(istream& stream, Octal& c) {
  for (int i = 0; i < c.size; i++)
  {
    stream >> c.dec[i];
  }
  return stream;
}
