#ifndef INCLUDE_SNAKEGAME_H_
#define INCLUDE_SNAKEGAME_H_

#include<iostream>
#include <windows.h>
#include <conio.h>
#include <deque>

class Snake
{
	const unsigned short DARK_BLUE = FOREGROUND_BLUE;
	const unsigned short BRIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;


	void setConsoleColour(unsigned short colour);//���� �������
	void setCursorPosition(int y, int x);//������� �������
	int EatAdd();//�������� ��� �� ����
	bool FindEl(int head);//����������� ������ � �����
	void PrintSnake();//��������� ����
	int Joy(char a);//����������
	bool StepBool(char a);//����������� ����
	void Step(char ar);//���


public:
	Snake();
	~Snake();
	void Start();//������
};

#endif  // INCLUDE_SNAKEGAME_H_
