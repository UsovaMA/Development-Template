#ifndef INCLUDE_CLASS_MEDIAPLAYER_HPP_
#define INCLUDE_CLASS_MEDIAPLAYER_HPP_
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdexcept>

using namespace std;

class Song {
private:
	string Name_of_song;
	string Author_of_song;
	string Author_of_music;
	string Name_of_singer;
	string Name_of_album;
	string Date_of_release;

public:
	Song();
	Song(string a, string b, string c, string d, string e, string f);

	const string get_Name_of_song() const { return Name_of_song; }
	const string get_Author_of_song() const { return Author_of_song; }
	const string get_Author_of_music() const { return Author_of_music; }
	const string get_Name_of_singer() const { return Name_of_singer; }
	const string get_Name_of_album() const { return Name_of_album; }
	const string get_Date_of_release() const { return Date_of_release; }

	void set_Name_of_song(string a);
	void set_Author_of_song(string a);
	void set_Author_of_music(string a);
	void set_Name_of_singer(string a);
	void set_Name_of_album(string a);
	void set_Date_of_release(string a);

	void show_song_info();
	friend bool operator==(const Song& left, const Song& right);
};

class MediaPlayer {
public:
	Song *arr;
	int size;

	MediaPlayer();
	MediaPlayer(const Song a);
	void add_new_song(string a, string b, string c, string d, string e, string f);
	int index_of_Song_name(string a);
	int index_of_Song_name_and_singer(string a, string b);
	void song_of_Author_of_song(string a);
	void song_of_Author_of_music(string a);
	void song_of_singer(string a);
	void delete_song(int index);
	void set_Data_to_file();
};

#endif INCLUDE_CLASS_MEDIAPLAYER_HPP_
