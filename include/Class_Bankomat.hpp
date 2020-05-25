#ifndef INCLUDE_CLASS_BANKOMAT_HPP_
#define INCLUDE_CLASS_BANKOMAT_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <locale>

using namespace std;

class Client {
private:
	int Balance;
	string Pin_code;
	string Card_number;
	string Full_name;
	int Status;
public:
	Client();
	Client(int Balance, int Card_num, string Pin_code, string Full_name);

	void set_Balance(int Balance);
	void set_Pin_code(string Pin_code);
	void set_Card_number(string Card_number);
	void set_Full_name(string Full_name);
	void set_Status(int Status);

	const int get_Balance() const { return Balance; }
	const string get_Pin_code() const { return Pin_code; }
	const string get_Card_number() const { return Card_number; }
	const string get_Full_name() const { return Full_name; }
	const int get_Status() const { return Status; }


};

class ProcCenter {
protected:
	vector<Client> Clients;
	int Card_num;
public:
	ProcCenter();

	void add_new_client(string Pin_code, string Full_name);


};

class Bankomat:public ProcCenter {
private:
	int rub_100;
	int rub_200;
	int rub_500;
	int rub_1000;
	int rub_2000;
	int rub_5000;
	int in_out;
public:
	Bankomat();
	Bankomat(int rub_100, int rub_200, int rub_500, int rub_1000, int rub_2000, int rub_5000);

	void Accept_customer_card(string Card_number);
	int Find_customer(string Card_number);
	void Show_balance(string Card_number);
	void Accept_money(string Card_number, int money);
	void Give_out_money(string Card_number, int money);
	void Return_customer_card();
};


#endif INCLUDE_CLASS_BANKOMAT_HPP_
