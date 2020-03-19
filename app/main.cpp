#include <iostream>
#include "MatrixClass.h"
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

int** generator(int size) {
  int**toGen = new int*[size];
  for (int i = 0; i < size; ++i) {
    toGen[i] = new int[size];
  }
  mt19937 generator(chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
  uniform_int_distribution<> uid(0, 100);
  for (int j = 0; j < size; ++j) {
    for (int i = 0; i < size; ++i) {
      toGen[j][i] = uid(generator);
    }
  }
  return toGen;
}

void print(int**arr, int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << "\n" << "";
  }
}


int main() {
  //�������� ������
  Matrix a = Matrix(5);
  Matrix b = Matrix(4);

  //������������� ��������� �������� (����������� �������)
  a.init(5, generator(5));
  //������������� ������
  b.init();
  //������ ������ �������
  Matrix c = Matrix(a);

  //����� ���� ������
  Matrix d = a + c;
  d += a;

  //����������
  int number = d(2, 2);
  //d(6,6) - ������� ������ out_of_range

  //����� ������� � �����
  cout << d;
  //����� ������� � ����
  d.out("Dmatrix.txt");

  //���������� ������� ������ ����
  Matrix e = Matrix::in("Dmatrix.txt");
  e(0, 0) = 100; e(1, 1) = 100;
  e.out("Ematrix.txt");

  //��� �� ��������� �����
  fstream someFile;
  someFile.open("Ematrix.txt", fstream::in);
  if (someFile.is_open()) {
    Matrix k = Matrix();
    someFile >> k;
  }

  //��������� ������ (range_error � ������ �������������� �������� ������)
  Matrix f = d * e;
  f *= a;

  //��������� �� ������
  Matrix g = f * 3;
  f *= 2;

  //������������ ������������
  if (f.diagonalPrevalence()) std::cout << "f matrix has diagonal prevalence" << std::endl;

  //����������������
  a.transpose();

  return 0;
}
