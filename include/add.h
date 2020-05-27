#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>   
using namespace std;

class Polynom
{
private:
    int high, low;
public:
    int n; //������� ��������
    double* koef; //��������� �� ������ ������������� �������� koef[i] - ����������� ��� i-� �������
    Polynom();
    Polynom(int an);//����������� � �����������
    Polynom(const Polynom&); //�����������
    ~Polynom();//����������
    bool operator==(const Polynom& c) {
        return (low == c.low && high == c.high);
    }
    friend bool operator==(const Polynom& c1, const Polynom& c2) {
        return (c1.low == c2.low && c1.high == c2.high);
    }
    int getn(); //������� ��������� ������� ��������
    double getkoef(int); //������� ��������� ������������ ��� i-� �������
    Polynom operator+(const Polynom&);   //�������� �������� ���� ���������
    Polynom operator-(const Polynom&);   //�������� ��������� ���� ���������
    Polynom operator*(const Polynom&);// �������� ���������
    Polynom operator=(const Polynom&);   //�������� ������������
    Polynom derivative();//�����������

    friend ostream& operator<< (ostream& s, const Polynom& c); // ������������� �������� ������
    friend istream& operator >> (istream& s, Polynom& c); // ������������� �������� �����
    double& operator()(int i)
    {
        return koef[i];
    }
};
