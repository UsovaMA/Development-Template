#ifndef INCLUDE_COMPLEX_H_
#define INCLUDE_COMPLEX_H_

#include <iostream>
#include <fstream>

class Complex {
public:
  Complex();
  Complex(const Complex &c);
  Complex(double _re, double _im);
  Complex(double d);

  ~Complex();

  void output();
  Complex Add(const Complex& c);

  Complex& operator=(const Complex& c);

  bool operator==(const Complex& c);

  friend bool operator==(const Complex& left, const Complex& right) {
	  if (left.re == right.re && left.im == right.im) return true;
	  else return false;
  }

  bool operator!=(const Complex& c);

  Complex operator+(const Complex& c);
  Complex operator-(const Complex& c);
  Complex operator*(const Complex& c);
  Complex operator/(const Complex& c);

  friend Complex operator+(double d, const Complex& c);
  friend Complex operator-(double d, const Complex& c);
  friend Complex operator*(double d, const Complex& c);
  friend Complex operator/(double d, const Complex& c);

  friend std::ostream& operator<<(std::ostream& stream, const Complex& c);
  friend std::istream& operator>>(std::istream& stream, Complex& c);

private:
  double re;
  double im;
};

#endif  // INCLUDE_COMPLEX_H_
