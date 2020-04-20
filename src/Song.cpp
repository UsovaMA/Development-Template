// Copyright 2020 Podovinnikov
#include "Song.h"
Song:: Song() {}
Song:: Song(const string& date, const string& author, const string& title, const string& poet, const string& composer, const string& album) {
  set(date, author, title, poet, composer, album);
}
void Song::set(const string& date, const string& author, const string& title, const string& poet, const string& composer, const string& album) {
  m_date = date;
  m_author = author;
  m_title = title;
  m_poet = poet;
  m_composer = composer;
  m_album = album;
}
string Song::getDate()  { return m_date; }
string Song::getAuthor()  { return m_author; }
string Song::getTitle()  { return m_title; }
string Song::getPoet()  { return m_poet; }
string Song::getComposer()  { return m_composer; }
string Song::getAlbum()  { return m_album; }


ostream& operator << (ostream& os, const Song& b) {
  return os
    << b.m_author << endl
    << b.m_title << endl
    << b.m_date << endl
    << b.m_poet << endl
    << b.m_composer << endl
    << b.m_album << endl;
}

void inputSong(Song& b) {
  string da, ti, po, co, al, yr;
  cout << "Ввод данных о песне\n" << "~~~~~~~~~~~~~~~~~~~\n";
  cout << "Название   : ";
  getline(cin, ti);
  cout << "Исполнитель  : ";
  getline(cin, da);
  cout << "Поэт: ";
  getline(cin, al);
  cout << "Композитор      : ";
  getline(cin, co);
  cout << "Альбом  : ";
  getline(cin, al);
  cout << "Дата: ";
  getline(cin, yr);
  b.set(yr, da, ti, po, co, al);
}


Playlist::Playlist() {}
  void Playlist::append(const Song& Song) {
    m_bc.push_back(Song);
  }
  int Playlist::numoOfsongs() {
    return m_bc.size();
  }
  bool Playlist::remove(const Song& Song) {
    auto it = find(m_bc.begin(), m_bc.end(), Song);
    if (it != m_bc.end()) {
      m_bc.erase(it);
      return true;
    }
    return false;
  }
  /*bool edit(const Song& Song, const Song& song1) {
    auto it = find(m_bc.begin(), m_bc.end(), Song);
    if (it != m_bc.end()) {
      m_bc.emplace(it,song1);
      m_bc.erase(it);
      return true;
    }
    return false;
  }*/
  Playlist::Songcase::iterator Playlist:: findByTitle(const string& title, Songcase::iterator from) {
    return find_if(from, m_bc.end(), [title]( Song& b) { return title == b.getTitle(); });
  }
  Playlist::Songcase::iterator Playlist::findByAuthor(const string& author, Songcase::iterator from) {
    return find_if(from, m_bc.end(), [author]( Song& b) { return author == b.getAuthor(); });
  }
  Playlist::Songcase::iterator Playlist::findByPoet(const string& poet, Songcase::iterator from) {
    return find_if(from, m_bc.end(), [poet]( Song& b) { return poet == b.getPoet(); });
  }
  Playlist::Songcase::iterator Playlist::findByComposer(const string& co, Songcase::iterator from) {
    return find_if(from, m_bc.end(), [co]( Song& b) { return co == b.getComposer(); });
  }
  Playlist::Songcase::iterator Playlist::findByDate(const string& year, Songcase::iterator from) {
    return find_if(from, m_bc.end(), [year]( Song& b) { return year == b.getDate(); });
  }

  Playlist::Songcase::iterator Playlist::begin() { return m_bc.begin(); }
  Playlist::Songcase::iterator Playlist::end() { return m_bc.end(); }