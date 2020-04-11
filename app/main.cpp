#include "polinom.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void main()
{
    setlocale(LC_ALL, "");
    int n, m;
    cout << "������� ������� ��������:" << '\n';
    cout << "N = ";
    cin >> n;
    Polynom A(n), D, K, Y;
    cout << "������� ����������� ��������:" << '\n';
    cin >> A;
    cout << setw(17) << "������� �:" << setw(5) << A << '\n';
    cout << setw(17) << "����� ������� D=A+A:" << setw(5) << (D = A + A) << '\n';
    cout << setw(17) << "����� ������� K=A-A:" << setw(5) << (K = A - A) << '\n';
    cout << setw(17) << "����������� �� ��������:" << setw(5) << A.derivative() << '\n';
    cout << setw(17) << "����� ������� Y=A*A:" << setw(5) << (Y = A * A) << '\n';
    system("pause");
}
