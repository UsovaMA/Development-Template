// Copyright 2020 Podovinnikov
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include<Windows.h>

using namespace std;

class Song {
public:
  Song();
  Song(const string& date, const string& author, const string& title, const string& poet, const string& composer, const string& album);
  void set(const string& date, const string& author, const string& title, const string& poet, const string& composer, const string& album);
  string getDate();
  string getAuthor();
  string getTitle();
  string getPoet();
  string getComposer();
  string getAlbum();

  bool operator == (const Song& op) {
    return bool(m_date == op.m_date &&
      m_author == op.m_author &&
      m_title == op.m_title &&
      m_poet == op.m_poet &&
      m_composer == op.m_composer &&
      m_album == op.m_album);
  }
  friend bool operator == (const Song& left, const Song& right) {
    return bool (left.m_date == right.m_date &&
      left.m_author == right.m_author &&
      left.m_title == right.m_title &&
      left.m_poet == right.m_poet &&
      left.m_composer == right.m_composer &&
      left.m_album == right.m_album);
  }

  friend ostream& operator << (ostream& os, const Song& b);
private:
  string m_date, m_author, m_title, m_poet, m_composer, m_album;
};

void inputSong(Song& b);

class Playlist
{
public:

  typedef vector<Song> Songcase;

  Playlist();
  void append(const Song& Song);
  int numoOfsongs();
  bool remove(const Song& Song);
  /*bool edit(const Song& Song, const Song& song1) {
    auto it = find(m_bc.begin(), m_bc.end(), Song);
    if (it != m_bc.end()) {
      m_bc.emplace(it,song1);
      m_bc.erase(it);
      return true;
    }
    return false;
  }*/
  Songcase::iterator findByTitle(const string& title, Songcase::iterator from);
  Songcase::iterator findByAuthor(const string& author, Songcase::iterator from);
  Songcase::iterator findByPoet(const string& poet, Songcase::iterator from);
  Songcase::iterator findByComposer(const string& co, Songcase::iterator from);
  Songcase::iterator findByDate(const string& year, Songcase::iterator from);

  Songcase::iterator begin();
  Songcase::iterator end();
private:
  Songcase m_bc;
};

