// Copyright free James-Bolt 2020

#include "Class_MediaPlayer.hpp"

int main() {

	int index;
	int number;
	string a, b, c, d, e, f, str;
	MediaPlayer mass;
	ifstream file;
	int tmp = 0;

	while (1) {
		cout << "MediaPlayer:" << endl;
		cout << "1. Add song" << endl;
		cout << "2. Edit song data" << endl;
		cout << "3. Find a song by title and artist" << endl;
		cout << "4. Get all songs of the given author" << endl;
		cout << "5. Get all songs of the given composer" << endl;
		cout << "6. Get all songs of the given artist" << endl;
		cout << "7. Find out the current number of songs" << endl;
		cout << "8. Delete song" << endl;
		cout << "9. Read data from file" << endl;
		cout << "10. Write data to file" << endl;
		cout << "11. Exit the program" << endl;
		cin >> number;
		cin.ignore();
		cout << endl;
		switch (number) {
		case 1:
			cout << "Name of song : ";
			cin >> a;
			cout << "Author of song: ";
			cin >> b;
			cout << "Author of music: ";
			cin >> c;
			cout << "Name of singer: ";
			cin >> d;
			cout << "Name of album: ";
			cin >> e;
			cout << "Date of release: ";
			cin >> f;
			cout << endl;
			mass.add_new_song(a, b, c, d, e, f);
			break;
		case 2:
			cout << "Enter the name of the song whose data you want to change: ";
			cin >> a;
			cout << endl;
			index = mass.index_of_Song_name(a);
			if (index == -1) break;
			cout << "Enter new data:"<< endl;
			cout << "Author of song: ";
			cin >> b;
			cout << "Author of music: ";
			cin >> c;
			cout << "Singer: ";
			cin >> d;
			cout << "Name of song: ";
			cin >> e;
			cout << "Date of release: ";
			cin >> f;
			mass.arr[index].set_Author_of_song(b);
			mass.arr[index].set_Author_of_music(c);
			mass.arr[index].set_Name_of_singer(d);
			mass.arr[index].set_Name_of_album(e);
			mass.arr[index].set_Date_of_release(f);
			cout << endl;
			break;
		case 3:
			cout << "Enter the name of the song and name of singer you want to find" << endl;
			cout << "Name of song: ";
			cin >> a;
			cout << "Name of singer: ";
			cin >> b;
			cout << endl;
			index = mass.index_of_Song_name_and_singer(a, b);
			if (index == -1) break;
			cout << "About song: " << endl;
			if(index != -1) mass.arr[index].show_song_info();
			cout << endl;
			break;
		case 4:
			cout << "Enter the name of author of songs whose songs you want to find: ";
			cin >> a;
			mass.song_of_Author_of_song(a);
			cout << endl;
			break;
		case 5:
			cout << "Enter the name of author of music whose songs you want to find: ";
			cin >> a;
			mass.song_of_Author_of_music(a);
			cout << endl;
			break;
		case 6:
			cout << "Enter the name of singer whose songs you want to find: ";
			cin >> a;
			mass.song_of_singer(a);
			cout << endl;
			break;
		case 7:
			cout << mass.size << endl;
			break;
		case 8:
			cout << "Enter the name of song whose you want to delete: ";
			cin >> a;
			index = mass.index_of_Song_name(a);
			if (index == -1) break;
			mass.delete_song(index);
			cout << endl;
			break;
		case 9:
			file.open("C://Data.txt", ios::in);
			if (!file.is_open()) cout << "Cant open file" << endl;
			while (getline(file, str)) {
				tmp++;
				if (tmp == 1) {
					a = str.erase(0, 14);
				}
				if (tmp == 2) {
					b = str.erase(0, 16);
				}
				if (tmp == 3) {
					c = str.erase(0, 17);
				}
				if (tmp == 4) {
					d = str.erase(0, 16);
				}
				if (tmp == 5) {
					e = str.erase(0, 15);
				}
				if (tmp == 6) {
					f = str.erase(0, 17);
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
	}
	delete[] mass.arr;
	return 0;
}
