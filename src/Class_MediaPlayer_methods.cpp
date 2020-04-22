#include "Class_MediaPlayer.hpp"

// Реализация стандартных конструкторов

Song::Song() {
	Name_of_song = "";
	Author_of_song = "";
	Author_of_music = "";
	Name_of_singer = "";
	Name_of_album = "";
	Date_of_release = "";
}

Song::Song(string a, string b, string c, string d, string e, string f) {
	Name_of_song = a;
	Author_of_song = b;
	Author_of_music = c;
	Name_of_singer = d;
	Name_of_album = e;
	Date_of_release = f;
}

MediaPlayer::MediaPlayer() {
	size = 0;
	arr = new Song[size];
}

MediaPlayer::MediaPlayer(const Song a) {
	size = 1;
	arr = new Song[size];
	arr[0] = a;
}


// Реализация методов класса и дополнительных функций

void Song::show_song_info() {
	cout << "Name of song: " << get_Name_of_song() << endl;
	cout << "Author of song: " << get_Author_of_song() << endl;
	cout << "Author of music: " << get_Author_of_music() << endl;
	cout << "Name of singer: " << get_Name_of_singer() << endl;
	cout << "Name of album: " << get_Name_of_album() << endl;
	cout << "Date of release: " << get_Date_of_release() << endl << endl;;
}

void MediaPlayer::add_new_song(string a, string b, string c, string d, string e, string f) {
	if (size == 0) {
		size = 1;
		arr = new Song[size];
		arr[0] = Song(a, b, c, d, e, f);
		return;
	}
	size += 1;
	Song *tmp;
	tmp = new Song[size - 1];
	for (int i = 0; i < size - 1; ++i) {
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = new Song[size];
	for (int i = 0; i < size - 1; ++i) {
		arr[i] = tmp[i];
	}
	delete[] tmp;
	arr[size - 1] = Song(a, b, c, d, e, f);
	
	for (int i = 0; i < size - 1; ++i) {
		for (int j = (size - 1); j > i; --j) {
			if (arr[j - 1].get_Name_of_song() > arr[j].get_Name_of_song()) {
				Song temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void Song::set_Name_of_song(string a) {
	Name_of_song = a;
}

void Song::set_Author_of_music(string a) {
	Author_of_music = a;
}

void Song::set_Name_of_singer(string a) {
	Name_of_singer = a;
}

void Song::set_Name_of_album(string a) {
	Name_of_album = a;
}

void Song::set_Date_of_release(string a) {
	Date_of_release = a;
}

void Song::set_Author_of_song(string a) {
	Author_of_song = a;
}

int MediaPlayer::index_of_Song_name(string a) {
	for (int i = 0; i < size; ++i) {
		if (arr[i].get_Name_of_song() == a) return i;
	}
}

int MediaPlayer::index_of_Song_name_and_singer(string a, string b) {
	for (int i = 0; i < size; ++i) {
		if (arr[i].get_Name_of_song() == a && arr[i].get_Name_of_singer() == b) {
			cout << "Song was found" << endl;
			return i;
		}
	}
	cout << "Song wasnt found" << endl;
	return -1;
}

void MediaPlayer::song_of_Author_of_song(string a) {
	for (int i = 0; i < size; ++i) {
		if (arr[i].get_Author_of_song() == a) arr[i].show_song_info();
	}
}

void MediaPlayer::song_of_Author_of_music(string a) {
	for (int i = 0; i < size; ++i) {
		if (arr[i].get_Author_of_music() == a) arr[i].show_song_info();
	}
}

void MediaPlayer::song_of_singer(string a) {
	for (int i = 0; i < size; ++i) {
		if (arr[i].get_Name_of_singer() == a) arr[i].show_song_info();
	}
}

void MediaPlayer::delete_song(string a, int index) {
	Song *tmp;
	for (int i = index; i < size - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	tmp = new Song[size - 1];
	for (int i = 0; i < size - 1; ++i) {
		tmp[i] = arr[i];
	}
	delete[] arr;
	size--;

	arr = new Song[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = tmp[i];
	}
	delete[]tmp;
}

void MediaPlayer::set_Data_to_file() {
	ofstream file;
	file.open("C://Data.txt", ios::app);
	if (!file.is_open()) cout << "Cant open file" << endl;
	for (int i = 0; i < size; ++i) {
		file << "Название песни: " << arr[i].get_Name_of_song() << endl;
		file << "Автор песни: " << arr[i].get_Author_of_song() << endl;
		file << "Автор музыки: " << arr[i].get_Author_of_music() << endl;
		file << "Исполнитель: " << arr[i].get_Name_of_singer() << endl;
		file << "Название альбома: " << arr[i].get_Name_of_album() << endl;
		file << "Дата релиза: " << arr[i].get_Date_of_release() << endl;
		file << endl;
		file.flush();
	}
	cout << "The data is recorded!" << endl;
	file.close();
}

void MediaPlayer::get_Data_from_file() {
	ifstream file;
	file.open("C://Data.txt", ios::in);
	while (!file.eof) {
		
	}
}

