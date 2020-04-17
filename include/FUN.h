#pragma once
#ifndef FUN_C_H_
#define FUN_C_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Contacts.h"
using namespace std;

bool ver_one_word(string str);
bool ver_three_word(string str);
bool ver_let_char(char a);
bool checkFIO(string f1, string i1, string o1, string f2, string i2, string o2);
string breakdown1(string str);
string breakdown2(string str);
string breakdown3(string str);

int high_letter(char a1, char a2);
int high_name(string str1, string str2);

void swap_con(Contact& a, Contact& b);

void exampleIn();
#endif  // FUN_C_H_
