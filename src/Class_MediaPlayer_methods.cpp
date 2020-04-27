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
	for (int i = 0; i < f.size() - 1; ++i) {
		if ((f[i] < 0 && f[i]>9) || f[i] != 58) throw logic_error("Date of release can only contain numbers");
	}
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
		if (arr[i].get_Name_of_song() == a) {
			return i;
		}
	} 
	cout << "Song wasnt found" << endl << endl;
	return -1;
}

int MediaPlayer::index_of_Song_name_and_singer(string a, string b) {
	for (int i = 0; i < size; ++i) {
		if (arr[i].get_Name_of_song() == a && arr[i].get_Name_of_singer() == b) {
			cout << "Song was found" << endl;
			return i;
		}
	}
	cout << "Song wasnt found" << endl << endl;;
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

void MediaPlayer::delete_song(int index) {
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
	cout << "Song deleted" << endl << endl;
}

void MediaPlayer::set_Data_to_file() {
	ofstream file;
	file.open("C://Data.txt", ios::app);
	if (!file.is_open()) cout << "Cant open file" << endl;
	for (int i = 0; i < size; ++i) {
		file << "Name of song: " << arr[i].get_Name_of_song() << endl;
		file << "Author of song: " << arr[i].get_Author_of_song() << endl;
		file << "Author of music: " << arr[i].get_Author_of_music() << endl;
		file << "Name of singer: " << arr[i].get_Name_of_singer() << endl;
		file << "Name of album: " << arr[i].get_Name_of_album() << endl;
		file << "Date of release: " << arr[i].get_Date_of_release() << endl;
		file << endl;
		file.flush();
	}
	cout << "The data is recorded!" << endl;
	file.close();
}

bool operator==(const Song& left, const Song& right) {
	if (left.get_Author_of_music() == right.get_Author_of_music() &&
		left.get_Author_of_song() == right.get_Author_of_song() &&
		left.get_Date_of_release() == right.get_Date_of_release() &&
		left.get_Name_of_album() == right.get_Name_of_album() &&
		left.get_Name_of_singer() == right.get_Name_of_singer() &&
		left.get_Name_of_song() == right.get_Name_of_song()) {
		return 1;
	} else return 0;
}
