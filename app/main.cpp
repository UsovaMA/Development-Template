// Copyright free James-Bolt 2020

#include "Class_MediaPlayer.hpp"

int main() {
	setlocale(LC_ALL, "Russian");

	int index;
	int number;
	string a, b, c, d, e, f, str;
	MediaPlayer mass;
	ifstream file;
	int tmp = 0;

	while (1) {
		cout << "Песенник:" << endl;
		cout << "1. Добавить песню" << endl;
		cout << "2. Изменить данные песни" << endl;
		cout << "3. Найти песню по назаванию и исполнителю" << endl;
		cout << "4. Выдать все песни заданного автора" << endl;
		cout << "5. Выдать все песни заданного композитора" << endl;
		cout << "6. Выдать все песни заданного исполнителя" << endl;
		cout << "7. Узнать текущее число песен" << endl;
		cout << "8. Удалить песню" << endl;
		cout << "9. Считать песенник из файла" << endl;
		cout << "10. Записать песенник в файл" << endl;
		cout << "11. Выйти из программы" << endl;
		cin >> number;
		cin.ignore();
		cout << endl;
		switch (number) {
		case 1:
			cout << "Название песни: ";
			cin >> a;
			cout << "Автор песни: ";
			cin >> b;
			cout << "Автор музыки: ";
			cin >> c;
			cout << "Исполнитель: ";
			cin >> d;
			cout << "Название альбома: ";
			cin >> e;
			cout << "Дата релиза: ";
			cin >> f;
			cout << endl;
			mass.add_new_song(a, b, c, d, e, f);
			break;
		case 2:
			cout << "Введите название песни, данные о которой вы хотите изменить: ";
			cin >> a;
			index = mass.index_of_Song_name(a);
			cout << index;
			cout << "Введите новые данные:"<< endl;
			cout << "Автор песни: ";
			cin >> b;
			cout << "Автор музыки: ";
			cin >> c;
			cout << "Исполнитель: ";
			cin >> d;
			cout << "Название альбома: ";
			cin >> e;
			cout << "Дата релиза: ";
			cin >> f;
			mass.arr[index].set_Author_of_song(b);
			mass.arr[index].set_Author_of_music(c);
			mass.arr[index].set_Name_of_singer(d);
			mass.arr[index].set_Name_of_album(e);
			mass.arr[index].set_Date_of_release(f);
			cout << endl;
			break;
		case 3:
			cout << "Введите название и исполнителя песни, которую вы хотите найти" << endl;
			cout << "Название песни: ";
			cin >> a;
			cout << "Исполнитель: ";
			cin >> b;
			cout << endl;
			index = mass.index_of_Song_name_and_singer(a, b);
			cout << "Информация о песни: " << endl;
			if(index != -1) mass.arr[index].show_song_info();
			cout << endl;
			break;
		case 4:
			cout << "Введите имя автора, чьи песни вы хотите найти: ";
			cin >> a;
			cout << endl;
			break;
		case 5:
			cout << "Введите имя композитора, чьи песни вы хотите найти: ";
			cin >> a;
			cout << endl;
			break;
		case 6:
			cout << "Введите имя исполнителя, чьи песни вы хотите найти: ";
			cin >> a;
			cout << endl;
			break;
		case 7:
			cout << mass.size << endl;
			break;
		case 8:
			cout << "Введите название песни, которую вы хотите удалить: ";
			cin >> a;
			index = mass.index_of_Song_name(a);
			mass.delete_song(a, index);
			cout << endl;
			break;
		case 9:
			file.open("C://Data.txt", ios::in);
			if (!file.is_open()) cout << "Cant open file" << endl;
			while (getline(file, str)) {
				tmp++;
				if (tmp == 1) {
					a = str.erase(0, 29);
				}
				if (tmp == 2) {
					b = str.erase(0, 23);
				}
				if (tmp == 3) {
					c = str.erase(0, 25);
				}
				if (tmp == 4) {
					d = str.erase(0, 24);
				}
				if (tmp == 5) {
					e = str.erase(0, 33);
				}
				if (tmp == 6) {
					f = str.erase(0, 23);
				}
				if (tmp == 7) {
					mass.add_new_song(a, b, c, d, e, f);
					tmp = 0;
				}
			}
			file.close();
			break;
		case 10:
			mass.set_Data_to_file();
			break;
		case 11:
			exit(1);
		}
		for (int i = 0; i < mass.size; ++i) {
			mass.arr[i].show_song_info();
		}
	}
	delete[] mass.arr;
	return 0;
}