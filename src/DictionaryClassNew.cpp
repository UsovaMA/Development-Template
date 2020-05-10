#include "..\include\DictionaryClassNew.h"
#include "..\include\DictionaryClassNew.h"
#include "..\include\DictionaryClassNew.h"
#include "..\include\DictionaryClassNew.h"
#include "..\include\DictionaryClassNew.h"
#include "..\include\DictionaryClassNew.h"
#include "..\include\DictionaryClassNew.h"
#include "..\include\DictionaryClassNew.h"
#include "..\include\DictionaryClassNew.h"
#include "..\include\DictionaryClassNew.h"
#include "..\include\DictionaryClassNew.h"
#include "..\include\DictionaryClassNew.h"
#include "..\include\DictionaryClassNew.h"
#include "DictionaryClassNew.h"

#include <string>
#include <vector>
#include <locale>
#include <iostream>
#include <fstream>
#include <Windows.h>

Words::Words() {
	word = "none";
	translate = "none";
}
Words::Words(string _word, string _translate) :word(_word),translate(_translate) { }
Words::Words(const Words& c) {
	word = c.word;
	translate = c.translate;
}
Words::~Words() {
	word = "";
	translate = "";
}
Dictionary::Dictionary() {
	book = nullptr;
	number = 0;
}
Dictionary::Dictionary(int number_, Words* book_) {
	book = new Words[number_];
	number = number_;
	for (int i = 0; i < number; i++) {
		book[i] = book_[i];
	}
}
Dictionary::Dictionary(const Dictionary& c) {
	book = new Words[c.number];
	number = c.number;
	for (int i = 0; i < number; i++) {
		book[i] = c.book[i];
	}
}
Dictionary::~Dictionary() {
	delete[] book;
	number = 0;
}

//методы 
void Dictionary::fill_mass_from_file() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::ifstream fs;

	fs.open("C:/temp1/book.txt", ios::in);

	if (!fs.is_open()) {
		std::cout << "Ошибка открытия файла!" << std::endl;
	}
	else {
		std::cout << "Файл успешно открыт\n" << std::endl;
		if (fs.peek() == EOF)
		{
			std::cout << "Файл пуст\n";
		}
		else
		{
			if (number != 0) {
				delete[]book;
				number = 0;
			}
			fs >> number;
			book = new Words[number];
			for (int i = 0; i < number; i++) {
				fs >> book[i].word;
				fs >> book[i].translate;
				std::cout << "Данные успешно считаны" << std::endl << std::endl;
			}
		}
	}
	fs.close();
}
void Dictionary::outputall() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	for (int i = 0; i < number; i++) {
		cout << number <<" "<< book[i].word <<" "<< book[i].translate << endl;
	}
}
void Dictionary::create(const Words &new_word) {
	Dictionary result;

	result.number = number + 1;
	result.book = new Words[number + 1];
	for (int i = 0; i < number; i++) {
		result.book[i] = book[i];
	}
	result.book[result.number - 1].word = new_word.word;
	result.book[result.number - 1].translate = new_word.translate;
	(*this) = result;
}
void Words::input_all_data() {
	cout << "Слово : ";
	cin >> word;
	cout << endl << "Перевод: ";
	cin >> translate;
}
void Dictionary::input_and_create() {
		Words new_word;
		new_word.input_all_data();        
		(*this).create(new_word);       
}
void Dictionary::change_translate(string word) {
	for (int i = 0; i <= number; i++) {
		if (book[i].word == word) {
			cout << "Введите новый перевод для выбранного слова: ";
			cin >> book[i].translate;
		}
	}
}
void Dictionary::input_and_change() {
		string new_word;
		cout << "Введите слово,перевод которого вы хотели бы изменить: ";
		cin >> new_word;
		(*this).change_translate(new_word);
}
string Dictionary::find_translate(string word) {
	for (int i = 0; i <= number; i++) {
		if (book[i].word == word) {
			return book[i].translate;
		}
	}
}
void Dictionary::input_and_find() {
	string new_word;
	cout << "Введите слово: ";
	cin >> new_word;
	cout << endl;
	cout<<"Перевод выбранного слова: "<<(*this).find_translate(new_word)<<endl;
}
bool Dictionary::find_word(string word) {
	for (int i = 0; i <= number; i++) {
		if (book[i].word == word) {
			return 1;
		}
	}
}
void Dictionary::find_find() {
	string new_word;
	cout << "Введите слово: ";
	cin >> new_word;
	if (find_word(new_word) == 1) {
		cout << "Данное слово имеется в словаре"<<endl;
	}
	else {
		cout << "Данного слова нет в словаре"<<endl;
	}
}
void Dictionary::return_number() {
	int count = number;
	cout << "Количество слов в словаре: " << count << endl;
}
void Dictionary::fill_file_from_mass() {
	int count;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream f("C:/temp1/book.txt", ios::out);
	if (f.is_open())
	{
		f << number << endl;
		for (int i = 0; i <= number - 1; i++) {
			f << book[i].word << endl;
			f << book[i].translate << endl;
		}
		f.close();
	}
	else
	{
		cout << "Ошибка при открывании файла";
	}

}

Dictionary& Dictionary::operator =(const Dictionary& c) {
	if (number != 0 && number != c.number) {
		delete[] book;
		number = 0;
		book = new Words[c.number];
	}
	number = c.number;
	for (int i = 0; i < number; i++) {
		book[i] = c.book[i];
	}

	return *this;
}