// Copyright free James-Bolt 2020

#include "Class_MediaPlayer.hpp"

int main() {
	setlocale(LC_ALL, "Russian");

	int index;
	int number;
	string a, b, c, d, e, f;
	MediaPlayer mass;

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
		cin >> number;
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
			break;
		case 4:
			cout << "Введите имя автора, чьи песни вы хотите найти: ";
			cin >> a;
			break;
		case 5:
			cout << "Введите имя композитора, чьи песни вы хотите найти: ";
			cin >> a;
			break;
		case 6:
			cout << "Введите имя исполнителя, чьи песни вы хотите найти: ";
			cin >> a;
			break;
		case 7:
			cout << mass.size << endl;
			break;
		case 8:

			break;
		case 9:
			break;
		case 10:
			break;
		}
		for (int i = 0; i < mass.size; ++i) {
			mass.arr[i].show_song_info();
		}
	}

	return 0;
}