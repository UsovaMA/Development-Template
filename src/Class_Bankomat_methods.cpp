#include "Class_Bankomat.hpp"

Client::Client() {
	this->Balance = 0;
	this->Card_number = "";
	this->Pin_code = "";
	this->Full_name = "";
	this->Status = 1;
}

Client::Client(int Balance, int Card_num, string Pin_code, string Full_name) {
	if (Card_num > 9999) throw logic_error("Номер карты не может превышать 9999.");
	this->Balance = Balance;
	this->Pin_code = Pin_code;
	string Card_num_tmp;
	if (Card_num / 10 == 0) {
		Card_num_tmp = "000" + to_string(Card_num);
	} else if (Card_num / 100 == 0) {
		Card_num_tmp = "00" + to_string(Card_num);
	} else if (Card_num / 1000 == 0) {
		Card_num_tmp = "0" + to_string(Card_num);
	} else Card_num_tmp = to_string(Card_num);
	this->Card_number = Card_num_tmp;
	this->Full_name = Full_name;
	this->Status = 1;
}

void Client::set_Card_number(string Card_number) {
	this->Card_number = Card_number;
}

void Client::set_Balance(int Balance) {
	this->Balance += Balance;
}

void Client::set_Pin_code(string Pin_code) {
	this->Pin_code = Pin_code;
}

void Client::set_Full_name(string Full_name) {
	this->Full_name = Full_name;
}

void Client::set_Status(int Status) {
	this->Status = Status;
}

ProcCenter::ProcCenter() {
	Clients.reserve(1);
}

Bankomat::Bankomat() {
	this->rub_100 = 1600;
	this->rub_200 = 1600;
	this->rub_500 = 1600;
	this->rub_1000 = 1600;
	this->rub_2000 = 1600;
	this->rub_5000 = 1600;
	this->Card_num = 1;
}

Bankomat::Bankomat(int rub_100, int rub_200, int rub_500, int rub_1000, int rub_2000, int rub_5000) {
	if (rub_100 > 2000 || rub_200 > 2000 || rub_500 > 2000 || rub_1000 > 2000 || rub_2000 > 2000 || rub_5000 > 2000) throw logic_error("Емкость кассеты не более 2000 купюр");
	this->rub_100 = rub_100;
	this->rub_200 = rub_200;
	this->rub_500 = rub_500;
	this->rub_1000 = rub_1000;
	this->rub_2000 = rub_2000;
	this->rub_5000 = rub_5000;
	this->Card_num = 1;
}

void ProcCenter::add_new_client(string Pin_code, string Full_name) {
	this->Clients.push_back(Client(0, Card_num, Pin_code, Full_name));
	this->Card_num++;
}

void Bankomat::Accept_customer_card(string Card_number) {
	if (this->in_out != 1) {
		if (Find_customer(Card_number) != -1) {
			if (Clients[Find_customer(Card_number)].get_Status() == 0) {
				cout << "Ваша карта заблокирована!" << endl;
				return;
			}
			int tmp = 0;
			string Pin_code_tmp;
			for (int i = 0; i < Clients.size(); ++i) {
				if ((Card_number == Clients[i].get_Card_number()) && (Clients[i].get_Status() != 0)) {
					while (tmp < 3) {
						cout << "Введите пин код: ";
						cin >> Pin_code_tmp;
						tmp++;
						if (Pin_code_tmp == Clients[i].get_Pin_code()) {
							tmp = 0;
							cout << "Карта принята!" << endl;
							this->in_out = 1;
							return;
						}
						else cout << "Вы ввели неверный пин-код, попробуйте ещё раз!" << endl;
					}
					cout << "Вы три раза ввели неверный пин код, ваша карта заблокирована!" << endl;
					Clients[i].set_Status(0);
					return;
				}
			}
		}
		cout << "Вашей карты нет в базе клиентов." << endl << "Не забудьте забрать карту!" << endl;
		return;
	}
	cout << "В банкомат уже вставлена карта!" << endl;
}

int Bankomat::Find_customer(string Card_number) {
	for (int i = 0; i < Clients.size(); ++i) {
		if (Card_number == Clients[i].get_Card_number()) {
			return i;
		} else {
			return -1;
		}
	}
}

void Bankomat::Show_balance(string Card_number) {
	if (Find_customer(Card_number) != -1) {
		if (Clients[Find_customer(Card_number)].get_Status() == 0) {
			cout << "Ваша карта заблокирована!" << endl;
			return;
		} else if (this->in_out == 1) {
			cout << "Ваш баланс: " << Clients[Find_customer(Card_number)].get_Balance() << endl;
		} else cout << "В банкомат не вставлена карта!" << endl;
	}
}

void Bankomat::Accept_money(string Card_number, int money) {
	if (this->in_out == 1) {
		if (Find_customer(Card_number) != -1) {
			if (Clients[Find_customer(Card_number)].get_Status() == 0) {
				cout << "Ваша карта заблокирована!" << endl;
				return;
			} else if (rub_5000 < 2000 || rub_2000 < 2000 || rub_1000 < 2000 || rub_500 < 2000 || rub_200 < 2000 || rub_100 < 2000) {
				if (money % 100 == 0) {
					int tmp = money;
					while (money % 5000 >= 0 && money >= 5000 && rub_5000 < 2000) {
						rub_5000++;
						money -= 5000;
					}
					while (money % 2000 >= 0 && money >= 2000 && rub_2000 < 2000) {
						rub_2000++;
						money -= 2000;
					}
					while (money % 1000 >= 0 && money >= 1000 && rub_1000 < 2000) {
						rub_1000++;
						money -= 1000;
					}
					while (money % 500 >= 0 && money >= 500 && rub_500 < 2000) {
						rub_500++;
						money -= 500;
					}
					while (money % 200 >= 0 && money >= 200 && rub_200 < 2000) {
						rub_200++;
						money -= 200;
					}
					while (money % 100 >= 0 && money >= 100 && rub_5000 < 2000) {
						rub_100++;
						money -= 100;
					}
					if (money != 0) {
						cout << "Банкомат переполнен!" << endl << "Заберите оставшиеся деньги!" << endl;
						Clients[Find_customer(Card_number)].set_Balance(money);
						return;
					}	else {
						cout << "Деньги успешно зачислены на ваш счёт!" << endl;
						Clients[Find_customer(Card_number)].set_Balance(tmp);
						return;
					}
				} else {
					cout << "Допустимы только купюры номиналом 100, 200, 500, 1000, 2000, 5000!" << endl;
					return;
				}
			} else {
				cout << "Банкомат переполнен!" << endl;
				return;
			}
		}
	}
	cout << "В банкомат не вставлена карта!" << endl;
}

void Bankomat::Give_out_money(string Card_number, int money) {
	if (this->in_out == 1) {
		if (Find_customer(Card_number) != -1) {
			if (Clients[Find_customer(Card_number)].get_Status() == 0) {
				cout << "Ваша карта заблокирована!" << endl;
				return;
			} else if (money <= Clients[Find_customer(Card_number)].get_Balance()) {
				if (rub_5000 > 0 || rub_2000 > 0 || rub_1000 > 0 || rub_500 > 0 || rub_200 > 0 || rub_100 > 0) {
					if (money % 100 == 0) {
						int tmp = money;
						while (money % 5000 >= 0 && money >= 5000 && rub_5000 > 0) {
							rub_5000--;
							money -= 5000;
						}
						while (money % 2000 >= 0 && money >= 2000 && rub_2000 > 0) {
							rub_2000--;
							money -= 2000;
						}
						while (money % 1000 >= 0 && money >= 1000 && rub_1000 > 0) {
							rub_1000--;
							money -= 1000;
						}
						while (money % 500 >= 0 && money >= 500 && rub_500 > 0) {
							rub_500--;
							money -= 500;
						}
						while (money % 200 >= 0 && money >= 200 && rub_200 > 0) {
							rub_200--;
							money -= 200;
						}
						while (money % 100 >= 0 && money >= 100 && rub_5000 > 0) {
							rub_100--;
							money -= 100;
						}
						if (money != 0) {
							cout << "К сожалению, в банкомате закончились наличные!" << endl << "Не забудтье забрать полученные деньги, остальная часть останется на вашем счету." << endl;
							Clients[Find_customer(Card_number)].set_Balance(money - tmp);
							return;
						} else {
							cout << "Деньги успешно выданы, не забудьте их забрать!" << endl;
							Clients[Find_customer(Card_number)].set_Balance(-tmp);
							return;
						}
					} 	else {
						cout << "Банкомат выдаёт купюры номиналом 100, 200, 500, 1000, 2000, 5000!" << endl;
						return;
					}
				}
			} else {
				cout << "На вашем счету недостаточно средств!" << endl;
				return;
			}
		}
	}
	cout << "В банкомат не вставлена карта!" << endl;
}

void Bankomat::Return_customer_card() {
	this->in_out = 0;
	cout << "Карта возвращена, не забудьте её забрать!" << endl;
}
