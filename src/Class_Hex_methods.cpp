#include "Class_Hex.hpp"

// Реализация стандартных конструкторов

Hex::Hex() {
	size = 1;
	Number = new unsigned char[size];
	Number[0] = 0;
}

Hex::Hex(const Hex &a) {
	size = a.size;
	Number = new unsigned char[size];
	for (int i = 0; i < size; ++i) {
		Number[i] = a.Number[i];
	}
}

Hex::Hex(string number, int size_) {
	size = size_;
	Number = new unsigned char[size];
	for (int j = 0, i = size - 1; i >= 0; --i, ++j) {
		Number[j] = number[i];
	}
}

// Реализация методов класса и вспомогательных функций

unsigned char& Hex::operator[](const int index) {
	if (index < 0 || index >= this->size) throw std::out_of_range("Out of range!");
	return Number[index];
}

char* ConvertCC(string x, int fromCC, int toCC) {
	char *abc = "0123456789ABCDEFGHIJKLMNOPQESTUVWXYZ";
	char buf[255] = { 0 };
  char *result;
	int i, k, ten = 0, stp = 1;
	for (i = 0; x[i]; i++);
	for (; i; i--) {
		for (k = 0; abc[k] != x[i - 1] && k < 36; k++);
		ten += k * stp;
		stp *= fromCC;
	}
	k = 0;
	while (ten) {
		i = ten % toCC;
		buf[k++] = abc[i];
		ten /= toCC;
	}
	result = new char[k + 1];
	for (i = 0; k; i++) result[i] = buf[--k];
	result[i] = 0;
	return result;
}

Hex Hex::operator+(const Hex &number) {
	Hex res;
	int str_size;
	string converted_1 = reinterpret_cast<char*>(this->Number);
	string converted_2 = reinterpret_cast<char*>(number.Number);
	converted_1.erase(this->size);
	converted_2.erase(number.size);
	reverse(converted_1.begin(), converted_1.end());
	reverse(converted_2.begin(), converted_2.end());
	string a = ConvertCC(converted_1, 16, 10);
	string b = ConvertCC(converted_2, 16, 10);
	int a_ = stoi(a);
	int b_ = stoi(b);
	int sum = a_ + b_;
	a = to_string(sum);
	b = ConvertCC(a, 10, 16);
	str_size = b.size();
	res.size = str_size;
	res.Number = new unsigned char[res.size];
	for (int j = 0, i = res.size - 1; i >= 0; --i, ++j) {
		res.Number[j] = b[i];
	}
	return res;
}

Hex Hex::operator-(const Hex &number) {
	Hex res;
	int str_size;
	string converted_1 = reinterpret_cast<char*>(this->Number);
	string converted_2 = reinterpret_cast<char*>(number.Number);
	converted_1.erase(this->size);
	converted_2.erase(number.size);
	reverse(converted_1.begin(), converted_1.end());
	reverse(converted_2.begin(), converted_2.end());
	string a = ConvertCC(converted_1, 16, 10);
	string b = ConvertCC(converted_2, 16, 10);
	int a_ = stoi(a);
	int b_ = stoi(b);
	int dif = a_ - b_;
	if (dif <= 0) {
		res.size = 1;
		res.Number = new unsigned char[res.size];
		res.Number[0] = '0';
		cout << "The difference is less than zero" << endl;
		return res;
	}
	a = to_string(dif);
	b = ConvertCC(a, 10, 16);
	str_size = b.size();
	res.size = str_size;
	res.Number = new unsigned char[res.size];
	for (int j = 0, i = res.size - 1; i >= 0; --i, ++j) {
		res.Number[j] = b[i];
	}
	return res;
}

Hex Hex::operator=(const Hex &number) {
	size = number.size;
	Number = new unsigned char[size];
	for (int i = 0; i < size; ++i) {
		Number[i] = number.Number[i];
	}
	return *this;
}

bool operator<(const Hex &number1, const Hex &number2) {
	string converted_1 = reinterpret_cast<char*>(number1.Number);
	string converted_2 = reinterpret_cast<char*>(number2.Number);
	converted_1.erase(number1.size);
	converted_2.erase(number2.size);
	reverse(converted_1.begin(), converted_1.end());
	reverse(converted_2.begin(), converted_2.end());
	string a = ConvertCC(converted_1, 16, 10);
	string b = ConvertCC(converted_2, 16, 10);
	int a_ = stoi(a);
	int b_ = stoi(b);
	if (a_ < b_) return true;
	return false;
}

bool operator>(const Hex &number1, const Hex &number2) {
	string converted_1 = reinterpret_cast<char*>(number1.Number);
	string converted_2 = reinterpret_cast<char*>(number2.Number);
	converted_1.erase(number1.size);
	converted_2.erase(number2.size);
	reverse(converted_1.begin(), converted_1.end());
	reverse(converted_2.begin(), converted_2.end());
	string a = ConvertCC(converted_1, 16, 10);
	string b = ConvertCC(converted_2, 16, 10);
	int a_ = stoi(a);
	int b_ = stoi(b);
	if (a_ > b_) return true;
	return false;
}

bool operator==(const Hex &number1, const Hex &number2) {
	string converted_1 = reinterpret_cast<char*>(number1.Number);
	string converted_2 = reinterpret_cast<char*>(number2.Number);
	converted_1.erase(number1.size);
	converted_2.erase(number2.size);
	reverse(converted_1.begin(), converted_1.end());
	reverse(converted_2.begin(), converted_2.end());
	string a = ConvertCC(converted_1, 16, 10);
	string b = ConvertCC(converted_2, 16, 10);
	int a_ = stoi(a);
	int b_ = stoi(b);
	if (a_ == b_) return true;
	return false;
}

std::ostream& operator<<(ostream &out, const Hex &Hex) {
	for (int i = Hex.size - 1; i >= 0; --i) {
		out << Hex.Number[i];
	}
	out << endl;
	return out;
}

std::ofstream& operator<<(ofstream& f, const Hex &number) {
	int i = number.size - 1;
	while (i != -1) {
		f << number.Number[i--];
	}
	return f;
}

std::ifstream& operator>>(ifstream& f, const Hex &number) {
	int i = number.size - 1;
	char symbol;
	while (f >> symbol || i != -1)
		number.Number[i--] = symbol;
	return f;
}
