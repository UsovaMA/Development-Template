// Copyright free James-Bolt 2020

#include "Class_Bankomat.hpp"

int main() {
	setlocale(LC_ALL, "Rus");

	Bankomat a;
	a.add_new_client("0000", "Фролов Глеб Витальевич");
	a.Accept_customer_card("0002");
	a.Accept_customer_card("0001");
	a.Find_customer("0001");
	a.Accept_money("0001", 700);
	a.Show_balance("0001");
	a.Give_out_money("0001", 5000);
	a.Show_balance("0001");
	a.Return_customer_card();
	return 0;
}
