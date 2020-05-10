#ifndef INCLUDE_DICTIONARYCLASSNEW_H_
#define INCLUDE_DICTIONARYCLASSNEW_H_

#include <iostream>
#include <fstream>
#include <string>


using namespace std;
class Words {
	friend class Dictionary;
public:
	string Words::getWord() {
		Words res;
		res.word = this->word;
		return res.word;
	}
	string Words::getTranslate() {
		Words res;
		res.translate = this->translate;
		return res.translate;
	}
	friend bool operator==(const Words& a, const Words& c) {
		bool res = 0;
		if ((a.word == c.word) && (a.translate == c.translate)) {
			res = 1;
		}
		return res;
	}
	Words();
	Words(const Words& v);
	Words(string _word, string _translate);

	~Words();
	void input_all_data();
private:
	string word;
	string translate;
};
class Dictionary {
	friend class Words;
public:
	int Dictionary::getNumber() {
		Dictionary res;
		res.number = this->number;
		return res.number;
	}
	Dictionary();
	Dictionary(int number_, Words* book);
	Dictionary(const Dictionary& c);
	Dictionary& operator =(const Dictionary& c);
	~Dictionary();
	void fill_mass_from_file();//
	void outputall();//
	void create(const Words & new_word);//
	void input_and_create();
	void input_and_change();
	void input_and_find();
	bool find_word(string word);
	void find_find();
	void return_number();
	void fill_file_from_mass();
	string find_translate(string word);
	void change_translate(string word);///
private:
	int number;
	Words* book;
};

#endif  // INCLUDE_DICTIONARYCLASSNEW_H_
